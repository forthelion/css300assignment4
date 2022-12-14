#include "BigInteger.h"
#include "DoublyLinkedList.h"
#include <fstream>
#include <iostream>

using namespace std;

int score = 0;

void grade(bool condition, int points) {
    if (condition) {
        cout << "Pass" << endl;
        score += points;
    } else {
        cout << "Fail" << endl;
    }
}

void dllTest() {
    DoublyLinkedList<int> list;
    grade(list.isEmpty() == true, 1);//1
    for (int i = 0; i < 10; i++) {
        list.insertFirst(i);
    }
    grade(list.getLength() == 10, 2);//2

    list.setIteratorFirst();
    grade(list.hasPrev() == false, 2);//3

    grade(list.getData() == 9, 1);//4

    list.next();
    grade(list.getData() == 8, 2);//5

    list.prev();
    grade(list.getData() == 9, 2);//6
    list.setIteratorLast();
    grade(list.hasNext() == false, 2);//7

    grade(list.getData() == 0, 1);//8

    list.insertFirst(10);
    list.setIteratorFirst();
    grade(list.getData() == 10, 1);//9

    list.insertLast(40);
    list.setIteratorLast();
    grade(list.getData() == 40, 1);//10

    list.deleteFirst();
    list.setIteratorFirst();
    grade(list.getData() == 9, 2);//11

    list.deleteLast();
    list.setIteratorLast();
    grade(list.getData() == 0, 2);//12

    list.clear();
    grade(list.getLength() == 0, 1);//13
}

void bigIntegerTest() {
    BigInteger int1("19"), int2("300");
    BigInteger actual2 = int1 - int2;
    BigInteger expected2("-281");
    grade(actual2 == expected2, 3);//14
    grade(actual2.isNegative() == true, 2);//15

    BigInteger bigInt1("55555556666666687888999");
    grade(bigInt1.getLength() == 23, 2);//16

    BigInteger bigInt2, bigInt3;
    ifstream file;
    file.open("test.txt");
    file >> bigInt2 >> bigInt3;// heres  glitch
    grade(bigInt2.getLength() == 23, 2);//17
    grade(bigInt3.getLength() == 24, 2);//18
    // bugs here
    BigInteger actual1 = bigInt2 + bigInt3;
    BigInteger expected1("234657681223242153555775");
    grade(actual1 == expected1, 2);//19
    BigInteger actual3 = bigInt2 - bigInt2;
    BigInteger expected3("0");
    grade(actual3 == expected3, 2);//20

    BigInteger actual4 = bigInt2 - bigInt3;
    BigInteger expected4("-123546567889908777777777");
    grade(actual4 == expected4, 2);//21

    grade(bigInt2 < bigInt3 == true, 1);//22

    grade(bigInt3 >= bigInt2 == true, 1);//23

    BigInteger bigInt4("12345678997654321"), bigInt5("12345678997654321");
    grade((bigInt4 <= bigInt5 == true), 1);//24
}

int main() {

    dllTest(); // test cases for doubly linked list implementation

    bigIntegerTest(); // test cases for big integer implementation

    cout << "Test Score:" << score << endl;

    return 0;
}
