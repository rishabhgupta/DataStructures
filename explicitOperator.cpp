// cppTry.cpp : Defines the entry point for the console application.
//opertor overloading
/*
Member functions
Sperete non member functions 
*/

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
#include <conio.h>
using namespace std;
class Box
{
private:
	double lenght;
	double breadth;
	double height;
public:
	double getVolume();
	void setLength(double ln);
	void setHeight(double hg);
	void setBreadth(double br);
	Box operator+(const Box b)
	{
		Box box;
		box.lenght=this->lenght +b.lenght;
		box.breadth=this->breadth+b.breadth;
		box.height=this->height+b.height;
		return box;
	}

};
double Box::getVolume()
{
	return lenght*breadth*height;
}
void Box::setLength(double ln)
{
	lenght=ln;
}
void Box::setBreadth(double br)
{
	breadth=br;
}
void Box::setHeight(double hg)
{
	height=hg;
}

int main()
{
	
	Box Box1,Box2,Box3;
	double volume=0.0;
	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);

	Box2.setLength(12.0); 
	Box2.setBreadth(13.0); 
	Box2.setHeight(10.0);

	//VOLUME OF BOX1
	volume=Box1.getVolume();
	cout<<"Volume of box1 "<<volume;

	//VOLUME OF BOX2
	volume=Box2.getVolume();
	cout<<"Volume of Box2 "<<volume;

	//ADD THE TWO OBJECTS

	Box3=Box1+Box2;
	volume=Box3.getVolume();
	cout<<"Volume of box3: "<<volume;
 
	system("PAUSE");
	getchar();
    return 0;
}
