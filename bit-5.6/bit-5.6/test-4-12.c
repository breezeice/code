#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void menu()
//{
//	printf("************************\n");
//	printf("*********1.play*********\n");
//	printf("*********0.exit ********\n");
//	printf("************************\n");
//}
//void game()
//{
//	int ret = 0;
//	int game = 0;
//	 ret = rand()%100+1;
//	while (1)
//	{
//		printf("�����:\n");
//		scanf("%d", &game);
//		if(game>ret)
//		{
//			printf("�´���\n");
//		}
//		 else if(game < ret)
//		{
//			printf("��С��\n");
//		}
//		else
//		{
//			printf("�¶���\n");
//			break;
//		}
//	}
//}
//int main()
//{
//	int input;
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("��ѡ��");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��:\n");
//			break;
//		}
//	} while (input);
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int main()
//{
//	int i=0;
//	char input[] = { 0 };
//	char code[10] = {"wei123"};
//	printf("���������룺");
//	while (i < 3)
//	{
//		scanf("%s", &input);
//		if (strcmp(input,code )==0)
//		{
//			printf("��¼�ɹ�\n");
//			break;
//		}
//		else
//		{
//			printf("�����������������:");
//		}
//		++i;
//	}
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	int a[]={ 1,2,3,4,5,6,7,8,9,10 };
//	int mid,k;
//	int left = 0;
//	int right = sizeof(a) / sizeof(a[0]);
//	scanf("%d", &k);
//	while (left <= right)
//	{
//		mid = left + (right - left) / 2;
//		if (a[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (a[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//			break;
//	}
//	if(left<=right)
//		printf("�ҵ����±�Ϊ��%d\n", mid); 
//	else 
//		printf("�Ҳ���\n");
//	system("pause");
//	return 0;
//}
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	char a;
//	while (1)
//	{
//		scanf("%c", &a);
//		if (a <= 122 && a >= 97)
//			printf("%c\n", a - 32);
//		else if (a <= 90 && a >= 65)
//			printf("%c\n", a + 32);
//	}
//	system("psuse");
//	return 0;
//}
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a;
	scanf("%d", &a);
	for (int i = 1; i <=a; ++i)
	{
		for (int j=1; j <= i; ++j)
		{
			int sum = i * j;
			printf("%d*%d=%d ", i, j, sum);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
void swap(int *x, int *y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y =tmp;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("%d %d", a, b);
	system("pause");
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int  if_leap_year(int year)
{
	if (year % 4 == 0 && year % 1 != 0 || year % 400 == 0)
		return 1;
	else 
		return 0;
}
int main()
{
	int year;
	scanf("%d", &year);
	int ret=if_leap_year(year);
	if (ret = 1)
		printf("%d������\n", year);
	else
		printf("%d��������\n", year);
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
int if_suhsu(int a)
{
	int i = 2;
	while (i<a)
	{
		if (a%i == 0)
			return 0;
		else
			i++;
	}
	return 1;
}
int main()
{
	int a;
	scanf("%d", &a);
	int ret = if_suhsu(a);
	if (ret == 1)
		printf("%d������\n",a);
	else
		printf("%d��������\n",a);
	system("pause");
	return 0;
}
#include<stdio.h>
#include<stdlib.h>
void init(int b[],int k)
{
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &b[i]);
	}
}
void empty(int b[])
{

}
void reverse(int b[],int tmp)
{
	for (int i = tmp; i >= 0; --i)
	{
		b[i]=
	}
}
int main()
{
	int a[10];
	int tmp = sizeof(a) / sizeof(a[0]);
	init(a,tmp);
	system("pause");
	return 0;
}