#include <iostream>
#include <chrono>
#include <iomanip>
#include <stdexcept>
#include "Graph.h"
#include "Algorithms.h"
using std::ios_base;
using namespace std::chrono;

void printTimes(double time_taken) {
    time_taken *= 1e-9;
    cout << "Time taken by function Algorithms::calcShortestPathes is : " << std::fixed
        << time_taken << std::setprecision(9);
    cout << " sec" << endl;
}

int main()
{
    Graph graph;

    try {
        graph.readGraph();
    }
    catch (const std::invalid_argument& err) {
        std::cerr << err.what() << endl;
        exit(1);
    }

    auto start = high_resolution_clock::now();
    // unsync the I/O of C and C++.
    ios_base::sync_with_stdio(false);

    // Act 
    Graph H(Algorithms::calcShortestPathes(graph));
    auto end = high_resolution_clock::now();
    // Calculating total time taken by the program.
    double time_taken = duration_cast<nanoseconds>(end - start).count();
    // Program output
    H.printGraph();
    printTimes(time_taken);
}