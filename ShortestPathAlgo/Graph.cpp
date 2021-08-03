#include "Graph.h"

void Graph::readGraph() {
	cin >> n;
	cin >> s;
	cin >> t;

	if (s < 0 || t < 0 || s > n || t > n) {
		cout << "wrong input" << endl;
		return;
	}

	makeEmptyGraph(n);

	int edge1, edge2;
	bool lastEdgeIsValid = true;
	
	while (lastEdgeIsValid && cin >> edge1 && cin >> edge2) {
		lastEdgeIsValid = addEdge(edge1, edge2);
	}

	if (!lastEdgeIsValid) {
		cout << "wrong input" << endl;
		return;
	}
}

void Graph::makeEmptyGraph(int n) {
	vertices = new LinkedList[n+1];
}

bool Graph::addEdge(int edge1, int edge2) {
	if (edge1 > 0 && edge1 <= n &&
		edge2 > 0 && edge2 <= n &&
		edge1 != edge2) {
		vertices[edge1].addToTail(new Node(edge2));
		return true;
	} 
	
	return false;
}
