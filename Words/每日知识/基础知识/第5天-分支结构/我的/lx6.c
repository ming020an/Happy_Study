#include<stdio.h>
int main()
{
	int a,sum;
	scanf("%d",&a);
	switch(a/100000)
	{
		case 0:
			sum=0;
			break;
		case 1:
		sum= (a-100000)*55/1000;
			break;
		case 2:
		sum= 100*55+(a-200000)*50/1000;
			break;
		case 3:
		sum= 100*(55+50)+(a-300000)*45/1000;
			break;
		case 4:
		sum= 100*(55+50+45)+(a-400000)*40/1000;
			break;
		case 5:
		sum= 100*(55+50+45+40)+(a-500000)*35/1000;
			break;
		case 6:
		sum= 100*(55+50+45+40+35)+(a-600000)*30/1000;
			break;
		case 7:
		sum= 100*(55+50+45+40+35+30)+(a-700000)*25/1000;
			break;	
		case 8:
		sum= 100*(55+50+45+40+35+30+25)+(a-800000)*20/1000;
			break;	
		case 9:
		sum= 100*(55+50+45+40+35+30+25+20)+(a-900000)*15/1000;
			break;
		case 10:
		default:
		sum= 100*(55+50+45+40+35+30+25+20+15)+(a-1000000)*10/1000;
			break;			
	}
	printf("%d\n",sum);
	return 0;

}