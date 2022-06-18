#include <stdio.h>
int a[10][10];
int n;
int stack[20];
int ToS=-1;
void push(int value)
{
	ToS++;
	stack[ToS]=value;
}
int pop()
{
	return (stack[ToS--]);
}
void adjacency()
{
	int e,i,j,s,d;
	char x;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the number of edges:");
    scanf("%d",&e);
    for(i=0;i<=n-1;i++)
    {
	    for(j=0;j<=n-1;j++)
	    {
		    a[i][j]=0;
	    }
    }
    for(i=0;i<=e-1;i++)
    {
		scanf("%c",&x);//dummy variable for enter key
		printf("Enter the source vertex:");
        scanf("%c",&x);
		s=x-97; //x is the character input and subtracting ascii value of a
		scanf("%c",&x);//dummy variable for enter key
        printf("Enter the destination vertex:");
        scanf("%c",&x);
		d=x-97;//x is the character input and subtracting ascii value of a
        a[s][d]=1;
	}
}
void topological_sort(int flag[], int indeg[])
{
	int i,j,k,f=0;
	for(k=0;k<=n-1;k++)
	{
		if((indeg[k]==0) && (flag[k]==0)) //choosing vertex which is unvisited and zero indegree
		{
			push(k);
			flag [k]=1;//flag is an array of visited vertices
			for(i=0;i<=n-1;i++)
		    {
		        //decreasing indree of all those vertices by 1(corresponding to removeing edges)
				if(a[k][i]==1) indeg[i]--; 
	        }
			topological_sort(flag,indeg);//recursively calling again
			//reverting back all the values for enumeration of other possibilities
			flag[k]=0;
			pop();
		    for(i=0;i<n;i++)
		    {
			    if(a[k][i]==1) indeg[i]++;
		    }
		    f=1;
	    }
    }
	//we reach here if all vertices are visited hence we print it
    if(f==0)
	{
		for(i=0;i<n;i++)
		{
			printf("%c ",stack[i]+97);//adding ascii value of a so that characters are displayed
		}
		printf("\n");
	}
}
int main()
{
	int flag[10],indeg[10];
	printf("Input to be taken in the form of lowercase alphabets:\n");
	adjacency();
	for(int i=0;i<n;i++)//initializing all to zero
	{
		indeg[i]=0;
		flag[i]=0;
	}
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=n-1;j++)
		{
			indeg[i]=indeg[i]+a[j][i];//adding adjacentry matrix columns to indegree
		}
	}
	printf("The topological order is:\n");
	topological_sort(flag,indeg);
}