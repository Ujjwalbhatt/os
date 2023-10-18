//Non preemptive sjf

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
    	int min=bt[i];
    	int pos=i;
    	for(int j=i+1;j<n;j++ )
    	{
    		if(bt[j]<min)
    		{
    			min=bt[j];
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
    		ct[i]=at[i]+bt[i]+gap;
    	}
    }

    for(int i=0;i<n;i++)
    {
    	tat[i]=ct[i]-at[i];
    	wt[i]=tat[i]-bt[i];
    }

    float avgTat=0,avgWat=0;
    for(int i=0;i<n;i++)
    {
    	avgTat+=tat[i];
    	avgWat+=wt[i];
    }
    avgTat/=n;
    avgWat/=n;
    printf("pid\t AT\t BT\t CT\t TAT\t WT\n");
    for(int i=0;i<n;i++)
    {
    	printf("%d\t %d\t %d\t %d\t %d\t %d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Avg TAT : %f\n",avgTat);
    printf("Avg WT : %f\n",avgWat);

    return 0;

}