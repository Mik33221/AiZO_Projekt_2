#pragma once

#include <vector>
#include <queue>
#include <limits>
#include <iostream>
#include "Graph.h"

//WIP

using namespace std;

// Function to perform Ford-Fulkerson algorithm to find the maximum flow in a graph
void fordFulkerson(Graph* graph, int source, int sink) {
    int numVertices = graph->getVerticeCount();
    
    // Create a residual graph and initialize it with the original capacities
    vector<vector<int>> residualGraph(numVertices, vector<int>(numVertices, 0));
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if(i == j)
                continue;
            residualGraph[i][j] = graph->checkEdge(i,j);
        }
    }
    
    // Create an array to store the parent of each vertex in the augmenting path
    vector<int> parent(numVertices, -1);
    
    int maxFlow = 0; // Initialize the maximum flow to 0
    
    // Augment the flow while there is a path from source to sink in the residual graph
    while (true) {
        // Use BFS to find an augmenting path from source to sink
        queue<int> q;
        q.push(source);
        parent[source] = -2;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v = 0; v < numVertices; v++) {
                if (parent[v] == -1 && residualGraph[u][v] > 0) {
                    q.push(v);
                    parent[v] = u;
                }
            }
        }
        
        // If there is no augmenting path, break the loop
        if (parent[sink] == -1) {
            break;
        }
        
        // Find the minimum residual capacity along the augmenting path
        int pathFlow = numeric_limits<int>::max();
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }
        
        // Update the residual capacities and reverse edges along the augmenting path
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }
        
        // Add the path flow to the maximum flow
        maxFlow += pathFlow;
    }
    
    // Print the maximum flow
    cout << "Maximum Flow: " << maxFlow << endl;
}
