#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct stack
{
	int data;
	struct stack *next;
};
struct stack*top=NULL;
void insert (int);
void display();
int del();
void loc_insert(int,int);
int main ()
{
	int num,choice,m,num1,loc;
	do
	{
		printf("Enter 1 for insertion\n");
		printf("Enter 2 for display\n");
		printf("Enter 3 for delete\n");
		printf("Enter 4 for break\n ");
		printf("Enter 5 for location insert\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("Enter the number\n");
			scanf("%d",&num);
			insert(num);
			break;
			case 2:
			display();
			break;
			case 3:
			m=del();
			printf("The deleted element is %d\n",m);
			break;
			case 4:
			break;
			case 5:
			printf("Enter the number you want to add\n");
			scanf("%d",&m);
			printf("Enter the location\n");
			scanf("%d",&loc);
			loc_insert(m,loc);
			break;
			default:
			printf("Enter valid number between 1 to 4\n");
		}
	}while(choice!=4);
getch();
return 0;
}

void insert( int x)
{
	struct stack *q;
	q= (struct stack*)malloc(sizeof(struct stack));
	q->data=x;
	q->next= NULL;

	if(top==NULL)
	{
		top=q;
	}
	else
	{	q->next=top;
		top=q;
	}
}

void display()
{
	struct stack *q;
	q=(struct stack*)malloc(sizeof(struct stack));
	 if(top==NULL)
	 {
		printf("Stack is empty\n");
	 }
	 else
	 {
		 q=top;
		 while(q!=NULL)
		 {
			printf("%d\n",q->data);
			q=q->next;
		 }
	 }
}

int del()
{
       int m;
	struct stack *q;
	q=(struct stack*)malloc(sizeof(struct stack));
	if(top==NULL)
	{
		printf("Stack is empty\n");
		return 0;
	}
	else
	{
		q=top;
		m = q->data;
		top=top->next;
		q->next=NULL;
		free(q);
		return(m);
	}
}

 void loc_insert(int x, int loc)
{
	int count=0,p=0;
	struct stack*q;
	q=(struct stack*)malloc(sizeof(struct stack));
	struct stack *m;
	m=(struct stack*)malloc(sizeof(struct stack));

	q=top;
	while(q!=NULL)
	{
		count++;
		q=q->next;
	}
	if(loc==1)
	{
		//struct stack *m;
		//m=(struct stack*)malloc(sizeof(struct stack));
		m->data=x;
		m->next=NULL;
		m->next=top;
		top=m;
	}
	else if(loc==count+1)
	{
	       struct stack *m;
		m=(struct stack*)malloc(sizeof(struct stack));
		m->data=x;
		m->next=NULL;
			q=top;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			q->next=m;
	}
	else if(loc>1&&loc<=count)
	{
		struct stack *m;
		m=(struct stack*)malloc(sizeof(struct stack));
		m->data=x;
		m->next=NULL;
		q= top;
		while(q!=NULL)
		{
			p++;
			if(p==loc-1)
			{
				break;
			}
			q=q->next;
		}
		m->next= q->next;
		q->next=m;
	}
	else
	{
		printf("Invalid locations\n");
	}
}