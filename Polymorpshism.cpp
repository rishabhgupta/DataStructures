// cppTry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
#include <conio.h>

using namespace std;

class Shape
{
protected:
	int width, height;
public:
	Shape(int a = 0, int b = 0)
	{
		width = a;
		height = b;
	}
	virtual int area()
	{
		cout << "Parent class area" << endl;
		return 0;
	}
};
class Rectangle : public Shape
{
public:
	Rectangle(int a = 0, int b = 0) :Shape(a, b) {}
	int area()
	{
		cout << "Rectangle Class Area" << endl;
		return (width*height);
	}
};
class Triangle :public Shape
{
public:
	Triangle(int a = 0, int b = 0) :Shape(a, b){}
	int area()
	{
		cout << "Triangle Area class" << endl;
		return (width*height / 2);
	}
};
int main()
{
	Shape *shape;
	Rectangle rec(10, 7);
	Triangle tri(10, 5);

	//store the address of the rectangle shape
	shape = &rec;
	//call rectangle area
	cout << "Via Pointer" << endl;
	shape->area();
	cout << "via object" << endl;
	rec.area();

	//store the address of the triangle
	shape = &tri;
	cout << "Call via pointer" << endl;
	shape->area();
	cout << "Call via object" << endl;
	tri.area();
	system("PAUSE");
	getchar();
	return 0;
}
