#pragma once

#include <optional>
#include <queue>
#include <unordered_map>
#include <vector>

#include <cassert>

#include "graph/graph.h"
#include "graph/node_id.h"

#include "encoding/encoding_table.h"

template<typename T>
class HuffmanEncoding {
  EncodingTable<T> encodingTable;

  std::unordered_map<T, int> buildSymbolCountsMap(std::vector<T> symbolStream);

  NodeId buildEncodingTree(Graph<std::optional<T>>& graph, std::unordered_map<T, int> unorderedCounts);
  std::priority_queue<std::pair<int, NodeId>> buildInitialQueue(Graph<std::optional<T>>& graph,
								std::unordered_map<T, int> unorderedCounts);

  void buildEncodingTable(Graph<std::optional<T>> graph, NodeId root);
  void buildEncodingTableHelper(Graph<std::optional<T>> graph, NodeId nodeId, int encoding);

public:
  HuffmanEncoding(std::vector<T> symbolStream);

  int encode(T symbol);
  T decode(int decode);
};


template<typename T>
HuffmanEncoding<T>::HuffmanEncoding(std::vector<T> symbolStream) {
  Graph<std::optional<T>> graph;

  auto unorderedCounts = this->buildSymbolCountsMap(symbolStream);

  auto rootNode = this->buildEncodingTree(graph, unorderedCounts);
  this->buildEncodingTable(graph, rootNode);
}

template<typename T>
std::unordered_map<T, int> HuffmanEncoding<T>::buildSymbolCountsMap(std::vector<T> symbolStream) {
  std::unordered_map<T, int> unorderedCounts;

  for (auto symbol : symbolStream) {
    unorderedCounts[symbol]++;
  }

  return unorderedCounts;
}

template<typename T>
NodeId HuffmanEncoding<T>::buildEncodingTree(Graph<std::optional<T>>& graph,
					     std::unordered_map<T, int> unorderedCounts) {
  auto q = buildInitialQueue(graph, unorderedCounts);

  while (!q.empty()) {
    auto smallerCountNodePair = q.top();
    auto smallerCount = smallerCountNodePair.first;
    NodeId smallerNode = smallerCountNodePair.second;

    q.pop();

    if (q.empty()) {
      NodeId rootNode = smallerNode;
      return rootNode;
    }

    auto largerCountNodePair = q.top();
    auto largerCount = largerCountNodePair.first;
    NodeId largerNode = largerCountNodePair.second;
    q.pop();

    auto nodeId = graph.createNode(Node<std::optional<T>>(std::optional<T>{}));
    graph.createEdge(nodeId, smallerNode);
    graph.createEdge(nodeId, largerNode);

    q.push({smallerCount + largerCount, nodeId});
  }

  return NodeId{0};
}

template<typename T>
std::priority_queue<
  std::pair<int,NodeId>
  > HuffmanEncoding<T>::buildInitialQueue(Graph<std::optional<T>>& graph,
					  std::unordered_map<T, int> unorderedCounts) {
  std::priority_queue<std::pair<int, NodeId>> q;

  for (auto symbolCountPair : unorderedCounts) {
    auto symbol = symbolCountPair.first;
    auto counts = -1 * symbolCountPair.second; // -1 is to make it a min-heap

    auto nodeId = graph.createNode(Node<std::optional<T>>(std::optional<T>{symbol}));
    q.push({counts, nodeId});
  }

  return q;
}

template<typename T>
void HuffmanEncoding<T>::buildEncodingTable(Graph<std::optional<T>> graph, NodeId rootId) {
  this->buildEncodingTableHelper(graph, rootId, 0);
}

template<typename T>
void HuffmanEncoding<T>::buildEncodingTableHelper(Graph<std::optional<T>> graph,
						  NodeId nodeId,
						  int encoding) {
  auto node = graph.getNodeFromId(nodeId);

  if (node.getValue().has_value()) {
    auto symbol = node.getValue().value();
    this->encodingTable.setSymbolEncodingEntry(symbol, encoding);
  }

  auto children = graph.getChildren(nodeId);
  if (!children.size()) {
    return;
  }


  int count = 1;
  for (auto childId : children) {
    this->buildEncodingTableHelper(graph, childId, (encoding << 1) + count);

    assert(count >= 0); // should be a binary tree

    count--;
  }
}

template<typename T>
int HuffmanEncoding<T>::encode(T symbol) {
  return this->encodingTable.encode(symbol);
}

template<typename T>
T HuffmanEncoding<T>::decode(int encoding) {
  return this->encodingTable.decode(encoding);
}

