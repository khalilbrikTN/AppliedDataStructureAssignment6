#include <iostream>
#include "Graphs.h"

using namespace std;

int main() {
    string file_reference = "/home/khalil/Desktop/courses/applied_data_structures/AssignBonus/Sample.txt";
    Graphs gh;

    gh.getGraph(file_reference);
    gh.dispGraph();
    gh.dispEdges();

    // Testing DFS
    cout << "\nDepth First Search Traversal:\n";
    gh.DFS();

    // Testing Dijkstra's Algorithm for shortest paths
    int sourceVertex = 0; // Replace with your desired source vertex
    cout << "\nShortest paths from vertex " << char('A' + sourceVertex) << ":\n";
    gh.shPath(sourceVertex);

    // Optionally, you can display the shortest path to a specific vertex
    int destinationVertex = 3; // Replace with your desired destination vertex
    cout << "\nShortest path from " << char('A' + sourceVertex) << " to " << char('A' + destinationVertex) << ":\n";
    gh.printPath(sourceVertex, destinationVertex);

    return 0;
}
