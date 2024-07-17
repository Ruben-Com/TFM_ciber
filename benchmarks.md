# Speed Evaluation
## Key Encapsulation Schemes
| scheme | implementation | key generation [cycles] | encapsulation [cycles] | decapsulation [cycles] |
| ------ | -------------- | ----------------------- | ---------------------- | ---------------------- |
## Signature Schemes
| scheme | implementation | key generation [cycles] | sign [cycles] | verify [cycles] |
| ------ | -------------- | ----------------------- | ------------- | --------------- |
| falcon-512 (3 executions) | clean | AVG: 189,140,844 <br /> MIN: 136,076,487 <br /> MAX: 263,972,410 | AVG: 63,945,169 <br /> MIN: 63,875,502 <br /> MAX: 64,018,224 | AVG: 828,793 <br /> MIN: 828,685 <br /> MAX: 828,945 |
| falcon-512 (3 executions) | m4-ct | AVG: 133,501,348 <br /> MIN: 115,210,570 <br /> MAX: 155,846,599 | AVG: 41,638,612 <br /> MIN: 41,595,986 <br /> MAX: 41,701,880 | AVG: 475,408 <br /> MIN: 467,366 <br /> MAX: 479,666 |
| falcon-512 (3 executions) | opt-ct | AVG: 153,817,464 <br /> MIN: 111,141,867 <br /> MAX: 233,082,954 | AVG: 41,702,148 <br /> MIN: 41,536,309 <br /> MAX: 41,791,478 | AVG: 475,058 <br /> MIN: 467,566 <br /> MAX: 478,826 |
| falcon-512 (3 executions) | opt-leaktime | AVG: 161,721,993 <br /> MIN: 104,126,853 <br /> MAX: 256,042,567 | AVG: 38,895,048 <br /> MIN: 38,792,988 <br /> MAX: 39,010,434 | AVG: 467,571 <br /> MIN: 467,172 <br /> MAX: 468,072 |
# Memory Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | Key Generation [bytes] | Encapsulation [bytes] | Decapsulation [bytes] |
| ------ | -------------- | ---------------------- | --------------------- | --------------------- |
| bikel1 | m4f | 43,920 | 32,144 | 91,372 |
| bikel3 | m4f | 85,836 | 62,936 | 175,096 |
| kyber1024 | m4fspeed | 6,436 | 7,500 | 7,484 |
| kyber1024 | m4fstack | 3,332 | 3,372 | 3,356 |
| kyber512 | m4fspeed | 4,364 | 5,436 | 5,412 |
| kyber512 | m4fstack | 2,292 | 2,348 | 2,332 |
| kyber768 | m4fspeed | 5,396 | 6,468 | 6,452 |
| kyber768 | m4fstack | 2,828 | 2,868 | 2,852 |
## Signature Schemes
| Scheme | Implementation | Key Generation [bytes] | Sign [bytes] | Verify [bytes] |
| ------ | -------------- | ---------------------- | ------------ | -------------- |
| dilithium3 | m4f | 60,824 | 68,864 | 57,828 |
| dilithium3 | m4fstack | 4,408 | 6,608 | 2,704 |
| dilithium5 | m4f | 97,688 | 116,076 | 92,932 |
| dilithium5 | m4fstack | 4,408 | 8,136 | 2,712 |
| falcon-512 | clean | 18,140 | 43,560 | 4,692 |
| falcon-512 | m4-ct | 1,196 | 2,540 | 484 |
| falcon-512 | opt-ct | 1,252 | 2,440 | 376 |
| falcon-512 | opt-leaktime | 1,228 | 2,604 | 376 |
| haetae3 | m4f | 29,484 | 83,420 | 31,768 |
| perk-192-fast-3 | m4 | 14,952 | 47,736 | 41,368 |
| perk-192-fast-5 | m4 | 16,872 | 48,784 | 42,424 |
| perk-192-short-5 | m4 | 16,872 | 51,896 | 47,272 |
# Hashing Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | Key Generation [%] | Encapsulation [%] | Decapsulation [%] |
| ------ | -------------- | ------------------ | ----------------- | ----------------- |
## Signature Schemes
| Scheme | Implementation | Key Generation [%] | Sign [%] | Verify [%] |
| ------ | -------------- | ------------------ | -------- | ---------- |
| falcon-512 | clean | 14.0% | 0.4% | 26.1% |
| falcon-512 | m4-ct | 15.7% | 0.5% | 34.8% |
| falcon-512 | opt-ct | 11.6% | 0.5% | 34.3% |
| falcon-512 | opt-leaktime | 11.7% | 0.5% | 34.3% |
# Size Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | .text [bytes] | .data [bytes] | .bss [bytes] | Total [bytes] |
| ------ | -------------- | ------------- | ------------- | ------------ | ------------- |
## Signature Schemes
| Scheme | Implementation | .text [bytes] | .data [bytes] | .bss [bytes] | Total [bytes] |
| ------ | -------------- | ------------- | ------------- | ------------ | ------------- |
| falcon-512 | clean | 83,067 | 0 | 0 | 83,067 |
| falcon-512 | m4-ct | 82,093 | 0 | 39,936 | 122,029 |
| falcon-512 | opt-ct | 82,093 | 0 | 39,936 | 122,029 |
| falcon-512 | opt-leaktime | 75,493 | 0 | 39,936 | 115,429 |