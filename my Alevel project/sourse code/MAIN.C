#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include<process.h>
#include "prototp.h"

/*  Initializes the graphics system */

void init(void)
{
     int gd=DETECT,gm;
     initgraph(&gd,&gm,"");
}

/* To display searching window */

void searchingwindow(void)
{
     int p[]={0,0,0,0,1};
     int num=5,choice;
     char hot[]="lbmhx";
     char menu[][20]={"LINEAR SEARCH","BINARY SEARCH",
				 "MAIN WINDOW","HELP","EXIT","SEARCHING"};
     char message[10][70]={
				 "Search For A Element Using Linear Search Technic",
				 "Search For A Element Using Binary Search Technic",
				 "Return To Main Window",
				 "Help For Searching Technics",
				 "Return to Dos"," "};

		cleardevice();

		while(1)
		{
		cleardevice();

		titlebar("SEARCHING",BLUE,15);
		logo();
		choice=mkey(num,hot,menu,p,message,BLUE);
		cleardevice();
		titlebar("SEARCHING",BLUE,15);

		switch(choice)
		{
		  case 1:
				drawmenu(menu,num,hot,6,p,1,0);
				linearsearch();
				break;
		  case 2:
				drawmenu(menu,num,hot,6,p,1,0);
				binarysearch();
				break;
		  case 3:
				cleardevice();
				return;
		  case 4:
				help("search.txt");
				break;
		  case 5:
				drawmenu  (menu,num,hot,6,p,1,0);
				if(quit())
				{
					closegraph();
					exit(0);
				}
		}
	 }
}

/* To display sorting window */

void sortingwindow(void)
{
     int p[]={0,0,0,0,0,1};
     int num=6,choice;
     char hot[]="sibmhx";
     char menu[][20]={"LINEAR SORT","INSERTION SORT",
			     "BUBBLE SORT","MAIN WINDOW","HELP","EXIT","MENU"};
     char message[10][70]={
				"Sorting Example Using Linear Sorting Technic",
				"Sorting Example Using Insertion Sorting Technic",
				"Sorting Example Using Bubble Sorting Technic",
				"Return To Main Window",
				"Help For Sorting Technics",
				"Return To Dos"};

	  while(1)
	  {
		cleardevice();
		logo();
		titlebar("SORTING",RED,15);
		choice=mkey(num,hot,menu,p,message,RED);
		cleardevice();
		titlebar("SORTING",RED,15);

		switch(choice)
		{
		 case 1:
				drawmenu(menu,num,hot,1,p,1,1);
				lenearsort();
				break;
		 case 2:
				drawmenu(menu,num,hot,1,p,1,1);
				insertionsort();
				break;
		 case 3:
				drawmenu(menu,num,hot,1,p,1,1);
				bubblesort();
				break;
		 case 4:
				cleardevice();
				return;
		 case 5:
				help("sorting.txt");
				break;
		 case 6:
				drawmenu(menu,num,hot,1,p,1,1);
				if(quit())
				{
					closegraph();
					exit(0);
				}
	   }

	   }
}

/* To display linked list main window */

void linkedlistwindow(void)
{
     char menu[][20]={"DOUBLY LIST","SINGLY LIST",
			    "MAIN WINDOW","HELP","EXIT","MENU"};
     int p[]={0,0,0,0,1};
     int num=5,choice;
     char hot[]="dsmhx";
     char message[10][70]={
		    "Example For Singly linked list(Creation,Deletion,Insertion)",
		    "Example For Doubly linked list(Creation,Deletion,Insertion)",
		    "Return To Main Window",
		    "Help For Linked list",
		    "Return To Dos"};

	    while(1)
	    {
		    cleardevice();
			titlebar("LINKED LIST",BROWN,15);
			logo();
			choice=mkey(num,hot,menu,p,message,BROWN);

		switch(choice)
		{
		 case 1:
				drawmenu(menu,num,hot,1,p,1,1);
				listwindow(0);
				break;
		 case 2:
				drawmenu(menu,num,hot,1,p,1,1);
				listwindow(1);
				break;
		 case 3:
				cleardevice();
				return;

		 case 4:
				help("linklist.txt");
				break;
		 case 5:
				drawmenu(menu,num,hot,1,p,1,1);
				if(quit())
				{
					closegraph();
					exit(0);
				}
	   }
     }
}

/* To display stack window */

