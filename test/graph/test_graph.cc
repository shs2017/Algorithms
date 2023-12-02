#include <gtest/gtest.h>

#include "graph/graph.h"

// Create Edge Tests
TEST(Graph, createNode_Succeeds) {
  Graph<char> graph;

  EXPECT_FALSE(graph.hasNode(NodeId{0}));

  auto nodeId = graph.createNode(Node<char>('a'));

  EXPECT_TRUE(graph.hasNode(nodeId));
}

TEST(Graph, createEdge_Succeeds) {
  Graph<char> graph;

  EXPECT_FALSE(graph.hasEdge(NodeId{0}, NodeId{1}));

  auto fromId = graph.createNode(Node<char>('a'));
  auto toId = graph.createNode(Node<char>('b'));

  graph.createEdge(fromId, toId);

  EXPECT_TRUE(graph.hasEdge(fromId, toId));
}

TEST(Graph, createEdge_Fails_FromDoesNotExist) {
  Graph<char> graph;

  auto toId = graph.createNode(Node<char>('a'));
  EXPECT_THROW(graph.createEdge(NodeId{100}, toId), std::runtime_error);
}

TEST(Graph, createEdge_Fails_ToDoesNotExist) {
  Graph<char> graph;

  auto fromId = graph.createNode(Node<char>('a'));
  EXPECT_THROW(graph.createEdge(fromId, NodeId{100}), std::runtime_error);
}

TEST(Graph, createEdge_Fails_FromAndToDoesNotExist) {
  Graph<char> graph;
  EXPECT_THROW(graph.createEdge(NodeId{100}, NodeId{101}), std::runtime_error);
}

// Remove Edge Tests
TEST(Graph, removeEdge_Succeeds) {
  Graph<char> graph;

  auto fromId = graph.createNode(Node<char>('a'));
  auto toId = graph.createNode(Node<char>('b'));
  graph.createEdge(fromId, toId);

  EXPECT_TRUE(graph.hasEdge(fromId, toId));

  graph.removeEdge(fromId, toId);

  EXPECT_FALSE(graph.hasEdge(fromId, toId));
}

TEST(Graph, removeEdge_Fails_FromDoesNotExist) {
  Graph<char> graph;

  auto toId = graph.createNode(Node<char>('a'));
  EXPECT_THROW(graph.removeEdge(NodeId{100}, toId), std::runtime_error);
}

TEST(Graph, removeEdge_Fails_ToDoesNotExist) {
  Graph<char> graph;

  auto fromId = graph.createNode(Node<char>('a'));
  EXPECT_THROW(graph.removeEdge(fromId, NodeId{100}), std::runtime_error);
}

TEST(Graph, removeEdge_Fails_FromAndToDoesNotExist) {
  Graph<char> graph;
  EXPECT_THROW(graph.removeEdge(NodeId{100}, NodeId{101}), std::runtime_error);
}

TEST(Graph, removeEdge_Fails_EdgeDoesNotExist) {
  Graph<char> graph;
  EXPECT_THROW(graph.removeEdge(NodeId{100}, NodeId{101}), std::runtime_error);
}


// Get Children Test
TEST(Graph, getChildren_Succeeds) {
  Graph<char> graph;

  auto fromId = graph.createNode(Node<char>('a'));

  auto toId1 = graph.createNode(Node<char>('b'));
  auto toId2 = graph.createNode(Node<char>('b'));

  graph.createEdge(fromId, toId1);
  graph.createEdge(fromId, toId2);

  EXPECT_EQ(graph.getChildren(fromId).size(), 2);
}

// Get Node From Id Tests
TEST(Graph, getNodeFromId_Succeeds) {
  Graph<char> graph;

  auto nodeId = graph.createNode(Node<char>('a'));
  auto node = graph.getNodeFromId(nodeId);

  EXPECT_EQ(node.getValue(), 'a');
}

TEST(Graph, getNodeFromI_Fails_dNodeDoesNotExist) {
  Graph<char> graph;
  EXPECT_THROW(graph.getNodeFromId(NodeId{0}), std::runtime_error);
}
