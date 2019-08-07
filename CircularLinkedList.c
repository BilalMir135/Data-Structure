#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


struct Node{
	int data;
	int index;
	struct Node *next;
};

void insert(struct Node**,int);
void printall (struct Node*);
void search(struct Node*,int);
void delvalue(struct Node**,int);
void delList(struct Node**);
int get(struct Node*,int);
//-----------------------XXXXXXXXXXXXX----------------------------XXXXXXXXXXXXXXX------------------------------

int main(int argc, char *argv[]) {
	
	struct Node *start=NULL;
	insert(&start,5);
	insert(&start,4);
	insert(&start,3);
	insert(&start,2);
	insert(&start,1);
    printall(start);
	delvalue(&start,3);
	printall(start);
	search(start,2);
	int a=get(start,3);
	printf("%d",a);
	delList(&start);
	printall(start);
	
	getchar();
	
	return 0;
}

//---------------------XXXXXXXXXXXXXXXXXX--------------------------XXXXXXXXXXXXXXX-----------------------------

void insert(struct Node **start,int value)
{
	struct Node *temp;
	
  	temp=(struct Node*)malloc(sizeof(struct Node));
  	temp->data=value;
  	temp->next=temp;
  	if(*start==NULL)
  	{
	   temp->index=0;
	   *start=temp;
	}
  	else
  	{
	  struct Node *current;
  	  current=*start;
	 while(current->next!=*start)
	 	{ 
		 	current=current->next;
		} 
		int t=current->index;
		t++;
		temp->index=t;
		current->next=temp;
		temp->next=*start;
		
	}
}

//-------------------XXXXXXXXXXXXXXXXXXXXX--------------------------XXXXXXXXXXXXXX-----------------------------------

void printall(struct Node *start)
{
	struct Node *tempstart=start;
	printf("Your List :");
	printf("\n");
	
	if(start==NULL)
	{
		printf("\n \'LIST IS EMPTY\'\n");
	}
	else {
	
	while (start->next!=tempstart)
	{
		printf("INDEX : %d \nValue : %d \n\n",start->index,start->data);
		start=start->next;
	}
	 printf("INDEX : %d \nValue : %d \n\n",start->index,start->data);
}
}

//----------------XXXXXXXXXXXXXXXXXXXXXXX------------------------XXXXXXXXXXXXXXXXXXXXXXXXXXX------------------

void search(struct Node *start,int value)
{
    struct Node *tempstart=start;
    
    bool found=false;
	while(start->next!=tempstart)
	{
	
	if (start->data==value)
	{
		
		printf("\tYour Value:\nINDEX : %d \nValue : %d \n\n",start->index,start->data);
		found=true;
	}
	
	start=start->next;
	}
		if (start->data==value)
	{
		
		printf("\tYour Value:\nINDEX : %d \nValue : %d \n\n",start->index,start->data);
		found=true;
	}
	if(found==false)
	{
		printf("\'Not Found\'");
	}
}

//----------------XXXXXXXXXXXXXXXXXXXXX--------------------------XXXXXXXXXXXXXXXXXXXXXX-------------------------

void delvalue(struct Node **start,int value)
{
	
  	if(*start==NULL)
  	{
	  printf("\n \'LIST IS EMPTY\' \n");
	}
	else
    {
  
  	if((*start)->data==value)
	 {
	 	struct Node *t=*start;
	 	*start=(*start)->next;
	 	
	 struct Node *curr=*start;
	 while(curr->next!=t)
	 {
	 	curr=curr->next;
	 }
	  curr->next=*start;
	  free(t);
	  t=NULL;
	 }
	  else
  	{
	  struct Node *current;
  	  current=(*start)->next;
	  struct Node*t;
	  while(current->data!=value)
	 	{ 
		 	 t=current;
			 current=current->next;
		} 
	    t->next=current->next;
	    free(current);
	    current=NULL;
	}
    
	int ind=0;
    struct Node *t=*start;

	if(t!=NULL)
		{
	
	while(t->next!=*start)
    {   
		 
		t->index=ind;		
		t=t->next;
		ind++;
	}
	t->index=ind;
		}	
	
	}
}

//------------------XXXXXXXXXXXXXXXXX----------------------------XXXXXXXXXXXXXXXXXXXXXXXXXX

void delList(struct Node **start)
{
	
		struct Node *temp=*start;
		while (temp->next!=*start)
		{   
			struct Node *t=temp; 
			temp=temp->next;
		    free(t);
		}
	free(temp);
	
     *start=NULL;
}
int get(struct Node *start,int ind)
{
	struct Node *current;
  	  current=start;
	
	  while(current->index!=ind&&current->next!=start)
	 	{ 
		 	 
			 current=current->next;
		} 
	if(current->index==ind)
	{
	return current->data;
	}
	else return 0;
}
