#pragma once

#include <unordered_map>

template<typename T>
class EncodingTable {
  std::unordered_map<T, int> encoder;
  std::unordered_map<int, T> decoder;

public:
  void setSymbolEncodingEntry(T symbol, int encoding);

  int encode(T symbol);
  T decode(int encoding);
};

template<typename T>
void EncodingTable<T>::setSymbolEncodingEntry(T symbol, int encoding) {
  this->encoder[symbol] = encoding;
  this->decoder[encoding] = symbol;
}

template<typename T>
int EncodingTable<T>::encode(T symbol) {
  if (!this->encoder.count(symbol)) {
    throw std::runtime_error("Symbol does not exist in the encoding table");
  }

  return this->encoder[symbol];
}

template<typename T>
T EncodingTable<T>::decode(int encoding) {
  if (!this->decoder.count(encoding)) {
    throw std::runtime_error("Symbol does not exist in the encoding table");
  }

  return this->decoder[encoding];
}
