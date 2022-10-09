#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "encoding.h"
#include "node.h"
#include "word.h"

#include<string>
#include<queue>
#include<unordered_map>
#include<vector>

typedef std::pair<std::string, Encoding> encoding_pair;

class Huffman {
    Node* root;
    std::priority_queue<Word> q;
    std::unordered_map<std::string, Encoding> encodingMap;
    void setEncoding(Node* node, Encoding encoding);

public:
    Huffman();

    Huffman& build(std::vector<Word> words);
    Node* encode();

    Node* getRoot();
    Encoding getEncoding(std::string b);
};


#endif
