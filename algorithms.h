#pragma once

#include "graph.h"
#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <string>


/*
class BFS {
    BFS(Graph graph)
    private:
        std::queue<int> q;
}
*/

std::unordered_map<Vertex, std::unordered_map<Vertex, int>> BFS(Graph graph);

void BFS(Graph & graph, Vertex v, std::unordered_map<Vertex, bool> & explored, std::unordered_map<Vertex, int> & dist);

Graph makeGraph(std::string filename);

std::unordered_map<Vertex, double> PageRank(Graph graph);

std::vector<std::vector<Vertex>> SCC(Graph graph);

Graph GraphTranspose(Graph graph);

void SCC_Helper(Graph & graph, Vertex v, std::unordered_map<Vertex, bool> & visited, std::vector<Vertex> & component);

