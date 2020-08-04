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

	printf("请选择DFS起点(共 %d 个顶点, 从 0 开始)", graph->Nv - 1);
	
	scanf("%d", &randomVertex);

	DFS(graph, randomVertex, visit);

	return 0;

}

