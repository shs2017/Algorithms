#include <gtest/gtest.h>

#include "encoding/encoding_table.h"

TEST(EncodingTable, encode_Success_Simple) {
  EncodingTable<char> t;
  t.setSymbolEncodingEntry('a', 1);
  EXPECT_EQ(t.encode('a'), 1);
}

TEST(EncodingTable, encode_Success_Complex) {
  EncodingTable<char> t;
  t.setSymbolEncodingEntry('a', 1);
  t.setSymbolEncodingEntry('b', 10);

  EXPECT_EQ(t.encode('a'), 1);
  EXPECT_EQ(t.encode('b'), 10);
}

TEST(EncodingTable, encode_Failure_SymbolDoesNotExist) {
  EncodingTable<char> t;
  EXPECT_THROW(t.encode('a'), std::runtime_error);
}

TEST(EncodingTable, decode_Success_Simple) {
  EncodingTable<char> t;
  t.setSymbolEncodingEntry('a', 1);
  EXPECT_EQ(t.decode(1), 'a');
}

TEST(EncodingTable, decode_Success_Complex) {
  EncodingTable<char> t;
  t.setSymbolEncodingEntry('a', 1);
  t.setSymbolEncodingEntry('b', 10);

  EXPECT_EQ(t.decode(1), 'a');
  EXPECT_EQ(t.decode(10), 'b');
}

TEST(EncodingTable, decode_Failure_SymbolDoesNotExist) {
  EncodingTable<char> t;
  EXPECT_THROW(t.decode(1), std::runtime_error);
}
