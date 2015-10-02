#include<graphics.h>
#include<conio.h>
#include<malloc.h>
#include<stdio.h>
#include "prototp.h"
#include<dos.h>

/* To draw node figure */

void drawnode(int x,int y,struct listnode *p,int i)
{
     char ch[4];

		setcolor(WHITE);
		line(x,y,x+92,y);
		line(x,y+20,x+92,y+20);
		line(x,y,x,y+20);
		line(x+92,y,x+92,y+20);

	/* i=0 for to draw double link node
	   i!=0 to draw single link node */

	if(i==0)
	{
		line(x+28,y,x+28,y+20);
		line(x+60,y,x+60,y+20);
	}
	else
		line(x+46,y,x+46,y+20);

			setcolor(CYAN);

		if(i==0)
		{
			outtextxy(x+2,y-10,"Pre");
			outtextxy(x+64,y-10,"Nxt");
		}
		else
			outtextxy(x+55,y-10,"NEXT");

		setcolor(LIGHTRED);

		if(i==0)
			outtextxy(x+32,y-10,"NUM");
		else
			outtextxy(x+15,y-10,"INFO");

		setcolor(LIGHTBLUE);

		if(i==0)
		{
			sprintf(ch,"%d",p->padd);
			outtextxy(x+2,y+10,ch);
			sprintf(ch,"%d",p->nadd);
			outtextxy(x+64,y+10,ch);
		}
		else
		{
			sprintf(ch,"%d",p->nadd);
			outtextxy(x+60,y+10,ch);
		}

			setcolor(YELLOW);
			sprintf(ch,"%d",p->num);

		if(i==0)
			outtextxy(x+32,y+10,ch);
		else
			outtextxy(x+15,y+10,ch);


		setcolor(LIGHTMAGENTA);
		sprintf(ch,"%d",p->add);
		outtextxy(x+32,y+22,ch);
}

/* To draw left link to  new node  for insert new node in single row*/

void llink(int x,int y)
{
     setcolor(LIGHTRED);
     line(x+92,y+10,x+102,y+10);
     line(x+102,y+10,x+102,y+32);
     line(x+50,y+32,x+102,y+32);
     line(x+50,y+32,x+50,y+60);
     line(x+50,y+60,x+60,y+60);
     line(x+60,y+60,x+57,y+57);
     line(x+60,y+60,x+57,y+63);
}

/* to draw right link to new node for insert new node in single row*/

void rlink(int x,int y)
{
     setcolor(LIGHTRED);
     line(x,y+10,x-10,y+10);
     line(x-10,y+10,x-10,y+32);
     line(x-10,y+32,x+40,y+32);
     line(x+40,y+32,x+40,y+60);
     line(x+40,y+60,x+32,y+60);
     line(x,y+10,x-4,y+13);
     line(x,y+10,x-4,y+7);
}

/* to draw left link to new node for insert new node between two rows */

void llinelink(int x,int y)
{
     setcolor(LIGHTRED);
     line(x+92,y+10,x+102,y+10);
     line(x+102,y+10,x+102,y+32);
     line(x-10,y+32,x+102,y+32);
     line(x-10,y+32,x-10,y+60);
     line(x-10,y+60,x,y+60);
     line(x,y+60,x-3,y+57);
     line(x,y+60,x-3,y+63);
}

/* To draw right link to new node for insert new node between two rows */

void rlinelink(int x,int y)
{
     setcolor(LIGHTRED);
     line(x+92,y+10,x+102,y+10);
     line(x+102,y+10,x+102,y+32);
     line(150,y+32,622,y+32);
     line(150,y+32,150,y+58);
     line(150,y+58,160,y+58);
     line(157,y+55,160,y+58);
     line(157,y+61,160,y+58);
}

/*To draw link for insert new node in head position */

void firstlink(void)
{
     setcolor(LIGHTRED);
     line(150,110,160,110);
     line(150,110,150,130);
     line(150,130,260,130);
     line(260,130,260,160);
     line(252,160,260,160);
     line(156,107,160,110);
     line(156,113,160,110);
}

/* To draw link for delete middle node in a row */

