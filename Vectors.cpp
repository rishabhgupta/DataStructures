// vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void vectorTest();

template <typename T> 
struct stackV
{
	vector<T> vil;
	void pushBack(T input)
	{
		vil.push_back(input);
	}
	T pop()
	{
		T temp = vil.back();
		vil.erase(vil.end()-1);
		return temp;
	}
	void display()
	{
		for (T &v : vil)
		{
			cout << v << " ";
		}
	}
};
int main()
{ 

	stackV<string> si;
	int ch, ch1;
	string input,out;
	do
	{
		cout << "Menu\n1.Push\n2.Pop\n3.Display\nEnter your choice:\n";
		cin >> ch;
		switch(ch)
		{
			case 1: cout << "Enter the element to push" << endl;
					cin >> input;
					si.pushBack(input);
					break;
			case 2:	out = si.pop();
					cout << "Element Popped:" << out << endl;
					break;
			case 3:	cout << "Elements are: " << endl;
					si.display();
					break;
			default: cout << "Error";
					break;
		}
		cout << "\nDo you wish to continue: [1 for yes ]" << endl;
		cin >> ch1;
	} while (ch1==1);
	
	


	
	system("PAUSE");
	return 0;
}
void vectorTest()
{
	cout << "Vector Example" << endl;
	vector <int> vil = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
	cout << "Size" << vil.size() << endl;
	cout << "Front" << vil.front() << endl;
	cout << "Back" << vil.back() << endl;
	cout << "Insert 42 at 5" << endl;
	vil.insert(vil.begin() + 5, 42);
	cout << "New size" << vil.size() << endl;
	cout << "Element at 5" << vil[5] << endl;
	cout << "Erase Element" << endl;
	vil.erase(vil.begin() + 5);
	cout << "New Size" << vil.size() << endl;
	cout << "Push back 47" << endl;
	vil.push_back(47);
	cout << "Last element" << vil.back();
	for (int &v : vil)
	{
		cout << v << " ";
	}
	cout << "Erase Last" << endl;
	vil.erase(vil.end());

}
