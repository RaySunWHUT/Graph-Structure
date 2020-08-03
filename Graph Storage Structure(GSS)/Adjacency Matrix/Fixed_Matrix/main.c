#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

#pragma warning(disable:4996)

int main() {

	Gpointer Graph = NULL;

	Graph = buildGraph();

	if (Graph != NULL) {
		output(Graph);
	}

	return 0;

}


