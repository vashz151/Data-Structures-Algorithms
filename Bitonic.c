#include<stdio.h>
#include<stdlib.h>
int isbitonic(int *arr, int n)
{
    int i,dir=0,mono=0;//dir is the number of times direction is changing 
    for(i=0;i<n;i++)//mono is 1 for monotonically increasing and -1 for decreasing,0 is default
    {
        if(arr[i]<arr[(i+1)%n])
        {
            if(mono==0) mono=1;
            else if(mono==-1)
            {
                dir++;
                mono=1;
            }
        }
        else if(arr[i]>arr[(i+1)%n])
        {
            if(mono==0) mono=-1;
            else if(mono==1)
            {
                dir++;
                mono=-1;
            }
        }
        if(dir>2) return 0;//dir>2 that is peak has been change for more than twice
    }
    return 1;
}
int bitonic_peak(int *arr,int l,int r)
{
    int mid;
    int b=0;
    mid=(l+r)/2;
    static int prev_mid; //need this if we give only increasing or decreasing sequence like 1 2 3 4 so thar for 3<4 it does not go in infinite loop in first else if
    if(prev_mid==mid) return mid+1; //in above case if the prev one is equal to mid that is mid is repeating twice than we will simply return mid+1 that is index of 4 will be returned
    prev_mid=mid;
    if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
	{
		return mid;
	}
	else if(arr[mid]>arr[mid-1] && arr[mid]<arr[mid+1])
	{
		b=bitonic_peak(arr,mid,r);
	}
	else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1])
	{
		b=bitonic_peak(arr,l,mid);
	}
	return b;  
}
int binarySearch(int arr[], int l,int r, int key)
{
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if ((arr[mid] > key && arr[l]<arr[r])|| (arr[mid]<key && arr[l]>arr[r])) //here we have tried to cover ascending and descending conditon
        {//first condition is of ascending sequence and second is of descending
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return -1;
}
int search(int *arr,int index,int n,int key)
{
    int asc;
    if(key>arr[index]) return -1;
    else if (key==arr[index]) return index;
    else
    {
        asc=binarySearch(arr,0,index-1,key);//if ascending
        if(asc!=-1)
        {
            return asc; 
        }
        else return binarySearch(arr,index+1,n-1,key);//if descending
    }
}
int main()
{
    int *arr,n,i,key,l,r,index,found;
    printf("Enter number of elements:");
    scanf("%d",&n);
    arr=(int *) malloc (n*sizeof(int));
    printf("Enter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(isbitonic(arr,n)==1)
    {
        printf("Enter element to be found:");
        scanf("%d",&key);
        l=0;
        r=n-1;
        index=bitonic_peak(arr,l,r);
        found=search(arr,index,n,key);
        if(found!=-1)
        {
            printf("Element %d found at index= %d",key,found);
        }
        else printf("Element not found\n");     
    }
    else printf("Not a bitonic array\n");
    return 0;
}