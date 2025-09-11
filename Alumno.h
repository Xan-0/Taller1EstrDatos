#include "Node.h"
#include <iostream>
#pragma once
using namespace std;

class Alumno {
    private:
        int id;
    	string nombre;
    	string apellido;
    	string carrera;
    	string fechaIngreso;
        Alumno *next;
    public:
        Alumno(int id, string nombre, string apellido,
        string carrera, string fechaIngreso);
	
        void setId(int id);
    	void setNombre(string nombre);
    	void setApellido(string apellido);
    	void setCarrera(string carrera);
    	void setFecha(string fechaIngreso);
    	void setNext(Alumno *next);
    	
        void print();
	
        int getId();
    	string getNombre();
    	string getApellido();
    	string getCarrera();
    	string getFecha();
        Alumno *getNext();
	
        ~Alumno();
};
