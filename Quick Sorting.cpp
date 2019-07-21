#include<iostream>
using namespace std;

void swap (int *x, int *y)
{
	int z=*x;
	*x=*y;
	*y=z;
}

void quick(int array[], int BEG, int END, int length, int *LOC)
{
	step2:		//right->left
		int LEFT, RIGHT;
		LEFT = BEG;
		RIGHT = END;
		*LOC = BEG;
		while(array[*LOC]<array[RIGHT] && *LOC!=RIGHT)
		{
			RIGHT--;
		}
		if(*LOC==RIGHT)
		{
			return;
		}
		if(array[*LOC]>array[RIGHT])
		{
			swap(&array[*LOC],&array[RIGHT]);
			*LOC = RIGHT;
		}
		goto step3;
	step3:		//left->right
		while(array[LEFT]<array[*LOC] && LEFT!=*LOC)
		{
			LEFT++;
		}
		if(LEFT==*LOC)
		{
			return;
		}
		if(array[LEFT]>array[*LOC])
		{
			swap(&array[LEFT],&array[*LOC]);
			*LOC = LEFT;
		}
		goto step2;
}

void quick_sort(int array[], int length)
{
	int BEG,END,LOC,TOP=-1;
	int LOWER[length-1];
	int UPPER[length-1];
	if(length>1)
	{
		TOP++;
		LOWER[TOP]=0;
		UPPER[TOP]=length-1;
	}
	while(TOP!=-1)
	{
		BEG=LOWER[TOP];
		END=UPPER[TOP];
		TOP--;
		quick(array,BEG,END,length,&LOC);
		if(BEG<LOC-1)
		{
			TOP++;
			LOWER[TOP]=BEG;
			UPPER[TOP]=LOC-1;
		}
		if(LOC+1<END)
		{
			TOP++;
			LOWER[TOP]=LOC+1;
			UPPER[TOP]=END;
		}
	}
}

int main()
{
	int array[] = {44,33,11,55,77,90,40,60,99,22,88,66};
	int length = sizeof(array)/sizeof(array[0]);
	quick_sort(array,length);
	for(int i=0; i<length; i++)
	{
		cout<<array[i]<<" ";
	}
	return(0);
}
