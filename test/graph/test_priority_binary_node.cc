#include <gtest/gtest.h>

#include "graph/priority_binary_node.h"


TEST(PriorityBinaryNode, getValue) {
  PriorityBinaryNode<char> node('c', 2);
  EXPECT_EQ('c', node.getValue());
}

TEST(PriorityBinaryNode, setValue) {
  PriorityBinaryNode<char> node('c', 3);
  node.setValue(4);
  EXPECT_EQ(4, node.getValue());
}

TEST(PriorityBinaryNode, getLeftNullByDefault) {
  PriorityBinaryNode<char> node('c', 2);
  EXPECT_EQ(node.getLeft(), nullptr);
}

TEST(PriorityBinaryNode, getLeftAfterSettingValue) {
  PriorityBinaryNode<char> rootNode('a', 1);
  PriorityBinaryNode<char> leftNode('b', 0);
  rootNode.setLeft(&leftNode);

  EXPECT_EQ(rootNode.getLeft(), &leftNode);
}

TEST(PriorityBinaryNode, getRightNullByDefault) {
  PriorityBinaryNode<char> node('c', 2);
  EXPECT_EQ(node.getRight(), nullptr);
}

TEST(PriorityBinaryNode, getRightAfterSettingValue) {
  PriorityBinaryNode<char> rootNode('a', 1);
  PriorityBinaryNode<char> rightNode('b', 0);
  rootNode.setRight(&rightNode);

  EXPECT_EQ(rootNode.getRight(), &rightNode);
}

TEST(PriorityBinaryNode, getPriority) {
  PriorityBinaryNode<char> rootNode('a', 3);
  EXPECT_EQ(rootNode.getPriority(), 3);
}

TEST(PriorityBinaryNode, lessThan) {
  PriorityBinaryNode<char> nodeA('a', 1);
  PriorityBinaryNode<char> nodeB('a', 3);
  EXPECT_LT(nodeB, nodeA);
}
