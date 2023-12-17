// FCFS Disk Scheduling algorithm
#include <stdio.h>
#include <math.h>


int main()
{
    int head,n;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Requests sequence\n");
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);
    printf("Enter initial head position\n");
	scanf("%d",&head);
	int seek_count = 0;
	int cur_track, distance;
	for(int i=0;i<n;i++)
	{
		cur_track = arr[i];
		distance = fabs(head - cur_track);
		seek_count += distance;
		head = cur_track;
	}
	printf("Total number of seek operations: %d\n",seek_count);
	return 0;
}

