#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
 
struct queue
{
	int arr[100];
	int head;
	int tail;
	queue()
	{
		head=0;
		tail=0;
	}
	void enqueue(int n)
	{
		arr[tail]=n;
		tail++;
	}
	int dequeue()
	{
		if(head==0 && tail==0)
		{
			cout<<"Underflow";
			return 0;
		}
		else
		{
			int x=arr[head];
			head++;
			return x;
		}
	}
	void display()
	{
		for(int i=head;i<tail;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
};
struct stack
{
	queue q1;
	queue q2;
};
int main()
{
	stack s;
	int ch1,ch,n;
	do
	{
		cout<<"MENU\n1.PUSH\n2.POP\n3.DISPLAY\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter the element\n";
					cin>>n;
					s.q1.enqueue(n);
					s.q1.display();
					break;

			case 2: int y;
					while(s.q1.head<s.q1.tail-1)
					{
						int x=s.q1.dequeue();
						s.q2.enqueue(x);
					}
					y =s.q1.dequeue();
					while(s.q2.head<s.q2.tail)
					{
						int x=s.q2.dequeue();
						s.q1.enqueue(x);
					}
					s.q1.display();
					break;
			default: cout<<"Invalid Choice\n";
		}
		cout<<"Do you wish to continue [1 for yes 2 for no]\n";
		cin>>ch1;

	}while(ch1==1);
	system("PAUSE");
	getchar();
	return 0;
}