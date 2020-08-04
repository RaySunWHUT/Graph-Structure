#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

#pragma warning(disable:4996)


Gpointer createGraph(int vertexNum) {   /* 初始化一个有VertexNum个顶点但无边的图 */

	Vertex v;
	Gpointer graph;

	graph = (Gpointer) malloc(GSIZE);
	graph->Nv = vertexNum;
	graph->Ne = 0;

	for (v = 0; v < vertexNum; v++) {

		graph->G[v].FirstEdge = NULL;

	}

	return graph;

}


Gpointer buildGraph() {

	Gpointer graph;
	Epointer edge;
	int Nv;

	GraphType kind;

	printf("请输入创建图种类(0: 无向图; 1: 有向图):");
	scanf("%d", &kind);

	printf("请输入顶点数：");
	scanf("%d", &Nv);

	graph = createGraph(Nv);

	printf("请输入边数：");
	scanf("%d", &(graph->Ne));

	if ((graph->Ne) != 0) {

		edge = (Epointer) malloc(ESIZE);

		printf("请按格式 v1, v2, weight 输入图(Graph)的边信息:\n");
		for (int i = 0; i < graph->Ne; i++) {

			printf("请输入第 %d 条边的信息:", i + 1);
			scanf("%d%d%d", &(edge->V1), &(edge->V2), &(edge->Weight));

			insertEdge(graph, edge, kind);

		}

	}

	// 冲掉缓冲流
	getchar();

	/* 如果顶点存在数据，读入数据 */
	printf("请输入各顶点数据(共%d项)：", graph->Nv);
	for (Vertex v = 0; v < graph->Nv; v++) {

		scanf("%c", &(graph->G[v].Data));

	}

}


void insertEdge(Gpointer graph, Epointer edge, GraphType kind) {

	Apointer newNode;

	 /* 插入边<V1, V2> */
	 /* 为V2建立新的邻接点 */
	newNode = (Apointer)malloc(ASIZE);
	newNode->AdjV = edge->V2;
	newNode->Weight = edge->Weight;

	 /* 将V2插入V1的表头 */
	// 利用邻接表下标序号表示顶点	
	newNode->Next = graph->G[edge->V1].FirstEdge;     /* 妙哉！妙哉！插入操作, 新结点要插入到最前面 */
	graph->G[edge->V1].FirstEdge = newNode;
	
	if (kind == 0) {	// 若是无向图

		/* 插入边<V2, V1> */
		newNode = (Apointer)malloc(ASIZE);
		newNode->AdjV = edge->V1;
		newNode->Weight = edge->Weight;

		/* 将V1插入V2的表头 */
		newNode->Next = graph->G[edge->V2].FirstEdge;
		graph->G[edge->V2].FirstEdge = newNode;

	}

}


void output(Gpointer graph) {
	
	Apointer adjVNode = NULL;

	printf("序号 Data ---> 邻接点/权重\n");

	for (Vertex v = 0; v < graph->Nv; v++) {

		printf("%d %c", v, graph->G[v].Data);

		adjVNode = graph->G[v].FirstEdge;

		while (adjVNode != NULL) {

			printf("---> %d/%d", adjVNode->AdjV, adjVNode->Weight);
			adjVNode = adjVNode->Next;
		
		}

		printf("\n");
	
	}

}


void visit(Vertex v) {

	printf("正在访问顶点%d\n", v);

}


