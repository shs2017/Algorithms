#pragma once

#include <limits>
#include <list>
#include <set>
#include <unordered_map>

#include "graph/node.h"
#include "graph/node_id.h"

/**
 * Implementation of a graph data structure
 *
 * Note: this is currently not thread-safe
 */
template<typename T>
class Graph {
  std::unordered_map<NodeId, Node<T>> nodes;

  std::unordered_map<NodeId, std::list<NodeId>> adjacencyList;

  NodeId currentNodeId;
  NodeId createNewNodeId();

public:
  Graph();

  bool hasNode(NodeId nodeId);
  NodeId createNode(Node<T> node);
  Node<T> getNodeFromId(NodeId nodeId);

  bool hasEdge(NodeId fromId, NodeId toId);
  void createEdge(NodeId fromId, NodeId toId);
  void removeEdge(NodeId fromId, NodeId toId);

  std::list<NodeId> getChildren(NodeId nodeId);
};

template<typename T>
Graph<T>::Graph() {
  this->currentNodeId = 0;
}

template<typename T>
bool Graph<T>::hasNode(NodeId nodeId) {
  return this->nodes.count(nodeId);
}

template<typename T>
NodeId Graph<T>::createNode(Node<T> node) {
  auto nodeId = createNewNodeId();
  this->nodes.insert({nodeId, node});

  this->currentNodeId = currentNodeId;

  return nodeId;
}

template<typename T>
Node<T> Graph<T>::getNodeFromId(NodeId nodeId) {
  if (!this->nodes.count(nodeId)) {
    throw std::runtime_error("One of the nodes provided does not exists");
  }

  return this->nodes.at(nodeId);
}

template<typename T>
bool Graph<T>::hasEdge(NodeId fromId, NodeId toId) {
  if (!this->hasNode(fromId) || !this->hasNode(toId)) {
    return false;
  }

  auto adjacentNodes = this->adjacencyList[fromId];
  return std::find(adjacentNodes.begin(), adjacentNodes.end(), toId) != adjacentNodes.end();
}

template<typename T>
void Graph<T>::createEdge(NodeId fromId, NodeId toId) {
  if (!this->hasNode(fromId) || !this->hasNode(toId)) {
    throw std::runtime_error("One of the nodes provided does not exists");
  }

  auto adjacentNodes = this->adjacencyList[fromId];
  auto it = std::find(adjacentNodes.begin(), adjacentNodes.end(), toId);
  if (it != adjacentNodes.end()) {
    return;
  }

  this->adjacencyList[fromId].push_back(toId);
}

template<typename T>
void Graph<T>::removeEdge(NodeId fromId, NodeId toId) {
  if (!nodes.count(fromId) || !nodes.count(toId)) {
    throw std::runtime_error("One of the nodes provided does not exists");
  }

  this->adjacencyList[fromId].remove(toId);
}

template<typename T>
std::list<NodeId> Graph<T>::getChildren(NodeId nodeId) {
  if (!this->nodes.count(nodeId)) {
    return std::list<NodeId>{};
  }
    
  return this->adjacencyList[nodeId];
}

template<typename T>
NodeId Graph<T>::createNewNodeId() {
  NodeId newNodeId = this->currentNodeId + 1;

  for (NodeId count = MIN_NODE_ID; count < MAX_NODE_ID; count++) {
    if (!this->nodes.count(newNodeId)) {
      return newNodeId;
    }

    newNodeId = (newNodeId == MAX_NODE_ID) ? 0 : newNodeId + 1;
  }

  throw "Maximum number of allowable nodes reached";
}
