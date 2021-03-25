/*************************************************************************
	> File Name: linkedList.c
	> Author: 欧阳华亮
	> Mail: hualiang0305@foxmail.com 
	> Created Time: Thu 01 Feb 2018 07:17:26 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

struct node
{
	ElemType data; //数据域
	struct node* next; //指针域
}NODE;//链表结点结构体


typedef struct list
{
	NODE *first; //用来指向链表的第一个结点
	NODE *last; //用来只想链表的最后一个结点
	ElemType num; //链表结点数
}LIST; //头结点结构体

/*
 *创建一个新的链表，存储用户输入的数据，直到用户输入0
 *   @不需要输入参数
 *   @功能完成后应返回创建好的链表的 首地址  struct node*
*/
struct node * create_linkedList(void)
{
	
	struct list * l = (struct list *)malloc(sizeof(*l));
	l->first = NULL;
	l->last = NULL;
	l->num = 0;
	//struct node *first = NULL; //用来指向链表第一个结点的地址
	//struct node *last = NULL; //用来指向链表最后一个结点的地址
	struct node *p = NULL;   //新的结点,要插入的结点
	//struct node *now = NULL; //用来指向当前结点
	//struct node *pre = NULL; //用来指向当前结点的上一个结点
	int n; //用来存放用户输入的数据
	//int s = 0;
	
	while(1)
	{
		scanf("%d",&n);
		if(n == 0) //等于0,表示用户输入结束
		{
			break;
		}

		/*1.创建一个结点来保存用户输入的 数*/
		p = (struct node *)malloc(sizeof(*p)); //分配一个空间用来保存
		p->data = n;
		p->next = NULL;


		/*2.将新建的结点插入到链表*/
		if(l->first == NULL)//链表不存在
		{
			l->first = p; 
			l->last = p; //链表只有一个元素 就是 p 这个结点
		}
		else
		{
			/*头插法:将新节点当成链表的第一个结点*/
			//p->next = first;
			//first = p;
			
			/*尾插法*/
			l->last->next = p;
			l->last = p;
		
			/*有序插入  升序排列*/
			/*
			now = first;
			while(now)//找插入位置  now != NULL
			{
				if(now->data > p->data) //找到第一个比插入结点数据大的数
				{
					break;
				}
				pre = now; //记录当前位置
				now = now->next;
			}

			if(now == NULL)//表示整个链表中都没有比新结点大的数
			{
				//尾插法
				last->next = p; //连线
				last = p;
			}
			else if(now == first)//比最小结点 还 小
			{
				//头插法
				p->next = first;
				first = p;
			}
			else //中间插入
			{
				pre->next = p;
				p->next = now;
			}
			*/
		}
		l->num++;
	}
	
	

	return l->first;
}

/*
 *delete_node函数用来删除链表中的某个节点
 *	@要删除哪个链表的东西
 *	@要删除那个数
 *	#返回值 删除一个数后的链表
 * */
struct node* delete_node(struct node*head ,int x)
{
	struct node * now = NULL;
	struct node * pre = NULL;

	/*0.找到要删除的结点*/
	now = head;
	while(now)//遍历链表查找要删除的结点
	{
		if(now->data == x)
		{
			break;
		}
		pre = now;
		now = now->next;
	}
	
	if(now == NULL)
	{
		printf("no find\n");
	}
	else
	{
		if(now == head)
		{
			head = head->next; //刑天
		}
		else
		{
			/*1.转接*/
			pre->next = now->next;
		}

		now->next = NULL;
		/*2.删除*/
		free(now);
	}

	return head;
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
	struct node *list = create_linkedList();
	int n;

	print_linked(list);

	scanf("%d",&n);
	list = delete_node(list,n);
	print_linked(list);

	return 0;
}
