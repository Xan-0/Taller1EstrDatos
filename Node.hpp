#pragma once

class Node {
    private:
        int value;
        Node *next;
    public:
        Node();
        void setValue(int value);
        void setNext(Node *next);
        int getValue();
        Node *getNext();
        ~Node();
};