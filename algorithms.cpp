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
    int a = 0;
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

Graph makeGraph(std::string filename) {
    std::ifstream text(filename);
    std::vector<std::string> out;

    if (text.is_open()) {
        std::istream_iterator<std::string> iter(text);
        while (!text.eof()) {
            out.push_back(*iter);
            ++iter;
        }
    }
    Graph g(false, true);
    for (unsigned curr = 4; curr < out.size(); curr++) {
        Vertex source = out[curr].substr(0, 1);
        Vertex dest = out[curr].substr(4, 1);
        if (!g.vertexExists(source)) {
            g.insertVertex(source);
        } else if (!g.vertexExists(dest)) {
            g.insertVertex(dest);
        }
        g.insertEdge(source, dest);
    }

    return g;
}