#include"HEADERS/HEADER.h"
void main()
{
 clrscr();
 randomize();
 ofstream fout("database.dat",ios::app|ios::binary);
 fout.close();
 login();
}