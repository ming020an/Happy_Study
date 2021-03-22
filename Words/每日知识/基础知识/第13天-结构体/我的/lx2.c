#include<stdio.h>
struct student
		{
			int id;
			char name[50];
			char sex; 
			char class[20];
			char addr[50];
			long phonenum;
		};
int main (void)
{
	struct student lgw;
	printf("请输入名字！");
	
	scanf("%s",lgw.name);
	
	printf("请输入性别！");
	getchar();
	scanf("%c",&lgw.sex);
	
	printf("请输入班级！");
	
	scanf("%s",lgw.class);
	
	printf("请输入地址！");
	
	scanf("%s",lgw.addr);
	
	//struct student *t;
	
	printf("%s--%c--%s--%s\n",lgw.name,lgw.sex,lgw.class,lgw.addr);
}