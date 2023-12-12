// FILE: Graphs.cpp
#include "Graphs.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <limits>

using namespace std;


// Constructor
Graphs::Graphs() {
    E = V = order = 0;
}

// Destructor
Graphs::~Graphs() {
}


// Map vertex number (0,1,2,..) to (A,B,C,..)
char Graphs::Vname(const int s) const {
    return char(s + 65);
}

// Get Graph from text File
void Graphs::getGraph(string fname) {
    ifstream source(fname.c_str());
    if (!source) {
        cerr << "Error: File could not be opened" << endl;
        return;
    }

    source >> V; // Read number of vertices

    E = 0; // Reset number of edges
    for (int r = 0; r < V; r++) {
        for (int c = 0; c < V; c++) {
            source >> AdjMatrix[r][c];
            if (r < c && AdjMatrix[r][c] != 0) {
                edges[E++] = Edge{r, c, AdjMatrix[r][c]};
            }
        }
    }
    source.close();
}


// Display Adjacency Matrix
void Graphs::dispGraph() const {
    cout << "Adjacency Matrix\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << setw(3) << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Get Non-Zero edges from adjacency matrix
// and store them in array edges[].
// Get Non-Zero edges from adjacency matrix
void Graphs::getEdges() {
    E = 0; // Reset edge count
    for (int r = 0; r < V; r++) {
        for (int c = r + 1; c < V; c++) {
            if (AdjMatrix[r][c] > 0) {
                edges[E++] = Edge{r, c, AdjMatrix[r][c]};
            }
        }
    }
}

// Get number of vertices
int Graphs::No_of_Verices() const {
    return V;
}


// Get Number of Non-zero edges
int Graphs::No_of_Edges() const {
    return E;
}

// Output an edge
void Graphs::printEdge(Edge e) const {
    cout << Vname(e.u) << " - " << Vname(e.v) << " : " << e.w << endl;
}


// Display Graph Edges
void Graphs::dispEdges() const {
    cout << "Graph Edges\n";
    for (int i = 0; i < E; i++) {
        printEdge(edges[i]);
    }
}

// Shortest paths from node s (Dijkstra's Algorithm)
void Graphs::shPath(int s) {
    // Initialize distances to maximum value
    for (int i = 0; i < V; i++) {
        distance[i] = numeric_limits<weightType>::max();
        via[i] = -1;
        processed[i] = false;
    }

    // Priority queue for shortest tentative distance
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    distance[s] = 0;
    pq.push(Edge{s, s, 0});

    while (!pq.empty()) {
        Edge smallest = pq.top();
        pq.pop();
        int u = smallest.v;

        if (processed[u]) continue;

        processed[u] = true;

        for (int v = 0; v < V; v++) {
            if (AdjMatrix[u][v] && !processed[v]) {
                weightType newDist = distance[u] + AdjMatrix[u][v];
                if (newDist < distance[v]) {
                    distance[v] = newDist;
                    pq.push(Edge{u, v, distance[v]});
                    via[v] = u;
                }
            }
        }
    }
}


// Print path (vertex names) from source (s) to destination (i)
void Graphs::printPath(int s, int i) const {
    if (i == s) {
        cout << Vname(s);
        return;
    } else if (via[i] == -1) {
        cout << "No path from " << Vname(s) << " to " << Vname(i) << " exists.";
        return;
    } else {
        printPath(s, via[i]); // Recursively call to print the previous vertex in the path
        cout << " -> " << Vname(i); // Print the current vertex
    }
}

// Node Visit Function for DFS
void Graphs::visit(int k) {
    val[k] = order++; // Set the order of visit for the node
    cout << "Visited " << Vname(k) << " at order " << val[k] << endl;

    // Additional processing can be done here if required
}


// Depth First Search Traversal
void Graphs::DFS() {
    // Array to keep track of visited vertices
    vector<bool> visited(V, false);

    // Call the recursive helper function for each vertex
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFSRecursive(i, visited);
        }
    }
}

// Private helper function for DFS, implemented as a part of the Graphs class
void Graphs::DFSRecursive(int v, vector<bool> &visited){};