#include<stdio.h>
void main(){
int i,j,n;
int max;
int rc;
printf("Enter the maximun capacity : ");
scanf("%d",&max);
printf("Enter number of Items : ");
scanf("%d",&n);
float x[n];
int w[n];
int p[n];
float ratio[n];
float profit=0;
printf("*** Enter profit and weight ***\n");
for(i=0;i<n;i++){
 x[i]=0;
 printf("Item : %d\n",i+1);
 scanf("%d %d",&p[i],&w[i]);
 ratio[i]=(float)p[i]/(float)w[i];
}
for(i=0;i<n;i++){
 for(j=0;j<n;j++){
  if(ratio[i]>ratio[j]){
   int temp1=w[i];
   w[i]=w[j];
   w[j]=temp1;
   int temp2=p[i];
   p[i]=p[j];
   p[j]=temp2;
   float temp3=ratio[i];
   ratio[i]=ratio[j];
   ratio[j]=temp3;
  }
 }
 }
rc=max;
i=0;
while(rc){
 if(w[i]<=rc){
  x[i]=1;
  profit+=p[i]*x[i];
  rc-=w[i];
 }
 else{
  x[i]=(float)rc/(float)w[i];
  profit+=p[i]*x[i];
  rc=0;
 }
 i++;
}
printf("Profit : %.2f\n",profit);
}
