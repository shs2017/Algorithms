#include <deque>
#include <unordered_set>
#include <vector>

#include "graph/graph.h"
#include "graph/node_id.h"

template<typename T>
class BFS {
  NodeId rootId;
  Graph<T> graph;

public:
  BFS(NodeId rootId, Graph<T>& graph);

  void traverseAsVector(std::vector<T>& v);
};

template<typename T>
BFS<T>::BFS(NodeId rootId, Graph<T>& graph) : rootId(rootId), graph(graph) {
}

template<typename T>
void BFS<T>::traverseAsVector(std::vector<T>& v) {
  std::deque<NodeId> d;
  std::unordered_set<NodeId> visited;

  d.push_back(this->rootId);

  while (!d.empty()) {
    auto nodeId = d.front();

    if (visited.count(nodeId)) {
      d.pop_front();
      continue;
    }

    visited.insert(nodeId);

    auto node = this->graph.getNodeFromId(nodeId);
    v.push_back(node.getValue());

    d.pop_front();

    auto children = this->graph.getChildren(nodeId);
    if (!children.size()) {
      continue;
    }

    for (auto childId : children) {
      d.push_back(childId);
    }
  }
}
