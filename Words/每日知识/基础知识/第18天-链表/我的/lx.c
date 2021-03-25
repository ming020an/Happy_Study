#include <stdio.h>
#include <stdlib.h>

typedef struct creat_student
{
	int id;
	char name[50];
	int class;
	float yw;
	float sx;
	float yy;
	struct creat_student*next;
}STU;

typedef struct creat_link
{
	STU *first;
	STU *last;
	int num;
}LIST;

LIST * create_list(void)
{
	/*定义一个头结点指针,分配空间*/
	LIST *list = (LIST*)malloc(sizeof(*list));
	list->num = 0;
	list->first = NULL;
	list->last = NULL;

	return list;
}

LIST*creat_link(LIST* list)
{
	STU*pre=NULL;
	STU*now=NULL;
	LIST *list=NULL;

	while(1)
	{
		STU *p = (STU*)malloc(sizeof(*p));
		printf("请分别输出学生id，名字，班级，语文，数学，英语！");
		scanf("%d %s %d %f %f %f",&p->id,p->name,&p->class,&p->yw,&p->sx,&p->yy);
		p->next=NULL;
		if(list->first==NULL)/*判断是否有链表*/
		{
			list->first=p;
			list->last=p;
		}
		else
		{
			list->last->next = p;
			list->last = p;
		}
			list->num++;
	}
	return list;
}
	

void print_link(struct link *head)
{
	struct link *p = head;
	while(p)
	{
		printf("%d  %s  %d  %f  %f  %f",p->id,p->name,p->class,p->yw,p->sx,p->yy);
		p=p->next;
	}
	printf("\n");

}	
int main (void)
{
	LIST* list = creat_list();
	/*创造一个链表*/
	LIST*list=student_link();
	/*打印链表*/
	print_link(head);
	return 0;
}

/*typedef struct creat_class
{
	int clanum; //班级
	int clasum; //人数
	float yw;  //语文总分(平均分)
	float sx; //数学总分(平均分)
	float yy; //英语总分(平均分)
	//STU *first;
	//STU *last;
	//int num;
}CS;*/

