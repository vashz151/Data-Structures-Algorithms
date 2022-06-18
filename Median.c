#include <stdio.h>
#include <stdlib.h>
struct node
{
    float data;
    struct node *left, *right;
};
struct node *create(int value)
{
    struct node *New_Node =(struct node *) malloc(sizeof(struct node));
    New_Node->data = value;
    New_Node->left = NULL;
    New_Node->right = NULL;
    return New_Node;
}
struct node *insertNode(struct node *root, int value)
{
    if (root == NULL)
    {
        root = create(value);
    }
    else if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else 
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}
void inorder(struct node *root,int *arr)
{
    if(root!=NULL)
    {
	    static int i;//considering it as static so that each time we insert in array i is increased from previous value
        inorder(root->left,arr);
	    arr[i++]=root->data;//inserting inorder element in array
	    inorder(root->right,arr);
    }
}
void findMedian(int *arr,int n)
{
    float median=0;
    // if number of elements are even
    if(n%2==0)
    {
        median=(arr[(n-1)/2]+arr[n/2])/2.0;
    }
    // if number of elements are odd
    else
    {
        median=arr[n/2];
    }
    printf("The median=%f\n",median);
}
int main()
{
    int i,n,*arr;
    struct node *root=NULL;
    printf("Enter number of elements in array:");
    scanf("%d", &n);
    arr=(int *) malloc(n*sizeof(int));
    printf("Enter elements of array:");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        root=insertNode(root,arr[i]);
    }
    inorder(root,arr);//calling it to insert elements in array
    findMedian(arr,n);
}