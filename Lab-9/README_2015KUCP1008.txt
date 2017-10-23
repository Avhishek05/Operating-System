Abhishek Yadav
2015KUCP1008


<----------------------------------------------------------------------------------------------------------------
1.Qestion------
---------------------------------------------------------------------------------------------------------------------
Ans:

    malloc();
  1.   The malloc() function allocates size bytes and returns a pointer to the
       allocated memory.  The memory is not initialized.  If size is  0,  then
       malloc()  returns either NULL, or a unique pointer value that can later
       be successfully passed to free().
   2. C impementation: #include <stdlib.h>
                    void *malloc(size_t size);
                    int *ptr = (int *) malloc(sizeof(int)*10);

   3.Memory allocation and deallocation
   The malloc() functions return a pointer to  the  allocated memory,  which  is  suitably  aligned for any built-in type.  On error,
       these functions return NULL.  NULL may also be returned by a successful call  to  malloc() with a size of zero.
   4.Precaution:
   Don't expect the memory to be zeroed. It might be in debug mode, but in release mode it often isn't, for performance reasons.
   In a mixed C/C++ system, don't use delete to release memory allocated by malloc().
---------------------------------------------------------------------------------------------------------------------
  calloc():
  1.The  calloc()  function allocates memory for an array of nmemb elements
       of size bytes each and returns a pointer to the allocated memory.   The
       memory  is  set  to zero.  If nmemb or size is 0, then calloc() returns
       either NULL, or a unique pointer value that can later  be  successfully
       passed to free().
  2.C impementation: #include <stdlib.h>
    void *calloc(size_t nitems, size_t size)
    a = (int*)calloc(n, sizeof(int));
  3.Memory allocation and deallocation
  The calloc() functions return a pointer to  the  allocated memory,  which  is  suitably  aligned for any built-in type.  On error,
       these functions return NULL.  NULL may also be returned by a successful call to calloc() with nmemb or size equal to zero.
  4. Precaution:   Don't use delete to release memory allocated by calloc().
  Always check if the call was successful. Type cast the pointer properly.
  If allocating memory for a string, don't forget to allocate , one extra byte for the null terminator of the string.
    ------------------------------------------------------------------------------------------------------------------
  realloc():
  1.The  realloc() function changes the size of the memory block pointed to by ptr to size bytes.  The contents will be unchanged in the range from
       the start of the region up to the minimum of the old and new sizes.  If the new size is larger than the old size, the added memory will not  be
       initialized.
  2.C impementation: #include <stdlib.h>
    void *realloc(void *ptr, size_t size)
    ptr_new = (int *)realloc(ptr, sizeof(int)*3);

  3.Memory allocation and deallocation
    realloc () function modifies the allocated memory size by malloc () and calloc () functions to new size.
    If enough space doesn’t exist in memory of current block to extend, new block is allocated for the full size of reallocation,
    then copies the existing data to new block and then frees the old block.
  4. Precaution:
    realloc will first deallocate the old object and than reallocate the new size? or is it simply append the required new bytes at the end of old pointer,
    i.e. implementation dependent.
    same is the case with dynamic arrays also, when they want to expand their size.

    -------------------------------------------------------------------------------------------------------------

    free():
  1.  The C library function void free(void *ptr) deallocates the memory previously allocated by a call to calloc, malloc, or realloc.
  2.  C impementation: #include <stdlib.h>
      ptr_new = (int *)realloc(ptr, sizeof(int)*3);
          free(ptr);
  3.Deallocate is a process performed by a computer where a block of information is released from memory so that it may be used by a different program.
  4.Precaution: we should not freeing a memory that is not allocated by malloc,calloc or realloc.
    ------------------------------
  alloca -
  1. allocate memory that is automatically freed
  2. #include <alloca.h>
     void *alloca(size_t size);
  3.Memory allocation: The alloca() function allocates size bytes of space in the stack
       frame of the caller.  This temporary space is automatically freed when the function that called alloca() returns to its caller.
       #include <alloca.h>
      void *alloca(size_t size);
  4.  Precaution:The alloca() function returns a pointer to the beginning of the allocated space.
       If the allocation causes stack overflow, program behaviour is undefined.
  --------------------------------------------------------------------------------------------------------------------------------
  longjmp()
  1.it cpoies saved state in jmp_buffer variable to processor
  2.C implementation: void longjmp(jmp_buf environment, int value)
          When longjmp is called the state saved in the jmp_buf variable is copied back in the processor and computation
          starts over from the return point of setjmp function but the returned value is the one passed as second argument to longjmp function.
  3.Memory allocation and deallocation:
          after longjmp called varirable jmp_buffer's content destroyed.
  4.precaution:
        A ‘goto’ can’t jump out of current function while we can ‘longjmp’ long way away, even to a function in a different file.
  ------------------------------------------
  brk():
  1.brk()- change data segment size
  brk() sets the end of the data segment to the value specified by end_data_segment, when that value is reasonable,
  the system does have enough memory and the process does not exceed its max data size.
  2.C implementation:       #include <unistd.h>
                          int brk(void *addr);
  3.Memory allocation and deallocation:
  brk()  and  sbrk() change the location of the program break, which defines the end of the process's data segment (i.e., the program break is the first location
   after the end of the uninitialized data segment).  Increasing the program break has the effect of allocating memory to the process; decreasing the break deallocates memory
  4. Precaution:
   Avoid using brk(): the malloc memory allocation package is the portable and comfortable way of allocating memory.
          On Linux, sbrk() is implemented as a library function that uses the brk() system call, and does some internal bookkeeping so that it can return the old break value.
  ------------------------------------------------------------------------------------------------------------------
