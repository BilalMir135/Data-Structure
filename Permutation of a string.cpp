#include<iostream>
#include<string.h>
using namespace std;

void swap(char*x,char*y)
{
	char ch;
	ch = *x;
	*x = *y;
	*y = ch;
}

void permutation(char*s,int i,int n)
{
	static int count;
	int j;
	if(i==n)
	{
		count++;
		cout<<count<<". "<<s<<endl;
	}
	else
	{
		for(j=i; j<=n; j++)
		{
			swap((s+i),(s+j));
			permutation(s,i+1,n);
			swap((s+i),(s+j)); //Backtracking
		}
	}
}

int main()
{
	char *s;
	cout<<"Enter a string = ";
	cin>>s;
	permutation(s,0,strlen(s)-1);
	return(0);
}
