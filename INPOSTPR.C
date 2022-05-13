#include<stdio.h>
#include<conio.h>
#include<math.h>
int ToS=-1;
int prec(char x)
{
	if(x=='(' || x==')') return 4;
	if(x=='^') return 3;
	if(x=='*' || x=='/' || x=='%') return 2;
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
char peek(char stack[],int MAX)
{
	if(ToS==-1)
	{
		return -1;
	}
	else
	return(stack[ToS]);
}
void display(char stack[], int MAX)
{
	int i;
	printf("Stack contains:\n");
	for(i=ToS;i>=0;i--)
	{
		printf("%d\n",stack[i]);
	}
	if(ToS==-1) printf("Stack is empty\n");
}
char evaluate(char n1,char n2,char op)
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
	char stack[20],op1,op2,ans;
	int i=0;
	ToS=-1;
	while(postfix[i]!=0)
	{
		if(postfix[i]>='0' && postfix[i]<='9')
		push(stack,postfix[i]-'0',20);
		else
		{
			op1=pop(stack,20);
			op2=pop(stack,20);
			ans=evaluate(op2,op1,postfix[i]);
			push(stack,ans,20);
		}
		i++;
	}
	printf("Answer=%d",pop(stack,20));
}
void evaluatePrefix(char prefix[])
{
	char stack[20],op1,op2,ans;
	int i=0;
	ToS=-1;
	while(prefix[i]!=0)
	{
		i++;
	}
	i--;
	while(i>=0)
	{
		if(prefix[i]>='0' && prefix[i]<='9')
		push(stack,prefix[i]-'0',20);
		else
		{
			op1=pop(stack,20);
			op2=pop(stack,20);
			ans=evaluate(op1,op2,prefix[i]);
			push(stack,ans,20);
		}
		i--;
	}
	printf("Answer=%d",pop(stack,20));
}
int main()
{
	int value,choice,i,MAX=20,j=0,k=0,l;
	char infix[100],x,temp,postfix[100],*stack;
	stack=(char*) malloc(MAX);
	printf("Enter the infix expression:");
	gets(infix);
	printf("1.Postfix\n2.Prefix\nEnter your choice:");
	scanf("%d",&choice);
	if(choice==2)
	{
		l=0;
		while(infix[l]!=0)
		{
			if(infix[l]=='(') infix[l]=')';
			else if(infix[l]==')') infix[l]='(';
			l++;

		}
		for(i=0;i<=(l-1)/2;i++)
		{
			temp=infix[i];
			infix[i]=infix[l-i-1];
			infix[l-i-1]=temp;
		}
	}
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
			x=pop(stack,MAX);
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
			if(choice==1)
			{
				if(assoc(infix[j]))
				{
					postfix[k++]=pop(stack,MAX);
					push(stack,infix[j],MAX);
				}
				else push(stack,infix[j],MAX);
			}
			else
			{
				if(!assoc(infix[j]))
				{
					postfix[k++]=pop(stack,MAX);
					push(stack,infix[j],MAX);
				}
				else push(stack,infix[j],MAX);
			}
		}
		j++;
	}
	while(peek(stack,MAX)!=-1)
	{
		postfix[k++]=pop(stack,MAX);
	}
	postfix[k]=0;
	if(choice==1)
	{
		printf("Postfix format:%s\n",postfix);
		evaluatePostfix(postfix);
	}
	else
	{
		l=0;
		while(postfix[l]!=0)
		{
			l++;

		}
		for(i=0;i<=(l-1)/2;i++)
		{
			temp=postfix[i];
			postfix[i]=postfix[l-i-1];
			postfix[l-i-1]=temp;
		}
		printf("Prefix format:%s\n",postfix);
		evaluatePrefix(postfix);
	}
}