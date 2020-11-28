#include "algorithms.h"
#include <utility>

Graph BFS(Graph graph) {
    std::vector<Vertex> vertices = graph.getVertices();
    std::vector<Edge> edges = graph.getEdges();
    
    std::map<Vertex, bool> vertexExplored;
    for (unsigned curr = 0; curr < vertices.size(); curr++) {
        vertexExplored.insert(std::make_pair(vertices[curr], false));
    }
    for (unsigned curr = 0; curr < edges.size(); curr++) {
        graph.setEdgeLabel(edges[curr].source, edges[curr].dest, "Unexplored");
    }
    for (unsigned curr = 0; curr < vertices.size(); curr++) {
        if (!vertexExplored[vertices[curr]]) {
            BFS(graph, vertices[curr], vertexExplored);
        }
    }
    return graph;
}

void BFS(Graph & graph, Vertex v, std::map<Vertex, bool> & explored) {
    explored[v] = true;
    std::queue<Vertex> q;
    q.push(v);
    
    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (Vertex w : graph.getAdjacent(v)) {
            if (!explored[w]) {
                graph.setEdgeLabel(v, w, "Discovery");
                explored[w] = true;
                q.push(w);
            } else if (graph.getEdgeLabel(v, w) == "Unexplored") {
                graph.setEdgeLabel(v, w, "Cross");
            }
        }
    }
}
