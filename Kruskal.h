#pragma once

#include "Graph.h"
#include "Edge.h"

#include <queue>
#include <vector>
#include <iostream>
#include <chrono>



int findParent(std::vector<int>& parent, int vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = findParent(parent, parent[vertex]);
    }
    return parent[vertex];
}

auto MSTKruskal(Graph* graph) {

    auto start_time = std::chrono::high_resolution_clock::now();

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> edges;

    for (int vertex1 = 0; vertex1 < graph->getVerticeCount(); vertex1++) {
        for (int vertex2 = vertex1 + 1; vertex2 < graph->getVerticeCount(); vertex2++) {
            int weight = graph->checkEdge(vertex1, vertex2);
            if (weight != 0) {
                Edge edge(vertex1, vertex2, weight);
                edges.push(edge);
            }
        }
    }

    // Wektor na rodzicow kazdego wierzcholka
    std::vector<int> parent(graph->getVerticeCount());

    for (int vertex = 0; vertex < graph->getVerticeCount(); vertex++) {
        parent[vertex] = vertex;
    }

    std::vector<Edge> mst;

    int sumOfWeights = 0;

    // Dla kazdej krawedzi
    while (!edges.empty()) {
        Edge edge = edges.top();
        edges.pop();

        int vertex1 = edge.getVertex1();
        int vertex2 = edge.getVertex2();

        int parent1 = findParent(parent, vertex1);
        int parent2 = findParent(parent, vertex2);

        // Sprawdzamy czy nie tworzy sie cykl
        if (parent1 != parent2) {
            mst.push_back(edge);

            sumOfWeights += edge.weight;

            parent[parent1] = parent2;
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

