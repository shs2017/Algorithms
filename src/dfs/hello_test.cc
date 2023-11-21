#include <gtest/gtest.h>

template<typename T>
class BinaryNode {
  T value;
  BinaryNode<T>* leftNode;
  BinaryNode<T>* rightNode;

public:
  BinaryNode(T value) : value(value) {
    this->leftNode = nullptr;
    this->rightNode = nullptr;
  }

  T getValue() {
    return this->value;
  }

  void setLeft(BinaryNode<T>* leftNode) {
    this->leftNode = leftNode;
  }

  BinaryNode<T>* getLeft() {
    return this->leftNode;
  }


  void setRight(BinaryNode<T>* rightNode) {
    this->rightNode = rightNode;
  }

  BinaryNode<T>* getRight() {
    return this->rightNode;
  }
};


TEST(BinaryNode, getValue) {
  BinaryNode<int> node = BinaryNode<int>(3);
  EXPECT_EQ(3, node.getValue());
}

TEST(BinaryNode, getLeftNullByDefault) {
  BinaryNode<int> node = BinaryNode<int>(3);
  EXPECT_EQ(node.getLeft(), nullptr);
}

TEST(BinaryNode, getLeftAfterSettingValue) {
  BinaryNode<int> rootNode = BinaryNode<int>(3);
  BinaryNode<int> leftNode = BinaryNode<int>(2);
  rootNode.setLeft(&leftNode);

  EXPECT_EQ(rootNode.getLeft(), &leftNode);
}

TEST(BinaryNode, getRightNullByDefault) {
  BinaryNode<int> node = BinaryNode<int>(3);
  EXPECT_EQ(node.getRight(), nullptr);
}

TEST(BinaryNode, getRightAfterSettingValue) {
  BinaryNode<int> rootNode = BinaryNode<int>(3);
  BinaryNode<int> rightNode = BinaryNode<int>(2);
  rootNode.setRight(&rightNode);

  EXPECT_EQ(rootNode.getRight(), &rightNode);
}
