#include <iostream>
#include <cmath>
//#include <ncurses.h>
#include <cstdlib>

using namespace std;


int main()
{
	// current date/time based on current system
   time_t now = time(0);

   //cout << "Number of sec since January 1,1970:" << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   //cout << "Year: "<< ltm->tm_year << endl;
   //cout << "Month: "<<ltm->tm_mon<< endl;
   //cout << "Day: "<<  ltm->tm_mday << endl;
   //cout << "Time: "<<ltm->tm_hour << ":";
   //cout <<ltm->tm_min << ":";
   //cout <<ltm->tm_sec << endl;
   if(ltm->tm_hour<12)
   {
   		cout<<"root: Good Morning Rishabh";
   }
   else if(ltm->tm_hour==12)
   {
   		cout<<"root: Good Noon Rishabh";
   }
   else if(ltm->tm_hour>12 && ltm->tm_hour<7)
   {
   		cout<<"root: Good Evening Rishabh";
   }
   else
   {
   		cout<<"root: Good Night Rishabh";
   }
   cout<<endl;
	//getchar();
	return 0;
}