#include <vector>
#include <deque>

#include "binary_node.h"

template<typename T>
class BFS {
  BinaryNode<T> root;

  void appendNonEmptyNode(std::deque<BinaryNode<T>>& d, BinaryNode<T>* node);

public:
  BFS(BinaryNode<T>& root);

  void traverseAsVector(std::vector<T>& v);
};


template<typename T>
BFS<T>::BFS(BinaryNode<T>& root): root(root) {
}

template<typename T>
void BFS<T>::traverseAsVector(std::vector<T>& v) {
  std::deque<BinaryNode<T>> d;
  d.push_back(this->root);

  while (!d.empty()) {
    BinaryNode<T> node = d.front();
    v.push_back(node.getValue());
    d.pop_front();

    this->appendNonEmptyNode(d, node.getLeft());
    this->appendNonEmptyNode(d, node.getRight());
  }
}

template<typename T>
void BFS<T>::appendNonEmptyNode(std::deque<BinaryNode<T>>& d, BinaryNode<T>* node) {
  if (node != nullptr) {
    d.push_back(*node);
  }
}
