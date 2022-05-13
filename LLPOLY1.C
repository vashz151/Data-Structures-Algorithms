#include<stdio.h>
#include<conio.h>
typedef struct poly
{
	int pow;
	float coeff;
	struct poly *next;
}poly;
poly *create(int n)
{
	poly *p,*ptr;//*p for traversing and *ptr to point to first node
	int i;
	float temp;
	if(n==0)return NULL;
	printf("please enter powers in sorted way:\n");
	p=ptr=(poly *)malloc(sizeof(poly));
	printf("Enter the coefficients and the power:\n");
	scanf("%f%d",&temp,&p->pow);
	p->coeff=temp;
	p->next=NULL;
	for(i=2;i<=n;i++)
	{
		p->next=(poly *)malloc(sizeof(poly));
		p=p->next;
		printf("Enter the coefficient and power:\n");
		scanf("%f%d",&temp,&p->pow);
		p->coeff=temp;
		p->next=NULL;
	}
	return ptr;
}
poly *add(poly *p1, poly *p2)
{
	poly *r,*p;//*r is to create nodes of sum equation and *p
				//*p is for traversin the sum equation
	p=NULL;
	while(p1!=NULL&&p2!=NULL)
	{
		//creation of nodes
		if(p==NULL)
		{
			p=r=(poly *)malloc(sizeof(poly));
			r->next=NULL;
		}
		else
		{
			r->next=(poly *)malloc(sizeof(poly));
			r=r->next;
			r->next=NULL;
		}
		if(p1->pow>p2->pow)
		{
			r->pow=p1->pow;
			r->coeff=p1->coeff;
			p1=p1->next;
		}
		else if(p2->pow>p1->pow)
		{
			r->pow=p2->pow;
			r->coeff=p2->coeff;
			p2=p2->next;
		}
		else
		{
			r->pow=p1->pow;
			r->coeff=p1->coeff+p2->coeff;
			p1=p1->next;
			p2=p2->next;
		}
	}
	while(p1!=NULL)
	{
		if(p==NULL)
		{
			p=r=(poly *)malloc(sizeof(poly));
			r->next=NULL;
		}
		else
		{
			r->next=(poly *)malloc(sizeof(poly));
			r=r->next;
			r->next=NULL;
		}
		r->pow=p1->pow;
		r->coeff=p1->coeff;
		p1=p1->next;
	}
	while(p2!=NULL)
	{
		if(p==NULL)
		{
			p=r=(poly *)malloc(sizeof(poly));
			r->next=NULL;
		}
		else
		{
			r->next=(poly *)malloc(sizeof(poly));
			r=r->next;
			r->next=NULL;
		}
		r->pow=p2->pow;
		r->coeff=p2->coeff;
		p2=p2->next;
	}
	return p;
}
poly *mul(poly *p1, poly *p2, poly *start)
{
	poly *p,*r;
	p=NULL;
	while(p1!=NULL)
	{
		while(p2!=NULL)
		{
			if(p==NULL)
			{
				p=r=(poly *)malloc(sizeof(poly));
				r->next=NULL;
			}
			else
			{
				r->next=(poly *)malloc(sizeof(poly));
				r=r->next;
				r->next=NULL;
			}

			r->pow=p1->pow + p2->pow;
			r->coeff=p1->coeff * p2->coeff;
			p2=p2->next;
		}
		p2=start;
		p1=p1->next;
	}
	return p;
}
poly *simplification(poly *start)
{
	poly *p,*p1,*p2,*dup;
	p1=p2=p=start;
	while(p1!=NULL&&p1->next!=NULL)
	{
		p2=p1;
		while(p2!=NULL)
		{
			if(p1->pow==p2->next->pow)
			{
				p1->coeff=p1->coeff+p2->next->coeff;
				dup=p2->next;
				p2->next=p2->next->next;
				free(dup);
			}
			else p2=p2->next;
		}
		p1=p1->next;
	}
	return p;
}

void display(poly *p)
{
	while(p!=NULL)
	{
		if(p>=0)printf("+%5.2fx^%d",p->coeff,p->pow);
		else printf("%5.2fx^%d",p->coeff,p->pow);
		p=p->next;
	}
}
void main()
{
	poly *p1, *p2, *p3,*p4, *temp;
	int n,ch;
	clrscr();
	do
	{
		printf("\n1-addition\n2-Multiplication\n3-Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter the number of terms in equation 1:");
			scanf("%d",&n);
			p1=create(n);
			printf("Enter the numeber of terms in equation 2:");
			scanf("%d",&n);
			p2=create(n);
			p3=add(p1,p2);
			printf("Eq1:\n");
			display(p1);
			printf("\nEq2:\n");
			display(p2);
			printf("\nSum:\n");
			display(p3);
			break;
			case 2:
			printf("Enter the number of terms in equation one:");
			scanf("%d",&n);
			p1=create(n);
			printf("Enter the number of terms in equation two:");
			scanf("%d",&n);
			temp=p2=create(n);
			p3=mul(p1,p2,temp);
			p4=simplification(p3);
			printf("(");
			display(p1);
			printf(")");
			printf("(");
			display(p2);
			printf(")");
			printf("\nAns:\n");
			display(p4);
			break;
			case 3:exit();
			default:printf("Wrong choice!");
		}
	}while(ch!=3);
	getch();
}
