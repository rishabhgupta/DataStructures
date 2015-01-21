#include <iostream>
#include <cmath>
#include <ncurses.h>
#include <cstdlib>

using namespace std;

struct node
{
	int data;
	node* next;
}*start;

node *head_ref1, *head_ref2;

/**
*Function to create a new node
*@param integer value
*@return node
*/
node* createNode(int value)
{
	node *temp;
	temp = new(node);
	temp->data = value;
	temp->next = NULL;
	return temp;
}

/**
*Function to insert a value in the begining of the linked list
*/
void insertBegin()
{
	int value;
	cout<<"Enter the value to be inserted"<<endl;
	cin>>value;
	node *temp,*p;
	temp= createNode(value);
	if(start==NULL)
	{
		start=temp;
		start->next= start;
	}
	else
	{
		node *travel;
		travel= start;
		while(travel->next!=start)
		{
			travel=travel->next;
		}
		travel->next=temp;
		temp->next=start;
	}
	cout<<"Element inserted succesfully at the begining."<<endl;

}

node* last()
{
	node* travel= start;
	while(travel->next!=start)
		travel=travel->next;
	return travel;
}
/**
*Function to display a linked list
*/
void display()
{
	node *travel;
	travel= start;
	if(start==NULL)
	{
		cout<<"List is currently empty."<<endl;
		return;
	}
	while(travel->next!=start && start!=NULL)
	{
		cout<<"->";
		cout<<travel->data;
		travel=travel->next;
	}
	cout<<"->";
	cout<<travel->data;
	if(start==NULL)
	{
		cout<<"List is currently empty."<<endl;
	}
}

void deleteNode()
{
	node *temp,*travel;
	int value;
	cout<<"Enter element to be deleted."<<endl;
	cin>>value;
	//if thei is only one element in the list
	if(start->next==start && start->data==value)
	{
		temp= start;
		start=NULL;
		cout<<"Only Element in the list "<<temp->data<<" has been deleted."<<endl;
		free(temp);
		display();
		return;
	}
	//fist value 
	if(start->next!=start && start->data==value)
	{
		temp= start;
		travel= last();
		start=start->next;
		travel->next=start;
		cout<<"First in the list "<<temp->data<<" has been deleted."<<endl;
		free(temp);
		display();
		return;
	}
	//delete middle
	travel=start->next;
	node* pre = start;
	while(travel->next!=start)
	{
		if(travel->data==value)
		{
			temp=travel;
			pre->next=travel->next;
			cout<<"Element in the list "<<temp->data<<" has been deleted."<<endl;
			free(temp);
			display();
			return;
		}
		else
		{
			travel=travel->next;
			pre=pre->next;
		}
	}
	//deleting the last element
	travel= last();

	if(travel->data==value)
	{
		temp=travel;
		pre= start;
		while(pre->next!=travel)
		{
			pre= pre->next;
		}
		pre->next=start;
		cout<<"Last element in the list "<<temp->data<<" has been deleted."<<endl;
		free(temp);
		display();
		return;

	}
	cout<<"Element not found\n";
}

void display(node* head)
{
	node* s=head;
	while(s->next!=head)
	{
		cout<<"->"<<s->data;
		s=s->next;
	}
	cout<<"->"<<s->data<<endl;
	return;
}
void splitList()
{
	node* fast_ptr=start;
	node* slow_ptr=start;
	while(fast_ptr->next!=start && fast_ptr->next->next!=start)
	{
		fast_ptr=fast_ptr->next->next;
		slow_ptr= slow_ptr->next;
	}
	if(fast_ptr->next!=start)
	{
		fast_ptr=fast_ptr->next;
	}
	cout<<"Middle: "<<slow_ptr->data<<endl;
	cout<<"Last: "<<fast_ptr->data<<endl;
	head_ref1 =start;
	head_ref2 =slow_ptr->next;
	slow_ptr->next= head_ref1;
	fast_ptr->next= head_ref2;
	cout<<"\nList 1: ";
	display(head_ref1);
	cout<<"\nList 2: ";
	display(head_ref2);

}
int main()
{
	int ch,ch2;
	do
	{
		cout<<"MENU\n1.Insert Bigining\n2.Display\n3. Delete \n4. Last Element\n5. Split List\nEnter your choice\n";
		cin>>ch;
		switch(ch)
		{
		case 1: insertBegin();
			break;;
		case 2: display();
			break;
		case 3: deleteNode();
			break;
		case 4: node* temp;
				temp =last();
				cout<<"Last element of the list is "<<temp->data<<endl;
			break;
		case 5: splitList();
			break;
		default: cout<<"Invalid Choice\n";
			break;

		}
		cout<<"\nDo you wish to continue\n";
		cin>>ch2;
	}while(ch2==1);
	getchar();
	return 0;
}