#include"HEADERS\HEADER.h"


void hash(char * temp,int k) {
 int i=0;
 while(temp[i]!='\0')
 {
  temp[i]=temp[i++]+k;
 }
}
char *user::retpass()
{
 return pass;
}
char *user::retname()
{
 return name;
}
int user::retk()
{
 return k;
}
void user::getpass()
{
 cout<<"\nEnter your password\n";
 gets(pass);
 k=random(random(100)+random(100));
 hash(pass,k);
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
 getpass();
 writetofile();
}
void loading()
{
 cout<<"\t\t\t";
 for(int i=0;i<20;i++)
 {
  delay(200);
  cout<<(char)(178);
  gotoxy(34,2);
  cout<<i*5<<'%';
  gotoxy(24+i,1);
 }
}
void login()
{
 user temp;
 char *passtemp,*nametemp,ch;
 cout<<"Enter username\n"; gets(nametemp);
 cout<<"Enter password(leave empty if a new user)\n";
 loading();
 int i=0,check=0;
 while(1)
 {
  cin>>ch;
  if(ch=='\n')
   break;
  passtemp[i++]=ch;
 }
 passtemp[i]='\0';
 ifstream fin("database",ios::binary);
 while(1)
 {
  if(fin.eof()) break;
  fin.read((char *)&temp,sizeof(temp));
  hash(passtemp,temp.retk());
  if(!strcmpi(passtemp,temp.retpass())&&!strcmpi(nametemp,temp.retname()))
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
}