#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

#pragma warning(disable:4996)


// 全局变量: 访问标志数组
Bool dfs_visited[MaxVertexNum] = { False };	// 注: 不能在.h文件中声明并初始化全局变量, 否则报错！


void DFS(Gpointer graph, Vertex randomVertex, void(*visit)(Vertex)) {

	// 访问随机的第 v 个结点
	visit(randomVertex);

	// 标志已访问
	dfs_visited[randomVertex] = True;

	for (Vertex v2 = 0; v2 < graph->Nv; v2++) {

		// randomVertex 与 v2存在边, 且v2未被访问过
		if (!dfs_visited[v2] && isEdge(graph, randomVertex, v2)) {

			DFS(graph, v2, visit);

		}

	}

}

