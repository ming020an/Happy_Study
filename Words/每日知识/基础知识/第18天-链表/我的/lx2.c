#include<stdio.h>
#include<stdlib.h>
typedef struct creat_class
{
	int clanum; //班级
	int clasum; //人数
	float yw;  //语文总分(平均分)
	float sx; //数学总分(平均分)
	float yy; //英语总分(平均分)
	//STU *first;
	//STU *last;
	//int num;
}CS;
typedef int ElemType;

typedef struct creat_student
{
	int id;
	char name[50];
	int class;
	float yw;
	float sx;
	float yy;
	struct creat_student*next;
}STU; //结点结构体

typedef struct list
{
	STU *first; //用来指向链表的第一个结点
	STU *last; //用来只想链表的最后一个结点
	ElemType num; //链表结点数
}LIST; //头结点结构体


/*
 *create_list 用来创建头结点的函数
 */
LIST * create_list(void)
{
	/*定义一个头结点指针,分配空间*/
	LIST *list = (LIST*)malloc(sizeof(*list));
	list->num = 0;
	list->first = NULL;
	list->last = NULL;

	return list;
}

LIST * create_linked(LIST *list,CS * t)
{
	STU *p =NULL;
	while(1)
	{
		/*0.分配一个结点空间*/
		p=(STU*)malloc(sizeof(*p));
		scanf("%d %s %d %f %f %f",&p->id,p->name,&p->class,&p->yw,&p->sx,&p->yy);
		p->next = NULL;
		t->yw+=p->yw;
		t->sx+=p->sx;
		t->yy+=p->yy;
		if(p->id == 0)
		{
			break;
		}
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
/*打印链表*/
void print_linked(struct creat_student*head)
{
	struct creat_student *p = head;
	printf("ID\t名字\t班级\t语文成绩\t数学成绩\t英语成绩\t\n");
	while(p)
	{
		printf("%d\t%s\t%d\t%.2f\t%.2f\t%.2f\t\n",p->id,p->name,p->class,p->yw,p->sx,p->yy);
		p = p->next;
	}
	printf("\n");
}

int main(void)
{
	/*0.创建一个头节点 用来标识一个链表*/
	LIST* list = create_list();
	/*1.创建链表*/
	CS * t=(CS*)malloc(sizeof(*t));
	t->clanum=139;
	list = create_linked(list,t);
	t->clasum=list->num;
	/*2.打印*/
	print_linked(list->first);
	printf("班级\t人数\t语文总分\t数学总分\t英语总分\n");
	printf("%d\t%d\t%.2f\t%.2f\t%.2f\t\n",t->clanum,t->clasum,t->yw,t->sx,t->yy);
	//printf("%d\n",list->num);
	
	return 0;
}