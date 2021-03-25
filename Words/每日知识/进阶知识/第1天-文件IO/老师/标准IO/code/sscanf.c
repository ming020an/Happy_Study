#include <stdio.h>

int main()
{
	//const char *str = "ABCD1234 A";
	const char *str = "1234BCDDDDD";
	int r ;
	int a ;
	char c;
	r = sscanf(str, "%d %c", &a, &c);
	

	printf("a = %d c = %c r = %d\n", a, c, r );

	return 0;
					
}
