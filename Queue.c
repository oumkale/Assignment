#include <stdio.h>
#include <stdlib.h>
struct que
{
   int arr[10];
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
  int num;
  if(!isFull(q))
  {
    q->rear++;
    printf("Enter a number to Enqueue:\n");
    scanf("%d",&num);
    q->arr[q->rear]=num;
  }  
  else 
  printf("Overflow\n");
}
void deQueue(Queue *p)
{
  Queue *q;
  q=p;
   int t;
  if(!isEmpty(q))
  {
      t=q->arr[q->front];
     q->front++;   
  }
  else
  printf("Underflow");
  
  printf("Deleted element is %d\n",t);
}
void disp(Queue *p)
{
  Queue *q;
   q=p;
  if(!isEmpty(q))
  {
    for(int i=q->front;i<=q->rear;i++)
    {
      printf("Elements is:%d \n",q->arr[i]);
    }
  }
  else
  printf("Queue is Empty\n");
 /* while(q->arr[q->rear])
  {
     printf("Queue element is %d\n",q->arr[q->rear]);
     q->rear++;
  }
  */
  printf("Thank You\n");
}
int main()
{
  Queue *p;
  
   int ch,val,pos;
  p=(Queue*)malloc(sizeof(Queue));
  do{
       printf("Containing Methods on Queue \n");
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
                  printf("Queue is Empty\n");
                  else
                  printf("Queue is not empty\n");
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
