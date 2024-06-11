#pragma once

#include "Graph.h"
#include <vector>  
#include <limits.h>
#include <iostream>

// Function to find the shortest path using Ford-Bellman algorithm
void ShortestPathFordBellman(Graph* graph, int startNode, int endNode) {

    int numNodes = graph->getVerticeCount();

    if (startNode < 0 || startNode >= numNodes || endNode < 0 || endNode >= numNodes) {
        std::cout << "Vertices out of this graph scope";
        return;
    }

    // Create an array to store the distances from the start node to all other nodes
    int* distances = new int[numNodes];
    for (int i = 0; i < numNodes; i++) {
        distances[i] = INT_MAX;
    }

    // Set the distance of the start node to 0
    distances[startNode] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < numNodes - 1; i++) {
        for (int u = 0; u < numNodes; u++) {
            for (int v = 0; v < numNodes; v++) {
                if (u == v) {
					continue;
				}
                int edgeWeight = graph->checkEdge(u, v);
                if (edgeWeight != 0 && distances[u] != INT_MAX && distances[u] + edgeWeight < distances[v]) {
                    distances[v] = distances[u] + edgeWeight;
                }
            }
        }
    }

    // Create a vector to store the shortest path
    std::vector<int> shortestPath;

    // If there is a path from the start node to the end node
    if (distances[endNode] != INT_MAX) {
        // Traverse the path backwards from the end node to the start node
        int currentNode = endNode;
        while (currentNode != startNode) {
            shortestPath.push_back(currentNode);
            for (int v = 0; v < numNodes; v++) {
                if (v == currentNode) {
                    continue;
                }
                int edgeWeight = graph->checkEdge(v, currentNode);
                if (edgeWeight != 0 && distances[v] + edgeWeight == distances[currentNode]) {
                    currentNode = v;
                    break;
                }
            }
        }

        // Reverse the shortest path to get the correct order
        std::reverse(shortestPath.begin(), shortestPath.end());
    }

    std::cout << "Shortest Path: ";
    std::cout << startNode << " ";
    for (int node : shortestPath) {
        std::cout << node << " ";
    }
    std::cout << "Distance: " << distances[endNode] << std::endl;

    delete[] distances;

    std::cout << std::endl;
}
