
#include "stdafx.h"
#include <iostream>

using namespace std;
 
struct queue
{
	int arr[10];
	int head;
	int tail;
	queue()
	{
		head=0;
		tail=0;
	}
	void enqueue(int n)
	{
		if(head==tail && head!=0)
			cout<<"Overflow"<<endl;
		else
		{
			cout<<"Entering:"<<n<<endl;
			arr[tail]=n;
			if(tail==9)
				tail=0;
			else
				tail++;
		}
	}
	void dequeue()
	{
		if(head==0 && tail==0)
			cout<<"Underflow"<<endl;
		else
		{
			int x=arr[head];
			if(head==9)
				head=1;
			else
				head++;
			cout<<"Removed element: "<<x<<endl;
		}
	}
	void display()
	{
		for(int i=head;i<tail;i++)
		{
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int main()
{
	queue q;
	int ch,ch1;
	do
	{
		cout<<"MENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nENTER YOUR CHOICE: "<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter the element "<<endl;
					int val;
					cin>>val;
					q.enqueue(val);
					break;
			case 2: q.dequeue();
					break;
			case 3: q.display();
					break;
			case 4: cout<<"Invalid choice"<<endl;


		}
		cout<<"Do you wish to continue [1 for yes 2 for no]"<<endl;
		cin>>ch1;

	}while(ch1==1);
	system("PAUSE");
	getchar();
	return 0;
}
