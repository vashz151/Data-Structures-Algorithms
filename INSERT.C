#include<stdio.h>
#include<conio.h>
#define MAX 1000
int insert(int a[MAX],int n,int value,int index)
{
	int i;
	for(i=n-1;i>=index;i--)
	{
		a[i+1]=a[i];
	}
	a[index]=value;
	return (n+1);
}
void main()
{
	int a[MAX],i,value,index,choice,n;
	clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	printf("The array elements are:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("Enter element to insert:");
	scanf("%d",&value);
	printf("1.Insert in beginning\n2.Insert at end\n3.Insert at a given position\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:n=insert(a,n,value,0);
		break;
		case 2:n=insert(a,n,value,n);
		break;
		case 3:printf("Enter the index:");
		scanf("%d",&index);
		n=insert(a,n,value,index);
		break;
		default:printf("Invalid choice\n");
	}
	printf("Finally the array has:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}