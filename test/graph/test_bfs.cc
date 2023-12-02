#include <gtest/gtest.h>

#include <vector>

#include "graph/bfs.h"
#include "graph/graph.h"

TEST(BFS, traverseAsVector_Success_TwoEdges) {
  Graph<char> graph;

  auto n1 = graph.createNode('a');
  auto n2 = graph.createNode('b');
  auto n3 = graph.createNode('c');

  graph.createEdge(n1, n2);
  graph.createEdge(n1, n3);

  std::vector<char> actualVector;

  BFS<char> bfs = BFS<char>(n1, graph);
  bfs.traverseAsVector(actualVector);

  std::vector<char> expectedVector{'a', 'b', 'c'};

  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}

TEST(BFS, traverseAsVector_Success_MultipleLayers) {
  //          n1
  //         / \
  //        /   \
  //       n2    n5
  //      / \    /
  //    n3  n4  n6

  Graph<std::string> graph;
  auto n1 = graph.createNode(std::string("n1"));
  auto n2 = graph.createNode(std::string("n2"));
  auto n3 = graph.createNode(std::string("n3"));
  auto n4 = graph.createNode(std::string("n4"));
  auto n5 = graph.createNode(std::string("n5"));
  auto n6 = graph.createNode(std::string("n6"));

  graph.createEdge(n1, n2);
  graph.createEdge(n1, n5);

  graph.createEdge(n2, n3);
  graph.createEdge(n2, n4);

  graph.createEdge(n5, n6);

  std::vector<std::string> actualVector;

  auto bfs = BFS<std::string>(n1, graph);
  bfs.traverseAsVector(actualVector);

  std::vector<std::string> expectedVector{"n1", "n2", "n5", "n3", "n4", "n6"};
  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}


TEST(BFS, traverseAsVector_Success_Cycles) {
  //          n1
  //         /
  //        /
  //       n2-\
  //      / \  |
  //      /  \ /
  //    n3   n4

  Graph<std::string> graph;
  auto n1 = graph.createNode(std::string("n1"));
  auto n2 = graph.createNode(std::string("n2"));
  auto n3 = graph.createNode(std::string("n3"));
  auto n4 = graph.createNode(std::string("n4"));

  graph.createEdge(n1, n2);

  graph.createEdge(n2, n3);
  graph.createEdge(n2, n4);

  graph.createEdge(n4, n2);

  std::vector<std::string> actualVector;

  auto bfs = BFS<std::string>(n1, graph);
  bfs.traverseAsVector(actualVector);

  std::vector<std::string> expectedVector{"n1", "n2", "n3", "n4"};
  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}
