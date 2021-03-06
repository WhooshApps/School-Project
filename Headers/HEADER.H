#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

class user;
class point;
class logger;
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

time_t t = time(0) ;
fstream log("logfile.txt", ios::out | ios::app);
class logger{
  tm * initime;
  clock_t time_in;
  public :
   logger(){
      initime = localtime(&t);
      log<<"-------------------------------------------------------------\n";
      log<<asctime(initime);
      log<<"-------------------------------------------------------------\n\n";
   }
   void log_olduser(user B, tm* A);
   void log_newuser(user B, tm* A);
   void log_admin(user B, tm* A);
}logi;

inline void log_olduser(user use, tm * logintime){
log<<"\n`"<<use.retname()<<"` logged in at "<<asctime(logintime);
}

inline void log_newuser(user use, tm * logintime){
 log<<"\nNew user `"<<use.retname()<<"` created and added to database at "<<asctime(logintime);
}

inline void log_admin(user use, tm * logintime){
  log<<"\nBow before thy admin Sir "<<use.retname()<<" as he controls thy program, beginning at "<<asctime(logintime);
}

void login();
void pattern();


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
		cprintf("%c",250);
	}
	void set(int a, int b) {
		x = a;
		y = b;
	}
};


#endif //HEADER_H_INCLUDED
