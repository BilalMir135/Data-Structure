#include<iostream>
using namespace std;

void count_sort(int A[], int length, int B[], int K)
{
	int C[K];
	
	for(int i=0; i<K; i++)
	{
		C[i] = 0;
	}
	
	for(int i=0; i<length; i++)
	{
		C[A[i]] = C[A[i]]+1;
	}
	
	for(int i=1; i<K; i++)
	{
		C[i] = C[i] + C[i-1];
	}
	
	for(int i=length-1; i>=0; i--)
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]] = C[A[i]] -1;
	}
}

int main()
{
	int A[] = {5,9,4,5,3,6,8,5,4,8,7,4,6,9,7};
	int length = sizeof(A)/sizeof(A[0]);
	int B[length];
	int K = 10;
	count_sort(A,length,B,K);
	for(int i=0; i<length; i++)
	{
		cout<<B[i]<<" ";
	}
	return(0);
}
