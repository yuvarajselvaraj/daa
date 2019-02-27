#include<stdio.h>
int minmax(int *a,int l,int h,int *min,int *max)
 {
  int min1,max1,mid;
  if(l==h)
    *min=*max=a[l];
  else if(l==(h-1))
  {
   if(a[l]>a[h])
     {
       *min=a[h];
       *max=a[l];
     }
    else
      {
        *min=a[l];
        *max=a[h];
      }
    }
  else
   {
      mid=(l+h)/2;
      minmax(a,l,mid,(int *)min,(int *)max);
      minmax(a,mid+1,h,&min1,&max1);
      if(*max<max1)
        {
         *max=max1;
         }
      if(*min>min1)
       {
          *min=min1;
         }
   }

 }
void main()
{ 
 int *min,*max;
  int ab=0,bc=0;
   min=&ab;
   max=&bc;
 int a[]={50,40,-5,-9,45,90,65,25,75};
   
 minmax(a,0,8,(int *)min,(int*)max);
 printf("min  %d  \n  max %d",*min,*max);
}
