#include<stdio.h>
#include<conio.h>

#define MAX 5

int front=-1,rear=-1;

void insert(int queue[MAX],int value)
{
	if(rear==MAX-1 && front==0)
	{
		printf("Queue Overflow\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=value;
	}
	else if(rear==MAX-1 && front!=0)
	{
		rear=0;
		queue[rear]=value;
	}
	else
	{
		rear++;
		if (rear==front)
		{
			printf("Queue Overflow\n");
			rear--;
		}
		else
		queue[rear]=value;
	}
}
int delete(int queue[MAX])
{
	int x;
	if(front==-1)
	{
		printf("Queue Underflow\n");
		return -1;
	}
	else
	{
		x=queue[front];
		if (front==rear)
		front=rear=-1;
		else if(front==MAX-1)
		front=0;
		else front++;
		return (x);
	}
}
int peek(int queue[MAX])
{
	if(front==-1)
	{
		printf("Queue is empty\n");
		return -1;
	}
	else
	return(queue[front]);
}
void display(int queue[MAX])
{
	int i;
	if (front==-1) printf("Queue is empty\n");
	else if(front<=rear)
	{
		printf("Queue contains:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
	else
	{
		printf("Queue contains:\n");
		for(i=front;i<=MAX-1;i++)
		{
			printf("%d\n",queue[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}

}
int main()
{
	int queue[MAX],value,choice;
	//clrscr();
	do
	{
		printf("1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value to be inserted:");
			scanf("%d",&value);
			insert(queue,value);
			break;
			case 2:value=delete(queue);
			if(value!=-1)
			printf("%d deleted from the queue\n",value);
			break;
			case 3:value=peek(queue);
			if(value!=-1)
			printf("Front of queue has:%d\n",value);
			break;
			case 4:display(queue);
			break;
			case 5:break;
			default:printf("Invalid choice");
		}
	}while(choice!=5);
	getch();
}