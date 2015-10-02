#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<io.h>
#include<bios.h>
#include "prototp.h"
#include<dos.h>

/* To display help file */

void help(char *name)
{
     int n=0,i=0,j,numlines=0,x=10,y=5,pre=1;
     FILE *f;
     char ch[90];

     f=fopen(name,"r");

     if(f==0)
     {
	 getdata(100,200,0,"         Help File Can't open");
	 return;
     }

     while((fgets(ch,90,f)>0))
     numlines++;

     do{
	   setcolor(LIGHTGREEN);
	   if(n==20480&&i<numlines-23)
	     i++;
	   if(n==18432&&i>0)
	     i--;

	   rewind(f);

	   if(pre!=i)
	   {
			for(j=0;j<i;j++)
			fgets(ch,90,f);

		cleardevice();

		for(y=10;y<420;y=y+18)
		{
			if(fgets(ch,90,f)>0)
			{
			   for(j=0;ch[j]!='\n';j++);
			     ch[j]=0;


			   outtextxy(x,y,ch);
			}

		}

		setcolor(LIGHTBLUE);
		line(0,440,640,440);

		setcolor(LIGHTRED);
sprintf(ch," Use Cursor Keys to Scorll UP/DOWN,Press ESC to Exit (file: %s)",name);
		outtextxy(10,450,ch);
	   }

	   pre=i;

	} while((n=bioskey(0))!=283);

     fclose(f);
     return ;
}