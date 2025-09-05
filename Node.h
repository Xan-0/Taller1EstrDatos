#include <iostream>
#pragma once

class Node {
    private:
        int nota;
        std::string curso;
        Node *next;
    public:
        Node();
        void setNota(int nota);
        void setCurso(std::string curso);
        void setNext(Node *next);
        int getNota();
        std::string getCurso();
        Node *getNext();
        ~Node();
};
