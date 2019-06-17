#include<iostream>
using namespace std;
int main()
{
	int sum(int);	
	cout<<sum(3)<<endl;
	return(0);
}
int sum(int x)            //recursive function
{
	int y;
	if(x==1)
	{
		return(x);
	}
	else
	{
		y = x + sum(x-1);            //recursion
		return(y);
	}

}
//This prgram sum the 1st 3 natural numbers as 3 is given as an actual argument
