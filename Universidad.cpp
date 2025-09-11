#include "Universidad.h"

Universidad::Universidad(string nombre){
    this -> nombre = nombre;
    notas_start = nullptr;
    alumnos_start = nullptr;
    cursos_start = nullptr;
}

void Universidad::setNombre(string nombre){
    this -> nombre = nombre;
}

string Universidad::getNombre(){
    return nombre;
}

void Universidad::addNota(Node *nuevo) {
    Curso *curso = getCurso(nuevo -> getCurso());
    
    if (notas_start == nullptr) {
        notas_start = nuevo;
        notas_start -> setNext(nullptr);
        
        //Si es inscripción se aumenta la cantidad de alumnos al curso
        if (nuevo -> getNota() == 0.0){
            curso -> setCantAlumnos(curso -> getCantAlumnos() + 1);
        }
        
        return;
    }
    
    Node *cursor = notas_start;
    while (cursor -> getNext() != nullptr){
        cursor = cursor -> getNext();
    }
    
    cursor -> setNext(nuevo);
    nuevo -> setNext(nullptr);
    if (nuevo -> getNota() == 0.0){
        curso -> setCantAlumnos(curso -> getCantAlumnos() + 1);
    }
    curso = nullptr;
    return;
}

//Se añade el alumno a la Universidad, no necesariamente a un curso.
void Universidad::addAlumno(Alumno *alumno){
    if (alumnos_start == nullptr) {
        alumnos_start = alumno;
        alumnos_start -> setNext(nullptr);
        return;
    }
    
    Alumno *cursor = alumnos_start;
    while (cursor -> getNext() != nullptr){
        cursor = cursor -> getNext();
    }
    
    cursor -> setNext(alumno);
    alumno -> setNext(nullptr);
    return;
}

void Universidad::addCurso(Curso *curso){
    if (cursos_start == nullptr) {
        cursos_start = curso;
        cursos_start -> setNext(nullptr);
        return;
    }
    
    Curso *cursor = cursos_start;
    while (cursor -> getNext() != nullptr){
        cursor = cursor -> getNext();
    }
    cursor -> setNext(curso);
    curso -> setNext(nullptr);
    return;
}

//Usado para desinscribir a un Alumno de un Curso
void Universidad::removerNotas(int id_alumno, int id_curso){
    
    Node *cursor = notas_start;
    Node *anterior = nullptr;
    Node *siguiente = nullptr;
    while (cursor -> getNext() != nullptr){
        siguiente = cursor -> getNext();
        
        if(anterior != nullptr){
            if(cursor -> getAlumno() == id_alumno && cursor -> getCurso() == id_curso){
                cursor -> ~Node();
                anterior -> setNext(siguiente);
            }
        } else if(cursor -> getAlumno() == id_alumno && cursor -> getCurso() == id_curso){
            cursor -> ~Node();
            notas_start = siguiente;
        }
        
        anterior = cursor;
        cursor = siguiente;
        
    }
    
    if(anterior != nullptr){
        if(cursor -> getAlumno() == id_alumno && cursor -> getCurso() == id_curso){
            cursor -> ~Node();
            anterior -> setNext(nullptr);
        }
    } else if(cursor -> getAlumno() == id_alumno && cursor -> getCurso() == id_curso){
        cursor -> ~Node();
    }
    
    siguiente = nullptr;
    anterior = nullptr;
    cursor = nullptr;
    return;
}

void Universidad::removerAlumno(int id){
    //Eliminar todas las Notas del Alumno.
    Node *cursor = notas_start;
    Node *anterior = nullptr;
    Node *siguiente = nullptr;
    while (cursor -> getNext() != nullptr){
        siguiente = cursor -> getNext();
        
        if(anterior != nullptr){
            if(cursor -> getAlumno() == id){
                cursor -> ~Node();
                anterior -> setNext(siguiente);
            }
        } else if(cursor -> getAlumno() == id){
            cursor -> ~Node();
            notas_start = siguiente;
        }
        anterior = cursor;
        cursor = siguiente;
        
    }
    
    if(anterior != nullptr){
        if(cursor -> getAlumno() == id){
            cursor -> ~Node();
            anterior -> setNext(nullptr);
        }
    } else {
        if(cursor -> getAlumno() == id){
            cursor -> ~Node();
        }
    }
    
    siguiente = nullptr;
    anterior = nullptr;
    cursor = nullptr;
    
    //Eliminar el Alumno de la lista de Alumnos.
    Alumno *cursor2 = alumnos_start;
    Alumno *anterior2 = nullptr;
    Alumno *siguiente2 = nullptr;
    while(cursor2 -> getNext() != nullptr){
        siguiente2 = cursor2 -> getNext();
        
        if(anterior2 != nullptr){
            if(cursor2 -> getId() == id){
                cursor2 -> ~Alumno();
                anterior2 -> setNext(siguiente2);
            }
        } else if(cursor2 -> getId() == id){
            cursor2 -> ~Alumno();
            alumnos_start = siguiente2;
        }
        anterior2 = cursor2;
        cursor2 = cursor2 -> getNext();
        
    }
    
    if(anterior2 != nullptr){
        cursor2 -> ~Alumno();
        anterior2 -> setNext(nullptr);
    } else if(cursor2 -> getId() == id){
        cursor2 -> ~Alumno();
    }
    
    siguiente2 = nullptr;
    anterior2 = nullptr;
    cursor2 = nullptr;
    return;
}

