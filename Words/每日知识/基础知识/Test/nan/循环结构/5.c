/*
 * @Author: lgw
 * @Date: 2021-02-17 14:37:10
 * @LastEditTime: 2021-02-17 15:43:23
 * @LastEditors: Do not edit
 * @FilePath: \循环结构\5.c
 * @Description: 
 */
#include <stdio.h>
int main()
{
   int a = 1;
flag :
   a++;

  if(a<=18)
  {
    printf("a=%d\n",a);
    goto flag;
  }
  printf("a=%d\n",a);
  return 0;
}
