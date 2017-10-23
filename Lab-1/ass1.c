//Name: ABhishek yadav

//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include <ctype.h>//for isdigit function
#include<unistd.h>//one declaration was implicitly so .......
int main (int argc,char *argv[])
{
int i;
if(argc==1)
{

int system(const char *command);
//Processor type
 printf("1) Processor type\n");
  system("cat /proc/cpuinfo | grep 'model name' | awk -F: '{ print $2 }'");
 //Kernel version

  printf( "2) Kernel information\n");
  system("cat /proc/version");
 //The amount of memory configured into this computer.

   printf("3) Total memory in kB\n" );
  system("cat /proc/meminfo | grep 'MemTotal' | awk '{ print $2 }'");

//Amount of time since the system was last booted.
   printf("4) Seconds since system last booted\n");
  system("cat /proc/uptime | awk '{ print $1 }'");
printf("\n");
}

else
{
//_________________-----------____________________
//validation of input
char* p = argv[1];
    while (*p != '\0')
    {
        if (*p<'0' || *p>'9')
        {
            printf("this is not a valid number");
            return 0;
        }
        p++;
    }

char* q = argv[2];
    while (*q != '\0')
    {
        if (*q<'0' || *q>'9')
        {
            printf("this is not a valid number");
            return 0;
        }
        q++;
    }

//_________________-----------______________________-
int len,result,resul,num,num2,num1,num3,ss,ss1,ss3,ss2,free_mem,m,total_mem;
//changeing input string to integer
char str[300];
strcpy(str,argv[2]);
len = strlen(str);
for(i=0; i<len; i++)
{
result = result * 10 + ( str[i] - '0' );

}
strcpy(str,argv[1]);
//puts(argv[1]);
len = strlen(str);
for(i=0; i<len; i++)
{
resul = resul* 10 + ( str[i] - '0' );
}
char str1[3000];
//_____________________________________________________________________________________
//infinite while loop
while(5)
{
for(i=0;i<(result/resul);i++)
{
char a[20],a1[20];
FILE *fp;
//_______________________________________________________________________________
//The rate (number per second) of context switches in the kernel
fp=popen("cat /proc/stat | grep ctxt | uniq","r");
fscanf(fp,"%s %d",a,&ss);
//printf("ss is :%d\n",ss);
num+=ss;
//printf("avereage context switches in the kernel is  : %d \n",num);
//_____________________________________________________________________________________
//The rate (number per second) of process creations in the system
fp=popen("cat /proc/stat | grep processes | uniq","r");
fscanf(fp,"%s %d",a1,&ss1);
//printf("ss1 is :%d\n",ss1);
num1+=ss1;
//__________________________________________________________________________________________



fp=popen("cat /proc/diskstats | awk '{print $4}'","r");
//--------------------
///FOR LOOP
//----------------------

for(i=0;i<29;i++)
{
fscanf(fp,"%d\n",&ss2);
num2+=ss2;

}


fp=popen("cat /proc/diskstats | awk '{print $8}'","r");
for(i=0;i<29;i++)
{
fscanf(fp,"%d\n",&ss3);
num3+=ss3;

}
sleep(resul);
}
//-------------------------------------------------------------------------------------------
//The amount and percentage of available (or free) memory

FILE *ft;
ft=popen("cat /proc/meminfo | awk 'NR==2{print $2}'","r");
fscanf(ft,"%d",&free_mem);
ft=popen("cat /proc/meminfo | awk 'NR==1{print $2}'","r");
fscanf(ft,"%d",&total_mem);
m=(free_mem*100)/total_mem;
printf("The amount and percentage of available (or free) memory : %d  %d ",free_mem,m);
printf("%c", '%');

//--------------------------------------------------------------------------------------------------------------
//The percentage of time the processor(s) spend in user mode
//printf("The percentage of time the processor(s) spend in user mode  : ");
strcpy(str1,"cat /proc/stat | awk 'NR==1{print $2/($1+$2+$3+$4+$5+$6+$7+$8+$9+$10)}'");
system(str1);
// The percentage of time the processor(s) spend in system mode
//printf("The percentage of time the processor(s) spend in system mode  : ");
strcpy(str1,"cat /proc/stat | awk 'NR==1{print $4/($1+$2+$3+$4+$5+$6+$7+$8+$9+$10)}'");
system(str1);

//the percentage of time the processor(s) are idle
//printf("the percentage of time the processor(s) are idle  : ");
strcpy(str1,"cat /proc/stat | awk 'NR==1{print $5/($1+$2+$3+$4+$5+$6+$7+$8+$9+$10)}'");
system(str1);

printf("\nThe rate (number of blocks per second) of disk read and write  : %d  %d\n",num2,num3);
printf("avereage context switches in the kernel is  : %d \n",num/(result/resul));
printf("avereage rate (number per second) of process creations in the system  : %d \n",num1/(result/resul));
}

/*
OOOther commands to find answer not average
//strcpy(str1,"cat /proc/stat | grep ctxt | uniq");
//system(str1);

//The rate (number per second) of process creations in the system
strcpy(str1,"cat /proc/stat | grep processes | uniq");
system(str1);

//The rate (number of blocks per second) of disk read/write in the system
strcpy(str1,"cat /proc/diskstats | awk -F',' '{sum+=$4}END{print sum;}'");
system(str1);



//strcpy(str1,"cat /proc/meminfo | awk 'NR==2{print $2}'");
//strcpy(str3,"cat /proc/meminfo | awk 'NR==1{print $2}'");
*/
}
}
