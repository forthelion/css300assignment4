#ifndef BIG_INTGERH
#define BIG_INTGERH

#include "DoublyLinkedList.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class IllegalArgumentException: public::exception{
  public:
    char * what(){
        return "IllegalArgumentException";
    }
};
class NosuchElementException: public::exception{
  public:
    char * what(){
        return "NosuchElementException";
    }
};

class BigInteger {
  protected:
    DoublyLinkedList<int> dll;
  public:
    // might change in future
    BigInteger() : BigInteger("0") {};

    BigInteger(char digits[]){
        string s(digits);

        // validate all digits before any allocation
        for (int i = 0; i < s.size(); i++){
            if (!isdigit(s.at(i))) {
                throw new IllegalArgumentException();
            }
        }

        // insert digits on the list
        for (int i = 0; i < s.size(); i++){
            int digit = s.at(i) - '0';
            dll.insertFirst(digit);
        }


    }; 

    
    BigInteger operator-(const BigInteger &other) {
        return *this;
    }; // tempory
    // yet to be tested 
    bool operator==(BigInteger &other) {
       if (dll.getLength() != other.dll.getLength()) {
            return false;
        }

        dll.setIteratorFirst();
        other.dll.setIteratorFirst();
        while (!dll.isIteratorNULL()) {
            if (dll.getData() != other.dll.getData()) {
                return false;
            }
            dll.next();
            other.dll.next();
        }
        return true;


    }; // tempory

    // copy assignment operator
    BigInteger operator=(const BigInteger &other) {
        return *this;
    }; // tempory

    BigInteger operator+(BigInteger &other) {
        return *this;
    }; // tempory

    bool operator>=(BigInteger &other) {
        return true;
    }; // tempory;

    bool operator<=(BigInteger &other) {
        return true;
    }; // tempory;

    bool operator>(BigInteger &other) {
        return true;
    }; // tempory;

    bool operator<(BigInteger &other) {
        return true;
    }; // tempory;

    bool isNegative() {
        return true;
    }; // tempory


};
#endif
