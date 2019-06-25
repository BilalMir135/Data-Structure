#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h> 
using namespace std;

//Binary Tree Node
struct bst_node
{
	char data;
	struct bst_node *left, *right;
};

//Binary Tree Node Creation
struct bst_node* create_bst_node(char ch)
{
	struct bst_node *temp;
	temp = (bst_node*)malloc(sizeof(bst_node));
	temp->data=ch;
	temp->right=NULL;
	temp->left=NULL;
	return(temp);
} 

//Binary Tree Node Insertion 
struct bst_node* insert_bst_node(struct bst_node *root, struct bst_node *left_child, struct bst_node *right_child)
{
	root->left = left_child;
	root->right = right_child;
	return(root);
}

//Stack Node
struct stack_node
{
	struct bst_node *data;
	struct stack_node *link;
};

//Push Function(stack top address, binary tree node address as a data of stack)
void push(struct stack_node **top, struct bst_node *info)
{
	struct stack_node *temp;
	temp = (stack_node*)malloc(sizeof(stack_node));
	temp->data = info;
	temp->link = NULL;
	if(*top==NULL)
		*top = temp;
	else
	{
		temp->link = *top;
		*top = temp;
	}	
}

//Pop Function returns that binary tree node address
struct bst_node * pop(struct stack_node **top)
{
	if(*top==NULL)
		return(NULL);
	else
	{
		struct bst_node *x;
		x = (*top)->data;
		struct stack_node *temp;
		temp = *top;
		*top = (*top)->link;
		free(temp);
		return(x);
	}
}

//Binary Expression Tree Creation 
void bet_creation(char ch, struct stack_node **top)
{
	struct bst_node *Node;
	Node = create_bst_node(ch);
	
	char operators[] = {'+','-','*','/','^'};
	bool isoperator = false;
	for(int i=0; i<strlen(operators); i++)
	{
		if(operators[i]==ch)
		{
			isoperator = true;
			break;
		}
	}
	if(isoperator)
	{
		struct bst_node *temp_root;
		temp_root = insert_bst_node(Node, pop(top), pop(top));
		push(top, temp_root);
	}
	else
	{
		push(top,Node);
	}
}

//Traversing Root->Left->Right
void preorder(struct bst_node **root)
{
	if(*root!=NULL)
	{
		cout<<" "<<(*root)->data;
		preorder(&((*root)->left));
		preorder(&((*root)->right));
	}
}
//Traversing Left->Root->Right
void inorder(struct bst_node **root)
{
	if(*root!=NULL)
	{
		inorder(&((*root)->left));
		cout<<" "<<(*root)->data;
		inorder(&((*root)->right));
	}
}
//Traversing Left->Right->Root
void postorder(struct bst_node **root)
{	
	if(*root!=NULL)
	{
		postorder(&((*root)->left));
		postorder(&((*root)->right));
		cout<<" "<<(*root)->data;
	}
}

int main()
{
	struct stack_node *top = NULL;
	struct bst_node *root;
	
	//taking string as an input
	string str;
	cout<<"Enter a postfix expression = ";
	getline(cin,str);  
	
	//finding the length of string
	int length = str.length();
		
	//converting string into characters array
	char array[length+1];
	strcpy(array, str.c_str());
	for(int i=0; i<length; i++)
	{
		bet_creation(array[i],&top);
	}
	root = pop(&top);
	
	//Traversing	
	cout<<"\nPreorder Traversing / Prefix "<<endl;
	preorder(&root);
	cout<<"\nInorder Traversing / Infix "<<endl;
	inorder(&root);	
	cout<<"\nPostorder Traversing / Postfix "<<endl;
	postorder(&root);
	
	return(0);
}




