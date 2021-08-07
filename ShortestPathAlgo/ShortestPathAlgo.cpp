// ShortestPathAlgo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Graph.h"
#include "Algorithms.h"

int main()
{
    Graph graph;
    graph.readGraph();
    cout << "test for end of file";
    Graph H = Algorithms::calcShortestPathes(graph);
    H.printGraph();

}