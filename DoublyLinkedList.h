#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

template <class T> class DoublyLinkedList {

  protected:
    Node<T> *first;    // a pointer to the first of the linked list
    Node<T> *last;     // a pointer to the last node of the linked list
    Node<T> *iterator; // an internal iterator for the linked list object
    int length;        // number of items in the linked list

  public:
    // CASSIDY

    // default no-argument constructor
    DoublyLinkedList() {
        init();
    }

    // destructor
    ~DoublyLinkedList();

    // copy constructor
    DoublyLinkedList(const DoublyLinkedList<T> &);

    // copy assignment operator
    DoublyLinkedList operator=(const DoublyLinkedList<T> &);

    // initializes an empty list
    void init() {
        first = nullptr;
        last = nullptr;
        length = 0;
    }

    // returns true if the list is empty, false otherwise
    bool isEmpty() const {
        return length == 0;
    }

    // returns the number of items in the list
    int getLength() const {
        return length;
    }

    // inserts a new item to the beginning of the list
    void insertFirst(const T &item) {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;

        if (!isEmpty()) {
            first->prev = newNode;
            newNode->next = first;

            newNode->prev = nullptr;

            // New first node is the one just created
            first = newNode;
        } else { // List is empty
            newNode->next = nullptr;
            newNode->prev = nullptr;

            first = newNode;
            last = newNode;
        }

        length++;
    }

    // inserts a new item at the end of the list
    void insertLast(const T &item) {
        Node<T> *newNode = new Node<T>;
        newNode->data = item;

        if (!isEmpty()) {
            last->next = newNode;
            newNode->prev = last;

            newNode->next = nullptr;

            last = newNode;
        } else {
            newNode->next = nullptr;
            newNode->prev = nullptr;

            first = newNode;
            last = newNode;
        }

        length++;
    }

    // deletes the first item from the list
    void deleteFirst();

    // IGOR

    // deletes the last item in the list
    void deleteLast();

    // destroys the list and makes it empty
    void clear();

    // iterator functions
    // sets the iterator to the beginning of the linked list
    void setIteratorFirst();

    // sets the iterator to the beginning of the linked list
    void setIteratorLast();

    // checks if the iterator has next
    bool hasNext();

    // checks if the iterator has prev
    bool hasPrev();

    // sets the iterator to the next node
    void next();

    // sets the iterator to the previous node
    void prev();

    // returns true if the iterator is null
    bool isIteratorNULL();

    // gets the data the iterator pointing at
    T getData();

    // friend functions
    // overloading operator<<
    template <class U>
    friend ostream &operator<<(ostream &out, const DoublyLinkedList<U> &);

    // overloading operator>>
    template <class U>
    friend istream &operator>>(istream &in, DoublyLinkedList<U> &);
};

#endif
