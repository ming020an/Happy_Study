#include <stdio.h>
#include <string.h>
typedef struct student
{
    char name[256];
    int chinese;
    int math;
    int english;
} STU;


void head_print()
{
    printf ("       学生管理系统     \n");
   printf("请输入以下按键\n");
    printf("       1 增加学生成绩   \n");
    printf ("       2 删除学生成绩   \n");
    printf("       3、修改学生成绩        *\n");
    printf("     4、查询学生成绩        *\n");
    printf("       0 退出系统       \n");
}
int manage_system()
{
    int key;
    int i;
    int index;
    int num=0;//用来存放学生数量
    STU str_stu[100];// 用来存放学生信息
    memset(str_stu,0,sizeof (STU)*100);
    scanf("%d",&key);

    while(key!=0)
    {
        if (key==1)
        {
            //增加成绩
            printf("请输入学生名字!\n");
             scanf("%s",&str_stu[num].name);
            printf("请输入学生语文成绩");
            scanf("%d",&str_stu[num].chinese);
            printf ("请输入学生数学成绩");
            scanf("%d",&str_stu[num].math);
            printf ("请输入学生英语成绩");
            scanf("%d",&str_stu[num].math);
            num++
           printf("输入成功！\n");
        }
        else if (key==2)
        {

        }
        //删除学生成绩
        if(num == 0)
        {
            printf("系统没有数据，你个憨憨！！\n"); 
        }
        printf ("你想删除哪一个学生");
        scanf("%d",&index);
        for (i=num;i>=index;i++)
        {
            strcpy(str_stu[index].name,str_stu[index+1].name);
            str_stu[index].chinese= str_stu[index+1].chinese;
                str_stu[index].english= str_stu[index+1].english;
                str_stu[index].math= str_stu[index+1].math;

        }
        num--;
    }
}
 else if(key == 3)
{
    printf("你想修改哪一个学生\n");
        scanf("%d",&index);

        printf("请输入学生名字!\n");
        scanf("%s",&str_stu[index].name);
        printf("请输入学生英语成绩!\n");
        scanf("%d",&str_stu[index].english);

        printf("请输入学生语文成绩!\n");
        scanf("%d",&str_stu[index].chinese);

        printf("请输入学生数学成绩!\n");
        scanf("%d",&str_stu[index].math);

        printf("输入成功！\n");
}
else if(key == 4)
    {
        //4、查询学生成绩
        printf("|NO\t | Name\t | English | Chinese | Math \n");
        for(i = 0;i<num;i++)
        {
            printf("|%d\t |%s\t | %d\t | %d\t | %d\t \n",i,str_stu[i].name,str_stu[i].english,str_stu[i].chinese,str_stu[i].math);
        }
    }
    else
    {
        // 提示错误
        printf("你输错了！哈哈哈 \n");

    }
    printf("请再次输入指令 \n");
    scanf("%d",&key);
}
   return 0;
}

   int main()
{
    head_print();
    manage_system();

    return 0;

}
