// cppTry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  

using namespace std;
class square 
{
	int l,b;
public:
	void set(int len,int bre)
	{
		l=len;
		b=bre;
	}
	int get()
	{
		return l*b;
	}
};
int main()
{
	square sq;
	sq.set(2,2);
	cout<<"Area: "<<sq.get();

	system("PAUSE");
	getchar();
    return 0;
}
