#ifndef AlgorithmsH
#define AlgorithmsH

#include "Graph.h"
#include "LinkedList.h"

class Algorithms {
	static LinkedList* BFS(const Graph &g);
	static void removeNonBFSEdges(Graph& g, LinkedList* levels);
public:
	
};

#endif