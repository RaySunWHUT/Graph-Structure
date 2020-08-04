#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

#pragma warning(disable:4996)


// ȫ�ֱ���: ���ʱ�־����
Bool visited[MaxVertexNum] = { False };	// ע: ������.h�ļ�����������ʼ��ȫ�ֱ���, ���򱨴�


void visit(Vertex v) {

	printf("���ڷ��ʶ���%d\n", v);

}


void DFS(Gpointer graph, Vertex randomVertex, void(*visit)(Vertex)) {

	Apointer w;

	// ��������ĵ� v �����
	visit(randomVertex);

	// ��־�ѷ���
	visited[randomVertex] = True;

	for (w = graph->G[randomVertex].FirstEdge; w != NULL; w = w->Next) {

		if (!visited[w->AdjV]) {	// �ڽӵ�δ������

			DFS(graph, w->AdjV, visit);

		}

	}

}
