// Q2-  Implement Multiple Fork System Call.

// SOURCE CODE

#include<stdio.h>
#include<unistd.h>
int main()
{
fork();
fork();
printf("LINUX \n");
return 0;
}