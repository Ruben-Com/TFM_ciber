# Speed Evaluation
## Key Encapsulation Schemes
| scheme | implementation | key generation [cycles] | encapsulation [cycles] | decapsulation [cycles] |
| ------ | -------------- | ----------------------- | ---------------------- | ---------------------- |
## Signature Schemes
| scheme | implementation | key generation [cycles] | sign [cycles] | verify [cycles] |
| ------ | -------------- | ----------------------- | ------------- | --------------- |
| falcon-1024 (3 executions) | clean | AVG: 1,081,357,350 <br /> MIN: 613,650,862 <br /> MAX: 1,953,264,490 | AVG: 140,042,876 <br /> MIN: 139,949,097 <br /> MAX: 140,112,622 | AVG: 1,664,828 <br /> MIN: 1,664,650 <br /> MAX: 1,664,919 |
| falcon-1024 (3 executions) | m4-ct | AVG: 488,485,488 <br /> MIN: 304,818,567 <br /> MAX: 800,111,911 | AVG: 90,951,452 <br /> MIN: 90,744,894 <br /> MAX: 91,106,944 | AVG: 979,986 <br /> MIN: 971,337 <br /> MAX: 985,248 |
| falcon-1024 (3 executions) | opt-ct | AVG: 568,320,334 <br /> MIN: 509,162,103 <br /> MAX: 633,987,232 | AVG: 90,892,753 <br /> MIN: 90,844,643 <br /> MAX: 90,916,884 | AVG: 976,121 <br /> MIN: 972,455 <br /> MAX: 983,115 |
| falcon-1024 (3 executions) | opt-leaktime | AVG: 386,652,453 <br /> MIN: 306,718,746 <br /> MAX: 534,090,453 | AVG: 83,455,650 <br /> MIN: 83,209,797 <br /> MAX: 83,874,717 | AVG: 978,993 <br /> MIN: 970,973 <br /> MAX: 983,133 |
| falcon-512 (5 executions) | clean | AVG: 180,127,750 <br /> MIN: 136,076,487 <br /> MAX: 232,657,271 | AVG: 64,005,487 <br /> MIN: 63,776,812 <br /> MAX: 64,138,650 | AVG: 828,927 <br /> MIN: 828,569 <br /> MAX: 829,209 |
| falcon-512 (5 executions) | m4-ct | AVG: 171,839,642 <br /> MIN: 119,292,436 <br /> MAX: 282,321,994 | AVG: 41,630,839 <br /> MIN: 41,605,645 <br /> MAX: 41,669,986 | AVG: 474,574 <br /> MIN: 466,854 <br /> MAX: 479,864 |
| falcon-512 (5 executions) | opt-ct | AVG: 183,487,047 <br /> MIN: 125,391,288 <br /> MAX: 284,379,638 | AVG: 41,734,329 <br /> MIN: 41,679,833 <br /> MAX: 41,799,985 | AVG: 474,521 <br /> MIN: 466,785 <br /> MAX: 480,766 |
| falcon-512 (5 executions) | opt-leaktime | AVG: 136,794,456 <br /> MIN: 95,563,673 <br /> MAX: 200,652,030 | AVG: 38,931,607 <br /> MIN: 38,825,069 <br /> MAX: 39,023,757 | AVG: 474,341 <br /> MIN: 467,179 <br /> MAX: 478,852 |
# Memory Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | Key Generation [bytes] | Encapsulation [bytes] | Decapsulation [bytes] |
| ------ | -------------- | ---------------------- | --------------------- | --------------------- |
## Signature Schemes
| Scheme | Implementation | Key Generation [bytes] | Sign [bytes] | Verify [bytes] |
| ------ | -------------- | ---------------------- | ------------ | -------------- |
| falcon-1024 | clean | 35,084 | 84,616 | 8,776 |
| falcon-1024 | m4-ct | 1,252 | 2,520 | 376 |
| falcon-1024 | opt-ct | 1,220 | 2,520 | 376 |
| falcon-1024 | opt-leaktime | 1,260 | 2,592 | 376 |
| falcon-512 | clean | 18,140 | 43,560 | 4,788 |
| falcon-512 | m4-ct | 1,252 | 2,440 | 484 |
| falcon-512 | opt-ct | 1,212 | 2,540 | 484 |
| falcon-512 | opt-leaktime | 1,260 | 2,504 | 376 |
# Hashing Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | Key Generation [%] | Encapsulation [%] | Decapsulation [%] |
| ------ | -------------- | ------------------ | ----------------- | ----------------- |
## Signature Schemes
| Scheme | Implementation | Key Generation [%] | Sign [%] | Verify [%] |
| ------ | -------------- | ------------------ | -------- | ---------- |
| falcon-1024 | clean | 5.5% | 0.3% | 23.9% |
| falcon-1024 | m4-ct | 9.9% | 0.4% | 32.9% |
| falcon-1024 | opt-ct | 17.6% | 0.4% | 32.6% |
| falcon-1024 | opt-leaktime | 7.5% | 0.4% | 32.6% |
| falcon-512 | clean | 11.2% | 0.4% | 26.2% |
| falcon-512 | m4-ct | 18.4% | 0.5% | 34.6% |
| falcon-512 | opt-ct | 17.4% | 0.5% | 34.3% |
| falcon-512 | opt-leaktime | 24.3% | 0.5% | 33.5% |
# Size Evaluation
## Key Encapsulation Schemes
| Scheme | Implementation | .text [bytes] | .data [bytes] | .bss [bytes] | Total [bytes] |
| ------ | -------------- | ------------- | ------------- | ------------ | ------------- |
## Signature Schemes
| Scheme | Implementation | .text [bytes] | .data [bytes] | .bss [bytes] | Total [bytes] |
| ------ | -------------- | ------------- | ------------- | ------------ | ------------- |
| falcon-1024 | clean | 83,107 | 0 | 0 | 83,107 |
| falcon-1024 | m4-ct | 82,093 | 0 | 79,872 | 161,965 |
| falcon-1024 | opt-ct | 82,093 | 0 | 79,872 | 161,965 |
| falcon-1024 | opt-leaktime | 75,493 | 0 | 79,872 | 155,365 |
| falcon-512 | clean | 83,067 | 0 | 0 | 83,067 |
| falcon-512 | m4-ct | 82,093 | 0 | 39,936 | 122,029 |
| falcon-512 | opt-ct | 82,093 | 0 | 39,936 | 122,029 |
| falcon-512 | opt-leaktime | 75,493 | 0 | 39,936 | 115,429 |