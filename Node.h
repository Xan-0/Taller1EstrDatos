#pragma once

class Node {
    private:
        double nota;
        int id_alumno;
        int id_curso;
        Node *next;
    public:
        Node(double nota, int id_alumno, int id_curso);
        void setNota(double nota);
        void setAlumno(int id_alumno);
        void setCurso(int id_curso);
        void setNext(Node *next);
        double getNota();
        int getCurso();
        int getAlumno();
        Node *getNext();
        ~Node();
};
