#include<stdio.h>
#include <string.h>
int insert_sort()
{
    int number[10];     // �������õ���
    int index;          // ���ÿ���������
    int i,j;
    memset(number,0,sizeof(int)*10);
for(i = 1 ;i<10;i++)
{
    printf("�� %d���� =%d\n",i,number[i]);
}

for(i = 1;i<=10;i++)
{
    printf("������� %d����\n",i);
    // ������
    scanf("%d",&index);
    for(j = i;j>0;j--)
    {
        if(number[j-1]>index)
        {   
            number[j]=number[j-1];
        }
        else
        {
            break;
        }
    }
    number[j] = index ;
    }
for(i = 0 ;i<10;i++)
{
    printf("�� %d���� =%d\n",i+1,number[i]);
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