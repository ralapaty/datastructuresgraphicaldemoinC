#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

void buybuy()
{
     char name[25],pname[25]=" Vanam";
     int i;

     cleardevice();
     setcolor(6);
     settextstyle(1,0,1);
  outtextxy(100,100,"Thanks For  Using This Software !.");
  outtextxy(100,130,"If Any Suggestions Or Defects Regarding This Software.");
  outtextxy(100,160,"Please Send Mail to <Vanamkumar@yahoo.com>.");

     settextstyle(5,0,1);
     setcolor(DARKGRAY);
     circle(60,100,22);
     setfillstyle(1,YELLOW);
     floodfill(60,100,DARKGRAY);
     setcolor(LIGHTBLUE);
     outtextxy(45,96,"Sunny");
     setcolor(9);

     for(i=0;pname[i]!=0;i++)
     {
	   name[i]=pname[i];
	   name[i+1]=0;
	   outtextxy(420,250,name);
	   delay(2000);
     }

     setcolor(LIGHTGRAY);
     setfillstyle(1,LIGHTGRAY);
     fillellipse(50,96,6,2);
     fillellipse(70,96,6,2);

     setcolor(BLACK);
     circle(50,96,1);
     circle(70,96,1);
     setcolor(BLACK);
     arc(60,100,205,335,15);
     line(45,108,48,106);
     line(75,108,72,106);
     sleep(1);
     setfillstyle(1,0);
     fillellipse(70,96,6,2);
     sleep(1);

     setfillstyle(1,LIGHTGRAY);
     fillellipse(70,96,6,2);
     circle(70,96,1);
     sleep(1);
     setcolor(BLUE);
     circle(60,100,22);

     setfillstyle(1,BLACK);
     floodfill(60,100,BLUE);
     setcolor(DARKGRAY);
     circle(60,100,22);
     setfillstyle(1,YELLOW);
     floodfill(60,100,DARKGRAY);
     setcolor(LIGHTBLUE);
     outtextxy(45,96,"Sunny");

     getch();
     closegraph();
     return ;
}
