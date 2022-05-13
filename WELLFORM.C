#include<stdio.h>
#include<conio.h>
#define MAX 20
int ToS=-1;
char pop(char stack[MAX])
{
	if(ToS==-1) return -1;
	return(stack[ToS--]);
}
void push(char stack[MAX],char value)
{
	if(ToS==MAX-1) printf("Stack Overflow");
	else stack[++ToS]=value;
}
void main()
{
	char stack[MAX],expr[100];
	int i=0,check;
	clrscr();
	printf("Enter the expression:");
	gets(expr);
	while(expr[i]!=0)
	{
		if(expr[i]=='(') push(stack,'(');
		else if(expr[i]==')')
		{
			check=pop(stack);
			if(check==-1)
			{
				printf("Not well-formed expression");
				exit(0);
			}
		}
		i++;
	}
	if(pop(stack)!=-1) printf("Not well-formed expression");
	else printf("Well-formed expression");
	getch();
}