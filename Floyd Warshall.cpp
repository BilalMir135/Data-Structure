#include<iostream>
#include<stdlib.h>
#define INF 99999
using namespace std;

struct Graph
{
	int V;
	int E;
	int **Adj;
};

void printarray (struct Graph *temp)
{
	for(int i=0; i<temp->V; i++)
	{
		for(int j=0; j<temp->V; j++)
		{
			if(temp->Adj[i][j]==INF)
			{
				cout<<"\tINF";
			}
			else
			{
				cout<<"\t"<<temp->Adj[i][j];
			}
		}
		cout<<endl;
	}
}

void floydwarshall(struct Graph *temp)
{
	for(int k=0; k<temp->V; k++)
	{
		for(int i=0; i<temp->V; i++)
		{
			for(int j=0; j<temp->V; j++)
			{
				if(temp->Adj[i][k] + temp->Adj[k][j] < temp->Adj[i][j])
				{
					temp->Adj[i][j] = temp->Adj[i][k] + temp->Adj[k][j];
				}
			}
		}
	}
	
}
int main()
{
	int matrix[4][4] = 	{
							{0,5,INF,10},
							{INF,0,3,INF},
							{INF,INF,0,1},
							{INF,INF,INF,0}
						};
	struct Graph *G;
	G = (Graph*)malloc(sizeof(G));
	G->V=4;
	G->E=4;
	G->Adj = new int*[G->V];
	//G->Adj = (int **)malloc(sizeof(int*)*G->V);
	for(int i=0; i<G->V; i++)
	{
		G->Adj[i] = new int[G->V];
		//G->Adj[i] = (int *)malloc(sizeof(int)*G->V);
	}
	cout<<"Original Distance"<<endl;
	for(int i=0; i<G->V; i++)
	{
		for(int j=0; j<G->V; j++)
		{
			G->Adj[i][j] = matrix[i][j];
		}
	}
	printarray(G);
	cout<<"Shortest Distance after applying Floyd Warshall's Algorithm"<<endl;
	floydwarshall(G);
	printarray(G);
	return(0);
}
