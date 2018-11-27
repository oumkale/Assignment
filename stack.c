#include<stdio.h>
#include <stdlib.h>
struct stk
{
	int arr[100];
	int top;
};

typedef struct stk Stack;

void initialize(Stack *p)
{
	if(p!=NULL)
		p->top=-1;
	else
		exit(0);
}

void dispstack(Stack *p)
{
	int i,n;

	
	printf("\n");
	if(!isEmpty(p))
	{
		for(i=p->top;i>=0;i--)
			printf("\n%d",p->arr[i]);
	}
	else
		printf("Stack is empty");
}

int isFull(Stack *p)
{
	return(p->top==99 ? 1:0);
}

int isEmpty(Stack *p)
{
	return(p->top==-1 ? 1:0);
}

void push(Stack *p, int v)
{
	if(!isFull(p))
	{
		p->top++;
		p->arr[p->top]=v;
	}
}

int pop(Stack *p)
{
	int t;
	if(!isEmpty(p))
	{
		t=p->arr[p->top];
		p->top--;
		return(t);
	}
	else
	{
		printf("\nStack underflows");
		return '\0';
	}
}
int peek(Stack *p)
{
	if(!isEmpty(p))
		return(p->arr[p->top]);
	else
		return '\0';
}
void infixToPostfix(int *exp ,Stack *stack)
{
	 int i=0, k=-1;
	int post[100];

	while(exp[i])
	 {

		  if (isOperand(exp[i]))
				post[++k] = exp[i];


		  else if (exp[i] == '(')
				push(stack, exp[i]);


		  else if (exp[i] == ')')
		  {
				while (peek(stack) != '(')
					 post[++k] = pop(stack);
				pop(stack);
		  }
		  else // an operator is encountered
		  {
				while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
					 post[++k] = pop(stack);
				push(stack, exp[i]);
		  }
		i++;

	 }

	 // pop all the operators from the stack
	 while (!isEmpty(stack))
		  post[++k] = pop(stack);

	 post[++k] = '\0';
	 printf( "\n%d", post);
}
int isOperand(int ch)
{
	if((ch>=65 && ch<=90) || (ch>=97 && ch <=122)|| (ch>=48 && ch<=57))
		return(1);
	else
		return(0);
}
int Prec(int ch)
{
	int p;
	switch(ch)
	{
		case '+':
		case '-':
			p=1;
			break;
		case '*':
		case '/':
			p=2;
			break;
		case '^':
			p=3;
			break;
		default:
			p=0;
			break;
	}
	return(p);
}
int evalpost(int *exp,Stack *stack)
{
	int a,b,c,i=0;
	int ch,op;
	while(ch=exp[i])
	{
		if(isOperand(ch))
			push(stack,ch);
		else
		{
			b=pop(stack)-'0';
			a=pop(stack)-'0';
			switch(ch)
			{
				case '+':
					c=a+b;
					break;
				case '-':
					c=a-b;
					break;
				case '*':
					c=a*b;
					break;
				case '/':
					c=a/b;
					break;
				/*case '^':
					c=pow(a,b);
					break;*/
			}
			push(stack,c+'0');
		}
		i++;
	}
	return(pop(stack)-'0');
}
int main()
{
	Stack *s;
	int r,v;
	int choice,val;
	int inf[100],post[50];
	s=(Stack *)malloc(sizeof(Stack));
	do
	{
		printf("\n----Menu----");
		printf("\n1:Initialize stack");
		printf("\n2:Disp stack");
		printf("\n3:Push an elelement");
		printf("\n4:Pop an element");
		printf("\n5:Peek element");
		printf("\n6:Infix to Postfix");
		printf("\n7:Postfix evaluation");
		printf("\n8:Exit");
		printf("\nEnter you choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				
				initialize(s);
				break;
			case 2:
				
				dispstack(s);
				
				break;
			case 3:
				
				
				printf("\nEnter value:");
				scanf("%d",&v);
				push(s,v);
				break;
			case 4:
				
				r=pop(s);
				printf("\n%d is popped",r);
				
				break;
			case 5:
				
				r=peek(s);
				printf("\n%d is at top of he stack",r);
				
				break;
			case 6:
				
				
				printf("\nEnter infix expression:");
				scanf("%d",inf);
				infixToPostfix(inf,s);
				
				break;
			case 7:
				
				
				printf("\nEnter postfix expression:");
				scanf("%d",post);
				val=evalpost(post,s);
				printf("Value of postfix exp:%d",val);
				
				break;
			case 8:
				printf("good bye");
				break;
		}
	}while(choice!=8);
	return(1);
}


