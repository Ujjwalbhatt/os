//Sample Input
// Total number of process in the system: 4
// Enter the Arrival and Burst time of the Process[1]: 0 5
// Enter the Arrival and Burst time of the Process[2]: 1 4
// Enter the Arrival and Burst time of the Process[3]: 2 2
// Enter the Arrival and Burst time of the Process[4]: 4 1
// Enter the Time Quantum for the process: 2
//Sample Output
// At      Bt      Ct      Tat     Wt
// 0       5       12       12      7
// 1       4       11       10      6
// 2       2       6         4      2
// 4       1       9         5      4

#include <stdio.h>
#include <conio.h>
void main()
{
  int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10],ct[10];
  float avg_wt, avg_tat;
  printf(" Total number of process in the system: ");
  scanf("%d", &NOP);
  y = NOP;
  for (i = 0; i < NOP; i++)
  {
    printf("\nEnter the Arrival and Burst time of the Process[%d]: ", i + 1);
    scanf("%d%d", &at[i], &bt[i]);
    temp[i] = bt[i];
  }
  printf("Enter the Time Quantum for the process:");
  scanf("%d", &quant);
  for (sum = 0, i = 0; y != 0;)
  {
    if (temp[i] <= quant && temp[i] > 0)
    {
      sum = sum + temp[i];
      temp[i] = 0;
      count = 1;
    }
    else if (temp[i] > 0)
    {
      temp[i] = temp[i] - quant;
      sum = sum + quant;
    }
    if (temp[i] == 0 && count == 1)
    {
      y--; // decrement the process no.
      ct[i]=sum; // calculate the completion time
      count = 0;
    }
    if (i == NOP - 1)
      i = 0;

    else if (at[i + 1] <= sum)
      i++;

    else
      i = 0;
  }
  printf("At\t\tBt\t\tCt\t\tTat\t\tWt\n");
  for(i=0;i<NOP;i++)
  {
      tat=ct[i]-at[i];
      wt=tat-bt[i];
      avg_tat+=tat;
      avg_wt+=wt;
      printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",at[i],bt[i],ct[i],tat,wt);
  }
  avg_tat/=NOP;
  avg_wt/=NOP;
  printf("\nAverage Turn Around Time:\t%f", avg_wt);
  printf("\nAverage Waiting Time:\t%f", avg_tat);
}
