#include<stdio.h>
void main()
{
	int n,i,ended,count = 1;
	printf("\nEnter the Number of Jobs\n");
	scanf("%d",&n);
	int job[n],start[n],end[n];
	for(i = 0 ; i < n ; i++)
		{
			printf("\nEnter the Job Number");
			scanf("%d",&job[i]);
			printf("\nEnter the Start Time");
			scanf("%d",&start[i]);
			printf("\nEnter the End Time");
			scanf("%d",&end[i]);
		}
	printf("\nThe Job 1 is done Without Overlapping");
	ended = end[0];
	for(i = 1;i < n;i++)
		{
		if(end[i-1] >= ended)
			ended = end[i-1];
		if(start[i] >= ended)
			{
			printf("\nThe Job %d is done Without Overlapping",job[i]);
			count++;
			}
		}
	printf("\nThe Total No. of Jobs Done is %d",count);
}
