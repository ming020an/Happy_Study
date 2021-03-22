#include <stdio.h>

H(int n,char i,char j,char k)
{
	//usleep(400000);
	if(n == 1)
	{
		printf("end:%c---->%c\n",i,k);
	}
	else
	{
		H(n-1,i,k,j);//n-1个盘子,是要移动到中间柱子上,这个时候可以借用目标柱子		
		printf("mid:%c--->%c\n",i,k);//第n个盘子
		//执行完上面的步骤后,n-1个盘子在j上
		H(n-1,j,i,k);
	}

}
	
	
int main(void)
{
	H(1000,'A','B','C'); // 20个盘子,从A上借助B移动到C
}		