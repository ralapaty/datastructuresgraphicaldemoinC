#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include<process.h>
#include"prototp.h"

/* To draw title bar and status bar */

void titlebar(char *s,int bcolor,int color)
{
     int l,x;

     setfillstyle(SOLID_FILL,bcolor);
     bar(0,0,getmaxx(),20);
     setcolor(WHITE);
     line(0,0,getmaxx(),0);
     line(0,0,0,20);

     for(l=0;s[l]!=0;l++);

     x=320-((l/2)*8);
     setcolor(color);
     outtextxy(x,10,s);
     bar(0,463,640,480);
     setcolor(WHITE);
     line(0,463,getmaxx(),463);
     line(0,463,0,480);

}

/* To display menu in window */

void drawmenu(char array[10][20],int num,char *s,int i,int p[10],int mode,int color)
{
     int x1,y1,x2,y2,len,z;

     x1=5;y1=23;
     x2=130;y2=460;

     setbkcolor(BLACK);
     setcolor(WHITE);
     setfillstyle(SOLID_FILL,LIGHTGRAY);
     setlinestyle(SOLID_LINE,1,2);
     bar(x1,y1,x2,y2);
     line(x1,y1,x2,y1);
     line(x1,y1,x1,y2);

     setcolor(RED);
     setlinestyle(SOLID_LINE,1,2);
     line(x1+5,y1+5,x1+5,y2-5);
     line(x1+5,y1+5,x2-5,y1+5);
     line(x1+5,y2-5,x2-5,y2-5);
     line(x2-5,y1+5,x2-5,y2-5);

     len=strlen(array[num]);
     outtextxy(x1=(x1+x2)/2-len*4,35,array[num]);

     line(x1,44,x1+len*8,44);

     x1=16;y1=60;

     /* mode==0 for active state of menu
	  mode!=0 for disable state of menu */

     if(mode==0)
     {
	  /* To hilight menu choice */

	  setfillstyle(SOLID_FILL,color);
	  bar(15,6+(i+1)*25,122,20+(i+1)*25);

	  setcolor(BLUE);
     }
     else
     {
	  setcolor(BLACK);
     }

     for(z=0;z<num;z++)
     {
	  if(i!=z+1)
	  {
	     outtextxy(x1,y1,array[z]);
	     line(x1+p[z]*8,y1+9,x1+p[z]*8+6,y1+9);
	  }
	  else
	  {
		if(mode==0)
		setcolor(WHITE);

		outtextxy(x1,y1,array[z]);
		line(x1+p[z]*8,y1+9,x1+p[z]*8+6,y1+9);

		if(mode==0)
		setcolor(BLUE);
	  }

	  y1+=25;
     }

     for(x1=0;s[x1]!=0;x1++);

}

/* TO get user choice from menu */

int mkey(int num,char *s,char array[10][20],int p[10],char message[10][70],int color)
{
    int i=1,n=0,j;

    while(1)
    {
	   drawmenu(array,num,s,i,p,0,color);
	   setfillstyle(SOLID_FILL,color);
	   bar(0,463,640,480);
	   setcolor(WHITE);
	   line(0,463,getmaxx(),463);
	   line(0,463,0,480);
	   setcolor(BLACK);

	   outtextxy(60,470,message[i-1]);

	   while((n=bioskey(0))==0);

	   if(n==20480)
		i++;

	   if(n==18432)
		i--;


	   if(i==0)
		i=num;

	   if(i==num+1)
		i=1;

	   if(n==7181)
		return i;

	   for(j=0;j<num;j++)
	   {
		 if(s[j]==tolower((char)n))
		 {
			setfillstyle(SOLID_FILL,color);
			bar(60,470,600,480);
			outtextxy(60,470,message[j]);
			return j+1;
		 }
	   }


    }
}

/* To print pointer lables in searching and sorting */

void drawlable(int pos,int p,char *s)
{
     int x=210+pos*40,y=180;

     if(p==1)
     {
	  x=200+pos*40;
	  y=172;
     }

     if(p==2)
     {
	  x=230+pos*40;
	  y=172;
     }

     setcolor(WHITE);
     outtextxy(x,y,s);
}

/* To draw horizontal array */