mmap(), munmap()
1.   mmap(), munmap() - map or unmap files or devices into memory
    mmap()  creates a new mapping in the virtual address space of the calling process.  The starting address for the new mapping is specified in addr.
    The length argument specifies the length of the mapping.
    The  munmap()  system call deletes the mappings for the specified address range, and causes further references to addresses within the range to generate invalid memory references.  The region
           is also automatically unmapped when the process is terminated.On the other hand, closing the file descriptor does not unmap the region.
2.  C implementation:
      #include <sys/mman.h>
     void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);
     int munmap(void *start, size_t length);
3.   Memory allocation and deallocation:
     Memory mapped by mmap() is preserved across fork, with the same attributes.A file is mapped in multiples of the page size.  For a file that is not a
     multiple of the page size, the remaining memory is zeroed when mapped, and writes to that region are not written  out to the file.
4.   If mmap() fails, it will return MAP_FAILED. Thus, you need to test for that before de-referencing the pointer returned by mmap().
     There is significant overhead to mmap(), and typically allocations cannot be smaller than a "page".
------------------------------------------------------------------------------------------------------------------------


<!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!11>
Answer:2

/* Program with memory leak */
      #include<stdio.h>
      #include <stdlib.h>
      void f()
      {
         int *ptr = (int *) malloc(sizeof(int)*10);
        /* Do some work */
         return; /* Return without freeing ptr*/
      }
      int main()
      {
      void f();
      }

what is Memory leak?
        A memory leak is a type of resource leak that occurs when a computer program incorrectly manages memory
        allocations in such a way that memory which is no longer needed is not released.


How does this program leak memory?
        If we didn't use free(),The process dies and then the heap space is gone anyway so there's no harm in missing the call to free,however except the runtime
         cost of having more storage than you need.if you don't call free, the data you wrote to them might not get flushed, or if they're a temp file, they might not get deleted when you're done.
        Also, database handles should have their transactions committed and then closed when you're done with them.

Q.How can this be fixed?
        Ans.To avoid memory leaks, memory allocated on heap should always be freed when no longer needed.

/* Function without memory leak */
#include<stdio.h>
#include <stdlib.h>;

void f()
{
   int *ptr = (int *) malloc(sizeof(int));

   /* Do some work */

   free(ptr);
   return;
}
int main()
{
void f();
}

best practices:
    * Always use memset along with malloc, or always use calloc.
    *Whenever writing values to pointers, make sure you cross check the number of bytes available and number of bytes being written.
    *Before assigning the pointers, make sure no memory locations will become orphaned.
    *Whenever freeing the structured element free it from child to parents.
    *Always properly handle return values of functions returning references of dynamically allocated memory.
    *Have a corresponding free to every malloc.
    *Make sure you are not accessing null pointer
<>!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!<>

