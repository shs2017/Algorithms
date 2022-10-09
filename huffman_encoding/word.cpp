#include "word.h"

#include<string>

Word::Word(std::string s, float p) {
  word.first = s;
  word.second = p;
}

std::string Word::getString() {
  return this->word.first;
}

float Word::getProbrability() {
  return this->word.second;
}

// Greater means lower probrability
bool Word::operator<(Word w) const {
  return this->word.second > w.word.second;
}
