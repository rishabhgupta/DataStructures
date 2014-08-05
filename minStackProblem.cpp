#include "stdafx.h"
#include <iostream>
#define INFINITY 9999
using namespace std;
 struct stack
 {
	 struct node
	 {
		 int val;
		 int min;
		 node()
		 {
			 min=0;
		 }
	 };
	 node arr[100];
	 int top;
	 stack()
	 {
		top=-1;
		
	 }
	 int pop()
	 {
		 if(top==-1)
		 {
			 cout<<"Underflow";
			return NULL;
		 }
		 else
		 {
			 int x=arr[top].val;
			 top--;
			 return x;
		 }

	 }
	 void push(int n)
	 {
		 top++;
		 arr[top].val=n;
		 if(top==0)
		 {
				 arr[top].min=n;
		 }
		 else
		 {
			 if(n<arr[top-1].val)
				 arr[top].min=n;
		 }
		 cout<<"Element Inserted\n";
		
	 }
	 void display()
	 {
		 for(int i=0;i<=top;i++)
			 cout<<arr[i].val<<" ";
		 cout<<endl;
	 }
	 int minimum()
	 {
		 return arr[top].min;
	 }

 };
int main()
{
	int n,ch,ch1,x,z;
	stack s;
	cout<<"Enter tha number of elements in stack\n";
	cin>>n;
	do
	{
		cout<<"MENU\n1.PUSH\n2.POP\n3.DISPLAY\n4.MIN\nEnter Your Choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter the element\n";
					int val;
					cin>>val;
					s.push(val);
					break;

			case 2: x=s.pop();
					cout<<x<<" popped\n";
					break;

			case 3: s.display();
					break;

			case 4: cout<<"The minimum value in stack is "<<endl;
					z=s.minimum();
					cout<<z<<endl;
					break;

			default: cout<<"Invalid choice\n";

		}
		cout<<"Do you wish to continue [1 for y 2 for no]\n";
		cin>>ch1;
	}while(ch1==1);


	system("PAUSE");
	getchar();
	return 0;
}
