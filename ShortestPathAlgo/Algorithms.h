/*
This class is in charge of the BFS algoritham and some supporitve actions thats being used on our graph
*/

#ifndef AlgorithmsH
#define AlgorithmsH

#include "Graph.h"
#include "LinkedList.h"

class Algorithms {
	static LinkedList* BFS(Graph &g);									//input - graph, output - array of vertices levels found on BFS
	static void removeNonBFSEdges(Graph& g, LinkedList* levels);		//input - graph, array of vertices levels by BFS, result - graph containing only edges thats are contributing to the shortest path to the next level by BFS
public:
	static Graph calcShortestPathes(Graph& g);							//input - graph, output - all edges of the shortest path graph
};

#endif