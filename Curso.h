#include "Alumno.h"
#pragma once

class Curso {
    private:
        int id;
    	string nombre;
    	int capacidad;
    	string carrera;
    	string profesor;
    	int cant_alumnos;
    	Curso *next;
    public:
        Curso(int id, string, int capacidad, string carrera,
        string profesor);
	
        void setId(int id);
    	void setNombre(string nombre);
    	void setCapacidad(int capacidad);
    	void setCarrera(string carrera);
    	void setProfesor(string profesor);
    	void setCantAlumnos(int cant_alumnos);
        void setNext(Curso *next);
	
    	void print();
	
        int getId();
    	string getNombre();
    	int getCapacidad();
    	string getCarrera();
    	string getProfesor();
    	int getCantAlumnos();
        Curso *getNext();
        
        ~Curso();
};
