#include "Algorithms.h"

LinkedList* Algorithms::BFS(const Graph& g) {
	const int s = g.getSIndex();
	const int n = g.getVerticesCount();
	LinkedList* levels = new LinkedList[n];
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
			};
		}
	}
}