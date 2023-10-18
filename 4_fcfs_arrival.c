//Fcfs with arrival time

#include<stdio.h>
#include<math.h>

void swap(int *a,int *b)
{
	int temp= *a;
	*a=*b;
	*b=temp;
}

int main()
{
	printf("Enter the number of processes\n");
	int n;
	scanf("%d",&n);
	
	int pid[n],at[n],bt[n],ct[n],wt[n],tat[n];
	int gap;
	
	for(int i=0;i<n;i++)
	{
		pid[i]=i+1;
		
		printf("Enter the arrival time and burst time for p%d\n",i+1);
		scanf("%d%d",&at[i],&bt[i]);
	}
    for(int i=0;i<n-1;i++)
    {
    	int min=at[i];
    	int pos=i;
    	for(int j=i+1;j<n;j++ )
    	{
    		if(at[j]<min)
    		{
    			min=at[j];
    			pos=j;
    		
			}
		}
		if(pos!=i)
		{
			swap(&pid[i],&pid[pos]);
			swap(&at[i],&at[pos]);
			swap(&bt[i],&bt[pos]);
           
		}
        for(int i=0;i<n;i++)
         printf("pid[i]=%d at[i]=%d bt[i]=%d\n",pid[i],at[i],bt[i]);
         printf("--------\n");
	}
	
	ct[0]=at[0]+bt[0];
	
	for(int i=1;i<n;i++)
	{
		if(ct[i-1]>=at[i])
		{
			ct[i]=ct[i-1]+bt[i];
		}
		else
		{
			int gap=at[i]-ct[i-1];
			ct[i]=ct[i-1]+bt[i]+gap;
		}
	}
	float awt=0,atat=0;
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		awt+=wt[i];
		atat+=tat[i];
	}
	awt=awt/n;
	atat=atat/n;
	printf("pid\t\tat\t\tbt\t\tct\t\ttat\t\twt\n");
	for(int i=0;i<n;i++)
	{
		printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	printf("Avg TAT : %f\n",atat);
	printf("Avg WT : %f\n",awt);
}