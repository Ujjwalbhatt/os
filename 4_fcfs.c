// Implement First Come First Serve scheduling algorithm.

// SOURCE CODE
#include<stdio.h>
int main()
{  
  int processes[10];
  int bt[10];
  int n;
  printf("Enter the number of processes: ");
  scanf("%d",&n);
  printf("Enter the processes: ");
  for(int i=0;i<n;i++)
  {
     scanf("%d",&processes[i]);
  }
  printf("Enter the burst time : ");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&bt[i]);
  }
  
   int wt[n];
   wt[0] = 0;
   for(int i=1;i<n;i++)
   {
       wt[i] = bt[i-1] + wt[i-1];
   }
   
   printf("Processes\tbursttime\twaitingtime\tturnaroundtime\n");
   float twt = 0.0;
   float tat = 0.0;
   for(int i=0;i<n;i++)
   {
      printf("%d\t\t",processes[i]);
      printf("%d\t\t",bt[i]);
      printf("%d\t\t",wt[i]);
      printf("%d\t\t",bt[i]+wt[i]);
      printf("\n");
      twt += wt[i];
      tat += (wt[i]+bt[i]);
   }
   float att,awt;
   awt = twt/n;
   att = tat/n;
   printf("Avg wait time = %f\n",awt);
   printf("Avg turnaround time = %f\n",att);
}