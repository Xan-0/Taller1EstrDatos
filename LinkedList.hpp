#pragma once
#include "Node.hpp"

class LinkedList {
    private:
        Node *start;
    public:
        LinkedList();
        /*void add(int value);*/
        void add(int value, int pos);
        void remove(int index);
        int get(int index);
        bool isEmpty();
	~LinkedList();
};