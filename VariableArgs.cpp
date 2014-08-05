// cppTry.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>  
#include <stdarg.h>

using namespace std;

double avg(const int count, ...)
{
	va_list ap;
	int i;
	double total=0.0;
	va_start(ap,count);
	for(i=0;i<count;i++){
		total+=va_arg(ap, double);
	}
	va_end(ap);
	return total/count;
}
int main()
{

	double av=avg(6,25.0,35.7,50.1,127.6,75.0,80.0);
	cout<<av;
	system("PAUSE");
	getchar();
    return 0;
}
