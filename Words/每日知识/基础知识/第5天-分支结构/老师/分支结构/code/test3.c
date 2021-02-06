#include <stdio.h>

int main(void)
{
	int a;
	int t;
	int flag = 0;
	double qian = 0.0;
	scanf("%d",&a);
	
	
	switch(a/100000)
	{
		default:
		case 10://超出百万的部分,1%
			qian += (a-1000000)*0.01;//算超出100w部分的提成
			a = 1000000;//还剩下100w的提成没算
			if(flag)
			{
				printf("100:%lf\n",qian);
			}
		case 9:
			qian += (a-900000)*0.015;//对90w-100w之间的部分提成
			a = 900000;//剩下90w没提成
			if(flag)
			{
				printf("90:%lf\n",qian);
			}
		case 8:
			qian += (a-800000)*0.02;
			a = 800000;
			if(flag)
			{
				printf("80:%lf\n",qian);
			}
		case 7:
			qian += (a-700000)*0.025;
			a = 700000;
			if(flag)
			{
				printf("70:%lf\n",qian);
			}
		case 6:
			qian += (a-600000)*0.03;
			a = 600000;
			if(flag)
			{
				printf("60:%lf\n",qian);
			}
		case 5:
			qian += (a-500000)*0.035;
			a = 500000;
			if(flag)
			{
				printf("50:%lf\n",qian);
			}
		case 4:
			qian += (a-400000)*0.04;
			a = 400000;
			if(flag)
			{
				printf("40:%lf\n",qian);
			}
		case 3:
			qian += (a-300000)*0.045;
			a = 300000;
			if(flag)
			{
				printf("30:%lf\n",qian);
			}
		case 2:
			qian += (a-200000)*0.05;
			a = 200000;
			if(flag)
			{
				printf("20:%lf\n",qian);
			}
		case 1:
			qian += (a-100000)*0.055;
			a = 100000;
			if(flag)
			{
				printf("10:%lf\n",qian);
			}
		case 0:
			break;
	}
	printf("qian=%lf\n",qian);
	
	return 0;
}