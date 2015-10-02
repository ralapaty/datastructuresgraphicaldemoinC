#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include<process.h>
#include "prototp.h"
/* To exchange two elements in array */

int swaping(int array[10],int i,int j,int flag)
{
    int temp;

    drawbox(array,10,11);
    drawarrow(i,LIGHTBLUE);
    drawarrow(j,LIGHTGREEN);

    if(flag==1)
    {
	drawlable(i,0,"i");
	drawlable(j,0,"j");
   opmessage(200,250,' ',"Check Whether ith Element > jth Element",LIGHTBLUE);
   opmessage(200,270,' ',"If Not, Increment j. Otherwise..",LIGHTBLUE);
    }
    else
    {
 opmessage(200,250,' ',"Check Whether Jth Element > J+1th Element",LIGHTBLUE);
 opmessage(200,270,' ',"If Not, Increment j. Otherwise..",LIGHTBLUE);
	drawlable(i,0,"j");
	drawlable(j,0,"j+1");
    }

    sleep(1);

    if(array[i]>array[j])
    {
	opmessage(200,250,' ',"Check Whether ith Element > jth Element",BLACK);
	opmessage(200,270,' ',"If Not, Increment j. Otherwise..",BLACK);
	opmessage(200,250,' ',"Check Whether Jth Element > J+1th Element",BLACK);
	opmessage(200,270,' ',"If Not, Increment j. Otherwise..",BLACK);
	opmessage(200,250,' ',"Swap Both Elements",LIGHTBLUE);
	delay(200);

	setcolor(CYAN);
	line(220+i*40,168,220+j*40,168);
	line(220+i*40,170,220+j*40,170);
	setcolor(BROWN);
	outtextxy(225+i*40,159,"SWAP");
	sleep(1);
	temp=array[i];
	array[i]=array[j];
	array[j]=temp;
	flag=1;
	opmessage(200,250,' ',"Swap Both Elements",BLACK);
    }
    return flag;
}
/* leniar sorting propram */

void lenearsort(void)
{
     int array[10];
     int temp,i,j;
     char s[30];

		    setcolor(YELLOW);
		    settextstyle(8,0,1);
		    outtextxy(340,70,"LINEAR SORT ");
		    settextstyle(0,0,1);

     for(i=0;i<10;i++)
     array[i]=0;

		    drawbox(array,0,11);

     for( i=0;i<10;i++)
     {
		    array[i]=getdata(250,300,2,"ENTER A NUMBER (2 digits):");
		    drawbox(array,i+1,11);
     }

	opmessage( 200,220,' ',"Set i=0,j=i+1",MAGENTA);
	delay(1000);
	opmessage( 200,220,' ',"Set i=0,j=i+1",BLACK);

   for(i=0;i<10;i++)
   {
    opmessage( 200,220,' ',"If j Is Max Size, Increment i,Set j=i+1",BLACK);
    for(j=i+1;j<10;j++)
    swaping(array,i,j,1);
    opmessage( 200,220,' ',"If j Is Max Size, Increment i,Set j=i+1",MAGENTA);
    sleep(1);
   }

     drawbox(array,10,11);
     opmessage( 200,220,' ',"If j Is Max Size, Increment i,Set j=i+1",BLACK);
     getdata(250,300,0,"         SORTING COMPLETED");
}

/* bubble sorting program */

void bubblesort(void)
{
     int array[10];
     int temp,i,j;
     char s[30];

		    setcolor(YELLOW);
		    settextstyle(8,0,1);
		    outtextxy(320,70,"BUBBLE SORT ");
		    settextstyle(0,0,1);

     for(i=0;i<10;i++)
     array[i]=0;

		    drawbox(array,0,11);

     for(i=0;i<10;i++)
     {
	  array[i]=getdata(250,300,2,"ENTER A NUMBER (2 digits):");
	  drawbox(array,i+1,11);
     }

     for(i=0;i<10;i++)
     {
	  temp=0;
	  opmessage( 200,250,' ',"Set j To Initial Position,j=0",MAGENTA);
	  sleep(1);
	  opmessage( 200,250,' ',"Set j To Initial Position,j=0",BLACK);

	  for(j=0;j<9-i;j++)
	  {
		temp=swaping(array,j,j+1,temp);
	  }

		  if(temp==0)
		  break;
     }

	    drawbox(array,10,11);
	    getdata(250,300,0,"         SORTING COMPLETED");
}

/* insertion sorting program */

void insertionsort(void)
{
     int array[10];
     int temp,i=0,k=0,num;
     char s[30];

		    setcolor(YELLOW);
		    settextstyle(8,0,1);
		    outtextxy(320,70,"INSERTION SORT");
		    settextstyle(0,0,1);

     for(i=0;i<10;i++)
     array[i]=0;
     i=-1;

		    drawbox(array,0,11);
		    i=0;

     for(k=1;k<=10;k++)
     {
	   num=getdata(250,300,2,"ENTER A NUMBER (2 digits):");

	   drawbox(array,k-1,11);
	   drawarrow(i,LIGHTBLUE);
	   delay(1000);

	   while(array[i-1]>num&&i>0)
	   {
opmessage( 200,250,' ',"Shift Desired Elements One Position Right",LIGHTBLUE);
		   drawbox(array,k,11);
		   setfillstyle(SOLID_FILL,BLACK);
		   bar(203+i*40,125,225+i*40,140);
		   drawarrow(i-1,LIGHTBLUE);
		   sleep(1);
		   array[i]=array[i-1];
		   i--;
		   drawbox(array,k,11);
		   setfillstyle(SOLID_FILL,BLACK);
		   bar(203+i*40,125,225+i*40,140);
		   drawarrow(i+1,LIGHTBLUE);
		   sleep(1);
    opmessage( 200,250,' ',"Shift Desired Elements One Position Right",BLACK);
	   }

		    array[i]=num;
		    drawbox(array,k,11);
		    drawarrow(i,LIGHTBLUE);
		    sleep(1);
		    drawbox(array,k,11);
		    i=k;
     }

	getdata(250,300,0,"         LIST IS FULL");
}
