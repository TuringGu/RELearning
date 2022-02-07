#include <stdio.h>
#include <ctype.h>  

int main()
{
	// if  switch  goto
	// continue: jump out of this cycle, execute next cycle
	// break: jump out of the big cycle

	// && || !
	// and or not

	// isalpha()  isalnum()  isblank()  iscntrl()  isdigit()  isgraph()  islower()
	// isprint()  ispunct()  isspace()  isupper()  isxdigit()
	char a;
	a = getchar();
	int flag = isalpha(a);	// Need to declare header file <ctype.h>

	return 0;
}