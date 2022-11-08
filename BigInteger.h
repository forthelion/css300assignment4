#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>

class IllegalArgumentException : public std::exception {
  public:
    const char *what() {
        return "IllegalArgumentException";
    }
};
class NosuchElementException : public std::exception {
  public:
    const char *what() {
        return "NosuchElementException";
    }
};

class BigInteger {
  protected:
    DoublyLinkedList<int> dll;
    bool negative;

  public:
    // might change in future
    BigInteger() : BigInteger("0"){};
    BigInteger(const std::string &);
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

    friend std::ostream &operator<<(std::ostream &output, BigInteger &str);
};
#endif
