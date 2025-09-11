#include "Alumno.h"

Alumno::Alumno(int id, string nombre, string apellido,
        string carrera, string fechaIngreso){
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
    next = nullptr;
}

void Alumno::setId(int id){
    this -> id = id;
}

void Alumno::setNombre(string nombre){
    this -> nombre = nombre;
}

void Alumno::setApellido(string apellido){
    this -> apellido = apellido;
}

void Alumno::setCarrera(string carrera){
    this -> carrera = carrera;
}

void Alumno::setFecha(string fechaIngreso){
    this -> fechaIngreso = fechaIngreso;
}

void Alumno::setNext(Alumno *next){
    this -> next = next;
}

int Alumno::getId(){
    return id;
}

string Alumno::getNombre(){
    return nombre;
}

string Alumno::getApellido(){
    return apellido;
}

string Alumno::getCarrera(){
    return carrera;
}

string Alumno::getFecha(){
    return fechaIngreso;
}

Alumno *Alumno::getNext(){
    return next;
}

void Alumno::print(){
    if(this != nullptr){
        cout<<"__DATOS DEL ALUMNO__ "<< endl;
        cout<<"Id: ";
        cout<<this -> getId() << endl;
        cout<<"Nombre: ";
        cout<<this -> getNombre() << endl;
        cout<<"Apellido: ";
        cout<<this -> getApellido() << endl;
        cout<<"Carrera: ";
        cout<<this -> getCarrera() << endl;
        cout<<"Fecha de ingreso: ";
        cout<<this -> getFecha() << endl;
        cout<<" " << endl;
    } else {
        cout<<"__ALUMNO INEXISTENTE__"<< endl;
    }
}

Alumno::~Alumno(){
    next = nullptr;
}
