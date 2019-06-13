#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

struct node *Top = NULL;

void push (int data)
{
	struct node *temp;
	temp = (node*)malloc(sizeof(node));
	temp->link = NULL;
	temp->data = data;
	if(Top==NULL)
	{
		Top = temp;
	}
	else
	{
		temp->link = Top;
		Top = temp;
	}
}

int pop()
{
	int data;
	if(Top==NULL)
	{
		cout<<"Stack Underflow"<<endl;
		return(0);
	}
	else
	{
		struct node *temp;
		data = Top->data;
		temp = Top;
		Top = Top->link;
		free(temp);	
		return(data);	
	}
}

void display()
{
	if(Top==NULL)
	{
		cout<<"Stack Underflow"<<endl;
	}
	else
	{
		struct node *temp = Top;
		while(temp!=NULL)
		{
			cout<<temp->data<<" "<<endl;
			temp = temp->link;
		}
	}
}

int count()
{
	if(Top==NULL)
	{
		return(0);
	}
	else
	{
		int x;
		struct node* temp =Top;
		while(temp!=NULL)
		{
			x++;
			temp = temp->link;
		}
		return(x);
	}
}

int main()
{
	pop();
	push(10);
	push(20);
	push(30);
	push(40);
	push(50);
	cout<<"Total nodes = "<<count()<<endl;
	pop();
	cout<<"Pop = "<<pop()<<endl;
	cout<<"Total nodes = "<<count()<<endl;
	display();
	return(0);
}



