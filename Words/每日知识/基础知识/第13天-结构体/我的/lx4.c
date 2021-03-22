#include<stdio.h>
#include<>

struct student
{
	char sex;
	int id;
	int core;
	char name[20];
	char addr[20];
};
void print(struct student a[5],int b);
int main (void)
	{
		struct student a[5];
		int i,b,j;
		for(i=0;i<5;i++)
		{
			printf("请输入第%d个学生ID！\n",i+1);
			scanf("%d",&a[i].id);
			printf("请输入第%d个学生名字！\n",i+1);
			//scanf("%s",a[i].name);           
			gets(a[i].name);
			printf("请输入第%d个学生性别！\n",i+1);
			scanf("%c",&a[i].sex);
			
			printf("请输入第%d个学生分数!\n",i+1);
			scanf("%d",&a[i].core);
			//getchar();
			//getchar();
			printf("请输入第%d个学生地址！\n",i+1);
			//getchar();
			scanf("%s",a[i].addr);
		}
		for(j=1;j<=5;j++)
		{
			b=j;
			print(a, b);
		}
	}	
	
	void print(struct student a[5],int b)
	{
		printf("第%d个学生ID:%d\n",b,a[b].id);
		printf("第%d个学生名字:%s\n",b,a[b].name);
		printf("第%d个学生性别:%c\n",b,a[b].sex);
		printf("第%d个学生分数:%d\n",b,a[b].core);
		printf("第%d个学生地址:%s\n",b,a[b].addr);
	}
	