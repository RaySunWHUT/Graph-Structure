#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

#pragma warning(disable:4996)


// 全局变量: 访问标志数组
Bool visited[MaxVertexNum] = { False };	// 注: 不能在.h文件中声明并初始化全局变量, 否则报错！


void visit(Vertex v) {

	printf("正在访问顶点%d\n", v);

}


void DFS(Gpointer graph, Vertex randomVertex, void(*visit)(Vertex)) {

	Apointer w;

	// 访问随机的第 v 个结点
	visit(randomVertex);

	// 标志已访问
	visited[randomVertex] = True;

	for (w = graph->G[randomVertex].FirstEdge; w != NULL; w = w->Next) {

		if (!visited[w->AdjV]) {	// 邻接点未被访问

			DFS(graph, w->AdjV, visit);

		}

	}

}
