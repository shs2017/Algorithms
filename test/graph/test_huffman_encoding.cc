#include <gtest/gtest.h>

#include "graph/huffman_encoding.h"

// #include <iostream>

TEST(HuffmanEncoding, simple) {
  std::vector<char> symbolStream{'a', 'b', 'c', 'a', 'b', 'a'};

  HuffmanEncoding<char> huffman(symbolStream);
  // std::cout << huffman.encode('a') << std::endl;
}
