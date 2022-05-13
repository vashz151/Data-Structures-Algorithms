#include<stdio.h>
#include<conio.h>
void bucksort(int *a,int n)
{
    int large,i,j,k=0,count=0,steps,noeb[10],buck[10][10],loc,div=1;
    large=a[0];
    for(i=0;i<=n-1;i++)
    {
       if(a[i]>=large) large=a[i];
    }
    while(large!=0)
    {
       count++;
       large=large/10;
    }
    for(steps=1;steps<=count;steps++)
    {
	for(j=0;j<=9;j++)
	{
	  noeb[j]=0;
	}
	for(i=0;i<=n-1;i++)
	{
	   loc=(a[i]/div)%10;
	   buck[loc][noeb[loc]++]=a[i];
	}
	for(j=0,k=0;j<=9;j++)
	{
	   for(i=0;i<=noeb[j]-1;i++)
	   {
	       a[k++]=buck[j][i];
	   }
	}
	div=div*10;
    }

}
void main()
{
   int *a,n,i,x;
   clrscr();
   printf("Enter the number of elements:");
   scanf("%d",&n);
   a=(int *)malloc(sizeof(int)*2);
   for(i=0;i<=n-1;i++)
   {
      printf("Enter a value:");
      scanf("%d",&a[i]);
   }
   bucksort(a,n);
   printf("Sorted list:\n");
   for(i=0;i<=n-1;i++)
   {
       printf("%d\n",a[i]);
   }
   getch();
}