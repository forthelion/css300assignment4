#include "BigInteger.h"

BigInteger::BigInteger(char digits[]) {
    string s(digits);
    // always create postive 
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
// not finished 
BigInteger BigInteger::operator-(const BigInteger &other) {
    BigInteger newBigInt;
    BigInteger tempbigger;
    BigInteger tempsmall;
    
    bool shouldswap;
    newBigInt.dll.clear(); // remove list with zero
    tempbigger.dll.clear(); // remove list with zero
    tempsmall.dll.clear(); // remove list with zero
    
    //if(*this < other){ // this* is greater then
        //shouldswap = true; 
    //}
    if(shouldswap){
        tempbigger = *this;
        tempsmall = other;
    }
    else{
        tempbigger = other;
        tempsmall = *this;
    }

    int bigsizelength = tempbigger.dll.getLength();

    int smallsizelength = tempsmall.dll.getLength();


    // subtraction starts here 
    int carry = 0; 

    for (int i = 0; i < smallsizelength; i++){

        int sub = ((tempbigger.dll.getData()-'0')-(tempsmall.dll.getData()-'0'));

        if (sub < 0){
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        newBigInt.dll.insertFirst(sub + '0');



    }


    return newBigInt;
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
    BigInteger newBigInt;

    newBigInt.dll.clear(); // remove list with zero
    newBigInt.dll = other.dll; // the operator creates a copy of the list
    newBigInt.negative = other.negative;
    
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
    return negative;
}
