#include "Node.hpp"

Node::Node(){
    value = 0;
    next = nullptr;
}

void Node::setValue(int value){
    this -> value = value;
}

void Node::setNext(Node *next){
    this -> next = next;
}

Node::~Node(){
    delete &value;
    next = nullptr;
    delete next;
}

int Node::getValue(){
    return value;
}

Node *Node::getNext(){
    return next;
}