#include<iostream>
using namespace std;

class Graph
{
	private:
		int V;
		int **array;
	public:
		Graph(int V);
		void addedge(int, int);
		void print_graph();
};

Graph::Graph(int V)
{
	this->V = V;
	array = new int*[V];
	for(int i=0; i<V; i++)
	{
		array[i] = new int[V];
	}
	
	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
		{
			array[i][j] = 0;
		}
	}
}

void Graph::addedge(int source, int destination)
{
	array[source][destination] = 1;
	array[destination][source] = 1;
}

void Graph::print_graph()
{
	for(int i=0; i<V; i++)
	{
		for(int j=0; j<V; j++)
		{
			cout<<"\t"<<array[i][j];
		}
		cout<<endl;
	}
}

int main()
{
	Graph gh (4);
	gh.addedge(0,1);
	gh.addedge(0,2);
	gh.addedge(1,3);
	gh.addedge(3,2);
	gh.addedge(3,0);
	gh.print_graph();
	return(0);
}
