#include<stdio.h>
#include<conio.h>
typedef struct poly
{
	int pow;
	float coeff;
	struct poly *next;
}poly;
poly* create(int n)
{
	int i;
	float temp;
	poly *p,*ptr;
	if(n==0) return NULL;
	p=ptr=(poly *)malloc(sizeof(poly));
	printf("Enter the coefficient and the power:");
	scanf("%f %d",&temp,&p->pow);
	p->coeff=temp;
	p->next=NULL;
	for(i=2;i<=n;i++)
	{
		p->next=(poly *)malloc(sizeof(poly));
		p=p->next;
		printf("Enter the coefficient and the power:");
		scanf("%f %d",&p->coeff,&p->pow);
		p->next=NULL;
	}
	return ptr;
}
poly* add(poly *p1,poly *p2)
{
	poly *p,*r;
	p=NULL;
	while(p1!=NULL && p2!=NULL)
	{
		if(p==NULL)
		{
			p=r=(poly *) malloc(sizeof(poly));
			r->next=NULL;
		}
		else
		{
			r->next=(poly *)malloc(sizeof(poly));
			r=r->next;
			r->next=NULL;
		}
		if(p1->pow<p2->pow)
		{
			r->pow=p1->pow;
			r->coeff=p1->coeff;
			p1=p1->next;
		}
		else if(p2->pow<p1->pow)
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
			p=r=(poly *) malloc(sizeof(poly));
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
			p=r=(poly *) malloc(sizeof(poly));
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
void display(poly *p)
{
	while(p!=NULL)
	{
		if(p->coeff>=0) printf("+%5.2fx^%d",p->coeff,p->pow);
		else printf("%5.2fx^%d",p->coeff,p->pow);
		p=p->next;
	}
}
void main()
{
	poly *p1,*p2,*p3;
	int n;
	clrscr();
	printf("Enter the number of terms in first polynomial:");
	scanf("%d",&n);
	p1=create(n);
	printf("Enter the number of terms in second polynomial:");
	scanf("%d",&n);
	p2=create(n);
	p3=add(p1,p2);
	printf("First polynomial:");
	display(p1);
	printf("\nSecond Polynomial:");
	display(p2);
	printf("\nSum Polynomial:");
	display(p3);
	getch();
}