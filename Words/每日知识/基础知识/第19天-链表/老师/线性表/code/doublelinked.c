/*************************************************************************
	> File Name: doublelinked.c
	> Author: 欧阳华亮
	> Mail: hualiang0305@foxmail.com 
	> Created Time: Mon 05 Feb 2018 10:14:18 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


typedef int ElemType;

struct node
{
	ElemType data;
	struct node* next;
	struct node* prev;
};

/*创建一个有序的双向链表*/
struct node *create_doubleLinked(void)
{
	/*0.定义一个结点对象*/
	struct node * p = NULL;
	struct node * first = NULL;
	struct node * last = NULL;
	
	struct node * now = NULL;
	int x;
	while(1)
	{
		/*1.从键盘获取输入,并保存到结点对象中*/
		scanf("%d",&x);
		if(x == 0)
		{
			break;
		}
		p = (struct node*)malloc(sizeof(*p));
		p->data = x;
		p->next = NULL;
		p->prev = NULL;
		
		/*2.将结点插入链表*/
		if(first == NULL)
		{
			first = p;
			last = p;
		}
		else
		{
			/*有序插入,先找要插入的位置,然后再执行插入操作*/
			now = first;
			while(now)
			{
				if(now->data > p->data)
				{
					break;
				}
				now = now->next;
			}
			
			if(now == NULL)
			{
				/*尾插法*/
				p->prev = last;
				last->next = p;
				last = p;
			}
			else
			{
				if(now == first)
				{
					/*头插法*/
					p->next = first;
					first->prev = p;
					first = p;
				}
				else
				{
					/*中间插*/
					p->next = now;
					p->prev = now->prev;
					now->prev->next = p;
					now->prev = p;
				}
			}
		}
	}

	return first;

}

/*增*/
struct node * add_node(struct node *list,int x)
{
	/*定义一个结点对象,保存要插入的数据*/
	struct node *now = NULL;
	struct node *first = list;
	struct node *last = NULL;
	struct node *p = (struct node*)malloc(sizeof(*p));
	p->data = x;
	p->next = p->prev = NULL;
	now = list;
	
	while(now) //找链表尾巴的
	{
		last = now;
		now = now->next;
	}
	
	/*将结点插入链表*/
	/*2.将结点插入链表*/
	if(first == NULL)
	{
		first = p;
		last = p;
	}
	else
	{
		/*有序插入,先找要插入的位置,然后再执行插入操作*/
		now = first;
		while(now)
		{
			if(now->data > p->data)
			{
				break;
			}
			now = now->next;
		}
		
		if(now == NULL)
		{
			/*尾插法*/
			p->prev = last;
			last->next = p;
			last = p;
		}
		else
		{
			if(now == first)
			{
				/*头插法*/
				p->next = first;
				first->prev = p;
				first = p;
			}
			else
			{
				/*中间插*/
				p->next = now;
				p->prev = now->prev;
				now->prev->next = p;
				now->prev = p;
			}
		}
	}
	return first;
}

/*删*/
//struct node *delete_all_node(struct node *list,int x)
struct node *delete_node(struct node *list,int x)
{
	
}

/*改*/
struct node *change_node(struct node *list,int src,int targe)
{
	
}

/*查*/
int find_node(struct node *list ,int x)
{
	
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

	}
	printf("\n");
}


int main(int argc,char *argv[])
{
	int x;
	/*创建一个有序的双链表*/
	struct node * list = create_doubleLinked();
	
	/*look a look*/
	print_linked(list);
	
	/*add_node*/
	while(1)
	{
		scanf("%d",&x);
		if(x == 0)
			break;
		list = add_node(list,x);
	}
	
	print_linked(list);
}




