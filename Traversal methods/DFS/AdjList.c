#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

#pragma warning(disable:4996)


Gpointer createGraph(int vertexNum) {   /* ��ʼ��һ����VertexNum�����㵫�ޱߵ�ͼ */

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

	printf("�����봴��ͼ����(0: ����ͼ; 1: ����ͼ):");
	scanf("%d", &kind);

	printf("�����붥������");
	scanf("%d", &Nv);

	graph = createGraph(Nv);

	printf("�����������");
	scanf("%d", &(graph->Ne));

	if ((graph->Ne) != 0) {

		edge = (Epointer) malloc(ESIZE);

		printf("�밴��ʽ v1, v2, weight ����ͼ(Graph)�ı���Ϣ:\n");
		for (int i = 0; i < graph->Ne; i++) {

			printf("������� %d ���ߵ���Ϣ:", i + 1);
			scanf("%d%d%d", &(edge->V1), &(edge->V2), &(edge->Weight));

			insertEdge(graph, edge, kind);

		}

	}

	// ���������
	getchar();

	/* �������������ݣ��������� */
	printf("���������������(��%d��)��", graph->Nv);
	for (Vertex v = 0; v < graph->Nv; v++) {

		scanf("%c", &(graph->G[v].Data));

	}

}


void insertEdge(Gpointer graph, Epointer edge, GraphType kind) {

	Apointer newNode;

	 /* �����<V1, V2> */
	 /* ΪV2�����µ��ڽӵ� */
	newNode = (Apointer)malloc(ASIZE);
	newNode->AdjV = edge->V2;
	newNode->Weight = edge->Weight;

	 /* ��V2����V1�ı�ͷ */
	// �����ڽӱ��±���ű�ʾ����	
	newNode->Next = graph->G[edge->V1].FirstEdge;     /* ���գ����գ��������, �½��Ҫ���뵽��ǰ�� */
	graph->G[edge->V1].FirstEdge = newNode;
	
	if (kind == 0) {	// ��������ͼ

		/* �����<V2, V1> */
		newNode = (Apointer)malloc(ASIZE);
		newNode->AdjV = edge->V1;
		newNode->Weight = edge->Weight;

		/* ��V1����V2�ı�ͷ */
		newNode->Next = graph->G[edge->V2].FirstEdge;
		graph->G[edge->V2].FirstEdge = newNode;

	}

}


void output(Gpointer graph) {
	
	Apointer adjVNode = NULL;

	printf("��� Data ---> �ڽӵ�/Ȩ��\n");

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