// srjf preemptive
#include <stdio.h>
#include<math.h>
#include<limits.h>
int main()
{
    printf("enter the number of process\n");
    int n;
    scanf("%d",&n);

    int at[n],bt[n],pid[n];
    for(int i=0;i<n;i++){
        pid[i]=i+1;
        printf("enter the arrival time of %d procces:",i+1);
        scanf("%d",&at[i]);
        printf("enter the burst time of %d procces:",i+1);
        scanf("%d",&bt[i]);
    }
    int remainingTime[n];
    for(int i=0;i<n;i++)
    remainingTime[i]=bt[i];
    
    int ct[n],tat[n],wt[n];
    int nProComp=0; // number of process completed
    int currentTime=0; // current time
        while(nProComp!=n){
        // finding shortes job among all
        int shortestJob = -1; // index of shortest job
        int shortestTime = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && remainingTime[i] < shortestTime && remainingTime[i] > 0) {
                shortestJob = i;
                shortestTime = remainingTime[i];
            }
        }
        int shortestJobIndex=shortestJob;
        if (shortestJobIndex == -1) {
            currentTime++;
            continue;
        }
        remainingTime[shortestJobIndex]--;
        if (remainingTime[shortestJobIndex] == 0) {
            nProComp++;
            ct[shortestJobIndex] = currentTime + 1;
        }

        currentTime++;
        
    }
    
    float avgTat=0,avgWat=0;
    for(int i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avgTat+=tat[i];
        avgWat+=wt[i];
    }
   printf("\npid\t A.T\t B.T\t C.T\t TAT\t WT");
   for(int i=0;i<n;i++)
    {
      printf("\nP%d\t %d\t %d\t %d\t %d\t %d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
   (avgTat)/=n;
    (avgWat)/=n;
    printf("\navgTat : %f\n",avgTat);
    printf("avgWt : %f",avgWat);
}


