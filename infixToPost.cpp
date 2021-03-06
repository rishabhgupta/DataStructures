
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

class stack
{

	char arr[100];
	int top;
	
public:

	stack()
	{
		top=-1;
	}

	void push(char value)
	{
		arr[++top] = value;
	}
	bool isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	char peek()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty nothing to peep.\n";
			return -1;
		}
		return arr[top];
	}
	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty nothing to pop.\n";
			return;
		}
		else
			top--;
	}
	
};
void stackFn()
{
	stack stk;

	int ch, ch2;
	char value;
	do
	{
		cout << "Menu\n1.Push\n2.Peek\n3.Pop\nEnter:\n";
		cin >> ch;
		switch (ch)
		{
			case 1: cout << "Enter value to push:\n";
					cin >> value;
					stk.push(value);
					break;
			case 2:	cout << stk.peek();
					break;
			case 3: stk.pop();
					break;
			default: cout << "Invalid Choice\n";
					break;

		}
		cout << "\nDo you wish to cont..\n";
		//getchar();
		cin >> ch2;

	}while(ch2 == 1);
}
int isOperand(char value)
{
	if ((value >= 'a' && value <= 'z') || (value >= 'A' && value <= 'Z'))
	{
		return 1;
	}
	else
		return 0;
}
void display(char *output,int val)
{
	for (int i = 0; i <= val; i++)
	{
		cout << output[i] << " ";
	}
}
int prec(char value)
{
	switch(value)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
			
	}
	return -1;
}
int main()
{
	string infix;
	stack stk;
	char output[100]; int head = -1, pred = -1;
	cout << "Enter a infix Expression.\n";
	getline(cin, infix);
	for (int i = 0; i < infix.length(); i++)
	{
		if (isOperand(infix[i]))
		{
			output[++head] = infix[i];
		}
		else if (prec(infix[i]) > pred)
		{
			stk.push(infix[i]);
			//pred = prec(stk.peek());
			//cout << pred << endl;
		}
		else if(infix[i]=='(')
		{
			stk.push(infix[i]);
			pred=prec(infix[i]);
		}
		else if(infix[i]==')')
		{
			while (!(stk.isEmpty()) && stk.peek()!='(')
			{
				output[++head]=stk.peek();
				stk.pop();
			}
			stk.pop();
			
		}
		else 
		{
			while (!(stk.isEmpty()) && prec(infix[i])<=pred)
			{
				//cout << "PREC: " << prec(infix[i])<<" PRED "<<pred<<endl;
				output[++head] = stk.peek();
				stk.pop();
				pred = prec(stk.peek());

			}
			stk.push(infix[i]);
			pred = prec(stk.peek());
		}

		
	}
	while (!(stk.isEmpty()))
	{
		output[++head]= stk.peek();
		stk.pop();
	}
	display(output,head);
	//cout << "\nOperators\n";
	

	


	//system("PAUSE");
	//getchar();
	return 0;
}
