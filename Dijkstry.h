#pragma once

#include "Graph.h"
#include "PriorityQueue.h"
#include <vector>  
#include <limits.h>
#include <iostream>

// Function to find the shortest path using Dijkstra's algorithm
void ShortestPathDijkstra(Graph* graph, int startNode, int endNode) {

    int numNodes = graph->getVerticeCount();

    if (startNode < 0 || startNode >= numNodes || endNode < 0 || endNode >= numNodes) {
        cout << "Vertices out of this graph scope";
        return;
    }

    // Create an array to store the distances from the start node to all other nodes
    int* distances = new int[numNodes];
    for (int i = 0; i < numNodes; i++) {
        distances[i] = INT_MAX;
    }

    // Create a priority queue to store the nodes based on their distances
    PriorityQueue pq;

    // Set the distance of the start node to 0 and push it into the priority queue
    distances[startNode] = 0;
    pq.push({ startNode, 0 });

    // Create an array to store the previous node for each node in the shortest path
    int* previousNodes = new int[numNodes];
    for (int i = 0; i < numNodes; i++) {
        previousNodes[i] = -1;
    }

    // Loop until the priority queue is empty
    while (!pq.isEmpty()) {
        // Get the node with the minimum distance from the priority queue
        node currentNode = pq.pop();

        // If the current node is the end node, we have found the shortest path
        if (currentNode.Vertice == endNode) {
            break;
        }

        // Check the neighbors of the current node
        for (int neighbor = 0; neighbor < numNodes; neighbor++) {
            // Ignore self-loop edges
            if (neighbor == currentNode.Vertice) {
                continue;
            }
            // If there is an edge between the current node and the neighbor
            int edgeWeight = graph->checkEdge(currentNode.Vertice, neighbor);
            if (edgeWeight != 0) {
                // Calculate the distance to the neighbor through the current node
                int distance = currentNode.Value + edgeWeight;
                // If the calculated distance is smaller than the current distance to the neighbor
                if (distance < distances[neighbor]) {
                    // Update the distance and push the neighbor into the priority queue
                    distances[neighbor] = distance;
                    pq.push({ neighbor, distance });
                    // Update the previous node for the neighbor
                    previousNodes[neighbor] = currentNode.Vertice;
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
        while (currentNode != -1) {
            shortestPath.push_back(currentNode);
            currentNode = previousNodes[currentNode];
        }

        // Reverse the shortest path to get the correct order
        std::reverse(shortestPath.begin(), shortestPath.end());
    }

    std::cout << "Shortest Path: ";
    for (int node : shortestPath) {
        std::cout << node << " ";
    }
    std::cout << "Distance: " << distances[endNode] << std::endl;

    delete[] distances;
    delete[] previousNodes;

    std::cout << std::endl;
}
