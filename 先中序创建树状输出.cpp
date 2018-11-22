#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
	int pos;
}BiTreeNode;
#define N 10
BiTreeNode *CreatBiTree(char pre[],char in[],char n)
{
	if(n==0)
	return NULL;
	char lpre[N],lin[N],rpre[N],rin[N];
	int lm=0,rm=0,ln=0,rn=0,i;
	BiTreeNode *p;
	p=(BiTreeNode*)malloc(sizeof(BiTreeNode));
	if(p==NULL)
	return NULL;
	p->data=pre[0];
	for(i=0;i<n;i++)
	{
		if(i<=lm&&in[i]!=pre[0])
		{
			lin[lm]=in[i];
			lm++;
		}
		else if(in[i]!=pre[0])
		{
			rin[rm]=in[i];
			rm++;
		}
	}
	for(i=1;i<n;i++)
	{
		if(i<=lm)
		{
			lpre[ln]=pre[i];
			ln++;
		}
		else
		{
			rpre[rn]=pre[i];
			rn++;
		}
	}
	p->lchild=CreatBiTree(lpre,lin,lm);
	p->rchild=CreatBiTree(rpre,rin,rm);
	return p;
}
void Traverse(BiTreeNode *root)
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
void TreePrint(BiTreeNode *root)
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
	char pre[N],in[N];
	int i=0,j=0;
	BiTreeNode *p;
	scanf("%s%s",pre,in);
	i=strlen(pre);
	p=CreatBiTree(pre,in,i);
	Traverse(p);
	TreePrint(p);
}
