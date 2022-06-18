#include<stdio.h>
#include<stdlib.h>
int value=0;
struct node
{
    int data;
    struct node *left,*right;
};
struct node *create_BSTNode(int value)
{
    struct node* NewNode;
    NewNode=(struct node*) malloc(sizeof(struct node));
    NewNode->data=value;
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}
struct node *insert_BSTNode(struct node *root,int value)
{
    if(root==NULL)
    {
        root=create_BSTNode(value);
    }
    else if (value<root->data)
    {
        root->left=insert_BSTNode(root->left,value);
    }
    else 
    {
        root->right=insert_BSTNode(root->right,value);
    }
    return root;
}
struct node *findlca(struct node *root,int n1,int n2)
{
    if(root==NULL) return NULL;
    if(root->right!=NULL)//this is to check if 1 2 3 4 and ancestor for 3 and 4 will be 2
    {
        if(root->right->data==n1 || root->right->data==n2)
        {
            return root;//if right of root is equal to n1 or n2 return that node
        }
    }
    if(root->left!=NULL)//this is to check if 4 3 2 1 and ancestor for 2 and 3 will be 4
    {
        if(root->left->data ==n1 || root->left->data==n2)
        {
            return root;//if left of root is equal to n1 or n2 return that node
        }
    }   
    if(root->data>n1 && root->data>n2)
    {
        return findlca(root->left,n1,n2);
    }
    else if(root->data<n1 && root->data<n2)
    {
        return findlca(root->right,n1,n2);
    }
    return root;
}
struct node *kth_smallest(struct node *root)
{
    struct node *l,*r;
    if (root==NULL) return NULL;
    l=kth_smallest(root->left);//searching in left subtree
    if (l!=NULL) return l;
    value--;
    if (value==0) return root;//if current node is smallest
    r=kth_smallest(root->right);//searching in right subtree
    return r;
}
int balance(struct node* root,int *height)
{
    int leftht=0,rightht=0;//heights of left and right subtrees
    int l=0,r=0;//to check if balanced
    if (root==NULL) 
    {
        *height=0;
        return 1;
    }
    l=balance(root->left,&leftht);
    r=balance(root->right,&rightht);
    *height=(leftht>rightht? leftht:rightht)+1;
    if (leftht-rightht>=2 || leftht-rightht<=-2) return 0;
    else if(l==1 && r==1) return 1;//both will be 1 if balanced
    else return 0;
}
void range(struct node* root, int k1, int k2)
{
    if(root==NULL) return;
    if(root->data<=k2 && root->data>=k1)//if in element in given range
    {  
       printf("%d ",root->data);
    }
    //if larger than k1 call for left subtree
    if(root->data>k1) range(root->left,k1,k2);
    range(root->right,k1,k2);//calling for right subtree
}
int main()
{
    struct node *root=NULL,*val;
    int n,n1,n2,i,choice=0,height=0;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter elements of the tree:");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&value);
        root=insert_BSTNode(root,value);
    }
    while(choice!=5)
    {
        printf("\n1.Find LCA\n2.Find kth smallest element\n3.Balanced BST\n4.Print all elements in range of n1 and n2\n5.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the two elements whose lca needs to find:");
                    scanf("%d %d",&n1,&n2);
                    val=findlca(root,n1,n2);
                    printf("Least Common Ancestor of %d and %d is %d",n1,n2,val->data);
            break;
            case 2: printf("Enter the value of k:");
                    scanf("%d",&value);
                    val=kth_smallest(root);
                    printf("The required element is %d",val->data);
            break;
            case 3: if (balance(root,&height)==1) printf("Tree is balanced");
                    else printf("Tree is not balanced"); 
            break;
            case 4: printf("Emter the start and end of range:");
                    scanf("%d %d",&n1,&n2);
                    printf("Elements in given range are:");
                    if(n1>n2) range(root,n2,n1);
                    else range(root,n1,n2);
            break;
            case 5:
            break;
            default:printf("Invalid choice\n");
        }
    }    
    return 0;
}