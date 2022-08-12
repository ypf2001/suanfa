#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int* a;
	int front;
	int rear;
	int k;
} MyCircularQueue;
bool MyCircularQueueIsEmpty(MyCircularQueue*obj);
bool MyCircularQueueIsFull(MyCircularQueue* obj);
MyCircularQueue* init_queue(int k) {
	MyCircularQueue* p = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	p->a = (int*)malloc(sizeof(int) * (k + 1));
	p->front = 0;
	p->rear = 0;
	p->k = k;
	return p;

}
bool MyCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->front == obj->rear)
		return true;
	else
		return false;

}
bool MyCircularQueueIsFull(MyCircularQueue* obj) {
	if (obj->front == (obj->rear + 1) % (obj->k + 1))
		return true;
	else
		return false;

}
bool insert(MyCircularQueue*obj ,int value) {
	if (MyCircularQueueIsEmpty) {
		return false;
	}
	obj->a[obj->rear++] = value;
	obj->rear = (obj->rear) % (obj->k + 1);
	return true;
}

bool deleteQueue(MyCircularQueue*obj ) {
	if (MyCircularQueueIsEmpty(obj))
		return false;
	else
	{
		obj->front++;
		obj->front %= (obj->k + 1);
		return true;
	}

}

int QueueFront(MyCircularQueue*obj) {
	if (MyCircularQueueIsEmpty(obj))
		return -1;
	return obj->a[obj->front];
}
int QueueRear(MyCircularQueue* obj) {
	if (MyCircularQueueIsEmpty(obj))
		return -1;
	else
	{
		int tail = obj->rear - 1;
		if (tail == -1)
			tail = obj->k;
		return obj->a[tail];
	}
}
void QueueFree(MyCircularQueue*obj) {
	free(obj);
	free(obj->a);
}
int main() {
	return
		0;
}