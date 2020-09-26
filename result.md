## Case I: $h_1=SHA256$, $h_2=MD5$, $h_3=SHA1$, $h_4=blake2b$

## Case II:  $h_1=SHA1$, $h_2=blake2b$, $h_3=SHA256$, $h_4=MD5$

## Case III:  $h_1=SHA1$, $h_2=MD5$, $h_3=blake2b$, $h_4=SHA256$

|          | Setup time (seconds) | Average password generation time (seconds) | Average verification time (milliseconds) |
| -------- | -------------------- | ------------------------------------------ | ---------------------------------------- |
| MD5      | 0.96                 | 0.50                                       | 1.3                                      |
| SHA1     | 2.11                 | 1.14                                       | 2.4                                      |
| SHA256   | 8.20                 | 3.37                                       | 9.1                                      |
| blake2b  | 8.76                 | 3.59                                       | 4.8                                      |
| Case I   | 6.26                 | 2.57                                       | 5.0                                      |
| Case II  | 7.01                 | 3.11                                       | 6.5                                      |
| Case III | 7.86                 | 3.19                                       | 6.7                                      |

## Case IV: $h_1=MD5$, $h_2=KECCAK256$, $h_3=SHA512$

|           | Setup time (seconds) | Average password generation time (seconds) | Average verification time (milliseconds) |
| --------- | -------------------- | ------------------------------------------ | ---------------------------------------- |
| MD5       | 0.96                 | 0.50                                       | 1.3                                      |
| KECCAK256 | 34.77                | 12.67                                      | 23                                       |
| SHA512    | 8.84                 | 4.27                                       | 12.25                                    |
| Case IV   | 8.91                 | 6.12                                       | 9.4                                      |

