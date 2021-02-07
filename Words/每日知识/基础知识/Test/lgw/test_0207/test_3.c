/*
 * @Author: lgw
 * @Date: 2021-02-07 16:22:12
 * @LastEditTime: 2021-02-07 16:27:00
 * @LastEditors: Do not edit
 * @FilePath: \test_0207\test_3.c
 * @Description: 
 */
int main(void)
{
	int i = 1;
    int sum = 0;
   while(i<1)
   {
        i++;
        sum = i + sum;
   }
   printf("i = %d ,sum =%d",i,sum);

	return 0;	
}