//����㷨ʵ��ɾ���������ж����ظ�Ԫ��
#include<stdio.h>
#include<stdlib.h>
typedef struct LinkList
{
	int val;
	struct LinkList* next;
}List;
void menu()
{
	printf("     *********************************\n");
	printf("                                      \n");
	printf("     *****��ӭʹ�õ�����ȥ�ز���******\n");
	printf("                                      \n");
	printf("     *********************************\n");
}
void print(List *head)
{
	List* cur = head;
	for (List *i =cur; i != NULL; i = i->next)
	{
		printf("%d->", i->val);
	}
	printf("\n");
}

List* InitList(int *a,List *head)
{
	head->val = a[0];
	List *l=head;
	int i = 1;
	while(a[i]!=888)
	{
		List *b= (List*)malloc(sizeof(List));
		b->val = a[i];
		l->next = b;
		l = b;
		i++;
	}
	l->next = NULL;
	return head;
}
List* CreateList(List * head)
{
	int t=0,a[100];
	printf("\n\n\n\n     ****����������Ҫȥ�ص�����ֵ****\n");
	printf("     *******��000�����������********\n");
	printf("������->");
	int i = 0;
	while (t!=888)
	{
		scanf("%d",&a[i]);
		t = a[i];
		i++;
	}
	InitList(a,head);
	printf("������ĵ�����Ϊ:  ");
	print(head);
	return head;
}
void DeteleTheSame(List *head)
{
	List* p, *q=NULL, *t=NULL, *s=NULL;
	p = head;
	p = p->next;
	while(p!=NULL)	
	{		
		t = p;  		
	    for(q = p->next;q != NULL;)		
	    {	s = q;			
	       if(p->val == q->val)			
	       {
			   t->next = q->next;			
	           q = q->next;          			
	           free(s);              			
	       }			
		   else                     			
	       {				
			   t = t->next;          				
	           q = q->next;          		
	       }		
	    }		
	    p = p->next;	
	}
}	
int main()
{
	menu();
	List *head = (List*)malloc(sizeof(List));
	CreateList(head);
	DeteleTheSame(head);
	print(head);
	system("pause");
	return 0;
}