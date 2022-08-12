#include<stdio.h>
#include<stdlib.h>
typedef struct DoubleNode {
	int data;
	struct DoubleNode* prior, * next;

}DuLNode, * DulinkList;

DulinkList init_List () {
	DulinkList linklist = (DulinkList)malloc(sizeof(DoubleNode));
	linklist->next = NULL;
	linklist->prior = NULL;
	return linklist;
}
DulinkList insertNextList(DulinkList list,int data) {
	if (list->next==NULL) {
		DulinkList p = (DulinkList)malloc(sizeof(DoubleNode));
		p->data = data;
		p->next = NULL;
		p->prior = list;
		list->next = p;
		return  p;
	}
	else {
		DulinkList p = (DulinkList)malloc(sizeof(DoubleNode));
		p->data = data;
		//p->next = list->next;
		list->next->prior = p;
		list->next = p;
		p->prior = list;
		return  p;
	}


}
DulinkList insertPriorList(DulinkList list, int data) {

	if (list->prior == NULL) {
		DulinkList p = (DulinkList)malloc(sizeof(DoubleNode));
		p->data = data;
		p->prior = NULL;
		p->next = list;
		list->prior = p;
		return  p;
	}
	else {
		DulinkList p = (DulinkList)malloc(sizeof(DoubleNode));
		p->data = data;
		p->prior = list->prior;
		list->prior->next = p;
		list->prior = p;
		p->next = list;
		return  p;
	}
}
int deleteList(DulinkList list) {
	if (list->next == NULL) {
		list->prior->next = NULL;
		free(list);
	}
	else if (list->prior == NULL) {
		list->next->prior = NULL;
		free(list);
	}
	else {
		list->prior->next = list->next;
		list->next->prior = list->prior;
		free(list);

	};
	return  0;

}
void TraverseLeft(DulinkList l) {
	while (l->next) {
		printf("双向数组该项值为:%d" , l->data);
		l = l->next;
	}
}
int main() {
	DulinkList list = init_List();
	int i = 0;
	DulinkList n = list ,p = list;
	for (i = 0; i < 100;i++) {
		n =  insertNextList(n, i);
	}
	for (i = 0; i < 100; i++) {
		p = insertPriorList(p, i);
	}
	TraverseLeft(p);
	return 0;
}