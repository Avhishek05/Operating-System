//Name: ABhishek yadav
//ID: 2015KUCP1008
//
#include  <stdio.h>
#include <stdlib.h>
#include  <sys/types.h>
#include <unistd.h>
void  parse(char *line, char **argv)
{
     while (*line != '\0') {      
          while (*line == ' ' || *line == '\t' || *line == '\n' )
               *line++ = '\0';    
          *argv++ = line;     
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;        
     }
     *argv = '\0';
}

void  execute(char **argv)
{
     pid_t  pid;
     int    status;

     if ((pid = fork()) < 0) { 
          printf("forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) {      
          if (execvp(*argv, argv) < 0) { 
               printf("\nExecution failed.\n");
               exit(1);
          }
     }
     else {                              
          while (wait(&status) != pid)   
               ;
     }
}
void chdirectory(char * dir){
//cwd=getcwd(argv,100);      // get the current working directory and save it to cwd
  //      cwdtemp=cwd;                //save current directory as string to cwdtemp
    //    printf("%s",cwd);
  if(dir=='\0'){              //if user entered nothing after cd
        chdir( "/home/" );      //change to home
    }else{
        if(chdir(dir)==-1){     //if chdir function returned error  
            printf("%s:directory does not exist\n",dir);
        }
    }
//chdir(dir);

}

void  main(void)
{
     char  line[1024];
     char  *argv[64]; 

     while (1) {      
          printf("avhishekydv~> ");
	   
          gets(line);          
          printf("\n");
          parse(line, argv);   
          if (strcmp(argv[0], "exit") == 0)
               exit(0);
	  else if(strcmp(argv[0],"cd") == 0)
       chdirectory(argv[1]);  
	else 
       	execute(argv);
     }
}
