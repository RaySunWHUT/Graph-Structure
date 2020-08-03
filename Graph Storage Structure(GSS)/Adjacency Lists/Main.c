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

	return 0;

}