void Universidad::removerCurso(int id){
    //Eliminar las inscripciones de todos los Alumnos del Curso.
    Alumno *cursor = alumnos_start;
    Alumno *anterior = nullptr;
    while (cursor -> getNext() != nullptr){
        
        if(anterior != nullptr){
            if(getNota(anterior -> getId(), id) != nullptr){ //Si el Alumno pertenece al Curso.
                removerNotas(anterior -> getId(), id);
            }
        }
        anterior = cursor;
        cursor = cursor -> getNext();
        
    }
    
    if(getNota(cursor -> getId(), id) != nullptr){
        removerNotas(cursor -> getId(), id);
    }
    anterior = nullptr;
    cursor = nullptr;
    
    //Eliminar el Curso de la lista de Cursos.
    Curso *cursor2 = cursos_start;
    Curso *anterior2 = nullptr;
    Curso *siguiente = nullptr;
    while(cursor2 -> getNext() != nullptr){
        siguiente = cursor2 -> getNext();
        
        if(anterior2 != nullptr){
            if(cursor2 -> getId() == id){
                cursor2 -> ~Curso();
                anterior2 -> setNext(siguiente);
            }
        } else if(cursor2 -> getId() == id){
            cursor2 -> ~Curso();
            cursos_start = siguiente;
        }
        anterior2 = cursor2;
        cursor2 = cursor2 -> getNext();
        
    }
    
    if(anterior2 != nullptr){
        cursor2 -> ~Curso();
        anterior2 -> setNext(nullptr);
    } else if(cursor2 -> getId() == id){
        cursor2 -> ~Curso();
    }
    
    siguiente = nullptr;
    anterior2 = nullptr;
    cursor2 = nullptr;
    return;
}

//Se usa para verificar si un Alumno está inscrito en un Curso.
Node *Universidad::getNota(int id_alumno, int id_curso){
    if (cursos_start == nullptr || alumnos_start == nullptr || notas_start == nullptr) {
        return nullptr;
    }
    
    Node *cursor = notas_start;
    while(cursor -> getNext() != nullptr){
        if(cursor -> getAlumno() == id_alumno && cursor -> getCurso() == id_curso){
            return cursor;
        }
        cursor = cursor -> getNext();
    }
    if(cursor -> getAlumno() == id_alumno && cursor -> getCurso() == id_curso){
        return cursor;
    }
    
    return nullptr;
}

Alumno *Universidad::getAlumno(int id) {
    if (alumnos_start == nullptr) {
        return nullptr;
    }
    
    Alumno *cursor = alumnos_start;
    while (cursor -> getNext() != nullptr) {
        if(cursor -> getId() == id){
            return cursor;
        }
        cursor = cursor -> getNext();
    }
    if(cursor -> getId() == id){
        return cursor;
    }
    return nullptr;
}

Curso *Universidad::getCurso(int id) {
    if (cursos_start == nullptr) {
        return nullptr;
    }
    
    Curso *cursor = cursos_start;
    while (cursor -> getNext() != nullptr) {
        if(cursor -> getId() == id){
            return cursor;
        }
        cursor = cursor -> getNext();
    }
    if(cursor -> getId() == id){
        return cursor;
    }
    return nullptr;
}

//Imprime por consola a todos los alumnos con el mismo nombre
void Universidad::print_alumno(string nombre){
    if (alumnos_start == nullptr) {
        return;
    }
    bool printed = false;
    
    Alumno *cursor = alumnos_start;
    while(cursor -> getNext() != nullptr){
        if(cursor -> getNombre() == nombre){
            cursor -> print();
            printed = true;
        }
        cursor = cursor -> getNext();
    }
    if(cursor -> getNombre() == nombre){
        cursor -> print();
        printed = true;
    }
    if(!printed){
        cout<<"No se han encontrado Alumnos con el nombre "+nombre+"."<< endl;
    }
    return;
}

