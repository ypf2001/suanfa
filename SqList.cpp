#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define LIST_INIT_SIZE 100;
typedef int status;
typedef int Elem;
typedef struct {
	Elem* elem;
	int size, length;
}SqList;


SqList* InitList(int n) {
	SqList* sq = (SqList*)malloc(sizeof(SqList));
	sq->elem =(Elem*)malloc(sizeof(Elem) * n);
	//if (!sq->elem)
	//	exit(OVERFLOW);
	sq->size = n;
	sq->length = 0;//空表长度为0
	return sq;
}
 void DestoryList(SqList* list) {
	 free(list->elem);
	 free(list);

}
void ClearList(SqList* list) {
	list->length = 0;
}

int GetLength(SqList* list) {
	return list->length;
}
int GetElem(SqList* list,int i) {
	return list->elem[i];
}

int LocateElem(SqList* list ,Elem* elem) {
	int i = 0;
	for (i = 0; i < list->length;i++) {
		if (list->elem[i]==*elem) {
			return i;
		}
		else
		{
			return -1;	
		}
	}
}
//获取前驱
//int PriorElem() {
//}

int ListInsert(SqList* list , int idx , Elem val) {
	if (list == NULL) 
		return -1;
	if (idx > list->length)
		return -1;
	int i = 0;
	int temp = 0;
	int next = 0;
		temp = list->elem[idx];
		list->elem[idx] = val;
		list->length++;
		for (i = idx+1; i < list->length;i++) {
			if (i + 1 < list->length) {
				next = list->elem[i + 1];
			}			
			list->elem[i] = temp;
			temp = next;
		}
		return 1;
}
int ListDelete(SqList* list, int idx){
	if (list == NULL)
		return -1;
	if (idx > list->length)
		return -1;
	int temp = 0;
	int i = 0;
	for (i = idx; i < list->length; i++) {
		if (i + 1 == list->length) {
			list->length--;
			return 1; 
		}
			
		temp = list->elem[i+1];
		list->elem[i] = temp;
	}
}
// 遍历
void ListTraverse(SqList* list) {
	int i = 0;
	for (i = 0; i < list->length;i++) {
		printf("数组的值为%d", list->elem[i]);
	}

}

int main() {
	SqList* list = InitList(100);
	int i = 0;
	for (i = 0; i < 100;i++) {
		ListInsert(list, i, rand());
	}
	ListDelete(list, 2);

	ListTraverse(list);
	printf("数组的长度为%d", list->length);
	return 0;
}
