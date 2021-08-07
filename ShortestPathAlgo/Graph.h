#ifndef UserInputH
#define UserInputH

#include <string>
#include <iostream>
#include "LinkedList.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Graph {
	int n, t, s;
	LinkedList* vertices;
public:
	Graph() { vertices = nullptr; }
	virtual ~Graph() { delete vertices; }
	void readGraph();
	void makeEmptyGraph(int n);
	int isEmpty();
	void printGraph();
	int getSIndex() const { return s; }
	int getTIndex() const { return t; }
	int getVerticesCount() const { return n; }
	bool addEdge(int edge1, int edge2);
	bool removeEdge(int edge1, int edge2);

	bool isAdjacent(int edge1, int edge2);
	LinkedList* getAdjList(int edge);
};

#endif