#include <stdio.h>
#include<stdlib.h>

typedef struct stack{
	int size;
	 int* top,* base;
}stack, * stackElem;

stackElem InitStack(int n) {

	stackElem elem= (stackElem)malloc(sizeof(stack));
	elem->base =(int*) malloc(sizeof(int));
	elem->top = elem->base;
	elem->size = n;
	return elem;
}
//
//stackElem InitElem(int val) {
//
//}
//入栈
int push(stackElem e,int val) {
	if((e->top -e->base)/(sizeof(int)) == e->size) {
		return 0;
	}
	e->top++;
	*e->top = val;
	

	return 1;
}
//出栈
int pop(stackElem e) {
	if (e->top == e->base) {
		return 0;
	}
	int val = *e->top;
	e->top--;
	return val;
}
int main() {
	stackElem e =InitStack(100);

	push(e, 10);
	push(e, 10);
	push(e, 10);
	push(e, 30);
	printf( "出栈值为%d", pop(e));
	printf("出栈值为%d", pop(e));
	printf("出栈值为%d", pop(e));
	printf("出栈值为%d", pop(e));
}