void stackwindow(void)
{
     char menu[][20]={"PUSH","POP","TOP","MAIN WINDOW","HELP","EXIT","MENU"};
     int p[]={1,0,0,0,0,1};
     int num=6,choice;
     char hot[]="uptmhx";
     stack s;
     char message[10][70]={"Example For Push Operation  ",
				   "Example For Pop Operation ",
				   "Example For Top Operation "
				   "Return To Main Window",
				   "Help For Stack",
				   "Return To Dos"};

		 cleardevice();

		 s.top=-1;
		 stackdisplay(500,200,10,&s,1);

	 while(1)
	 {
		stackdisplay(500,200,10,&s,1);
		setcolor(LIGHTGREEN);
		settextstyle(1,0,2);
		outtextxy(340,60,"STACK");
		settextstyle(0,0,1);
		titlebar("STACK",CYAN,15);

		choice=mkey(num,hot,menu,p,message,CYAN);

		switch(choice)
		{
		 case 1:
				drawmenu(menu,num,hot,1,p,1,1);
				push(500,200,10,&s,1,0);
				break;
		 case 2:
				drawmenu(menu,num,hot,1,p,1,1);
				pop(500,200,10,&s,0,1);
				break;

		 case 3:
				drawmenu(menu,num,hot,1,p,1,1);
				pop(500,200,10,&s,1,1);
				break;
		 case 4:
				cleardevice();
				return;

		 case 5:
				help("stack.txt");
				cleardevice();
				break;
		 case 6:
				drawmenu(menu,num,hot,1,p,1,1);
				if(quit())
				{
					closegraph();
					exit(0);
				}
		 }
	}
}

/* To display Queue window */

void queuewindow(void)
{
     char menu[][20]={"INSERT","DELETE","MAIN WINDOW","HELP","EXIT","MENU"};
     int p[]={0,0,0,0,1};
     int num=5,choice;
     char hot[]="idmhx";
     int x=240,y=200,size=10;
     q s;
     char message[10][70]={"Example For Insert Operation  ",
				   "Example For Delete Operation ",
				   "Return To Main Window",
				   "Help For queue",
				   "Return To Dos"};

		cleardevice();
		s.rear=-1;
		s.front=-1;

		drawq(x,y,size);
		drawqpoint( x, y, size,s.front,2,0);
		drawqpoint( x, y, size,s.rear,2,1);

		while(1)
		{
			 drawq(x,y,size);
			 displayq(x,y,size,&s);
			 drawqpoint( x, y, size,s.rear,2,0);
			 drawqpoint( x, y, size,s.front,2,1);

			 settextstyle(1,0,2);
			 outtextxy(340,60,"QUEUE");
			 settextstyle(0,0,1);
			 titlebar("QUEUE",GREEN,15);

			 choice=mkey(num,hot,menu,p,message,GREEN);

			switch(choice)
			{
				case 1:
					    drawmenu(menu,num,hot,1,p,1,1);
					    insertq(x,y,size,&s);
					    break;
				case 2:
					    drawmenu(menu,num,hot,1,p,1,1);
					    deleteq(x,y,size,&s);
					    break;
				case 3:
					    cleardevice();
					    return;
				case 4:
					    help("queue.txt");
					    cleardevice();
					    break;
				case 5:
					    drawmenu(menu,num,hot,1,p,1,1);
					    if(quit())
					    {
						closegraph();
						exit(0);
					    }

			}
		}
}

/* To display prefixwindow  */

void prefixwindow(void)
{

     int p[]={0,1,0,0,0,1};
     int num=6,choice;
     char hot[]="poemhx";
     char menu[][20]={"PREFIX","POSTFIX","EVAL POSTFIX",
			    "MAINWINDOW","HELP","EXIT","MENU"};
     char message[10][70]={
			"Example For Convertion To Infix To Prefix Expression ",
			"Example For Convertion To Infix To Postfix Expression ",
			"Example For Evaluation Of Postfix Expression",
			"Return To Main Window",
			"Help For Convertion Of Infix Expressions",
			"Return To Dos"};

	   while(1)
	   {
		cleardevice();
		titlebar("CONVERSTION OF INFIX EXPRESSTIONS",DARKGRAY,15);
		logo();

		choice=mkey(num,hot,menu,p,message,DARKGRAY);
		cleardevice();
		titlebar("CONVERSTION OF INFIX EXPRESSTIONS",DARKGRAY,15);

		switch(choice)
		{
		 case 1:
				drawmenu(menu,num,hot,1,p,1,1);
				prefix();
				break;
		 case 2:
				drawmenu(menu,num,hot,1,p,1,1);
				postfix(0);
				break;
		 case 3:
				drawmenu(menu,num,hot,1,p,1,1);
				postfix(1);
				break;
		 case 4:
				cleardevice();
				return;

		 case 5:
				help("infix.txt");
				cleardevice();
				break;
		 case 6:
				drawmenu(menu,num,hot,1,p,1,1);
				if(quit())
				{
					closegraph();
					exit(0);
				}
	   }

	}
}

/* To display  binary tree window */

