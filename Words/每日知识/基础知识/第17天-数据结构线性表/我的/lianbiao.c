/*************************************************************************
  > File Name: lianbiao.c
  > Author: 刘广伟
  > Mail: gwacoe@163.com 
  > Created Time: Fri 02 Feb 2018 02:44:18 PM CST
  输入一些数，使其降序排列，链表做法
 ************************************************************************/

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
int my_select(struct link *head,int c[]);
struct link* my_delete(struct link*head,int a,int b);

int main (void)
{	
	int num,sum ,i,j;
	struct link *list=creat_link();
	//printf("sssssssssss");
	sum=print_link(list);
	//printf("sss");
	//printf("sum=%d",sum);
	//printf("saaasssssss");
	int b[100];
	j=my_select(list,b);//选择函数，参数为链表，数组用于存放相同的数，
	for(i=0;i<10;i++)
	{
		num=b[i];
		my_delete(list,sum,num);//参数为链表，循环次数，被删数
	}
	print_link(list);
	
	
	for(i=0;i<j;i++)
	printf("%d\t",b[i]);
	return 0;
}
/** 删除函数 **/
struct link* my_delete(struct link*head,int a,int b)
{
	struct link* pre=NULL;
	struct link* now=NULL;
	int x;
	int flag=0;
	x=b;
	printf("删除的数为%d",x);
	//scanf("%d",&x);
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

/**选择函数*/

int my_select(struct link *head,int c[])//把数存放到数组c中
{
		int	i=1;
		int j =0;
		struct link *p = head;
		
	while(p)
		{
			for(j=0;j<i;j++)
			{
			if(p->data!=*(c+j))
			{
				*(c+i)=p->data;
				i++;
			}
			}
			p=p->next;
			
		}
	return j;
}
