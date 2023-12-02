#include <gtest/gtest.h>

#include "encoding/huffman_encoding.h"

TEST(HuffmanEncoding, encode_Success_Simple) {
  std::vector<char> symbolStream{'a', 'a', 'a', 'a', 'b', 'b'};

  HuffmanEncoding<char> huffman(symbolStream);
  ASSERT_EQ(huffman.encode('a'), 0);
  ASSERT_EQ(huffman.encode('b'), 1);
}

TEST(HuffmanEncoding, encode_Success_Complex) {
  std::vector<char> symbolStream{'a', 'b', 'c', 'a', 'b', 'a'};

  HuffmanEncoding<char> huffman(symbolStream);
  ASSERT_EQ(huffman.encode('a'), 0);
  ASSERT_EQ(huffman.encode('b'), 2);
  ASSERT_EQ(huffman.encode('c'), 3);
}

TEST(HuffmanEncoding, decode_Success_Simple) {
  std::vector<char> symbolStream{'a', 'a', 'a', 'a', 'b', 'b'};

  HuffmanEncoding<char> huffman(symbolStream);
  ASSERT_EQ(huffman.decode(0), 'a');
  ASSERT_EQ(huffman.decode(1), 'b');
}

TEST(HuffmanEncoding, decode_Success_Complex) {
  std::vector<char> symbolStream{'a', 'b', 'c', 'a', 'b', 'a'};

  HuffmanEncoding<char> huffman(symbolStream);
  ASSERT_EQ(huffman.decode(0), 'a');
  ASSERT_EQ(huffman.decode(2), 'b');
  ASSERT_EQ(huffman.decode(3), 'c');
}
