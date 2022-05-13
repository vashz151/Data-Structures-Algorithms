#include<stdio.h>
#include<conio.h>
int ToS=-1;
void push(int stack[],int value,int MAX)
{
	if(ToS==MAX-1)
	{
		printf("Stack Overflow\n");
	}
	else
	{
		ToS++;
		stack[ToS]=value;
	}
}
int pop(int stack[],int MAX)
{
	if(ToS==-1)
	{
		printf("Stack Underflow\n");
		return -1;
	}
	else
	{
		return (stack[ToS--]);
	}
}
int peek(int stack[],int MAX)
{
	if(ToS==-1)
	{
		printf("Stack is empty\n");
		return -1;
	}
	else
	return(stack[ToS]);
}
void display(int stack[], int MAX)
{
	int i;
	printf("Stack contains:\n");
	for(i=ToS;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	if(ToS==-1) printf("Stack is empty\n");
}
void main()
{
	int *stack,value,choice,i,MAX;
	printf("Enter the size of stack:");
	scanf("%d",&MAX);
	stack=(int*) malloc(MAX*2);
	clrscr();
	do
	{
		printf("1.Push\n2.POP\n3.Peek\n4.Display()\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value to be pushed:");
			scanf("%d",&value);
			push(stack,value,MAX);
			break;
			case 2:value=pop(stack,MAX);
			if(value!=-1)
			printf("%d popped from top of stack\n",value);
			break;
			case 3:value=peek(stack,MAX);
			if(value!=-1)
			printf("Top of stack has:%d\n",value);
			break;
			case 4:display(stack,MAX);
			break;
			case 5:break;
			default:printf("Invalid choice");
		}
	}while(choice!=5);
	getch();
}