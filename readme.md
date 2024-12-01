## LBARCHY - Grp 6
**Daxpy in C and x86**
***
<p>To run the prorgam in cmd, input the following text in cmd:</p>
<p>1. nasm -f win64 daxpy.asm</p>
<p>2. gcc -c main.c -o main.obj -m64 -mavx </p>
<p>3. gcc -o main.exe main.obj daxpy.obj -mconsole</p>
<p>4. main.exe</p>

***
<p>When you have excecuted the exe file it will first ask you to choose the size of the vector, the sizes being 2^20, 2^24 and 2^29.</p>
<p>The user must input the corresponding letter for the size of the vector. If the user entered a character not recognized by the porgram, it will automatically set the size of the vector to 2^20 as seen in the image below.</p>

**Image of the size selection:**
![Logo](Images/MPpic1.png)

<p>Invalid Input:</p>

![Logo](Images/MPpic1.png)

***
<p>After selecting the size of the vector it will then ask you for a number. That number will be the one used as the value for the variable A. The entered value cannot be 1, if the value 1 is entered as the input the program will say it can't be 1 and loop back to ask for a new input.</p>

**Image of the size selection:**
![Logo](Images/MPpic1.png)

***
<p>With the value for A already set the program will now begin. It will print out the first 10 elements of all vectors of the Daxpy Operation done by assembly at the same time caluculation its execution. After that it will print out the Daxpy done by the SIMD instructions in C to visibly check if the outputs of the assembly is correct.</p>

**Sample runs of different vector Sizes:**

![Logo](Images/MPpic4.png)
![Logo](Images/MPpic5.png)
![Logo](Images/MPpic6.png)

***
**Run time Results**
<p>In this section we will see the time it took for the program to complete computing for the Daxpy. We will conduct 30 test runs for each size before we compute for the average run time. The value of A will be set to two for all test runs.</p>

**Vector Size: 2^20**
| Test no:           | asm time in Seconds: | SIMD time in Seconds: |
|:------------------:|:--------------------:|:---------------------:|
| 1                  | 0.003000             | 0.001000              |
| 2                  | 0.001000             | 0.001000              |
| 3                  | 0.004000             | 0.002000                    |
| 4                  | 0.005000                   | 0.003000                    |
| 5                  | 0.002000                   | 0.005000                    |
| 6                  | 0.005000                   | 0.004000                    |
| 7                  | 0.005000                   | 0.004000                    |
| 8                  | 0.003000                   | 0.002000                    |
| 9                  | 0.004000                   | 0.003000                    |
| 10                 | 0.002000                   | 0.003000                    |
| 11                 | 0.003000                   | 0.003000                    |
| 12                 | 0.002000                   | 0.003000                    |
| 13                 | 0.002000                   | 0.003000                    |
| 14                 | 0.004000                   | 0.003000                    |
| 15                 | 0.003000                   | 0.003000                    |
| 16                 | 0.001000                   | 0.004000                    |
| 17                 | 0.002000                   | 0.003000                    |
| 18                 | 0.002000                   | 0.003000                    |
| 19                 | 0.004000                   | 0.004000                    |
| 20                 | 0.002000                   | 0.003000                    |
| 21                 | 0.004000                   | 0.003000                    |
| 22                 | 0.002000                   | 0.003000                    |
| 23                 | 0.005000                   | 0.005000                    |
| 24                 | 0.004000                   | 0.006000                    |
| 25                 | 0.002000                   | 0.004000                    |
| 26                 | 0.002000                   | 0.001000                    |
| 27                 | 0.004000                   | 0.002000                    |
| 28                 | 0.004000                   | 0.005000                    |
| 29                 | 0.003000                   | 0.002000                    |
| 30                 | 0.003000                   | 0.003000                    |
| **Avg Time**           | **0.00323**                   | **0.00287**                    |

**Vector Size: 2^24**
| Test no:           | asm time in Seconds: | SIMD time in Seconds: |
|:------------------:|:--------------------:|:---------------------:|
| 1                  | 0.057000             | 0.042000              |
| 2                  | 0.039000             | 0.041000              |
| 3                  | 0.044000             | 0.037000                    |
| 4                  | 0.051000                   | 0.041000                    |
| 5                  | 0.041000                   | 0.040000                    |
| 6                  | 0.065000                   | 0.045000                    |
| 7                  | 0.055000                   | 0.045000                    |
| 8                  | 0.060000                   | 0.043000                    |
| 9                  | 0.071000                   | 0.044000                    |
| 10                 | 0.044000                   | 0.043000                    |
| 11                 | 0.038000                   | 0.039000                    |
| 12                 | 0.048000                   | 0.042000                    |
| 13                 | 0.055000                   | 0.039000                    |
| 14                 | 0.052000                   | 0.041000                   |
| 15                 | 0.044000                     | 0.040000                       |
| 16                 | 0.041000                     | 0.040000                       |
| 17                 | 0.042000                     | 0.042000                       |
| 18                 | 0.043000                     | 0.042000                       |
| 19                 | 0.046000                     | 0.044000                       |
| 20                 | 0.039000                     | 0.040000                       |
| 21                 | 0.041000                     | 0.046000                       |
| 22                 | 0.057000                     | 0.041000                       |
| 23                 | 0.044000                     | 0.049000                       |
| 24                 | 0.042000                     | 0.039000                       |
| 25                 | 0.042000                     | 0.044000                       |
| 26                 | 0.040000                     | 0.042000                       |
| 27                 | 0.044000                     | 0.037000                       |
| 28                 | 0.039000                     | 0.039000                       |
| 29                 | 0.045000                     | 0.040000                       |
| 30                 | 0.042000                     | 0.040000                       |
| **Avg Time**           | **0.0416**                   | **0.0416**                    |

**Vector Size: 2^29**
| Test no:           | asm time in Seconds: | SIMD time in Seconds: |
|:------------------:|:--------------------:|:---------------------:|
| 1                  |                      |                        |
| 2                  |                      |                        |
| 3                  |                      |                        |
| 4                  |                      |                        |
| 5                  |                      |                        |
| 6                  |                      |                        |
| 7                  |                      |                        |
| 8                  |                      |                        |
| 9                  |                      |                        |
| 10                 |                      |                        |
| 11                 |                      |                        |
| 12                 |                      |                        |
| 13                 |                      |                        |
| 14                 |                      |                        |
| 15                 |                      |                        |
| 16                 |                      |                        |
| 17                 |                      |                        |
| 18                 |                      |                        |
| 19                 |                      |                        |
| 20                 |                      |                        |
| 21                 |                      |                        |
| 22                 |                      |                        |
| 23                 |                      |                        |
| 24                 |                      |                        |
| 25                 |                      |                        |
| 26                 |                      |                        |
| 27                 |                      |                        |
| 28                 |                      |                        |
| 29                 |                      |                        |
| 30                 |                      |                        |
| **Avg Time**       | ****                 | ****                   |
