#include<stdio.h>
void main()
{
	int n,i,j,key;	
	int temp,temp1,temp2,temp3;	
	printf("\n entetr number of jobs  :");
	scanf("%d",&n);
	int job[n],limit[n],pro[n],t[n];	
	printf("\n enter values of jobs  :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&job[i]);
	}

	printf("\n enter deadline  of jobs :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&limit[i]);
	}

	printf("\n enter profit  of jobs :\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pro[i]);
	}
	for(i=0;i<n;i++)
	{
		t[i]=0;
	}

	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(pro[j] < pro[j+1]){
			temp=pro[j];
			pro[j]=pro[j+1];
			pro[j+1]=temp;

			temp1=job[j];
			job[j]=job[j+1];
			job[j+1]=temp1;

			temp2=limit[j];
			limit[j]=limit[j+1];
			limit[j+1]=temp2;			
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(t[limit[i]]==0) 
	                               	{
			t[limit[i]]=job[i];
		}
		else
		{
			key = limit[i];
			for(j=key-1;j>=0;j--)
			{
				if(t[j]==0) 
				{
					t[j]=job[i];
					break;
				}
			}
		}
	}
	printf("\n job order \n ");
	for(i=0;i<n;i++)
	{
		printf(" jobs : %d \n ",t[i]);
	}
								
}
	
