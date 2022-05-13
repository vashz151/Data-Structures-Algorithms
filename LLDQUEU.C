#include<stdio.h>
#include<conio.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
typedef struct Queue
{
	struct Node *front;
	struct Node *rear;
}Queue;
void insertRight(Queue *q,int value)
{
	Node *ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	if(q->front==NULL)
	{
		q->front=q->rear=ptr;
		q->front->next=q->rear->next=NULL;
	}
	else
	{
		q->rear->next=ptr;
		ptr->next=NULL;
		q->rear=ptr;
	}
}
void insertLeft(Queue *q,int value)
{
	Node *ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	if(q->front==NULL)
	{
		q->front=q->rear=ptr;
		q->front->next=q->rear->next=NULL;
	}
	else
	{
		ptr->next=q->front;;
		q->front=ptr;
	}
}
int deleteLeft(Queue *q)
{
	int x;
	Node *ptr;
	if(q->front==NULL)
	{
		printf("Underflow\n");
		return -1;
	}
	x=q->front->data;
	ptr=q->front;
	q->front=q->front->next;
	if(q->front==NULL) q->rear=NULL;
	free (ptr);
	return x;
}
int deleteRight(Queue *q)
{
	int x;
	Node *ptr;
	if(q->front==NULL)
	{
		printf("Underflow\n");
		return -1;
	}
	x=q->rear->data;
	ptr=q->rear;
	q->rear=q->front;
	while(q->rear->next!=ptr)
	{
		q->rear=q->rear->next;
	}
	q->rear->next=NULL;
	free (ptr);
	return x;
}
int peek(Queue *q)
{
	int x;
	if(q->front==NULL)
	{
		printf("Queue is empty\n");
		return -1;
	}
	x=q->front->data;
	return x;
}
void display(Queue *q)
{
	int x;
	Node *ptr=q->front;
	if(q->front==NULL)
	{
		printf("Queue is empty\n");
	}
	else
	{
		printf("Queue contains:\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}
void main()
{
	Queue *q;
	int choice, value;
	clrscr();
	q->front=q->rear=NULL;
	do
	{
		printf("1.Insert Right\n2.Insert Left\n3.Delete Left\n4.Delete Right\n5.Peek\n6.Display\n7.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value to be inserted:");
			scanf("%d",&value);
			insertRight(q,value);
			break;
			case 2:printf("Enter the value to be inserted:");
			scanf("%d",&value);
			insertLeft(q,value);
			break;
			case 3:value=deleteLeft(q);
			if(value!=-1) printf("Deleted %d from queue\n",value);
			break;
			case 4:value=deleteRight(q);
			if(value!=-1) printf("Deleted %d from queue\n",value);
			break;
			case 5:value=peek(q);
			if(value!=-1) printf("Element at front of queue is %d\n",value);
			break;
			case 6:display(q);
			break;
			case 7:
			break;
			default:printf("Invalid Choice\n");
		}
	}while(choice!=7);
	getch();
}