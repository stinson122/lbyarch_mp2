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
