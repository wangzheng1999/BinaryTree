#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
	int pos;
}TreeNode;
int i=0;
TreeNode *CreatTree()
{
	char ch;
	TreeNode *root;
	ch=getchar();
	if(ch=='#')
	return NULL;
	else
	{
		root=(TreeNode*)malloc(sizeof(TreeNode));
		root->data=ch;
		root->lchild=CreatTree();
		root->rchild=CreatTree();
		return root;
	}
}
void Traverse(TreeNode *root)
{
	if(root==NULL)
	return ;
	else
	{
	    if(root->lchild!=NULL)
		root->lchild->pos=root->pos+2;
		if(root->rchild!=NULL)
		root->rchild->pos=root->pos+2;
		Traverse(root->lchild);
		Traverse(root->rchild);
    }
}
void TreePrint(TreeNode *root)
{
	int i=0;
	if(root==NULL)
	return ;
	else
	{
		TreePrint(root->rchild);
		while(i<root->pos)
		{
		printf(" ");
		i++;
	    }
		printf("%c",root->data);
		printf("\n");
		TreePrint(root->lchild);
		return ;
	}
 } 
int main()
{
	TreeNode *t;
	t=CreatTree();
	t->pos=0;
	Traverse(t);
	TreePrint(t);
}

