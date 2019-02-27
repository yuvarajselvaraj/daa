#include<stdio.h>
main(){
int n,i,j,temp,temp1,temp2;
printf("enter the number of jobs:");
scanf("%d",&n);
int job[n],d[n],p[n],max,sol[100];
for(i=1;i<=n;i++){
printf("enter the job:");
scanf("%d",&job[i]);
printf("enter the deadline:");
scanf("%d",&d[i]);
printf("enter the profit:");
scanf("%d",&p[i]);
}
for(i=0;i<=n;i++){
	sol[i]=0;
}
max=d[1];
for(i=2;i<=n;i++){
	if(d[i]>max){
		max=d[i];
	}
}
printf("maximum is :%d",max);
for(i=1;i<=n;i++){
for(j=i+1;j<=n;j++){
if(p[i]>p[j]){
temp=p[i];
p[i]=p[j];
p[j]=temp;

temp1=job[i];
job[i]=job[j];
job[j]=temp1;


temp2=d[i];
d[i]=d[j];
d[j]=temp2;
}
}
}
for(i=1;i<=n;i++){
	for(j=d[i];j>=1;j--){
		if(sol[j]==0){
			printf("the solution is :%d",sol[j]);
			sol[j]=job[i];
			break;
		}
	}
}
for(i=1;i<=max;i++){
printf("%d",sol[i]);
}
}
			

