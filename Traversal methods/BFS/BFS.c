#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Header.h"

#pragma warning(disable:4996)
#pragma warning(disable:6001)


// 全局变量: 访问标志数组
Bool bfs_visited[MaxVertexNum] = { False };	// 注: 不能在.h文件中声明并初始化全局变量, 否则报错！


//Bool isEdge(Gpointer graph, Vertex v1, Vertex v2) {
//
//	for (Apointer p = graph->G[v1].FirstEdge; p != NULL; p = p->Next) {
//
//		if (p->AdjV == v2) {
//
//			return True;
//
//		}
//
//	}
//
//	//printf("%d与%d间不存在边(Edge). \n", v1, v2);
//	return False;
//
//}


// 以randomVertex为出发点, 对邻接表存储的图Graph进行 BFS 搜索
void BFS(Gpointer graph, Vertex randomVertex, void(*visit)(Vertex)) {

	Vertex v1;

	Qpointer queen;

	// 创建空队列, maxSize为最大容量
	queen = createQueue(15);

	// 访问顶点randomVertex
	visit(randomVertex);

	// 标志顶点randomVertex已被访问
	bfs_visited[randomVertex] = True;

	// randomVertex入队
	addQ(queen, randomVertex);

	while (!isQEmpty(queen)) {

		// 弹出v1
		v1 = deleteQ(queen);

		for (Apointer p = graph->G[v1].FirstEdge; p != NULL; p = p->Next) {

			if (!bfs_visited[p->AdjV]) {

				// 访问顶点v2
				visit(p->AdjV);

				// 标记v2已被访问
				bfs_visited[p->AdjV] = True;

				// v2入队
				addQ(queen, p->AdjV);

			}

		}

	}

}



Qpointer createQueue(int maxSize) {

	Qpointer headp = NULL;

	headp = (Qpointer)malloc(QSIZE);
	headp->front = headp->rear = NULL;
	headp->maxSize = maxSize;

	return headp;

}


Bool isQEmpty(Qpointer headp) {

	return (headp->front == NULL);

}


Qpointer addQ(Qpointer headp, Vertex v) {

	Npointer nodep = NULL;

	if (isQEmpty(headp)) {

		nodep = (Npointer)malloc(NSIZE);
		nodep->v = v;
		nodep->next = NULL;
		headp->front = nodep;
		headp->rear = nodep;

	} else {

		nodep = (Npointer)malloc(NSIZE);      /*  pList list = (pList)malloc(sizeof(lis)); */
		nodep->v = v;	                      /*  list->element = element; */
		nodep->next = NULL;
		headp->rear->next = nodep;            /*  list->next = queue->rear->next; */
		headp->rear = headp->rear->next;      /*  queue->rear->next = list; */
											  /*  queue->rear = list; */
	}

	return headp;

}


Vertex deleteQ(Qpointer headp) {

	Npointer front = NULL;

	Vertex v;

	if (isQEmpty(headp)) {

		printf("The Queue is empty!\n");

	} else {

		front = headp->front;

		v = front->v;

		if (headp->front == headp->rear) {    /* 若队列中只有一个结点 */

			headp->front = headp->rear = NULL;

		}
		else {

			headp->front = headp->front->next;

		}

		free(front);

	}

	return v;

}

