#include <gtest/gtest.h>

#include "graph/binary_node.h"


TEST(BinaryNode, getValue) {
  BinaryNode<int> node(3);
  EXPECT_EQ(3, node.getValue());
}

TEST(BinaryNode, setValue) {
  BinaryNode<int> node(3);
  node.setValue(4);
  EXPECT_EQ(4, node.getValue());
}

TEST(BinaryNode, getLeftNullByDefault) {
  BinaryNode<int> node(3);
  EXPECT_EQ(node.getLeft(), nullptr);
}

TEST(BinaryNode, getLeftAfterSettingValue) {
  BinaryNode<int> rootNode(3);
  BinaryNode<int> leftNode(2);
  rootNode.setLeft(&leftNode);

  EXPECT_EQ(rootNode.getLeft(), &leftNode);
}

TEST(BinaryNode, getRightNullByDefault) {
  BinaryNode<int> node(3);
  EXPECT_EQ(node.getRight(), nullptr);
}

TEST(BinaryNode, getRightAfterSettingValue) {
  BinaryNode<int> rootNode(3);
  BinaryNode<int> rightNode(2);
  rootNode.setRight(&rightNode);

  EXPECT_EQ(rootNode.getRight(), &rightNode);
}
