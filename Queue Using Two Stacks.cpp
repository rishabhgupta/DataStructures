#include "stdafx.h"
#include <iostream>

using namespace std;
 
struct stack
{
	int arr[100];
	int top;
	stack ()
	{
		top=-1;
	}
	void push(int n)
	{
		top++;
		arr[top]=n;
		
	}
	int pop()
	{
		int x=arr[top];
		top--;
		return x;
	}
	void display()
	{
		for(int i=0;i<=top;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
};
struct queue
{
	stack s1;
	stack s2;
};
int main()
{
	queue q;
	int ch,ch1,n;
	do
	{
		cout<<"MENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1:	cout<<"Element to enter\n";
					cin>>n;
					q.s1.push(n);
					q.s1.display();
					break;
			case 2: if(q.s1.top==-1 && q.s2.top==-1)
					{
						
						cout<<"Underflow";
					}
					else
					{
						if(q.s2.top==-1)
						{
							while(q.s1.top!=-1)
							{
								int x=q.s1.pop();
								q.s2.push(x);
								
							}
							int y=q.s2.pop();
							cout<<"Element dequeued: "<<y<<endl;
							
						}
						while(q.s2.top!=-1)
						{
							int x=q.s2.pop();
							q.s1.push(x);
								
						}
						q.s1.display();
						
					}
					break;

			default: cout<<"Invalid choice\n";


		}
		cout<<"Do you wish to contiue [1 for yes 2 for no]\n";
		cin>>ch1;
	}while(ch1==1);
	system("PAUSE");
	getchar();
	return 0;
}