//Imprime por consola a todos los cursos con el mismo nombre
void Universidad::print_curso(string nombre){
    if (cursos_start == nullptr) {
        return;
    }
    bool printed = false;
    
    Curso *cursor = cursos_start;
    while(cursor -> getNext() != nullptr){
        if(cursor -> getNombre() == nombre){
            cursor -> print();
            printed = true;
        }
        cursor = cursor -> getNext();
    }
    if(cursor -> getNombre() == nombre){
        cursor -> print();
        printed = true;
    }
    if(!printed){
        cout<<"No se han encontrado Cursos con el nombre "+nombre+"."<< endl;
    }
    return;
}

////Imprime por consola a todos los alumnos de la misma carrera
void Universidad::print_alumnos(string carrera){
    if (alumnos_start == nullptr) {
        return;
    }
    bool printed = false;
    
    Alumno *cursor = alumnos_start;
    while(cursor -> getNext() != nullptr){
        if(cursor -> getCarrera() == carrera){
            cursor -> print();
            printed = true;
        }
        cursor = cursor -> getNext();
    }
    if(cursor -> getCarrera() == carrera){
        cursor -> print();
        printed = true;
    }
    if(!printed){
        cout<<"No se han encontrado Alumnos en la Carrera " +carrera+"."<< endl;
    }
    return;
}

//Imprime por consola a todos los cursos que contienen al alumno
void Universidad::print_cursos(int id_alumno){
    if (cursos_start == nullptr) {
        return;
    }
    bool printed = false;
    /*Un Nodo con los parámetros (4.0,2,3) significa que el alumno 2 en el curso 3 tiene
    asignada la nota 4.0, si la nota es 0.0 es tomada como una inscripción al curso 3*/
    Node *cursor = notas_start;
    while(cursor -> getNext() != nullptr){
        if(cursor -> getAlumno() == id_alumno && cursor -> getNota() == 0.0){
            getCurso(cursor -> getCurso()) -> print();
            printed = true;
        }
        
        cursor = cursor -> getNext();
    }
    if(cursor -> getAlumno() == id_alumno && cursor -> getNota() == 0.0){
        getCurso(cursor -> getCurso()) -> print();
        printed = true;
    }
    
    if(!printed){
        cout<<"El Alumno no tiene Cursos inscritos."<< endl;
    }
    return;
}

double Universidad::promedio(int id_alumno, int id_curso){
    double i = 0.0;
    double acumulador = 0.0;
    
    Alumno *al = getAlumno(id_alumno);
    
    if(al == nullptr){
        cout<<"Error, ID del Alumno inexistente."<< endl;
        return -1.0;
    }
    
    Node *cursor = notas_start;
    while (cursor -> getNext() != nullptr){
        if (cursor -> getNota() != 0.0 && cursor -> getAlumno() == id_alumno
            && cursor -> getCurso() == id_curso){
            
            acumulador = acumulador + cursor -> getNota();
            i++;
        }
        cursor = cursor -> getNext();
    }
    if (cursor -> getNota() != 0.0 && cursor -> getAlumno() == id_alumno
        && cursor -> getCurso() == id_curso){
        acumulador = acumulador + cursor -> getNota();
        i++;
    }
    
    al = nullptr;
    cursor = nullptr;
    if (i == 0.0){
        return 0.0;
    }
    return acumulador / i;
}

//Calcula el promedio del alumno por cada curso y se recalcula un promedio total.
double Universidad::promedio_General(int id_alumno){
    
    double i = 0.0;
    double acumulador = 0.0;
    
    Curso *cursor = cursos_start;
    while (cursor -> getNext() != nullptr){
        
        if(getNota(id_alumno, cursor -> getId()) != nullptr){
            acumulador = acumulador + promedio(id_alumno, cursor -> getId());
            i++;
        }
        
        cursor = cursor -> getNext();
    }
    if(getNota(id_alumno, cursor -> getId()) != nullptr){
        acumulador = acumulador + promedio(id_alumno, cursor -> getId());
        i++;
    }
    
    cursor = nullptr;
    if (i == 0.0){
        return 0.0;
    }
    return acumulador / i;
}

Universidad::~Universidad(){
    if (cursos_start != nullptr) {
        
        Curso *cursor = cursos_start;
        Curso *anterior = nullptr;
        while (cursor -> getNext() != nullptr){ //Va eliminando al anterior mientras reccorre
            if(anterior != nullptr){
                removerCurso(anterior -> getId());
            }
            anterior = cursor;
            cursor = cursor -> getNext();
        }
        removerCurso(anterior -> getId());
        removerCurso(cursor -> getId());
        anterior = nullptr;
        cursor = nullptr;
    }
    
    notas_start = nullptr;
    alumnos_start = nullptr;
    cursos_start = nullptr;
}