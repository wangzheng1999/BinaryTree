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
TreeNode *leaf[50];
int i=0;
typedef struct stack
{
	char data;
	struct stack *next;
}Stack;
Stack *Init()
{
	Stack *p;
	p=(Stack*)malloc(sizeof(Stack));
	p->next=NULL;
	return p;
}
void Push(Stack *h,char c)
{
	Stack *p;
	p=(Stack*)malloc(sizeof(Stack));
	p->data=c;
	p->next=h->next;
	h->next=p;
}
TreeNode *CreatTree()
{
	char ch;
	TreeNode *p;
	ch=getchar();
	if(ch!='#')
	{
		p=(TreeNode*)malloc(sizeof(TreeNode));
		p->parent=NULL;
		p->data=ch;
		p->lchild=CreatTree();
		p->rchild=CreatTree();
		if(p->lchild!=NULL)
		p->lchild->parent=p;
		if(p->rchild!=NULL)
		p->rchild->parent=p;
		return p;
	}
	else
	return NULL;
}
int Traverse(TreeNode *root)
{
	if(root==NULL)
	return i;
	else
	{
		if(root->lchild==NULL&&root->rchild==NULL)
		{
			leaf[i]=root;
			i++;
		}
		Traverse(root->lchild);
		Traverse(root->rchild);
	}
	return i;
}
void Trace(int d)
{
	int i;
	Stack *h,*q;
	TreeNode *p;
	for(i=0;i<d-1;i++)
	{
		h=Init();
		p=leaf[i]->parent;
		printf("%c:",leaf[i]->data);
		while(p!=NULL)
		{
			Push(h,p->data);
			p=p->parent;
		}
		q=h->next;
		while(q!=NULL)
		{
			printf("%c",q->data);
			q=q->next;
		}
		printf("\n");
	}
	    h=Init();
		p=leaf[i]->parent;
		printf("%c:",leaf[i]->data);
		while(p!=NULL)
		{
			Push(h,p->data);
			p=p->parent;
		}
		q=h->next;
		while(q!=NULL)
		{
			printf("%c",q->data);
			q=q->next;
		}
}
int main()
{
	int d;
	TreeNode *p;
	p=CreatTree();
	d=Traverse(p);
	Trace(d);
}
