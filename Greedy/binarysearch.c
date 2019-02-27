#include<stdio.h>
void main()
{
  int i,n,sum=0,key;
  scanf("%d",&n);
  int a[n],w;
  for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
    printf("%d",a[i]);
    }
    printf("enter key");
    scanf("%d",&key);
    w=bs(a,0,n-1,key);
    if(w==key)
    {
      printf("present");
    }
    else
     printf("NOT PRESENT");
 }
 int bs(int a[],int l,int h,int key)
 {
   int mid;
   if(l>h)
      return -1;
   else
   {
      
      mid=(l+h)/2;
      if(a[mid]==key)
        {
          return a[mid];
          }
      else if(a[mid]>key)
      {
          bs(a,l,mid,key);
          }
      else
      {
          bs(a,mid+1,h,key);
          }
    }
    }
