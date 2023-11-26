#pragma once

#include "binary_node.h"


template<typename T>
class PriorityBinaryNode {
  T value;
  PriorityBinaryNode<T>* leftNode;
  PriorityBinaryNode<T>* rightNode;

  int priority;

public:
  PriorityBinaryNode(T value, int priority);
  T getValue();
  int getPriority();

  void setValue(T value);

  void setLeft(PriorityBinaryNode<T>* leftNode);
  void setRight(PriorityBinaryNode<T>* rightNode);

  PriorityBinaryNode<T>* getLeft();
  PriorityBinaryNode<T>* getRight();


  template <typename U>
  friend bool operator<(const PriorityBinaryNode<U>& lhs, const PriorityBinaryNode<U>& rhs);
};

template<typename T>
PriorityBinaryNode<T>::PriorityBinaryNode(T value, int priority) {
  this->leftNode = nullptr;
  this->rightNode = nullptr;

  this->value = value;
  this->priority = priority;
}

template<typename T>
int PriorityBinaryNode<T>::getPriority() {
  return this->priority;
}

template<typename T>
bool operator<(const PriorityBinaryNode<T>& lhs,
	       const PriorityBinaryNode<T>& rhs) {
  return lhs.priority > rhs.priority;
}

template<typename T>
T PriorityBinaryNode<T>::getValue() {
  return this->value;
}

template<typename T>
void PriorityBinaryNode<T>::setValue(T value) {
  this->value = value;
}

template<typename T>
void PriorityBinaryNode<T>::setLeft(PriorityBinaryNode<T>* leftNode) {
  this->leftNode = leftNode;
}

template<typename T>
PriorityBinaryNode<T>* PriorityBinaryNode<T>::getLeft() {
  return this->leftNode;
}


template<typename T>
void PriorityBinaryNode<T>::setRight(PriorityBinaryNode<T>* rightNode) {
  this->rightNode = rightNode;
}

template<typename T>
PriorityBinaryNode<T>* PriorityBinaryNode<T>::getRight() {
  return this->rightNode;
}
