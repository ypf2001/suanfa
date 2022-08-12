#include<stdio.h>
#include<stdlib.h>
typedef int Elem;
typedef struct Lnode {
	Elem data;
	struct Lnode* next;
}Lnode, * LinkList;

LinkList initList_L() {
	Lnode* L = (LinkList)malloc(sizeof(Lnode));
	L->next = NULL;
	L->data = 0;
	return L;
}
void tailList_L(LinkList L, Elem val) {
	while (L->next != NULL) {
		L = L->next;
	}
	L->next = (Lnode*)malloc(sizeof(Lnode));
	L->next->data = val;
	L->next->next = NULL;
}
LinkList headInsert(LinkList L, Elem elem) {
	Lnode* n_l = (LinkList)malloc(sizeof(Lnode));
	n_l->next = L;
	n_l->data = elem;
	L = n_l;
	return L;
}
void ListTraverse(LinkList L) {
	do {
		printf("数组当前值为：%d", L->data);
		L = L->next;
	} while ((L != NULL));
}
void ListHeadTraverse(LinkList L) {
	do {
		printf("数组当前值为：%d", L->data);
		L = L->next;
	} while ((L->next != NULL));
}
int destoryList(LinkList l) {
	Lnode* p;
	while (l) {
		p = l;
		l = l->next;
		delete p;
	}
	return 1;

}

int getLength(LinkList l) {
	LinkList p;
	p = l->next;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}

Lnode* getElem(LinkList l, int idx) {
	int i = 0;
	Lnode* node = l;
	while (l->data && idx >= 0 && i <= idx) {
		node = node->next;
		i++;
	}
	return node;
}
LinkList Connect(LinkList a,LinkList b ) {
	Lnode* p;
	p = a->next;
	a->next = b->next->next;
	delete b->next;
	b->next = a;
	return b;
}
int main() {
	LinkList list_p = initList_L();
	int i = 0;
	LinkList L;
	for (i = 0; i < 100; i++) {

		L = headInsert(list_p, i);
		list_p = L;
	}
	ListTraverse(L);
	return 0;
}