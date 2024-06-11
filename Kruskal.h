#pragma once

#include "Graph.h"
#include "Edge.h"

#include <queue>
#include <vector>
#include <iostream>



// Function to find the parent of a vertex
int findParent(std::vector<int>& parent, int vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = findParent(parent, parent[vertex]);
    }
    return parent[vertex];
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void MSTKruskal(Graph* graph) {
    // Create a priority queue to store the edges
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> edges;

    // Add all the edges to the priority queue
    for (int vertex1 = 0; vertex1 < graph->getVerticeCount(); vertex1++) {
        for (int vertex2 = vertex1 + 1; vertex2 < graph->getVerticeCount(); vertex2++) {
            int weight = graph->checkEdge(vertex1, vertex2);
            if (weight != 0) {
                Edge edge(vertex1, vertex2, weight);
                edges.push(edge);
            }
        }
    }

    // Create a vector to store the parent of each vertex
    std::vector<int> parent(graph->getVerticeCount());

    // Initialize the parent vector
    for (int vertex = 0; vertex < graph->getVerticeCount(); vertex++) {
        parent[vertex] = vertex;
    }

    // Create a vector to store the minimum spanning tree
    std::vector<Edge> mst;

    // Variable to store the sum of weights of edges
    int sumOfWeights = 0;

    // Loop through all the edges
    while (!edges.empty()) {
        Edge edge = edges.top();
        edges.pop();

        int vertex1 = edge.getVertex1();
        int vertex2 = edge.getVertex2();

        // Find the parent of each vertex
        int parent1 = findParent(parent, vertex1);
        int parent2 = findParent(parent, vertex2);

        // Check if adding the edge will form a cycle
        if (parent1 != parent2) {
            // Add the edge to the minimum spanning tree
            mst.push_back(edge);

            // Add the weight of the edge to the sum
            sumOfWeights += edge.weight;

            // Union the two vertices
            parent[parent1] = parent2;
        }
    }

    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (Edge edge : mst) {
        std::cout << edge.getVertex1() << " -- " << edge.getVertex2() << " : " << edge.weight << std::endl;
    }

    std::cout << "Sum of weights of edges: " << sumOfWeights << std::endl;
}

