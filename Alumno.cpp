#include "Alumno.h"

Alumno::Alumno(int id, std::string nombre, std::string apellido,
        std::string carrera, std::string fechaIngreso){
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
    notas_start = nullptr;
    next = nullptr;
}

void Alumno::setId(int id){
    this -> id = id;
}

void Alumno::setNombre(std::string nombre){
    this -> nombre = nombre;
}

void Alumno::setApellido(std::string apellido){
    this -> apellido = apellido;
}

void Alumno::setCarrera(std::string carrera){
    this -> carrera = carrera;
}

void Alumno::setFecha(std::string fechaIngreso){
    this -> fechaIngreso = fechaIngreso;
}

void Alumno::add(double nota, std::string curso){
    Node *nuevo = new Node();
    
    if (notas_start == nullptr) {
        nuevo -> setNota(nota);
        nuevo -> setCurso(curso);
        nuevo -> setNext(nullptr);
        notas_start = nuevo;
        return;
    }
    
    Node *cursor = notas_start;
    while (cursor -> getNext() != nullptr){
        cursor = cursor -> getNext();
    }
    
    nuevo -> setNota(nota);
    nuevo -> setCurso(curso);
    nuevo -> setNext(nullptr);
    cursor -> setNext(nuevo);
    return;
}

void Alumno::remove(std::string curso){
    if (notas_start == nullptr){
        return;
    }
    
    Node *cursor = notas_start;
    Node *anterior = nullptr;
    Node *siguiente = nullptr;
    while (cursor != nullptr){
        
        if(cursor -> getCurso() == curso){
            siguiente = cursor -> getNext();
            cursor -> ~Node();
            cursor = siguiente;
            if (anterior != nullptr){
                anterior -> setNext(siguiente);
            } else {
                notas_start = siguiente;
                siguiente = nullptr;
                cursor = notas_start;
            }
        }
        
        anterior = cursor;
        if(cursor != nullptr){
            cursor = cursor -> getNext();
        }
    }
    return;
}

void Alumno::setNext(Alumno *next){
    this -> next = next;
}

void Alumno::print(){
    if(this != nullptr){
        std::cout<<"__DATOS DEL ALUMNO__ "<< std::endl;
        std::cout<<"ID: ";
        std::cout<<this -> getId() << std::endl;
        std::cout<<"Nombre: ";
        std::cout<<this -> getNombre() << std::endl;
        std::cout<<"Apellido: ";
        std::cout<<this -> getApellido() << std::endl;
        std::cout<<"Carrera: ";
        std::cout<<this -> getCarrera() << std::endl;
        std::cout<<"Fecha de ingreso: ";
        std::cout<<this -> getFecha() << std::endl;
        std::cout<<" " << std::endl;
    } else {
        std::cout<<"__ALUMNO INEXISTENTE__"<< std::endl;
    }
}

int Alumno::getId(){
    return id;
}

std::string Alumno::getNombre(){
    return nombre;
}

std::string Alumno::getApellido(){
    return apellido;
}

std::string Alumno::getCarrera(){
    return carrera;
}

std::string Alumno::getFecha(){
    return fechaIngreso;
}

Node *Alumno::getNotas(){
    return notas_start;
}

Alumno *Alumno::getNext(){
    return next;
}

Alumno::~Alumno(){
    if (notas_start != nullptr){
        Node *cursor = notas_start;
        Node *anterior = nullptr;
        while (cursor -> getNext() != nullptr){
            if(anterior != nullptr){
                anterior -> ~Node();
            }
            anterior = cursor;
            cursor = cursor -> getNext();
        }
        cursor -> ~Node();
    }
    delete notas_start;
    notas_start = nullptr;
    delete next;
    next = nullptr;
}
