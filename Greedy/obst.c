#include<stdio.h>
#include<limits.h>
float OptimalBinarySearchTree(float Freq[], int n);
float Sum(float Freq[], int i, int j);
void main()
{
int n, i;
printf("Enter the value of n : ");
scanf("%d", &n);
float Freq[n];
printf("Enter the frequency for %d keys :\n", n);
for(i=1; i<=n; i++)
{
printf("Enter the frequency for key %d : ", i);
scanf("%f", &Freq[i]);
}
printf("Cost of Optimal BST is %.2f\n", OptimalBinarySearchTree(Freq, n));
}
float OptimalBinarySearchTree(float Freq[], int n)
{
int size = n+1;
float OBST[size][size], Freqsum, MinVal, x;
int Root[size][size], i, j, k, L, R;
// Initial Table
for(i=0; i<size; i++)
{
for(j=0; j<size; j++)
{
OBST[i][j] = 0.0;
Root[i][j] = 0;
}
}
for(i=1; i<size; i++)
{
OBST[i][i-1] = 0.0;
OBST[i][i] = Freq[i];
Root[i][i] = i;
}
for(L = 2; L < size; L++)
{
for(i = 1; i < size-L+1 ; i++)
{
j = i+L-1;MinVal = (float)INT_MAX;
Freqsum = Sum(Freq, i, j);
for(k = i; k <= j; k++)
{
x = OBST[i][k-1] + OBST[k+1][j] + Freqsum;
if(x < MinVal)
{
MinVal = x;
R = k;
}
}
OBST[i][j] = MinVal;
Root[i][j] = R;
}
}
printf("Main Table :\n");
for(i=0; i<size; i++)
{
for(j=0; j<size; j++)
printf("%.2f ", OBST[i][j]);
printf("\n");
}
printf("Root Table :\n");
for(i=0; i<size; i++)
{
for(j=0; j<size; j++)
printf("%d ", Root[i][j]);
printf("\n");
}
return OBST[1][n];
}
float Sum(float Freq[], int i, int j)
{
int t;
float totalFreq = 0.0;
for(t = i; t <= j; t++)
totalFreq += Freq[t];
return totalFreq;
}

