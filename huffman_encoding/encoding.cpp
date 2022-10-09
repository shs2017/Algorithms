#include "encoding.h"

#include<iostream>
#include<vector>

void Encoding::addBit(bool b) {
     encoding.push_back(b);
}

void Encoding::dropBit() {
     encoding.pop_back();
}

void Encoding::print() {
     for (auto bit : encoding) {
	  std::cout << bit;
     }

     std::cout << std::endl;
}
