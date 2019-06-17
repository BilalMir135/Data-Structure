#include<iostream>
using namespace std;
long factorial(int x)
{
	if(x>1)
	{
		return(x*factorial(x-1));
	}
	return(x);
}
int main()
{
	int num;
	cout<<"Number = ";
	cin>>num;
	cout<<"Factorial of "<<num<<" is "<<factorial(num)<<endl;
	return(0);
}
