#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
struct queue
{
	char str1[100];
	struct queue *next;
};
struct queue *front=NULL;
struct queue *rear=NULL;
void insert(char []);
void del(void);
void display(void);
int main(void)
{

	char str[100],str2[100];
	int choice,m;
	do
	{
		printf("press 1 for insert\n");
		printf("press 2 for del\n");
		printf("press 3 for display\n");
		printf("press 4 for break\n");
		printf("enter your choice = ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			printf("enter string = ");
			scanf("%s",str);
			insert(str);
			break;
			case 2:
			del();
			break;
			case 3:
			display();
			break;
			case 4:
			break;
			default:
			printf("enter number between 1 to 3 only\n");
		}
	}while(choice!=4);
getch();
return(0);
}
void insert(char str[100])
{
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	strcpy(q->str1,str);
	q->next=NULL;
	if(front==NULL)
	{
		front=rear=q;
	}
	else
	{
		rear->next=q;
		rear=q;
	}
}
void del(void)
{
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	if(front==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		q=front;
		printf("The deleted element is = %s\n",front->str1);
		front=front->next;
		q->next=NULL;
		strcpy(q->str1,NULL);
		free(q);
	}
}

void display(void)
{
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	if(front==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		q=front;
		while(q!=NULL)
		{
			printf("%s\n",q->str1);
			q=q->next;
		}
	}
}



