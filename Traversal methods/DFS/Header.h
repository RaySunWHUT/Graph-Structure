#pragma once

#define MaxVertexNum 100

#define INFINITY 65535

#define GSIZE sizeof(struct GNode)
#define ASIZE sizeof(struct AdjVNode)
#define ESIZE sizeof(struct ENode)


typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef int GraphType;	// 建立图类型(0: 无向图; 1: 有向图)

typedef int Bool;


typedef enum {

	False = 0,
	True

} Status;


typedef struct ENode {   /* 边定义 */

	Vertex V1, V2;       /* 有向边 <V1, V2> */
	WeightType Weight;    /* 权重 */

} ENode, *Epointer;


typedef struct AdjVNode {    /* 邻接点定义 */

	Vertex AdjV;    /* 邻接点下标 */
	WeightType Weight;    /* 对于网图边表，增加边权重Weight */
	struct AdjVNode* Next;   /* 指向下一个邻接点的指针 */

} AdjVNode, *Apointer;


typedef struct Vnode {    /* 顶点表头结点 */

	DataType Data;      /* 顶点无数据，Data可以不出现 */
	Apointer FirstEdge;   /* 边表头指针 */

} AdjList[MaxVertexNum];


typedef struct GNode {   /* 图结点 */

	int Nv;    /* 顶点数 */
	int Ne;    /* 边数 */
	AdjList G;	// 邻接表

} GNode, *Gpointer;


Gpointer createGraph(int vertexNum);
Gpointer buildGraph();
void insertEdge(Gpointer graph, Epointer edge, GraphType kind);
void output(Gpointer graph);

void visit(Vertex v);
void DFS(Gpointer graph, Vertex randomVertex, void(*visit)(Vertex));