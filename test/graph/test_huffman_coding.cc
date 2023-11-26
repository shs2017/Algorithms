#include <gtest/gtest.h>

#include <vector>

#include "graph/huffman_coding.h"

TEST(HuffmanTest, Constructor) {
  std::vector<char> v{'H','e','l','l','o', 'w','o','r','l','d'};
  HuffmanCoding<char> h(v);
}

// TEST(HuffmanTest, MaxEncoding) {
//   std::vector<char> v{'H','e','l','l','o', 'w','o','r','l','d'};
//   HuffmanCoding<char> h(v);

//   int encoding = h.encode('l');
//   EXPECT_EQ(encoding, 0);
// }

// TEST(HuffmanTest, SeconLargestEncoding) {
//   std::vector<char> v{'H','e','l','l','o', 'w','o','r','l','d'};
//   HuffmanCoding<char> h(v);

//   int encoding = h.encode('o');
//   EXPECT_EQ(encoding, 0b10);
// }
