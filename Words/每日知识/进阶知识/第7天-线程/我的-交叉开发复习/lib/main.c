#include <stdio.h>
#include "chu.h"
#include "add.h"
#include "jian.h"
#include "cheng.h"

int main ()
{
	int a,b,c,d;
	a = add(2,3);
	b = jian(4,2);
	c = cheng(4,5);
	d = chu(9,3);
	printf("add:2+3=%d  jian:4-2=%d cheng:4*5=%d chu:9/3= %d \n",a,b,c,d);
	return 0;
}
