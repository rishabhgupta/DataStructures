#include <iostream>
#include <cmath>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

struct node
{
	int data;
	node* next;
	node* pre;

}*start;

node* createNode(int val)
{
	node *temp;
	temp = new(node);
	temp->data= val;
	temp->next=NULL;
	temp->pre= NULL;
	return temp;

}
void insertEndNode()
{
	int val;
	cout<<"Enter element to be inserted.\n";
	cin>>val;
	node* temp;
	temp= createNode(val);

	if(start==NULL)
	{
		start=temp;
		temp->pre=start;
	}
	else
	{
		node* travel;
		travel=start;
		while(travel->next!=NULL)
		{
			travel=travel->next;
		}
		travel->next=temp;
		temp->pre=travel;
		cout<<"ELement inserted successfully at the end.\n";
	}
}
void insertBigNode()
{
	int val;
	cout<<"Enter element to be inserted.\n";
	cin>>val;
	node* temp;
	temp= createNode(val);

	if(start==NULL)
	{
		start=temp;
		temp->pre=start;
	}
	node* p=start;
	start=temp;
	temp->next=p;
	p->pre=temp;
	cout<<"ELement inserted successfully at the Bigining.\n";
}
void insertAfter(int val)
{	
	node* travel=start;
	while(travel->next!=NULL)
	{
		if(travel->data==val)
			break;
		travel=travel->next;
	}
	if(travel->data==val)
	{
		node* temp;
		int inVal;
		cout<<"Enter Element to insert\n";
		cin>>inVal;
		temp= createNode(inVal);
		temp->next=travel->next;
		travel->next->pre=temp;
		travel->next=temp;
		temp->pre=travel;

		cout<<"\nNode inserted after "<<travel->data<<endl;

	}
	else
	{
		cout<<"Element not found\n";
	}
}
void deleteNode(int value)
{
	node* travel=start;
	node* temp;
	//delete bigining
	if(start->data==value)
	{
		temp=start;
		start=start->next;
		start->pre=NULL;
		cout<<"Element Deleted\n";
		free(temp);
		return;
	}
	//delete middle
	while(travel->next->next!=NULL)
	{
		if(travel->data==value)
			break;
		travel=travel->next;
	}
	if(travel->data==value)
	{
		temp=travel;
		temp->pre->next=temp->next;
		temp->next->pre=temp->pre;
		free(temp);
		cout<<"Deleted Node\n";
		return;
	}
	//delete last element
	if(travel->next->data=value)
	{
		temp=travel->next;
		free(temp);
		travel->next=NULL;
		cout<<"Element Delete\n";
		return;
	}

}
void revereseList()
{
	cout<<"\nReversed\n";
	node *temp;
	node *pred=NULL;
	node* succ;
	node* travel= start;
	while(travel)
	{
		succ= travel->next;
		travel->next=pred;
		travel->pre=succ;
		pred=travel;
		travel=succ;
	}
	start=pred;

}
void display()
{
	cout<<"Displaying..\n";
	node* travel = start;
	while(travel!=NULL)
	{
		cout<<"-> "<<travel->data;
		travel=travel->next;
	}
}
void displayRev()
{

	cout<<"Printing Reverse:\n";
	node* travel;
	travel=start;
	while(travel->next!=NULL)
	{
		travel=travel->next;
	}

	while(travel!=start)
	{
		cout<<" <-"<<travel->data;
		travel=travel->pre;
	}
	cout<<"<- "<<travel->data;

}
void swap(int value)
{
	
}
int main()
{
	int ch,cont;
	do
	{
		cout<<"MENU\n1.Insert End\n2.Display\n3.Display Reverse \n4.Insert Bigining\n5. Insert After\n6. Delete \nEnter 7. Reverse\nyour choice\n";
		cin>>ch;
		switch(ch)
		{
			case 1: insertEndNode();
					break;
			case 2: display();
					break;
			case 3: displayRev();
					break;
			case 4: insertBigNode();
					break;
			case 5: int value;
					cout<<"Enter a value\n";
					cin>>value;
					insertAfter(value);
					break;
			case 6: int v;
					cout<<"Enter a value\n";
					cin>>v;
					deleteNode(v);
					break;
			case 7: revereseList();
					break;
			default: cout<<"Error.\n";
		}
		cout<<"\nDo you wish to cont..\n";
		cin>>cont;
	}while(cont==1);
	

}

