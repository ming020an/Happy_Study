#include <stdio.h>
#include <errno.h>


int main()
{
	#if 0
	//char s[8];
	//char *s; //s指向哪个空间，不知道!!!! malloc一个空间，赋值给s

	char *s = "12345"; //s指向一块只读空间，gets(s)也是有问题的

	gets(s);//必须要确保s指向的一块空间，是可以写的。

	#endif

	char s1[8];
	char s2[8] = {"12345"};

	printf("%p\n%p\n",s1,s2);

	//gets(s1); //假设用户输入大于8个字符，程序的行为是undefined 
	fgets(s1, 9, stdin);
	
	printf("%s\n%s\n", s1,s2);
	
}
