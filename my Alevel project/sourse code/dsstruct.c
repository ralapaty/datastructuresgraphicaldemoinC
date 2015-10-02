struct listnode
{
int num,padd,nadd,add;
struct listnode *pre,*next;
};

struct q
{
int array[20];
int rear,front;
};
struct stack
{
int array[20];
int top;
};

struct node
{
int info;
int x,y;
struct node *left,*right;
};
typedef struct node node;
typedef struct q q;
typedef struct stack stack;
