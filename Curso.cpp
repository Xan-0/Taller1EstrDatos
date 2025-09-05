#include "Curso.h"

Curso::Curso(int id, std::string nombre, int capacidad, std::string carrera,
        std::string profesor){
    this -> id = id;
    this -> nombre = nombre;
    this -> capacidad = capacidad;
    this -> carrera = carrera;
    this -> profesor = profesor;
    alumnos_start = nullptr;
    next = nullptr;
}

void Curso::setId(int id){
    this -> id = id;
}

void Curso::setNombre(std::string nombre){
    this -> nombre = nombre;
}

void Curso::setCapacidad(int capacidad){
    this -> capacidad = capacidad;
}

void Curso::setCarrera(std::string carrera){
    this -> carrera = carrera;
}

void Curso::setProfesor(std::string profesor){
    this -> profesor = profesor;
}

void Curso::setNext(Curso *next){
    this -> next = next;
}

void Curso::add(Alumno *alumno){
    if (alumno -> getCarrera() != this -> getCarrera()){
        return;
    }
    if (alumnos_start == nullptr) {
        alumnos_start = alumno;
        return;
    }
    
    Alumno *cursor = alumnos_start;
    while (cursor -> getNext() != nullptr){
        cursor = cursor -> getNext();
    }
    
    alumno -> add(0, nombre);
    cursor -> setNext(alumno);
    return;
}

void Curso::remove(int index){
    if (alumnos_start == nullptr){
        return;
    }
    
    int i = 0;
    Alumno *cursor = alumnos_start;
    Alumno *anterior = nullptr;
    while (cursor -> getNext() != nullptr){
        
        if(i == index){
            Alumno *siguiente = cursor -> getNext();
            cursor -> ~Alumno();
            
            if(anterior != nullptr){
                anterior -> setNext(siguiente);
                return;
            }
            alumnos_start = siguiente;
            return;
        }
        
        anterior = cursor;
        cursor = cursor -> getNext();
        i++;
    }
    
    if(index == 0){
        cursor -> ~Alumno();
    }
    return;
}

Alumno *Curso::get(int id){
    if (alumnos_start == nullptr){
        return nullptr;
    }
    
    Alumno *cursor = alumnos_start;
    while (cursor -> getNext() != nullptr){
        if(id == cursor -> getId()){
            return cursor;
        }
        cursor = cursor -> getNext();
    }
    if(id == cursor -> getId()){
            return cursor;
    }
    return nullptr;
}

bool Curso::isEmpty(){
    if (alumnos_start == nullptr){
        return true;
    }
    return false;
}

int Curso::getId(){
    return id;
}

std::string Curso::getNombre(){
    return nombre;
}

int Curso::getCapacidad(){
    return capacidad;
}

std::string Curso::getCarrera(){
    return carrera;
}

std::string Curso::getProfesor(){
    return profesor;
}

Alumno *Curso::getAlumnos(){
    return alumnos_start;
}

Curso *Curso::getNext(){
    return next;
}

Curso::~Curso(){
    if (alumnos_start != nullptr){
        Alumno *cursor = alumnos_start;
        Alumno *anterior = nullptr;
        while (cursor -> getNext() != nullptr){
            if(anterior != nullptr){
                anterior -> remove(nombre);
            }
            anterior = cursor;
            cursor = cursor -> getNext();
        }
        cursor -> remove(nombre);
    }
    alumnos_start = nullptr;
    delete next;
    next = nullptr;
}