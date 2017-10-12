#include"HEADERS\HEADER.h"


void hash(char * temp,int k) {
 int i=0;
 while(temp[i]!='\0')
 {
  temp[i]=temp[i++]+k;
 }
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
 ofstream fout("database",ios::binary);
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