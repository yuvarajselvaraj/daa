#include<stdio.h>
void main(){
int n,i,j;
printf("Enter number of activity : ");
scanf("%d",&n);
int start[n],end[n];
printf("*** Enter the starting and ending time ***\n");
for(i=0;i<n;i++){
printf("Task : %d \n",i+1);
scanf("%d %d",&start[i],&end[i]);
}
int pos=0;
printf("List of Activity : 1");
for(i=1;i<n;i++){
if(start[i]>=end[pos]){
printf(", %d",i+1);
pos=i;
}
}
printf(".\n");
}
