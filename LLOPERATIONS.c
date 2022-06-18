//Q1. Singly linked list with options: 
//Insert in end & front, remove a node before certain value and display the content of linked list.
#include<stdio.h>
#include<stdlib.h>
//using typedef 
typedef struct Node
{
	int data;
	struct Node *link;
}Node;
//used typedef so need of struct node
Node * create(int value)
{
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=value;
    newnode->link = NULL;
    return (newnode);
}
Node* insertBeg(Node *head, int value)
{
	Node *ptr=create(value);
	if(head==NULL)
	{
        head=ptr;
	}
    else
    {
	    ptr->link=head;
        head=ptr;
    }
    return head;
}
Node* insertEnd(Node *head, int value)
{
	Node *ptr=create(value),*p;
	if(head==NULL)
	{
		head=ptr;
	}
    else
    {
	    p=head;
	    while(p->link!=NULL)
	    {
		    p=p->link;
	    }
	    p->link=ptr;
    }
	return head;
}
Node *deleteBefore(Node *head,int before)
{
	Node *ptr,*p;
    ptr=head;
	if(head==NULL)
	{
		printf("Underflow\n");
		return NULL;
	}
	while(ptr->data!=before)
	{
		p=ptr;
        ptr=ptr->link;
        if(ptr==NULL)//not found case
        {
            printf("Element not found\n");
            return head;
        }
	}
    if(p==head) //delete beginning case
    {
        p=head->link;
        free (head);
        head=p;
    }
    else
    {
        p->link=ptr->link;
        free(ptr);
    }
    return head;
}
void display(Node *head)
{
	Node *p=head;
    printf("Contents of linked list are: ");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->link;
	}
}
void main()
{
	Node *head=NULL;
	int choice,value,before;
	do
	{
		printf("\n1.Insert at beginning\n2.Insert at end\n3.Delete before an element\n4.Display all elements\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter value:");
			scanf("%d",&value);
			head=insertBeg(head,value);
			break;
			case 2:printf("Enter value:");
			scanf("%d",&value);
			head=insertEnd(head,value);
			break;
			case 3:printf("Enter the value before which the element is to be deleted:");
			scanf("%d",&before);
			head=deleteBefore(head,before);
			break;
			case 4:if(head!=NULL) display(head);
			else printf("Empty list\n");
			break;
			case 5:
            break;
			default:printf("Invalid choice\n");
		}
	}while(choice!=5);
}