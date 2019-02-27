#include<stdio.h>
int Knapsack_01(int Item[], int Profit[], int Weight[], int Capacity, int n);
void main()
{
int n, i;
printf("Enter the value of n : ");
scanf("%d", &n);
int Item[n], Profit[n], Weight[n], Capacity;
printf("Enter %d items Profit and Weight :\n", n);
for(i=1; i<=n; i++)
{
Item[i] = i;
printf("Enter item %d Profit and Weight : ", Item[i]);
scanf("%d %d", &Profit[i], &Weight[i]);
}
printf("Enter the Knapsack Capacity : ");
scanf("%d", &Capacity);
printf("Maximum Profit attained with Knapsack of capacity %d with %d Items is %d\n",
Capacity, n, Knapsack_01(Item, Profit, Weight, Capacity, n));
}
int Knapsack_01(int Item[], int Profit[], int Weight[], int Capacity, int n)
{
int Knapsack01[n + 1][Capacity + 1], i, j;
for(i = 0; i <= n; i++)
Knapsack01[i][0] = 0;
for(j = 0; j <= Capacity; j++)
Knapsack01[0][j] = 0;
for(i = 1; i <= n; i++)
{
for(j = 1; j <= Capacity; j++)
{
if((j - Weight[i]) < 0)
Knapsack01[i][j] = Knapsack01[i-1][j];
else
Knapsack01[i][j] = Max(Knapsack01[i-1][j], Profit[i] +
Knapsack01[i-1][j-Weight[i]]);
}
}for(i = 0; i <= n; i++)
{
for(j = 0; j <= Capacity; j++)
printf("%d ", Knapsack01[i][j]);
printf("\n");
}
return Knapsack01[n][Capacity];
}
int Max(int a, int b)
{
return (a>b) ? a : b;
}

