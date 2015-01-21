// tryCPpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
int N;int arr[100];
//function to swap to numbers in an array
void swap(int i, int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;

}
//function to swap largest element in an array
void maxHeap(int i)
{
	int left=2*i;
	int right=2*i+1;
	int max=i;
	if(left<=N && arr[left]>arr[max])
		max=left;
	if(right<=N && arr[right]>arr[max])
		max=right;
	if(max!=i)
	{
		swap(i,max);
		maxHeap(max);
	}
}
//built heap
void heapify()
{
	for(int i=N/2;i>=0;i--)
		maxHeap(i);
}
//sorting
void sort()
{
	heapify();
	for(int i=N;i>=0;i--)
	{
		swap(0,i);
		N=N-1;
		maxHeap(0);
	}
}
int main()
{
	cout<<"\nHeap Sort";
	cout<<"\nEnter the number integer elements";
	cin>>N;
	int count=N;
	cout<<"\nEnter the values";
	for(int i=0;i<N;i++)
		cin>>arr[i];
	cout<<"\nUnsorted Array";
	for(int i=0;i<N;i++)
		cout<<arr[i];
	sort();
	cout<<"\nSorted Array";
	for(int i=0;i<=count;i++)
		cout<<arr[i]<<" ";
	system("PAUSE");
	getchar();
	return 0;
}
