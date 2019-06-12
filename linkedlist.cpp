#include<iostream>
#include<stdlib.h>            //for malloc
using namespace std;

struct node
{
	int info;
	struct node *link;
};
struct node *start = NULL;

//Create a new node 
struct node* createnode()
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->link = NULL;
	cout<<"Enter the value = ";
	cin>>temp->info;
	return(temp);
}

//Add nodes at the end of the linked list
void apendEnd()
{
	struct node *temp, *t;
	temp = createnode();		
	if(start==NULL)
	{
		start = temp;
	}
	else
	{
		t=start;
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link = temp;
	}
}

//Add nodes at the beginning of the linked list
void apendBeg()
{
	struct node *temp;
	temp = createnode();
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		temp->link = start;
		start = temp;
	}
}

//Add nodes after the specified number of nodes
void apendAfter(int location)
{
	int count();
	if(count()<location || location==0)
	{
		cout<<"Sorry! there are less nodes so new node cannot apend after location "<<location<<endl;
	}
	else
	{
		struct node *temp, *t;
		temp = createnode();
		t = start;
		for(int i=0; i<location; i++)
		{
			t=t->link;
		}
		temp->link = t;
		t = start;
		for(int i=0; i<location-1; i++)
		{
			t = t->link;
		}
		t->link = temp;
	}
	
}

//Counts the number of nodes present in the linked list
int count()
{
	int x;
	if(start==NULL)
	{
		return(0);
	}
	else
	{
		struct node *temp;
		temp = start;
		while(temp!=NULL)
		{
			x++;
			temp = temp->link;
		}
		return(x);
	}
}

//Delete nodes from the beginning of linked list
void deleteBeg()
{
	struct node *temp;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		temp = start;
		start = start->link;
		free(temp);
	}
}

//Delete nodes from the end of the linked list
void deleteEnd()
{ 
	struct node *temp, *t;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		temp = start;
		while(temp->link!=NULL)
		{
			if(temp->link->link==NULL)     //if we find last node with link = NULL we have to store the address of previous node which is pointing 
			{							  //the last node so after removing last node we wiil make the link null of the node that is pointing last node
				t = temp;
			}
			temp = temp->link;	
		}
		free(temp);
		t->link = NULL;
	}
}

//Delete nodes from the specified location of the linked list
void deleteAfter(int location)
{
	int count();
	if(count()<location || location==0)
	{
		cout<<"Sorry! there are less nodes so new node cannot delete node of location "<<location<<endl;
	}
	else
	{
		struct node *temp, *t;
		temp = start;
		for(int i=1; i<location; i++)
		{
			if(i==location-1)   //to save the address of node that is before the located node so in the end we add the address of next node to located node 
			{					//in the node that is before located node 
				t=temp;
			}	
			temp = temp->link;
		}
		t->link = temp->link;
		free(temp);
	}
}

//displays the content of the linked list
void viewnode()
{
	struct node *temp;
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		temp = start;
		while(temp!=NULL)
		{
			cout<<" "<<temp->info;
			temp=temp->link;
		}
	}
}

//delete all the nodes from linked list
void clear()
{
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		struct node *temp, *t;
		int  x = count();
		temp = start;
		while(x!=0)
		{
			t = temp->link;
			free(temp);
			temp = t;
			x--;
		}
		start = NULL;
		cout<<"Linked list is cleared"<<endl;
	}
	
}

//reverse linked list
void reverse()
{
	if(start==NULL)
	{
		cout<<"List is empty"<<endl;
	}
	else
	{
		struct node *q, *r, *s;
		q = start;
		r = NULL;   		//to make the last node link null
		while(q!=NULL)
		{
			s = r;
			r = q;
			q = q->link;
			r->link = s;
		}
		start = r;
	}
	
}

int main()
{
	int x;	
	while(1)
	{
		system("CLS");
		cout<<"1. Add node in the End"<<endl;
		cout<<"2. Add node in the Beginning"<<endl;
		cout<<"3. Add node after specified number of nodes"<<endl;
		cout<<"4. Delete node from the beginning"<<endl;
		cout<<"5. Delete node from the end"<<endl;
		cout<<"6. Delete node of specified location"<<endl;
		cout<<"7. View nodes"<<endl;
		cout<<"8. Count nodes"<<endl;
		cout<<"9. Clear linkedlist"<<endl;
		cout<<"10. Reverse linkedlist"<<endl;
		cout<<"Enter your choice = ";
		cin>>x;
		switch(x)
		{
			case 1:
				apendEnd();
				break;
			case 2:
				apendBeg();
				break;
			case 3:
				{
					int loc;
					cout<<"Enter the location = ";
					cin>>loc;
					apendAfter(loc);
				}
				break;
			case 4:
				deleteBeg();
				break;
			case 5:
				deleteEnd();
				break;
			case 6:
				{
					int loc;
					cout<<"Enter the location = ";
					cin>>loc;
					deleteAfter(loc);
				}
				break;
			case 7:
				viewnode();
				break;
			case 8:
				cout<<"Total nodes = "<<count()<<endl;
				break;
			case 9:
				clear();
				break;
			case 10:
				reverse();
				break;
			default:
				cout<<"Wrong Choice"<<endl;
		}
		system("PAUSE");
	}
	return(0);
}
