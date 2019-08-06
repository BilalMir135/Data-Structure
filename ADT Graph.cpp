#include<iostream>
#include<stdlib.h>
using namespace std;

struct Vertex
{
	int vertexno;
	int data;
	struct Vertex *next;
};

Vertex * create_vertex(int vertexno, int data)
{
	Vertex *temp = new Vertex;
	temp->data=data;
	temp->vertexno=vertexno;
	temp->next=NULL;
}

class Graph
{
	private:
		int V;	//number of vertices
		Vertex **Adjlist;
		int *status;
	public:
		Graph(int);
		void addvertex(int,int);
		void addedge(int,int);
		void printgraph();
		void BFS(int);
		void DFS(int);
};

Graph::Graph(int V)
{
	this->V = V;
	Adjlist = new Vertex*[V];
	for(int i=0; i<V; i++)
	{
		Adjlist[i] = NULL;
	}
}

void Graph::addvertex(int num, int data)
{
	Vertex *temp = create_vertex(num,data);
	Adjlist[num] = temp;
}

void Graph::addedge(int source, int destination)
{
	Vertex *temp, *t;
	temp = create_vertex(destination, Adjlist[destination]->data);
	t = Adjlist[source];
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next = temp;
	
	temp = create_vertex(destination, Adjlist[source]->data);
	t = Adjlist[destination];
	while(t->next!=NULL)
	{
		t=t->next;
	}
	t->next = temp;
}

void Graph::printgraph()
{
	Vertex *temp;
	for(int i=0; i<V; i++)
	{
		temp = Adjlist[i];
		cout<<i;
		while(temp!=NULL)
		{
			cout<<"->"<<temp->data;
			temp = temp->next;
		}
		cout<<endl;
	}
}

struct Node
{
	int data;
	Node *next;
};

class Queue
{
	private:
		Node *Front = NULL;
	public:
		void enqueue(int);
		int dequeue();
		bool Isqueueempty();
};

void Queue::enqueue(int info)
{
	Node *temp,*t;
	temp = new Node;
	temp->data = info;
	temp->next = NULL;
	if(Front==NULL)
	{
		Front = temp;
	}
	else
	{
		t=Front;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next = temp;
	}
}

int Queue::dequeue()
{
	if(Front==NULL)
	{
		return(0);
	}
	else
	{
		int data;
		Node *temp;
		temp = Front;
		Front = Front->next;
		data = temp->data;
		free(temp);
		return(data);
	}
}

bool Queue::Isqueueempty()
{
	if(Front==NULL)
		return true;
	else
		return false;
}

void Graph::BFS(int starting_vertex)
{
	status = new int[V];
	Queue Q;
	Q.enqueue(starting_vertex);
	status[starting_vertex] = 1;
	cout<<"\nBreath First Searching"<<endl;
	while(!Q.Isqueueempty())
	{
		int currentvertex = Q.dequeue();
		cout<<Adjlist[currentvertex]->data<<" ";
		Vertex *temp = Adjlist[currentvertex];
		while(temp!=NULL)
		{	
			int adjvertex = temp->vertexno;
			if(status[adjvertex]==0)
			{
				Q.enqueue(adjvertex);
				status[adjvertex]=1;
			}			
			temp = temp->next;
		}
	}
}

class Stack
{
	private:
		Node *Top = NULL;
	public:
		void push(int);
		int pop();
		bool Isstackempty();
};

void Stack::push(int info)
{
	Node *temp,*t;
	temp = new Node;
	temp->data = info;
	temp->next = NULL;
	if(Top==NULL)
	{
		Top = temp;
	}
	else
	{
		temp->next = Top;
		Top = temp;
	}
}

int Stack::pop()
{
	if(Top==NULL)
	{
		return(0);
	}
	else
	{
		int info;
		Node *temp = Top;
		Top = temp->next;
		info = temp->data;
		free(temp);
		return(info);
	}
}

bool Stack::Isstackempty()
{
	if(Top==NULL)
		return true;
	else
		return false;
}

void Graph::DFS (int starting_vertex)
{
	status = new int[V];
	Stack S;
	S.push(starting_vertex);
	status[starting_vertex] = 1;
	cout<<"\nDepth First Searching"<<endl;
	while(!S.Isstackempty())
	{
		int currentvertex = S.pop();
		cout<<Adjlist[currentvertex]->data<<" ";
		Vertex *temp = Adjlist[currentvertex];
		while(temp!=NULL)
		{
			int adjvertex = temp->vertexno;
			if(status[adjvertex]==0)
			{
				S.push(adjvertex);
				status[adjvertex]=1;
			}
			temp = temp->next;
		}
	}
}

int main()
{
	Graph G(6);
	G.addvertex(0,10);
	G.addvertex(1,20);
	G.addvertex(2,30);
	G.addvertex(3,40);
	G.addvertex(4,50);
	G.addvertex(5,60);
	
	G.addedge(0,2);
	G.addedge(0,1);
	G.addedge(0,4);
	G.addedge(1,3);
	G.addedge(1,5);
	G.addedge(2,3);
	G.addedge(2,4);
	G.addedge(3,4);
	G.addedge(4,5);
	
	G.printgraph();
	
	G.BFS(0);
	G.DFS(0);
	return(0);
}
