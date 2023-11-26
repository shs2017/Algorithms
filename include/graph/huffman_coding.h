#pragma once

#include <optional>
#include <queue>
#include <unordered_map>
#include <vector>

#include <iostream>

#include "priority_binary_node.h"

template<typename T>
using CountMap = std::unordered_map<T, int>;

template<typename T>
using OptionalBinaryNode = PriorityBinaryNode<std::optional<T>>;

template<typename T>
using PriorityQueue = std::priority_queue<OptionalBinaryNode<T>*>;

template<typename T>
class HuffmanCoding {
  CountMap<T> computeCounts(std::vector<T> message);
  PriorityQueue<T> createQueueFromCounts(CountMap<T> counts);
  void deleteGraph(OptionalBinaryNode<T>* node);


  OptionalBinaryNode<T>* root;

public:
  HuffmanCoding(std::vector<T> v);
  ~HuffmanCoding();
};


template<typename T>
HuffmanCoding<T>::HuffmanCoding(std::vector<T> message) {
  auto counts = this->computeCounts(message);
  auto q = this->createQueueFromCounts(counts);

  while (!q.empty()) {
    auto leftNode = q.top();
    auto leftPriority = leftNode->getPriority();
    q.pop();

    if (q.empty()) {
      this->root = leftNode;
      break;
    }

    auto rightNode = q.top();
    auto rightPriority = rightNode->getPriority();
    q.pop();

    auto newPriority = leftPriority + rightPriority;
    auto newNode = new OptionalBinaryNode<T>({}, newPriority);
    newNode->setLeft(leftNode);
    newNode->setRight(rightNode);

    q.push(newNode);
  }
}

template<typename T>
HuffmanCoding<T>::~HuffmanCoding() {
  this->deleteGraph(this->root);
}

template<typename T>
void HuffmanCoding<T>::deleteGraph(OptionalBinaryNode<T>* node) {
  if (node != nullptr) {
    delete node;
    return;
  }

  deleteGraph(node->getLeft());
  deleteGraph(node->getRight());
}


template<typename T>
CountMap<T> HuffmanCoding<T>::computeCounts(std::vector<T> message) {
  std::unordered_map<T, int> counts;

  for (auto symbol: message) {
    counts[symbol]++;
  }

  return counts;
}

template<typename T>
PriorityQueue<T>  HuffmanCoding<T>::createQueueFromCounts(CountMap<T> counts) {
  PriorityQueue<T> q;

  for (auto symbolCountPair : counts) {
    auto symbol = std::optional<T>{symbolCountPair.first};
    auto value = symbolCountPair.second;

    auto node = new OptionalBinaryNode<T>(symbol, value);
    q.push(node);
  }

  return q;
}
