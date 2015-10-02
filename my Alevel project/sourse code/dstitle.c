#include<graphics.h>
#include<conio.h>
#include<dos.h>

/* Appliction title display */

void titlewindow(void)
{
     int i;

     setcolor(RED);
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,5);
     outtextxy(170,130,"INTRODUCTION ");

     setcolor(CYAN);
     outtextxy(280,190,"TO");

     setcolor(GREEN);
     outtextxy(130,250,"DATA STRUCTURES");
     setcolor(WHITE);

     for(i=170;i<455;i++)
     {
	  line(i,180,i,180);
	  delay(900);
     }

     for(i=280;i<328;i++)
     {
	  line(i,240,i,240);
	  delay(900);
     }

     for(i=130;i<230;i++)
     {
	  line(i,300,i,300);
	  delay(900);
     }

     for(i=250;i<500;i++)
     {
	  line(i,300,i,300);
	  delay(900);
     }

	  delay(500);
     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
}

