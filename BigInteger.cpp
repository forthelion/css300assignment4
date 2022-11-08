#include "BigInteger.h"

// need to add tolerance for negative number
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

BigInteger BigInteger::operator=(BigInteger &other) {
    BigInteger newBigInt;
    newBigInt.dll.clear(); // remove list with zero
    newBigInt.dll = other.dll; // the operator creates a copy of the list
    // FIXME: add signal treatment
    return newBigInt;
};

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
    return true;
}; // tempory;

bool BigInteger::operator>(BigInteger &other) {
    // A longer number is always going to be bigger,
    // so check the length first.
    if (dll.getLength() > other.dll.getLength()) {
        return true;
    } else if (dll.getLength() < other.dll.getLength()) {
        return false;
    } else {
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
    }
}

bool BigInteger::operator<(BigInteger &other) {
    return true;
}; // tempory;

bool BigInteger::isNegative() {
    return true;
}; // tempory
