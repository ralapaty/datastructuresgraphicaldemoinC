#include<graphics.h>
#include<conio.h>
#include<dos.h>

/* To display application logo in all windows */

void logo(void)
{

     setcolor(RED);
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
     outtextxy(290,140,"INTRODUCTION ");

     setcolor(CYAN);
     outtextxy(360,175,"TO");

     setcolor(GREEN);
     outtextxy(270,210,"DATA STRUCTURES");
     setcolor(WHITE);

     line(290,167,448,167);
     line(360,202,385,202);
     line(270,237,325,237);
     line(338,237,475,237);

     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
}
