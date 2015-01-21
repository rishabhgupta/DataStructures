// cppTry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
#include <conio.h>

using namespace std;
class shape
{
protected:
	int width;
	int height;
public:
	void setWidth(int wd){ width = wd; }
	void setHeight(int ht){ height = ht; }
};
class paint
{
public:
	int getCost(int area)
	{
		return area * 7;
	}
};
class Rectangle : public shape, public paint
{
public:
	int getArea()
	{
		return width*height;
	}
};
int main()
{

	Rectangle rect;
	rect.setHeight(10);
	rect.setWidth(9);
	int area = rect.getArea();
	cout << "Total Area: " << area<<endl;
	cout << "Paint cost " << rect.getCost(area)<<endl;

	system("PAUSE");
	getchar();
	return 0;
}
