#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 100
bool flag= true;
int deepsize = 0;
typedef char TElemType;
typedef TElemType SqBiTree[MAXSIZE];
SqBiTree bt;
typedef struct BiNode{
TElemType  data;
struct BiNode* lchild,* rchild;
}BiNode, * BiTree;

//nΪ�������ڵ���
void  InitBiTree(BiTree T,int d) {
	if (d==0) {
	}
	else {
		char ch = NULL;
		scanf_s("%c/n", &ch);
		int temp = getchar();
		T = (BiTree)malloc(sizeof(BiNode));
		--d;
		T->data = ch;
		printf("��������ڵ��֧:");
		InitBiTree(T->lchild, d);
		printf("�������ҽڵ��֧:");
		InitBiTree(T->rchild, d);
	}
}

//���򴴽�������
//int CreateBiTree(BiTree T)
//{
//	TElemType ch;
//	TElemType temp;
//	scanf_s("%d", &ch);
//	temp = getchar();
//	if (ch == -1)
//	{
//		T = NULL;
//	}
//	else
//	{
//		T = (BiTree)malloc(sizeof(BiNode));
//		if (!(T))
//		{
//			exit(-1);
//		}
//		(T)->data = &ch;
//		printf("����%d�����ӽ�㣺", ch);
//		CreateBiTree((T)->lchild);
//		printf("����%d�����ӽ�㣺", ch);
//		CreateBiTree((T)->rchild);
//	}
//	return 1;
//}


int main() {
	BiTree T = NULL;
	
	InitBiTree(T,3);
	return 0;
}