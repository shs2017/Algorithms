#include "word.h"
#include "encoding.h"
#include "node.h"
#include "huffman.h"

#include<iostream>
#include<vector>

using namespace std;

int main() {
     vector<Word> words;

     words.push_back(Word("Test 1", 0.1));
     words.push_back(Word("Test 2", 0.3));
     words.push_back(Word("Test 3", 0.6));

     cout << "*** Implementation of Huffman Encoding ***" << endl;
     cout << "INPUT:" << endl;
     for (auto& word : words) {
	  cout << "Word: " << word.getString() << ", ";
	  cout << "Probrability: " << word.getProbrability() << endl;
     }

     Huffman g;
     g.build(words).encode();

     cout << endl;
     cout << "OUTPUT:" << endl;
     for (auto& word : words) {
	  cout << "Word: " << word.getString() << ", ";
	  cout << "Encoding:";
	  g.getEncoding(word.getString()).print();
     }

     return 0;
}
