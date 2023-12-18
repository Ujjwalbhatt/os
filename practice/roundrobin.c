#include<stdio.h>
int main(){
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int i=0,at[n],bt[n],pid[n],tat[n],wt[n],sum=0,y=0,temp[n],quant,count=0,ct[n];
    printf("Enter the value of arrival time and burst time: ");
    for (int i = 0; i < n; i++)
    {
        pid[i] = i+1;
        scanf("%d%d",&at[i],&bt[i]);
        temp[i] = bt[i];  
    }
    printf("Enter the value of quant: ");
    scanf("%d",&quant);
    y=n;
    for (sum = 0,i=0;y!=0;)
    {
        if(temp[i]<=quant && temp[i]>0){
            sum = sum+temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if(temp[i]>0){
            sum = sum+quant;
            temp[i] = temp[i]-quant;
        }
        if(temp[i]==0 && count == 1){
            y--;
            count = 0;
            ct[i] = sum;
        }
        if(i==n-1){
            i=0;
        }
        else if(at[i]<=sum){
            i++;
        }
        else{
            i=0;
        }
    }

    printf("p\tAT\tBT\tCT\tTAt\tWT\n");
    float avg_tat=0;
    float avg_wat=0;
    for (int i = 0; i < n; i++)
    {
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];
            avg_tat= avg_tat+tat[i];
            avg_wat= avg_wat+wt[i];
            printf("p%d\t%d\t%d\t%d\t%d\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    avg_tat = avg_tat/n;
    avg_wat = avg_wat/n;
    printf("average tat = %f and average wt=%f",avg_tat,avg_wat);
    return 0;
}