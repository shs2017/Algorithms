#include <gtest/gtest.h>

#include "graph/node.h"

TEST(Node, getValue_Succeeds) {
  Node<char> node('a');
  EXPECT_EQ(node.getValue(), 'a');
}
