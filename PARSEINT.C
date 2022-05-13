#include<stdio.h>
#include<conio.h>
void main()
{
	char a[5];
	int i=0,ans=0;
	clrscr();
	printf("Enter a number:");
	gets(a);
	while(a[i]!=0)
	{
		ans=ans*10+a[i]-'0';
		i++;
	}
	printf("Number entered is:%d",ans);
	getch();
}