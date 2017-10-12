#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream.h>

class user
{
 char *name;
 char *pass;
 int k;
 void getpass();
 void writetofile();
public:
 user()
 {
  name=pass=NULL;
 }
 void getdata();
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