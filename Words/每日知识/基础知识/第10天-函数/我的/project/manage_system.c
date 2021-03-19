/*
 * @Author: lgw
 * @Date: 2021-03-07 19:56:49
 * @LastEditTime: 2021-03-07 21:03:46
 * @LastEditors: Do not edit
 * @FilePath: \project\manage_system.c
 * @Description: 学生成绩管理系统，可以增删改查成绩 v1.0
 */

#include<stdio.h>
#include<string.h>
#define N 100
// 学生名字
char stu_name[N][256];
// 英文成绩
int stu_en_score[N];
// 语文成绩
int stu_ch_score[N];
// 数学成绩
int stu_ma_score[N];

// 记录系统的数据条数
int num =0;

void head_print()
{
    printf("*******学生成绩管理系统*********\n");
    printf("*       请输入以下按键:        *\n");
    printf("*       1、增加学生成绩        *\n");
    printf("*       2、删除学生成绩        *\n");
    printf("*       3、修改学生成绩        *\n");
    printf("*       4、查询学生成绩        *\n");
    printf("*       0、退出系统            *\n");
    printf("*******************************\n");

}

// 初始化
void init_sys()
{
    memset(stu_name,'0',N*256);

    memset(stu_en_score,0,N);
    memset(stu_ch_score,0,N);
    memset(stu_ma_score,0,N);

}

int manage_sys()
{
    int key = 0;

    scanf("%d",&key);

    while (key !=0)
    {
        switch (key)
        {
        case 1:
                insert_score(num);
                num++;
            break;
        case 2:
                del_score();
            break;
        case 3:
                modify_score();
            break;
        case 4:
             select_core();
             break;
        default:
            break;
        }

        printf("请再次输入指令\n");
        scanf("%d",&key);

    }
    return 0;
}

void insert_score(int index)
{
    printf("请输入学生名字!\n");
    scanf("%s",&stu_name[index]);

    printf("请输入学生英语成绩!\n");
    scanf("%d",&stu_en_score[index]);

    printf("请输入学生语文成绩!\n");
    scanf("%d",&stu_ch_score[index]);

    printf("请输入学生数学成绩!\n");
    scanf("%d",&stu_ma_score[index]);

    printf("输入成功！\n");
}

void del_score()
{
    int index = 0;
    int i;
    printf("你决定删除第几条数据？");
    scanf("%d",&index);

    for( i = num ;i>index;index++)
    {
        strcpy(stu_name[index],stu_name[index+1]);
        stu_en_score[index] = stu_en_score[index+1];
    }

}


void modify_score()
{
    printf("你决定修改第几条数据？\n");
    int index = 0;
    scanf("%d",&index);

    insert_score(index);

}

void select_core()
{
    int i=0;
    printf("|NO\t | Name\t | English | Chinese | Math \n");

    for(i=0;i<num;i++)
    {
        printf("|%d\t |%s\t | %d\t | %d\t | %d\t \n",i,stu_name[i],stu_en_score[i],stu_ch_score[i],stu_ma_score[i]);

    }
}

int main()
{
    head_print();
    init_sys();
    manage_sys();
    return 0;
}

