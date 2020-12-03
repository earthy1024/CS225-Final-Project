#include "algorithms.h"
#include <utility>
#include <iostream>

Graph BFS(Graph graph) {
    std::vector<Vertex> vertices = graph.getVertices();
    std::vector<Edge> edges = graph.getEdges();
    
    std::unordered_map<Vertex, bool> vertexExplored;
    for (unsigned curr = 0; curr < vertices.size(); curr++) {
        vertexExplored.insert(std::make_pair(vertices[curr], false));
    }
    for (unsigned curr = 0; curr < edges.size(); curr++) {
        graph.setEdgeLabel(edges[curr].source, edges[curr].dest, "Unexplored");
    }
    vector<std::unordered_map<Vertex, bool>> distances;
    for (unsigned curr = 0; curr < vertices.size(); curr++) {
        if (!vertexExplored[vertices[curr]]) {
            
            BFS(graph, vertices[curr], vertexExplored);
        }
    }
    return graph;
}

void BFS(Graph & graph, Vertex v, std::unordered_map<Vertex, bool> & explored) {
    cout << v << endl;
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
                cout << w << endl;
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
    for (unsigned curr = 0; curr < out.size(); curr += 2) {
        Vertex source = out[curr];
        Vertex dest = out[curr+1];
        if (curr == out.size()-3) {
            dest = out[curr+2];
            curr += 2;
        }
        
        cout << source << endl;
        cout << dest << endl;
        if (!g.vertexExists(source)) {
            g.insertVertex(source);
        } else if (!g.vertexExists(dest)) {
            g.insertVertex(dest);
        }
        g.insertEdge(source, dest);
    }

    return g;
}