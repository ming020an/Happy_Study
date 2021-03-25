#include<stdio.h>
#include<stdlib.h>
/**结构体*/
struct link
{
	int data;
	struct link * next;

};

/*创建一个从大到小的链表**/
struct link *creat_link(void)
{

	struct link *pre=NULL;
	struct link *now=NULL;
	struct link *first=NULL;
	struct link *last=NULL;
	struct link *p;
	int n;
	while(1)
	{
		scanf("%d",&n);
		p=(struct link *)malloc(sizeof(*p));
		p->data=n;
		p->next = NULL;
		if(n==0)
			break;

		if(first==NULL)  
		{
			first=p;
			last=p;
		}
		else
		{
			if(first->data<p->data)
			{
				p->next=first;//
				first=p;
			}
			else if(last->data>p->data)

			{
				last->next=p;
				last=p;		
			}
			else
			{
				now=first;		
				while(now)
				{
					if(now->data<p->data)
					{
						break;
					}
					pre=now;
					now=now->next;
				}
				pre->next=p;
				p->next=now;
			}
		}
	}
	printf("倒置前链表：\n");
	//print_link(struct link *first);
	
	return first;
}

/**打印链表函数**/
void print_link(struct link *head)//定义一个返回值为int函数
{
	
	struct link *p = head;
	while(p)
	{
		printf("%5d",p->data);
		p=p->next;
	}
	printf("\n");
	
}

struct link *daozhi(struct link * list)
{
	struct link * first=list;
	struct link * last=list;
	struct link * p = list;
	struct link * now=list;
	if(list==NULL)
		return 0;
	do
	{
		last=now;
		now=now->next;
	}
	while(now);
	//找last
	
	while(p!=last)
	{
		now=p;//now记录交换的点
		p=p->next;
		
		now->next=last->next;
		last->next=now;
	
	}
	return last;
}
int main(void)
{
	/*创建链表*/
	struct link *head=creat_link();
	//printf("ccccc");
	print_link(head);
	/*倒置*/
	//printf("aaaaa");
	struct link *last=daozhi(head);
	/*打印*/
	//printf("bbbbb");
	printf("倒置后链表：\n");
	print_link(last);
	
	return 0;
}
