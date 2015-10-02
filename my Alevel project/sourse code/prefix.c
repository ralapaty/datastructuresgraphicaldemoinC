#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include "prototp.h"
#include<stdio.h>

/* to know given charecter is alpha or not
   if it is not alpha it will return 1
   if it is alpha it will return 0 */

int notalpha(char ch)
{
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
    return 0;
    return 1;
}

/* To do given operation with given operends and it will return answer */

int evalexp(int od1,int od2,char or)
{
    switch(or)
    {
	case '+':
		 return(od1+od2);
	case '-':
		 return(od1-od2);
	case '*':
		 return(od1*od2);
	case '/':
		 return(od1/od2);
	case '%':
		 return(od1%od2);
    }
    return 0;
}

/* To get infix expression from user */

void getinfix(int x,int y,char infix[],char *s,int mode)
{
     int i=0;
     char ch;

     infix[0]=0;

     while(1)
     {
		setfillstyle(SOLID_FILL,CYAN);
		bar(x,y,x+300,y+40);
		setfillstyle(SOLID_FILL,DARKGRAY);
		bar(x+9,y+22,x+200,y+34);

		setcolor(RED);
		outtextxy(x+10,y+10,s);
		setcolor(YELLOW);
		outtextxy(x+10,y+25,infix);
		ch=getch();

		if(ch==8&&i>=0)
		{
		  if(i==0)
		     infix[0]=0;
		else
		     infix[--i]=0;
		}

		if(mode==0)
		{
		  if(i<21&&ch!=' '&&ch!='\r'&&ch!=8)
		  {
			infix[i++]=ch;
			infix[i]=0;
		  }
		}
		else
		{
		  if(i<21&&ch!=' '&&ch!='\r'&&notalpha(ch)&&ch!=8)
		  {
			infix[i++]=ch;
			infix[i]=0;
		  }
		}

		if(ch=='\r')
		break;

	}

    setfillstyle(SOLID_FILL,BLACK);
    bar(x,y,x+300,y+40);
}

/* To check given charecter is operand or not
   if it is operand it will return 1.
   if it is not operand it will return 0 */

