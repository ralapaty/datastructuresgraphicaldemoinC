#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include "prototp.h"

/* to draw diagram of stack */

void drawstack(int x,int y,int size,int color)
{
     int i;

		setfillstyle(SOLID_FILL,BLACK);
		bar(x,y,x+100,y+(size+1)*20);
		setcolor(color);
		line(x,y,x,y+size*20);
		line(x+30,y,x+30,y+size*20);

     for(i=0;i<=size;i++)
		line(x,y+i*20,x+30,y+i*20);
}

/* To draw stack top pointer */

void drawpointer(int x,int y,int size,int top,int color)
{
     setcolor(color);

     if(top!=-1)
	 {
	    line(x+30,y+(size-top)*20-10,x+35,y+(size-top)*20-15);
	    line(x+30,y+(size-top)*20-10,x+35,y+(size-top)*20-5);
	    line(x+30,y+(size-top)*20-10,x+55,y+(size-top)*20-10);
	    setcolor(LIGHTCYAN);
	    outtextxy(x+60,y+(size-top)*20-15,"TOP");
	 }
	 else
	 {
	    line(x+30,y+size*20,x+35,y+size*20-5);
	    line(x+30,y+size*20,x+35,y+size*20+5);
	    line(x+30,y+size*20,x+55,y+size*20);
	    setcolor(LIGHTCYAN);
	    outtextxy(x+60,y+size*20-5,"TOP");
	 }
}

/* to display the stack */

void stackdisplay(int x,int y,int size,stack *s,int pre)
{
     int i;
     char ch[3];

     setcolor(YELLOW);

     drawstack(x,y,size,MAGENTA);
     drawpointer(x,y,size,s->top,GREEN);

     for(i=0;i<=s->top;i++)
     {
	  if(pre==0)
	    sprintf(ch,"%c",s->array[i]);
	  else
	    sprintf(ch,"%d",s->array[i]);

	  outtextxy(x+8,y+(size-i)*20-10,ch);
     }
}

/* push a element into the stack
   pre=0 for charectar type stack
   pre=1 for integer type stack */


void push(int x,int y,int size,stack *s,int pre,char c)
{
     int x1,y1,num,t=s->top;
     char ch[3];

	   if(full(size,s->top))
	     {
		     getdata(160,350,0,"          STACK IS FULL");
			return;
	     }

	   if(pre==0)
		sprintf(ch,"%c",c);
	   else
	   {
		if(pre==1)
		{
			num=getdata(160,350,2,"ENTER A ELEMENT(2 DIGITS)");
  opmessage(160,425,' ',"Push Element In To Stack And Increment TOP",CYAN);
		}

			if(pre==2)
			    num=c;

			sprintf(ch,"%d",num);
	   }


	for( x1=x-80;x1<=x+5;x1++)
	{
		setcolor(YELLOW);
		outtextxy(x1,y-20,ch);
		delay(200);
		setcolor(BLACK);
		outtextxy(x1,y-20,ch);
	}


	for( y1=y-20;y1<=y+(size-t-2)*20;y1++)
	{
		setcolor(YELLOW);
		outtextxy(x+5,y1,ch);
		delay(200);
		stackdisplay(x,y,size,s,pre);
		setcolor(BLACK);
		outtextxy(x+5,y1,ch);
	}

	if(pre==0)
	  s->array[s->top+1]=c;
	else
	  s->array[s->top+1]=num;

	s->top++;
  opmessage(160,425,' ',"Push Element In To Stack And Increment TOP",BLACK);
	stackdisplay(x,y,size,s,pre);
}

/* if mode = 0 pop one element form stack
   if mode = 1 get copy of top element from stack
   if pre =0 character stack
   if pre=1 numaric stack */


int pop(int x,int y,int size,stack *s,int mode,int pre)
{
    int x1,y1,num,t=s->top;
    char ch[3];

    if(empty(s->top))
    {
	   getdata(160,350,0,"         STACK IS EMPTY");
	   return 0;
    }

    num=s->array[s->top];

    if(mode==0)
    {
	   s->top--;
	   if(pre!=0&&pre!=3)
     opmessage(160,420,' ',"Pop Element From Stack And Decrement TOP",CYAN);
    }

    if(mode!=0&&pre!=3)
	 opmessage(160,350,' ',"Pop Copy Of Top Element From Stack ",CYAN);

    if(pre==0)
	   sprintf(ch,"%c",num);
    else
	   sprintf(ch,"%d",num);

    t=s->top;

    for( y1=y+(size-t-2)*20;y1>=y-20;y1--)
    {
		setcolor(YELLOW);
		outtextxy(x+5,y1,ch);
		delay(200);
		stackdisplay(x,y,size,s,pre);
		setcolor(BLACK);
		outtextxy(x+5,y1,ch);
    }

    for( x1=x+5;x1>=x-80;x1--)
    {
		setcolor(YELLOW);
		outtextxy(x1,y-20,ch);
		delay(200);
		setcolor(BLACK);
		outtextxy(x1,y-20,ch);
    }

 opmessage(160,420,' ',"Pop Element From Stack And Decrement TOP",BLACK);
 opmessage(160,350,' ',"Pop Copy Of Top Element From Stack ",BLACK);

return num;
}

/* if stack is full it will return 1.
   if stack is not full it will return 0. */

int full(int size,int top)
{
    if(top==size-1)
    return 1;
    return 0;
}

/* if stack is empty it will return 1.
   if stack is not empty it will return 0. */

int empty(int top)
{
    if(top==-1)
    return 1;
    return 0;
}

