#include<stdlib.h>
#include<stdio.h>
#define MVNum 5
#define maxInt 10000
typedef char VerTexType;
typedef int ArcType;
typedef struct {
	VerTexType vexs[MVNum];//顶点表
	ArcType arcs[MVNum][MVNum];//邻接矩阵
	int vexnum, arcnum;
}AMGraph;
void CreateUDN(AMGraph* g){

	g = (AMGraph*)malloc(sizeof(AMGraph));
	//printf("%d \n", sizeof(g->arcs));
	int i = 0;
	int j = 0;
	for (i = 0; i < sizeof(g->vexs)/sizeof(char); i++) {
		char val = NULL;
		printf("请输入结点:\n");
		scanf_s("%c",&val);
		getchar();
		printf("结点为:%c \n",val);
		g->vexs[i] = val;
	}
	for (i = 0; i < MVNum; i++) {
		for (j = 0; j <MVNum; j++) {
			g->arcs[i][j] = maxInt;
		}
	}//每一个空的邻居矩阵权值都为最大值
	bool flag = true;
	while (flag) {
		printf("依次输入要连接的结点权值：\n");
		int  i,j,val,goon;
		scanf_s("%d%d%d", &i, &j,&val);
		getchar();
		g->arcs[i][j] = val;
		printf("是否继续：\n");
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