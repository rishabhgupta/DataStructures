#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
#include <conio.h>

using namespace std;

struct node
{
	 int info;
	 node* next;
}*start;

node* createNode(int value)
{
	node *temp;
	temp=new(node);
	temp->info=value;
	temp->next=NULL;
	return temp;

}

void insertBegin()
{
	int val;
	cout<<"Enter the value to be inserted:\n";
	cin>>val;
	node* temp,*p;
	temp=createNode(val);
	if(start==NULL)
	{
		start=temp;
		start->next=NULL;
	}
	else
	{
		p=start;
		start=temp;
		start->next=p;

	}
	cout<<"Element inserted in the begining\n";
}
void insertLast()
{
	int val;
	cout<<"Enter the value to be inserted in the end\n";
	cin>>val;
	node *temp,*travel;
	temp = createNode(val);
	travel=start;
	while(travel->next!=NULL)
		travel=travel->next;
	temp->next=NULL;
	travel->next=temp;

}
void display()
{
	node* travel;
	travel=start;
	while(travel!=NULL)
	{
		cout<<"->";
		cout<<travel->info;
		travel=travel->next;
	}
	cout<<endl;
}
int main()
{
	int ch,ch2;
	do
	{
		cout<<"MENU\n1.Insert Bigining\n2.Inser Last\n3.Display\n4.Exit\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1: insertBegin();
			break;
		case 2: insertLast();
			break;
		case 3: display();
			break;
		default: cout<<"Invalid Choice\n";
			break;

		}
		cout<<"Do you wish to continue\n";
		cin>>ch2;
	}while(ch2==1);
}