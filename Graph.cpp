#include<stdlib.h>
#include<stdio.h>
#define MVNum 5
#define maxInt 10000
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];//�����
	ArcType arcs[MVNum][MVNum];//�ڽӾ���
	int vexnum, arcnum;
}AMGraph;
void CreateUDN(AMGraph* g){

	g = (AMGraph*)malloc(sizeof(AMGraph));
	//printf("%d \n", sizeof(g->arcs));
	int i = 0;
	int j = 0;
	for (i = 0; i < sizeof(g->vexs)/sizeof(char); i++) {
		char val = NULL;
		printf("��������:\n");
		scanf_s("%c",&val);
		getchar();
		printf("���Ϊ:%c \n",val);
		g->vexs[i] = val;
	}
	for (i = 0; i < MVNum; i++) {
		for (j = 0; j <MVNum; j++) {
			g->arcs[i][j] = maxInt;
		}
	}//ÿһ���յ��ھӾ���Ȩֵ��Ϊ���ֵ
	bool flag = true;
	while (flag) {
		printf("��������Ҫ���ӵĽ��Ȩֵ��\n");
		int  i,j,val,goon;
		scanf_s("%d%d%d", &i, &j,&val);
		getchar();
		g->arcs[i][j] = val;
		printf("�Ƿ������\n");
		scanf_s("%d", &goon);
		getchar();
		if (!goon) {
			flag = false;
		}

	}
}


int main() {
	AMGraph* g = NULL;
	CreateUDN(g);
	return 0;
}