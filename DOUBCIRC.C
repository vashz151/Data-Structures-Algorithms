#include<stdio.h>
#include<conio.h>
typedef struct Node
{
	struct Node *prev,*next;
	int data;
}Node;
Node *insertBeg(Node *start, int value)
{
	Node *ptr;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	if(start==NULL)
	{
		ptr->next=ptr->prev=ptr;
		return ptr;
	}
	ptr->next=start;
	ptr->prev=start->prev;
	start->prev=ptr;
	ptr->prev->next=ptr;
	return ptr;
}
Node *insertEnd(Node *start,int value)
{
	Node *ptr,*p;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	if(start==NULL)
	{
		ptr->next=ptr->prev=ptr;
		return ptr;
	}
	p=start->prev;
	p->next=ptr;
	ptr->prev=p;
	ptr->next =start;
	start->prev=ptr;
	return start;
}
void insertAfter(Node *start,int value,int after)
{
	Node *ptr,*p;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	p=start;
	while(p->data!=after)
	{
		p=p->next;
	}
	ptr->next=p->next;
	ptr->prev=p;
	p->next=ptr;
	p=ptr->next;
	p->prev=ptr;
}
void insertBefore(Node *start,int value,int before)
{
	Node *ptr,*p;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	p=start;
	while(p->data!=before)
	{
		p=p->next;
	}
	ptr->next=p;
	ptr->prev=p->prev;
	p->prev=ptr;
	p=ptr->prev;
	p->next=ptr;
}
void insertSorted(Node *start,int value)
{
	Node *ptr,*p;
	ptr=(Node *)malloc(sizeof(Node));
	ptr->data=value;
	p=start;
	while(p->data<value && p->next!=NULL)
	{
		p=p->next;
	}
        if(p->data<=value) start=insertEnd(start,value);
	else
        {
            ptr->next=p;
	    ptr->prev=p->prev;
	    p->prev=ptr;
	    p=ptr->prev;
	    p->next=ptr;
        }
}
Node *deleteBeg(Node *start)
{
	Node *ptr;
	if(start==NULL)
	{
		printf("Underflow\n");
		return NULL;
	}
	if(start->next==start)
	{
		free(start);
		return NULL;
	}
	ptr=start->next;
	ptr->prev=start->prev;
	ptr->prev->next=ptr;
	free(start);
	return ptr;
}
Node *deleteEnd(Node *start)
{
	Node *ptr;
	if(start==NULL)
	{
		printf("Underflow\n");
		return NULL;
	}
	if(start->next==start)
	{
		free(start);
		return NULL;
	}
	ptr=start->prev;
	ptr->prev->next=start;
	start->prev=ptr->prev;
	free(ptr);
	return start;
}
Node *deleteAfter(Node *start, int after)
{
	Node *ptr,*p;
	if(start==NULL)
	{
		printf("Underflow\n");
		return NULL;
	}
	ptr=start;
	while(ptr->data!=after)
	{
		ptr=ptr->next;
	}
	p=ptr->next;
	ptr->next=p->next;
	p->next->prev=ptr;
	free(p);
	return start;
}
Node *deleteBefore(Node *start,int before)
{
	Node *ptr,*p;
	if(start==NULL)
	{
		printf("Underflow\n");
		return NULL;
	}
	while(ptr->data!=before)
	{
		ptr=ptr->next;
	}
	p=ptr->prev;
	p->prev->next=ptr;
	ptr->prev=p->prev;
	free(p);
	return start;
}
int getEle(Node *p,int posi)
{
	int i=1;
	while(i<posi)
	{
		p=p->next;
		i++;
	}
	return p->data;
}
int getPosi(Node *p,int ele)
{
	int i=1;
	while(p->data!=ele)
	{
		p=p->next;
		i++;
	}
	return i;
}
void display(Node *p,Node *start)
{
	printf("%d\n",p->data);
	if(p->next!=start) display(p->next,start);
}
void main()
{
	Node *start=NULL;
	int choice,value,posi,value1;
	clrscr();
	do
	{
		printf("1.Insert at the beginning\n2.Insert at the end\n3.Insert after a particular element\n4.Insert before an element\n5.Insert in sorted list\n6.Delete first node\n7.Delete last node\n8.Delete node after\n9.Delete node before\n10.Get element at location\n11.Get element's position\n12.Display all elements\n13.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value:");
			scanf("%d",&value);
			start=insertBeg(start,value);
			break;
			case 2:printf("Enter the value:");
			scanf("%d",&value);
			start=insertEnd(start,value);
			break;
			case 3:printf("Enter the value:");
			scanf("%d",&value);
			printf("Enter the value after which it is to be inserted:");
			scanf("%d",&value1);
			insertAfter(start,value,value1);
			break;
			case 4:printf("Enter the value:");
			scanf("%d",&value);
			printf("Enter the value before which it is to be inserted:");
			scanf("%d",&value1);
			insertBefore(start,value,value1);
			break;
			case 5:printf("Enter the value:");
			scanf("%d",&value);
			insertSorted(start,value);
			break;
			case 6:start=deleteBeg(start);
			break;
			case 7:start=deleteEnd(start);
			break;
			case 8:printf("Enter the value after which the element is to be deleted:");
			scanf("%d",&value);
			start=deleteAfter(start,value);
			break;
			case 9:printf("Enter the value before which the element is to be deleted:");
			scanf("%d",&value);
			start=deleteBefore(start,value);
			break;
			case 10:printf("Enter the position:");
			scanf("%d",&posi);
			value=getEle(start,posi);
			printf("Element at given position:%d\n",value);
			break;
			case 11:printf("Enter the element to search:");
			scanf("%d",&value);
			posi=getPosi(start,value);
			printf("Element found at position:%d\n",posi);
			break;
			case 12:if(start==NULL) printf("List is empty\n");
			else display(start,start);
			break;
			case 13:break;
			default:printf("Invalid choice\n");
		}
	}while(choice!=13);

	getch();
}