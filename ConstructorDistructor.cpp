// cppTry.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
//#include <conio.h>
using namespace std;

const static string unk="unknown";
const static string clone_prefix ="clone-";

class Animal
{
	string _type;
	string _name;
	string _sound;
public:
	Animal();//default constructor
	Animal ( string &type,  string &name,  string &sound);
	Animal ( Animal &);//constructor copy
	Animal & operator =(const Animal &);
	~Animal();//destructor;
	void print() ;
};
Animal::Animal() : _type(unk), _name(unk), _sound(unk) 
{
	cout<<"Default constructor"<<endl;
} 
Animal::Animal ( string & type,  string & name,  string & sound )
	: _type(type), _name(name), _sound(sound) 
{
	cout<<"Constructor with arguments"<<endl;

}
Animal::Animal( Animal & a)
{
	cout<<"Copy constructor"<<endl;
	_type=a._type;
	_sound=a._sound;
	_name =  a._name;
}
Animal::~Animal() 
{
	cout<<"destructor:"<<endl ;
	
}
void Animal::print() 
{
	cout<<"name " << _name << "the" <<_type << "dsys" <<_sound<<endl;
}
int main()
{
	
	Animal a;
	a.print();

	const Animal b("goat","bob","baah");
	b.print();
	//system("PAUSE");
	//getchar();
    return 0;
}
