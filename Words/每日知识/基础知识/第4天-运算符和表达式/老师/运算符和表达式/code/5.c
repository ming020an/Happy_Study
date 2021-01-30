#include <stdio.h>

int main(void)
{
	char a = 0x21;
	char b = 0x43;
	char c = 0x65;
	char d = 0x87;
	
	int t = d | c<<8 | b<<16 | a<<24;
	printf(":0x%x\n",t);
	
	return 0;
}