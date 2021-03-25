/*************************************************************************
> File Name: class.c
> Author: 欧阳华亮
> Mail: hualiang0305@foxmail.com 
> Created Time: Mon 05 Feb 2018 05:38:12 PM PST
************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct student
{
	int id;
	int class;
	char name[50];
	float yw,sx,yy;
	
	struct student *next;
};

struct class
{
	int class;
	int num;
	float yw,sx,yy; //整个班级的总分
	
	struct student *first;
	struct student *last;
};


/*0.创建一个头结点*/
struct class * create_head(void)
{
	//0.1 定义一个头结点结构体对象
	struct class * list;
	//0.2 (分配空间)
	list = (struct class*)malloc(sizeof(*list));
	//0.3 初始化赋值
	list->class = 0;
	list->num = 0;
	list->yw = 0;
	list->sx = 0;
	list->yy = 0;
	list->first = NULL; //还没有链表让我管理啊
	list->last = NULL;//同上
	
	//返回头结点指针
	return list;
}


/*1.创建一个链表,并用头结点管理(让头结点的指针指向这个链表)*/
struct class *create_linked(struct class * list)
{
	//1.1 定义一个头结点对象
	struct student * p;
	int flag = 1;
	while(1)
	{
		//1.2 用户输入对象的相关数据--->有了一个结点
		p = (struct student *)malloc(sizeof(*p));
		printf("please input id class name yw sx yy\n");
		scanf("%d %d %s %f %f %f",&p->id,&p->class,p->name, \
						&p->yw,&p->sx,&p->yy);
		p->next = NULL; //结点准备完毕

		//1.3 将结点插入到头结点所管理的链表
			//1.3.1 头结点还没有管理链表(first指针还是指向空的)
		if(list->first == NULL)
		{
			list->first = p;
			list->last = p;
		}
				//first last都应该指向 第一个插入的结点
			//1.3.2 头结点已经管理了一个链表
				//按需求将新结点插入该链表
		else
		{
			/*尾插法*/
			list->last->next = p;
			list->last = p;
		}
		list->num++;
		list->yw += p->yw;
		list->sx += p->sx;
		list->yy += p->yy;
		printf("please input a num:0 exit 1 continue\n");
		scanf("%d",&flag);
		if(flag == 0)
		{
			break;
		}
	}
	
	//返回头结点指针
	return list;
}
	
/*2.输出相关的信息*/
void print(struct class * list)
{
	struct student *p = list->first;
	//打印相关信息
	printf("学号\t姓名\t班级\t语文\t数学\t英语\t平均分\n");
	while(p)
	{
		printf("addr:%p\n",p);
		printf("%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t%.2f\n",p->id,p->name,p->class\
				,p->yw,p->sx,p->yy,(p->yw+p->sx+p->yy)/3.0);
		p=p->next;
	}
	printf("%d\t平均分\t%d\t%.2f\t%.2f\t%.2f\n",list->num,list->class\
				,list->yw/list->num,list->sx/list->num,list->yy/list->num);
}



int main(int argc,char *argv[])
{
	struct class * list = create_head();
	printf("please input class:\n");
	scanf("%d",&list->class);
	
	list = create_linked(list);
	
	print(list);
	
	return 0;
}