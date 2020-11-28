#pragma once

#include "graph.h"
#include <queue>
#include <vector>
#include <map>

/*
class BFS {
    BFS(Graph graph)
    private:
        std::queue<int> q;
}
*/

Graph BFS(Graph graph);

void BFS(Graph & graph, Vertex v, std::map<Vertex, bool> & explored);