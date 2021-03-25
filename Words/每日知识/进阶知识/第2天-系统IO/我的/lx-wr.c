#include<stdio.h>
struct student
{
	int ID;
	char name[10];
	int s_core;
};
int main()
{
	FILE * fp=fopen("xinxi.txt""w");
		printf("请输入学生序号\n");
		scanf("%d",&(stu[0].ID));
		printf("请输入学生名字\n");
		scanf("%s",stu[0].name);
		printf("请输入学生成绩\n");
		scanf("%d",&stu[0].s_core);
		printf("第一个学生信息输入完毕\n");
}