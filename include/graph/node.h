#pragma once

/**
 * Implementation of a graph node
 */
template<typename T>
class Node {
  T value;

public:
  Node(T value) : value(value) {
  }

  T getValue() {
    return this->value;
  }
};
