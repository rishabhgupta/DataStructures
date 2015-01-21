
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct  stack
{
	int arr[100];
	int top;
	stack()
	{
		top=-1;
	}
	void inc()
	{
		top++;
	}
	void dec()
	{
		top--;
	}
};
int isEmpty(stack *st)
{
	if(st->top==-1)
		return 1;
	else
		return 0;

}
void push(stack *st, int n)
{
	st->inc();
	cout<<"Inserting at "<<st->top<<endl;
	st->arr[st->top]=n;
}
void pop(stack *st)
{
	if(isEmpty(&*st))
		cout<<"Underflow\n";
	else
		st->dec();
}
void display(stack *st)
{
	cout<<"Displaying "<<st->top<<" Values:"<<endl;
	for(int i=0;i<=st->top;i++)
	{
		cout<<st->arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	stack stk;int ch;int ch1;
	
	
	
	do
	{
		cout<<"Menu\n1.PUSH\n2.POP\n3.DISPLAY\nEnter your choice :"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 1: cout<<"Enter the element: "<<endl;
				int num;
				cin>>num;
				push(&stk,num);
				break;

		case 2: pop(&stk);
				break;

		case 3: display(&stk);
				break;
		default: cout<<"Invalid input"<<endl;
		

		}
		cout<<"Do you wish to continue:[1 for yes 2 for no]\n";
		
		cin>>ch1;

	}while(ch1==1);

	system("PAUSE");
	getchar();
	return 0;
}
