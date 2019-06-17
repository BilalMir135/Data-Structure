#include<iostream>
using namespace std;

static int x=0;
void TOH(int n, char BEG, char AUX, char END)
{
	if(n>=1)
	{
		TOH(n-1, BEG, END, AUX);
		cout<<"Move # "<<++x<<" "<<BEG<<" to "<<END<<endl;
		TOH(n-1, AUX, BEG, END);
	}
}

int main()
{
	int n;
	char BEG, AUX, END;
	cout<<"Number of plates = ";
	cin>>n;
	cout<<"Beginning rode = ";
	cin>>BEG;
	cout<<"Auxiliary rode = ";
	cin>>AUX;
	cout<<"End rode = ";
	cin>>END;
	system("CLS");
	TOH(n,BEG,AUX,END);
	return(0);
}
