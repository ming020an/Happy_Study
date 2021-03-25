#include<stdio.h>
#include<errno.h>
struct student
{
	int ID;
	char name[10];
	int s_core;
};
struct student stu[20];
int main()
{
	FILE *fp=NULL;
	fp=fopen("st-core","w");
	if(fp==NULL)
	{
	printf("open erro");
	}
	fseek(fp,0,SEEK_SET);
	//char a[50]={"struggle for a better future!"};
		/*
		printf("请输入学生序号\n");
		scanf("%d",&(stu[0].ID));
		printf("请输入学生名字\n");
		scanf("%s",stu[0].name);
		printf("请输入学生成绩\n");
		scanf("%d",&stu[0].s_core);
		printf("第一个学生信息输入完毕\n");*/
		
	int re;
	re=fwrite(stu,sizeof(stu[0]),1,fp);
	if(re==-1)
	{
		printf("write erro");
		fclose(fp);
		return -1;
	}
	fclose(fp);
		
	return 0;
}
