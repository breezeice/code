#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
typedef struct Heap
{
	int* _array;
	int _capacity;
	int _size;
}Heap;
void print(Heap *hp)
{
	for (int i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
//���ϵ���
void AdjustUp(int *a, int place)
{
	int parent = (place - 1) / 2;
	if (place == 0) return;
	if (a[parent] < a[place]) return;
	swap(&a[parent], &a[place]);
	AdjustUp(a, parent);
}
//���µ���
void heapify(int* a, int size, int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int min = left;
	if (right < size&&a[right] < a[left])
		min = right;
	if (a[index] <= a[min]) return;
	swap(&a[index], &a[min]);
	if (index >= size) return;
	heapify(a, size, min);
}

// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp)
{
	hp->_array[0] = hp->_array[hp->_size - 1];
	heapify(hp->_array, --hp->_size - 1, 0);
}

// ����в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, int data)
{
	hp->_array[hp->_size++] = data;
	AdjustUp(hp->_array,hp->_size-1);
}

// ������ 
void CreatHeap(Heap* hp, int* array, int size)
{
	hp->_array = (int*)malloc(sizeof(int)*size);

	for (int i = 0; i < size; i++)
	{
		hp->_array[i] = array[i];
	}
	hp->_size = size;
	hp->_capacity = size;
	for (int j=(size - 2) / 2; j >= 0; j--)
	{
		heapify(hp->_array, hp->_size, j);
	}
}

// ��ȡ������ЧԪ�ظ��� 
int SizeHeap(Heap* hp)
{
	return hp->_size;
}

// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp)
{
	return hp->_array > 0 ? 1 : 0;
}

// ��ȡ�Ѷ�Ԫ�� 
int TopHeap(Heap* hp)
{
	return hp->_array[0];
}

// ���ٶ� 
void DestroyHeap(Heap* hp)
{
	free(hp->_array);
	hp->_array = NULL;
	hp->_array = 0;
	hp->_size = 0;
}
//topk���� �ں����������ҵ�����top����
void topk(int* a, int size, int top)
{
	for (int i = 0; i < top; i++)
	{
		int top[i] = a[i];
	}
	Heap hp;
	CreatHeap(hp, top, top);
	while (int i = top; i < size; i++)
	{
		if (a[i] > top[0])
		{
			top[0] = a[i];
				heapify()
		}
	}
}
void test()
{
	int a[] = { 5,9,7,12,45,32,21,8,9,10 };
	int size = sizeof(a) / sizeof(a[0]);
	Heap hp;
	CreatHeap(&hp, a, size);
	print(&hp);
	EraseHeap(&hp);
	print(&hp);
	InsertHeap(&hp, 1);
	print(&hp);
}
int main()
{
	test();
	system("pause");
}