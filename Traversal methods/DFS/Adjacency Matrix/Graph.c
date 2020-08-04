#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

#pragma warning(disable:4996)


/* 创建一个有VertexNum个顶点但没有边的无向图 */
Gpointer createGraph(int vertexNum) {

	// x, y: 邻接矩阵的x, y轴
	Vertex x, y;
	Gpointer graph = (Gpointer)malloc(GSIZE);

	graph->Nv = vertexNum;
	graph->Ne = 0;
	
	for (x = 0; x < vertexNum; x++) {

		for (y = 0; y < vertexNum; y++) {

			graph->G[x][y] = INFINITY;

		}

	}

	return graph;

}


void insertEdge(Gpointer Graph, Epointer Edge, GraphType kind) {    /* 插入边 */

	Vertex v1 = Edge->V1, v2 = Edge->V2;
	int weight = Edge->Weight;

	// 插入边Edge: <V1, V2>
	Graph->G[v1][v2] = weight;

	if (kind == 0) { // 无向图
		
		// 插入边Edge: <V2, V1>
		Graph->G[v2][v1] = weight;

	}

}


void deleteEdge(Gpointer graph, Epointer edge, GraphType kind) {    /* 删除边 */

	Vertex v1 = edge->V1, v2 = edge->V2;

	/* 无向图 */
	if (kind == 0) {

		graph->G[v1][v2] = graph->G[v2][v1] = INFINITY;
	
	}

	/* 有向图 */
	if (kind == 1) {

		graph->G[v1][v2] = INFINITY;
	
	}

}


Bool isGEmpty(Gpointer graph) {  /* 判空 */

	return (graph->Nv == 0);

}


Gpointer buildGraph() {

	Gpointer graph = NULL;
	
	// 顶点数
	Vertex vNodes;
	
	Epointer edge;
	int Nv;

	GraphType kind;
	printf("请输入创建图种类(0: 无向图; 1: 有向图):");
	scanf("%d", &kind);

	if (kind != 0 && kind != 1) {

		printf("输入错误!");

		return;

	}


	printf("请输入顶点数：");
	scanf("%d", &Nv);   /* 读入顶点数 */

	graph = createGraph(Nv);

	printf("请输入边数：");
	scanf("%d", &graph->Ne);   /* 读入边数 */

	if (graph->Ne != 0) {    /* 存在边 */

		edge = (Epointer)malloc(ESIZE);   /* 中间介质 */
		
		printf("请按格式 v1, v2, weight 输入图(Graph)的边信息:\n");
		for (int i = 0; i < graph->Ne; i++) {

			printf("请输入第 %d 条边的信息:", i + 1);

			scanf("%d%d%d", &(edge->V1), &(edge->V2), &(edge->Weight));
			
			// 插入边
			insertEdge(graph, edge, kind);

		}

	}

	// 得到缓存中的\n，防止影响后续输入字符紊乱
	getchar();
	
	printf("请输入图的各顶点数据信息(共%d个顶点)：", graph->Nv);
	
	/* 如果存在顶点数据 */
	for (vNodes = 0; vNodes < graph->Nv; vNodes++) {

		scanf("%c", &(graph->Data[vNodes]));

	}

	return graph;

}


void outputG(Gpointer graph) {    /* 遍历输出 */

	Vertex x, y;

	for (x = 0; x < graph->Nv; x++) {

		for (y = 0; y < graph->Nv; y++) {

			printf("%6d", graph->G[x][y]);

		}

		printf("\n");

	}

	printf("各结点数据为：");
	for (x = 0; x < graph->Nv; x++) {
     
		printf("%2c", graph->Data[x]);

	}

}


void visit(Vertex v) {

	printf("正在访问结点%d\n", v);

}


Bool isEdge(Gpointer graph, Vertex v1, Vertex v2) {

	return graph->G[v1][v2] < INFINITY ? True : False;

}
