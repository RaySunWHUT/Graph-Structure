#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

#pragma warning(disable:4996)


int main() {

	Gpointer graph;

	graph = buildGraph();

	output(graph);
	
	Vertex randomVertex;

	printf("��ѡ��DFS���(�� %d ������, �� 0 ��ʼ)", graph->Nv - 1);
	
	scanf("%d", &randomVertex);

	DFS(graph, randomVertex, visit);

	return 0;

}

