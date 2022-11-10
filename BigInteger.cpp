#include <iostream>
#include <string>

#include "BigInteger.h"

BigInteger::BigInteger(const std::string &s) {
    negative = false;

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
// yet to be tested  need greater then or less 
BigInteger BigInteger::operator-( BigInteger &other) {
const int BigInteger::getLength() {
    return dll.getLength();
}
    BigInteger newBigInt;
    BigInteger tempbigger;
    BigInteger tempsmall;
    
    bool shouldswap = false;
    newBigInt.dll.clear(); // remove list with zero
    tempbigger.dll.clear(); // remove list with zero
    tempsmall.dll.clear(); // remove list with zero
    
    // uncommented this if you want to use the method 
    if(*this < other){ // this* is greater then
        shouldswap = true;
        newBigInt.negative = true; 
    }

    if(shouldswap){
        tempbigger = other;
        tempsmall = *this;
    }
    else{
        tempbigger = *this;
        tempsmall = other;
    }

    int bigsizelength = tempbigger.dll.getLength();
    int smallsizelength = tempsmall.dll.getLength();


    // subtraction starts here 
    int carry = 0;
    
    // loops through all smaller one 
    tempbigger.dll.setIteratorLast();
    tempsmall.dll.setIteratorLast();
    for (int i = 0; i < smallsizelength; i++){
        // minus here 
        int sub = tempbigger.dll.getData() - tempsmall.dll.getData() - carry;
        // check if answer is negative  and does the math
        if (sub < 0){
            sub = sub + 10;
            carry = 1;
        }
        // if answers is postive  
        else{
            carry = 0;
        } 
        newBigInt.dll.insertFirst(sub);
        tempbigger.dll.prev();
        tempsmall.dll.prev();
    }

    // for ( int i = smallsizelength; i < bigsizelength; i++){
    //     int sub = ((tempbigger.dll.getData()-'0')-carry);

    //     if(sub<0){
    //         sub = sub + 10;
    //         carry = 1;
    //     }
    //     else{
    //         carry = 0;
    //     }
    //     newBigInt.dll.insertLast(sub + '0');
    // }

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
    dll.clear(); // remove list with zero
    dll = other.dll; // the operator creates a copy of the list
    negative = other.negative;
    
    return *this;
}

BigInteger BigInteger::operator+(BigInteger &other) {
    BigInteger newBigInt;

    int bigsizelength = dll.getLength();

    int smallsizelength = other.dll.getLength();

    int tempbigger; //temp to get rid of later 


    int carry = 0;

    for (int i = 0; i < smallsizelength; i++){
        // minus here 
        int carrycheck = ((dll.getData()-'0')+(other.dll.getData()-'0'));
        // check if answer is more then 9
        if (carrycheck > 9){
            carrycheck = (carrycheck-10);// to make if it 12 it will only push 2 
            carry = 1;
        }
        // if answers is postive  
        else{
            carry = 0;
        } 
        newBigInt.dll.insertLast(carrycheck + '0');
    }
    return newBigInt;
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
}

std::ostream &operator<<(std::ostream &out, BigInteger &big) {
    out << big.dll;
    return out;
}

std::istream &operator>>(std::istream &in, BigInteger &big) {
    std::string input;

    in >> input;

    BigInteger newBigInt(input);

    big = newBigInt;

    return in;
}
