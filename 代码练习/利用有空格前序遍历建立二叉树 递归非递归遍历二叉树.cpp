#include<stdio.h>
#include<stdlib.h>
#include<stack> 
typedef struct Node
{
	char data;
	struct Node* lchild;
	struct Node* rchild;
}Node;

void huanyuan(Node *  &a)
{
	
	int i = 1;
	char ch;
	if((ch = getchar()) == ' ')
	{
	     a = (Node*)malloc(sizeof(Node));
	     a = NULL;
	}
	else
	{
		a = (Node*)malloc(sizeof(Node));
		a->data = ch;
		huanyuan(a->lchild);
		huanyuan(a->rchild);
	}
}
//�ݹ�ʵ�� 
void qianxu(Node *root)
{
	if (root == NULL) return;
	printf("%c", root->data);
	qianxu(root->lchild);
	qianxu(root->rchild);
}
void zhongxu(Node *root)
{
	if (root == NULL) return;
	zhongxu(root->lchild);
	printf("%c", root->data);
	zhongxu(root->rchild);
}
void houxu(Node *root)
{
	if (root == NULL) return;
	houxu(root->lchild);
	houxu(root->rchild);
	printf("%c", root->data);
}
//�ǵݹ�ʵ��
void preorder(Node* root)
{
	Node* cur=root;
	std::stack<Node *>st;
	while(cur!=NULL||!st.empty())
	{
		while(cur!=NULL)
		{
			printf("%c",cur->data);
			st.push(cur);
			cur=cur->lchild;
		}
		Node *top=st.top();
		st.pop();
		cur=top->rchild;
	}
 }
 void inorder(Node* root)
{
	Node* cur=root;
	std::stack<Node*>st;
	while(cur!=NULL||!st.empty())
	{
		while(cur!=NULL)
		{
			st.push(cur);
			cur=cur->lchild;
		}
		Node *top=st.top();
		printf("%c",top->data);
		st.pop();
		cur=top->rchild;
	}
 }
 void postorder(Node* root)
 {
 	Node *cur=root;
 	Node *last=NULL;
 	std::stack<Node*>st;
 	while(cur!=NULL||!st.empty())
	{
		while(cur!=NULL)
		{
			st.push(cur);
			cur=cur->lchild;
		}
		Node *top=st.top();
		if(top->rchild==NULL||top->rchild==last)
		{
			st.pop();
			printf("%c",top->data);
			last=top;
		}
		else cur=top->rchild;
	}
  } 
int main()
{
	Node *a;
	huanyuan(a);
	printf("ǰ�����Ϊ��");
	qianxu(a);
	printf("\n");
	printf("�������Ϊ��");
	zhongxu(a);
	printf("\n");
	printf("�������Ϊ��");
	houxu(a);
	printf("\n");
	preorder(a);
	printf("\n");
	inorder(a);
	printf("\n");
	postorder(a);
	printf("\n");
	system("pause");
	return 0;
}
