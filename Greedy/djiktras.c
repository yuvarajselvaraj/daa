#include<stdio.h>
#define MAX 15

struct Table
{
	int Known, Dist, Path;

}T[MAX];

void CreateGraph();
void DisplayCost();
void DijkstrasAlg();
void DisplayTable();
void PrintPath(int);

int Cost[MAX][MAX], ch, n, i, j, k, v, w, V1, V2, Edge, S;

void main()
{
	CreateGraph();
	printf("\nGRAPH SUCCESSFULLY CREATED..\n");
	DisplayCost();

	DijkstrasAlg();

	printf("\n\n\t...SHORTEST PATHS...");
	for(i=1; i<=n; i++)
	{
		printf("\nFor Vertex V%d\n\t",i);
		PrintPath(i);
		printf(" with total Path Cost %d\n", T[i].Dist);
	}
}

void CreateGraph()
{
	printf("Enter the no. of vertices : ");
	scanf("%d", &n);

	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			Cost[i][j] = 0;

	do
	{
		printf("Enter the edges(v1 to v2) along with Cost : ");
		scanf("%d %d %d", &V1, &V2, &Edge);
		Cost[V1][V2] = Edge;
		printf("Enter 1 to add more edges : ");
		scanf("%d", &ch);
	}while(ch == 1);
}

void DisplayCost()
{
	printf("\nAdjacacency Matrix");
	printf("\nVERTEX");
	for(i=1; i<=n; i++)
		printf("\tV%d", i);

	for(i=1; i<=n; i++)
	{
		printf("\nV%d", i);
		for(j=1; j<=n; j++)
		{
			printf("\t%d", Cost[i][j]);
		}
	}
}

void DijkstrasAlg()
{
	printf("\n\n\t..DIJKSTRA'S ALGORITHM..");
	for(i=1; i<=n; i++)
	{
		T[i].Known = 0;
		T[i].Dist = 9999;
		T[i].Path = 0;
	}

	printf("\nEnter the Source Vertex: V");
	scanf("%d", &S);

	T[S].Dist=0;

	printf("\n\tInitial table\n");
	DisplayTable();

	k = 1;

	do
	{
		v = 1;

		while(T[v].Known == 1)
			v = v + 1;

		for(j=1; j<=n; j++)
		{
			if(T[j].Dist <= T[v].Dist)
				if(T[j].Known == 0)
						v = j;
		}

		T[v].Known = 1;

		for(w=1; w<=n; w++)
		{
			if(Cost[v][w] != 0)
			{
				if(T[w].Known == 0)
				{
					if((T[v].Dist + Cost[v][w]) < T[w].Dist)
					{
						T[w].Dist = T[v].Dist + Cost[v][w];
						T[w].Path = v;
					}
				}
			}
		}
		printf("\n\n\tAfter vertex V%d is Known", v);
		DisplayTable();

		k += 1;
	}while(k <= n);
}

void DisplayTable()
{
	printf("\nVERTEX\tKnown\tDv\tPv");
	for(i=1; i<=n; i++)
	{
		if(T[i].Path == 0)
			printf("\nV%d\t%d\t%d\t%d", i, T[i].Known, T[i].Dist, T[i].Path);
		else
			printf("\nV%d\t%d\t%d\tV%d",i, T[i].Known, T[i].Dist, T[i].Path);
	}
}

void PrintPath(int v)
{
	if(T[v].Path != 0)
	{
		PrintPath(T[v].Path);
		printf(" to");
	}
	printf(" V%d", v);
}

