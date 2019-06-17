#include<iostream>
#include<string.h>
using namespace std;

static int count =1;
void bin(int n, char A[])
{
	if(n<1)
	{
		cout<<count<<". ";
		for(int x=0; x<strlen(A); x++)
		{		
			cout<<A[x];	
		}
		count++;
		cout<<endl;
	}
	else
	{
		A[n-1] = '0';
		bin(n-1,A);
		A[n-1] = '1';
		bin(n-1,A);
	}
}

int main()
{
	int length;
	cout<<"Enter the length of permutation = ";
	cin>>length;
	char A [length+1];
	A[length] = '\0';
	bin(length,A);
	return(0);
}
