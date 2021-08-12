/*
This file contains our graph data structure
use to hold data members and basic actions of the data structure
*/

#ifndef UserInputH
#define UserInputH

#include <stdexcept>
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
	Graph() { vertices = nullptr; }															// empty ctor
	Graph(int _n, int _s = 0, int _t = 0) : n(_n), s(_s), t(_t) { makeEmptyGraph(n); }		// Creating an empty graph
	Graph(Graph& g);																		// copy ctor
	Graph(Graph&& other);																	// move ctor
	virtual ~Graph() { delete[] vertices; }													// distor
	void readGraph();																		// creating a graph from user input
	void makeEmptyGraph(int n);																// creating an empty graph with n vertices
	int isEmpty();																			// checking if the graph is empty or not
	void printGraph();																		// printing the graph for the user
	int getSIndex() const { return s; }														// return source vertice index
	int getTIndex() const { return t; }														// return destinition vertice index
	int getVerticesCount() const { return n; }												// output is how many vertices there is in the graph
	bool addEdge(int edge1, int edge2);														// adding edge between two spesific vertices
	bool removeEdge(int edge1, int edge2);													// removing spesific edge
	bool isAdjacent(int edge1, int edge2);													// checking if there is a spesific edge between two vertices
	LinkedList* getAdjList(int edge);														// getting an adj list of a spesific edge
	Graph transpose();																		// creating a transpose graph from existing graph
};

#endif