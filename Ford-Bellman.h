#pragma once

#include "Graph.h"
#include <vector>  
#include <limits.h>
#include <iostream>
#include <chrono>

auto ShortestPathFordBellman(Graph* graph, int startNode, int endNode) {

    auto start_time = std::chrono::high_resolution_clock::now();

    int numNodes = graph->getVerticeCount();

    if (startNode < 0 || startNode >= numNodes || endNode < 0 || endNode >= numNodes) {
        std::cout << "Vertices out of this graph scope";
    }

    // Dystans od startowego wierzcholka do wszystkich innych
    int* distances = new int[numNodes];
    for (int i = 0; i < numNodes; i++) {
        distances[i] = INT_MAX;
    }

    distances[startNode] = 0;

    // Wielokrotna relaksacja wszystkich krawedzi
    for (int i = 0; i < numNodes - 1; i++) {    //wykonujemy wierzcholki - 1 razy
        for (int u = 0; u < numNodes; u++) {    
            std::vector<Edge> edges = graph->getEdges(u);
            for (Edge edge : edges) {
				int v = edge.getVertex2();
				int weight = edge.getWeight();
                if (u == v) {
                    continue;
                }
				if (weight != 0 && distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
					distances[v] = distances[u] + weight;
				}
			}
        }
    }

    std::vector<int> shortestPath;

    if (distances[endNode] != INT_MAX) {
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

        std::reverse(shortestPath.begin(), shortestPath.end());
    }

    std::cout << "Najkrotsza droga: ";
    std::cout << startNode << " ";
    for (int node : shortestPath) {
        std::cout << node << " ";
    }
    std::cout << "Dystans: " << distances[endNode] << std::endl;

    delete[] distances;

    std::cout << std::endl;

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "Czas w ms: " << time << endl;

    return time;
}
