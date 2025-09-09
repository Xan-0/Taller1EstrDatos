#include "Alumno.h"
#pragma once

class Curso {
    private:
        int id;
    	std::string nombre;
    	int capacidad;
    	std::string carrera;
    	std::string profesor;
    	int cant_alumnos;
    	Alumno *alumnos_start;
    	Curso *next;
    public:
        Curso(int id, std::string, int capacidad, std::string carrera,
        std::string profesor);
	
        void setId(int id);
    	void setNombre(std::string nombre);
    	void setCapacidad(int capacidad);
    	void setCarrera(std::string carrera);
    	void setProfesor(std::string profesor);
        void setNext(Curso *next);
	
    	void add(Alumno *alumno);
    	void remove(int id);
    	Alumno *get(int id);
    	void print();
    	void print_alumno(std::string nombre_alumno);
    	void print_alumnos();
    	double promedio(int id_alumno);
        bool isEmpty();
	
        int getId();
    	std::string getNombre();
    	int getCapacidad();
    	std::string getCarrera();
    	std::string getProfesor();
    	Alumno *getAlumnos();
        Curso *getNext();
        ~Curso();
};
