#ifndef NODENODE_H
#define NODENODE_H

#include <iostream>

class Node {
    friend std::ostream& operator<<(std::ostream& os, const Node& node);
private:
    int data;
    Node* next;

public:
    Node(int data = 0, Node* next = nullptr);

    Node* getNext() const;

    void setNext(Node* next);

    int& getData();

    const int& getDataConst() const;

    Node& operator--();

    Node operator--(int);

    Node& operator++();

    Node operator++(int);


};

#endif
