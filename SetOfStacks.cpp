#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
struct stack
{
	int arr[100];
	int top;
	stack()
	{
		top=-1;
	}
	stack(int n)
	{
		top=n;
	}
	void pop()
	{
		top--;
	}
	void push(int n)
	{
		top++;
		arr[top]=n;
	}
	void display()
	{
		for(int i=0;i<=top;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
};
struct setOfStacks
{
	stack sArray[100];
	int sTop;
	setOfStacks()
	{
		sTop=-1;
	}
	void push(stack s)
	{
		sTop++;
		sArray[sTop]=s;	
		
	}
	void pushStack(int n)
	{
		sArray[sTop].push(n);
	}
	void popStack()
	{
		sArray[sTop].pop();
	}
	void pop()
	{
		sTop--;
	}
	void display()
	{
		for(int i=0;i<=sTop;i++)
		{
			cout<<"Stack: "<<i<<" -> ";
			sArray[i].display();

		}
	
	}
};
void chckFull(int *cnt, int th, setOfStacks *sos)
{
	if(*cnt%th==0)
	{
		//reached limit 
		stack obj;
		*cnt=0;
		sos->push(obj);
		cout<<"New Stack created\n";
	}
}
void chckEmpty(int *cnt, int th, setOfStacks *sos)
{
	if(*cnt%th==0)
	{
		//empty delete stack
		sos->pop();
		cout<<"Stack Deleted\n";
		*cnt=th;
	}
}
int main()
{
	setOfStacks sos;
	int th,count=0,ch,ch1,val;
	cout<<"Enter thr threshhold value\n";
	cin>>th;
	stack s1;
	sos.push(s1);
	do
	{
		cout<<"MENU\n1.PUSH\n2.POP\n3.DISPLAY\nEnter your choice:\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"Enter element to push\n";
					cin>>val;
					sos.pushStack(val);
					count++;
					chckFull(&count,th,&sos);
					cout<<"Limit= "<<(th-count)<<endl;
					break;

			case 2:	sos.popStack();
					count--;
					chckEmpty(&count,th,&sos);
					break;
					
			case 3: sos.display();
					break;
					

		}
		cout<<"do you wish to continue\n";
		cin>>ch1;

	}while(ch1==1);

	system("PAUSE");
	getchar();
	return 0;
}