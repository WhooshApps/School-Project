#include"HEADERS/HEADER.h"

// lxb = 80x24




inline void algorithm1(point &currpt, point* cornerpt,int t) {
 int j = random(t);
 int x, y;
 x = currpt.xcoord() + cornerpt[j].xcoord();
 y = currpt.ycoord() + cornerpt[j].ycoord();
 x/=2; y/=2;

 currpt.set(x,y);

 gotoxy(x,y);
 cprintf("%c",250);
}

int save=0;

void algorithm2(point &currpt, point* cornerpt,int t) {
 int j;
 a:
 j = random(t);
 if(save==j)
  goto a;
 int x, y;
 x = currpt.xcoord() + cornerpt[j].xcoord();
 y = currpt.ycoord() + cornerpt[j].ycoord();
 x/=2; y/=2;

 currpt.set(x,y);

 gotoxy(x,y);
 cprintf("%c",250);
 save=j;
}


void pattern() {
 int T,i;
 point * cornerpoints= new point[T];
 point startingpoint;
 startingpoint.set(40,12);
 clrscr();
 cout<<"Enter the no. of corner points(3-6)\n";
 cin>>T;

 switch(T) {
  case 3: cornerpoints[0].set(40,1);
	  cornerpoints[1].set(1,24);
	  cornerpoints[2].set(80,24);
	  break;
  case 4: cornerpoints[0].set(1,1);
  cornerpoints[1].set(80,1);
  cornerpoints[2].set(1,24);
  cornerpoints[3].set(80,24);
	 break;
  case 5: cornerpoints[0].set(40,1);
  cornerpoints[1].set(1,12);
  cornerpoints[2].set(20,24);
  cornerpoints[3].set(60,24);
  cornerpoints[4].set(80,12);
	  break;
  case 6: cornerpoints[0].set(40,1);
  cornerpoints[1].set(1,8);
  cornerpoints[2].set(1,16);
  cornerpoints[3].set(80,8);
  cornerpoints[4].set(80,16);
  cornerpoints[5].set(40,24);
	  break;
    default: cout<<"Wrong choice\n";
 }
 clrscr();
 for(i=0;i<T;i++) {
  gotoxy(cornerpoints[i].xcoord(),cornerpoints[i].ycoord());
  cornerpoints[i].pointdisplay();
 }
 gotoxy(startingpoint.xcoord(),startingpoint.ycoord());
 startingpoint.pointdisplay();
 getch();
 clrscr();
 textcolor(LIGHTGREEN+BLINK);
 switch(T) {
  case 3: for(i=0; i<5000; i++)
	     algorithm1(startingpoint, cornerpoints, T);
	  break;
  case 4: for(i=0; i<5000; i++)
	     algorithm2(startingpoint, cornerpoints, T);
	  break;
  case 5: for(i=0; i<5000; i++)
	     algorithm2(startingpoint, cornerpoints, T);
	  break;
 }
 getch();
}
