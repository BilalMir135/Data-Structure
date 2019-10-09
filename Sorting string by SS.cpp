#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int min(char arr[],int starting_index,int length){
	int min_value = int(arr[starting_index]);
	int loc = starting_index;
	for(int i=starting_index+1; i<length; i++){
		if(min_value>int(arr[i])){
			min_value = int(arr[i]);
			loc = i;
		}
	}
	return(loc);
}



void swap(char *x, char *y){
	char z = *x;
	*x = *y;
	*y =z;
}



int main()
{
	string name = "Bilal Mir";
	int length = name.length();
	char arr[length+1]; 
	strcpy(arr,name.c_str());
	int loc;
	for(int i=0; i<length-1; i++){
		loc = min(arr,i,length);
		swap(&arr[loc],&arr[i]);
	} 
	for(int i=0; i<length; i++){
		cout<<arr[i]<<" ,";
	}
	return(0);
}
