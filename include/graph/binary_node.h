#pragma once

template<typename T>
class BinaryNode {
  T value;
  BinaryNode<T>* leftNode;
  BinaryNode<T>* rightNode;

public:
  BinaryNode(T value);
  T getValue();
  void setValue(T value);

  void setLeft(BinaryNode<T>* leftNode);
  void setRight(BinaryNode<T>* rightNode);

  BinaryNode<T>* getLeft();
  BinaryNode<T>* getRight();
};

template<typename T>
BinaryNode<T>::BinaryNode(T value) : value(value) {
  this->leftNode = nullptr;
  this->rightNode = nullptr;
}

template<typename T>
T BinaryNode<T>::getValue() {
  return this->value;
}

template<typename T>
void BinaryNode<T>::setValue(T value) {
  this->value = value;
}

template<typename T>
void BinaryNode<T>::setLeft(BinaryNode<T>* leftNode) {
  this->leftNode = leftNode;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getLeft() {
  return this->leftNode;
}


template<typename T>
void BinaryNode<T>::setRight(BinaryNode<T>* rightNode) {
  this->rightNode = rightNode;
}

template<typename T>
BinaryNode<T>* BinaryNode<T>::getRight() {
  return this->rightNode;
}
