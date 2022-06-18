#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isOperator(char c)
{
    if( c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%') return 1;
    else return 0;
}
struct node
{
    char data;
    struct node *left,*right,*next;
};
struct node* TOS=NULL;
void push(struct node *ptr)
{ 
    if(TOS==NULL) ptr->next=NULL;
    else 
    {
        ptr->next=TOS;
    }
    TOS=ptr;
}
struct node *pop()
{
    struct node *ptr=TOS;
    TOS=TOS->next;
    return ptr;
}
struct node *create_BSTNode(char value)
{
    struct node* NewNode;
    NewNode=(struct node*) malloc(sizeof(struct node));
    NewNode->data=value;
    NewNode->left=NULL;
    NewNode->right=NULL;
    NewNode->next=NULL;
    return NewNode;
}
void preorder(struct node *root)
{
    if(root!=NULL)
    {
	    printf("%c ",root->data);
	    preorder(root->left);
	    preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL)
    {
	    postorder(root->left);
	    postorder(root->right);
	    printf("%c ",root->data);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL)
    {
	    if(isOperator(root->data)==1)
        printf("(");
        inorder(root->left);
	    printf("%c ",root->data);
	    inorder(root->right);
        if(isOperator(root->data)==1)
        printf(")");
    }
}
int main()
{
    int i,len;
    char value,exp[50];
    struct node *root,*T1,*T2;
    printf("Enter postfix expression:");
    gets(exp);
    len=strlen(exp);
    for(i=0;i<len;i++)
    {
        if(isOperator(exp[i])==1)
        {
            root=create_BSTNode(exp[i]);
            T2=pop();
            T1=pop();
            root->left=T1;
            root->right=T2;
            push(root);
        }
        else
        {
            root=create_BSTNode(exp[i]);
            push(root);   
        }
    }
    printf("Inorder:");
    inorder(root);
    printf("\nPreorder:");
    preorder(root);
    printf("\nPostorder:");
    postorder(root);
    return 0;
}