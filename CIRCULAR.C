#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}Node;
Node* insertBeg(Node *start, int value)
{
	Node *ptr,*p;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	if(start==NULL)
	{
		ptr->next=ptr;
		return ptr;
	}
	ptr->next=start;
	p=start;
	while(p->next!=start)
	{
		p=p->next;
	}
	p->next=ptr;
	return ptr;
}
Node* insertEnd(Node *start, int value)
{
	Node *ptr,*p;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	if(start==NULL)
	{
		ptr->next=ptr;
		return ptr;
	}
	p=start;
	while(p->next!=start)
	{
		p=p->next;
	}
	p->next=ptr;
	ptr->next=start;
	return start;
}
Node* deleteBeg(Node *start)
{
	Node *ptr=start;
	if(ptr->next==ptr)
	{
		free(ptr);
		return NULL;
	}
	while(ptr->next!=start)
	{
			ptr=ptr->next;
	}
	ptr->next=start->next;
	free(start);
	return ptr->next;
}
Node* deleteEnd(Node *start)
{
	Node *p,*ptr;
	p=ptr=start;
	if(ptr->next==ptr)
	{
		free(ptr);
		return NULL;
	}
	while(ptr->next!=start)
	{
		p=ptr;
		ptr=ptr->next;
	}
	p->next=start;
	free(ptr);
	return start;
}
void insertAfter(Node *start,int value,int after)
{
	Node *ptr,*p;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	p=start;
	while(p->data!=after && p->next!=start)
	{
		p=p->next;
	}
	ptr->next=p->next;
	p->next=ptr;
}
int getPosi(Node *start,Node *p,int x)
{
	if(p->data==x) return 1;
	if(p->next==start) return -100;
	return(1+getPosi(start,p->next,x));
}
void display(Node *start)
{
	Node *p=start;
	do
	{
		printf("%d\n",p->data);
		p=p->next;
	}while(p!=start);
}
void main()
{
	Node *start=NULL;
	int choice,value,posi,after;
	clrscr();
	do
	{
		printf("1.Insert at beginning\n2.Insert at end\n3.Delete first node\n4.Delete last node\n5.Get position of an element\n6.Display all elements\n7.Exit\n8.Enter after a node\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter value:");
			scanf("%d",&value);
			start=insertBeg(start,value);
			break;
			case 2:printf("Enter value:");
			scanf("%d",&value);
			start=insertEnd(start,value);
			break;
			case 8:printf("Enter value:");
			scanf("%d",&value);
			printf("Enter the value after which it is to be inserted:");
			scanf("%d",&after);
			insertAfter(start,value,after);
			break;
			case 3:start=deleteBeg(start);
			break;
			case 4:start=deleteEnd(start);
			break;
			case 5:printf("Enter the value:");
			scanf("%d",&value);
			posi=getPosi(start,start,value);
			if(posi<1) printf("Not found\n");
			else printf("Position is: %d\n",posi);
			break;
			case 6:if(start!=NULL) display(start);
			else printf("Empty list\n");
			break;
			case 7:break;
			default:printf("Invalid choice\n");
		}
	}while(choice!=7);
	getch();
}