#include<stdlib.h>
#include<stdio.h>

#define MVNNum 10
typedef int VerTexType;

typedef struct ArcNode {
	int adjvex;//权
	struct ArcNode* nextarc;
	int info;
}ArcNode ;
typedef struct VNode {
	VerTexType data;
	ArcNode* firstarc;
}VNode, AdjList[MVNNum];

typedef struct {
	AdjList vertices;
	int vexnum, arcnum;//点数 和边数
}ALGraph;

int countRelate(ArcNode* arc) {
	int i = 0;

	while (arc[i].adjvex>0) {
		i++;
	}
	return i;

}
ALGraph* InitGraph(ALGraph * G) {
	G = (ALGraph*)malloc(sizeof(ALGraph));
	int vexnum, arcnum;
	scanf_s("%d",&vexnum);
	getchar();
	scanf_s("%d",&arcnum);
	getchar();
	G->arcnum = arcnum;
	G->vexnum = vexnum;
	int i = 0;
	for (i = 0; i < vexnum;i++) {
		G->vertices[i].firstarc =(ArcNode*) malloc(sizeof(ArcNode));
		G->vertices[i].firstarc->adjvex = i;
	}

	for (i = 0; i < arcnum;i++) {
		printf("请输入权：");
		int temp = 0;
		scanf_s("%d", &temp);
		printf("请输入出发点：");
		int j = 0;
		scanf_s("%d", &j);
		printf("请输入结束点：");
		int t = 0;
		scanf_s("%d", &t);
		int sub   = getchar();
		G->vertices[j].firstarc->nextarc = (ArcNode*)malloc(sizeof(ArcNode) * MVNNum);
		int now =  countRelate(G->vertices[j].firstarc->nextarc);
		G->vertices[j].firstarc->nextarc[now].info = temp;
		G->vertices[j].firstarc->nextarc[now].adjvex = t;
	}
	return G;
}

int main() {
	ALGraph* G  = NULL;
	InitGraph(G);

	return 0;
}