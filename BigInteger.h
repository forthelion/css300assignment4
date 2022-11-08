#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class IllegalArgumentException : public exception {
  public:
    const char *what() {
        return "IllegalArgumentException";
    }
};
class NosuchElementException : public ::exception {
  public:
    const char *what() {
        return "NosuchElementException";
    }
};

class BigInteger {
  protected:
    DoublyLinkedList<int> dll;

  public:
    // might change in future
    BigInteger() : BigInteger("0"){};
    BigInteger(const string &);
    BigInteger operator-(const BigInteger &other);
    // yet to be tested
    bool operator==(BigInteger &other);
    // copy assignment operator
    BigInteger operator=(const BigInteger &other);
    BigInteger operator+(BigInteger &other);
    bool operator>=(BigInteger &other);
    bool operator<=(BigInteger &other);
    bool operator>(BigInteger &other);
    bool operator<(BigInteger &other);
    bool isNegative();
};
#endif
