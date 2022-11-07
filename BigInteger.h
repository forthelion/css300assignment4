#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include "DoublyLinkedList.h"
#include "Node.h"

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
    BigInteger() : BigInteger("0"){};// done
    BigInteger(char digits[]);// done
    BigInteger operator-(const BigInteger &other); // not done
    bool operator==(BigInteger &other);// done
    BigInteger operator=(const BigInteger &other);// not done
    BigInteger operator+(BigInteger &other); //not done
    bool operator>=(BigInteger &other); //not done
    bool operator<=(BigInteger &other); //not done
    bool operator>(BigInteger &other); //not done
    bool operator<(BigInteger &other); //not done
    bool isNegative(); //not done
};
#endif
