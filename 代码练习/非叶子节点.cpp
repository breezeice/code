#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
	int data;
	struct Node* lchild;
	struct Node* rchild;
}Node;
//顺序计算二叉树非叶子节点个数
int notleaf1(char *tree,int len)
{
	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (2 * i > len || tree[i * 2] == ' ' && tree[i * 2 + 1] == ' '||tree[i]==' ');
		else count++;
	}
	return count;
}
//链式存储计算二叉树非叶子节点个数
int count = 0;
void notleaf(Node* root)
{
	if (root != NULL)
	{
		if (root->lchild == NULL && root->rchild);
		else count++;
		notleaf(root->lchild);
		notleaf(root->rchild);
	}
}

void test1()
{
	char tree[20] = { 0 };
	gets_s(tree);
	int len = strlen(tree);
	printf("%d", notleaf1(tree, len));
}

Node* createnode(char ch)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = ch;
	node->lchild = node->rchild = NULL;
	return node;
}
void test2()
{
	Node *a = createnode('a'); Node *b= createnode('b');
	Node *c = createnode('c'); Node *d = createnode('d');
	Node *e = createnode('e'); Node *f = createnode('f');
	Node *g = createnode('g'); Node *h = createnode('h');
	a->lchild = b; a->rchild= c;
	b->lchild = d; b->rchild =e;
	c->lchild = f; c->rchild =g;
	d->lchild = NULL; d->rchild = NULL;
	e->lchild = NULL; e->rchild = h;
	f->lchild = NULL; f->rchild = NULL;
	notleaf(a);
	printf("%d",count );
}
int main()
{
	//test1();
	test2();
	system("pause");
	return 0;
}
