#ifndef WORD_H
#define WORD_H

#include<string>

class Word {
     std::pair<std::string, float> word;

public:
     Word(std::string s, float p);

     float getProbrability();
     std::string getString();

     bool operator<(Word w) const;
};

#endif
