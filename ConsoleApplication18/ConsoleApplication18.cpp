// ConsoleApplication18.cpp: 定义控制台应用程序的入口点。
#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node *ltree;
	struct node *rtree;
}BiTreeNode;
int Max(int a, int b)
{
	return a > b ?  a:b;
}
BiTreeNode *CreatBiTree()
{
	char ch;
	BiTreeNode *p;
	ch = getchar();
	if (ch!='0')
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
void Traverse(BiTreeNode *p)
{
	if (p != NULL)
	{
    	printf("%c ", p->data);
		Traverse(p->ltree);
		Traverse(p->rtree);
	}
	else
		return;
}
int Depth(BiTreeNode *p)
{
	int ltd = 0,rtd = 0;
	if (p == NULL)
		return 0;
	ltd = Depth(p->ltree) + 1;
	rtd = Depth(p->rtree) + 1;
		return Max(ltd,rtd);
}
int main()
{
	BiTreeNode *p;
	int d;
	p = CreatBiTree();
	d = Depth(p);
	printf("%d\n", d);
	Traverse(p);
	system("pause");
    return 0;
}

