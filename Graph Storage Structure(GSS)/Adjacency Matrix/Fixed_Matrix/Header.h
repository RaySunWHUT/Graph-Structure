#pragma once

#define GSIZE sizeof(struct GraphNode)
#define ESIZE sizeof(struct GraphEdge)

#define MAxVertexNum 100
#define INFINITY 65535

typedef int Vertex;    /* 顶点类型被定义为整型，意即用顶点的下标代表顶点，顶点 i 即指vi. */
typedef int WeightType;
typedef char DataType;
typedef int bool;
typedef int GraphType;	/* 0: 无向图; 1: 有向图 */

typedef struct GraphNode {   /* 图结点定义 */

	int Nv;   /* 顶点数: VertexNum */
    int Ne;   /* 边数：EdgeNum */
	WeightType G[MAxVertexNum][MAxVertexNum];    /* 邻接矩阵 */
 	DataType Data[MAxVertexNum];    /* 存储顶点的数据;  若无顶点数据, 此时Data[]可以不定义 */

} GNode,* Gpointer;


typedef struct GraphEdge {    /* 边定义 */
	 
	Vertex V1;     /* 有向边<V1, V2> */
	Vertex V2;
	WeightType Weight;

} GEdge, *Epointer;


Gpointer createGraph(int VertexNum);   /* 创建VertexNum个顶点的图 */

void insertEdge(Gpointer Graph, Epointer Edge, GraphType kind);   /* 插入边 */
void deleteEdge(Gpointer Graph, Epointer Edge, GraphType kind);   /* 删除边 */

Gpointer buildGraph();  /* 建立图 */

bool isEmpty(Gpointer Graph);    /* 判空 */

void output(Gpointer Graph);     /* 遍历输出 */
