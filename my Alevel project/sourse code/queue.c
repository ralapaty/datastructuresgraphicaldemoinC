#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include "prototp.h"

/* To draw queue pointers */

void drawqpoint(int x,int y,int size,int pos,int color,int mode)
{
     int x1=x+15+30*(size-pos-1);

     if(pos==-1)
		x1-=15;

     setcolor(color);
     line(x1,y+20,x1,y+40);
     line(x1,y+20,x1-4,y+24);
     line(x1,y+20,x1+4,y+24);
     setcolor(BROWN);

     if(mode==0)
		outtextxy(x1-32,y+35,"REAR");
     else
		outtextxy(x1+2,y+35,"FRONT");
}


/* To draw queue figure */

void drawq(int x,int y,int size)
{
     int x1;
     setfillstyle(SOLID_FILL,BLACK);
     bar(x-30,y,x+size*30+40,y+45);

     setcolor(LIGHTGRAY);
     line(x,y,x+size*30,y);
     line(x,y+20,x+size*30,y+20);

     for( x1=x;x1<=x+size*30;x1+=30)
		line(x1,200,x1,220);
}

/* To display queue */

void displayq(int x,int y,int size,q *s)
{
     int r=s->rear,f=s->front;
     char ch[3];

     if(f==-1)
	    f=0;

     setcolor(YELLOW);

     for(;f<=r;f++)
     {
		sprintf(ch,"%d",s->array[f]);
		outtextxy(x+(size-f-1)*30+5,y+7,ch);
     }
}

/* To insert a element into queue */

void insertq(int x,int y,int size,q *s)
{
    int num,x1,y1;
    int r=s->rear;
    char ch[3];

    if(s->rear==size-1)
    {
	 getdata(300,300,0,"        QUEUE IS FULL");
	 return;
    }

    num=getdata(300,300,2,"ENTER A ELEMENT(2 DIGITS):" );
opmessage(200,350,' ',"Insert Element Into Q And Increment Rear Pointer",MAGENTA);
    s->array[s->rear+1]=num;
    sprintf(ch,"%d",num);

    for(x1=x-20,y1=y+60;y1>=y+7;y1--)
    {
	     setcolor(YELLOW);
	     outtextxy(x1,y1,ch);
	     delay(200);
	     setcolor(BLACK);
	     outtextxy(x1,y1,ch);
    }

    for(x1=x-20;x1<=(x+(size-r-2)*30+5);x1++)
    {
	     setcolor(YELLOW);
	     outtextxy(x1,y1,ch);
	     delay(200);
	     drawq(x,y,size);
	     displayq(x,y,size,s);
	     drawqpoint(x,y,size,s->rear,2,0);
	     drawqpoint(x,y,size,s->front,2,1);

	     setcolor(BLACK);
	     outtextxy(x1,y1,ch);
    }

	     s->rear++;
    if(s->front==-1)
    {
		opmessage(200,360,' ',"And Increment Front Pointer",MAGENTA);
		s->front=0;
    }
opmessage(200,350,' ',"Insert Element Into Q And Increment Rear Pointer",BLACK);
opmessage(200,360,' ',"And Increment Front Pointer",BLACK);
    drawq(x,y,size);
    displayq(x,y,size,s);
    drawqpoint(x,y,size,s->rear,2,0);
    drawqpoint(x,y,size,s->front,2,1);

}

/* To delete a element form queue */

void deleteq(int x,int y,int size,q *s)
{
     int num,x1,y1;
     int f=s->front;

     char ch[3];
     if(s->rear==-1)
     {
	    getdata(300,300,0,"       QUEUE IS EMPTY");
	    return;
     }

opmessage(200,350,' ',"Delete Element From Q  And Increment Front Pointer",MAGENTA);
     num=s->array[s->front];
     s->front++;

     if(s->front>s->rear)
     {
opmessage(200,400,' ',"If Front Pointer > Rear Pointer,Set Front=Rear=-1 ",MAGENTA);
		s->front=s->rear=-1;
     }

     sprintf(ch,"%d",num);

     for(x1=(x+(size-f-1)*30+5);x1<=x+size*30+20;x1++)
     {

		setcolor(YELLOW);
		outtextxy(x1,y+7,ch);
		delay(200);


		drawq(x,y,size);
		displayq(x,y,size,s);
		drawqpoint(x,y,size,s->rear,2,0);
		drawqpoint(x,y,size,s->front,2,1);

	     setcolor(BLACK);
		outtextxy(x1,y+7,ch);
     }

     for(x1=x+size*30+20,y1=y+7;y1<=y+60;y1++)
     {
			setcolor(YELLOW);
			outtextxy(x1,y1,ch);
			delay(200);
			setcolor(BLACK);
			outtextxy(x1,y1,ch);
     }
opmessage(200,350,' ',"Delete Element From Q  And Increment Front Pointer",BLACK);
opmessage(200,400,' ',"If Front Pointer > Rear Pointer,Set Front=Rear=-1 ",BLACK);

     drawq(x,y,size);
     displayq(x,y,size,s);
     drawqpoint(x,y,size,s->rear,2,0);
     drawqpoint(x,y,size,s->front,2,1);

}
