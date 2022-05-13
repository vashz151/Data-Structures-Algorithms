#include<stdio.h>
#include<conio.h>
struct Student
{
	char name[20];
	int roll;
	struct Student *ptr;
};
void main()
{
	struct Student s[10],*start;
	int i,n;
	clrscr();
	printf("Enter the number of students:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter name and roll number:");
		scanf("%s %d",&s[i].name,&s[i].roll);
		if(i==n-1) s[i].ptr=NULL;
		else s[i].ptr=&s[i+1];
	}
	start=&s[0];
	while(start!=NULL)
	{
		printf("Name=%s\tRoll number=%d\n",start->name,
		start->roll);
		start=start->ptr;
	}
	getch();
}