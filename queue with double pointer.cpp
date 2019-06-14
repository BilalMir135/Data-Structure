#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next, *previous;
};

struct node *Front, *Rear = NULL;

void enqueue(int data)
{
	struct node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->next = NULL;
	temp->previous = NULL;
	temp->data = data;
	if(Front==NULL)
	{
		Front = temp;
		Rear = temp;
	}
	else
	{
		Rear->next = temp;
		temp->previous = Rear;
		Rear = temp;
	}
}

int dequeue()
{
	int data;
	if(Front==NULL)
	{
		cout<<"Queue is empty"<<endl;
		return(0);
	}
	else if (Front==Rear)
	{
		data = Front->data;
		free(Front);
		Front = NULL;
		Rear = NULL;
		return(data);
	}
	else
	{
		struct node *temp = Front;
		data = temp->data;
		Front = Front->next;
		Front->previous = NULL;
		free(temp);
		return(data);
		
	}
}

void display()
{
	if(Front==NULL)
		cout<<"Queue is empty"<<endl;
	else if(Front==Rear)
		cout<<Front->data<<" ";
	else
	{
		struct node *temp = Front;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->next;
		}
	}
}

int count()
{
	if(Front==NULL)
		return(0);
	else if(Front==Rear)
		return(1);
	else
	{
		int x;
		struct node *temp = Front;
		while(temp!=NULL)
		{
			x++;
			temp = temp->next;
		}
		return(x);
	}
}

int main()
{
	dequeue();
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	cout<<"Total nodes = "<<count()<<endl;
	dequeue();
	cout<<"Dequeue = "<<dequeue()<<endl;
	cout<<"Total nodes = "<<count()<<endl;
	display();
	return(0);
}




