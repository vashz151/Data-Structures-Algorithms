#include<stdio.h>
#include<conio.h>
int front=-1,rear=-1;
int w;
void enqueueR(int *dequeue,int value)
{
      if(!isFull(dequeue))
      {
	     if(front==-1 && rear==-1)
	     {
		    front=rear=0;
		    dequeue[rear]=value;
	     }
	     else
	     {
		    rear++;
		    dequeue[rear]=value;
	     }
      }
}
void dequeueF(int *dequeue)
{
      if(!isEmpty(dequeue))
      {
	     if(front==rear)
	     {
		    front=rear=-1;
	     }
	     else front++;
      }
}
void dequeueR(int *dequeue)
{
      if(!isEmpty(dequeue))
      {
	     if(front==rear)
	     {
		    front=rear=-1;
	     }
	     else rear--;
      }
}
int peek(int *dequeue)
{
	if(!isEmpty(dequeue))
	{
	     return(dequeue[front]);
	}
	else -1;
}
int isEmpty(int *dequeue)
{
      if(front== -1 || front>rear)
      {
	     return 1;
      }
      return 0;
}
int isFull(int *dequeue)
{
	if(rear== w-1)
	{
		return 1;
	}
	return 0;
}
void main()
{
	int *dequeue,*a,c,i,n,j;
	clrscr();
	printf("Enter number of elements and window size:");
	scanf("%d %d",&n,&w);
	printf("Enter elements:");
	a=(int *) malloc(n* sizeof(int));
	dequeue=(int *)malloc(w* sizeof(int));
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	}
	printf("Maxium of each window are:");
	for(i=0;i<w;i++)
	{
	     while(!isEmpty(dequeue) && a[i]>=a[peek(dequeue)])
	     {
		    dequeueR(dequeue);
	     }
	     enqueueR(dequeue,i);
	}
	for(i=w;i<n;i++)
	{
	     printf("%d ",a[peek(dequeue)]);
	     while(!isEmpty(dequeue) && peek(dequeue)<=i-w)
	     {
		    dequeueF(dequeue);
	     }
	     while(!isEmpty(dequeue) && a[i]>=a[peek(dequeue)])
	     {
		    dequeueR(dequeue);
	     }
	     enqueueR(dequeue,i);
	}
	printf("%d ",a[peek(dequeue)]);
	getch();
}