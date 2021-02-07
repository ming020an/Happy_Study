/*
 * @Author: lgw
 * @Date: 2021-02-07 16:31:03
 * @LastEditTime: 2021-02-07 16:44:23
 * @LastEditors: Do not edit
 * @FilePath: \test_0207\test_4.c
 * @Description: 
 */
int main(void)
{
	int li_y = 0;
    int sum = 0;
    //int a,b;
  for ( li_y = 1;li_y <= 1000; li_y++)
  {
    if(li_y == 100)
    {
        continue;
    }  
    sum = li_y + sum;
    // if(i == 100)
    // {
    //     break;
    // }
    
  }
   printf("li_y = %d ,sum =%d",li_y,sum);





	return 0;	
}