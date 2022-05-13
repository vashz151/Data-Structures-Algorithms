#include<stdio.h>
#include<conio.h>
void bbsort(int *a,int n)
{
	int temp,i,j;
	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void main()
{
	int *a,i,n;
	clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	bbsort(a,n);
	printf("Sorted List:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}