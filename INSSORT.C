#include<stdio.h>
#include<conio.h>
void inssort(int *a,int n)
{
	int temp,i,j;
	for(i=1;i<=n-1;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]<temp) break;
			a[j+1]=a[j];
		}
		a[j+1]=temp;
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
	inssort(a,n);
	printf("Sorted List:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}