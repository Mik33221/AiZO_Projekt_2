#pragma once

#include "Graph.h"
#include "Edge.h"

#include <queue>
#include <vector>
#include <iostream>
#include <chrono>


auto MSTPrim(Graph* graph) {

    auto start_time = std::chrono::high_resolution_clock::now();

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

    std::vector<bool> visited(graph->getVerticeCount(), false);

    std::vector<Edge> mst;

    int startVertex = 0;
    visited[startVertex] = true;

    for (int vertex = 0; vertex < graph->getVerticeCount(); vertex++) {
        if (startVertex == vertex) {
            continue;
        }
        int weight = graph->checkEdge(startVertex, vertex);
        if (weight != 0) {
            Edge edge(startVertex, vertex, weight);
            pq.push(edge);
        }
    }

    int sumOfWeights = 0;

    // Dla kazdej krawedzi
    while (!pq.empty()) {
        Edge minEdge = pq.top();
        pq.pop();

        int vertex1 = minEdge.getVertex1();
        int vertex2 = minEdge.getVertex2();

        // Sprawdzamy czy krawedz nie tworzy cyklu
        if (visited[vertex1] && visited[vertex2]) {
            continue;
        }

        mst.push_back(minEdge);

        sumOfWeights += minEdge.weight;

        visited[vertex1] = true;
        visited[vertex2] = true;

        // Wypelniamy priorityqueue krawedziami wychodzacymi z tego wierzcholka
        for (int vertex = 0; vertex < graph->getVerticeCount(); vertex++) {
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

    std::cout << "MST----------:" << std::endl;
    for (Edge edge : mst) {
        std::cout << edge.getVertex1() << " -- " << edge.getVertex2() << " : " << edge.weight << std::endl;
    }

    std::cout << "Suma wag krawedzi: " << sumOfWeights << std::endl;

    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();

    std::cout << "Czas w ms: " << time << endl;

    return time;
}
