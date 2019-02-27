#include <stdio.h>
#include<malloc.h>
typedef long long int  lli;
lli countall(lli a[],lli temp[],lli left, lli mid,lli right)
{
    lli i,j,k,calc = 0;
    i = left;
    j = mid;
    k = left;
    while((i<= mid-1)&&(j<=right))
    {
        if(a[i]<=a[j])
            temp[k++] = a[ i++];
        else
        {
            temp[k++] = a[j++];
            calc += mid - i;
        }
    }
    while(i<=mid-1)
        temp[k++] = a[i++];
    while(j<=right)
        temp[k++] = a[j++];
    for(i=left;i<=right;i++)
        a[i]=temp[i];
    return calc;
}
lli countit(lli a[],lli temp[],lli left,lli right)
{
    lli calc = 0,mid;
    if(left<right)
    {
        mid = (right + left)/2;
        calc += countit(a,temp,left,mid);
        calc += countit(a,temp,mid+1,right);
        calc += countall(a,temp,left,mid+1,right);
    }
    return calc;
}
lli violate(lli a[],lli n)
{
    lli *temp = (lli *)malloc(sizeof(lli)*n);
    return countit(a,temp,0,n-1);
}
 
int main()
{
    lli n,i,a[100001];
    scanf("%lld",&n);
    for(i = 0;i<n;i++)
        scanf("%lld",&a[i]);
    printf("%lld \n",violate(a,n));
    return 0;
}
