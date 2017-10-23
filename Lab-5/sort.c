#include <stdio.h>
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
