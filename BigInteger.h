#ifndef BIG_INTGERH
#define BIG_INTGERH

#include "Node.h"
#include "DoublyLinkedList.h"
#include <string>
#include <iostream>
using namespace std;


class BigInteger
{
    protected:
        Node<int> *first;      //a pointer to the first of the linked list
        Node<int> *last;       //a pointer to the last node of the linked list
        Node<int> *iterator;   //an internal iterator for the linked list object
        int length;            //number of items in the linked list
                    

    public:
        BigInteger(const char[]){};

        BigInteger(){};

        BigInteger operator-(const BigInteger& other){ return *this; };// tempory

        bool operator==(const BigInteger& other){ return true; };// tempory

        BigInteger operator=(const BigInteger& other){ return *this; };// tempory

        BigInteger operator+( BigInteger& other){ return *this; };// tempory

        bool operator>=( BigInteger& other){ return true; };// tempory;

       bool operator<=( BigInteger& other){ return true; };// tempory;

       bool operator>( BigInteger& other){ return true; };// tempory;

       bool operator<( BigInteger& other){ return true; };// tempory;

        bool isNegative(){ return true; };// tempory

        int getLength(){return 7;}; // tempory



};
#endif 