int operand(char ch)
{
	if(ch>='0'&&ch<='9'||ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
	   return 1;
	else
	   return 0;
}

/* To check given infix expression is valid or not
if it is valid it will return 1.
if it is not valid it will return 0 */

int validexp(char *s)
{
    int od=0,or=0,i,j=0;
    char exp[20];

    for(i=0;s[i]!=0;i++)
    {
	if(s[i]!='['&&s[i]!=']'&&s[i]!='{'&&s[i]!='}'&&s[i]!='('&&s[i]!=')')
	{
	  if(operand(s[i]))
	  {
	    od++;
		if(od-1!=or)
		return 0;
	  }
	  else
	  or++;
	}
	else
	{
	 if(s[i]==']')
		if(exp[j]!='[')
		   return 0;
		else
		{
			j--;
			continue;
		}

		if(s[i]=='}')
			if(exp[j]!='{')
			return 0;
		else
		{
			j--;
			continue;
		}

		if(s[i]==')')
			if(exp[j]!='(')
			return 0;
			else
			{
			j--;
			continue;
			}
		j++;
		exp[j]=s[i];

	}
    }

	 if(od-1!=or)
	 return 0;

	 if(j>0)
	 return 0;
	 return 1;

}

/* it will return precedence value of given operator */

int precedence(char ch,int mode)
{
    if(ch==']'||ch=='}'||ch==')')
    {
		if(mode==0)
		return 1;        /*postfix*/
		else
		return 10;       /*prefix */
    }

    if(ch=='*'||ch=='/'||ch=='%')
    return 8;

    if(ch=='-'||ch=='+')
    return 4;

    if(ch=='('||ch=='['||ch=='{')
    {
	if(mode==0)
	return 10;
	else
	return 1;
    }
     return 0;
}

/* To display opetations message for user */

void opmessage(int x,int y,char c,char *s,int color)
{
     char ch[2];

     ch[1]=0;
     setcolor(color);
     ch[0]=c;
     outtextxy(x,y,ch);
     outtextxy(x+20,y,s);
 }

/* if mode =0 it convert infix expression to postfix expression */
/* if mode==1 it convert infix expression to postfix expression
   and evaluate postfix expression */

void  postfix(int mode)
{
	stack s;
	char post[21],c,infix[21]={0,0,0,0,0},ch[2];
	int flag,i,j=0,od1,od2,ans;
	s.top=-1;
	setcolor(WHITE);
	outtextxy(300,70,"INFIX TO POSTFIX");

	if(mode==0)
		getinfix(200,170,infix,"ENTER INFIX EXPRESSION(a+b*c):",mode);
	else
	{
		setcolor(YELLOW);
		outtextxy(250,50,"EVALUATION OF POSTFIX EXPRESSION");
		getinfix(200,170,infix,"ENTER INFIX EXPRESSION(1+2*3):",mode);
	}

	flag=validexp(infix);
	setcolor(LIGHTCYAN);
	outtextxy(150,100,"INFIX");
	outtextxy(150,180,"POSTFIX");
	setcolor(LIGHTMAGENTA);
	outtextxy(150,110,infix);

	if(flag==0)
	{
		getdata(200,200,0,"       INVALID EXPRESSION");
		return ;
	}

	drawstack(500,200,10,9);

	for(i=0;infix[i]!=0;i++)
	{

		if(operand(infix[i]))
		{
			post[j++]=infix[i];
			post[j]=0;
			setcolor(LIGHTMAGENTA);
			outtextxy(150,200,post);

   opmessage(150,150,infix[i],"is Operand, Put In Postfix",LIGHTBLUE);
   delay(1500);
   opmessage(150,150,infix[i],"is Operand, Put In Postfix",BLACK);

			continue;
		}

		if(infix[i]=='['||infix[i]=='('||infix[i]=='{')
		{
	opmessage(150,150,infix[i],"is Open Brass, Push In stack",LIGHTBLUE);
			push(500,200,10,&s,0,infix[i]);
	opmessage(150,150,infix[i],"is Open Brass, Push In stack",BLACK);
			continue;
		}

		if(infix[i]==']'||infix[i]==')'||infix[i]=='}')
		{
		   while(1)
		   {
			c=s.array[s.top];

			if(c=='['||c=='{'||c=='(')
			break;

opmessage(150,150,infix[i],"is Close Brass, Pop Until Open Brass on Top of Stack",LIGHTBLUE);
			post[j]=pop(500,200,10,&s,0,0);
			j++;
			post[j]=0;
			setcolor(LIGHTMAGENTA);
			outtextxy(150,200,post);

		   }
opmessage(150,150,infix[i],"is Close Brass, Pop Until Open Brass on Top of Stack",BLACK);
opmessage(150,150,' '," Pop  Open Brass From Stack",LIGHTBLUE);
		pop(500,200,10,&s,0,0);
		opmessage(150,150,' '," Pop  Open Brass From Stack",BLACK);
		continue;
		}

		delay(400);
		if(!empty(s.top))
		{
    while(precedence(infix[i],1)<=precedence(s.array[s.top],1)&&!empty(s.top))
     {
opmessage(150,150,infix[i],"Operator,Check  Precedence With Top Element",LIGHTBLUE);
opmessage(150,170,infix[i]," Precedence >= Top Operator Pop And Put in Postfix",LIGHTBLUE);

		post[j]=(char)pop(500,200,10,&s,0,0);
		j++;
		post[j]=0;
		setcolor(LIGHTMAGENTA);
		outtextxy(150,200,post);
	}

opmessage(150,150,infix[i],"Operator,Check  Precedence With Top Element",BLACK);
opmessage(150,170,infix[i]," Precedence >= Top Operator Pop And Put in Postfix",BLACK);

	 }
    opmessage(150,150,infix[i],"is Operator,Push In to The Stack",LIGHTBLUE);
		push(500,200,10,&s,0,infix[i]);
    opmessage(150,150,infix[i],"is Operator,Push In to The Stack",BLACK);
	}

    while(!empty(s.top))
     {
	  opmessage(150,150,' ',"Pop and Add to Postfix",LIGHTBLUE);
	  post[j]=(char)s.array[s.top];
	  pop(500,200,10,&s,0,0);
	  j++;
	  post[j]=0;
	  delay(300);
	  setcolor(LIGHTMAGENTA);
	  outtextxy(150,200,post);
	}

	opmessage(150,150,' ',"Pop and Add to Postfix",BLACK);

     if(mode==0)
     {
		getdata(180,300,0,"     CONVERTION COMPLETE");
		return ;
     }

     setcolor(YELLOW);
     setfillstyle(SOLID_FILL,BLACK);
     bar(150,50,640,440);
     outtextxy(250,60,"EVALUATION OF POSTFIX EXPRESSION");
     setcolor(LIGHTCYAN);
     outtextxy(150,180,"POSTFIX");
     setcolor(LIGHTMAGENTA);
     outtextxy(150,190,post);
     drawstack(500,200,10,9);

     for(i=0;post[i]!=0;i++)
     {
	if(operand(post[i]))
	{
	 opmessage(150,150,post[i],"is Operand Push in to Stack",LIGHTBLUE);
	 push(500,200,10,&s,2,post[i]-48);
	 opmessage(150,150,post[i],"is Operand Push in to Stack",BLACK);
	 continue;
	}

	setcolor(LIGHTCYAN) ;
 opmessage(150,150,post[i],"is Operator, Pop Two Operands Form Stack",LIGHTBLUE);

	sprintf(infix,"%c",post[i]);
	outtextxy(240,300,infix);
	od2=pop(500,200,10,&s,0,3);
	setcolor(BLACK);
	outtextxy(240,300,infix);


	sprintf(infix,"%c%2d",post[i],od2);
	setcolor(LIGHTCYAN);
	outtextxy(240,300,infix);

	od1=pop(500,200,10,&s,0,3);

opmessage(150,150,post[i],"is Operator, Pop Two Operands Form Stack",BLACK);
opmessage(150,150,post[i],"Operation Perform",LIGHTBLUE);

	setcolor(BLACK);
	outtextxy(240,300,infix);
	sprintf(infix,"%2d%c%2d=",od1,post[i],od2);
	setcolor(LIGHTCYAN);
	outtextxy(240,300,infix);

	delay(400);
	opmessage(150,150,post[i],"Operation Perform",BLACK);
	setcolor(BLACK);
	outtextxy(240,300,infix);
	ans=evalexp(od1,od2,post[i]);
	sprintf(infix,"%2d%c%2d=%2d",od1,post[i],od2,ans);
	setcolor(LIGHTCYAN);
	outtextxy(240,300,infix);

	opmessage(150,150,' ',"Push Answer To Stack",LIGHTBLUE);

	push(500,200,10,&s,2,ans);

	opmessage(150,150,' ',"Push Answer To Stack",BLACK);

	setcolor(BLACK);
	outtextxy(240,300,infix);
     }

	opmessage(150,150,' ',"Pop Answer ",LIGHTBLUE);

	ans=pop(500,200,10,&s,0,3);

	opmessage(150,150,' ',"Pop Answer ",BLACK);

	sprintf(infix,"EXPRESSION VALUE =%2d",ans);
	setcolor(LIGHTCYAN);
	outtextxy(240,300,infix);
	getdata(180,400,0,"      EVALUATION COMPLETE");

return;
}

/* To convert infix expression to prefix expression */

void prefix(void)
{
     stack s1;
     stack s2;
     char prefix[21],c,infix[21]={0,0,0,0,0};
     int flag,i,j=0;

     s1.top=-1;
     s2.top=-1;
     setcolor(15);
     outtextxy(300,70,"INFIX TO PREFIX");
     getinfix(200,170,infix,"ENTER INFIX EXPRESSION(a+b*c):",0);
     flag=validexp(infix);
     setcolor(LIGHTCYAN);
     outtextxy(150,100,"INFIX");
     outtextxy(150,180,"PREFIX");
     setcolor(LIGHTMAGENTA);
     outtextxy(150,110,infix);

     if(flag==0)
     {
		getdata(200,200,0,"    INVALID EXPRESSION");
		return;
     }

     drawstack(400,200,12,9);
     outtextxy(400,450,"Stack1");

     drawstack(520,200,12,9);
     outtextxy(520,450,"Stack2");

     for(i=0;infix[i]!=0;i++);

     for(i=i-1;i>=0;i--)
	  {
		delay(200);

		if(operand(infix[i]))
		{
	opmessage(150,150,infix[i],"is Operand, Push into Stack1",LIGHTBLUE);
		  prefix[j++]=infix[i];
		  push(400,200,12,&s1,0,infix[i]);
		  setcolor(LIGHTBLUE);
		  outtextxy(400,450,"Stack1");
	opmessage(150,150,infix[i],"is Operand, Push into Stack1",BLACK);
		  continue;
		}

		if(infix[i]=='}'||infix[i]==')'||infix[i]==']')
		{
    opmessage(150,150,infix[i],"is Close Brass, push into Stack2",LIGHTBLUE);
			push(520,200,12,&s2,0,infix[i]);
			setcolor(LIGHTBLUE);
			outtextxy(520,450,"Stack2");
	 opmessage(150,150,infix[i],"is Close Brass, push into Stack2",BLACK);
			continue;
		}

		if(infix[i]=='['||infix[i]=='('||infix[i]=='{')
		{
 opmessage(150,150,infix[i],"is Open Brass, Pop Until  Stack2 Top is Close Brass",LIGHTBLUE);
 opmessage(150,160,' '," Push Poped Elements into Stack1",LIGHTBLUE);
	   while(1)
	   {
		c=s2.array[s2.top];

		if(c==']'||c=='}'||c==')')
		break;

		prefix[0]=pop(520,200,12,&s2,0,0);
		push(400,200,12,&s1,0,prefix[0]);
		setcolor(LIGHTBLUE);
		outtextxy(400,450,"Stack1");
		outtextxy(520,450,"Stack2");

	   }

opmessage(150,150,infix[i],"is Open Brass, Pop Until  Stack2 Top is Close Brass",BLACK);
opmessage(150,160,' '," Push Poped Elements into Stack1",BLACK);
opmessage(150,150,' '," Pop Close Brass From  Stack2 ",LIGHTBLUE);

		pop(520,200,12,&s2,0,0);
		setcolor(LIGHTBLUE);
		outtextxy(520,450,"Stack2");

    opmessage(150,150,' '," Pop Close Brass From  Stack2 ",BLACK);
		continue;
	   }
			delay(400);
	if(!empty(s2.top))
	{
opmessage(150,150,infix[i],"Operator,Check  Precedence With Top Element in Stack2",LIGHTBLUE);
opmessage(150,170,infix[i]," Precedence >= Top Operator Pop Stack2 And Push into Stack1",LIGHTBLUE);


while(precedence(infix[i],0)<=precedence(s2.array[s2.top],0)&&!empty(s2.top))
     {
	  prefix[0]=(char)pop(520,200,12,&s2,0,0);
	  push(400,200,12,&s1,0,prefix[0]);
	  setcolor(LIGHTBLUE);
	  outtextxy(400,450,"Stack1");
	  outtextxy(520,450,"Stack2");
	}

opmessage(150,150,infix[i],"Operator,Check  Precedence With Top Element in Stack2",BLACK);
opmessage(150,170,infix[i]," Precedence >= Top Operator Pop Stack2 And Push into Stack1",BLACK);


    }

    opmessage(150,150,infix[i]," is Operator Push into Stack2 ",LIGHTBLUE);
    push(520,200,12,&s2,0,infix[i]);
    opmessage(150,150,infix[i]," is Operator Push into Stack2 ",BLACK);
	setcolor(LIGHTBLUE);
		outtextxy(520,450,"Stack2");
	}
opmessage(150,150,' '," Pop all Elements From Stack2 and Push into Stack1 ",LIGHTBLUE);
    while(!empty(s2.top))
     {
	  prefix[0]=(char)s2.array[s2.top];
	  pop(520,200,12,&s2,0,0);
	  push(400,200,12,&s1,0,prefix[0]);
	  setcolor(LIGHTBLUE);
		outtextxy(520,450,"Stack2");
		outtextxy(400,450,"Stack1");
	}
		j=0;
opmessage(150,150,' '," Pop all Elements From Stack2 and Push into Stack1 ",BLACK);
opmessage(150,150,' '," Pop all Elements From Stack1 and Add to Prefix",LIGHTBLUE);

    while(!empty(s1.top))
    {
	  prefix[j]=(char)s1.array[s1.top];
	  pop(400,200,12,&s1,0,0);
	  j++;
	  prefix[j]=0;
	  setcolor(LIGHTMAGENTA);
	  outtextxy(150,200,prefix);
	  setcolor(LIGHTBLUE);
	  outtextxy(400,450,"Stack1");
    }

opmessage(150,150, ' '," Pop all Elements From Stack1 and Add to Prefix",BLACK);
     getdata(180,300,0,"       CONVERTION COMPLETE");

return;
}
