import numpy as np
import matplotlib.pyplot as plt
import csv
import statistics

algorithm = "Dilithium"
versions = ["2", "3", "5"]

gen  = [[] for i in range(3)]
sign = [[] for i in range(3)]
ver  = [[] for i in range(3)]

with open(algorithm +"/" + algorithm + versions[0], newline="") as csvfile:
    reader = csv.DictReader(csvfile, delimiter=",")
    for row in reader:
        gen[0].append(int(row["Gen"]))
        sign[0].append(int(row[" Sign"]))
        ver[0].append(int(row[" Ver"]))

with open(algorithm +"/" + algorithm + versions[1], newline="") as csvfile:
    reader = csv.DictReader(csvfile, delimiter=",")
    for row in reader:
        gen[1].append(int(row["Gen"]))
        sign[1].append(int(row[" Sign"]))
        ver[1].append(int(row[" Ver"]))

with open(algorithm +"/" + algorithm + versions[2], newline="") as csvfile:
    reader = csv.DictReader(csvfile, delimiter=",")
    for row in reader:
        gen[2].append(int(row["Gen"]))
        sign[2].append(int(row[" Sign"]))
        ver[2].append(int(row[" Ver"]))


X = [algorithm + versions[0], algorithm + versions[1], algorithm + versions[2]]
mean_gen  = [statistics.mean(gen[0]), statistics.mean(gen[1]), statistics.mean(gen[2])]
mean_sign = [statistics.mean(sign[0]), statistics.mean(sign[1]), statistics.mean(sign[2])]
mean_ver  = [statistics.mean(ver[0]), statistics.mean(ver[1]), statistics.mean(ver[2])]

X_axis = np.arange(len(X))

plt.grid()
plt.bar(X_axis - 0.3, mean_gen, 0.3, label = 'Generación')
plt.bar(X_axis, mean_sign, 0.3, label = 'Firma')
plt.bar(X_axis + 0.3, mean_ver, 0.3, label = 'Verificación')

plt.xticks(X_axis, X)
plt.xlabel("Versiones " + algorithm)
plt.ylabel("Tiempo medio de ejecución [us]")
plt.title("Tiempo necesario para cada función de " + algorithm)
plt.legend()
plt.show() 
