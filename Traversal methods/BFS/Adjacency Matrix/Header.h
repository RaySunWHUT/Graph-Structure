#pragma once

#define GSIZE sizeof(struct GraphNode)
#define ESIZE sizeof(struct GraphEdge)

#define MaxVertexNum 100
#define INFINITY 65535


#define NSIZE sizeof(struct Node)
#define QSIZE sizeof(struct Queue)


typedef int Vertex;    /* 顶点类型被定义为整型，意即用顶点的下标代表顶点，顶点 i 即指vi. */
typedef int WeightType;
typedef char DataType;
typedef int Bool;
typedef int GraphType;	/* 0: 无向图; 1: 有向图 */

typedef enum {

	False = 0,
	True

} Status;


typedef struct GraphNode {   /* 图结点定义 */

	int Nv;   /* 顶点数: VertexNum */
    int Ne;   /* 边数：EdgeNum */
	WeightType G[MaxVertexNum][MaxVertexNum];    /* 邻接矩阵 */
 	DataType Data[MaxVertexNum];    /* 存储顶点的数据;  若无顶点数据, 此时Data[]可以不定义 */

} GNode,* Gpointer;


typedef struct GraphEdge {    /* 边定义 */
	 
	Vertex V1;     /* 有向边<V1, V2> */
	Vertex V2;
	WeightType Weight;

} GEdge, *Epointer;


Gpointer createGraph(int vertexNum);   /* 创建VertexNum个顶点的图 */

void insertEdge(Gpointer graph, Epointer edge, GraphType kind);   /* 插入边 */
void deleteEdge(Gpointer graph, Epointer edge, GraphType kind);   /* 删除边 */

Gpointer buildGraph();  /* 建立图 */

Bool isGEmpty(Gpointer graph);    /* 判空 */

void outputG(Gpointer graph);     /* 遍历输出 */

// 访问
void visit(Vertex v);

void DFS(Gpointer graph, Vertex v, void (*visit)(Vertex));   /* 深度优先搜索 */
void BFS(Gpointer graph, Vertex v, void (*Visit)(Vertex));   /* 广度优先搜索 */

Bool isEdge(Gpointer graph, Vertex v1, Vertex v2);


typedef struct Node {         /* 队列中的结点 */

	Vertex v;	// 图结点
	struct Node* next;

} Node, * Npointer;


typedef struct Queue {

	Npointer front, rear;    /* 队头，队尾指针 */
	int maxSize;                   /* 队列最大容量 */

} Queue, * Qpointer;


Qpointer createQueue(int maxSize);
Bool isQEmpty(Qpointer headp);
Qpointer addQ(Qpointer headp, Vertex v);
Vertex deleteQ(Qpointer headp);