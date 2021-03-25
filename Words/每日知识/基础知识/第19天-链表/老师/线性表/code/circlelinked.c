/*************************************************************************
	> File Name: circlelinked.c
	> Author: 欧阳华亮
	> Mail: hualiang0305@foxmail.com 
	> Created Time: Mon 05 Feb 2018 11:07:24 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

struct node
{
	ElemType data; //数据域
	struct node* next; //指针域
};//链表结点结构体


struct node * create_linked(void)
{
	/*定义一个结点对象*/
	struct node* p = NULL;
	struct node * first =NULL;
	struct node * last = NULL;
	int x;
	
	/*用户输入数据,并保存到结点空间*/
	while(1)
	{
		scanf("%d",&x);
		if(x == 0)
			break;
		
		p = (struct node*)malloc(sizeof(*p));
		p->data = x;
		p->next = NULL;
		
		/*将结点插入链表*/
		if(first == NULL)
		{
			first = p;
			last = p;
			last->next = first; //形成循环
		}
		else
		{
			/*尾插法*/
			last->next = p;
			last = p;
			last->next = first;
		}
	}
	return first;
}

/*
 *打印链表函数: 用来将指定的链表打印出来
 *	@要打印的链表
 *	@返回值 不需要
 * */
void print_linked(struct node* head)
{
	struct node *p = head;
	while(p) // p!= NULL
	{
		printf("%d ",p->data); //打印p结点的数据域
		p=p->next;  //p指向下一个结点
		if(p == head)
			break;
	}
	printf("\n");
}

int main(void)
{
	struct node * list = create_linked();
	
	print_linked(list);
}
