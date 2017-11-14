#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<string.h>
#include<time.h>


class logger{
  fstream log.("logfile.txt", ios::out | ios::app);
  tm * initime;
  clock_t time_in;
  public :
   logger(){
      initime = localtime(&t);
      log<<"-------------------------------------------------------------\n";
      log<<asctime(initime);
      log<<"-------------------------------------------------------------\n\n";
   }
   void log_userdetails();
   void
};


void login();
void pattern();


class user {
 char name[100];
 char pass[6];
 int isadmin;
 void getpass();
 void writetofile();
public:
 user() {
  isadmin=0;
 }
 void getdata();
 char *retname();
 char *retpass();
 int admin(){ return isadmin;}
};


class point {
	int x;
	int y;
public:
	int xcoord() {
		return x;
	}
	int ycoord()
	{
		return y;
	}
	void pointget() {
		cout << "x="; cin >> x;
		cout << "y="; cin >> y;
	}
	void pointdisplay()
	{
		cout << (char)(250);
	    cout<<'('<<x<<','<<y<<')';
	}
	void set(int a, int b) {
		x = a;
		y = b;
	}
};


#endif //HEADER_H_INCLUDED
