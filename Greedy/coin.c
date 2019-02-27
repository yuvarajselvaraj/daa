#include<stdio.h>
void main(){
int den,i,j;
printf("Enter number of Denominations : ");
scanf("%d",&den);
int deno[den];
int count[den];
printf("Enter the Denominations : \n");
for(i=0;i<den;i++){
scanf("%d",&deno[i]);
count[i]=0;
}
for(i=0;i<den;i++){
 for(j=0;j<den;j++){
  if(deno[i]>deno[j]){
  int temp=deno[i];
   deno[i]=deno[j];
   deno[j]=temp;
}}}
int amount;
printf("Enter the Amount for Changinging : ");
scanf("%d",&amount);
i=0;
while(amount>=deno[den-1]){
if(amount>=deno[i]){
count[i]++;
amount-=deno[i];
}
else{
i++;
}
}
int flag=1;
for(i=0;i<den;i++){
if(count[i]!=0){
printf("Rs.%d coin is used  : %d \n",deno[i],count[i]);
flag=0;
}
}
if(flag)
 printf("!!! No change can be given !!!\n");
}
