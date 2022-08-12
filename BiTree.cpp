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

//n为二叉树节点数
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
		printf("请输入左节点分支:");
		InitBiTree(T->lchild, d);
		printf("请输入右节点分支:");
		InitBiTree(T->rchild, d);
	}
}

//先序创建二叉树
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
//		printf("输入%d的左子结点：", ch);
//		CreateBiTree((T)->lchild);
//		printf("输入%d的右子结点：", ch);
//		CreateBiTree((T)->rchild);
//	}
//	return 1;
//}


int main() {
	BiTree T = NULL;
	
	InitBiTree(T,3);
	return 0;
}