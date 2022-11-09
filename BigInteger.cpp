#include <iostream>
#include <string>

#include "BigInteger.h"

BigInteger::BigInteger(const std::string &s) {
    // validate all digits before any allocation
    for (int i = 0; i < s.size(); i++) {
        if (!isdigit(s.at(i))) {
            throw new IllegalArgumentException();
        }
    }

    // insert digits on the list
    for (int i = 0; i < s.size(); i++) {
        int digit = s.at(i) - '0';
        dll.insertLast(digit);
    }
}

int BigInteger::getLength() const {
    return dll.getLength();
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
    if (*this == other || *this > other) {
        return true;
    } else {
        return false;
    }
};

bool BigInteger::operator<=(BigInteger &other) {
    if (*this == other || *this < other) {
        return true;
    } else {
        return false;
    }
}; // tempory;

bool BigInteger::operator>(BigInteger &other) {
    // A longer number is always going to be bigger,
    // so check the length first.
    if (dll.getLength() > other.dll.getLength()) {
        return true;
    } else if (dll.getLength() < other.dll.getLength()) {
        return false;
    }

    dll.setIteratorFirst();
    other.dll.setIteratorFirst();

    while (!dll.isIteratorNULL()) {
        if (dll.getData() > other.dll.getData()) {
            return true;
        } else if (dll.getData() < other.dll.getData()) {
            return false;
        } else if (dll.getData() == other.dll.getData()) {
            dll.next();
            other.dll.next();
        }
    }

    // This should never be reached, but the compiler
    // complains if it isn't here ¯\_(ツ)_/¯
    return false;
}

bool BigInteger::operator<(BigInteger &other) {
    // If the numbers are equal, this will incorrectly return
    // true, because operator> will return false for equal numbers,
    // and this negates the result of operator>.
    if (*this == other) {
        return false;
    } else {
        return !(*this > other);
    }
}; // tempory;

bool BigInteger::isNegative() {
    return negative;
}; // tempory

std::ostream &operator<<(std::ostream &out, BigInteger &big) {
    out << big.dll;
    return out;
}

std::istream &operator>>(std::istream &in, BigInteger &big) {
    in >> big.dll;
    return in;
}
