/*
 * @Author: lgw
 * @Date: 2021-02-07 15:54:42
 * @LastEditTime: 2021-02-07 16:27:08
 * @LastEditors: Do not edit
 * @FilePath: \test_0207\test_2.c
 * @Description: 
 */
int main(void)
{
	int i = 1;
    int sum = 0;
   do
   {
        i++;
        sum = i + sum;
   } while (i < 1);
   printf("i = %d ,sum =%d",i,sum);

	return 0;	
}

