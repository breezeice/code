//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a[10],max;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d",&a[i]);
//	}
//	max = a[0];
//	for (int i = 1; i < 10; i++)
//	{
//		if (a[i] > max) max = a[i];
//	}
//	printf("最大值为%d\n",max);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b, c,max;
//	scanf("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		max = b;
//		b = a;
//		a= max;
//	}
//	if (a < c)
//	{
//		max = c;
//		c= a;
//		a= max;
//	}
//	if (b < c)
//	{
//		max = c;
//		c= b;
//		b = max;
//	}
//	printf("%d %d %d\n", a, b, c);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a,b,i;
//	scanf("%d%d", &a, &b);
//	while (a%b != 0)
//	{
//		i = a % b;
//		a = b;
//		b = i;
//	}
//	printf("%d\n", b);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[10], b[10],temp;
//	for (int i = 0; i < 10; ++i)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		scanf("%d", &b[i]);
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		temp = a[i];
//		a[i] = b[i];
//		b[i] = temp;
//	}
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//	for (int i = 0; i < 10; ++i)
//	{
//		printf("%d ", b[i]);
//	}
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	double a,i,sum = 0;
//	for (i = 1; i <= 100; ++i)
//	{
//		a = i * pow(-1, i - 1);
//		sum += 1/ a;
//	}
//	printf("%lf", sum);
//	system("pause");
//	return 0;
//}
//
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0,j=0;
	for (i = 1; i < 13 / 2 + 1; ++i)
	{
		for (j = 1; j <= 2 * i - 1; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 13 / 2 + 1; i >= 1; --i)
	{
		for (j = 2 * i - 1; j >= 1; --j)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int n, a, b, c;
	scanf("%d", &n);
	a = n / 100;
	b = n % 100 / 10;
	c = n % 10;
	if (n == pow(a, 3) + pow(b, 3) + pow(c, 3))
		printf("%d是水仙花数\n", n);
	else 
		printf("%d不是水仙花数\n", n);
	system("pause");
	 return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b,c,d,e,sum;
	scanf("%d", &a);
	b = a * 10 + a;
	c = b * 10 + a;
	d = c * 10 + a;
	e = d * 10 + a;
	sum = a + b + c + d + e;
	printf("%d\n", sum);
	system("pause");
	return 0;
}