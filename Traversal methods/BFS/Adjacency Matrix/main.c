#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

#pragma warning(disable:4996)
#pragma warning(disable:6011)

int main() {

	Gpointer graph = NULL;

	graph = buildGraph();

	if (graph != NULL) {

		outputG(graph);

	}

	Vertex randomVertex;

	printf("\n请选择BFS起点(共 %d 个顶点, 从 0 开始):", graph->Nv - 1);

	scanf("%d", &randomVertex);

	BFS(graph, randomVertex, visit);
	
	return 0;

}


