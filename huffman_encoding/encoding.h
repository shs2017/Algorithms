#ifndef ENCODING_H
#define ENCODING_H

#include<vector>

class Encoding {
     std::vector<bool> encoding;

public:
     void addBit(bool b);
     void dropBit();
     void print();
};


#endif
