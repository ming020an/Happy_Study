/*不要改动!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
#include<stdio.h>
#include<stdlib.h>
#define N 20
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
	return first;
}
/**打印链表函数**/
int print_link(struct link *head)//定义一个返回值为int函数
{
	int sum=0;
	struct link *p = head;
	while(p)
	{
		printf("%5d",p->data);
		p=p->next;
		sum++;
	}
	printf("\n");
	return sum;
}
struct link* my_delete(struct link*head,int a);

int main (void)
{	
	int sum ;
	struct link *list=creat_link();
		sum=print_link(list);
		my_delete(list,sum);
		print_link(list);
	return 0;
}
/** 删除函数 **/
struct link* my_delete(struct link*head,int a)
{
	struct link* pre=NULL;
	struct link* now=NULL;
	int x;
	int flag=0;
	printf("请输入一个想删除的数！");
	scanf("%d",&x);
	while(a!=0)
	{
		
		now=head;
		while(now)//找点
		{
			if(now->data==x)
			{
				break;
			}
			pre=now;//记录点位置
			now=now->next;
		}
		if(now==NULL)
		{
			;
		}
		else
		{
			if(now==head)
			{
				head = head->next;
				now->next=NULL;
			}
			else
			{
				pre->next=now->next;
				now->next=NULL;
			}
			free(now);
			flag=1;
		}
		a--;
	}
	if(flag==0)
	printf("很遗憾没找到这个数!\n");
	return head;

}
