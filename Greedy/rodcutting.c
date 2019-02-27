#include<stdio.h>
#include<limits.h>
int RodCuttingDP(int RodSize[], int Profit[], int n);
void main()
{
int n;printf("Enter the value of n : ");
scanf("%d", &n);
int RodSize[n], Profit[n], i;
for(i=1; i<=n; i++)
{
RodSize[i] = i;
printf("Enter the Profit of Rod size %d : ", i);
scanf("%d", &Profit[i]);
}
printf("Maximum profit attained by cutting the rod of length %d is %d\n", n,
RodCuttingDP(RodSize, Profit, n));
}
int RodCuttingDP(int RodSize[], int Profit[], int n)
{
int i, k, B[n], MaxVal;
B[0] = 0;
B[1] = Profit[1];
for(i=2; i<=n; i++)
{
MaxVal = INT_MIN;
for(k=1; k<=i; k++)
{
MaxVal = Max(MaxVal, Profit[k] + B[i-k]);
}
B[i] = MaxVal;

}
for(i=1; i<=n; i++)
printf("B[%d] = %d\n", i, B[i]);
return MaxVal;
}
int Max(int a, int b)
{
return (a>b) ? a : b;
}