void dmlink(int x,int y)
{
     setcolor(LIGHTRED);
     line(x+92,y+10,x+102,y+10);
     line(x+102,y+10,x+102,y-15);
     line(x+102,y-15,x+225,y-15);
     line(x+225,y-15,x+225,y+10);
     line(x+225,y+10,x+240,y+10);
     line(x+236,y+6,x+240,y+10);
     line(x+236,y+16,x+240,y+10);
}

/* to draw link for delete 5th or 9th node in list */

void d5link(int x,int y)
{
     setcolor(LIGHTRED);
     line(x+92,y+10,x+102,y+10);
     line(x+102,y+10,x+102,y+60);
     line(270,y+60,x+102,y+60);
     line(270,y+60,270,y+110);
     line(270,y+110,280,y+110);
     line(276,y+107,280,y+110);
     line(276,y+113,280,y+110);
}

/* to draw link for  one node to another node in a same row */

void nlink(int x,int y,int i)
{
     /* i=0 to draw link
	  i!=0 to erase link */

     if(i==0)
		setcolor(LIGHTGREEN);
     else
		setcolor(BLACK);

     line(x+92,y+10,x+120,y+10);
     line(x+116,y+7,x+120,y+10);
     line(x+116,y+13,x+120,y+10);
}

/* to delete 4th or 8th node in link list */

void d4link(int x,int y)
{
     setcolor(LIGHTRED);
     line(x+92,y+10,x+102,y+10);
     line(x+102,y+10,x+102,y+60);
     line(x-250,y+60,x+102,y+60);
     line(x-250,y+60,x-250,y+110);
     line(x-250,y+110,x-240,y+110);
     line(x-244,y+107,x-240,y+110);
     line(x-244,y+113,x-240,y+110);
}

/* to draw link between one row to aother row */

void newlink(int x,int y,int i)
{
     if(i==0)
	setcolor(LIGHTGREEN);
     else
	setcolor(BLACK);

     line(x+92,y+10,x+105,y+10);
     line(x+105,y+10,x+105,y+30);
     line(150,y+30,x+105,y+30);
     line(150,y+30,150,y+110);
     line(150,y+110,160,y+110);
     line(156,y+107,160,y+110);
     line(156,y+113,160,y+110);
}

/* to display link list */

void display( struct listnode *p,int i)
{
     int count=0,x=160,y=100;

		setfillstyle(SOLID_FILL,BLACK);
		bar(145,70,640,400);

     while(p!=0)
     {
	   /* to display maximam 4 nodes in row */

		if(count<4)
		{
			count++;
			drawnode(x,y,p,i);
			x+=120;

			if(count>1)
			nlink(x-240,y,0);
		}
		else
		{
			newlink(520,y,0);
			drawnode(160,y+100,p,i);
			x=280;y+=100;
			count=1;
		}

		p=p->next;
	}
}

/* to create link list  */

struct listnode *createlink(struct listnode *head,int *address,int t)
{
	 int info,count=0;
	 struct listnode *p,*temp;


		freelink(head); /* to distroy old list if exist */

		setfillstyle(SOLID_FILL,BLACK);
		bar(145,70,640,400);
		head=0;
		info=getdata(300,400,2,"ENTER A NUM(2 DIGI)0 EXIT");

			if(info==0)
			return head;

		head=(struct listnode*)calloc(sizeof(struct listnode),1);

		if(head==0)
		{
			getdata(100,100,0,"Memory not avilable,con't create node");
			return head;
		}

		head->num=info;
		head->padd=0;
		head->nadd=0;
		head->add=*address;
		head->pre=0;
		head->next=0;

		display(head,t);
		*address+=50;
		count++;

	while(1)
	{
		p=head;

		info=getdata(300,400,2,"ENTER A NUM(2 DIGI)0 EXIT");

		if(info==0)
			return head;

		/*  This example can dispaly 12 nodes maximum */

		if(count<12)
		{
		   temp=(struct listnode*)calloc(sizeof(struct listnode),1);

		   if(temp==0)
		   {
		     getdata(100,100,0,"Memory not avilable,con't create node");
		     return head;
		   }

		   temp->num=info;
		   temp->padd=0;
		   temp->nadd=0;
		   temp->add=*address;
		   temp->pre=0;
		   temp->next=0;


			for(p=head;p->next!=0;p=p->next);
				temp->pre=p;

		   p->next=temp;
		   p->nadd=temp->add;
		   temp->padd=p->add;

		   count++;
		   *address+=50;
		}
		else
		  getdata(300,400,0,"CAN'T TAKE MORE THAN 12 NODES");

			display(head,t);
	}

}
/* to insert new node in given position in list */

