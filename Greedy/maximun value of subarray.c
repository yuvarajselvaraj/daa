#include<stdio.h>
int max(int val1,int val2,int val3)
{
if(val1>val2)
{
if(val1>val3)
	return val1;
else
	return val3;
}
if(val2>val1)
{
if(val2>val3)
	return val2;
else
	return val3;
}
}
int crosssum(int a[],int low,int middle,int high)
{
int leftsum=0,leftmax=-999,i;
for(i=middle;i>=low;i--)
{
	leftsum=leftsum+a[i];
	if(leftsum>leftmax)
		leftmax=leftsum;	
}
int rightsum=0,rightmax=-999;
for(i=middle+1;i<=high;i++)
{
	rightsum=rightsum+a[i];
	if(rightsum>rightmax)
		rightmax=rightsum;	
}
return leftmax+rightmax;
}

int maxsubarray(int a[],int low,int high)
{
int middle;
if(low==high)
	return a[low];
else
	{
	middle=(low+high)/2;
	return max(maxsubarray(a,low,middle),maxsubarray(a,middle+1,high),crosssum(a,low,middle,high));
}
}

void main()
{
printf("Enter the number of values	:");
int n,i;
scanf("%d",&n);
int a[n];
printf("Enter the elements\n");
for(i=0;i<n;i++)
{
	scanf("%d",&a[i]);
}
printf("The maximum value of subarray is :%d\n",maxsubarray(a,0,n-1));
}

