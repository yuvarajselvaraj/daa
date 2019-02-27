#include<stdio.h>
int[] sma(int a[],int b[],int n);
main(void){
int a[2][2],b[2][2],i,j;
printf("\n Enter the A matrix");
for(i=0;i<2;i++){
for(j=0;j<2;j++){
scanf("%d%d",&a[i][j]);
}
}
printf("\n Enter the B matrix");
for(i=0;i<2;i++){
for(j=0;j<2;j++){
scanf("%d%d",&b[i][j]);
}
}
int rs=sma(a,b,2);
printf("%d",rs);
}
int[][] sma(int a[][],int b[][],int n)
{
int p1,p2,p3,p4,p5,p6,p7,c[2][2];

 if(n==1)
return a*b;
else{
p1=sma(a[0][0],(b[0][1])-b[1][1],n/2);
p2=sma(a[1][1],(a[0][0]+a[0][1]),n/2);
p3=sma(b[0][0],(a[1][0]+a[1][1]),n/2);
p4=sma(a[1][1],(b[1][0]-b[0][0]),n/2);
p5=sma((a[0][0]+a[1][1]),(b[0][0]+b[1][1]),n/2);
p6=sma((a[0][1]-a[1][1]),(b[1][0]+b[1][1]),n/2);
p7=sma((a[0][0]-a[1][0]),(b[0][0]+b[0][1]),n/2);
c[0][0]=p4+p5+p6-p2;
c[0][1]=p1+p2;
c[1][0]=p3+p4;
c[1][1]=p1+p5-p3-p7;
return c;}}

