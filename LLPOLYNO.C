//VASHISTH ZATAKIA 60003200163
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct Node
{
      int coeff;
      int pow;
      struct Node *link;
}Node;
Node* simplification(Node *);
Node* create(int n)
{
      int i;
      Node *p,*ptr;
      if(n==0) return NULL;
      p=ptr=(Node *)malloc(sizeof(Node));
      printf("Enter coefficient and power:");
      scanf("%d %d",&p->coeff,&p->pow);
      p->link=NULL;
      for(i=2;i<=n;i++)
      {
	     p->link=(Node *)malloc(sizeof(Node));
	     p=p->link;
	     printf("Enter coefficients and power:");
	     scanf("%d %d",&p->coeff,&p->pow);
	     p->link=NULL;
      }
      return(ptr);
}
Node* add(Node *p1,Node *p2)
{
      Node *p,*r;
      p=NULL;
      while(p1!=NULL && p2!=NULL)
      {
	     if(p==NULL)
	     {
		    p=r=(Node *)malloc(sizeof(Node));
		    r->link=NULL;
	     }
	     else
	     {
		    r->link=(Node *) malloc(sizeof(Node));
		    r=r->link;
		    r->link=NULL;
	     }
	     if(p1->pow < p2->pow)
	     {
		    r->coeff=p1->coeff;
		    r->pow=p1->pow;
		    p1=p1->link;
	     }
	     else if(p1->pow > p2->pow)
	     {
		    r->coeff=p2->coeff;
		    r->pow=p2->pow;
		    p2=p2->link;
	     }
	     else
	     {
		    r->pow=p1->pow;
		    r->coeff=p1->coeff+p2->coeff;
		    p1=p1->link;
		    p2=p2->link;
	     }
      }
      while(p1!=NULL)//case when either p2 is null or p2 is over
      {
	     if(p==NULL)
	     {
		    p=r=(Node *)malloc(sizeof(Node));
		    r->link=NULL;
	     }
	     else
	     {
		    r->link=(Node *) malloc(sizeof(Node));
		    r=r->link;
		    r->link=NULL;
	     }
	     r->pow=p1->pow;
	     r->coeff=p1->coeff;
	     p1=p1->link;
      }
      while(p2!=NULL) //one case can be either p1 is null or p1 is completed
      {
	     if(p==NULL)
	     {
		    p=r=(Node *)malloc(sizeof(Node));
		    r->link=NULL;
	     }
	     else
	     {
		    r->link=(Node *) malloc(sizeof(Node));
		    r=r->link;
		    r->link=NULL;
	     }
	     r->pow=p2->pow;
	     r->coeff=p2->coeff;
	     p2=p2->link;
      }
      return p;
}
Node * sub(Node *p1,Node *p2, int n)
{
      Node *t,*s;
      if(n==1)
      {
	     s=p2;
	     s->link=p2->link;
      }
      if(n==2)
      {
	      s=p1;
	      s->link=p1->link;
      }
      while(s!=NULL)
      {
	     s->coeff=(s->coeff)*(-1);
	     s->pow=s->pow;
	     s=s->link;
      }
      if(n==1) t=add(p1,s);
      if(n==2) t=add(s,p2);
      t=add(p1,p2);
      return t;
}
Node* multiply(Node *p1,Node *p2,Node *ptr)
{
      Node *p,*r;
      p=NULL;
      while(p1!=NULL)
      {
	     while(p2!=NULL)
	     {
		    if(p==NULL)
		    {
			   p=r=(Node *)malloc(sizeof(Node));
			   r->link=NULL;
		    }
		    else
		    {
			   r->link=(Node *) malloc(sizeof(Node));
			   r=r->link;
			   r->link=NULL;
		    }
		    r->coeff=p1->coeff * p2->coeff;
		    r->pow=p1->pow+p2->pow;
		    p2=p2->link;
	     }
	     p2=ptr;
	     p1=p1->link;
      }
      p=simplification(p);
      return p;
}
Node *simplification(Node *ptr)
{
      Node *p,*p1,*p2,*temp;
      p=p1=p2=ptr;
      while(p1!=NULL)
      {
	     p2=p1;
	     while(p2!=NULL)
	     {
		    if(p1->pow==p2->link->pow)
		    {
			   p1->coeff=p1->coeff+p2->link->coeff;
			   temp=p2->link;
			   p2->link=p2->link->link;
			   free(temp);
		    }
		    else p2=p2->link;
	     }
	     p1=p1->link;
      }
      return p;
}
void traverse(Node *p)
{
      Node *head,*start;
      while(p->coeff==0 && p!=NULL)
      {
	     start=p;
	     p=p->link;
	     free(start);
      }
      head=p;
      while(p!=NULL)
      {
	     if(p->pow==0 && p->coeff!=0)
	     {
		    if(p->coeff>0 && p!=head) printf("+%d",p->coeff);
		    else printf("%d",p->coeff);
	     }
	     else if(p->pow==1 && p->coeff!=0)
	     {
		    if(p->coeff>1 && p!=head) printf("+%dx",p->coeff);
		    else if(p->coeff==1 && p!=head) printf("+x");
		    else if(p->coeff==1) printf("x");
		    else printf("%dx",p->coeff);
	     }
	     else if(p->coeff==1 && p->pow>1)
	     {
		    if(p!=head) printf("+x^%d",p->pow);
		    else printf("x^%d",p->pow);
	     }
	     else if(p->coeff>0 && p!=head) printf("+%dx^%d",p->coeff,p->pow);
	     else if(p->coeff==0 && p->pow>=0) printf("");
	     else printf("%dx^%d",p->coeff,p->pow);
	     p=p->link;
      }
}
void main()
{
      int choice=0,value,n;
      Node *p1,*p2,*p3,*p4,*p5,*temp;
      clrscr();
      printf("Terms of the polynomial needs to be entered in ascending order of power i.e smallest power term first:\n");
      printf("Enter the number of terms in first polynomial:");
      scanf("%d",&n);
      p1=create(n);
      printf("Enter the number of terms in second polynomial:");
      scanf("%d",&n);
      temp=p2=create(n);
      printf("First polynomial:");
      traverse(p1);
      printf("\nSecond Polynomial:");
      traverse(p2);
      while(choice!=4)
      {
	     printf("\n1.Add\n2.Sub\n3.Multiply\n4.Exit\n");
	     scanf("%d",&choice);
	     switch(choice)
	     {
		    case 1:p3=add(p1,p2);
		    printf("\nSum Polynomial:");
		    traverse(p3);
		    break;
		    case 2:printf("1.p1-p2\n2.p2-p1\nEnter your choice:");
		    scanf("%d",&value);
		    if(value==1 || value==2) p4=sub(p1,p2,value);
		    else printf("Invalid choice");
		    printf("\nAfter subtraction:\n");
		    traverse(p4);
		    break;
		    case 3:p5=multiply(p1,p2,temp);//passed p2 twice as we needed it to initialize back to orginal node
		    printf("After multiplication:");
		    traverse(p5);
		    break;
		    case 4:
		    break;
		    default:printf("Invalid choice");
	     }
      }
      getch();
}


