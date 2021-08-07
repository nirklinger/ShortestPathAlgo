#include "Algorithms.h"

LinkedList* Algorithms::BFS(const Graph& g) {
	const int s = g.getSIndex();
	const int n = g.getVerticesCount();
	LinkedList* levels = new LinkedList[n+1];
	levels[0].addToTail(s);
	int *colored = new int[n] ();

	for (int i = 0; i < n; i++) {
		Node *vertice = levels[i].getHead();
		while (vertice != nullptr) {
			int otherVertice = vertice->val;
			
			if (colored[otherVertice] == 0) {
				levels[i + 1].addToTail(otherVertice);
				colored[otherVertice] = 1;
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
	int* verticesByLevels = new int[n];

	for (int i = 0; i < n; i++) {
		Node* vertice = levels[i].getHead();

		while (vertice != nullptr) {
			verticesByLevels[vertice->val] = i;
		}
	}

	for (int i = 0; i < n; i++) {
		Node* vertice = g.getAdjList(i)->getHead();

		while (vertice != nullptr) {
			if (verticesByLevels[vertice->val] != i + 1) {
				g.removeEdge(i, vertice->val);
			}
		}
	}
	Node* nodesToDelete = levels[n].getHead();
	while (nodesToDelete!=nullptr)
	{
		g.getAdjList(nodesToDelete->val)->removeAllNodes();
	}
}

Graph& Algorithms::calcShortestPathes(Graph& g)
{
	LinkedList *levels = BFS(g);
	removeNonBFSEdges(g, levels);
	Graph Gtranspose=g.transpose();
	LinkedList* levelsForTranspose = BFS(Gtranspose);
	removeNonBFSEdges(Gtranspose, levelsForTranspose);
	return Gtranspose.transpose();

}