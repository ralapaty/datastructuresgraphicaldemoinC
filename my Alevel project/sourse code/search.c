
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include<process.h>
#include "prototp.h"


/* leniar search program */

void linearsearch(void)
{
     int array[10],key,i;
     char s[50];

		 setcolor(MAGENTA);
		 settextstyle(8,0,1);
		 outtextxy(320,70,"LINEAR SEARCH");
		 settextstyle(0,0,1);

		 for(i=0;i<10;i++)
			array[i]=0;

		 drawbox(array,0,11);

	for( i=0;i<10;i++)
	{
	   array[i]=getdata(250,300,2,"ENTER A NUMBER (2 digits):");
	   drawbox(array,i+1,11);
	}

		key=getdata(250,250,2,"ENTER A NUMBER TO SEARCH:");

	sprintf(s,"Search Key %d",key);
	opmessage(200,250,' ',s,MAGENTA);
	opmessage(200,300,' ',"Check Sequentially List Until Search key Found Or",LIGHTBLUE);
	opmessage(200,315,' ',"Checking All Elements Over",LIGHTBLUE);

	for(i=0;i<10;i++)
	{
	     if(array[i]==key)
	     {
			drawbox(array,10,i);
			drawarrow(i,GREEN);
			break;
	     }

						 drawbox(array,10,11);
						 drawarrow(i,GREEN);
						 sleep(1);
	}

	opmessage(200,300,' ',"Check Sequentially List Until Search key Found Or",BLACK);
	opmessage(200,310,' ',"Checking All Elements Over",BLACK);

		if(i>=10)
		{
			drawbox(array,10,11);
			sprintf(s,"         %d NOT FOUND",key);
			getdata(250,200,0,s);
		}
		else
		{
			sprintf(s,"      %d FOUND AT LOCATION %d",key,i+1);
			getdata(250,200,0,s);
		}


}

/* binary search program */

void binarysearch(void)
{
     int array[10];
     int key,i,j,low=0,mid,up=9;
     char s[50];

		    setcolor(LIGHTCYAN);
		    settextstyle(8,0,1);
		    outtextxy(320,70,"BINARY SEARCH");
		    settextstyle(0,0,1);

	for(i=0;i<10;i++)
	   array[i]=0;

				drawbox(array,0,11);

	for( i=0;i<10;i++)
	{
	   array[i]=getdata(250,300,2,"ENTER A NUMBER (2 digits):");
	   drawbox(array,i+1,11);
	}


		 for(i=0;i<10;i++)
			for(j=i+1;j<10;j++)
				if(array[i]>array[j])
				{
					key=array[i];
					array[i]=array[j];
					array[j]=key;
				}


		drawbox(array,10,11);
		key=getdata(250,250,2,"ENTER A NUMBER TO SEARCH:");

		sprintf(s,"Search Key %d",key);
		opmessage(200,250,' ',s,MAGENTA);

	while(low<=up)
	{

		drawbox(array,10,11);

		drawarrow(low,LIGHTBLUE);
		drawarrow(up,LIGHTGREEN);

		drawlable(low,1,"Low");
		drawlable(up,2,"Up");

		opmessage(200,300,' ',"Calculate Mid=(Low+Up)/2" ,LIGHTBLUE);
		sleep(1);
					mid= (low+up)/2;
					drawarrow(mid,WHITE);

					drawlable(low,1,"Low");
					drawlable(up,2,"Up");
					drawlable(mid,0,"Mid");

					sleep(1);


		if(array[mid]==key)
		{
		   opmessage(200,300,' ',"Calculate Mid=(Low+Up)/2" ,BLACK);
		   drawbox(array,10,mid);

		   drawarrow(low,LIGHTBLUE);
		   drawarrow(up,LIGHTGREEN);
		   drawarrow(mid,RED);

		   drawlable(low,1,"Low");
		   drawlable(up,2,"Up");
		   drawlable(mid,0,"Mid");

		   sprintf(s,"         %d FOUND AT LOCATION %d",key,mid+1);
		   getdata(250,250,0,s);
		   break;
		}


		if(key<array[mid])
		{
		   opmessage(200,300,' ',"Calculate Mid=(Low+Up)/2" ,BLACK);
		   opmessage(200,300,' ',"If Search Key < Mid Element" ,LIGHTBLUE);
		   opmessage(200,320,' ',"Shift Up to Mid-1 Position" ,LIGHTBLUE);
			for(;up>mid-1;up--)
			{
			    drawbox(array,10,11);
			    drawarrow(up,LIGHTGREEN);
			    drawarrow(low,LIGHTBLUE);
			    drawarrow(mid,WHITE);

			    drawlable(low,1,"Low");
			    drawlable(up,2,"Up");
			    drawlable(mid,0,"Mid");

			    sleep(1);
			}
		   opmessage(200,300,' ',"If Search Key < Mid Element" ,BLACK);
		   opmessage(200,320,' ',"Shift Up to Mid-1 Position" ,BLACK);
		}
		else
		{
		   opmessage(200,300,' ',"Calculate Mid=(Low+Up)/2" ,BLACK);
		   opmessage(200,300,' ',"If Search Key > Mid Element" ,LIGHTBLUE);
		   opmessage(200,320,' ',"Shift Low to Mid+1 Position" ,LIGHTBLUE);

		   for(;low<mid+1;low++)
			 {
			   drawbox(array,10,11);
			   drawarrow(low,LIGHTBLUE);
			   drawarrow(up,LIGHTGREEN);
			   drawarrow(mid,WHITE);

			   drawlable(low,1,"Low");
			   drawlable(up,2,"Up");
			   drawlable(mid,0,"Mid");

			   sleep(1);
			 }

		   opmessage(200,300,' ',"If Search Key > Mid Element" ,BLACK);
		   opmessage(200,320,' ',"Shift Low to Mid+1 Position" ,BLACK);
		}

	}


	if(low>up)
	{
	  drawbox(array,10,11);
	  opmessage(200,300,' ',"If Low > Up, Search Element Not Found" ,RED);
	  drawarrow(low,LIGHTBLUE);
	  drawarrow(up,LIGHTGREEN);

	  drawlable(low,1,"Low");
	  drawlable(up,2,"Up");

	  sleep(1);

	  sprintf(s,"              %d NOT FOUND ",key);
	  getdata(250,290,0,s);
	}


}