#include<stdio.h>
#include<conio.h>
struct Node *ToS=NULL;
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
void push(int value)
{
	Node *ptr=(Node *) malloc(sizeof(Node));
	ptr->data=value;
	if(ToS==NULL) ptr->next=NULL;
	else ptr->next=ToS;
	ToS=ptr;
}
int pop()
{
	Node *ptr;
	int x;
	if(ToS==NULL)
	{
		printf("Underflow\n");
		return-1;
	}
	x=ToS->data;
	ptr=ToS;
	ToS=ToS->next;
	free(ptr);
	return x;
}
int peek()
{
	if(ToS==NULL)
	{
		printf("Stack is empty\n");
		return -1;
	}
	return ToS->data;
}
void display()
{
	Node *ptr=ToS;
	if(ToS==NULL) printf("Stack is empty\n");
	else
	{
		printf("Stack contains:\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;
		}
	}
}
void main()
{
	int value,choice;
	clrscr();
	do
	{
		printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value:");
			scanf("%d",&value);
			push(value);
			break;
			case 2:value=pop();
			if(value!=-1) printf("Removed %d from the stack\n",value);
			break;
			case 3:value=peek();
			if(value!=-1) printf("Top of stack has %d",value);
			break;
			case 4:display();
			break;
			case 5:break;
			default:printf("Invalid choice\n");
		}
	}while(choice!=5);
	getch();
}