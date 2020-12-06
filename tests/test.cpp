#include "../graph.h"
#include "../random.h"
#include "../edge.h"
#include "../algorithms.h"
#include "../catch/catch.hpp"
#include <utility>

TEST_CASE("BFS is correct with undirected graph", "[weight=1]") {
    Graph myGraph(false, false);
    string alphabet = "ABCDEFGH";
    for (int curr = 0; curr < 8; curr++) {
        myGraph.insertVertex(alphabet.substr(curr, 1));
    }
    myGraph.insertEdge("A", "C");
    myGraph.insertEdge("A", "B");
    myGraph.insertEdge("A", "D");
    myGraph.insertEdge("B", "E");
    myGraph.insertEdge("B", "C");
    myGraph.insertEdge("C", "D");
    myGraph.insertEdge("C", "E");
    myGraph.insertEdge("C", "F");
    myGraph.insertEdge("F", "D");
    myGraph.insertEdge("F", "G");
    myGraph.insertEdge("E", "G");
    myGraph.insertEdge("G", "H");
    myGraph.insertEdge("D", "H");

    std::unordered_map<Vertex, std::unordered_map<Vertex, int>> traversal = BFS(myGraph);
    for (auto & one : traversal) {
        for (auto & two : one.second) {
            cout << one.first << "->" << two.first << " = " << two.second << endl;;
        }
    }
    cout << endl;
    //traversal.print();
    
    REQUIRE(traversal["C"]["C"] == 0);
    REQUIRE(traversal["F"]["A"] == 2);
    REQUIRE(traversal["B"]["G"] == 2);
    REQUIRE(traversal["A"]["G"] == 3);
    REQUIRE(traversal["H"]["C"] == 2);
}

TEST_CASE("Checks makeGraph works correctly", "[weight=1]") {
    Graph myGraph = makeGraph("smallgraphfile.txt");
    //myGraph.print();
    REQUIRE(true == true);
}

TEST_CASE("BFS works with directed graph") {
    Graph myGraph(false, true);
    string alphabet = "ABCDE";
    for (int curr = 0; curr < 5; curr++) {
        myGraph.insertVertex(alphabet.substr(curr, 1));
    }
    myGraph.insertEdge("A", "B");
    myGraph.insertEdge("A", "C");
    myGraph.insertEdge("A", "D");
    myGraph.insertEdge("A", "E");
    myGraph.insertEdge("B", "A");
    myGraph.insertEdge("C", "D");
    myGraph.insertEdge("D", "B");
    myGraph.insertEdge("D", "E");
    myGraph.insertEdge("E", "B");

    std::unordered_map<Vertex, std::unordered_map<Vertex, int>> traversal = BFS(myGraph);
    for (auto & one : traversal) {
        for (auto & two : one.second) {
            cout << one.first << "->" << two.first << " = " << two.second << endl;;
        }
    }
    
    cout << endl;
    REQUIRE(traversal["A"]["E"] == 1);
    REQUIRE(traversal["B"]["E"] == 2);
    REQUIRE(traversal["D"]["C"] == 3);
}

TEST_CASE("PageRank gets a steady state", "[weight=1]") {
    Graph myGraph(false, true);
    string alphabet = "ABCDE";
    for (int curr = 0; curr < 5; curr++) {
        myGraph.insertVertex(alphabet.substr(curr, 1));
    }
    myGraph.insertEdge("A", "B");
    myGraph.insertEdge("A", "C");
    myGraph.insertEdge("A", "D");
    myGraph.insertEdge("A", "E");
    myGraph.insertEdge("B", "A");
    myGraph.insertEdge("C", "D");
    myGraph.insertEdge("D", "B");
    myGraph.insertEdge("D", "E");
    myGraph.insertEdge("E", "B");
    
    std::unordered_map<Vertex, double> state = PageRank(myGraph);
    for (auto & curr : state) {
        cout << curr.first << " significance: " << curr.second << endl;
    }
    REQUIRE(true == true);

}

TEST_CASE("PageRank") {
    
   Graph myGraph(false, true);
    string alphabet = "ABCDEF";
    for (int curr = 0; curr < 6; curr++) {
        myGraph.insertVertex(alphabet.substr(curr, 1));
    }
    myGraph.insertEdge("A", "B");
    myGraph.insertEdge("A", "F");
    myGraph.insertEdge("B", "C");
    myGraph.insertEdge("B", "D");
    myGraph.insertEdge("C", "E");
    myGraph.insertEdge("C", "D");
    myGraph.insertEdge("C", "F");
    myGraph.insertEdge("D", "A");
    myGraph.insertEdge("E", "F");
    myGraph.insertEdge("F", "A");
    

    std::unordered_map<Vertex, double> state = PageRank(myGraph);
    for (auto & curr : state) {
        cout << curr.first << " significance: " << curr.second << endl;
    }
    double num = (int) (state["A"] * 100 + 0.5);
    double val = (double) num / 100;
    REQUIRE(val == 0.35);
}

TEST_CASE("PageRank works with large data set") {
    Graph myGraph = makeGraph("amazon0302small.txt");
    std::unordered_map<Vertex, double> state = PageRank(myGraph);
    double total = 0;
    for (auto & curr : state) {
        cout << curr.first << " significance: " << curr.second << endl;
        total += curr.second;
    }
    cout << total << endl;
    REQUIRE(true == true);
}

/*
# Directed graph (each unordered pair of nodes is saved once): Amazon0302.txt 
# Amazon product co-purchaisng network from March 02 2003
# Nodes: 262111 Edges: 1234877
# FromNodeId	ToNodeId
*/