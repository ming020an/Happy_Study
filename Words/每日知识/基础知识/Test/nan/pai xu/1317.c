#include <stdio.h>//头文件
#include <string.h>//字符串
int insert_sort()//插入排序
{
    int number[10];//存放每次排序好的数
    int index;//查找字符串，存放每次输入的数
    int i,j;
    memset(number,0,sizeof(int)*10);
    for(i = 1 ;i<10;i++)
{
    printf("第 %d个数 =%d\n",i,number[i]);
}

    for(i=1;i<=10;i++)//为循环
    {
        printf("请输入第%d个数\n",i);
        scanf ("%d",&index);//输入整数并赋值给index,
        for (j=i;j>0;j++)
        {
            if(number[j-1]>index)//条件函数if
            {
               number[j]=number[j-1]; 
            }
            else 
            {
                break;
            }
        }
        number[j]=index;

    }
    for (i=0;i<10;i++)
    {
        printf ("第%d个数=%d/n",i+1,number[i]);
    }
    return 0;
}
int main ()
{
    int ret;
    ret = insert_sort();
    printf("ret = %d\n",ret);
    return 0 ;
}