Answer3:

  #include <stdio.h>
  #include <malloc.h>     /* for definition of ptrdiff_t on GLIBC */
  #include <unistd.h>
  #include <alloca.h>     /* for demonstration only */
   void func(void);    /* a function for showing stack growth */
  int main(int argc, char **argv) /* arguments aren't used */
  {
      char *p, *b, *nb;
      printf("Stack Locations:\n");
      func();
      p = (char *) alloca(32);
      if (p != NULL) {
          printf("\tStart of alloca()'ed array: %p\n", p);
          printf("\tEnd of alloca()'ed array: %p\n", p + 31);
      }
      b = sbrk((ptrdiff_t) 32);   /* grow address space */
      nb = sbrk((ptrdiff_t) 0);
      printf("Heap Locations:\n");
      printf("\tInitial end of heap: %p\n", b);
      printf("\tNew end of heap: %p\n", nb);
      b = sbrk((ptrdiff_t) -16);  /* shrink it */
      nb = sbrk((ptrdiff_t) 0);
      printf("\tFinal end of heap: %p\n", nb);
      printf("Address of code segment is : %p\n",&main);
  }

  void func(void)
  {
      static int level = 0;       /* recursion level */
      auto int stack_var;        /* automatic variable, on stack */

      if (++level == 3)           /* avoid infinite recursion */
          return;

      printf("\tStack level %d: address of stack_var: %p\n",
              level, & stack_var);
      func();                    /* recursive call */
  }


output:   Stack Locations:
                  	Stack level 1: address of stack_var: 0x7ffcd481bc54
                  	Stack level 2: address of stack_var: 0x7ffcd481bc34
                  	Start of alloca()'ed array: 0x7ffcd481bc40
                  	End of alloca()'ed array: 0x7ffcd481bc5f
          Heap Locations:
                  	Initial end of heap: 0xe77000
                  	New end of heap: 0xe77020
                  	Final end of heap: 0xe77010
          Address of code segment is : 0x400626


Conclusion :when i duplicate this program then address of stack and heap changes but address of code segment remain same.
	    Because if the code segment in question is loaded from a DLL, it might be the operating system being clever and re-using the already loaded library.

<!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!>
Answer:4

	#include<stdio.h>
	int main()
	{
	int x=5;
	int *p;
	p=&x;
	printf("OS LAB : %d\n",*(&x));
	}

when we do gdb ./a.out then
	Output:

			(gdb) disas main
			Dump of assembler code for function main:
			   0x0000000000400596 <+0>:	push   %rbp
			   0x0000000000400597 <+1>:	mov    %rsp,%rbp
			   0x000000000040059a <+4>:	sub    $0x20,%rsp
			   0x000000000040059e <+8>:	mov    %fs:0x28,%rax
			   0x00000000004005a7 <+17>:	mov    %rax,-0x8(%rbp)
			   0x00000000004005ab <+21>:	xor    %eax,%eax
			   0x00000000004005ad <+23>:	movl   $0x5,-0x14(%rbp)
			   0x00000000004005b4 <+30>:	lea    -0x14(%rbp),%rax
			   0x00000000004005b8 <+34>:	mov    %rax,-0x10(%rbp)
			   0x00000000004005bc <+38>:	mov    -0x14(%rbp),%eax
			   0x00000000004005bf <+41>:	mov    %eax,%esi
			   0x00000000004005c1 <+43>:	mov    $0x400694,%edi
			   0x00000000004005c6 <+48>:	mov    $0x0,%eax
			   0x00000000004005cb <+53>:	callq  0x400470 <printf@plt>
			   0x00000000004005d0 <+58>:	mov    -0x10(%rbp),%rax
			   0x00000000004005d4 <+62>:	mov    (%rax),%eax
			   0x00000000004005d6 <+64>:	mov    %eax,%esi
			   0x00000000004005d8 <+66>:	mov    $0x4006a1,%edi
			   0x00000000004005dd <+71>:	mov    $0x0,%eax
			   0x00000000004005e2 <+76>:	callq  0x400470 <printf@plt>
			   0x00000000004005e7 <+81>:	mov    $0x0,%eax
			   0x00000000004005ec <+86>:	mov    -0x8(%rbp),%rdx
			   0x00000000004005f0 <+90>:	xor    %fs:0x28,%rdx
			   0x00000000004005f9 <+99>:	je     0x400600 <main+106>
			   0x00000000004005fb <+101>:	callq  0x400460 <__stack_chk_fail@plt>
			   0x0000000000400600 <+106>:	leaveq 
			   0x0000000000400601 <+107>:	retq   
			End of assembler dump.
			(gdb) 


If the base register holds 400601 and the limit register is 400596,then the program can legally access all addresses from 4000601
through 400596.

here,logical address of various instructions begin with below two instruction.
      push   %rbp
      mov    %rsp,%rbp
	bp is base pointer
	sp is stack pointer
callq check wheather address has come to the maximum adderss of stack when it comes at maximum address,then stack check failed occur
so we can say that relocation register and limit register kind of check exist and when does address binding take place.
If the base register holds 400601 and the limit register is 400596,then the program can legally access all addresses from 4000601
through 400596.