#include<stdio.h>
#include<conio.h>
typedef struct Node
{
	int x;
	struct Node *next;
}Node;
Node* add(Node *start, int val,int pos)
{
	Node *p,*temp;
	int i;
	p=(Node *)malloc(sizeof(Node));
	p->x=val;
	if(pos==1)
	{
		p->next = start;
		return p;
	}
	else
	{
		temp=start;
		for(i=1;i<=pos-2;i++)
		{
			temp=temp -> next;
		}
		p->next=temp->next;
		temp ->next = p;
		return start;
	}
}
Node* rem(Node *start,int pos)
{
	Node *p=start,*temp;
	int i;
	if(pos==1)
	{
		temp=p->next;
		free(p);
		return(temp);
	}
	for(i=1;i<=pos-2;i++)
	{
		p=p->next;
	}
	temp=p->next;
	p->next=temp->next;
	free(temp);
	return start;
}
int get(Node *start,int pos)
{
	int i;
	Node *p=start;
	for(i=1;i<=pos-1;i++)
	{
		p=p->next;
	}
	return(p->x);
}
void display(Node *start)
{
	Node *p=start;
	printf("Contents of list are:\n");
	while(p!=NULL)
	{
		printf("%d\n",p->x);
		p=p->next;
	}
}
void main()
{
	int n=0,val,pos,choice,choice1;
	Node *start=NULL;
	clrscr();
	do
	{
		printf("1.Add\n2.Remove\n3.Get\n4.Display\n5.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter the value:");
			scanf("%d",&val);
			printf("1.Add at start\n2.Add at end\n3.Add at given position\nEnter your choice:");
			scanf("%d",&choice1);
			switch(choice1)
			{
				case 1:n++;
				start=add(start,val,1);
				break;
				case 2:n++;
				start=add(start,val,n);
				break;
				case 3:printf("Enter the position:");
				scanf("%d",&pos);
				if(pos<=n+1 && pos>0)
				{
					start=add(start,val,pos);
					n++;
				}
				else printf("Out of range\n");
				break;
				default:printf("Invalid choice\n");
			}
			break;
			case 2:printf("1.Remove from start\n2.Remove from end\n3.Remove from given position\nEnter your choice:");
			scanf("%d",&choice1);
			switch(choice1)
			{
				case 1:start=rem(start,1);
				n--;
				break;
				case 2:start=rem(start,n);
				n--;
				break;
				case 3:printf("Enter the position:");
				scanf("%d",&pos);
				if(pos<=n && pos>0)
				{
					start=rem(start,pos);
					n--;
				}
				else printf("Out of range\n");
				break;
				default:printf("Invalid choice\n");
			}
			break;
			case 3:printf("Enter the position:");
			scanf("%d",&pos);
			if(pos<=n && pos>0)
			{
				val=get(start,pos);
				printf("Value at position %d is %d\n",pos,val);
			}
			else printf("Out of Range\n");
			break;
			case 4:if(n>0) display(start);
			else printf("List is empty\n");
			break;
			case 5:break;
			default:printf("Invalid choice\n");
		}
	}while(choice!=5);
	getch();
}