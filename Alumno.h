#include "Node.h"
#pragma once

class Alumno {
    private:
        int id;
    	std::string nombre;
    	std::string apellido;
    	std::string carrera;
    	std::string fechaIngreso;
    	Node *notas_start;
        Alumno *next;
    public:
        Alumno(int id, std::string nombre, std::string apellido,
        std::string carrera, std::string fechaIngreso);
	
        void setId(int id);
    	void setNombre(std::string nombre);
    	void setApellido(std::string apellido);
    	void setCarrera(std::string carrera);
    	void setFecha(std::string fechaIngreso);
    	
    	void add(int nota, std::string curso);
    	void remove(std::string curso);
        void setNext(Alumno *next);
	
        int getId();
    	std::string getNombre();
    	std::string getApellido();
    	std::string getCarrera();
    	std::string getFecha();
    	Node *getNotas();
        Alumno *getNext();
	
        ~Alumno();
};