#include<stdio.h>
int coin_exchange(int denominations[],int n,int amt)
	{
	int i,count[n];
	for(i=0;i<n;i++){
		count[i]=0;
	}
	for(i=0;i<n;i++)
	{
		while(denominations[i]<=amt)
		{
			amt=amt - denominations[i];
			count[i]=count[i]+1;
		}
	}
	for(i=0;i<n;i++)
	{
		if(count[i] != 0)
			printf("\nThe currency Rs:%d is needed for %d time's\n",denominations[i],count[i]);
	}
	}
void main()
{
	int amt;
	printf("\n Enter the amount");
	scanf("%d",&amt);
	int denominations[8] = {2000,500,100,50,20,10,5,1};
	coin_exchange(denominations,8,amt);
	printf("The Total Amount Is Rs:%d\n",amt);
}
