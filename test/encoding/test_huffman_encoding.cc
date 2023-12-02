#include <gtest/gtest.h>

#include "encoding/huffman_encoding.h"

TEST(HuffmanEncoding, simple) {
  std::vector<char> symbolStream{'a', 'b', 'c', 'a', 'b', 'a'};

  HuffmanEncoding<char> huffman(symbolStream);
}
