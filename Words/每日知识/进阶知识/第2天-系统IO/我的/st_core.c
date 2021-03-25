#include<stdio.h>

struct student
{
	int ID;
	char name[10];
	int s_core;
};
struct student stu[20];
void in();
//void del();
//void modify();
//void search();
//void show();
int main ()
{	int n,m;
	printf("请输入命令序号\n");
	printf("1录入，2删除，3修改，4寻找，0退出\n");
	scanf("%d",&n);
	while(n)
	{
		switch(n)
		{
			case 1:
				in();
				break;
			/*	case 2:
				del();
				break;
			case 3:
				modify();
				break;
			case 4:
				search();
				break;
				*/
			default:
				break;
		}
		printf("请再次输入指令\n");
		scanf("%d",&n);
	}
	
		
}

void in()
{	
	
	int i,m;
	FILE * fp=NULL;
	fp=fopen("st_core","ab+");
	//printf("33333333333333333\n");
	fclose(fp);
	//printf("lllllllllllllllllllll\n");
	fp=fopen("st_core","w");
	if(m==0)
	{
		printf("请输入学生序号\n");
		scanf("%d",&(stu[0].ID));
		printf("请输入学生名字\n");
		scanf("%s",stu[0].name);
		printf("请输入学生成绩\n");
		scanf("%d",&stu[0].s_core);
		printf("第一个学生信息输入完毕\n");
	}
	else
	{
		printf("请输入学生序号\n");
		scanf("%d",&stu[m].ID);
		printf("请输入学生名字\n");
		scanf("%s",stu[m].name);
		printf("请输入学生成绩\n");
		scanf("%d",&stu[m].s_core);
		printf("新学生信息输入完毕\n");
		m++;
	}
	
	for(i=0;i<m;i++)
	{
		fwrite(&stu[i],sizeof(stu[0]),1,fp);
		printf("%d%s%d",stu[m].ID,stu[m].name,stu[m].s_core);
	}

	
}


/*void show()
{
	FILE *fp=NULL;
	int i,m=0;
	fp=fopen("st_core","ab+");
		printf("222222222222222222\n");
	fclose(fp);
	printf("ID\t\t name\t\t score\t\t\n");
	for(i=0;i<m;i++)
	printf("%d%s%d",stu[m].ID,stu[m].name,stu[m].s_core);
}*/