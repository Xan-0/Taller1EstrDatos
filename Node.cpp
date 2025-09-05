#include "Node.h"

Node::Node(){
    nota = 0;
    next = nullptr;
}

void Node::setNota(int nota){
    this -> nota = nota;
}

void Node::setCurso(std::string curso){
    this -> curso = curso;
}

void Node::setNext(Node *next){
    this -> next = next;
}

Node::~Node(){
    delete next;
    next = nullptr;
}

int Node::getNota(){
    return nota;
}

std::string Node::getCurso(){
    return curso;
}

Node *Node::getNext(){
    return next;
}
