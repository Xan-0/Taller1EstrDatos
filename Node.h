#include <iostream>
#pragma once

class Node {
    private:
        double nota;
        std::string curso;
        Node *next;
    public:
        Node();
        void setNota(double nota);
        void setCurso(std::string curso);
        void setNext(Node *next);
        double getNota();
        std::string getCurso();
        Node *getNext();
        ~Node();
};


