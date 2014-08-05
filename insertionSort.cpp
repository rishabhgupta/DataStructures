// insertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//insertion sort
int main()
{
	int j,i,n,arr[100],temp,ptr;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	cout<<"Enter values"<<endl;
	for(i=1;i<=n;i++)
		cin>>arr[i];
	for(j=2;j<=n;j++)
	{
		temp=arr[j];
		ptr=j-1;
		while(temp>arr[ptr])
		{
			arr[ptr+1]=arr[ptr];
			ptr--;
		}
		arr[ptr+1]=temp;

	}
	//print sorted
	cout<<endl<<"Sorted"<<endl;
	for(i=1;i<=n;i++)
		cout<<arr[i]<<" ";
	getchar();
	getchar();
	return 0;
	
}






