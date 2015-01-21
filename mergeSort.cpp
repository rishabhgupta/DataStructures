// tryCPpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

void print(int *input,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<input[i]<<" ";
	}
	cout<<endl;
}
void merge(int *input, int p, int r)
{
	int mid = floor((p+r)/2);
	int i1=0;
	int i2=p;
	int i3=mid+1;
	int temp[100];
	//merge from both arrays
	while(i2<=mid && i3<=r)
		if(input[i2]<input[i3])
			temp[i1++]=input[i2++];
		else
			temp[i1++]=input[i3++];
	//merge remaining elements
	while(i2<=mid)
		temp[i1++]=input[i2++];
	while(i3<=r)
		temp[i1++]=input[i3++];
	//move
	for(int i=p;i<=r;i++)
		input[i]=temp[i-p];
}
void mergesort(int *input, int p, int r)
{
	int mid;
	if(p<r)
	{
		mid=floor((p+r)/2);
		mergesort(input,p,mid);
		mergesort(input,mid+1,r);
		merge(input,p,r);
	}
}
int main()
{
	int n,i,j,input[100];
	cout<<"Enter the number of values"<<endl;
	cin>>n;
	cout<<"Enter the values "<<endl;
	for(i=0;i<n;i++)
		cin>>input[i];
	cout<<"Usorted Array is:"<<endl;
	print(input,n);
	mergesort(input,0,n-1);
	cout<<"Sorted Array"<<endl;
	print(input,n);
	system("PAUSE");
	getchar();
	return 0;
}

