#include<stdio.h>
#include<conio.h>
int delele(int n,int posi, int a[50])
{
	int i;
	if(posi<1 || posi>n) return n;
	for(i=posi-1;i<=n-1;i++)
	{
		a[i]=a[i+1];
	}
	return(n-1);
}
void main()
{
	int a[50],i,n,posi,choice;
	clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Delete the element at:\n1.Start\n2.End\n3.Other Location\nEnter your choice:");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:n=delele(n,1,a);
		break;
		case 2:n=delele(n,n,a);
		break;
		case 3:printf("Enter the position:");
		scanf("%d",&posi);
		n=delele(n,posi,a);
		break;
		default:printf("Invalid choice\n");
	}
	printf("Array after deleting the element is:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\t",a[i]);
	}
	getch();
}