void treewindow(void)
{
     int p[]={0,0,0,1,0,0,1};
     int num=7,choice;
     char hot[]="cpiomhx";
     node* head=0;
     int x=5;
     char menu[][20]={"CREATE","PREORDER","INORDER","POSTORDER",
			    "MAIN WINDOW","HELP","EXIT","MENU"};
     char message[10][70]={"Example For Binary Tree Creation ",
				   "Example For Preorder  Traversal ",
				   "Example For Inorder Traversal",
				   "Example For Postorder Traversal",
				   "Return To Main Window",
				   "Help For Binary Tree Creation And Traversals",
				   "Return To Dos"};

	 logo();

	 while(1)
	 {
		x=5;

		if(head!=0)
		{
			cleardevice();
			treedisplay(head,head->x,head->y-12);
		}

		titlebar("BINARY TREE",LIGHTRED,15);
		choice=mkey(num,hot,menu,p,message,LIGHTRED);


		switch(choice)
		{
			case 1:
					cleardevice();
					freetree(head);
					head=0;
					head=create();
					break;
			case 2:

					if(head!=0)
					{
						cleardevice();
						treedisplay(head,head->x,head->y-12);
						setcolor(CYAN);
						outtextxy(10,355,"PREORDER ");
						preorder(head,&x);
						getch();
					}
					else
					{
					  getdata(200,300,0,"             EMPTY TREE" );
						cleardevice();
					}
					break;
			case 3:
					if(head!=0)
					{
						cleardevice();
						treedisplay(head,head->x,head->y-12);
						setcolor(CYAN);
						outtextxy(10,355,"INORDER  ");
						inorder(head,&x);
						getch();
					}
					else
					{
					   getdata(200,300,0,"           EMPTY TREE" );
						cleardevice();
					}
					break;

			case 4:
					if(head!=0)
					{
						cleardevice();
						treedisplay(head,head->x,head->y-12);
						setcolor(CYAN);
						outtextxy(10,355,"POSTORDER");
						postorder(head,&x);
						getch();
					}
					else
					{
					  getdata(200,300,0,"           EMPTY TREE" );
						cleardevice();
					}
					break;
			case 5:
					freetree(head);
					cleardevice();
					return;
			case 6:
					help("btree.txt");
					cleardevice();
					break;
			case 7:
					if(quit())
					{
						freetree(head);
						closegraph();
						exit(0);
					}
					cleardevice();

		}
	 }
}

/* To Display staring or main window */

void contentwindow(void)
{
     int p[]={0,1,0,2,0,0,0,0,1};
     int num=9,choice;
     char hot[]="solaqcbhx";
     char menu[][20]={"SEARCHING","SORTING","LINKED LIST","STACK",
			   "QUEUE","CONV OF INFIX","BINARY TREE","HELP","EXIT","CONTENTS"};
     char message[10][70]={
				    "Examples For Searching  Technics ",
				    "Examples For Sorting Technics",
				    "Examples For Linked Lists",
				    "Example For Stack Data Structure",
				    "Example For Queue Data structure",
				    "Examples For Convertion Of Infix Expressions",
				    "Example For Binary Tree Creation And Traversals",
				    "Help About Introduction To Datastructure",
				    "Return To Dos"};

	while(1)
	{
		titlebar("INTRODUCTION TO DATASTRUCTURES",MAGENTA,15);
		logo();
		choice=mkey(num,hot,menu,p,message,MAGENTA);

		switch(choice)
		{
			case 1:
					searchingwindow();
					break;
			case 2:
					sortingwindow();
					break;
			case 3:
					linkedlistwindow();
					break;
			case 4:
					stackwindow();
					break;
			case 5:
					queuewindow();
					break;
			case 6:
					prefixwindow();
					break;
			case 7:
					treewindow();
					break;
			case 8:
					help("main.txt");
					cleardevice();
					break;
			case 9:
					if(quit())
					{
						closegraph();
						exit(0);
					}
		}
	}
}

/* To display single linked or bouble linked list window */

void listwindow(int i)
{
     int p[]={0,0,0,0,0,1};
     int num=6,choice,address=100;
     char hot[]="cidphx";
     struct listnode *head=0;
     char menu[][20]={"CREATE LIST","INSERT NODE","DELETE NODE",
			    "PREVIOUS WIN","HELP","EXIT","MENU"};
     char message[10][70]={" Creation Of Linked List",
				   "Insertion Of A New Node In Linked List ",
				   "Deletion Of A Node In Linked List",
				   "Return To Previous Window",
				   "Help For Linked List Operations",
				   "Return To Dos"};

	    logo();

	    while(1)
	    {
			if(i!=0)
			titlebar("SINGLE LINKED LIST",BROWN,15);
			else
			titlebar("DOUBLE LINKED LIST",BROWN,15);
			display(head,i);
			choice=mkey(num,hot,menu,p,message,BROWN);

		switch(choice)
		{
		 case 1:
				drawmenu(menu,num,hot,1,p,1,1);
				address=100;
				head=createlink(head,&address,i);
				break;
		 case 2:
				drawmenu(menu,num,hot,1,p,1,1);
				head=insertnode(head,&address,i);
				break;
		 case 3:
				drawmenu(menu,num,hot,1,p,1,1);
				head=dellink(head,i);
				break;
		 case 4:

				cleardevice();
				freelink(head);
				return;

		 case 5:
				if(i!=0)
				help("single.txt");
				else
				help("double.txt");

				cleardevice();
				break;
		 case 6:
				drawmenu(menu,num,hot,1,p,1,1);

				if(quit())
				{
					closegraph();
					freelink(head);
					exit(0);
				}
			     display(head,i);
		}
	   }
}



int main()
{
	init();
	titlewindow();
	cleardevice();
	contentwindow();
	getch();
	closegraph();
	return 0;
}