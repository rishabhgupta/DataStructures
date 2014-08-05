#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
 
void display(int *input,int end)
{
	for(int i=0;i<end;i++)
		cout<<input[i]<<" ";
	cout<<endl;
}
int partition(int *input, int beg, int end)
{
	int p=beg,pivot =input[end],loc,r=end;
	while(beg<end)
	{
		while(input[p]<pivot)
			p++;
		while(input[r]>pivot)
			r--;
		if(input[p]==input[r])
			p++;
		else if(p<r)
		{
			int temp =input[p];
			input[p]=input[r];
			input[r]=temp;
		}

	}
	return r;
}
void quickSort(int *input, int  beg, int end)
{
	if(beg<end)
	{
		int p=partition(input,beg,end);
		quickSort(input,beg,p-1);
		quickSort(input,p+1,end);
	}
}
int main()
{
	int a[100],i,n,beg,end;
	cout<<"Enter the number of elements"<<endl;
	cin >>n;
	cout<<"Enter the elements\n"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	beg=0;
	end=n;
	cout<<"Input Array\n";
	display(a,end);
	quickSort(a,beg,end);
	cout<<"\nArray after sorting\n";
	display(a,end);

	
	system("PAUSE");
	getchar();
	return 0;
}
