#include "Algorithms.h"

LinkedList* Algorithms::BFS(Graph& g) {
	const int s = g.getSIndex();
	const int n = g.getVerticesCount();
	LinkedList* levels = new LinkedList[n + 1];
	levels[0].addToTail(s);
	int* colored = new int[n + 1]();
	colored[s] = 1;

	for (int i = 0; i < n; i++) {
		Node* vertice = levels[i].getHead();
		
		while (vertice != nullptr) {
			LinkedList* adjList = g.getAdjList(vertice->val);
			Node* adj = adjList != nullptr ? adjList->getHead() : nullptr;

			while (adj != nullptr) {
				int adjVal = adj->val;

				if (colored[adjVal] == 0) {
					levels[i + 1].addToTail(adjVal);
					colored[adjVal] = 1;
				}

				adj = adj->next;
			}

			vertice = vertice->next;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (colored[i] == 0)
		{
			levels[n].addToTail(i);
		}
	}

	delete[] colored;
	return levels;
}

void Algorithms::removeNonBFSEdges(Graph& g, LinkedList* levels) {
	int n = g.getVerticesCount();
	int* verticesByLevels = new int[n + 1];

	// for Each vertice we place at its value as index in array,
	// the level it was found on the BFS process
	for (int i = 0; i < n; i++) {
		Node* vertice = levels[i].getHead();

		while (vertice != nullptr) {
			verticesByLevels[vertice->val] = i;
			vertice = vertice->next;
		}
	}

	for (int i = 0; i <= n; i++) {
		LinkedList* adjList = g.getAdjList(i);
		Node* vertice = adjList != nullptr ? adjList->getHead() : nullptr;

		while (vertice != nullptr) {
			Node* tmp = vertice->next;
			
			if (verticesByLevels[vertice->val] != verticesByLevels[i] + 1) {
				g.removeEdge(i, vertice->val);
			}

			vertice = tmp;
		}
	}

	Node* nodesToDelete = levels[n].getHead();

	while (nodesToDelete != nullptr)
	{
		LinkedList* adjList = g.getAdjList(nodesToDelete->val);

		if (adjList != nullptr)
			adjList->removeAllNodes();

		nodesToDelete = nodesToDelete->next;
	}
}

Graph Algorithms::calcShortestPathes(Graph& g)
{
	LinkedList* levels = BFS(g);
	removeNonBFSEdges(g, levels);
	Graph gTranspose(g.transpose());
	LinkedList* levelsForTranspose = BFS(gTranspose);
	removeNonBFSEdges(gTranspose, levelsForTranspose);
	return gTranspose.transpose();
}