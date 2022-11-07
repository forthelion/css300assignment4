#include "BigInteger.h"

BigInteger::BigInteger(char digits[]) {
    string s(digits);

    // validate all digits before any allocation
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s.at(i))) {
            throw new IllegalArgumentException();
        }
    }

    // insert digits on the list
    for (int i = 0; i < s.size(); i++) {
        int digit = s.at(i) - '0';
        dll.insertFirst(digit);
    }
}

BigInteger BigInteger::operator-(const BigInteger &other) {
    return *this;
}

bool BigInteger::operator==(BigInteger &other) {
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
}

BigInteger BigInteger::operator=(const BigInteger &other) {
    return *this;
}; // tempory

BigInteger BigInteger::operator+(BigInteger &other) {
    return *this;
}; // tempory

bool BigInteger::operator>=(BigInteger &other) {
    return true;
}; // tempory;

bool BigInteger::operator<=(BigInteger &other) {
    return true;
}; // tempory;

bool BigInteger::operator>(BigInteger &other) {
    return true;
}; // tempory;

bool BigInteger::operator<(BigInteger &other) {
    return true;
}; // tempory;

bool BigInteger::isNegative() {
    return true;
}; // tempory
