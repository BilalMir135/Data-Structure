#include<iostream>
#include<stdlib.h>
using namespace std;

struct node 
{
	int data;
	struct node *link;
};

struct node *Front = NULL;

void enqueue(int data)
{
	struct node *temp, *t;
	temp = (node*)malloc(sizeof(node));
	temp->link = NULL;
	temp->data = data;
	if(Front==NULL)
		Front = temp;
	else
	{
		t = Front;
		while(t->link!=NULL)
		{
			t = t->link;
		}			
		t->link = temp;
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
	else
	{
		struct node *temp;
		temp = Front;
		Front = Front->link;
		data = temp->data;
		free(temp);
		return(data);
	}
}

void display()
{
	if(Front==NULL)
		cout<<"Queue is empty"<<endl;
	else
	{
		struct node *temp = Front;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp = temp->link;
		}
	}
}

int count()
{
	if(Front==NULL)
		return(0);
	else
	{
		int x;
		struct node *temp = Front;
		while(temp!=NULL)
		{
			x++;
			temp=temp->link;
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
	cout<<"dequeue = "<<dequeue()<<endl;
	cout<<"Total nodes = "<<count()<<endl;
	display();
	return(0);
}

















