#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	int degree;
	struct node *lchild;
	struct node *rchild;
}TreeNode;
typedef struct queue 
{
	char data;
	struct queue *next;
}QueueNode;
int flag=0;
QueueNode *InitQueue()
{
	QueueNode *p;
	p=(QueueNode*)malloc(sizeof(QueueNode));
	p->next=NULL;
	return p;
}
void Push(char c,QueueNode *h)
{
	QueueNode *p;
	while(h->next!=NULL)
	{
		h=h->next;
	}
	p=(QueueNode*)malloc(sizeof(QueueNode));
	p->data=c;
	h->next=p;
	p->next=NULL;
}
void Pop(QueueNode *h,char *c)
{
	QueueNode *p;
	p=h;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p=NULL;
	c=&h->data;
	//free(p);
}
TreeNode *CreatTree()
{
	char ch;
	TreeNode *p;
	ch=getchar();
	if(ch=='#')
	return NULL;
	else
	{
		p=(TreeNode*)malloc(sizeof(TreeNode));
		p->data=ch;
		if(p->lchild!=NULL&&p->rchild!=NULL)
		p->degree=2;
		else if(p->lchild==NULL&&p->rchild==NULL)
		p->degree=0;
		else
		p->degree=1;
		p->lchild=CreatTree();
		p->rchild=CreatTree();
		return p;
	}
}
void Trace(TreeNode *root,QueueNode *h)
{
	char c;
	QueueNode *p;
	p=h->next;
	if(root==NULL)
	{
     Pop(h,&c);
     return;
    }
	else
	{
		if(root->lchild==NULL&&root->rchild==NULL)
		{
		  printf("%c:",root->data);
		  while(p!=NULL)
		  {
			printf("%c",p->data);
			p=p->next;
		  }
	    }
	    Push(root->data,h);
		Trace(root->lchild,h);
		Trace(root->rchild,h);
		Pop(h,&c);
		return ;
	}
}
int main()
{
	TreeNode *root;
	QueueNode *h;
	h=InitQueue();
	root=CreatTree();
	Trace(root,h);
}
