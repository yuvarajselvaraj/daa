#include<stdio.h>
int median(int arr[],int n)
{
int middle=n/2;
	if(n%2==0)
	
			return (arr[middle]+arr[middle+1])/2 ;
	else
		return arr[middle];	
}
int max(int val1,int val2)
{
if(val1>val2)
	return val1;
else
	return val2;
}
int min(int val1,int val2)
{
if(val1>val2)
	return val2;
else
	return val1;
}
int getmedian(int arr1[],int arr2[],int n)
{
	int m1,m2;
	if(n==1)
	return (arr1[0]+arr2[0])/2;
	if(n==2)
	return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;
	m1=median(arr1,n);
	m2=median(arr2,n);
	if(m1<m2)
	{
		if(n%2==0)
			return getmedian(arr1+(n/2-1),arr2,n-n/2+1);
		return getmedian(arr1+(n/2),arr2,n-n/2);
	} 
	else
	{	if(n%2==0)
			return getmedian(arr1,arr2+(n/2-1),n-n/2+1);
		return getmedian(arr1,arr2+(n/2),n-n/2);
	}
}
void main()
{
printf("Enter the number of values	:");
int n,i;
scanf("%d",&n);
int arr1[n],arr2[n];
printf("Enter the elements for array1\n");
for(i=0;i<n;i++)
{
	scanf("%d",&arr1[i]);
}
printf("Enter the elements for array2\n");
for(i=0;i<n;i++)
{
	scanf("%d",&arr2[i]);
}
printf("The median is :%d\n",getmedian(arr1,arr2,n));
}
