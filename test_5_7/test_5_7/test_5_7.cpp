#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
返回参数二进制中 1 的个数 
int count_one_bits(unsigned int value)
{
	int count = 0;
	for(int i = 0; i < 32; i++)
	{
		if ((value & 1) == 1)
		{
			count++;
			value=value >> 1;
		}
		else
			value=value >> 1;
	}
	return count;
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", count_one_bits(n));
	system("pause");
	return 0;
}
获取一个数二进制序列中所有的偶数位和奇数位,分别输出二进制序列
void fun(int n)
{
	for (int i = 0; i < 32; i += 2)
	{
		printf("%d", n & 1);
		n = n >> 2;
	}
}
void fun1(int n)
{
	n = n >> 1;
	for (int i = 0; i < 32; i += 2)
	{
		printf("%d", n & 1);
		n = n >> 2;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	fun(n);
	printf("\n");
	fun1(n);
	system("pause");
	return 0;
}
输出一个整数的每一位
int main()
{
	int data;
	int temp;
	scanf("%d", &data);  // 接收用户输入的整数，并赋值给变量data
	while (data > 0)  // 当data=0或小于0时，退出循环，此时所以位数都已取出
	{
		temp = data % 10;   // 取出data的最低位
		printf("%d ", temp); // 输出最低位
		data /= 10;  // 将去掉data的最低位，次低位变为最低位
	}
	system("pause");
	return 0;
}
int main()
{
	int a, b, temp, count = 0;
	scanf("%d%d", &a, &b);
	temp = a ^ b;
	for (int i = 0; i < 32; i++)
	{
		if ((temp & 1) == 1)
		{
			count++;
			temp = temp >> 1;
		}
		else
			temp = temp >> 1;
	}
	printf("%d", count);
	system("pause");
	return 0;
}