#include "huffman.h"

#include<string>
#include<queue>
#include<unordered_map>
#include<vector>

Huffman::Huffman() {}

void Huffman::setEncoding(Node* node, Encoding encoding) {
    if (node == NULL) {
	return;
    }

    std::string key = node->getString();

    if (encodingMap.find(key) != encodingMap.end()) {
	encodingMap[key] = encoding;
    }

    encoding.addBit(0);
    this->setEncoding(node->getLeft(), encoding);
    encoding.dropBit();

    encoding.addBit(1);
    this->setEncoding(node->getRight(), encoding);
    encoding.dropBit();
}

Huffman& Huffman::build(std::vector<Word> words) {
    for (auto& w : words) {
	q.push(w);
    }

    return *this;
}

Node* Huffman::encode() {
    if (q.empty()) {
	return NULL;
    }

    this->root = new Node(q.top());
    this->encodingMap.insert(encoding_pair(this->root->getString(), Encoding()));
    q.pop();

    while (!q.empty()) {
	auto currentWord = q.top();
	auto childNode = new Node(currentWord);
	this->encodingMap.insert(encoding_pair(childNode->getString(), Encoding()));

	auto parentNode = new Node("", childNode->getProbrability() + root->getProbrability());
	parentNode->setLeft(childNode);
	parentNode->setRight(root);
	root = parentNode;
	q.pop();
    }

    Encoding encoding;
    this->setEncoding(root, encoding);

    return NULL;
}


Node* Huffman::getRoot() {
    return this->root;
}

Encoding Huffman::getEncoding(std::string s) {
    if (this->encodingMap.find(s) == this->encodingMap.end()) {
	throw new std::invalid_argument("key does not exist");
    }

    return this->encodingMap[s];
}
