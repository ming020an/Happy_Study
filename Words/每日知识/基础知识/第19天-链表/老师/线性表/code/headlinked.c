/*************************************************************************
  > File Name: headlinked.c
  > Author: 欧阳华亮
  > Mail: hualiang0305@foxmail.com 
  > Created Time: Sun 04 Feb 2018 06:58:08 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct node
{
	ElemType data;	//数据域
	struct node * next; //指针域
}NODE; //结点结构体

typedef struct list
{
	NODE *first; //用来指向链表的第一个结点
	NODE *last; //用来只想链表的最后一个结点
	ElemType num; //链表结点数
}LIST; //头结点结构体


/*
 *create_list 用来创建头结点的函数
 @void 不需要参数
 @返回值:头结点指针
 */
LIST * create_list(void)
{
	/*定义一个头结点指针,分配空间*/
	LIST *list = (LIST*)malloc(sizeof(*list));
	list->num = 0;
	list->first = NULL;
	list->last = NULL;

	return list;
} //创建头结点其实就是定义一个头结点结构提,分配空间并赋初值


/*
 *	create)linked函数,用来创建链表
 *	 @list 该链表的头结点
 *	 @返回值:头结点指针
 * */
LIST * create_linked(LIST *list)
{
	NODE *p =NULL;
	int x;

	while(1)
	{
		scanf("%d",&x);
		if(x == 0)
		{
			break;
		}

		/*0.分配一个结点空间*/
		p=(NODE*)malloc(sizeof(*p));
		p->data = x;
		p->next = NULL;

		/*1.将结点插入链表*/
		if(list->first == NULL)
		{
			list->first = p;
			list->last = p;
		}
		else
		{
			/*尾插法*/
			list->last->next = p;
			list->last = p;
		}
		list->num++;
	}

	return list;
}

LIST * dz_linked(LIST* list)
{
	/*链表只有一个结点 或者 没有结点,就不需要倒置*/
	if(list->num == 0 || list->num == 1)
	{
		return list;
	}
	
	NODE * p = list->first;
	NODE *now = NULL;
	while(p != list->last)
	{
		now = p; //now记录要换位的结点
		p=p->next; //p后移
		/*使用中间插入的方式将now插入到链表*/
		now->next = list->last->next;
		list->last->next = now;
	}
	
	/*头尾交换*/
	list->last = list->first;
	list->first =  p;
	
	return list;
}


void print_linked(struct node *head)
{
	struct node *p = head;
	while(p)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}


int main(void)
{
	/*0.创建一个头节点 用来标识一个链表*/
	LIST* list = create_list();


	/*1.创建链表*/
	list = create_linked(list);

	/*2.打印*/
	print_linked(list->first);
	printf("%d\n",list->num);
	
	
	list = create_linked(list);
	/*2.打印*/
	print_linked(list->first);
	printf("%d\n",list->num);
	
	return 0;
}



