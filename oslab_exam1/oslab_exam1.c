//program to implement bound wait matual exclusion using test_and_set
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int test_and_set(int* lock)
{
int initial = *lock;
if(*lock)
*lock = 0;
else *lock = 1;
return initial;
}
int main()
{
int lock = 0;
pid_t pid = fork();
if(pid < 0)
{
printf("no child process created\n");
return 1;
}
else if(!pid)
{
//child process consuming product of parent
do{
while(test_and_set(&lock) == 1);
printf("child process locked value is :");

printf("%d\n",lock);
}
while(1);
}
else
{
//parent process which is the producing product
do{
while(test_and_set(&lock) == 0);
printf("parent process locked value is :");
printf("%d\n",lock);
}while(1);
}
return 0;
}
