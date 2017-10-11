#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

//#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

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
}
#endif //HEADER_H_INCLUDED