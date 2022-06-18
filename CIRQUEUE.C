//Q. Implement Circular Queue and perform enqueue and dequeue operations.
#include <stdio.h>
#define SIZE 3
int cirqueue[SIZE];
int front=-1, rear=-1;

// Check if the queue is full
int isFull() 
{
    if ((front==rear+1) || (front==0 && rear==SIZE-1)) return 1;
    return 0;
}

// Check if the queue is empty
int isEmpty() 
{
    if (front==-1 && rear==-1) return 1;
    return 0;
}

// Adding an element
void enQueue(int value) 
{
    if (isFull()==1)
    {
        printf("Circular Queue is full!! \n");
    }
    else
    {
        if(isEmpty()==1)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%SIZE;
        }
        cirqueue[rear]=value;
        printf("Inserted %d in circular queue\n", value);
    }
}

// Removing an element
int deQueue() 
{
    int value;
    if (isEmpty())
    {
        printf("Circular Queue is empty\n");
        return -1;
    }
    else 
    {
        value=cirqueue[front];
        if (front==rear)
        {
            front=-1;
            rear=-1;
        } 
        else 
        {
            front=(front+1)%SIZE;
        }
        printf("Deleted element %d from circular queue \n",value);
        return (value);
    }
}

// Display the queue
void display() 
{
    int i;
    if (isEmpty())
    {
        printf("Circular Queue is empty\n");
    }
    else 
    {
        printf("Circular queue contains-> ");
        for (i=front; i!= rear;i=(i+1)%SIZE) 
        {
            printf("%d ",cirqueue[i]);
        }
        printf("%d\n",cirqueue[i]); //to print rear
    }
}

int main() 
{
    int choice,value; 
    do
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value to be inserted:");
			scanf("%d",&value);
			enQueue(value);
			break;
			case 2:value=deQueue();
			break;
			case 3:display();
			break;
			case 4:break;
			default:printf("Invalid choice");
		}
	}while(choice!=4);
    return 0;
}