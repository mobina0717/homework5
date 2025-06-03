#include "Nodenode.h"
#include <iostream>

Node::Node(int data, Node* next) : data(data), next(next) {}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* next) {
    this->next = next;
}

int& Node::getData() {
    return data;
}

const int& Node::getDataConst() const {
    return data;
}

Node& Node::operator--() {
    --data;
    return *this;
}

Node Node::operator--(int) {
    Node temp = *this;
    --data;
    return temp;
}

Node& Node::operator++() {
    ++data;
    return *this;
}

Node Node::operator++(int) {
    Node temp = *this;
    ++data;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Node& node) {
    os << node.data;
    return os;
}
