#include<iostream>
using namespace std;

void insertion_sort(int array[], int length)
{
	int temp,j;
	for(int i=1; i<length; i++)
	{
		temp = array[i];
		for(j=i-1; j>=0 && temp<array[j]; j--)
		{
			array[j+1] = array[j];
		}
		array[j+1] = temp;
	}
}

int main()
{
	int array[] = {34,45,11,89,55,19,22,8,40};
	int length = sizeof(array)/sizeof(array[0]);
	insertion_sort(array,length);
	for(int i=0; i<length; i++)
	{
		cout<<array[i]<<" ";
	}
	return(0);
}

