#include<stdio.h>
#include<kernel/console.h>
#include<random.h>
#include<threads/malloc.h>
#include<threads/init.h>
#include<threads/thread.h>
#include<devices/timer.h>
#define NUMBER 10
int sortnumber ()
{
  static int arr[NUMBER];
  int i,j,temp;
  //genrating random numbers
  random_bytes(arr,10*sizeof(i));
  //bubble sort to sort random numbers
  for (i = 0; i < NUMBER-1;i++)
    for (j = 0; j < NUMBER-1- i; j++)
      if (arr[j] > arr[j+1])
	{
	  temp = arr[j];
	  arr[j] = arr[j+1];
	  arr[j + 1] = temp;
	}
	for (i=0;i<NUMBER;i++)
  {
    printf("%d\n", arr[i]);
  }

}

void test_sort()
{
  thread_create("sorting",PRI_DEFAULT+1,(thread_func *)sortnumber,NULL);
printf("thread successfully created");
  timer_sleep(100);

}
