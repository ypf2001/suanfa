#include<stdio.h>
#include<stdlib.h>
const int MAXSIZE =5;
typedef struct {
	int *data;
	int rear, front;
}SQueue, *queue;

SQueue initQueue( ) {
	SQueue *queue=(SQueue*)malloc(sizeof(SQueue));
	queue->data = (int*)malloc(sizeof(int) * MAXSIZE);
	queue->rear = queue->front = 0;
	return *queue;
}
//省略队列满值的判断
int EnQueue(queue q, int val) {
	if ((q->rear-q->front)%MAXSIZE == MAXSIZE-1||q->rear+1==MAXSIZE) {
		return 0;
	}
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % MAXSIZE;
	return 1;
}
int DeleteQueue(queue q) {
	int val = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return val;
}

//牺牲了一个队列元素
int main() {
	SQueue q =initQueue();
	EnQueue(&q, 10);
	EnQueue(&q, 10);
	EnQueue(&q, 10);
	EnQueue(&q, 10);
	EnQueue(&q, 10);
	EnQueue(&q, 10);
	EnQueue(&q, 230);
	printf("当前值为:%d", DeleteQueue(&q));
	printf("当前值为:%d", DeleteQueue(&q));
	printf("当前值为:%d", DeleteQueue(&q));
	printf("当前值为:%d", DeleteQueue(&q));
	printf("当前值为:%d", DeleteQueue(&q));
	printf("当前值为:%d", DeleteQueue(&q));
	return 0;
}
