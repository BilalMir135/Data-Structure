#include<iostream>
using namespace std;

int min(int array[], int starting_index, int length)
{
	int min_value = array[starting_index];
	int location = starting_index;
	for(int i=starting_index+1; i<length; i++)
	{
		if(min_value>array[i])
		{
			min_value = array[i];
			location = i;
		}
	}
	return(location);
}

void swap (int *x, int *y)
{
	int z = *x;
	*x = *y;
	*y = z;
}

int main()
{
	int array[] = {33,11,66,88,99,77,44,55,22,1};
	int length = sizeof(array)/sizeof(array[0]);
	int loc;
	for(int i=0; i<length-1; i++)
	{
		loc = min(array,i,length);
		swap(&array[loc],&array[i]);
	}
	for(int i=0; i<length; i++)
	{
		cout<<array[i]<<" ";
	}
	return(0);
}
