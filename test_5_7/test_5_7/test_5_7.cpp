#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
���ز����������� 1 �ĸ��� 
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
��ȡһ�������������������е�ż��λ������λ,�ֱ��������������
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
���һ��������ÿһλ
int main()
{
	int data;
	int temp;
	scanf("%d", &data);  // �����û����������������ֵ������data
	while (data > 0)  // ��data=0��С��0ʱ���˳�ѭ������ʱ����λ������ȡ��
	{
		temp = data % 10;   // ȡ��data�����λ
		printf("%d ", temp); // ������λ
		data /= 10;  // ��ȥ��data�����λ���ε�λ��Ϊ���λ
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