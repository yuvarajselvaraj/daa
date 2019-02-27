#include<stdio.h>
void main()
{
	int n,i,j,temp1,temp2,temp3,k;
	printf("enter the number of items...");
	scanf("%d",&n);
	int item[n];
	float profit[n],weight[n];
	float weight_ratio[n],temp4;
	for(i = 0; i < n; i++){
		printf("\nEnter the Item\n");
		scanf("%d",&item[i]);
		printf("\nEnter the Profit\n");
		scanf("%f",&profit[i]);
		printf("\nEnter the weight\n");
		scanf("%f",&weight[i]);
				}
	for(i=0;i<n;i++)
{
weight_ratio[i]=profit[i]/weight[i];
}
	for(i = 0;i < n;i++)
	{
		for(j = i + 1;j < n; j++)
		{
 			if(weight_ratio[j] < weight_ratio[i])
			{
				temp1=item[i];
				item[i]=item[j];
				item[j]=temp1;

				temp2=profit[i];
				profit[i]=profit[j];
				profit[j]=temp2;

				temp3=weight[i];
				weight[i]=weight[j];
				weight[j]=temp3;
		
				temp4=weight_ratio[i];
				weight_ratio[i]=weight_ratio[j];
				weight_ratio[j]=temp4;
			}
		}
	}
	for(i = 0;i < n ;i++)
		{
		printf("\nItem is %d ",item[i]);
		printf("\nprofit is %f",profit[i]);
		printf("\nweight is %f",weight[i]);
		printf("\nweight_ratio is %f",weight_ratio[i]);	
		}
		int capacity,x;
		float profits=0.0,profit1=0.0;
		printf("\nCapacity is ");
		scanf("%d",&capacity);
		for(i=0;i<n;i++)
		{
			if(capacity>=weight[i])
				{
					x=1;
					profits=(float)x*profit[i];
					profit1=profits+profit1;
					capacity=capacity-weight[i];
					printf("capacity is %d\n",capacity);
				}
			else
				{
					float x1;
					x1=(float)capacity/weight[i];
					printf("%f\n",x1);
					profits=x1*profit[i];
					profit1=profits+profit1;
					printf("\nthe profit %f",profits);
					capacity=capacity-(x*weight[i]);
					break;
				}
		}
		printf("\nthe profit %f",profit1);
	

}
