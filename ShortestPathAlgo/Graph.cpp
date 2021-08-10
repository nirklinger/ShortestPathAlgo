#include "Graph.h"

void Graph::readGraph() {
	cin >> n;
	cin >> s;
	cin >> t;

	if (s < 0 || t < 0 || s > n || t > n) 
	{
		cout << "wrong input" << endl;
		return;
	}

	makeEmptyGraph(n);

	int edge1, edge2;
	bool lastEdgeIsValid = true;
	
	while (lastEdgeIsValid && cin >> edge1 && cin >> edge2) 
	{
		lastEdgeIsValid = addEdge(edge1, edge2);
	}

	if (!lastEdgeIsValid) 
	{
		cout << "wrong input" << endl;
		return;
	}
}

void Graph::makeEmptyGraph(int n) {
	vertices = new LinkedList[n+1];
}

bool Graph::addEdge(int edge1, int edge2) 
{
	if (edge1 > 0 && edge1 <= n &&
		edge2 > 0 && edge2 <= n &&
		edge1 != edge2) {
		vertices[edge1].addToTail(edge2);
		return true;
	} 
	return false;
}

bool Graph::removeEdge(int edge1, int edge2)
{
	if (edge1 > 0 && edge1 <= n &&
		edge2 > 0 && edge2 <= n &&
		edge1 != edge2) {
		return vertices[edge1].deleteNode(edge2);
	}
	return false;
}

bool Graph::isAdjacent(int edge1, int edge2)
{
	if (edge1 > 0 && edge1 <= n &&
		edge2 > 0 && edge2 <= n &&
		edge1 != edge2)
	{
		return vertices[edge1].search(edge2);
	}
	return false;
}

LinkedList* Graph::getAdjList(int edge) 
{ 
	if (edge >= 0 && edge <= n)
	{
		return &(vertices[edge]);
	}
	return nullptr;
}

void Graph::printGraph()
{
	LinkedList* index;
	Node *nodeToPrint;
	for (int i = 1; i <= n; i++)
	{
		index = getAdjList(i);
		if (index == nullptr)
			continue;

		nodeToPrint = index->getHead();
		
		while (nodeToPrint != nullptr)
		{
			cout << i << " " << nodeToPrint->val << endl;
			nodeToPrint = nodeToPrint->next;
		}
	}
}

int Graph::isEmpty()
{
	if (n == 0)
		return 1;
	return 0;
}

Graph::Graph(Graph&& other) {	
	vertices = other.vertices;
	n = other.n;
	t = other.t;
	s = other.s;

	other.vertices = nullptr;
	other.n = 0;
}

Graph Graph::transpose()
{
	Graph tGraph(n,t,s);
	for (int i = 0; i <= n; i++)
	{
		Node* index = getAdjList(i)->getHead();
		while (index != nullptr)
		{
			tGraph.addEdge(index->val,i);
			index = index->next;
		}
	}
	return tGraph;
}
