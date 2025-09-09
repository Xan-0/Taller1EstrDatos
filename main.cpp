#include "Curso.h"
#include <limits>
#include <cctype>

struct Universidad {
    Curso *cursos_start;
    
    void add_curso(Curso *curso){
        Curso *cursor = cursos_start;
        while (cursor -> getNext() != nullptr){
            cursor = cursor -> getNext();
        }
        cursor -> setNext(curso);
        curso -> setNext(nullptr);
        return;
    }
    
    Curso *get_curso(int id){
        if (id == -1){
            return cursos_start;
        }
        Curso *cursor = cursos_start;
        while (cursor -> getNext() != nullptr){
            if(cursor -> getId() == id){
                break;
            }
            cursor = cursor -> getNext();
        }
        if(cursor -> getId() == id){
            return cursor;
        }
        return nullptr;
    }
    
    void eliminar_alumno(int id){
        Curso *cursor = cursos_start;
        Alumno *al = cursos_start -> get(id);
        if(al != nullptr){
            while (cursor -> getNext() != nullptr){
                cursor -> remove(id);
                cursor = cursor -> getNext();
            }
            cursor -> remove(id);
            al -> ~Alumno();
            std::cout<<"Alumno Eliminado."<< std::endl;
        }
        return;
    }
    
    void print_curso(std::string nombre){
        Curso *cursor = cursos_start;
        bool printed = false;
        while (cursor -> getNext() != nullptr){
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
            std::cout<<"__CURSO/S INEXISTENTE/S__"<< std::endl;
        }
        return;
    }
    
    void remove(int id){
        if (id == -1){
            std::cout << "No se puede eliminar a el Curso 0." << std::endl;
            return;
        }
        if(cursos_start -> getNext() == nullptr){
            std::cout << "No hay cursos para eliminar." << std::endl;
            return;
        }
        
        Curso *cursor = cursos_start -> getNext();
        while (cursor -> getNext() != nullptr){
            if(cursor -> getId() == id){
                cursor -> ~Curso();
                std::cout<<"Curso Eliminado."<< std::endl;
                return;
            }
            cursor = cursor -> getNext();
        }
        
        return;
    }
    
    void alumnos_en(std::string carrera){
        Curso *cursor = cursos_start;
        bool printed = false;
        while (cursor -> getNext() != nullptr){
            if(cursor -> getCarrera() == carrera){
                cursor -> print_alumnos();
                printed = true;
            }
            cursor = cursor -> getNext();
        }
        if(cursor -> getCarrera() == carrera){
            cursor -> print_alumnos();
            printed = true;
        }
        if(!printed){
            std::cout<<"No hay cursos de la designada carrera."<< std::endl;
        }
        return;
    }
    
    void cursos_alumno(int id){
        if (cursos_start -> getNext() == nullptr){
            std::cout<<"No hay cursos disponibles."<< std::endl;
            return;
        }
        if (cursos_start -> getAlumnos() == nullptr){
            std::cout<<"No hay alumnos."<< std::endl;
            return;
        }
        
        Curso *cursor = cursos_start -> getNext();
        bool printed = false;
        while (cursor -> getNext() != nullptr){
            if(cursor -> get(id) != nullptr){
                cursor -> print();
                printed = true;
            }
            cursor = cursor -> getNext();
        }
        if(cursor -> get(id) != nullptr){
            cursor -> print();
            printed = true;
        }
        if(!printed){
            std::cout<<"Alumno no está inscrito en ningún curso."<< std::endl;
        }
        return;
    }
    
    double promedio_general(int id){
        double i = 1.0;
        double acumulador = 0.0;
        double temp = 0.0;
        
        Curso *cursor = cursos_start -> getNext();
        while (cursor -> getNext() != nullptr){
            
            if (cursor -> get(id) != nullptr){
                temp = cursor -> promedio(id);
                if (temp != -1.0) {
                    acumulador = acumulador + temp;
                    i++;
                }
            }
            
            cursor = cursor -> getNext();
        }
        
        if (cursor -> get(id) != nullptr){
            temp = cursor -> promedio(id);
                if (temp != -1.0) {
                    acumulador = acumulador + temp;
                }
        }
        return acumulador / i;
    }
    
};

Universidad* ucn = new Universidad;

bool esValido(const std::string & texto) {
    if (texto.empty()) {
        return false;
    }
    for (char c: texto) {
        if (!isalnum(static_cast<unsigned char>(c))) {
            return false;
        }
    }
    return true;
}

int leer_input_int(int input){
    bool valid = false;
    do {
        std::cout<<"Input: ";
        std::cin >> input;
        if(std::cin.fail()){
            std::cout << "Input inválido. Debe ser un entero." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
        } else {
            valid = true;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << " " << std::endl;
        }
    } while (!valid);
    
    return input;
}

