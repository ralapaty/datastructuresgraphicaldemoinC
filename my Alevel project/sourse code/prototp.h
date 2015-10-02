#include<g:\tc\dsstruct.c>

void init(void);
void searchingwindow(void);
void sortingwindow(void);
void linkedlistwindow(void);
void stackwindow(void);
void queuewindow(void);
void spacewindow(void);
void treewindow(void);
void contentwindow(void);
void listwindow(int i);

int swaping(int array[10],int i,int j,int flag);
void titlebar(char *s,int bcolor,int color);
void drawmenu(char array[10][20],int num,char *s,int i,int p[10],int mode,int color);
int mkey(int num,char *s,char array[10][20],int p[10],char message[10][70],int color);
void drawlable(int pos,int p,char *s);
void drawbox(int array[],int k,int j);
void drawarrow(int pos,int color);
int getdata(int x,int y,int j,char *s);
int strlen(char s[]);
int tolower(int ch);
int quit(void);

void linearsearch(void);
void binarysearch(void);

void lenearsort(void);
void bubblesort(void);
void insertionsort(void);
void drawqpoint(int x,int y,int size,int pos,int color,int mode);
void drawq(int x,int y,int size);

void drawstack(int x,int y,int size,int color);
void drawpointer(int x,int y,int size,int top,int color);
void stackdisplay(int x,int y,int size,stack *s,int pre);
void push(int x,int y,int size,stack *s,int pre,char c);
int  pop(int x,int y,int size,stack *s,int mode,int pre);
int full(int size,int top);
int empty(int top);

void drawpoint(int x,int y,int size,int pos,int color,int mode);
void drawq(int x,int y,int size);
void displayq(int x,int y,int size,q *s);
void insertq(int x,int y,int size,q *s);
void deleteq(int x,int y,int size ,q *s);

void treedisplay(node *head ,int x, int y);
void freetree(node *p );
void preorder(node *p,int *x);
void inorder(node *p,int *x);
void postorder(node *p,int *x);
node *create(void);

void drawnode(int x,int y,struct listnode *p,int i);
void llink(int x,int y);
void rlink(int x,int y);
void llinelink(int x,int y);
void rlinelink(int x,int y);
void firstlink(void);
void dmlink(int x,int y);
void d5link(int x,int y);
void nlink(int x,int y,int i);
void d4link(int x,int y);
void newlink(int x,int y,int i);
void display(struct listnode *p,int i);
struct listnode *createlink(struct listnode *head,int *address,int t);
struct listnode *insertnode(struct listnode *head,int *address,int t);
struct listnode *dellink(struct listnode *head,int t);
void freelink(struct listnode *head);

void getinfix(int x,int y,char infix[],char *s,int mode);
int operand(char ch);
int validexp(char *s);
int precedence(char ch,int mode);
void prefix(void);
void postfix(int mode);
int notalpha(char ch);
int evalexp(int od1,int od2,char or);
void opmessage(int x,int y,char c,char *s,int color);

void help(char *name);

void titlewindow(void);
void logo(void);

int buybuy(void);