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

Graph BFS(Graph graph);

void BFS(Graph & graph, Vertex v, std::unordered_map<Vertex, bool> & explored);

Graph makeGraph(std::string filename);