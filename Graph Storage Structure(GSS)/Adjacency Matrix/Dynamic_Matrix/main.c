#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

#pragma warning(disable:4996)

int main() {

	Gpointer graph = NULL;

	graph = buildGraph();
	
	if (graph != NULL) {

		output(graph);
	
	}

	return 0;

}


