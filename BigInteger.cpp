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
// yet to be tested  need greater then or less 
BigInteger BigInteger::operator-(const BigInteger &other) {
    BigInteger newBigInt;
    BigInteger tempbigger;
    BigInteger tempsmall;
    
    bool shouldswap;
    newBigInt.dll.clear(); // remove list with zero
    tempbigger.dll.clear(); // remove list with zero
    tempsmall.dll.clear(); // remove list with zero
    // uncommented this if you want to use the method 
    //if(*this < other){ // this* is greater then
      //  shouldswap = true; 
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
    // loops through all smaller one 
    for (int i = 0; i < smallsizelength; i++){
        // minus here 
        int sub = ((tempbigger.dll.getData()-'0')-(tempsmall.dll.getData()-'0'));
        // check if answer is negative  and does the math
        if (sub < 0){
            sub = sub + 10;
            carry = 1;
        }
        // if answers is postive  
        else{
            carry = 0;
        } 
        newBigInt.dll.insertLast(sub + '0');
    }

    for ( int i = smallsizelength; i < bigsizelength; i++){
        int sub = ((tempbigger.dll.getData()-'0')-carry);

        if(sub<0){
            sub = sub + 10;
            carry = 1;
        }
        else{
            carry = 0;
        }
        newBigInt.dll.insertLast(sub + '0');
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
    BigInteger newBigInt;

    int bigsizelength = dll.getLength();

    int smallsizelength = other.dll.getLength();

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

    for ( int i = smallsizelength; i < bigsizelength; i++){
        int carrycheck = ((tempbigger.dll.getData()-'0')+carry);

        if (carrycheck > 9){
            carrycheck = (carrycheck-10);// to make if it 12 it will only push 2 
            carry = 1;
        }
        else{
            carry = 0;
        }
         newBigInt.dll.insertLast(carrycheck + '0');
    }
       
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
