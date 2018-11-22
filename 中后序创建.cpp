#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
}TreeNode;
#define N 50
TreeNode *CreatTree(char in[],char post[],char n)
{
	TreeNode *p;
	char lin[50],rin[50],lpost[50],rpost[50];
	int i,lc=0,rc=0,lt=0,rt=0;
	if(n==0)
	return NULL;
	p=(TreeNode*)malloc(sizeof(TreeNode));
	if(p==NULL)
	return NULL;
	p->data=post[n-1];
	for(i=0;i<n;i++)
	{
		if(lc>=i&&in[i]!=post[n-1])
		{
			lin[lc]=in[i];
			lc++;
		}
		else if(in[i]!=post[n-1])
		{
			rin[rc]=in[i];
			rc++;
		}
	}
	for(i=0;i<n-1;i++)
	{
		if(i<lc)
		{
		lpost[lt]=post[i];
		lt++;
	    }
		else
		{
			rpost[rt]=post[i];
			rt++;
		}
	}
	p->lchild=CreatTree(lin,lpost,lc);
	p->rchild=CreatTree(rin,rpost,rc);
	return p;
}
void Traverse(TreeNode *root)
{
	if(root==NULL)
	return ;
	else
	{
		printf("%c",root->data);
		Traverse(root->lchild);
		Traverse(root->rchild);
	}
}
int main()
{
	char in[50],post[50];
	int n;
	TreeNode *root;
	scanf("%s%s",in,post);
	n=strlen(in);
	root=CreatTree(in,post,n);
	Traverse(root);
}
