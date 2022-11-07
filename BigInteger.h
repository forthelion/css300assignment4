#ifndef BIG_INTGERH
#define BIG_INTGERH

#include "DoublyLinkedList.h"
#include "Node.h"

class IllegalArgumentException : public ::exception {
  public:
    char *what() {
        return "IllegalArgumentException";
    }
};
class NosuchElementException : public ::exception {
  public:
    char *what() {
        return "NosuchElementException";
    }
};

class BigInteger {
  protected:
    DoublyLinkedList<int> dll;

  public:
    // might change in future
    BigInteger() : BigInteger("0"){};
    BigInteger(char digits[]);
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
