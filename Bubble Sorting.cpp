#include<iostream>
using namespace std;

int main()
{
	void bubble_sort(int[],int);
	void modified_bubble_sort(int[],int);
	
	int array[] = {34,15,29,8};
	int length = sizeof(array)/sizeof(array[0]);
	bubble_sort(array,length);
	for(int i=0; i<length; i++)
	{
		cout<<array[i]<<" ";
	}
	int array1[] = {34,15,29,50};
	modified_bubble_sort(array1,length);
	cout<<endl;
	for(int i=0; i<length; i++)
	{
		cout<<array1[i]<<" ";
	}
	return(0);
}

void swap(int *x, int *y)
{
	int c;
	c = *x;
	*x = *y;
	*y = c;
}

void bubble_sort(int array[], int length)
{
	for(int round=1; round<length; round++)
	{
		for(int i=0; i<length-round; i++)
		{
			if(array[i]>array[i+1])
				swap(&array[i],&array[i+1]);
		}
	}
	//cout<<"Round = "<<round<<endl;
}

void modified_bubble_sort(int array[], int length)
{
	int flag;
	for(int round=1; round<length; round++)
	{
		flag=0;
		for(int i=0; i<length-round; i++)
		{
			if(array[i]>array[i+1])
			{
				flag=1;
				swap(&array[i],&array[i+1]);
			}
		}
		if(flag==0)
		{
			cout<<"\nRound = "<<round<<endl;
			return;
		}
	}
}
