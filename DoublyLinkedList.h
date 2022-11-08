#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include "Node.h"
#include <iostream>
#include <string>

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
    ~DoublyLinkedList() {
        clear();
    }

    // copy constructor
    DoublyLinkedList(const DoublyLinkedList<T> &other) {
        init();

        Node<T> *cur = other.first;
        while (cur != nullptr) {
            insertLast(cur->data);
            cur = cur->next;
        }
    }

    // copy assignment operator
    DoublyLinkedList operator=(const DoublyLinkedList<T> &other) {
        clear();
        init();

        Node<T> *cur = other.first;
        while (cur != nullptr) {
            insertLast(cur->data);
            cur = cur->next;
        }

        return *this;
    }

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
    void deleteFirst() {
        if (first != nullptr) {

            Node<T> *temp = first->next;
            delete first;
            first = temp;
            if (first == nullptr) {
                last = nullptr;
            } else {
                first->prev = nullptr;
            }
            length--;
        }
    }

    // IGOR

    // deletes the last item in the list
    void deleteLast() {
        if (last != nullptr) {
            Node<T> *temp = last->prev; // theory prev is getting 3 and just
                                        // reassing it should be 2
            delete last; // delete not working for last one cant delete 3
            last = temp;
            if (last == nullptr) {
                first = nullptr;
            } else {
                last->next = nullptr;
            }
            length--;
        }
    }

    // destroys the list and makes it empty
    void clear() {
        Node<T> *victim;
        while (first != nullptr) {
            victim = first;
            first = first->next;
            delete victim;
        }
    }

    // iterator functions
    // sets the iterator to the beginning of the linked list
    void setIteratorFirst() {
        iterator = first;
    }

    // sets the iterator to the beginning of the linked list
    void setIteratorLast() {
        iterator = last;
    }

    // checks if the iterator has next
    bool hasNext() {
        return !isIteratorNULL() && iterator->next != nullptr;
    }

    // checks if the iterator has prev
    bool hasPrev() {
        return !isIteratorNULL() && iterator->prev != nullptr;
    }

    // sets the iterator to the next node
    void next() {
        iterator = iterator->next;
    }

    // sets the iterator to the previous node
    void prev() {
        iterator = iterator->prev;
    }

    // returns true if the iterator is null
    bool isIteratorNULL() {
        return iterator == nullptr;
    }

    // gets the data the iterator pointing at
    T getData() {
        return iterator->data;
    }

    // friend functions
    // overloading operator<<
    template <class U>
    friend std::ostream &operator<<(std::ostream &out, DoublyLinkedList<U> &list) {
        list.setIteratorFirst();
        while (!list.isIteratorNULL()) {
            out << list.getData();
            list.next();
        }
        return out;
    }

    // overloading operator>>
    template <class U>
    friend std::istream &operator>>(std::istream &in, DoublyLinkedList<U> &list) {
        return in;
    }
};

#endif
