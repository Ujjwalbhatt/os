// Q-  Implement Wait System Call.
// SOURCE CODE
#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
   pid_t p;
   printf("before fork\n");
   p = fork();
   if(p==0) // child 
   {
     printf("I am child having %d\n",getpid());
     printf("My parents id is %d\n",getppid());
   }
   else // parent 
   {
     wait(NULL);
     printf("My child id is %d\n",p);
     printf("I am parent having id %d\n",getpid());
   }
  printf("outside");
}