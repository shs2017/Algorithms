#ifndef NODE_H
#define NODE_H

#include "word.h"

#include<string>

class Node {
    std::string s;
    float p;

    Node* left;
    Node* right;

public:
    Node(std::string s, float p);
    Node(Word w);

    void setLeft(Node* n);
    void setRight(Node* n);

    Node* getLeft();
    Node* getRight();

    float getProbrability();
    std::string getString() const;

    Node& operator=(const Node& n);
    bool operator<(const Node& n) const;
};

#endif
