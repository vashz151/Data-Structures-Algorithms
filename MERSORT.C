#include<stdio.h>
#include<conio.h>
void merge(int *a,int l,int mid,int u)
{
	int *c,i=l,j=mid+1,k=0,s=u-l+1;
	c=(int *)malloc(sizeof(int)*s);
	while(i<=mid && j<=u)
	{
		if(a[i]<a[j])
		c[k++]=a[i++];
		else c[k++]=a[j++];
	}
	while(i<=mid)
	{
		c[k++]=a[i++];
	}
	while(j<=u)
	{
		c[k++]=a[j++];
	}
	for(i=l,j=0;i<=u;i++,j++)
	{
		a[i]=c[j];
	}
}
void merge_sort(int *a,int l,int u)
{
	int mid;
	if(l<u)
	{
		mid=(l+u)/2;
		merge_sort(a,l,mid);
		merge_sort(a,mid+1,u);
		merge(a,l,mid,u);
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
	merge_sort(a,0,n-1);
	printf("Sorted List:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	getch();
}