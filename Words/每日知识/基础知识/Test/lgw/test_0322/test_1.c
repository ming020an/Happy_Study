#include<stdio.h>
#include<string.h>
#include<windows.h>
typedef struct student
{
    char name[256];
    int math ;
    int chinese;
    int english;
}STU;

struct teacher
{
    char name[256];
    int height;
};


// 功能：结构体的使用
int main()
{
    STU test_s;
    struct teacher test_t;
    strcpy(test_s.name,"zhangsan");
    test_s.math = 100;
    test_s.english = 99;
    test_s.chinese = 88;

    strcpy(test_t.name,"lisi");
    test_t.height = 800;
    printf("name = %s,math =%d,english = %d, chinese = %d\n",test_s.name,test_s.math,test_s.english,test_s.chinese);
    printf("name = %s,height =%d\n",test_t.name,test_t.height);
    system("pause");
    return 0;
}