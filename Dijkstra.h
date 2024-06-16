#pragma once

#include "Graph.h"
#include "PriorityQueue.h"
#include <vector>  
#include <limits.h>
#include <iostream>
#include <chrono>

auto ShortestPathDijkstra(Graph* graph, int startNode, int endNode) {

    auto start_time = std::chrono::high_resolution_clock::now();

    int numNodes = graph->getVerticeCount();

    if (startNode < 0 || startNode >= numNodes || endNode < 0 || endNode >= numNodes) {
        cout << "Vertices out of this graph scope";
    }

    // Dystans od startowego wierzcholka do wszystkich innych
    int* distances = new int[numNodes];
    for (int i = 0; i < numNodes; i++) {
        distances[i] = INT_MAX;
    }

    PriorityQueue pq;

    distances[startNode] = 0;
    pq.push({ startNode, 0 });

    int* previousNodes = new int[numNodes];
    for (int i = 0; i < numNodes; i++) {
        previousNodes[i] = -1;
    }

    // Dopoki nie wykorzystamy wszyskich krawedzi
    while (!pq.isEmpty()) {
        node currentNode = pq.pop();

        if (currentNode.Vertice == endNode) {
            break;
        }

        for (int neighbor = 0; neighbor < numNodes; neighbor++) {
            if (neighbor == currentNode.Vertice) {
                continue;
            }
            // Jesli znaleziono krawedz
            int edgeWeight = graph->checkEdge(currentNode.Vertice, neighbor);
            if (edgeWeight != 0) {
                int distance = currentNode.Value + edgeWeight;
                // Jesli dystans jest mniejszy niz aktualny
                if (distance < distances[neighbor]) {
                    distances[neighbor] = distance;
                    pq.push({ neighbor, distance });
                    previousNodes[neighbor] = currentNode.Vertice;
                }
            }
        }
    }

    std::vector<int> shortestPath;

    if (distances[endNode] != INT_MAX) {
        int currentNode = endNode;
        while (currentNode != -1) {
            shortestPath.push_back(currentNode);
            currentNode = previousNodes[currentNode];
        }

        std::reverse(shortestPath.begin(), shortestPath.end());
    }

    //std::cout << "Najkrotsza droga: ";
    //for (int node : shortestPath) {
    //    std::cout << node << " ";
    //}
    //std::cout << "Dystans: " << distances[endNode] << std::endl;

    delete[] distances;
    delete[] previousNodes;

    //std::cout << std::endl;

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    //std::cout << "Czas w ms: " << time << endl;

    return time;
}
