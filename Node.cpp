#include "Node.h"

Node::Node(double nota, int id_alumno, int id_curso) {
    this -> nota = nota;
    this -> id_alumno = id_alumno;
    this -> id_curso = id_curso;
    next = nullptr;
}

void Node::setNota(double nota){
    this -> nota = nota;
}

void Node::setAlumno(int id_alumno){
    this -> id_alumno = id_alumno;
}

void Node::setCurso(int id_curso){
    this -> id_curso = id_curso;
}

void Node::setNext(Node *next){
    this -> next = next;
}

double Node::getNota(){
    return nota;
}

int Node::getAlumno(){
    return id_alumno;
}

int Node::getCurso(){
    return id_curso;
}

Node *Node::getNext(){
    return next;
}

Node::~Node(){
    next = nullptr;
}
