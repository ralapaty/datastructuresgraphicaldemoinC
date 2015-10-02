#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<malloc.h>
#include<stdio.h>
#include<dos.h>
#include "prototp.h"


/* To display tree  */

void treedisplay(node *head ,int x, int y)
{
     char ch[3];
     node *p=head;

     if(p==0)
     return;

     treedisplay(p->left,p->x,p->y+12);
     treedisplay(p->right,p->x,p->y+12);
     setcolor(LIGHTBLUE);
     sprintf(ch,"%d",p->info);
     circle(p->x,p->y,12);
     setcolor(YELLOW);
     outtextxy(p->x-8,p->y-2,ch);
     setcolor(LIGHTGREEN);
     line(x,y,p->x,p->y-12);
}

/* To destroy tree */

void freetree(node *p )
{
     if(p==0)
     return;

     freetree(p->left);
     freetree(p->right);
     free(p);
 }

/* Inorder traversal of a tree */

void inorder(node *p,int *x)
{
     char ch[3];

     if(p==0)
     return;

     sprintf(ch,"%d ",p->info);

     inorder(p->left,x);

     *x+=20;
     setcolor(MAGENTA);
     circle(p->x,p->y,12);
     sleep(1);
     setcolor(LIGHTBLUE);
     circle(p->x,p->y,12);
     setcolor(LIGHTGRAY);
     outtextxy(*x,370,ch);

     inorder(p->right,x);
}

/*  preorder traversal of a tree */

void preorder(node *p,int *x)
{
     char ch[3];

     if(p==0)
	  return;

     sprintf(ch,"%d ",p->info);

     *x+=20;
     setcolor(MAGENTA);
     circle(p->x,p->y,12);
     sleep(1);
     setcolor(LIGHTBLUE);
     circle(p->x,p->y,12);
     setcolor(LIGHTGRAY);
     outtextxy(*x,370,ch);

     preorder(p->left,x);
     preorder(p->right,x);
}

/* postorder traversal of a tree */

void postorder(node *p,int *x)
{
     char ch[3];

     if(p==0)
	  return;

     postorder(p->left,x);
     postorder(p->right,x);

     sprintf(ch,"%d ",p->info);

     *x+=20;
     setcolor(MAGENTA);
     circle(p->x,p->y,12);
     sleep(1);
     setcolor(LIGHTBLUE);
     circle(p->x,p->y,12);
     setcolor(LIGHTGRAY);
     outtextxy(*x,370,ch);

}

/* To create a binary tree */

node *create(void)
{
	node *p,*q,*head=0,*temp;
	int level,num;
	char ch[3];
	char s[50];

	num=getdata(100,400,2,"ENTER A NUM(2 DIGIT)0 EXIT");

	if(num==0)
	   return head;

	head=(node*)calloc(sizeof(node),1);

	if(head==0)
	{
	   getdata(100,100,0,"Memory not available,con't create a node");
	   return head;
	}

	head->info=num;
	head->x=350;
	head->y=70;
	head->left=0;
	head->right=0;

	cleardevice();
	treedisplay(head,head->x,head->y-12);


	while(1)
	{
		num=getdata(100,400,2,"ENTER A NUM(2 DIGIT)0 EXIT");

		if(num==0)
		   break;

		p=head;
		level=0;

		while(p!=0&&p->info!=num)
		{
			setcolor(RED);
			circle(p->x,p->y,12);
			sleep(1);
			setcolor(LIGHTBLUE);
			circle(p->x,p->y,12);
			level++;
			q=p;

			if(p->info<num)
			{
				opmessage( 100, 380, ' ', s,BLACK);
				sprintf(s,"If %d < %d Go Right ",p->info,num);
				opmessage( 100, 380, ' ', s,LIGHTRED);
				delay(2000);
				p=p->right;

			}
			else
			{

				opmessage( 100, 380, ' ', s,BLACK);
				sprintf(s,"If %d > %d Go Left ",p->info,num);
				opmessage( 100, 380, ' ', s,LIGHTRED);
				delay(2000);
				p=p->left;
			}
		}

		if(p==0)
		{
		   if(level<5)
		   {
			if(q->info<num)
			{
			  temp=(node*)calloc(sizeof(node),1);

			  if(head==0)
			  {
		   getdata(100,100,0,"Memory not available,con't create a node");
				return head;
			  }

			  temp->info=num;
			  temp->left=0;
			  temp->right=0;

			  if(level==1)
			     temp->x=q->x+150;

			  if(level==2)
			     temp->x=q->x+75;

			  if(level==3)
			     temp->x=q->x+35;

			  if(level==4)
			     temp->x=q->x+15;

			  temp->y=q->y+60;
			  q->right=temp;
			}
			else
			{

			  temp=(node*)calloc(sizeof(node),1);

			  if(head==0)
			  {
		   getdata(100,100,0,"Memory not available,con't create a node");
				return head;
			  }

			  temp->info=num;
			  temp->left=0;
			  temp->right=0;

			  if(level==1)
			     temp->x=q->x-150;

			  if(level==2)
			     temp->x=q->x-75;

			  if(level==3)
			     temp->x=q->x-35;

			  if(level==4)
			     temp->x=q->x-15;

			  temp->y=q->y+60;
			  q->left=temp;
			}
			cleardevice();

			treedisplay(head,head->x,head->y-12);

		   }
		   else
			getdata(100,400,0,"    CAN'T SHOW 5 LEVELS MORE");


		}
		else
			getdata(100,400,0,"          DUPLICATE NODE");

	}

	return head;
}

