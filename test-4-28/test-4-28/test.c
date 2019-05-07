#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
非递归法求斐波那契数
int fib(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	if (n <= 2)
		return 1;
	else
	{
		for (int i = 0; i < n - 2; ++i)
		{
			c = a + b;
			a = b;
			b = c;
		}
		return c;
	}

}
int main()
{
	int a,n;
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d", ret);
	system("pause");
	return 0;
}
递归法求斐波那契数列
int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}
int main()
{
	int n;
	scanf("%d", &n);
	int ret = fib(n);
	printf("%d", ret);
	system("pause");
	return 0;
}
计算n^k
int fun(int n, int k)
{
	if (k == 0)
		return 1;
	else if (k == 1)
		return n;
	else
		return n * fun(n, k - 1);
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int ret = fun(n, k);
	printf("%d", ret);
	system("pause");
	return 0;
}
输入一个非负整数，返回组成它的数字之和
int DigitSum(n)
{
	if (n > 0)
		return n % 10 + DigitSum(n / 10);
	return 0;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", DigitSum(n));
	system("pause");
	return 0;
}
int main()
{
	char a;
	scanf("%s", &a);
	reverse_string(char * string);
	printf("%s", a);
	system("pause");
	return 0;
}
int my_strlen(char *p)
{
	int count = 0;
	while (*p++ != '\0')
	{
		count++;
	}
	return count;
}
int my_strlen(char *p)
{
	int count = 0;
	while (*p != '\0')
	{
			count++;
			*p++;
	}
	return count;
}
int main()
{
	char *a = "cbobibik";
	printf("%d\n", my_strlen(a));
	system("pause");
	return 0;
}
编写一个函数 reverse_string(char * string)（递归实现） 
void reverse_string(char *string)
{
	if ('\0' != *(++string))
		reverse_string(string);
	printf("%c", *(string - 1));
}

int main()
{
	char *a = "abcde";
	reverse_string(a);
	printf("\n");
	system("pause");
	return 0;
}
递归和非递归分别实现求n的阶乘
int fun(n)
{
	int sum;
	if (n == 1)
		sum = 1;
	else 
		sum = n * fun(n - 1);
	return sum;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fun(n));
	system("pause");
	return 0;
}
int fun(int n)
{
	int sum=1;
	for (int i = 1; i <=n; i++)
	{
		sum = sum * i;
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fun(n));
	system("pause");
	return 0;
}
递归方式实现打印一个整数的每一位
void print(int n)
{
	if (n < 9)
		printf("%d ", n);
	else
	{
		printf("%d ", n % 10);
		print(n / 10);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	print(n);
	system("pause");
	return 0;
}
