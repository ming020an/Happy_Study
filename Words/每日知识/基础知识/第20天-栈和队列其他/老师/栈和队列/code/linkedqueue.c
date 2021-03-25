/*************************************************************************
	> File Name: linkedqueue.c
	> Author: 欧阳华亮
	> Mail: hualiang0305@foxmail.com 
	> Created Time: Tue 06 Feb 2018 07:18:59 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef int ElemType;

struct node
{
	ElemType data;
	struct node *next;
	struct node *prev;
};

struct linkedqueue
{
	struct node * front; //指向队列头的指针
	struct node * rear; //指向队列尾的指针
	int num; //队列中元素个数
}; //头结点结构体,用来维护一个队列

/*初始化队列*/
struct linkedqueue *InitQueue(void)
{
	struct linkedqueue * p = (struct linkedqueue *)malloc(sizeof(*p));
	p->front = p->rear = NULL;
	p->num = 0;
	
	return p;
}
/*清空队列*/
struct linkedqueue * ClearQueue(struct linkedqueue * q)
{
	struct node * p = q->front;
	while(q->front)
	{
		p = q->front;
		q->front = q->front->next;
		q->front->prev = NULL;
		p->next = NULL;
		free(p);
	}
	
	return q;
}

/*销毁一个队列*/
void DestroyQueue(struct linkedqueue *q)
{
	ClearQueue(q);
	free(q);
}

/*判断链表是否为空*/
int QueueEmpty(struct linkedqueue *q)
{
	return q->num == 0;
	//return q->front == NULL;
}

/*队列的长度*/
int QueueLength(struct linkedqueue *q)
{
	//if()
	return q->num;
}

/*获取第一个元素的数据*/
ElemType GetFront(struct linkedqueue *q)
{	
	//if()?
	return q->front->data;
}

/*入队 --->尾插法*/
struct linkedqueue *EnQueue(struct linkedqueue *q,ElemType x)
{
	struct node * p = (struct node*)malloc(sizeof(*p));
	p->data = x;
	p->next = p->prev = NULL;
	
	if(q->rear == NULL)
	{
		q->rear = q->front = p;
	}
	else
	{
		q->rear->next = p;
		p->prev = q->rear;
		
		q->rear = p;
	}
	q->num++;
	
	return q;
}

/*出队--->砍头*/
ElemType DeQueue(struct linkedqueue *q)
{
	ElemType n = q->front->data;
	struct node * p = q->front;
	q->front = q->front->next;
	p->next = NULL;
	q->front->prev = NULL;
	
	free(p);
	
	return n;
}
