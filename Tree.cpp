#include<iostream>
#include<stdlib.h>
using namespace std;

struct btnode
{
	int info;
	struct btnode *left, *right;
};

//Inserting node without recursion
void insert(struct btnode **root, int data)
{
	struct btnode *temp;
	temp = (btnode*)malloc(sizeof(btnode));
	temp->info = data;
	temp->left = NULL;
	temp->right = NULL;
	
	if(*root==NULL)
	{
		*root = temp;
	}
	else
	{
		struct btnode *t;
		t = *root;
		while(t!=NULL)
		{
			if(t->info < data)
			{
				if(t->right==NULL)
				{
					t->right = temp;
					t=NULL;	
				}			
				else
					t=t->right;
			}
			else if(t->info > data)
			{
				if(t->left==NULL)
				{
					t->left = temp;
					t=NULL;
				}			
				else
					t=t->left;
			}
		}
	}
}

//Inserting node with recursion
void insertwithrecursion(struct btnode **root, int data)
{
	if(*root==NULL)
	{
		struct btnode *temp;
		temp = (btnode*)malloc(sizeof(btnode));
		temp->info = data;
		temp->left = NULL;
		temp->right = NULL;
		*root = temp;
	}
	else
	{
		if((*root)->info < data)
		{
			insertwithrecursion(&((*root)->right),data);
		}
		else if((*root)->info > data)
		{
			insertwithrecursion(&((*root)->left),data);
		}
	}
}
//Traversing Root->Left->Right
void preorder(struct btnode **root)
{
	if(*root!=NULL)
	{
		cout<<" "<<(*root)->info;
		preorder(&((*root)->left));
		preorder(&((*root)->right));
	}
}
//Traversing Left->Root->Right
void inorder(struct btnode **root)
{
	if(*root!=NULL)
	{
		inorder(&((*root)->left));
		cout<<" "<<(*root)->info;
		inorder(&((*root)->right));
	}
}
//Traversing Left->Right->Root
void postorder(struct btnode **root)
{
	if(*root!=NULL)
	{
		postorder(&((*root)->left));
		postorder(&((*root)->right));
		cout<<" "<<(*root)->info;
	}
}

struct queuenode
{
	struct btnode *info;
	struct queuenode *link;
};

void enqueue (struct queuenode **front, struct btnode *data)
{
	struct queuenode *temp;
	temp = (queuenode*)malloc(sizeof(queuenode));
	temp->info = data;
	temp->link = NULL;
	if(*front==NULL)
		*front = temp;
	else
	{
		struct queuenode *t;
		t = *front;
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=temp;
	}		
}

struct btnode * dequeue(struct queuenode **front)
{
	struct queuenode *temp;
	struct btnode *data;
	temp = *front;
	*front = (*front)->link;
	data = temp->info;
	free(temp);
	return(data);
}

int count_queue(struct queuenode **front)
{
	if(*front==NULL)
		return(0);
	else
	{
		struct queuenode *temp;
		temp = *front;
		int x=0;
		while(temp!=NULL)
		{
			x++;
			temp=temp->link;
		}
		return(x);
	}
}

void clear_queue(struct queuenode **front)
{
	if(*front==NULL)
		return;
	struct queuenode *temp, *t;
	temp = *front;
	while(temp!=NULL)
	{
		t=temp;
		temp=temp->link;
		free(t);		
	}
}

//Traversing root->left->right
void levelorder(struct btnode **root)
{
	struct queuenode *front = NULL;
	struct btnode *temp;
	if(root==NULL)
		return;
	else
	{
		enqueue(&front,*root);
		while(count_queue!=0)
		{
			temp = dequeue(&front);
			cout<<" "<<temp->info;
			if(temp->left)
			{
				enqueue(&front,temp->left);
			}
			if(temp->right)
			{
				enqueue(&front,temp->right);
			}
		}
		clear_queue(&front);
	}
}

struct btnode* findmax(struct btnode *root,struct btnode **beforemax)
{
	if(root->right!=NULL)
	{
		*beforemax = root;
		return(findmax(root->right,beforemax));
	}
		
	else
		return(root);
}

struct btnode* search(struct btnode *root, int num, struct btnode **pointing_search)
{
	if(num>root->info)
	{
		*pointing_search = root;
		return(search(root->right,num,pointing_search));
	}
	else if (num<root->info)
	{
		*pointing_search = root;
		return(search(root->left,num,pointing_search));
	}
	else if(num==root->info)
	{
		return(root);
	}
	else
	{
		return(NULL);
	}
}

Delete(struct btnode *root, int num)
{	
	struct btnode *temp, *q;
	temp = search(root,num,&q);
	if(temp==NULL)
		cout<<"No such value exsists in tree"<<endl;
	else if(temp->left==NULL && temp->right==NULL)
	{
		if(q->info>temp->info)
			q->left = NULL;
		else if(q->info<temp->info)
			q->right = NULL;
		free(temp);
	}
	else if(temp->left!=NULL && temp->right!=NULL)
	{
		struct btnode *t,*s;
		t=findmax(temp->left,&s);
		temp->info = t->info;
		if(t->left==NULL)
		free(t);
		else
		{
		s->right = t->left;
		free(t);
		}
	}
	else
	{
		if(q->info>temp->info)
		{
			if(temp->left!=NULL)
				q->left = temp->left;
			else
				q->left = temp->right;
		}
		else if(q->info<temp->info)
		{
			if(temp->left!=NULL)
				q->right = temp->left;
			else
				q->right = temp->right;
		}			
	}	
}

int main()
{
	struct btnode *root = NULL;
	int num,data, i=1;
	cout<<"How many nodes you want to enter = ";
	cin>>num;
	
	while(i<=num)
	{
		cout<<i<<". Enter the number = ";
		cin>>data;
		insert(&root,data);
		i++;
	}
	int num1;
	cout<<"Enter a number = ";
	cin>>num1;
	Delete(root,num1);
	
	//cout<<"\nMax Value = "<<(findmax(root))->info<<endl;
	cout<<"\nPreOrder Traversal"<<endl;
	preorder(&root);
	cout<<"\nInOrder Traversal"<<endl;
	inorder(&root);
	cout<<"\nPostOrder Traversal"<<endl;
	postorder(&root);
	cout<<"\nLeveOrder Traversal"<<endl;
	levelorder(&root);
	
	return(0);
	
}







