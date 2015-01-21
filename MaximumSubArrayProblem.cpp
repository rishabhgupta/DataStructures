// tryCPpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define MINUS_INFINITY -9999
using namespace std;

//Kadanes Algorithm
int start;
int subArray(int *input,int n)
{
	int sum = 0;
	int maxSum=0;
	for(int i=0;i<n;i++)
	{
		sum+=input[i];
		if(sum>0)
		{
			if(sum>maxSum)
			{
				maxSum=sum;
				start=i;
			}
		}
		else
		{
			sum=0;
			start=i;
		}
	}
	return maxSum;

}
int main()
{
	cout<<"Maximum Sub Array Problem"<<endl;
	int arr[]= {-2, -5, 6, -2, -3, 1, 5, -6};
	int result=subArray(arr,8);
	cout<<"Max :"<<result<<endl;
	system("PAUSE");
	getchar();
	return 0;
}
/*
//Devide And conquer solution O(nlogn)
int low,high;
int max_sub_array_in_mid(int *input, int l, int h )
{
	int currentSum;
	int leftSum=MINUS_INFINITY;
	int rightSum=MINUS_INFINITY;
	
	int mid=floor((l+h)/2);
	//left side
	currentSum=0;
	for(int i=mid;i>=l;i--)
	{
		currentSum+=input[i];
		if(currentSum>leftSum)
		{
			leftSum=currentSum;
			low=i;

		}

	}
	//right side
	currentSum = 0;
	for(int i=mid+1;i<=h;i++)
	{
		currentSum+=input[i];
		if(currentSum>rightSum)
		{
			rightSum=currentSum;
			high=i;
		}
	}
	return (leftSum+rightSum);
	
}

int max_sub_array(int *input, int l, int h)
{
	if(l==h)
	{
		high=l;
		low=l;
		return input[l];
	}
	else
	{
		int mid=floor((l+h)/2);
		int leftMax=max_sub_array(input,0,mid);
		int rightMax=max_sub_array(input,mid+1,h);
		int crossMax=max_sub_array_in_mid(input,l,h);

		if(leftMax>rightMax && leftMax>crossMax)
			return leftMax;
		else if (rightMax>leftMax && rightMax>crossMax)
			return rightMax;
		else if(crossMax>leftMax && crossMax>rightMax)
			return crossMax;
	}
}
int main()
{
	cout<<"Maximum Sub Array Problem"<<endl;
	int arr[]= {-2, -5, 6, -2, -3, 1, 5, -6};
	int result=max_sub_array(arr,0,8);
	cout<<"Max :"<<result;
	system("PAUSE");
	getchar();
	return 0;
}
*/
/*
Brut Force Solution O(n^2)
int main()
{
	cout<<"Maximum Sub Array Problem"<<endl;
	int arr[]= {-2, -5, 6, -2, -3, 1, 5, -6};
	int i,j,k,maxSum=0,maxStart=0,maxEnd=0,tempSum;
	cout<<"The array is: ";
	for(i=0;i<8;i++)
		cout<<arr[i]<<", ";
	cout<<endl;
	maxSum=arr[0];
	for (i=0;i<8;i++)
	{
		tempSum=0;
		for(j=i;j<8;j++)
		{
			tempSum+=arr[j];
			if(tempSum>maxSum)
			{
				maxSum=tempSum;
				maxStart=i;
				maxEnd=j;
				cout<<"Cheacking Starting with "<<maxStart<<" Ending With "<<maxEnd<<" MaxSum is "<<maxSum<<endl;
			}
			
		}
	}
	cout<<"MaxSum= "<<maxSum<<" MaxStart "<<maxStart<<" MaxEnd "<<maxEnd;



	system("PAUSE");
	getchar();
	return 0;
}
*/
