// tryCPpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//bubble sort
int main()
{
	int arr[100],i,j,k,temp;
	cout<<"Enter no. of elements"<<endl;
	cin>>k;
	cout<<"Enter Elements";
	for(i=0;i<k;i++)
		cin>>arr[i];
	for(i=0;i<k;i++)
		for(j=i+1;j<k;j++)
		{
			if(arr[i]>arr[j])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}
		}

	for(i=0;i<k;i++)
		cout<<arr[i]<<" ";
	system("PAUSE");
	getchar();
	return 0;
}

