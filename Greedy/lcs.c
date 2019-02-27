#include<stdio.h>
#include<string.h>
#define size 15 
int LongestCommonSubsequence(char X[], char Y[]);
void main()
{
char X[size], Y[size];
printf("Enter the Sequence 1 : ");
scanf("%s", X);
printf("Enter the Sequence 2 : ");
scanf("%s", Y);
printf("Length of the LCS of sequences %s and %s is %d\n", X, Y,
LongestCommonSubsequence(X,Y));
}
int LongestCommonSubsequence(char X[], char Y[])
{
int L1 = strlen(X), L2 = strlen(Y), LCS[L1 + 1][L2 + 1], i, j;
for(i = 0; i <= L1; i++)
LCS[i][0] = 0;
for(j = 0; j <= L2; j++)
LCS[0][j] = 0;
for(i = 1; i <= L1; i++)
{
for(j = 1; j <= L2; j++)
{
if(X[i-1] == Y[j-1])
LCS[i][j] = 1 + LCS[i-1][j-1];
else
LCS[i][j] = Max(LCS[i-1][j], LCS[i][j-1]);
}
}
for(i = 0; i <= L1; i++)
{
for(j = 0; j <= L2; j++)
printf("%d ", LCS[i][j]);
printf("\n");
}
return LCS[L1][L2];
}
int Max(int a, int b)
{
return (a>b) ? a : b;
}

