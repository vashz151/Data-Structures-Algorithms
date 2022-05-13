#include<stdio.h>
#include<conio.h>
void selsort(int *a,int n)
{
	int temp,i,j,k;
	for(i=0;i<=n-2;i++)
	{
		k=i;
		for(j=i+1;j<=n-1;j++)
		{
			if(a[j]<a[k])
			k=j;
		}
		if(k!=i)
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
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
	selsort(a,n);
	printf("Sorted List:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}