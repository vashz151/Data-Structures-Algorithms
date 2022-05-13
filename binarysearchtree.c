#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left , *right;
}node;
node* BSTSearch(node *temp , int key)
{
    if(temp==NULL) return NULL;
    else if(key==temp->data) return temp;
    else if(key < temp->data) return BSTSearch(temp->left , key);
    else return BSTSearch(temp->right , key);
}
node* smallest(node *temp)
{
    if(temp==NULL || temp->left==NULL) return temp;
    return smallest(temp->left);
}
node* insertelement(node *temp , int val)
{
    node *newnode, *temp1,*temp2;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if(temp==NULL)
    {
	temp=newnode;
    }
    else
    {
	temp2=NULL;
	temp1=temp;
	while(temp1!=NULL)
	{
	    temp2=temp1;
	    if(val<=temp1->data)
	    {
		temp1=temp1->left;
	    }
	    else
	    {
		temp1=temp1->right;
	    }
	}
	if(val<temp2->data)
	{
	    temp2->left=newnode;
	}
	else
	{
	    temp2->right=newnode;
	}
    }
    return temp;

}
node* deleteNode(node *root , int key)
{
    if(root==NULL)
    {
	printf("Tree is empty\n");
	return NULL;
    }
    if(key>root->data)
    {
	root->right=deleteNode(root->right,key);
    }
    else if(key<root->data)
    {
	root->left=deleteNode(root->left,key);
    }
    else
    {
	if(root->left==NULL)
	{
	    node *temp=root->right;
	    free(root);
	    return temp;
	}
	else if(root->right==NULL)
	{
	    node *temp=root->left;
	    free(root);
	    return temp;

	}
	else
	{
	    node *temp=smallest(root->right);
	    root->data=temp->data;
	    root->right=deleteNode(root->right , temp->data);
	}
    }
    return root;
}
void preorder(node *p)
{

    if(p!=NULL)
    {
	printf("%d\n",p->data);
	preorder(p->left);
	preorder(p->right);

    }

}
void postorder(node *p)
{

    if(p!=NULL)
    {
	postorder(p->left);
	postorder(p->right);
	printf("%d\n",p->data);

    }

}
void inorder(node *p)
{
    if(p!=NULL)
    {
	inorder(p->left);
	printf("%d\n",p->data);
	inorder(p->right);
    }

}
int count_total(node *temp)
{
    if(temp==NULL) return 0;
    return (1+count_total(temp->left)+count_total(temp->right));
}
int count_internal(node *temp)
{
    if(temp==NULL || (temp->left==NULL && temp->right==NULL)) return 0;
    return (1+count_internal(temp->left)+count_internal(temp->right));
}
int count_external(node *temp)
{
    if(temp==NULL) return 0;
    else if(temp->left==NULL && temp->right==NULL) return 1;
    return (count_external(temp->left)+count_external(temp->right));
}
int height(node *temp)
{
    int leftht,rightht;
    if(temp==NULL || (temp->left==NULL && temp->right==NULL)) return 0;
    else
    {
	leftht=height(temp->left);
	rightht=height(temp->left);
	if(leftht>rightht) return leftht+1;
	return rightht+1;
    }
}
node* largest(node *temp)
{
    if(temp==NULL || temp->right==NULL) return temp;
    return largest(temp->right);
}

node* deleteFULL(node *root)
{
    if(root==NULL)
    {
	//printf("Tree is empty\n");
	return NULL;
    }
    if(root->left != NULL)
    deleteFULL(root->left);
    if(root->right!=NULL)
    deleteFULL(root->right);
    free(root);
    return NULL;
}
node* mirrorBST(node *temp)
{
    node *p;
    p=NULL;
    if(temp!=NULL)
    {
	p=(node *)malloc(sizeof(node));
	p->data=temp->data;
	p->left=mirrorBST(temp->right);
	p->right=mirrorBST(temp->left);
    }
    return p;
}
void main()
{
    int choice , value , key;
    char confirm;
    node *root=NULL,*l,*s,*val;
    clrscr();
    printf("This program is an implementation of Binary Search Tree\n");

    do
    {
	printf("\nMenu : \n1. Searching \n2. Insertion\n3. Deleting a node\n4. Preorder Traversal\n5. Postorder Traversal\n6. Inorder Traversal\n7. Count Total Number of Nodes\n8. Count Total Number of Internal Nodes\n9. Count Total Number of External Nodes\n10. Height of a tree\n11. Largest element in the tree\n12. Smallest element in the tree\n13. Deleting entire tree\n14. Mirror of BST\n15. Exit\nChoose your option : ");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1 : printf("Enter the value to be searched : ");
	    scanf("%d",&key);
	    val=BSTSearch(root,key);
	    if(val!=NULL) printf("Element %d found",val->data);
	    else printf("Element not found");
	    inorder(root);
	    break;

	    case 2 : printf("Enter the value to be inserted : ");
	    scanf("%d",&value);
	    root=insertelement(root,value);
	    inorder(root);
	    break;

	    case 3 : printf("Enter the value to be deleted : ");
	    scanf("%d",&value);
	    root=deleteNode(root,value);
	    inorder(root);
	    break;

	    case 4 : printf("Current BST through preorder traversal is : \n");
	    preorder(root);
	    break;

	    case 5 : printf("Current BST through postorder traversal is : \n");
	    postorder(root);
	    break;

	    case 6 : printf("Current BST through inorder traversal is : \n");
	    inorder(root);
	    break;

	    case 7 : printf("Total number of nodes in tree = %d",count_total(root));
	    break;

	    case 8 : printf("Total number of internal nodes in tree = %d",count_internal(root));
	    break;

	    case 9 : printf("Total number of external nodes in tree = %d",count_external(root));
	    break;

	    case 10 : printf("Height of current Binary Search Tree = %d",height(root));
	    break;

	    case 11 : l=largest(root);
	    printf("Largest element in the tree is = %d",l->data);
	    break;

	    case 12 : s=smallest(root);
	    printf("Smallest element in the tree is = %d",s->data);
	    break;

	    case 13 : printf("Are you sure you want to delete the entire tree?\nYes\nNo\nType y(for Yes) or n(for No) : ");
	    scanf("%s",&confirm);
	    if(confirm=='y'|| confirm=='Y')
	    {
		root=deleteFULL(root);
	    }

	    break;

	    case 14 : root=mirrorBST(root);
	    inorder(root);
	    break;

	    case 15 : break;

	    default : printf("Enter valid option from above given menu\n");
	}
    }while(choice!=15);
    getch();
}
