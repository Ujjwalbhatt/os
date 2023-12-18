#include<stdio.h>
#include<limits.h>
#include<math.h>

int main(){
    printf("Enter the vlaue of n: ");
    scanf("%d",&n);
    int at[n],bt[n],rt[n],tat[n],wt[n],ct[n],pid[n],c;
    for (int i = 0; i < n; i++)
    {
        pid[i] = i+1;
        printf("Enter the value of arrival time and burst time : ");
        scanf("%d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }
    int nprocomp = 0;
    int c=0;
    while(nprocomp!=n){
        int shortjob = -1;
        int shortTime = INT_MAX;
    for(int i=0;i<n;i++){
        if(at[i]>=ct && rt[i]<shortTime && rt[i]>0  ){
            shortjob = i;
            shortTime = rt[i];
        }
    }
        int shortestJobIndex = shortjob;
        if(rt[shortestJobIndex] == -1){
            c++;
            continue;
        }
        rt[shortestJobIndex]--;
        if(rt[shortestJobIndex] == 0){
            nprocomp++;
            ct[shortestJobIndex] = c+1;
        }
        c++;
    }
    printf("p%d\t%d\t%d\t%d")
    }