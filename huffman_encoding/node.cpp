#include "node.h"

#include<string>

Node::Node(std::string s, float p) : s(s), p(p) {
}

Node::Node(Word w) {
     this->s = w.getString();
     this->p = w.getProbrability();
}

void Node::setLeft(Node* n) {
     this->left = n;
}

void Node::setRight(Node* n) {
     this->right = n;
}

Node* Node::getLeft() {
     return this->left;
}

 
Node* Node::getRight() {
     return this->right;
}

float Node::getProbrability() {
     return this->p;
}

std::string Node::getString() const {
     return this->s;
}

Node& Node::operator=(const Node& n) {
     this->s = n.s;
     this->p = n.p;
     this->left = n.left;
     this->right = n.right;
     return *this;
}
 
bool Node::operator<(const Node& n) const {
     return this->p < n.p;
}
