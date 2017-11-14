#include"HEADERS\HEADER.h"

char *user::retpass()
{
 return pass;
}
char *user::retname()
{
 return name;
}
void user::getpass()
{
 cout<<"\nEnter your password\n(MAX 6 length)";
 gets(pass);
}
void user::writetofile()
{
 ofstream fout("database",ios::binary|ios::app);
 fout.write((char *)&this,sizeof(user));
 fout.close();
}
void user::getdata()
{
 cout<<"Enter your name\n";
 gets(name);
 if(!(strcmpi(name,"NALIN"))||!(strcmpi(name,"HARSHIT")))
  isadmin=1;
 getpass();
 writetofile();
}
void loading()
{
 clrscr();
 textcolor(BLUE);
 cout<<"\t\t\t";
 for(int i=0;i<=20;i++)
 {
  delay(200);
  cprintf("%c",178);
  gotoxy(34,2);
  cprintf("%i",i*5);
  cprintf("%");
  gotoxy(24+i,1);
 }
}
void login()
{
 user temp;
 char passtemp[6],nametemp[100],ch;
 cout<<"Enter username\n"; cin.getline(nametemp,100);
 cout<<"Enter password(leave empty if a new user)(MAX length 6)\n";
 int i=0,check=0;
 while(i<6)
 {
  ch=getch();
  cout<<'*';
  if(ch=='\n')
   break;
  passtemp[i++]=ch;
 }
 passtemp[i]='\0';
 loading();
 clrscr();
 cout.write(passtemp,6);
 ifstream fin("database",ios::binary);
 while(fin.read((char *)&temp,sizeof(temp)))
 {
  if(fin.eof()) break;
  cout<<"hello";
  if(!(strcmpi(passtemp,temp.retpass()))&&!(strcmpi(nametemp,temp.retname())))
  {
   check=1;
   break;
  }
 }
 fin.close();
 if(!check)
 {
  cout<<"New user detected\n";
  temp.getdata();
 }
 else
 {
  cprintf("Welcome");
  cprintf(temp.retname());
 }
 if(temp.admin())
  cout<<"ADMIN DETECTED\n";
}
