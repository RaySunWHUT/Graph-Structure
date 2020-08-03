#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

#pragma warning(disable:4996)


Gpointer createGraph(int VertexNum) {   /* 创建一个有VertexNum个顶点但没有边的无向图 */

	// x, y: 邻接矩阵的x, y轴
	Vertex x, y;
	Gpointer Graph = (Gpointer)malloc(GSIZE);

	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	
	for (x = 0; x < VertexNum; x++) {

		for (y = 0; y < VertexNum; y++) {

			Graph->G[x][y] = INFINITY;

		}

	}

	return Graph;

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


void deleteEdge(Gpointer Graph, Epointer Edge, GraphType kind) {    /* 删除边 */

	Vertex V1 = Edge->V1, V2 = Edge->V2;

	/* 无向图 */
	if (kind == 0) {

		Graph->G[V1][V2] = Graph->G[V2][V1] = INFINITY;
	
	}

	/* 有向图 */
	if (kind == 1) {

		Graph->G[V1][V2] = INFINITY;
	
	}

}


bool isEmpty(Gpointer Graph) {  /* 判空 */

	return (Graph->Nv == 0);

}


Gpointer buildGraph() {

	Gpointer Graph = NULL;
	
	// 顶点数
	Vertex vNodes;
	
	Epointer Edge;
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

	Graph = createGraph(Nv);

	printf("请输入边数：");
	scanf("%d", &Graph->Ne);   /* 读入边数 */

	if (Graph->Ne != 0) {    /* 存在边 */

		Edge = (Epointer)malloc(ESIZE);   /* 中间介质 */
		
		printf("请按格式 v1, v2, weight 输入图(Graph)的边信息:\n");
		for (int i = 0; i < Graph->Ne; i++) {

			printf("请输入第 %d 条边的信息:", i);

			scanf("%d%d%d", &(Edge->V1), &(Edge->V2), &(Edge->Weight));
			
			// 插入边
			insertEdge(Graph, Edge, kind);

		}

	}

	// 得到缓存中的\n，防止影响后续输入字符紊乱
	getchar();
	
	printf("请输入图的各顶点数据信息(共%d个顶点)：", Graph->Nv);
	
	/* 如果存在顶点数据 */
	for (vNodes = 0; vNodes < Graph->Nv; vNodes++) {

		scanf("%c", &(Graph->Data[vNodes]));

	}

	return Graph;

}


void output(Gpointer Graph) {    /* 遍历输出 */

	Vertex x, y;

	for (x = 0; x < Graph->Nv; x++) {

		for (y = 0; y < Graph->Nv; y++) {

			printf("%6d", Graph->G[x][y]);

		}

		printf("\n");

	}

	printf("各结点数据为：");
	for (x = 0; x < Graph->Nv; x++) {
     
		printf("%2c", Graph->Data[x]);

	}

}

