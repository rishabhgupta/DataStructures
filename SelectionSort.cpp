// tryCPpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n,i,j,arr[100],temp;
	cout<<"Selection Sort"<<endl;
	cout<<"Enter the number of values\n";
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	int small=arr[0];
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[i])
			{
				temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;
			}

		}
	}
	//print
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	getchar();
	system("PAUSE");
	return 0;
}

