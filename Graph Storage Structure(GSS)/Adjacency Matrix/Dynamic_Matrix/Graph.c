#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

#pragma warning(disable:4996)

Gpointer createGraph(int VertexNum) {

	Vertex x, y;
	Gpointer Graph = (Gpointer)malloc(GSIZE);

	Graph->Nv = VertexNum;
	Graph->Ne = 0;

	Graph->G = (WeightType**)malloc(WPSIZE * VertexNum);   /* 动态申请二维数组 */

	for (int i = 0; i < VertexNum; i++) {

		Graph->G[i] = (WeightType*)malloc(WSIZE * VertexNum);

	}

	for (x = 0; x < VertexNum; x++) {

		for (y = 0; y < VertexNum; y++) {

			Graph->G[x][y] = INFINITY;

		}

	}


	Graph->Data = (DataType*)malloc(CSIZE * VertexNum);   /* 动态申请顶点数据空间 */


	return Graph;

}


void insertEdge(Gpointer Graph, Epointer Edge, GraphType kind) {    /* 插入边 */

	Vertex v1 = Edge->V1, v2 = Edge->V2;
	int weight = Edge->Weight;

	Graph->G[v1][v2] = weight;
	
	if (kind == 0) {	// 无向图, 邻接矩阵需为对称矩阵

		Graph->G[v2][v1] = weight;
	
	}

}


void deleteEdge(Gpointer Graph, Epointer Edge, GraphType kind) {    /* 删除边 */

	Vertex v1 = Edge->V1, v2 = Edge->V2;

	/* 无向图 */
	if (kind == 0) {
		Graph->G[v1][v2] = Graph->G[v2][v1] = INFINITY;
	}
	
	/* 有向图 */
	if (kind == 1) {
		 Graph->G[v1][v2] = INFINITY;
	}

}


Bool isEmpty(Gpointer Graph) {  /* 判空 */

	return (Graph->Nv == 0);

}


Gpointer buildGraph() {

	Gpointer Graph = NULL;
	Epointer Edge;
	int Nv;

	GraphType kind;
	
	printf("请输入创建图种类(0: 无向图; 1: 有向图):");
	scanf("%d", &kind);

	printf("请输入顶点数：");
	scanf("%d", &Nv);   /* 读入顶点数 */

	Graph = createGraph(Nv);

	printf("请输入边数：");
	scanf("%d", &Graph->Ne);   /* 读入边数 */

	if (Graph->Ne != 0) {    /* 存在边 */

		Edge = (Epointer)malloc(ESIZE);

		printf("请按格式 v1, v2, weight 输入图(Graph)的边信息:\n");
		for (int i = 0; i < Graph->Ne; i++) {
			
			printf("请输入第 %d 条边的信息:", i);
			
			scanf("%d%d%d", &(Edge->V1), &(Edge->V2), &(Edge->Weight));

			if (Edge->V1 >= Nv || Edge->V2 >= Nv || Edge->V1 < 0 || Edge->V2 < 0) {

				printf("您输入的数据有误! 请重新输入!\n");

			} else {   /* 0 <= V1, V2 < Nv  */

				insertEdge(Graph, Edge, kind);

			}

		}

	}

	getchar();   // 获取缓存中的空格

	Vertex vNodes;

	printf("请输入各顶点数据(共%d项)：", Graph->Nv);
	for (vNodes = 0; vNodes < Graph->Nv; vNodes++) {   /* 如果存在顶点数据 */

		scanf("%c", &(Graph->Data[vNodes]));

	}

	return Graph;

}


void output(Gpointer Graph) {    /* 遍历输出 */

	Vertex x, y;

	printf("\n邻接矩阵：\n");
	for (x = 0; x < Graph->Nv; x++) {

		for (y = 0; y < Graph->Nv; y++) {

			printf("%8d", Graph->G[x][y]);

		}

		printf("\n");

	}

	printf("各顶点数据为：");

	for (x = 0; x < Graph->Nv; x++) {

		printf("%2c", Graph->Data[x]);

	}

}

