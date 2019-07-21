#include<iostream>
using namespace std;

void merge(int A[], int length1, int index1, int B[], int length2, int index2, int C[], int index)
{
	while(length1!=0 && length2!=0)	//if any of 2 sub-arrays finishes the loop stop
	{
		if(A[index1]<B[index2])
		{
			C[index]=A[index1];
			index++;
			index1++;
			length1--;
		}
		else
		{
			C[index]=B[index2];
			index++;
			index2++;
			length2--;
		}
	}
	while(length1!=0)		//if array A left with some values pass into C
	{
		C[index]=A[index1];
		index++;
		index1++;
		length1--;
	}
	while(length2!=0)		//if array B left with some values pass into C
	{
		C[index]=B[index2];
		index++;
		index2++;
		length2--;
	}
}

void mergepass(int array[], int length, int L, int new_array[])
{
	int pairs = length/(2*L);		//How many sub-arrays will be there
	int values = pairs * 2 * L;		//How many elements from main array will be covered in merging
	int remaining = length-values;	//How many elements from main array will be left unmerged
	int starting_index;
	for(int i=0; i<pairs; i++)
	{
		starting_index = (2*i)*L;
		merge(array,L,starting_index,array,L,starting_index+L,new_array,starting_index);
	}
	if(remaining<=L)		//when the remaining is one sub-array then we don't need to merge it
	{
		for(int i=0; i<remaining; i++)
		{
			new_array[values+i]=array[values+i];	//copying the remaining values in new array
		}
	}
	else
	{
		merge(array,L,values,array,remaining-L,values+L,new_array,values);	//merging the remaining arrays
	}
}

void merge_sort(int array[], int length)
{
	int L=1;
	int new_array[length];
	while(L<length)
	{
		mergepass(array,length,L,new_array);
		mergepass(new_array,length,L*2,array);
		L=L*4;
	}
}

int main()
{
	int array[] = {12,8,24,17,33,71,10,48,41,21,6};
	int length = sizeof(array)/sizeof(array[0]);
	merge_sort(array,length);
	for(int i=0; i<length; i++)
	{
		cout<<array[i]<<" ";
	}
	return(0);
}
