#include <stdio.h>
#include <stdlib.h>

//node
//student
typedef struct student
{
	int id;//学号
	char name[20];//姓名
	char class[10];//班级名称
	float chin_ese;//语文成绩
	float ma_th;//数学成绩
	float eng_lish;//英语成绩
	struct student *next;
	
}STU;//NODE;

//head_node
//class
typedef struct class//head_node
{
	int cla_ss; //班级
	int class_num; //人数
	float yw;  //语文总分
	float sx; //数学总分
	float yy; //英语总分
	STU *head;//NODE *head;
	STU *tail;//NODE *tail;
	int len ;
} CLA;//head_NODE;

     
  //head_NODE * creat_list()
  CLA *creat_list()//创建头结点，并且初始化
{
	CLA *l;//head_NODE *l;
	l=(CLA *)malloc(sizeof (CLA));
	l->cla_ss=0;
	l->class_num=0;
	l->yw=0;
	l->sx=0;
	l->yy=0;
	l->head=NULL;
	l->tail=NULL;
	l->len=0;
	return l;
}


//head_printf(l,data)
void head_printf(CLA *l,STU *tx)//头结点指向头结点对象
{
	if(l->len<=0)
	{
		l->head=tx;
		l->tail=tx;
		l->len=1;
	}
	
	else
	{
		tx->next=l->head;
		l->head->next=tx;
		l->len++;
	}
	
}
/*打印链表*/
void print_linked(struct student*head)
{
	struct student *p = head;
	printf("ID\t名字\t班级\t语文成绩\t数学成绩\t英语成绩\t\n");
	while(p)
	{
		printf("%d\t%s\t%s\t%.2f\t%.2f\t%.2f\t\n",p->id,p->name,p->class,p->chin_ese,p->ma_th,p->eng_lish);
		p = p->next;
	}
	printf("\n");
}
 /*void printf_list(CLA *l,STU *t)//打印链表
{
	if(l->len<=0)
	{
		printf("NULL_LIST\n");
	}
	
	else
	{
		l->head=t;
	while(t)
	{
		printf("%d %s %s %f %f  %f\t",t->id,t->name,t->class,t->chin_ese,t->ma_th,t->eng_lish);
		t=t->next;
	}
	}

}
*/
int main(int argc ,char *argv[])
{
	STU *tx;
	tx->next=NULL;
	CLA *l;//head_NODE *l;
	l=creat_list();
	int num,i;
	printf("请输入学生的的人数\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		STU *list =(STU*)malloc(sizeof(*list));
		printf("请输入第%d个同学的学号\n",i+1);
		scanf("%d",&tx[i].id);
		getchar();
		printf("请输入第%d个同学的姓名\n",i+1);
		scanf("%s",tx[i].name);
		getchar();
		printf("请输入第%d个同学的班级名称\n",i+1);
		scanf("%s",tx[i].class);
		getchar();
		printf("请输入第%d个同学的语文成绩\n",i+1);
		scanf("%f",&tx[i].chin_ese);
		getchar();
		printf("请输入第%d个同学的数学成绩\n",i+1);
		scanf("%f",&tx[i].ma_th);
		getchar();
		printf("请输入第%d个同学的英语成绩\n",i+1);
		scanf("%f",&tx[i]. eng_lish);
		getchar();
		head_printf(l,tx);
		
	}
		//printf_list(l,l->head);
		print_linked(l->head);
		printf("\n");
	
		return 0;
}