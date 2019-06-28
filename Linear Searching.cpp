#include<iostream>
#include <iterator>
using namespace std;

void Linear_search(int l[],int N, int item)
{
	int flag = 0;
	for(int i=0; i<N-1; i++)
	{
		if(l[i]==item)
		{
			flag = 1;
			cout<<"Search Successful"<<endl;
			break;
		}
	}
	if(flag == 0)
	{
		cout<<"Search Unsuccessful"<<endl;
	}
}

int main()
{
	int array[] = {10,20,30,40,50,60,99,67,34,23,56,78};
	int length = sizeof(array)/sizeof(array[0]);
	Linear_search(array,length,68);
	Linear_search(array,length,34);
	return(0);
}
