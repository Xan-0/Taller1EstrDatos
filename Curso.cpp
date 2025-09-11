#include "Curso.h"

Curso::Curso(int id, string nombre, int capacidad, string carrera,
        string profesor){
    this -> id = id;
    this -> nombre = nombre;
    this -> capacidad = capacidad;
    this -> carrera = carrera;
    this -> profesor = profesor;
    cant_alumnos = 0;
    next = nullptr;
}

void Curso::setId(int id){
    this -> id = id;
}

void Curso::setNombre(string nombre){
    this -> nombre = nombre;
}

void Curso::setCapacidad(int capacidad){
    this -> capacidad = capacidad;
}

void Curso::setCarrera(string carrera){
    this -> carrera = carrera;
}

void Curso::setProfesor(string profesor){
    this -> profesor = profesor;
}

void Curso::setCantAlumnos(int cant_alumnos){
    this -> cant_alumnos = cant_alumnos;
}

void Curso::setNext(Curso *next){
    this -> next = next;
}

void Curso::print(){
    if(this != nullptr){
        cout<<"__DATOS DEL CURSO__ "<< endl;
        cout<<"ID: ";
        cout<<this -> getId() << endl;
        cout<<"Nombre: ";
        cout<<this -> getNombre() << endl;
        cout<<"Capacidad: ";
        cout<<this -> getCapacidad() << endl;
        cout<<"Carrera: ";
        cout<<this -> getCarrera() << endl;
        cout<<"Profesor: ";
        cout<<this -> getProfesor() << endl;
        cout<<" " << endl;
    } else {
        cout<<"__CURSO INEXISTENTE__"<< endl;
    }
}

int Curso::getId(){
    return id;
}

string Curso::getNombre(){
    return nombre;
}

int Curso::getCapacidad(){
    return capacidad;
}

string Curso::getCarrera(){
    return carrera;
}

string Curso::getProfesor(){
    return profesor;
}

int Curso::getCantAlumnos(){
    return cant_alumnos;
}

Curso *Curso::getNext(){
    return next;
}

Curso::~Curso(){
    next = nullptr;
}
