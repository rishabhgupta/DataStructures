// tryCPpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int a[2][2]={{2,2},{2,2}};
	int b[2][2]={{2,2},{2,2}};
	int c[2][2]={{0,0},{0,0}};
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
		{
			c[i][j]=0;
			for(int k=0;k<2;k++)
				c[i][j]=c[i][j]+(a[i][k]+b[k][j]);
		}

	//display
	cout<<"Result:"<<endl;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
			cout<<c[i][j]<<" ";

		cout<<endl;
	}
	system("PAUSE");
	getchar();
	return 0;
}

