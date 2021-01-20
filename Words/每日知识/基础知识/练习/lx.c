/*
五个学生，分别输入学号01——05，姓名：刘大 钱二 张三 李四 王五；三门课数学 语文
 英语成绩，取平均值。
 */

#include<stdio.h>
int main()
{
char num[5];
printf("请输入学号!\n");
scanf(" %c%c%c%c%c",&num);
printf("%c%c%c%c%c\n",num[0],num[1],num[2],num[3],num[4]);
return 0;

}