//.求1024的65535次方后三位是多少
//./4.exe
//ls/1#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[10],i,j;
    for(i=0;i<10;i++)
    {
        a[i]=0;                  //初始化
    }                                      
    for(i=0;i<5;i++)
    {
        scanf("%d",&j);         //输入
        a[j]=a[j]+1;                    //计数
    }
    for(i=0;i<10;i++)      /*如果需要逆序只需要改为for(i=9;i>=0;i--)即可*/
    {
    for(j=1;j<=a[i];j++)
    {    printf("%d",i);}     //打印输出
    }
}

 
