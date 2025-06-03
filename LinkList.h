#ifndef LINKLIST_H
#define LINKLIST_H

#include "Nodenode.h"
//#include "Nodenode.cpp"
#include <iostream>

class LinkedList {
private:
    Node* head;
    Node* tail;
    int listSize;

public:
    LinkedList();

    LinkedList(const LinkedList& other);

    ~LinkedList();

    LinkedList& operator=(const LinkedList& other);

    LinkedList operator+(int value) const;
    LinkedList operator+(const LinkedList& other) const;
    friend LinkedList operator+(int value, const LinkedList& list); // برای حالت 3 + lk1

    LinkedList& operator++();

    LinkedList operator++(int);

    LinkedList& operator--();

    LinkedList operator--(int);

    int& operator[](int index);
    const int& operator[](int index) const;

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);

    bool operator==(const LinkedList& other) const;

    void appendNode(int data);

    Node* copyNodes(Node* otherHead) const;

        void clearList();

        int size() const;
    };
    
    #endif
    