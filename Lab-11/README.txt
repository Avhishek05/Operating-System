Abhishek Yadav
2015kucp1008

ANS 1:
Linux has a common paging model that works in both 32-bit and 64-bit architectures.In 32-bit architectures two paging levels are
sufficient for 32-bitarchitectures, while 64-bit architectures require a higher number of paging levels.Up to version 2.6.10
The four types of page tables are as follows:

1.Page Global Directory
2.Page Upper Directory
3.Page Middle Directory
4.Page Table

/Desktop/2015KUCP1008OS/Lab-11$ cat /proc/meminfo | grep PageTables
PageTables:        34560 kB

Reference: https://www.safaribooksonline.com/library/view/understanding-the-linux/0596005652/ch02s05.html
----------------------------------------------------------------------------------------------------------------------------------------
Ans2:
#include <stdlib.h>
#include <stdio.h>

int main () {

    printf("Look at /proc/%d/maps\n", getpid());

    // allocate 200 KiB, forcing a mmap instead of brk
    char * addr = (char *) malloc(204800);

    getchar();

    free(addr);

    return 0;

}
Look at /proc/29322/maps
gcc pro1.c
Memory layout:

00400000-00401000 r-xp 00000000 08:01 1074032                            /home/avhishek/Desktop/2015KUCP1008OS/Lab-11/a.out
00600000-00601000 r--p 00000000 08:01 1074032                            /home/avhishek/Desktop/2015KUCP1008OS/Lab-11/a.out
00601000-00602000 rw-p 00001000 08:01 1074032                            /home/avhishek/Desktop/2015KUCP1008OS/Lab-11/a.out
01c52000-01c73000 rw-p 00000000 00:00 0                                  [heap]
7f3c98884000-7f3c98a43000 r-xp 00000000 08:01 1054946                    /lib/x86_64-linux-gnu/libc-2.23.so
7f3c98a43000-7f3c98c43000 ---p 001bf000 08:01 1054946                    /lib/x86_64-linux-gnu/libc-2.23.so
7f3c98c43000-7f3c98c47000 r--p 001bf000 08:01 1054946                    /lib/x86_64-linux-gnu/libc-2.23.so
7f3c98c47000-7f3c98c49000 rw-p 001c3000 08:01 1054946                    /lib/x86_64-linux-gnu/libc-2.23.so
7f3c98c49000-7f3c98c4d000 rw-p 00000000 00:00 0
7f3c98c4d000-7f3c98c73000 r-xp 00000000 08:01 1054947                    /lib/x86_64-linux-gnu/ld-2.23.so
7f3c98e22000-7f3c98e58000 rw-p 00000000 00:00 0
7f3c98e70000-7f3c98e72000 rw-p 00000000 00:00 0
7f3c98e72000-7f3c98e73000 r--p 00025000 08:01 1054947                    /lib/x86_64-linux-gnu/ld-2.23.so
7f3c98e73000-7f3c98e74000 rw-p 00026000 08:01 1054947                    /lib/x86_64-linux-gnu/ld-2.23.so
7f3c98e74000-7f3c98e75000 rw-p 00000000 00:00 0
7ffed1324000-7ffed1345000 rw-p 00000000 00:00 0                          [stack]
7ffed1397000-7ffed1399000 r--p 00000000 00:00 0                          [vvar]
7ffed1399000-7ffed139b000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]


#include <stdio.h>
int global;
int main(void)
{
  printf("abhishel yadav");
  return 0;
}

gcc pro1.c -o memory-layout
size memory-layout
output:
text	   data	    bss	    dec	    hex	filename
 1187	    552	      8	   1747	    6d3	memory-layout

1. Text segment
2. Initialized data segment
3. Uninitialized data segment
4. Stack
5. Heap

1. Text Segment:A text segment , also known as a code segment or simply as text, is one of the sections of a program in an object file or in memory, which contains executable instructions.
2. Initialized Data Segment:Initialized data segment, usually called simply the Data gment. A data segment is a portion of virtual address space of a program, which contains the global variables
and static variables that are initialized by the programmer.
3. Uninitialized Data Segment:Uninitialized data segment, often called the “bss” segment, Data in this segment is initialized by the kernel to arithmetic 0 before the program
starts executing
4. Stack:The Stack area contains the program stack, i.e., a LIFO structure typically located in the higher memory addresses right below the OS kernel space. On the standard x86 architecture
 it grows downwards to lower addresses, but on some other architectures it may grow the opposite direction.
This area is used to store all the data needed by a function call in a program.
5.Heap:Heap is the segment where dynamic memory allocation usually takes place, i.e., to allocate memory requested by the programmer
 for variables whose size can be only known at run-time and cannot be statically determined by the compiler before program execution.
