// cppTry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
#include <conio.h>
using namespace std;

class cls1
{
	int i;
public:
	void set(int val){i=val;}
	int get(){return i+1;}
	void lookAtThis(int i);
};
void cls1::lookAtThis(int i)
{
	cout<<"I is"<<this->i<<endl;
}

int main()
{
	int i=47;
	cls1 obj;
	obj.set(i);
	obj.lookAtThis(9);
	cout<<obj.get();

	system("PAUSE");
	getchar();
    return 0;
}
