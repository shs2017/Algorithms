#include <gtest/gtest.h>

#include "graph/dfs.h"
#include "graph/binary_node.h"

TEST(DFSTest, simple) {
  BinaryNode<int> rootNode(3);
  BinaryNode<int> leftNode(2);
  BinaryNode<int> rightNode(5);

  rootNode.setLeft(&leftNode);
  rootNode.setRight(&rightNode);

  std::vector<int> actualVector;

  DFS<int> dfs = DFS<int>(rootNode);
  dfs.traverseAsVector(actualVector);

  std::vector<int> expectedVector{3, 2, 5};

  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}

TEST(DFSTest, complex) {
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

  DFS<int> dfs = DFS<int>(node1);
  dfs.traverseAsVector(actualVector);

  std::vector<int> expectedVector{1, 2, 3, 4, 5, 6};

  EXPECT_EQ(actualVector.size(), expectedVector.size());

  for (int i = 0; i < actualVector.size(); i++) {
    EXPECT_EQ(actualVector[i], expectedVector[i]);
  }
}
