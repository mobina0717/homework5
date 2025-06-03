#include "LinkList.h"
#include <iostream>
#include <stdexcept>

LinkedList::LinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), listSize(0) {
    head = copyNodes(other.head);
    if (head == nullptr && other.head != nullptr) {
        listSize = 0;
    } else {
        listSize = other.listSize;
        if (listSize > 0) {
            Node* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            tail = current;
        } else {
            tail = nullptr;
        }
    }
}

LinkedList::~LinkedList() {
    clearList();
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this != &other) {
        clearList();
        head = copyNodes(other.head);
        if (head == nullptr && other.head != nullptr) {
            listSize = 0;
        } else {
            listSize = other.listSize;
            if (listSize > 0) {
                Node* current = head;
                while (current->getNext() != nullptr) {
                    current = current->getNext();
                }
                tail = current;
            } else {
                tail = nullptr;
            }
        }
    }
    return *this;
}

LinkedList LinkedList::operator+(int value) const {
    LinkedList newList = *this;
    newList.appendNode(value);
    return newList;
}

LinkedList LinkedList::operator+(const LinkedList& other) const {
    LinkedList newList = *this;
    Node* currentOther = other.head;
    while (currentOther != nullptr) {
        newList.appendNode(currentOther->getDataConst());
        currentOther = currentOther->getNext();
    }
    return newList;
}

LinkedList operator+(int value, const LinkedList& list) {
    LinkedList newList;
    newList.appendNode(value);
    Node* currentList = list.head;
    while (currentList != nullptr) {
        newList.appendNode(currentList->getDataConst());
        currentList = currentList->getNext();
    }
    return newList;
}

LinkedList& LinkedList::operator++() {
    Node* current = head;
    while (current != nullptr) {
        ++current->getData();
        current = current->getNext();
    }
    return *this;
}

LinkedList LinkedList::operator++(int) {
    LinkedList temp = *this;
    Node* current = head;
    while (current != nullptr) {
        current->getData()++;
        current = current->getNext();
    }
    return temp;
}

LinkedList& LinkedList::operator--() {
    Node* current = head;
    while (current != nullptr) {
        --current->getData();
        current = current->getNext();
    }
    return *this;
}

LinkedList LinkedList::operator--(int) {
    LinkedList temp = *this;
    Node* current = head;
    while (current != nullptr) {
        current->getData()--;
        current = current->getNext();
    }
    return temp;
}

int& LinkedList::operator[](int index) {
    if (index < 0 || index >= listSize) {
        std::cout << "not in range !" << std::endl;
        static int dummy = 0;
        return dummy;
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->getNext();
    }
    return current->getData();
}

const int& LinkedList::operator[](int index) const {
    if (index < 0 || index >= listSize) {
        std::cout << "not in range !" << std::endl;
        static const int dummy = 0;
        return dummy;
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->getNext();
    }
    return current->getDataConst();
}

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    Node* current = list.head;
    while (current != nullptr) {
        os << current->getDataConst();
        if (current->getNext() != nullptr) {
            os << " ";
        }
        current = current->getNext();
    }
    return os;
}

bool LinkedList::operator==(const LinkedList& other) const {
    if (listSize != other.listSize) {
        return false;
    }
    Node* currentThis = head;
    Node* currentOther = other.head;
    while (currentThis != nullptr) {
        if (currentThis->getDataConst() != currentOther->getDataConst()) {
            return false;
        }
        currentThis = currentThis->getNext();
        currentOther = currentOther->getNext();
    }
    return true;
}

void LinkedList::appendNode(int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        tail = newNode;
    }
    listSize++;
}

Node* LinkedList::copyNodes(Node* otherHead) const {
    if (otherHead == nullptr) {
        return nullptr;
    }
    Node* newHead = new Node(otherHead->getDataConst());
    Node* currentNew = newHead;
    Node* currentOther = otherHead->getNext();
    while (currentOther != nullptr) {
        Node* newNode = new Node(currentOther->getDataConst());
        currentNew->setNext(newNode);
        currentNew = newNode;
        currentOther = currentOther->getNext();
    }
    return newHead;
}

void LinkedList::clearList() {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    listSize = 0;
}

int LinkedList::size() const {
    return listSize;
}
