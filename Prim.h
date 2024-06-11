#pragma once

#include "Graph.h"
#include "Edge.h"

#include <queue>
#include <vector>
#include <iostream>


// Function to find the minimum spanning tree using Prim's algorithm
void MSTPrim(Graph* graph) {
    // Create a priority queue to store the edges
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

    // Create a vector to store the visited vertices
    std::vector<bool> visited(graph->getVerticeCount(), false);

    // Create a graph to store the minimum spanning tree
    std::vector<Edge> mst;

    // Start with the first vertex
    int startVertex = 0;
    visited[startVertex] = true;

    // Add all the edges of the start vertex to the priority queue
    for (int vertex = 0; vertex < graph->getVerticeCount(); vertex++) {
        // Ignore self-loop edges
        if (startVertex == vertex) {
            continue;
        }
        int weight = graph->checkEdge(startVertex, vertex);
        if (weight != 0) {
            Edge edge(startVertex, vertex, weight);
            pq.push(edge);
        }
    }

    // Variable to store the sum of weights of edges
    int sumOfWeights = 0;

    // Loop until all vertices are visited
    while (!pq.empty()) {
        // Get the edge with the minimum weight
        Edge minEdge = pq.top();
        pq.pop();

        int vertex1 = minEdge.getVertex1();
        int vertex2 = minEdge.getVertex2();

        // Check if the edge forms a cycle
        if (visited[vertex1] && visited[vertex2]) {
            continue;
        }

        // Add the edge to the minimum spanning tree
        mst.push_back(minEdge);

        // Add the weight of the edge to the sum
        sumOfWeights += minEdge.weight;

        // Mark the vertices as visited
        visited[vertex1] = true;
        visited[vertex2] = true;

        // Add all the edges of the start vertex to the priority queue
        for (int vertex = 0; vertex < graph->getVerticeCount(); vertex++) {
            // Ignore self-loop edges
            if (vertex2 == vertex) {
                continue;
            }
            int weight = graph->checkEdge(vertex2, vertex);
            if (weight != 0) {
                Edge edge(vertex2, vertex, weight);
                pq.push(edge);
            }
        }
    }

    std::cout << "Minimum Spanning Tree:" << std::endl;
    for (Edge edge : mst) {
        std::cout << edge.getVertex1() << " -- " << edge.getVertex2() << " : " << edge.weight << std::endl;
    }

    std::cout << "Sum of weights of edges: " << sumOfWeights << std::endl;
}
