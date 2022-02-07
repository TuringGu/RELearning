#include <stdio.h>
#include <string.h> 
#include <stdlib.h>

//————————————————
//版权声明：本文为CSDN博主「诡白丷」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/weixin_44579240/article/details/89603800

int Preemption(char a, char b)                           //符号优先级比较,a为当前读入，b为栈顶元素 
{
	int c;                                              //c反馈指令信息 0.结束 1.弹出 2.进栈 3.删除当前元素及栈顶元素 4.报错 
	switch (a)
	{
	case '#':if (b == '#') c = 0;
			 else c = 1; break;
	case '+':if (b == '#' || b == '(') c = 2;
			 else c = 1; break;
	case '-':if (b == '#' || b == '(') c = 2;
			 else c = 1; break;
	case '*':if (b == '*' || b == '/') c = 1;
			 else c = 2; break;
	case '/':if (b == '*' || b == '/') c = 1;
			 else c = 2; break;
	case '(':c = 2; break;
	case ')':if (b == '(') c = 3;
			 else c = 1; break;
	default:c = 4; break;
	}
	return c;
}

// Only support int input
int main()
{
	char str[50] = { "\0" };
	char *p = str;
	double *p3, *p4, a = 0, b = 0;
	char *p1, *p2;
	char stack1[20];                      //符号栈 栈顶指针p2，栈底指针p1 
	double stack2[20];                       //数字栈 栈顶指针p4，栈底指针p3 
	p1 = p2 = stack1;
	p3 = p4 = stack2;
	*p2++ = '#';
	printf("请输入需要计算的算术表达式：");
	gets(str);
	strcat(str, "#");
	while (*p != '\0')
	{
		if (*p <= '9'&&*p >= '0')
		{
			a = a * 10 + (*p - '0');
			if (*(p + 1)>'9' || *(p + 1)<'0')
			{
				*p4++ = a;
				a = 0;
			}
			p++;
		}
		else
		{
			switch (Preemption(*p, *(p2 - 1)))
			{
			case 0:
				printf("计算结果为:%lf\n", *p3);
				p++;
				break;
			case 1:
				b = *--p4;
				switch (*(--p2))
				{
				case '+':*(p4 - 1) = *(p4 - 1) + b; break;
				case '*':*(p4 - 1) = *(p4 - 1) * b; break;
				case '-':*(p4 - 1) = *(p4 - 1) - b; break;
				case '/':*(p4 - 1) = *(p4 - 1) / b; break;
				}
				break;
			case 2:
				*p2++ = *p++;
				break;
			case 3:
				p++;
				p2--;
				break;
			case 4:
				printf("程序读到了无法计算的符号，出错了\n");
				p++;
				break;
			}
		}
	}

	system("pause");
	return 0;
}
