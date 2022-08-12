#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct QueueNode {
	DataType data;
	QueueNode* next;
} QueueNode ;

typedef struct {
	QueueNode* from;
	QueueNode* rear;
}LinkQueue;

void InitQueue(LinkQueue * q) {
	q->from = q->rear=NULL;

}
int EnQueue(LinkQueue *q,DataType x) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = x;
	node->next = NULL;
	if (q->rear == NULL&&q->rear == NULL) {
		q->rear = node;
		q->from = node;
	}
	else {
		q->rear->next = node;
		q->rear = q->rear->next;
	}
	return 1;
}
int DeleteQueue(LinkQueue* q) {
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	if (q->rear == NULL && q->rear == NULL) {
		return 0;
	}
	else {
		int val = q->from->data;
		q->from = q->from->next;
		return val;
	}
}
int main() {
	LinkQueue* q = (LinkQueue*)malloc(sizeof(LinkQueue));
	InitQueue(q);
	EnQueue(q,120);
	EnQueue(q,130);
	EnQueue(q,140);
	EnQueue(q,150);
	EnQueue(q,10);
	//printf("当前值为%d", DeleteQueue(q));
	//printf("当前值为%d", DeleteQueue(q));
	//printf("当前值为%d", DeleteQueue(q));
	//printf("当前值为%d", DeleteQueue(q));
	//printf("当前值为%d", DeleteQueue(q));
	return 0;
}
