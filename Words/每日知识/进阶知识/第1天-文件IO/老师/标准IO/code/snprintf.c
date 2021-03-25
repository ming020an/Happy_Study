#include <stdio.h>

int main()
{
	char s[8];
	char *str = "1234567890";
	int r;

	r = snprintf(s, 8, "%s", str);

	printf("r = %d\n",r);
	printf("%s\n",s);
	

	return 0;
}
