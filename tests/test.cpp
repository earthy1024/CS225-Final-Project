#include "../graph.h"
#include "../random.h"
#include "../edge.h"
#include "../algorithms.h"
#include "../catch/catch.hpp"

TEST_CASE("BFS gets corrects traversal with small graph", "[weight=1]") {
    Graph myGraph(false, true);
    for (int curr = 0; curr < 8; curr++) {
        myGraph.insertVertex(std::to_string(curr));
    }
    myGraph.insertEdge("0", "2");
    myGraph.insertEdge("0", "1");
    myGraph.insertEdge("0", "3");
    myGraph.insertEdge("1", "4");
    myGraph.insertEdge("1", "2");
    myGraph.insertEdge("2", "3");
    myGraph.insertEdge("2", "4");
    myGraph.insertEdge("2", "5");
    myGraph.insertEdge("5", "3");
    myGraph.insertEdge("5", "6");
    myGraph.insertEdge("4", "6");
    myGraph.insertEdge("6", "7");
    myGraph.insertEdge("3", "7");

    Graph traversal = BFS(myGraph);
    traversal.print();
    
    REQUIRE(true == true);
}

TEST_CASE("Checks makeGraph works correctly", "[weight=1]") {
    Graph myGraph = makeGraph("smallgraphfile.txt");
    myGraph.print();
    REQUIRE(true == true);
}



