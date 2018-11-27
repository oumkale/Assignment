#include <stdio.h>
#include <stdlib.h>
struct prioele
{
  char ele;
  int priority; 
};
typedef struct prioele Prio;
struct queue
{
 Prio a[10];
 int rear,front;
};
typedef struct queue Queue;
void intialise(Queue *q)
{
 if(!q)
   {
    printf("Will not print:\n"); 
     exit(0);
    }
  q->rear=-1;
  q->front=0;
}
int isEmpty(Queue *q)
{
  return (q->rear=-1 ? 1:0);
}
int isFull(Queue *q)
{
  return (q->rear==9 ? 1:0);
}
void enQueue(Queue *q,Prio v)
{
  if(!isFull(q))
  {  
      q->rear++;
      q->a[q->rear]=v;
     
   }
   else{
   printf("It is overflow now\n:");
   }
}

void display(Queue *q)
{
 for(int i=q->front;i<=q->rear;i++)
  printf("%c--%d\n",q->a[i].ele,q->a[i].priority);
 
}

int main()
{
 Queue *p;
 Prio w;
 char val;
 int choice,l,m;
   p=(Queue*)malloc(sizeof(Queue));
 do
  {
    printf("\n");
    printf("MENU\n");
    printf("1-Intialise\n");
    printf("2-Check Emptyness\n");
    printf("3-Check Fullness\n");
    printf("4-Enqueue\n");
    printf("5-Delqueue\n");
    printf("6-Display\n");
    printf("7-Exit\n");
    printf("Enter a choice:\n");
    scanf("%d",&choice);
    
    switch(choice)
    {
     case 1:intialise(p);
     break;
     case 2: l=isEmpty(p);
            if(l==1)
            printf("Yes it is empty\n:");
            else 
            printf("Not a empty:");
     break;
     
     case 3: m=isFull(p); 
            if(m==1)
            printf("Yes it is Full\n:");
            else 
            printf("Not full:");
     break;

     case 4: 
	fflush(stdin);
            printf("Enter priority and Element :\n");
            scanf("%d %c",&w.priority,&w.ele);
            
           
            enQueue(p,w);
     break;
    
     case 6:display(p);
     break;
     case 7: exit(0);
     break;
 
    }
  }while(choice!=8);
  return 0;
}

