#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void print(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//插入排序
void insertsort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (a[j] > a[i]) swap(&a[j], &a[i]);
			if (a[j - 1] > a[j]) swap(&a[j - 1], &a[j]);
		}
	}
}
void insertsort1(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = a[i];
		int j;
		for (j = i - 1; j >= 0 && a[j] > k; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = k;
	}
}
//希尔排序
void shellsort(int a[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size; i++)
		{
			int k = a[i];
			int j;
			for (j = i - gap; j >= 0 && a[j] > k; j -= gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = k;
		}
		if (gap <= 1) break;
	}
}
//选择排序
void selectsort(int a[], int size)
{
	int min = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (a[j] < a[min]) min = j;
		}
		swap(&a[min], &a[i]);
	}
}
void selectsort1(int a[], int size)
{
	int left = 0;
	int right = size - 1;
	while (left <= right)
	{
		int min = left;
		int max = right;
		for (int i = left; i <= right; i++)
		{
			if (a[i] <= a[min]) min = i;
			if (a[i] >= a[max]) max = i;
		}
		swap(&a[left], &a[min]);
		swap(&a[right], &a[max]);
		left++;
		right--;
	}
}
//堆排序
void heapify(int a[], int size, int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left >= size)
		return;
	int max = left;
	if (max < size&&a[max] < a[right])
		max = right;
	if (index >= max) return;
	swap(&a[index], &a[max]);
	heapify(a, size, max);
}
void creatheap(int a[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		heapify(a, size, i);
	}
}
void heapsort(int a[], int size)
{
	creatheap(a, size);
	for (int i = 0; i < size; i++)
	{
		swap(a, a + size - i - 1);
		heapify(a, size - i - 1, 0);
	}
}
//快速排序
int partition(int a[], int left, int right)
{
	int mid = right;
	int k = a[right];
	for (int i = right - 1; i >= left ; i--)
	{
		if (a[i] > k)
		{
			int t = a[i];
			for (int j = i; j < right; j++)
			{
				a[j] = a[j + 1];
			}
			a[right] = t;
			mid--;
		}
	}
	return mid;
}
void quicksort(int a[], int left, int right)
{
	if (left >= right) return;
	int pivotIndex = partition(a, left, right);
	quicksort(a, left, pivotIndex - 1);
	quicksort(a, pivotIndex +1, right);
}
//归并排序
void Merge(int a[], int left, int mid, int right)
{
	int len = right - left + 1;        //    数组的长度
	int *temp = (int*)malloc(sizeof(int) * 11);  // 分配个临时数组
	int k = 0;
	int i = left;                   // 前一数组的起始元素
	int j = mid + 1;                // 后一数组的起始元素
	while (i <= mid && j <= right)
	{
		//    选择较小的存入临时数组
		temp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= right)
	{
		temp[k++] = a[j++];
	}
	for (int k = 0; k < len; k++)
	{
		a[left++] = temp[k];
	}
}

// 递归实现的归并排序
void MergeSort(int a[], int left, int right)
{
	if (left == right)
		return;
	int mid = (left + right) / 2;
	MergeSort(a, left, mid);
	MergeSort(a, mid + 1, right);
	Merge(a, left, mid, right);
}

//void merge(int a[], int left, int mid,int  right,int tmp[])
//{
//	int index = 0;
//	int i = left, j = mid + 1;
//	while (i <= mid&&j <= right)
//	{
//		if (a[i] <= a[j])
//		{
//			tmp[index++] = a[i];
//			i++;
//		}
//		if (a[j] <= a[i])
//		{
//			tmp[index++] = a[j];
//			j++;
//		}
//	}
//	for (int k = 0; k < right; k++)
//	{
//		a[k] = tmp[k];
//	}
//}
//void mergeSort(int a[], int left, int right,int* tmp)
//{
//	if (left >= right - 1) return;
//	int mid = (right + left) / 2;
//	mergeSort(a, left, mid,tmp);
//	mergeSort(a, mid, right,tmp);
//	merge(a, left, mid, right,tmp);
//}
int main()
{
	int a[] = { 9,6,5,8,20,9,4,3,10,4,7 };
	int size = sizeof(a) / sizeof(a[0]);
	int *tmp = (int*)malloc(sizeof(int) * size);
	print(a, size);
    MergeSort(a, 0, size - 1);
	print(a, size);
	system("pause");
	return 0;
}