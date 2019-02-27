#include<stdio.h>
void tower(int n, char source, char temp, char dest)
{
if(n>0)
{
tower(n-1,source,dest,temp);
printf("Move disc %d from %c to %c\n", n,source,dest);
tower(n-1, source, temp, dest);
}
}
main()
{
int n;
printf("enter n");
scanf("%d",&n);
tower(n,'A','B','C');
}

