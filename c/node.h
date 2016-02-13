#ifndef PRACTICE_NODE_H
#define PRACTICE_NODE_H


#include <iostream>

template<typename T> class Node {
    T payload;

    Node *next;

public:
    Node(T value) {
        payload = value;
        next = 0;
    }

    Node* getNext() {
        return next;
    }

    void link(Node * node) {
        next = node;
    }

    T getValue() {
        return payload;
    }
};


template<typename T> class LinkedList {

    Node<T> *head;

public:
    LinkedList() {
        head = 0;
    }

    ~LinkedList() {
        if (head != 0) {
            Node<T> *next, *curr;
            curr = head;
            do {
                next = curr->getNext();
                delete curr;
                curr = next;
            } while (curr);
        }
    }

    void addAtTail(T value) {
        if (head == 0) {
            head = new Node<T>(value);
        } else {
            Node<T> *tail = getTail();
            tail->link(new Node<T>(value));
        }
    }

    Node<T>* getTail() {
        if (head == 0) {
            return 0;
        }
        Node<T> *curr = head;
        while (curr->getNext()) {
            curr = curr->getNext();
        }
        return curr;
    }

    void print() {
        if (head == 0) {
            return;
        }
        Node<T> *curr = head;
        do {
            std::cout << curr->getValue() << std::endl;
            curr = curr->getNext();
        } while (curr);
    }

    void reverse() {
        if (head != 0) {
            Node<T> *curr = head;
            Node<T> *prev = 0;
            Node<T> *next;

            do {
                next = curr->getNext();
                curr->link(prev);
                prev = curr;
                curr = next;
            } while (curr);

            head = prev;
        }
    }
};


template<typename T> class BinaryTree {

    Node<T> *head;

public:
    BinaryTree() {
        head = 0;
    }

    ~BinaryTree() {
        if (head != 0) {
            Node<T> *next, *curr;
            curr = head;
            do {
                next = curr->getNext();
                delete curr;
                curr = next;
            } while (curr);
        }
    }

    void addAtTail(T value) {
        if (head == 0) {
            head = new Node<T>(value);
        } else {
            Node<T> *tail = getTail();
            tail->link(new Node<T>(value));
        }
    }

    Node<T>* getTail() {
        if (head == 0) {
            return 0;
        }
        Node<T> *curr = head;
        while (curr->getNext()) {
            curr = curr->getNext();
        }
        return curr;
    }

    void print() {
        if (head == 0) {
            return;
        }
        Node<T> *curr = head;
        do {
            std::cout << curr->getValue() << std::endl;
            curr = curr->getNext();
        } while (curr);
    }
};

#endif //PRACTICE_NODE_H