struct listnode *insertnode(struct listnode *head,int *address,int t)
{
	 int info,i,x,y,count=0,position;
	 struct listnode *p,*temp;
	 char ch[50];

		if(head==0)
		{
			getdata(300,400,0,"            LIST IS EMPTY");
			return head;
		}

		info=getdata(300,400,2,"ENTER A NUM(2 DIGI)0 EXIT");

	for(count=0,p=head;p!=0;p=p->next,count++);

	sprintf(ch,"ENTER POSITION(1 TO %d)",count+1);
	position=getdata(300,400,2,ch);


	if(position<=0||position>12||count+1<position)
	{
		getdata(300,400,0,"          INVALID POSITION ");
		return head;
	}

     if(count>=12)
     {
	  getdata(300,400,0,"CAN'T TAKE MORE THAN 12 NODES");
	  return head;
     }

	temp=(struct listnode*)calloc(sizeof(struct listnode),1);

	if(temp==0)
	{
	   getdata(100,100,0,"Memory not avilable,con't create node");
	   return head;
	}

	temp->pre=0;
	temp->next=0;
	temp->num=info;
	temp->add=*address;

	*address+=50;
	temp->padd=0;
	temp->nadd=0;

 if(position==1)
   {
opmessage( 160, 400, ' ',"Put Link New Node to Head Node And Set Head Is New Node",MAGENTA);
		drawnode(160,150,temp,t);
		firstlink();
		sleep(1);
opmessage( 160, 400, ' ',"Put Link New Node to Head Node And Set Head Is New Node",BLACK);

		temp->next=head;
		head->pre=temp;
		head->padd=temp->add;
		temp->nadd=head->add;
		head=temp;

		display(head,t);
		return head;

   }

     for( i=2,p=head;i<position&&p->next!=0;i++,p=p->next);

     if(count+1==position)
	{
 opmessage( 160, 400, ' ',"Create New Node And Put Link Last Node to New Node ",MAGENTA);
	 sleep(1);
 opmessage( 160, 400, ' ',"Create New Node And Put Link Last Node to New Node ",BLACK);

		p->next=temp;
		temp->pre=p;
		temp->padd=p->add;
		p->nadd=temp->add;

		display(head,t);

		return head;
	}

   sprintf(ch,"Create New Node And Put Link New Node to  %d Node ",position);
   opmessage( 160, 400, ' ',ch,MAGENTA);
   sprintf(ch," And Put Link  %d Node To New Node ",position-1);
   opmessage( 160, 410, ' ',ch,MAGENTA);
   delay(1000);

			temp->next=p->next;
			p->next->pre=temp;
			temp->nadd=p->next->add;
			p->next->padd=temp->add;
			temp->pre=p;
			temp->padd=p->add;
			p->next=temp;
			p->nadd=temp->add;

		if(position==5||position==9)
		{
			if(position==5)
			y=150;
			else
			y=250;

		  x=520;
		  newlink(x,y-50,1);
		  drawnode(x,y,temp,t);
		  rlinelink(x,y);
		  sleep(1);
		  llinelink(x,y-50);

			sleep(1);
   sprintf(ch,"Create New Node And Put Link New Node to  %d Node ",position);
	   opmessage( 160, 400, ' ',ch,BLACK);
   sprintf(ch," And Put Link  %d Node To New Node ",position-1);
	   opmessage( 160, 410, ' ',ch,BLACK);

			display(head,t);

			return head;
		}

				if(position>1&&position<5)
					y=100;
				if(position>5&&position<9)
					y=200;
				if(position>9&&position<12)
					y=300;

