#include"HEADERS/HEADER.h"
void main()
{
 clrscr();
 randomize();
 logger logi;
 ofstream fout("database.dat",ios::app|ios::binary);
 fout.close();
 login();
}
