#include "Curso.h"
#pragma once

class Universidad {
    private:
        string nombre;
    public:
        Node *notas_start;
        Alumno *alumnos_start;
        Curso *cursos_start;
        Universidad(string nombre);
        
        void setNombre(string nombre);
        string getNombre();
        Node *getNota(int id_alumno, int id_curso);
        Alumno *getAlumno(int id);
        Curso *getCurso(int id);
        
        void addNota(Node *nuevo);
        void addAlumno(Alumno *alumno);
        void addCurso(Curso *curso);
        
        void removerNotas(int id_alumno, int id_curso);
        void removerAlumno(int id);
        void removerCurso(int id);
        
        void print_alumno(string nombre);
        void print_curso(string nombre);
        void print_alumnos(string carrera);
        void print_cursos(int id_alumno);
        double promedio(int id_alumno, int id_curso);
        double promedio_General(int id_alumno);
        
        ~Universidad();
};