#include<stdio.h>
#include<kernel/console.h>
#include "threads/thread.h"
#include "hello.h"
#include "random.h"
#include "devices/timer.h"
int s=10,temp,i,j,k,arr[18];
void print_priority(void);
void print_thread_name(void);
void print_tid(void);
void helloworld(void)
{
printf("<<<<<----------hello,This is Abhishek Yadav------->>>>>>>\n");

thread_create("th4",PRI_MIN,(thread_func *)print_priority,NULL);
thread_yield ();
thread_create("th5",PRI_DEFAULT,(thread_func *)print_tid,NULL);
thread_yield ();
thread_create("th6",PRI_DEFAULT,(thread_func *)print_thread_name,NULL);
thread_yield ();
thread_print_stats();
}
void print_priority(void)
{
    printf("starting of Thread number :1\n");
    for(i=0;i<10000;i++)
    {
       for(j=0;j<1000;j++)
        {
                for(k=0;k<100;k++)
                {}
        }
    }
    //this function will print thread priority
        printf("thread_priority = %d\n",thread_get_priority());
  //thread_print_stats();
  printf("ending of Thread number :1\n");
  thread_exit();
}//this function will print thread ID
void print_tid(void)
{
        printf("starting of Thread number :2\n");
        printf("thread_id = %d\n",thread_tid());
        //thread_print_stats();
        printf("ending of Thread number :2\n");
        thread_exit();
}
//this function will print its thread name
void print_thread_name(void)
{
        printf("starting of Thread number :3\n");
        printf("thread_name = %s\n",thread_name());
        //thread_print_stats();
        printf("ending of Thread number :3\n\n");
        thread_exit();
}
