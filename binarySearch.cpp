// tryCPpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
/*normal method
int main()
{
	int arr[10]={00,11,22,33,44,55,66,77,88,99},n;
	cout<<"Enter the element to search for:"<<endl;
	cin>>n;
	int mid=5;
	while(arr[mid]!=n && mid>0)
	{
		if(arr[mid]<n)
			mid=floor((mid+10)/2);
		else
			mid=floor(mid/2);
	}
	if(arr[mid]==n)
		cout<<"Element found at location: "<<mid;
	else
		cout<<"Element not found";


	

	cout<<"Hello World";
	system("PAUSE");
	getchar();
	return 0;
}*/
//recursive method
int find(int *input,int low, int high,int s)
{
	
	int mid= floor((low+high)/2);
	if(input[mid]==s)
		return mid;
	if(mid>low && mid<high)
	{
		if(input[mid]<s)
		{
			find(input,mid,high,s);
		}
		else if(input[mid]>s)
		{
			find(input,low,mid,s);
		}
	}
	else if (input[mid]!=s)
		return 0;
	


}
int main()
{
	int arr[10]={00,11,22,33,44,55,66,77,88,99},n;
	cout<<"Enter the element to search for:"<<endl;
	cin>>n;
	int result=find(arr,0,9,n);
	if(result==0)
		cout<<"Element not found"<<endl;
	else
		cout<<"Element "<<n<<" found at location "<<result;
	system("PAUSE");
	getchar();
	return 0;
}

