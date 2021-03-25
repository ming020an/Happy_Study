/*************************************************************************
	> File Name: linked.c
	> Author: 欧阳华亮
	> Mail: hualiang0305@foxmail.com 
	> Created Time: Thu 01 Feb 2018 06:52:27 PM PST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>

typedef int ElemType;

struct node
{
	ElemType data;
	struct node *next;
};

int main(int argc,char *argv[])
{
	struct node *p = (struct node*)malloc(sizeof(*p));
	struct node *q = (struct node*)malloc(sizeof(*q));
	struct node *t = (struct node*)malloc(sizeof(*t));
	struct node *r = (struct node*)malloc(sizeof(*r));
	struct node *w = (struct node*)malloc(sizeof(*w));

	p->data = 1;
	p->next = q;

	q->data = 2;
	q->next = t;

	t->data = 3;
	t->next = r;

	r->data = 4;
	r->next = w;

	w->data = 5;
	w->next = NULL;

	printf("p:%p  \nq:%p  \nt:%p  \nr:%p  \nw:%p\n",p,q,t,r,w);

	struct node *v = p;
	while(v) // v != NULL
	{
		printf("%3d",v->data); //打印v指向的结点的数据
		v = v->next; //v 指向v的下一个结点
	}
	printf("\n");
	return 0;
}
