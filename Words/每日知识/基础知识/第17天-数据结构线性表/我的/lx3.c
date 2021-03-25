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
	int n,x;
	printf("请输入一个数！\n");
	scanf("%d",&n);
	while(n!=0)
	{
		x=n%10;
		n=n/10;
		p=(struct link *)malloc(sizeof(*p));
		p->data=x;
		p->next = NULL;
		
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
	return first;
}
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
int main(void)
{
	struct link *head=creat_link();
	printf("转换后：\n");
	print_link(head);
	
	return 0;
}