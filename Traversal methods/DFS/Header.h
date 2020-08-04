#pragma once

#define MaxVertexNum 100

#define INFINITY 65535

#define GSIZE sizeof(struct GNode)
#define ASIZE sizeof(struct AdjVNode)
#define ESIZE sizeof(struct ENode)


typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef int GraphType;	// ����ͼ����(0: ����ͼ; 1: ����ͼ)

typedef int Bool;


typedef enum {

	False = 0,
	True

} Status;


typedef struct ENode {   /* �߶��� */

	Vertex V1, V2;       /* ����� <V1, V2> */
	WeightType Weight;    /* Ȩ�� */

} ENode, *Epointer;


typedef struct AdjVNode {    /* �ڽӵ㶨�� */

	Vertex AdjV;    /* �ڽӵ��±� */
	WeightType Weight;    /* ������ͼ�߱����ӱ�Ȩ��Weight */
	struct AdjVNode* Next;   /* ָ����һ���ڽӵ��ָ�� */

} AdjVNode, *Apointer;


typedef struct Vnode {    /* �����ͷ��� */

	DataType Data;      /* ���������ݣ�Data���Բ����� */
	Apointer FirstEdge;   /* �߱�ͷָ�� */

} AdjList[MaxVertexNum];


typedef struct GNode {   /* ͼ��� */

	int Nv;    /* ������ */
	int Ne;    /* ���� */
	AdjList G;	// �ڽӱ�

} GNode, *Gpointer;


Gpointer createGraph(int vertexNum);
Gpointer buildGraph();
void insertEdge(Gpointer graph, Epointer edge, GraphType kind);
void output(Gpointer graph);

void visit(Vertex v);
void DFS(Gpointer graph, Vertex randomVertex, void(*visit)(Vertex));