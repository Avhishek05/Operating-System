#include<stdio.h>
int main()
{
int j,i;
//printing the address of a variable
printf("%p",&i);
for(j=0;j<5000;j++)
{
printf("%p",&j);
printf("\n");
}
return 0;
}
