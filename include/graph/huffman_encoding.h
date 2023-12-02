#include <optional>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include "graph.h"
#include "node_id.h"

template<typename T>
class HuffmanEncoding {
  void buildEncodings(Graph<std::optional<T>> graph, NodeId root);
  void buildEncodingsHelper(Graph<std::optional<T>> graph, NodeId nodeId, std::string encoding);
public:
  HuffmanEncoding(std::vector<T> symbolStream);
};


template<typename T>
HuffmanEncoding<T>::HuffmanEncoding(std::vector<T> symbolStream) {
  std::unordered_map<T, int> unorderedCounts;
  for (auto symbol : symbolStream) {
    unorderedCounts[symbol]++;
  }

  Graph<std::optional<T>> graph;

  std::priority_queue<std::pair<int, NodeId>> q;
  for (auto symbolCountPair : unorderedCounts) {
    auto symbol = symbolCountPair.first;
    auto counts = -1 * symbolCountPair.second; // -1 is to make it a min-heap

    auto nodeId = graph.createNode(Node<std::optional<T>>(std::optional<T>{symbol}));
    q.push({counts, nodeId});
  }

  while (!q.empty()) {
    auto smallerCountNodePair = q.top();
    auto smallerCount = smallerCountNodePair.first;
    NodeId smallerNode = smallerCountNodePair.second;

    q.pop();

    if (q.empty()) {
      NodeId rootNode = smallerNode;
      this->buildEncodings(graph, rootNode);
      return;
    }

    auto largerCountNodePair = q.top();
    auto largerCount = largerCountNodePair.first;
    NodeId largerNode = largerCountNodePair.second;
    q.pop();

    auto nodeId = graph.createNode(Node<std::optional<T>>(std::optional<T>{}));
    graph.createEdge(nodeId, largerNode);
    graph.createEdge(nodeId, smallerNode);

    q.push({smallerCount + largerCount, nodeId});
  }
}

template<typename T>
void HuffmanEncoding<T>::buildEncodings(Graph<std::optional<T>> graph, NodeId rootId) {
  this->buildEncodingsHelper(graph, rootId, "");
}

template<typename T>
void HuffmanEncoding<T>::buildEncodingsHelper(Graph<std::optional<T>> graph, NodeId nodeId, std::string encoding) {
  auto node = graph.getNodeFromId(nodeId);

  if (node.getValue().has_value()) {
    std::cout << "Node " << node.getValue().value() << "'s encoding is " << encoding << std::endl;
  }

  auto children = graph.getChildren(nodeId);
  if (!children.size()) {
    return;
  }


  int count = 0;
  for (auto childId : children) {
    this->buildEncodingsHelper(graph, childId, encoding + std::to_string(count));
    count++;
  }
}

