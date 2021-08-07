#ifndef AlgorithmsH
#define AlgorithmsH

#include "Graph.h"
#include "LinkedList.h"

class Algorithms {
	static LinkedList* BFS(Graph &g);
	static void removeNonBFSEdges(Graph& g, LinkedList* levels);
public:
	static Graph& calcShortestPathes(Graph& g);

};

#endif