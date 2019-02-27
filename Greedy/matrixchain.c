#include<stdio.h>
#include<limits.h>
int MatrixChainMultiplication(int P[], int n);
void main() {
int n, i;
printf("Enter the value of n : ");
scanf("%d", &n);
int P[n];
printf("Enter %d Dimensions for %d Matrices : ", n, n-1);
for(i=0; i<n; i++)
scanf("%d", &P[i]);printf("Minimum no. of operations to perform Multiplication of %d Matrices is %d\n", n-1,
MatrixChainMultiplication(P, n));
}
int MatrixChainMultiplication(int P[], int n) {
int M[n-1][n-1], i, j, k, MinVal, L;
// Initial Table
for(i = 1; i < n; i++)
for(j = 1; j < n; j++)
M[i][j] = 0;
//for(i = 1; i < n; i++)
//
M[i][i] = 0;
for(L = 2; L < n; L++) {
for(i = 1; i < n-L+1 ; i++) {

j = i+L-1;
MinVal = INT_MAX;
for(k = i; k < j; k++) {
MinVal = Min(MinVal, M[i][k] + M[k+1][j] + (P[i-1]*P[k]*P[j]));
}
M[i][j] = MinVal;
}
}
for(i=1; i<n; i++) {
for(j=1; j<n; j++)
printf("%d ", M[i][j]);
printf("\n");
}
return M[1][n-1];
}
int Min(int a, int b) {
return (a<b) ? a : b;
}

