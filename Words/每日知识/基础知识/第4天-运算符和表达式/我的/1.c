/*五个物件各有自己价值，设一个期望总值，每次取若干物件，计算价值总值，并且与
期望值比较，求出计算价值与期望总值最接近的取出方式*/
#include<stdio.h>

int main(void)
{
int i,n;
int s[100];
//int a,b,c,d,e;
//s[5]={a,b,c,d,e};
for(i=0;i<6;i++)
{
scanf("%d",&s[i]);
printf("%d\n",s[i]);

}
for(i=6;i>5;i--)
{
n++;
printf("%d\n",s[n]);
}
return 0;
}