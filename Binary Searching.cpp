#include<iostream>
using namespace std;

void binary_search(int A[], int N, int item)
{
	int u,l,m;
	u = N-1;
	l = 0;
	while(l<=u)
	{
		m = (l+u)/2;
		if(A[m]==item)
		{
			cout<<"Search Successful item found on index "<<m<<endl;
			return;
		}
		else if(A[m]<item)
		{
			l = m+1;
		}
		else
		{
			u = m-1;
		}
	}
	cout<<"Search Unsuccessful"<<endl;
}

int main()
{
	int array[] = {11,13,17,25,31,37,43,64,81,90,100};
	int length = sizeof(array)/sizeof(array[0]);
	binary_search(array,length,64);
	binary_search(array,length,35);
	return(0);
}
