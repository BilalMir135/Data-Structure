#include<iostream>
#include<stdlib.h>
using namespace std;

struct AdjListNode
{
	int destination;
	struct AdjListNode *next;
};

struct AdjList
{
	struct AdjListNode *head;
};

class Graph
{
	private:
		int V;
		struct AdjList *array;
		struct AdjListNode * create_adj_listnode(int);
	public:
		Graph(int);		
		void addEdge(int, int);
		void print_graph();
};

Graph::Graph(int V)
{
	this->V = V;
	array = new AdjList[V];
	for(int i=0; i<V; i++)
	{
		array[i].head = NULL;
	}
}

struct AdjListNode * Graph::create_adj_listnode(int destination)
{
	struct AdjListNode *temp;
	temp = new AdjListNode;
	temp->destination = destination;
	temp->next = NULL;
}

void Graph::addEdge(int source, int destination)
{
	struct AdjListNode *temp, *t;
	temp = create_adj_listnode(destination);
	temp->next = array[source].head;
	array[source].head = temp;
	t = create_adj_listnode(source);
	t->next = array[destination].head;
	array[destination].head = t;
}

void Graph::print_graph()
{
	struct AdjListNode *temp;
	for(int i=0; i<V; i++)
	{
		temp = array[i].head;
		cout<<i;
		while(temp!=NULL)
		{
			cout<<"->"<<temp->destination;
			temp = temp->next;
		}
		cout<<endl;
	}
}


int main()
{
	Graph G(4);
	G.addEdge(0,1);
	G.addEdge(0,2);
	G.addEdge(1,3);
	G.addEdge(3,0);
	G.addEdge(3,2);
	G.print_graph();
	return(0);
}
