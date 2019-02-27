#include<stdio.h>
int PrimsAlg(int n, int Cost[][n]);

void main()
{
	int n;

	printf("Enter the number of nodes : ");
	scanf("%d", &n);

	int Cost[n][n], i, j;
	printf("Enter the adjacency matrix :\n");
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			scanf("%d", &Cost[i][j]);
			if(Cost[i][j] == 0)
				Cost[i][j] = 999;
		}
	}
	printf("Minimum Cost = %d\n", PrimsAlg(n, Cost));
}

int PrimsAlg(int n, int Cost[][n])
{
	int i, j, a, b, ne = 1, Visited[10] = {0}, Min, MinCost = 0;

	Visited[1] = 1;
	printf("\n");

	while(ne < n)
	{
		for(i=1, Min=999; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				if(Cost[i][j] < Min)
				{
					 if(Visited[i] != 0)
					 {
						Min = Cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}


		if(Visited[a] == 1 && Visited[b] == 0)
		{
			printf("Edge %d : (%d %d) Cost : %d\n", ne++, a, b, Min);
			MinCost += Min;
			Visited[b] = 1;
		}
		Cost[a][b] = Cost[b][a] = 999;
	}
	return MinCost;
}

