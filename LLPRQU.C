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
void insert(Queue *q,int value)
{
	Node *p,*p1;
	Node *ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	if(q->front==NULL)
	{
		q->front=q->rear=ptr;
		q->front->next=q->rear->next=NULL;
	}
	else
	{
		p1=p=q->front;
		if(p->data>value)
		{
			ptr->next=p;
			q->front=ptr;
		}
		else
		{
			while(p->data<value && p!=NULL)
			{
				p1=p;
				p=p->next;
			}
			ptr->next=p1->next;
			p1->next=ptr;
                        q->rear=ptr;

		}
	}
}
int delete(Queue *q)
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
		printf("1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value to be inserted:");
			scanf("%d",&value);
			insert(q,value);
			break;
			case 2:value=delete(q);
			if(value!=-1) printf("Deleted %d from queue\n",value);
			break;
			case 3:value=peek(q);
			if(value!=-1) printf("Element at front of queue is %d\n",value);
			break;
			case 4:display(q);
			break;
			case 5:
			break;
			default:printf("Invalid Choice\n");
		}
	}while(choice!=5);
	getch();
}