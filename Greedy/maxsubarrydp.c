#include<stdio.h>
int MaxSubArrayDP(int A[], int n);
void main()
{
int n;
printf("Enter the value of n : ");
scanf("%d", &n);
int A[n], i;
printf("Enter %d Elements :\n", n);
for(i=0; i<n; i++)
scanf("%d", &A[i]);
printf("MaxSubArray sum is %d\n", MaxSubArrayDP(A, n));
}
int MaxSubArrayDP(int A[], int n)
{
int i, S[n], CurrMax;
= Max(CurrMax, S[i]);
} S[0] = A[0];
CurrMax = A[0];
for(i=1; i<n; i++)
{
S[i] = Max(S[i-1] + A[i], A[i]);
CurrMax
return CurrMax;
}
int Max(int a, int b)
{
return (a>b) ? a : b;
}

