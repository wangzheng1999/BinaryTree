#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
	char data;
	struct tree *ltree;
	struct tree *rtree;
}BiTreeNode;
typedef struct BiTree
{
	BiTreeNode node;
	struct BiTree *next;
}QueueNode;
BiTreeNode *CreatBiTree()
{
	char ch;
	BiTreeNode *p;
	ch = getchar();
	if (ch != '#')
	{
		p = (BiTreeNode*)malloc(sizeof(BiTreeNode));
		p->data = ch;
		p->ltree = CreatBiTree();
		p->rtree = CreatBiTree();
	}
	else
	{
		p = NULL;
	}
	return p;
}
QueueNode *InitQueue()
{
	QueueNode *p ;
	p=(QueueNode*)malloc(sizeof(QueueNode));
	p->next=NULL;
	return p;
}
void Push(QueueNode *p,BiTreeNode *m)
{
	QueueNode *q;
	q= (QueueNode *)malloc(sizeof(QueueNode));
	q->node=*m;
	while(p->next!=NULL)
	p=p->next;
	p->next=q;
	q->next=NULL;
}
QueueNode *Pop(QueueNode *p)
{
	QueueNode *q;
	q =p->next;
	if (p->next == NULL)
		return NULL;
	else
	{
		p->next = q->next;
		return q;
		free(q);
	}
}
void Traverse(BiTreeNode *t,QueueNode *p)
{
	Push(p,t);
	while(p->next!=NULL)
	{
		t=&Pop(p)->node;
		printf("%c",t->data);
		if(t->ltree!=NULL)
		Push(p,t->ltree);
		if(t->rtree!=NULL)
		Push(p,t->rtree);
	}
}
int main()
{
	BiTreeNode *t;
	QueueNode *p;
	t=CreatBiTree();
	p=InitQueue();
	Traverse(t,p);
}
