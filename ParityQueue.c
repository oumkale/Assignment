#include <stdio.h>
#include <stdlib.h>
struct Prio
{
  int ele;
  int prio;
};
typedef struct Prio PrioQueue;
struct que
{
   PrioQueue arr[10];
   int rear,front;
};
typedef struct que Queue;
void initialize(Queue *p)
{
  Queue *q;
  q=p;
  q->rear=-1;
  q->front=0;
}
int isEmpty(Queue *p)
{
  Queue *q;
  q=p;
  return (q->rear<q->front ? 1:0);
}
int isFull(Queue *p)
{
  Queue *q;
  q=p;
  return (q->rear==9 ? 1:0);
}
void enQueue(Queue *p)
{
  Queue *q;
  q=p;
  int num,priority;
  if(!isFull(q))
  {
    q->rear++;
    printf("Enter a number to Enqueue:\n");
    scanf("%d",&num);
    printf("Enter a priority of element:\n");
    scanf("%d",&priority);
    q->arr[q->rear].ele=num;
    q->arr[q->rear].prio=priority;
  }  
  else 
  printf("Overflow\n");
}
void deQueue(Queue *p)
{
  Queue *q;
  q=p;
   int frontEle,prioEle,frontInd,maxP,index;
  if(!isEmpty(q))
  {
      frontInd=q->front;  
      maxP=-1;
     for(int i=q->rear;i>=q->front;i--)
     {
       if(q->arr[i].prio>=maxP)
        {
           maxP=q->arr[i].prio;
           frontEle=q->arr[i].ele;
           index=i;
        }
        
     }
     for(int j=index;j<=q->rear;j++)
     {
      q->arr[j]=q->arr[j+1];
     }
    q->rear--;
    printf("Deleted element is :%d\n",frontEle);
  
  }
  else
  printf("Underflow");
  
}
void disp(Queue *p)
{
  Queue *q;
   q=p;
  if(!isEmpty(q))
  {
    	
    	for(int i=q->front;i<=q->rear;i++)
         {
      		printf("Elements info:%d \t priority is:%d \n",q->arr[i].ele,q->arr[i].prio);
               
    	 }	
  
  }
  else
  printf("Queue is Empty\n");
 
  printf("Thank You\n");
}
int main()
{
  Queue *p;
  
   int ch,val,pos;
  p=(Queue*)malloc(sizeof(Queue));
  do{
       printf("Containing Methods on Parity Queue \n");
       printf("1.Initialization\n");
       printf("2.Check Emptyness of Queue\n");
       printf("3.Check Fullness of Queue\n");
       printf("4.Insert an element in Queue\n");
       printf("5.Delete an element from Queue\n");
       printf("6.Display a Queue\n");
       printf("7.Exit\n");
       printf("Please enter a choice\n");
       scanf("%d",&ch);
       printf("Ur entered choice is  %d.\n",ch);
       
       switch(ch)
        {
           case 1:initialize(p);
           break;
           case 2:val=isEmpty(p);
                  if(val==1)
                  printf("Parity Queue is Empty\n");
                  else
                  printf("Parity Queue is not empty\n");
           break;
           case 3:val=isFull(p);
                  if(val==1)
                  printf("Queue is Full\n");
                  else
                  printf("Queue is not full\n");
           
           break;
           case 4:enQueue(p);
                 printf("Successfully done\n");
           break;
           case 5:deQueue(p);
                  printf("Successfully done\n");
           break;
           case 6:disp(p);
           break;
           case 7:printf("Program is exiting\n");
                  exit(0);
           break;
           default:printf("Please enter correct choice\n");
           break;
        }
      }while(ch!=8);  
  return 0;
}
