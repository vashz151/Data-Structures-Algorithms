#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1;
int w;
int isEmpty()
{
      if(front== -1 || front>rear)
      {
         return 1;
      }
      return 0;
}
int isFull()
{
    if(rear== w-1)
    {
        return 1;
    }
    return 0;
}
void enqueueR(int *dequeue,int value)
{
      if(!isFull())
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
      if(!isEmpty())
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
      if(!isEmpty())
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
    if(!isEmpty())
    {
        return(dequeue[front]);
    }
	else return 0;
}
void sliding(int *dequeue,int *a, int n, int w)
{
	int i;
    for(i=0;i<w;i++)
    {
         while(!isEmpty() && a[i]>=a[peek(dequeue)])
         {
            dequeueR(dequeue);
         }
         enqueueR(dequeue,i);
    }
    for(i=w;i<n;i++)
    {
         printf("%d ",a[peek(dequeue)]);
         while(!isEmpty() && peek(dequeue)<=i-w)
         {
            dequeueF(dequeue);
         }
         while(!isEmpty() && a[i]>=a[peek(dequeue)])
         {
            dequeueR(dequeue);
         }
         enqueueR(dequeue,i);
    }
    printf("%d ",a[peek(dequeue)]);
}
int main()
{
    int *dequeue,*a,n,i;
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
	sliding(dequeue,a,n,w);
    return 0;
}
