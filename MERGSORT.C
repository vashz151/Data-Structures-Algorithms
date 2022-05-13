#include<stdio.h>
#include<conio.h>
void mergesort(int a[5],int b[8], int c[13],int m,int n)
{
	int i=0,j=0,k;
	for(k=0;i<=m-1 && j<=n-1;k++)
	{
		if(a[i]<b[j])
		{
			c[k]=a[i];
			i++;
		}
		else
		{
			c[k]=b[j];
			j++;
		}
	}
	for(;i<=m-1;i++,k++)
	{
		c[k]=a[i];
	}
	for(;j<=n-1;j++,k++)
	{
		c[k]=b[j];
	}
}
void main()
{
	int a[5]={10,20,30,40,50},b[8]={1,3,9,12,13,19,25,29},
	c[13],i;
	clrscr();
	mergesort(a,b,c,5,8);
	printf("Array after merging is:\n");
	for(i=0;i<=12;i++)
	{
		printf("%d\t",c[i]);
	}
	getch();
}