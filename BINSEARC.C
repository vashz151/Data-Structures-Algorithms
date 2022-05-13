#include<stdio.h>
#include<conio.h>
int binsearch(int a[100],int n,int key)
{
	int l=0,r=n-1,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(key==a[mid]) return mid;
		else if(key<a[mid]) r=mid-1;
		else l=mid+1;
	}
	return -1;
}
int main()
{
	int a[100],i,n,key;
	//clrscr();
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter a value:");
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d",&key);
	i=binsearch(a,n,key);
	if(i==-1) printf("Element not found");
	else printf("Found at position: %d",i+1);
	getch();
}