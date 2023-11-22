#include <vector>

#include "binary_node.h"

template<typename T>
class DFS {
  BinaryNode<T> root;

public:
  DFS(BinaryNode<T>& root): root(root) {
  }

  void traverseAsVector(std::vector<T>& v) {
    traverseAsVectorTailRecursion(v, &this->root);
  }

  void traverseAsVectorTailRecursion(std::vector<T>& v, BinaryNode<T>* node) {
    if (node == nullptr) {
      return;
    }

    v.push_back(node->getValue());

    traverseAsVectorTailRecursion(v, node->getLeft());
    traverseAsVectorTailRecursion(v, node->getRight());
  }
};
