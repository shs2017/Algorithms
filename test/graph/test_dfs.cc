#include <gtest/gtest.h>

#include <vector>

#include "graph/dfs.h"
#include "graph/graph.h"

TEST(DFS, traverseAsVector_Success_TwoEdges) {
  Graph<char> graph;

  auto fromId = graph.createNode(Node<char>('a'));

  auto toId1 = graph.createNode(Node<char>('b'));
  auto toId2 = graph.createNode(Node<char>('c'));

  graph.createEdge(fromId, toId1);
  graph.createEdge(fromId, toId2);

  std::vector<char> actualVector;
  auto dfs = DFS<char>(fromId, graph);
  dfs.traverseAsVector(actualVector);

  std::vector<int> expectedVector{'a', 'b', 'c'};

  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}

TEST(DFS, traverseAsVector_Success_MultipleLayers) {
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

  auto dfs = DFS<std::string>(n1, graph);
  dfs.traverseAsVector(actualVector);

  std::vector<std::string> expectedVector{"n1", "n2", "n3", "n4", "n5", "n6"};
  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}


TEST(DFS, traverseAsVector_Success_Cycles) {
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

  auto dfs = DFS<std::string>(n1, graph);
  dfs.traverseAsVector(actualVector);

  std::vector<std::string> expectedVector{"n1", "n2", "n3", "n4"};
  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}