				if(position==2||position==6||position==10)
					x=160;
				if(position==3||position==7||position==11)
					x=280;
				if(position==4||position==8)
					x=400;

		drawnode(x+60,y+50,temp,t);
		nlink(x,y,1);
		rlink(x+120,y);
		sleep(1);

		llink(x,y);

		sleep(1);
   sprintf(ch,"Create New Node And Put Link New Node to  %d Node ",position);
		opmessage( 160, 400, ' ',ch,BLACK);
   sprintf(ch," And Put Link  %d Node To New Node ",position-1);
		opmessage( 160, 410, ' ',ch,BLACK);

		display(head,t);

	   return head;

}

/* to delete a node in given position in list */

struct listnode *dellink(struct listnode *head,int t)
{
	 int position,count=0,x,y,i;
	 struct listnode *p,*temp;
	 char ch[50];

		if(head==0)
		{
			getdata(300,400,0,"LIST IS EMPTY");
			return head;
		}

	 for(count=0,p=head;p!=0;count++,p=p->next)
		temp=p;

	 position=getdata(300,400,2,"WHICH POSITION TO DELETE");
		if(position==0||position>count)
		{
			getdata(300,400,0,"           INVALID POSITION");
			return head;
		}

	 if(position==1)
	 {
	  opmessage( 160, 400, ' ',"Move Head to Head->next Node",LIGHTGREEN);
			nlink(160,100,1);
			delay(1000);

			temp=head;
			head=head->next;
			free(temp);

			head->pre=0;
			head->padd=0;
	opmessage( 160, 400, ' ',"Move Head to Head->next Node",BLACK);

			display(head,t);
			return head;
	 }

	 sprintf(ch,"Put Link %d Node  To %d Node",position-1,position+1);
	 opmessage( 160, 400, ' ',ch,LIGHTGREEN);


	 for( i=2,p=head;i<position;i++,p=p->next);

	 if(position==5&&count==position||position==9&&position==count)
	 {
		if(position==5)
			newlink(520,100,1);
		else
			newlink(520,200,1);

			temp=p->next;
			p->next=0;
			p->nadd=0;
			free(temp);
			sleep(1);

	   opmessage( 160, 400, ' ',ch,BLACK);

			display(head,t);
			return head;
	 }

	 if(count==position)
	 {
		if(position<13)
			y=300;
		if(position<9)
			y=200;
		if(position<5)
			y=100;

		if(position==2||position==10||position==6)
			x=160;
		if(position==3||position==11||position==7)
			x=280;
		if(position==4||position==12||position==8)
			x=400;

		temp=p->next;
		p->next=0;
		p->nadd=0;
		free(temp);

		nlink(x,y,1);
		sleep(1);
	   opmessage( 160, 400, ' ',ch,BLACK);

		display(head,t);
		return head;
	 }

		temp=p->next;
		p->next=p->next->next;
		p->next->pre=p;
		p->next->padd=p->add;
		p->nadd=p->next->add;

		free(temp);

     if(position==4||position==8)
	{
	  if(position==4)
		y=100;
	  else
		y=200;

			x=400;

		newlink(520,y,1);
		nlink(400,y,1);
		d4link(x,y);
		sleep(1);
	opmessage( 160, 400, ' ',ch,BLACK);

		display(head,t);
		return head;
	}

     if(position==5||position==9)
	{
		if(position==5)
			y=100;
		else
			y=200;

				x=520;

		newlink(520,y,1);
		d5link(x,y);
		sleep(1);
	 opmessage( 160, 400, ' ',ch,BLACK);

		display(head,t);
		return head;
	}

		if(position<12)
			y=300;
		if(position<8)
			y=200;
		if(position<4)
			y=100;

		if(position==2||position==6)
			x=280;
		if(position==3||position==7)
			x=400;

		nlink(x-120,y,1);
		nlink(x,y,1);
		dmlink(x-120,y);
		sleep(1);
	 opmessage( 160, 400, ' ',ch,BLACK);

		display(head,t);

	 return head;

}

/* to destroy the list */

void freelink(struct listnode *head)
{
     struct listnode *p=head;

	while(head!=0)
	{
		p=head;
		head=head->next;
		free(p);
	}
}
