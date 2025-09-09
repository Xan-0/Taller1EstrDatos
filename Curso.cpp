#include "Curso.h"

Curso::Curso(int id, std::string nombre, int capacidad, std::string carrera,
        std::string profesor){
    this -> id = id;
    this -> nombre = nombre;
    this -> capacidad = capacidad;
    this -> carrera = carrera;
    this -> profesor = profesor;
    cant_alumnos = 0;
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
    if (alumno -> getCarrera() != this -> getCarrera() && this -> getCarrera() != "null"){
        std::cout << "Error, Carrera no compatible." << std::endl;
        return;
    }
    if (this -> cant_alumnos >= this -> getCapacidad()){
        std::cout << "Curso sin cupos." << std::endl;
        return;
    }
    if (alumnos_start == nullptr) {
        alumnos_start = alumno;
        this -> cant_alumnos++;
        return;
    }
    
    Alumno *cursor = alumnos_start;
    while (cursor -> getNext() != nullptr){
        cursor = cursor -> getNext();
    }
    
    alumno -> add(0.0, this -> getNombre());
    cursor -> setNext(alumno);
    this -> cant_alumnos++;
    return;
}

void Curso::remove(int id){
    if (alumnos_start == nullptr){
        return;
    }
    
    Alumno *cursor = alumnos_start;
    Alumno *anterior = nullptr;
    while (cursor -> getNext() != nullptr){
        
        if(cursor -> getId() == id){
            Alumno *siguiente = cursor -> getNext();
            cursor -> remove(this -> nombre);
            this -> cant_alumnos--;
            cursor = nullptr;
            
            if(anterior != nullptr){
                anterior -> setNext(siguiente);
                return;
            }
            alumnos_start = siguiente;
            return;
        }
        
        anterior = cursor;
        cursor = cursor -> getNext();
    }
    
    if(id == cursor -> getId()){
        alumnos_start -> ~Alumno();
        alumnos_start = nullptr;
        this -> cant_alumnos = 0;
        return;
    }
    std::cout << "Error, ID del alumno inválido." << std::endl;
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

void Curso::print(){
    if(this != nullptr){
        std::cout<<"__DATOS DEL CURSO__ "<< std::endl;
        std::cout<<"ID: ";
        std::cout<<this -> getId() << std::endl;
        std::cout<<"Nombre: ";
        std::cout<<this -> getNombre() << std::endl;
        std::cout<<"Capacidad: ";
        std::cout<<this -> getCapacidad() << std::endl;
        std::cout<<"Carrera: ";
        std::cout<<this -> getCarrera() << std::endl;
        std::cout<<"Profesor: ";
        std::cout<<this -> getProfesor() << std::endl;
        std::cout<<" " << std::endl;
    } else {
        std::cout<<"__CURSO INEXISTENTE__"<< std::endl;
    }
}

void Curso::print_alumno(std::string nombre_alumno){
    if (alumnos_start != nullptr){
        
        Alumno *cursor = alumnos_start;
        bool printed = false;
        while (cursor -> getNext() != nullptr){
            
            if(cursor -> getNombre() == nombre_alumno){
                cursor -> print();
                printed = true;
            }
            cursor = cursor -> getNext();
        }
        
        if(cursor -> getNombre() == nombre_alumno){
            cursor -> print();
            printed = true;
        }
        if(!printed){
            std::cout<<"__ALUMNO/S INEXISTENTE/S__"<< std::endl;
        }
        
    } else {
        if (this -> getId() == -1) {
            std::cout<<"Error, no hay alumnos."<< std::endl;
        } else {
            std::cout<<"Error, curso sin alumnos."<< std::endl;
        }
    }
    return;
}

void Curso::print_alumnos(){
    if (alumnos_start != nullptr){
        Alumno *cursor = alumnos_start;
        while (cursor -> getNext() != nullptr){
            cursor -> print();
            cursor = cursor -> getNext();
        }
        cursor -> print();
        
    } else {
        if (this -> getId() == -1) {
            std::cout<<"Error, no hay alumnos."<< std::endl;
        } else {
            std::cout<<"Error, curso sin alumnos."<< std::endl;
        }
    }
    return;
}

double Curso::promedio(int id_alumno) {
    double i = 0.0;
    double acumulador = 0.0;
    Alumno *al = this -> get(id_alumno);
    
    if(al == nullptr){
        std::cout<<"Error, alumno no está en el curso."<< std::endl;
        return -1.0;
    }
    
    Node *cursor = al -> getNotas();
    if (cursor == nullptr){
        std::cout<<"Error, alumno no tiene notas."<< std::endl;
        return -1.0;
    }
    
    while (cursor -> getNext() != nullptr){
        if (cursor -> getNota() != 0.0 && cursor -> getCurso() == this -> getNombre()){
            acumulador = acumulador + cursor -> getNota();
            i++;
        }
        std::cout<<i<< std::endl;
        cursor = cursor -> getNext();
    }
    if (cursor -> getNota() != 0.0 && cursor -> getCurso() == this -> getNombre()){
        acumulador = acumulador + cursor -> getNota();
        i++;
        std::cout<<i<< std::endl;
    }
    
    al = nullptr;
    cursor = nullptr;
    if (i == 0.0){
        return -1;
    }
    return acumulador / i;
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
