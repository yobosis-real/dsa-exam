#include<stdio.h>
#include<stdlib.h>

struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

typedef struct BST NODE;
NODE *root=NULL,*cur,*prev;

NODE *insert(int item)
{
    NODE *temp;
    temp=(NODE *)malloc(sizeof(NODE));
    temp->data=item;
    temp->right=NULL;
    temp->left=NULL;
    if(root==NULL)
    {
        root=temp;
        return 0;
    }
    cur=root;
    while(cur!=NULL)
    {
        prev=cur;
        if(item<(cur->data))
            cur=cur->left;
        else if(item>cur->data)
            cur=cur->right;
        else if(item=cur->data)
            return 0;
    }
    if(item<prev->data)
        prev->left=temp;
    else
        prev->right=temp;
}

void *inorder(NODE *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d\t",node->data);
        inorder(node->right);
    }
}

void *preorder(NODE *node)
{
    if(node!=NULL)
    {
        printf("%d\t",node->data);
        preorder(node->left);
        
        preorder(node->right);
    }
}

void *postorder(NODE *node)
{
    if(node!=NULL)
    {
        postorder(node->left);
        
        postorder(node->right);
        printf("%d\t",node->data);
    }
}

void main()
{
    int item;
    printf("insert");
    for(int i=0;i<=5;i++)
    {
        scanf("%d",&item);
        insert(item);
    }
    printf("pre - ");
    preorder(root);
    printf("in - ");
    inorder(root);
    printf("post - ");
    postorder(root);

}
