#include<iostream>
#include<stdlib.h>
using namespace std;

struct ListNode
{
	int vertex;
	struct ListNode *next;
};

struct ListNode * createnode(int vertex)
{
	struct ListNode *temp;
	temp = (ListNode *)malloc(sizeof(ListNode));
	temp->vertex = vertex;
	temp->next = NULL;
}

struct Graph
{
	int V;
	struct ListNode **Adjlist;
	int * status;
};

struct Graph * creategraph(int V)
{
	struct Graph *temp;
	temp = (Graph *)malloc(sizeof(Graph));
	temp->V = V;
	temp->Adjlist = (ListNode **)malloc(temp->V * sizeof(ListNode));
	
	for(int i=0; i<temp->V; i++)
	{
		temp->Adjlist[i] = NULL;
	}
	return(temp);
}

void addedge(struct Graph *G, int source, int destination)
{
	struct ListNode *newnode = createnode(destination);
	newnode->next = G->Adjlist[source];
	G->Adjlist[source] = newnode;
	//For undirected graph
	newnode = createnode(source);
	newnode->next = G->Adjlist[destination];
	G->Adjlist[destination] = newnode;
}

void printgraph(struct Graph *G)
{
	struct ListNode *temp;
	for(int i=0; i<G->V; i++)
	{
		temp = G->Adjlist[i];
		cout<<i;
		while(temp!=NULL)
		{
			cout<<"->"<<temp->vertex;
			temp = temp->next;
		}
		cout<<endl;
	}
}

struct queuenode
{
	int data;
	struct queuenode *next;
};

void enqueue(struct queuenode **front, int info)
{
	struct queuenode *temp,*t;
	temp = (queuenode *)malloc(sizeof(queuenode));
	temp->data = info;
	temp->next = NULL;
	if(*front==NULL)
	{
		*front = temp;
	}
	else
	{
		t=*front;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next = temp;
	}
}

int dequeue(struct queuenode **front)
{
	if(front==NULL)
	{
		return(0);
	}
	else
	{
		int data;
		struct queuenode *temp;
		temp = *front;
		*front = (*front)->next;
		data = temp->data;
		free(temp);
		return(data);
	}
}
int Isqueueempty(struct queuenode **Front)
{
	if(*Front==NULL)
		return (0);
	else
		return 1;
}
void BFS(struct Graph *G, int starting_vertex)
{
	G->status = (int *)malloc(G->V*sizeof(int));
	struct queuenode *Front = NULL;
	enqueue(&Front,starting_vertex);
	G->status[starting_vertex] = 1;
	cout<<"Breath First Searching"<<endl;
	while(Isqueueempty(&Front)!=0)
	{
		int currentvertex = dequeue(&Front);
		cout<<currentvertex<<" ";
		struct ListNode *temp = G->Adjlist[currentvertex];
		while(temp!=NULL)
		{
			int adjvertex = temp->vertex;
			if(G->status[adjvertex]==0)
			{
				enqueue(&Front,adjvertex);
				G->status[adjvertex]=1;
			}
			temp = temp->next;
		}
	}
}

struct stack
{
	int data;
	struct stack *next;
};

void push(struct stack **Top, int info)
{
	struct stack *temp,*t;
	temp = (stack*)malloc(sizeof(stack));
	temp->data = info;
	temp->next = NULL;
	if(*Top==NULL)
	{
		*Top = temp;
	}
	else
	{
		temp->next = *Top;
		*Top = temp;
	}
}

int pop (struct stack **Top)
{
	if(*Top==NULL)
	{
		return(0);
	}
	else
	{
		int info;
		struct stack *temp = *Top;
		*Top = temp->next;
		info = temp->data;
		free(temp);
		return(info);
	}
}

void DFS (struct Graph *G, int starting_vertex)
{
	G->status = (int *)malloc(G->V*sizeof(int));
	struct stack *Top = NULL;
	push(&Top,starting_vertex);
	G->status[starting_vertex] = 1;
	cout<<"\nDepth First Searching"<<endl;
	while(Top!=NULL)
	{
		int currentvertex = pop(&Top);
		cout<<currentvertex<<" ";
		struct ListNode *temp = G->Adjlist[currentvertex];
		while(temp!=NULL)
		{
			int adjvertex = temp->vertex;
			if(G->status[adjvertex]==0)
			{
				push(&Top,adjvertex);
				G->status[adjvertex]=1;
			}
			temp = temp->next;
		}
	}
}
int main()
{
	struct Graph *graph = creategraph(6);
	//addedge(graph,0,1);
	//addedge(graph,0,2);
	//addedge(graph,1,3);
	//addedge(graph,3,0);
	//addedge(graph,3,2);
	addedge(graph,0,2);
	addedge(graph,0,1);
	addedge(graph,0,4);
	addedge(graph,1,3);
	addedge(graph,1,5);
	addedge(graph,2,3);
	addedge(graph,2,4);
	addedge(graph,3,4);
	addedge(graph,4,5);
	printgraph(graph);
	BFS(graph,5);
	DFS(graph,1);
	return(0);
}
