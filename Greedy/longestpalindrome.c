#include<stdio.h>
#include<string.h>
#define size 15
int LongestPalindromeSubsequence(char X[]);
void main()
{
char X[size];
printf("Enter the Sequence : ");
scanf("%s", X);
printf("Length of the LPS of sequence %s is %d\n", X,
LongestPalindromeSubsequence(X));
}
int LongestPalindromeSubsequence(char X[])
{
int n = strlen(X), LPS[n][n], i, j, L;
// Initial Table
for(i = 0; i < n; i++)
for(j = 0; j < n; j++)
LPS[i][j] = 0;
for(i = 0; i < n; i++)
LPS[i][i] = 1;
for(L = 2; L <= n; L++){
for(i = 0; i < n-L+1 ; i++)
{
j = i+L-1;
if(j == i+1 && X[i] == X[j])
LPS[i][j] = 2;
else if(j == i+1 && X[i] != X[j])
LPS[i][j] = 1;
else if(X[i] == X[j])
LPS[i][j] = LPS[i+1][j-1] + 2;
else
LPS[i][j] = Max(LPS[i+1][j], LPS[i][j-1]);
}
}
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
printf("%d ", LPS[i][j]);
printf("\n");
}
return LPS[0][n-1];
}
int Max(int a, int b)
{
return (a>b) ? a : b;
}

