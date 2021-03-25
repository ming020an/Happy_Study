/*************************************************************************
	> File Name: seqstack.c
	> Author: 欧阳华亮
	> Mail: hualiang0305@foxmail.com 
	> Created Time: Tue 06 Feb 2018 05:25:44 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX 100

typedef int ElemType;

/*对于顺序栈来说插入和删除都在栈顶进行(小标为top的地方)*/
struct seqstack
{
	ElemType Elem[MAX]; //存放栈中元素的数组
	int top; //栈顶的下标
};//用来表示一个栈

/*初始化栈*/
struct seqstack *InitStack(void)
{
	struct seqstack *s = (struct seqstack*)malloc(sizeof(*s));
	memset(s,0,sizeof(*s));
	s->top = -1;
	
	return s;
}

/*销毁栈*/
void DestroyStack(struct seqstack* s)
{
	if(s)
	{
		free(s);
	}
}

/*清空栈*/
struct seqstack *ClearStack(struct seqstack* s)
{
	s->top = -1;
	return s;
}

/*判断栈是否为空*/
int StackEmpty(struct seqstack* s)
{
	return s->top == -1;
}

/*获取栈的长度*/
int StackLength(struct seqstack* s)
{
	return s->top + 1;
}

/*获取栈顶元素(不出栈的获取)*/
ElemType GetTop(struct seqstack* s)
{
	return s->Elem[s->top]; 
}

/*出栈*/
ElemType Pop(struct seqstack* s)
{
	ElemType tem = s->Elem[s->top];
	s->top--;
	return tem;
}

/*入栈*/
struct seqstack*Push(struct seqstack* s,ElemType x)
{
	s->Elem[++s->top] = x;
	return s;
}

//142+24*31+42/5+66-812*6/2
//进制转换 将一个任意的十进制数转换成任意进制

int main(void)
{
	int num , x;
	int n;
	scanf("%d",&num);
	scanf("%d",&x);
	/*将十进制的num转换成x进制*/
	struct seqstack* s = InitStack();
	
	printf("%d的%d进制为:",num,x);
	while(num)
	{
		n=num%x;
		Push(s,n);
		num = num/x;
	}
	
	while(!StackEmpty(s))
	{
		n=Pop(s);
		if(n>=10 && n < x)
		{
			printf("%c",n - 10 + 'A' );
		}
		else
			printf("%c",n+'0');
	}
	printf("\n");
}