#include <gtest/gtest.h>

#include <vector>

#include "graph/bfs.h"


TEST(BFSTest, simple) {
  BinaryNode<int> rootNode(3);
  BinaryNode<int> leftNode(2);
  BinaryNode<int> rightNode(5);

  rootNode.setLeft(&leftNode);
  rootNode.setRight(&rightNode);

  std::vector<int> actualVector;

  BFS<int> bfs = BFS<int>(rootNode);
  bfs.traverseAsVector(actualVector);

  std::vector<int> expectedVector{3, 2, 5};

  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}

TEST(BFSTest, complex) {
  //          n1
  //         / \
  //        /   \
  //       n2    n5
  //      / \    /
  //    n3  n4  n6
  BinaryNode<int> node1(1);
  BinaryNode<int> node2(2);
  BinaryNode<int> node3(3);
  BinaryNode<int> node4(4);
  BinaryNode<int> node5(5);
  BinaryNode<int> node6(6);

  node1.setLeft(&node2);
  node1.setRight(&node5);
  node2.setLeft(&node3);
  node2.setRight(&node4);
  node5.setLeft(&node6);

  std::vector<int> actualVector;

  BFS<int> bfs = BFS<int>(node1);
  bfs.traverseAsVector(actualVector);

  std::vector<int> expectedVector{1, 2, 5, 3, 4, 6};

  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}