double leer_input_double(double input){
    
    while (true) {
        std::cout << "Input (double): ";
        std::cin >> input;
        
        if (std::cin.fail()) {
            std::cout << "Input inválido. Debe ser un decimal (double)." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.clear();
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return input;
}

std::string leer_input_str(std::string input){
    bool valid = false;
    do {
        std::cout<<"Input: ";
        std::getline(std::cin, input);
        
        if (esValido(input)) {
            valid = true;
            std::cout << " " << std::endl;
        } else {
            std::cout << "Error. Texto inválido." << std::endl;
        }
        
    } while (!valid);
    
    return input;
}

void menu_alumnos(int int_input, std::string str_input){
    double double_input;
    int id = -1;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fecha;
    int id_curso;
    double nota;
    Curso *temp = nullptr;
    Alumno *temp_al = nullptr;
    
    do {
        std::cout<<"[Menú Alumnos]"<< std::endl;
        std::cout<<" "<< std::endl;
        std::cout<<"Opciones:"<< std::endl;
        std::cout<<"0. Salir."<< std::endl;
        std::cout<<"1. Crear Alumno."<< std::endl;
        std::cout<<"2. Buscar Alumno."<< std::endl;
        std::cout<<"3. Eliminar Alumno."<< std::endl;
        std::cout<<"4. Inscribir Alumno a un Curso."<< std::endl;
        std::cout<<"5. Desinscribir a Alumno de un Curso."<< std::endl;
        std::cout<<"6. Asignar notas a un Alumno en un Curso."<< std::endl;
        
        int_input = leer_input_int(int_input);
        
        switch(int_input){
            case 0:
                std::cout<<"[Menú Alumnos Finalizado]"<< std::endl;
                break;
            case 1:
                std::cout<<"Debe ingresar todos los datos necesarios: "<< std::endl;
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                std::cout<<"[NOMBRE]"<< std::endl;
                nombre = leer_input_str(str_input);
                std::cout<<"[APELLIDO]"<< std::endl;
                apellido = leer_input_str(str_input);
                std::cout<<"[CARRERA]"<< std::endl;
                carrera = leer_input_str(str_input);
                std::cout<<"[FECHA DE INGRESO]"<< std::endl;
                fecha = leer_input_str(str_input);
                
                ucn -> cursos_start -> add(new Alumno(id,nombre,apellido,carrera,fecha));
                std::cout<<"Alumno Creado."<< std::endl;
                break;
            case 2:
                if(ucn -> cursos_start -> isEmpty()){
                    std::cout<<"No hay alumnos."<< std::endl;
                    break;
                }
                do {
                std::cout<<"Buscar Almuno por:"<< std::endl;
                std::cout<<"0. Cancelar."<< std::endl;
                std::cout<<"1. ID."<< std::endl;
                std::cout<<"2. Nombre."<< std::endl;
                
                int_input = leer_input_int(int_input);
                
                //...
                switch(int_input){
                    case 0:
                        std::cout<<"[Cancelado]"<< std::endl;
                        break;
                    case 1:
                        std::cout<<"[ID]"<< std::endl;
                        id = leer_input_int(int_input);
                        ucn -> cursos_start -> get(id) -> print();
                        break;
                    case 2:
                        std::cout<<"[NOMBRE]"<< std::endl;
                        nombre = leer_input_str(str_input);
                        ucn -> cursos_start -> print_alumno(nombre);
                        break;
                    default:
                        std::cout<<"Opción no válida, debe ser un numero del 0 al 2."<< std::endl;
                        break;
                } //...
                
                } while(int_input != 0);
                int_input = 2;
                break;
            case 3:
                if(ucn -> cursos_start -> isEmpty()){
                    std::cout<<"No hay alumnos."<< std::endl;
                    break;
                }
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                
                ucn -> eliminar_alumno(id);
                break;
            case 4:
                if(ucn -> cursos_start -> getNext() == nullptr){
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                std::cout<<"[ID CURSO]"<< std::endl;
                id_curso = leer_input_int(int_input);
                
                if(id_curso == -1){
                    std::cout << "No se puede inscribir a un alumno en el Curso 0." << std::endl;
                    break;
                }
                
                temp =  ucn -> get_curso(id_curso);
                if(temp != nullptr){
                    temp -> add(ucn -> cursos_start -> get(id));
                    std::cout<<"Alumno Inscrito en " + temp -> getNombre() + "."<< std::endl;
                } else {
                    std::cout << "Error, ID del curso inexistente." << std::endl;
                }
                break;
            case 5:
                if(ucn -> cursos_start -> getNext() == nullptr){
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                std::cout<<"[ID CURSO]"<< std::endl;
                id_curso = leer_input_int(int_input);
                
                if(id_curso == -1){
                    std::cout << "No se puede desinscribir a un alumno en el Curso 0." << std::endl;
                    break;
                }
                
                temp = ucn -> get_curso(id_curso);
                
                if(temp != nullptr){
                    temp -> remove(id);
                    std::cout<<"Alumno Desinscrito de " + temp -> getNombre() + "."<< std::endl;
                } else {
                    std::cout << "Error, ID del curso inexistente." << std::endl;
                }
                break;
            case 6:
                /*if(ucn -> cursos_start -> getNext() == nullptr){
                    std::cout << "No hay cursos disponibles." << std::endl;
                    break;
                }
                if(ucn -> cursos_start -> isEmpty()){
                    std::cout<<"No hay alumnos."<< std::endl;
                    break;
                }*/
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                std::cout<<"[ID CURSO]"<< std::endl;
                id_curso = leer_input_int(int_input);
                std::cout<<"[NOTA]"<< std::endl;
                nota = leer_input_double(double_input);
                
                std::cout<<nota<< std::endl;
                if (nota < 1.0 || nota > 7.0){
                    std::cout << "Error, la nota debe estar en la escala Chilena (1,0 a 7,0)." << std::endl;
                    break;
                }
                
                temp = ucn -> get_curso(id_curso);
                
                if (temp != nullptr){
                    temp_al = temp -> get(id);
                    if (temp_al != nullptr){
                        
                        temp_al -> add(nota, temp -> getNombre());
                    } else {
                        std::cout << "Error, ID del alumno inexistente." << std::endl;
                        break;
                    }
                } else {
                    std::cout << "Error, ID del curso inexistente." << std::endl;
                    break;
                }
                
                std::cout<<"Nota Agregada."<< std::endl;
                break;
            default:
                std::cout<<"Opción no válida, debe ser un numero del 0 al 6."<< std::endl;
                break;
        }
        
    } while (int_input != 0);
    return;
}

void menu_cursos(int int_input, std::string str_input){
    int id = -1;
    std::string nombre;
    int cap = -1;
    std::string carrera;
    std::string profesor;
    
    do {
        std::cout<<"[Menú Cursos]"<< std::endl;
        std::cout<<" "<< std::endl;
        std::cout<<"Opciones:"<< std::endl;
        std::cout<<"0. Salir."<< std::endl;
        std::cout<<"1. Crear Curso."<< std::endl;
        std::cout<<"2. Buscar Curso."<< std::endl;
        std::cout<<"3. Eliminar Curso."<< std::endl;
        
        int_input = leer_input_int(int_input);
        
        switch(int_input){
            case 0:
                std::cout<<"[Menú Cursos Finalizado]"<< std::endl;
                break;
            case 1:
                std::cout<<"Debe ingresar todos los datos necesarios: "<< std::endl;
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                std::cout<<"[NOMBRE DEL CURSO]"<< std::endl;
                nombre = leer_input_str(str_input);
                std::cout<<"[CAPACIDAD DE ALUMNOS]"<< std::endl;
                cap = leer_input_int(int_input);
                std::cout<<"[CARRERA]"<< std::endl;
                carrera = leer_input_str(str_input);
                std::cout<<"[PROFESOR]"<< std::endl;
                profesor = leer_input_str(str_input);
                
                ucn -> add_curso(new Curso(id,nombre,cap,carrera,profesor));
                std::cout<<"Curso Creado."<< std::endl;
                break;
            case 2:
                if(ucn -> cursos_start -> getNext() == nullptr){
                    std::cout<<"No hay cursos."<< std::endl;
                    break;
                }
                
                do {
                std::cout<<"Buscar Curso por:"<< std::endl;
                std::cout<<"0. Cancelar."<< std::endl;
                std::cout<<"1. ID."<< std::endl;
                std::cout<<"2. Nombre."<< std::endl;
                
                int_input = leer_input_int(int_input);
                
                //...
                switch(int_input){
                    case 0:
                        std::cout<<"[Cancelado]"<< std::endl;
                        break;
                    case 1:
                        std::cout<<"[ID]"<< std::endl;
                        id = leer_input_int(int_input);
                        ucn -> get_curso(id) -> print();
                        break;
                    case 2:
                        std::cout<<"[NOMBRE]"<< std::endl;
                        nombre = leer_input_str(str_input);
                        ucn -> print_curso(nombre);
                        break;
                    default:
                        std::cout<<"Opción no válida, debe ser un numero del 0 al 2."<< std::endl;
                        break;
                } //...
                
                } while(int_input != 0);
                int_input = 2;
                break;
            case 3:
                if(ucn -> cursos_start -> getNext() == nullptr){
                    std::cout<<"No hay cursos."<< std::endl;
                    break;
                }
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                
                ucn -> remove(id);
                break;
            default:
                std::cout<<"Opción no válida, debe ser un numero del 0 al 3."<< std::endl;
                break;
        }
    } while (int_input != 0);
    return;
}

void menu_reportes(int int_input, std::string str_input){
    int id = -1;
    int id_curso = -1;
    double promedio = 0.0;
    double promedio_g = 0.0;
    std::string carrera;
    Curso *temp = nullptr;
    
    do {
        std::cout<<"[Menú de Consultas y Reportes]"<< std::endl;
        std::cout<<" "<< std::endl;
        std::cout<<"Opciones:"<< std::endl;
        std::cout<<"0. Salir."<< std::endl;
        std::cout<<"1. Listar Alumnos en Carrera."<< std::endl;
        std::cout<<"2. Cursos en los que un Alumno está inscrito."<< std::endl;
        std::cout<<"3. Promedio de Notas de un Alumno en un Curso."<< std::endl;
        std::cout<<"4. Promedio de Notas General de un Alumno."<< std::endl;
        
        int_input = leer_input_int(int_input);
        
        switch(int_input){
            case 0:
                std::cout<<"[Menú de Consultas y Reportes Finalizado]"<< std::endl;
                break;
            case 1:
                std::cout<<"[CARRERA]"<< std::endl;
                carrera = leer_input_str(str_input);
                
                ucn -> alumnos_en(carrera);
                break;
            case 2:
                if(ucn -> cursos_start -> getNext() == nullptr){
                    std::cout<<"No hay cursos."<< std::endl;
                    break;
                }
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                ucn -> cursos_alumno(id);
                break;
            case 3:
                if(ucn -> cursos_start -> getNext() == nullptr){
                    std::cout<<"No hay cursos."<< std::endl;
                    break;
                }
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                std::cout<<"[ID CURSO]"<< std::endl;
                id_curso = leer_input_int(int_input);
                
                temp = ucn -> get_curso(id_curso);
                if(temp == nullptr){
                    std::cout<<"Curso inválido."<< std::endl;
                    break;
                }
                promedio = temp -> promedio(id);
                if(promedio != -1.0){
                    std::cout<<"Promedio de Notas del Alumno en el Curso " + temp -> getNombre() + ": ";
                    std::cout<<promedio<< std::endl;
                }
                break;
            case 4:
                if(ucn -> cursos_start -> getNext() == nullptr){
                    std::cout<<"No hay cursos."<< std::endl;
                    break;
                }
                if (ucn -> cursos_start -> isEmpty()){
                    std::cout<<"No hay alumnos."<< std::endl;
                    break;
                }
                std::cout<<"[ID]"<< std::endl;
                id = leer_input_int(int_input);
                
                promedio_g = ucn -> promedio_general(id);
                if(promedio != -1.0){
                    std::cout<<"Promedio General de Notas del Alumno: ";
                    std::cout<<promedio_g<< std::endl;
                }
                break;
            default:
                std::cout<<"Opción no válida, debe ser un numero del 0 al 4."<< std::endl;
                break;
        }
        
    } while (int_input != 0);
    
    std::cout<<"[Menú reportes Finalizado]"<< std::endl;
    return;
}

void menu(){
    std::string str_input;
    int int_input = -1;
    do {
        std::cout<<"[MENÚ PRINCIPAL]"<< std::endl;
        std::cout<<" "<< std::endl;
        std::cout<<"Opciones:"<< std::endl;
        std::cout<<"0. Salir."<< std::endl;
        std::cout<<"1. Manejo de Alumnos."<< std::endl;
        std::cout<<"2. Manejo de Cursos."<< std::endl;
        std::cout<<"3. Consultas y Reportes."<< std::endl;
        
        int_input = leer_input_int(int_input);
        
        switch(int_input){
            case 0:
                std::cout<<"[MENÚ FINALIZADO]"<< std::endl;
                break;
            case 1:
                menu_alumnos(int_input, str_input);
                break;
            case 2:
                menu_cursos(int_input, str_input);
                break;
            case 3:
                menu_reportes(int_input, str_input);
                break;
            default:
                std::cout<<"Opción no válida, debe ser un numero del 0 al 3."<< std::endl;
                break;
        }
    } while (int_input != 0);
    return;
}

int main(){
    ucn -> cursos_start = new Curso(-1, "Curso_0", 1024, "null", "null");
    ucn -> cursos_start -> setNext(new Curso(1, "Programacion", 3, "iti","ed"));
    ucn -> cursos_start -> getNext() -> setNext(new Curso(2, "Electrotecnia", 3, "iti","fd"));
    Alumno *first = new Alumno(1, "Juan", "Beckios", "iti","2024");
    ucn -> cursos_start -> add(first);
    ucn -> cursos_start -> getNext() -> add(first);
    ucn -> cursos_start -> getNext() -> getNext() -> add(first);
    first -> add(2.0, "Programacion");
    first -> add(6.0, "Programacion");
    first -> add(6.0, "Electrotecnia");
    menu();
    return 0;
}
