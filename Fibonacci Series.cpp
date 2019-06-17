#include<iostream>
using namespace std;

int fib(int x)
{
	if(x==1 || x==2)
	{
		return(1);
	}
	else
	{
		return(fib(x-1)+fib(x-2));
	}
}

int main()
{
	int x;
	cout<<"Enter a number = ";
	cin>>x;
	cout<<"Fibonacci series upto "<<x<<" terms"<<endl;
	for(int i=1; i<=x; i++)
	{
		cout<<fib(i)<<" ";	
	}
	cout<<"\n"<<x<<" term of the fibonacci series is "<<fib(x)<<endl;
	return(0);
}
