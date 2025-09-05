#include "Curso.h"

int main()
{   
    Alumno *al = new Alumno(57,"Juan","Alzamora","ITI","2025");
    std::cout<<"id: ";
    std::cout<<al->getId()<< std::endl;
    std::cout<<"estudiante: ";
    std::cout<<al->getNombre() + " ";
    
    Curso *prog = new Curso(21, "Programacion",5,"ITI","David Beckios");
    prog -> add(al);
    
    std::cout<<prog->get(57)->getApellido()<< std::endl;
    std::cout<<"curso: ";
    std::cout<<prog->getNombre()<< std::endl;
    
    al -> add(5, "Programacion");
    std::cout<<"nota 1: ";
    std::cout<<al->getNotas()->getNota()<< std::endl;
    
    std::cout<<"eliminando curso..."<< std::endl;
    prog->~Curso();
    std::cout<<"comprobacion de estado de la id: ";
    std::cout<<al->getId();
    return 0;
}
