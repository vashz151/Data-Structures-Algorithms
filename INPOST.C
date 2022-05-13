#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<ctype.h>
int ToS=-1;
int prec(char x)
{
	if(x=='(' || x==')') return 4;
	if(x=='^') return 3;
	if(x=='*' || x=='/') return 2;
	return 1;
}
int assoc(char x)
{
	if(x=='^') return 0;
	return 1;
}
void push(char stack[],char value,int MAX)
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
void pushh(float stack[],float value,int MAX)
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
char pop(char stack[],int MAX)
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
float popp(float stack[],int MAX)
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
char peek(char stack[],int MAX)
{
	if(ToS==-1)
	{
		return -1;
	}
	else
	return(stack[ToS]);
}
float evaluate(float n1,float n2,char op)
{
	switch(op)
	{
		case '*':return(n1*n2);
		case '/':return(n1/n2);
		case '+':return(n1+n2);
		case '-':return(n1-n2);
		case '^':return(pow(n1,n2));
	}
}
void evaluatePostfix(char postfix[])
{
	float ans,op1,op2;
	int i=0,j=0;
	float stack[20],x[20];
	ToS=-1;
	while(postfix[j]!=0)
	{
		if(isalpha(postfix[j]))
		{
			printf("Enter value of %c:",postfix[j]);
			scanf("%f",&x[j]);
			pushh(stack,x[j],20);
		}
		else if(isdigit(postfix[j]))
		{
			pushh(stack,postfix[j]-'0',20);
		}
		else
		{
			op1=popp(stack,20);
			op2=popp(stack,20);
			ans=evaluate(op2,op1,postfix[j]);
			pushh(stack,ans,20);
		}
		j++;
	}
	printf("Answer=%f\n",popp(stack,20));
}
void infix_postfix(char infix[],char stack[],int MAX)
{
 	int value,i,j=0,k=0;
	char postfix[100];
        while(infix[j]!=0)
	{
		if(infix[j]!='(' && infix[j]!=')' && infix[j]!='*' && infix[j]!='/' && infix[j]!='%' && infix[j]!='^' && infix[j]!='+' && infix[j]!='-')
		postfix[k++]=infix[j];
		else if(peek(stack,MAX)==-1 || peek(stack,MAX)=='(')
		push(stack,infix[j],MAX);
		else if(infix[j]=='(') push(stack,'(',MAX);
		else if(infix[j]==')')
		{
			while(peek(stack,MAX)!='(')
			{
				postfix[k++]=pop(stack,MAX);
			}
			pop(stack,MAX);
		}
		else if(prec(infix[j])>prec(peek(stack,MAX)))
		{
			push(stack,infix[j],MAX);
		}
		else if(prec(infix[j])<prec(peek(stack,MAX)))
		{
			postfix[k++]=pop(stack,MAX);
			if(peek(stack,MAX)!=-1) continue;
			push(stack,infix[j],MAX);
		}
		else
		{
			if(assoc(infix[j]))
			{
				postfix[k++]=pop(stack,MAX);
				push(stack,infix[j],MAX);
			}
			else push(stack,infix[j],MAX);
		}
		j++;
	}
	while(peek(stack,MAX)!=-1)
	{
		postfix[k++]=pop(stack,MAX);
	}
	postfix[k]=0;
	printf("Postfix format:%s\n",postfix);
	evaluatePostfix(postfix);
}
int main()
{
	int MAX=20;
	char infix[100],*stack;
	stack=(char*) malloc(MAX);
	printf("Enter the infix expression:");
	gets(infix);
    infix_postfix(infix,stack,MAX);
}