void drawbox(int array[],int k,int j)
{
	int x,i;
	char ch[3];

	setfillstyle(SOLID_FILL,BLACK);
	bar(180,100,610,210);

	setcolor(WHITE);
	line(200,120,600,120);
	line(200,145,600,145);

	for(x=200,i=0;x<=600;x+=40,i++)
			line(x,120,x,145);


	setcolor(YELLOW);
	for(x=205,i=0;i<k;i++,x+=40)
	{
		sprintf(ch,"%d",array[i]);
		if(i==j)
		{
		   setcolor(RED);
		   outtextxy(x+5,130,ch);
		   setcolor(YELLOW);
		}
		else
		   outtextxy(x+5,130,ch);
	}
}


/* To draw  location pointer for searching,sorting */

void drawarrow(int pos,int color)
{
	int x=220+pos*40;

	    setcolor(color);
	    line(x,146,x+5,150);
	    line(x,146,x-5,150);
	    line(x,148,x+5,153);
	    line(x,148,x-5,153);
	    line(x-1,151,x-1,170);
	    line(x+1,151,x+1,170);
}

/* To get numeric data from user and send messages for user */

int getdata(int x,int y,int j,char *s)
{
    int i=0,n=0;
    char ch=0;
    char str[7]={""};

   /* j is maximam number of digits for input */

    while(1)
    {
	   setfillstyle(SOLID_FILL,CYAN);
	   bar(x-10,y-20,x+300,y+20);

	   if(j!=0)
	   {
		setfillstyle(SOLID_FILL,DARKGRAY);
		bar(x+208,y-2,x+208+j*9,y+10);
	   }

	   setcolor(YELLOW);
	   line(x-10,y-20,x-10,y+20);
	   line(x-10,y-20,x+300,y-20);
	   line(x-10,y+20,x+300,y+20);
	   line(x+300,y-20,x+300,y+20);

	   setcolor(BLACK);
	   outtextxy(x,y,s);
	   setcolor(YELLOW);

	   if(i==0&&j!=0)
		outtextxy(x+210,y,"0");
	   else
		outtextxy(x+210,y,str);

	   fflush(stdin);
	   ch=getch();

	   if(ch==8&&i>=0)
	   {
		if(i==0)
		  str[0]=0;
		else
		  str[--i]=0;
	   }

	   if(ch>='0'&&ch<='9'&&i<j)
	   {
		   str[i]=ch;
		   str[++i]=0;
	   }



	   if(ch=='\r')
	   break;


    }

    str[i]=0;

    setfillstyle(SOLID_FILL,BLACK);
    bar(x-10,y-20,x+300,y+20);

    for(i=0;str[i]!=0;i++)
	n=n*10+str[i]-48;

    return n;

}

/* To find length of given string */

int strlen(char s[])
{
    int i;
    for(i=0;s[i]!=0;i++);
    return i;
}

/* To convert capital letter to lower letter  */

int tolower(int ch)
{
    if(ch>='A'&&ch<='Z')
	ch+=32;

    return ch;
}

/* To confirm to quit form application */

int quit(void )
{
    char ch[2];
    int x=200,y=200;

    ch[1]=0;

    setfillstyle(SOLID_FILL,CYAN);
    bar(x-10,y-20,x+300,y+20);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(x+208,y-2,x+208+9,y+10);

    setcolor(YELLOW);
    line(x-10,y-20,x-10,y+20);
    line(x-10,y-20,x+300,y-20);
    line(x-10,y+20,x+300,y+20);
    line(x+300,y-20,x+300,y+20);

    setcolor(BLACK);
    outtextxy(x,y,"CONFIRM EXIT TO DOS (Y/N)");
    setcolor(YELLOW);
    outtextxy(x+210,y,"N" );
    fflush(stdin);
    ch[0]=getch();
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(x+208,y-2,x+208+9,y+10);

    if(ch[0]=='\r')
	 ch[0]='N';

    outtextxy(x+210,y,ch);
    delay(100);
    setfillstyle(SOLID_FILL,BLACK);
    bar(x-10,y-20,x+300,y+20);

    if(ch[0]=='y'||ch[0]=='Y')


    return 1;

	   return 0;
}