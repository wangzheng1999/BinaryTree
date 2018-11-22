#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	char data;
	struct node *lchild;
	struct node *rchild;
	struct node *parent;
}TreeNode;
int i = 0;
TreeNode *t,*s;
TreeNode *CreatTree()
{
	char ch;
	TreeNode *p;
	ch = getchar();
	if (ch != '#')
	{
		p = (TreeNode*)malloc(sizeof(TreeNode));
		p->parent = NULL;
		p->data = ch;
		p->lchild = CreatTree();
		p->rchild = CreatTree();
		if (p->lchild != NULL)
			p->lchild->parent = p;
		if (p->rchild != NULL)
			p->rchild->parent = p;
		return p;
	}
	else
		return NULL;
}
void Traverse(TreeNode *root, TreeNode *p)
{
	if (root == NULL)
		return;
	else
	{
		if (root == p)
			i++;
		else
		{
			Traverse(root->lchild, p);
			Traverse(root->rchild, p);
		}
	}
	return;
}
void CommonParent(TreeNode *p, TreeNode *q)
{
	while (p != NULL)
	{
		Traverse(p, q);
		if (i)
		{
			printf("%c", p->data);
			break;
		}
		p = p->parent;
	}
}
void Locate1(TreeNode *root, char c)
{
	if (root == NULL)
		return;
	else
	{
		if (root->data == c)
		{
			t= root;
		}
		Locate1(root->lchild, c);
		Locate1(root->rchild, c);
	}
}
void Locate2(TreeNode *root, char c)
{
	if (root == NULL)
		return;
	else
	{
		if (root->data == c)
		{
			s = root;
		}
		Locate2(root->lchild, c);
		Locate2(root->rchild, c);
	}
}
int main()
{
	TreeNode *m, *n, *root;
	char a,b;
	root = CreatTree();
    getchar();
	a = getchar();
	getchar();
	b = getchar();
	Locate1(root, a);
	m = t;
	Locate2(root, b);
	n = s;
	CommonParent(m, n);
}


