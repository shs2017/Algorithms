#include <unordered_set>
#include <vector>

#include "graph.h"
#include "node_id.h"

template<typename T>
class DFS {
  NodeId rootId;
  Graph<T> graph;

public:
  DFS(NodeId rootId, Graph<T>& graph);
  void traverseAsVector(std::vector<T>& v);
  void traverseAsVectorTailRecursion(NodeId nodeId, std::unordered_set<NodeId>& visited, std::vector<T>& v);
};


template<typename T>
DFS<T>::DFS(NodeId rootId, Graph<T>& graph) : rootId(rootId), graph(graph) {
}

template<typename T>
void DFS<T>::traverseAsVector(std::vector<T>& v) {
  std::unordered_set<NodeId> visited;
  traverseAsVectorTailRecursion(this->rootId, visited, v);
}

template<typename T>
void DFS<T>::traverseAsVectorTailRecursion(NodeId nodeId, std::unordered_set<NodeId>& visited, std::vector<T>& v) {
  if (visited.count(nodeId)) {
    return;
  }

  visited.insert(nodeId);

  auto node = this->graph.getNodeFromId(nodeId);
  v.push_back(node.getValue());

  auto children = this->graph.getChildren(nodeId);
  if (!children.size()) {
    return;
  }

  for (auto childId : children) {
    traverseAsVectorTailRecursion(childId, visited, v);
  }
}
