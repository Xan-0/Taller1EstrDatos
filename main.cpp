#include "Universidad.h"
#include <limits>
#include <cctype>

//Johan Piñones - Paralelo C2

Universidad* ucn = new Universidad("UCN");

bool esValido(const string & texto) {
    if (texto.empty()) {
        return false;
    }
    for (char c: texto) {
        if (!isalnum(static_cast<unsigned char>(c))) { //Si no es alfanumérico retorna false.
            return false;
        }
    }
    return true;
}

int leer_input_int(int input){
    bool valid = false;
    do {
        cout<<"Input: ";
        cin >> input;
        if(cin.fail()){
            cout << "Input inválido. Debe ser un entero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            valid = true;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << " " << endl;
        }
    } while (!valid);
    
    return input;
}

double leer_input_double(double input){
    
    while (true) {
        cout << "Input (double): ";
        cin >> input;
        
        if (cin.fail()) {
            cout << "Input inválido. Debe ser un decimal (double)." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    return input;
}

string leer_input_str(string input){
    bool valid = false;
    do {
        cout<<"Input: ";
        getline(cin, input);
        
        if (esValido(input)) {
            valid = true;
            cout << " " << endl;
        } else {
            cout << "Error. Texto inválido." << endl;
        }
        
    } while (!valid);
    
    return input;
}

void menu_alumnos(int int_input, string str_input) {
    double double_input;
    int id = -1;
    string nombre;
    string apellido;
    string carrera;
    string fecha;
    int id_curso;
    double nota;
    Curso *temp_cur = nullptr;
    Alumno *temp_al = nullptr;
    
    do {
        cout<<"[Menú Alumnos]"<< endl;
        cout<<" "<< endl;
        cout<<"Opciones:"<< endl;
        cout<<"0. Salir."<< endl;
        cout<<"1. Crear Alumno."<< endl;
        cout<<"2. Buscar Alumno."<< endl;
        cout<<"3. Eliminar Alumno."<< endl;
        cout<<"4. Inscribir Alumno a un Curso."<< endl;
        cout<<"5. Desinscribir a Alumno de un Curso."<< endl;
        cout<<"6. Asignar notas a un Alumno en un Curso."<< endl;
        
        int_input = leer_input_int(int_input);
        
        switch(int_input){
            case 0:
                cout<<"[Menú Alumnos Finalizado]"<< endl;
                cout<<" "<< endl;
                break;
            case 1:
                cout<<"Debe ingresar todos los datos necesarios: "<< endl;
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                if(ucn -> getAlumno(id) != nullptr){
                    cout<<"ID ya existente, los identificadores únicos no pueden repetirse."<< endl;
                    break;
                }
                
                cout<<"[NOMBRE]"<< endl;
                nombre = leer_input_str(str_input);
                cout<<"[APELLIDO]"<< endl;
                apellido = leer_input_str(str_input);
                cout<<"[CARRERA]"<< endl;
                carrera = leer_input_str(str_input);
                cout<<"[FECHA DE INGRESO]"<< endl;
                fecha = leer_input_str(str_input);
                
                ucn -> addAlumno(new Alumno(id,nombre,apellido,carrera,fecha));
                cout<<"Alumno Creado."<< endl;
                break;
            case 2:
                if(ucn -> alumnos_start == nullptr){
                    cout<<"No hay alumnos."<< endl;
                    break;
                }
                do {
                cout<<"Buscar Almuno por:"<< endl;
                cout<<"0. Cancelar."<< endl;
                cout<<"1. ID."<< endl;
                cout<<"2. Nombre."<< endl;
                
                int_input = leer_input_int(int_input);
                
                //...
                switch(int_input){
                    case 0:
                        cout<<"[Cancelado]"<< endl;
                        break;
                    case 1:
                        cout<<"[ID ALUMNO]"<< endl;
                        id = leer_input_int(int_input);
                        ucn -> getAlumno(id) -> print();
                        break;
                    case 2:
                        cout<<"[NOMBRE]"<< endl;
                        nombre = leer_input_str(str_input);
                        ucn -> print_alumno(nombre);
                        break;
                    default:
                        cout<<"Opción no válida, debe ser un numero del 0 al 2."<< endl;
                        break;
                } //...
                
                } while(int_input != 0);
                int_input = 2;
                break;
            case 3:
                if(ucn -> alumnos_start == nullptr){
                    cout<<"No hay alumnos."<< endl;
                    break;
                }
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                ucn -> removerAlumno(id);
                cout<<"Alumno eliminado."<< endl;
                break;
            case 4:
                if(ucn -> cursos_start == nullptr){
                    cout << "No hay cursos disponibles." << endl;
                    break;
                }
                if(ucn -> alumnos_start == nullptr) {
                    cout<<"No hay alumnos."<< endl;
                    break;
                }
                
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                if(ucn -> getAlumno(id) == nullptr){
                    cout<<"Error, ID del Alumno inexistente."<< endl;
                    break;
                }
                
                cout<<"[ID CURSO]"<< endl;
                id_curso = leer_input_int(int_input);
                
                temp_cur = ucn -> getCurso(id_curso);
                temp_al = ucn -> getAlumno(id);
                
                if(temp_cur != nullptr){
                    
                    if(temp_al -> getCarrera() == temp_cur -> getCarrera()){
                        if(temp_cur -> getCantAlumnos() < temp_cur -> getCapacidad()){
                            
                            ucn -> addNota(new Node(0.0, id, id_curso));
                            cout<<"Alumno Inscrito en " + temp_cur -> getNombre() + "."<< endl;
                            
                        } else {
                            cout << "Curso sin cupos." << endl;
                        }
                        
                    } else {
                        cout << "Error, Carrera no compatible." << endl;
                        break;
                    }
                    
                } else {
                    cout << "Error, ID del Curso inexistente." << endl;
                    break;
                }
                temp_cur = nullptr;
                temp_al = nullptr;
                break;
            case 5:
                if(ucn -> cursos_start == nullptr){
                    cout << "No hay Cursos disponibles." << endl;
                    break;
                }
                if(ucn -> alumnos_start == nullptr) {
                    cout<<"No hay Alumnos."<< endl;
                    break;
                }
                
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                if(ucn -> getAlumno(id) == nullptr){
                    cout<<"Error, ID del Alumno inexistente."<< endl;
                    break;
                }
                
                cout<<"[ID CURSO]"<< endl;
                id_curso = leer_input_int(int_input);
                
                temp_cur = ucn -> getCurso(id_curso);
                
                if(temp_cur != nullptr){
                    ucn -> removerNotas(id, id_curso);
                    cout<<"Alumno Desinscrito de " + temp_cur -> getNombre() + "."<< endl;
                } else {
                    cout << "Error, ID del Curso inexistente." << endl;
                    break;
                }
                temp_cur = nullptr;
                break;
            case 6:
                if(ucn -> cursos_start == nullptr){
                    cout << "No hay cursos disponibles." << endl;
                    break;
                }
                if(ucn -> alumnos_start == nullptr) {
                    cout<<"No hay alumnos."<< endl;
                    break;
                }
                
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                cout<<"[ID CURSO]"<< endl;
                id_curso = leer_input_int(int_input);
                cout<<"[NOTA]"<< endl;
                nota = leer_input_double(double_input);
                
                cout<<nota<< endl;
                if (nota < 1.0 || nota > 7.0){
                    cout << "Error, la nota debe estar en la escala Chilena (1,0 a 7,0)." << endl;
                    break;
                }
                
                temp_cur = ucn -> getCurso(id_curso);
                
                if (temp_cur != nullptr){
                    temp_al = ucn -> getAlumno(id);
                    if (temp_al != nullptr){
                        ucn -> addNota(new Node(nota, id, id_curso));
                    } else {
                        cout << "Error, ID del Alumno inexistente." << endl;
                        break;
                    }
                } else {
                    cout << "Error, ID del Curso inexistente." << endl;
                    break;
                }
                
                cout<<"Nota Agregada."<< endl;
                temp_cur = nullptr;
                temp_al = nullptr;
                break;
            default:
                cout<<"Opción no válida, debe ser un numero del 0 al 6."<< endl;
                break;
        }
        
    } while (int_input != 0);
    return;
}

void menu_cursos(int int_input, string str_input){
    int id = -1;
    string nombre;
    int cap = -1;
    string carrera;
    string profesor;
    
    do {
        cout<<"[Menú Cursos]"<< endl;
        cout<<" "<< endl;
        cout<<"Opciones:"<< endl;
        cout<<"0. Salir."<< endl;
        cout<<"1. Crear Curso."<< endl;
        cout<<"2. Buscar Curso."<< endl;
        cout<<"3. Eliminar Curso."<< endl;
        
        int_input = leer_input_int(int_input);
        
        switch(int_input){
            case 0:
                cout<<"[Menú Cursos Finalizado]"<< endl;
                cout<<" "<< endl;
                break;
            case 1:
                cout<<"Debe ingresar todos los datos necesarios: "<< endl;
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                if(ucn -> getCurso(id) != nullptr){
                    cout<<"ID ya existente, los identificadores únicos no pueden repetirse."<< endl;
                    break;
                }
                
                cout<<"[NOMBRE DEL CURSO]"<< endl;
                nombre = leer_input_str(str_input);
                cout<<"[CAPACIDAD DE ALUMNOS]"<< endl;
                cap = leer_input_int(int_input);
                cout<<"[CARRERA]"<< endl;
                carrera = leer_input_str(str_input);
                cout<<"[PROFESOR]"<< endl;
                profesor = leer_input_str(str_input);
                
                ucn -> addCurso(new Curso(id,nombre,cap,carrera,profesor));
                cout<<"Curso Creado."<< endl;
                break;
            case 2:
                if(ucn -> cursos_start == nullptr){
                    cout<<"No hay cursos."<< endl;
                    break;
                }
                
                do {
                cout<<"Buscar Curso por:"<< endl;
                cout<<"0. Cancelar."<< endl;
                cout<<"1. ID."<< endl;
                cout<<"2. Nombre."<< endl;
                
                int_input = leer_input_int(int_input);
                
                //...
                switch(int_input){
                    case 0:
                        cout<<"[Cancelado]"<< endl;
                        break;
                    case 1:
                        cout<<"[ID ALUMNO]"<< endl;
                        id = leer_input_int(int_input);
                        ucn -> getCurso(id) -> print();
                        break;
                    case 2:
                        cout<<"[NOMBRE]"<< endl;
                        nombre = leer_input_str(str_input);
                        ucn -> print_curso(nombre);
                        break;
                    default:
                        cout<<"Opción no válida, debe ser un numero del 0 al 2."<< endl;
                        break;
                } //...
                
                } while(int_input != 0);
                int_input = 2;
                break;
            case 3:
                if(ucn -> cursos_start == nullptr){
                    cout<<"No hay cursos."<< endl;
                    break;
                }
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                if(ucn -> getCurso(id) == nullptr){
                    cout<<"Error, ID del Curso inexistente."<< endl;
                    break;
                }
                
                ucn -> removerCurso(id);
                cout<<"Curso eliminado."<< endl;
                break;
            default:
                cout<<"Opción no válida, debe ser un numero del 0 al 3."<< endl;
                break;
        }
    } while (int_input != 0);
    return;
}

void menu_reportes(int int_input, string str_input){
    int id = -1;
    int id_curso = -1;
    double promedio = 0.0;
    double promedio_g = 0.0;
    string carrera;
    Curso *temp = nullptr;
    
    do {
        cout<<"[Menú de Consultas y Reportes]"<< endl;
        cout<<" "<< endl;
        cout<<"Opciones:"<< endl;
        cout<<"0. Salir."<< endl;
        cout<<"1. Listar Alumnos en Carrera."<< endl;
        cout<<"2. Cursos en los que un Alumno está inscrito."<< endl;
        cout<<"3. Promedio de Notas de un Alumno en un Curso."<< endl;
        cout<<"4. Promedio de Notas General de un Alumno."<< endl;
        
        int_input = leer_input_int(int_input);
        
        switch(int_input){
            case 0:
                cout<<"[Menú de Consultas y Reportes Finalizado]"<< endl;
                cout<<" "<< endl;
                break;
            case 1:
                if(ucn -> alumnos_start == nullptr) {
                    cout<<"No hay alumnos."<< endl;
                    break;
                }
                cout<<"[CARRERA]"<< endl;
                carrera = leer_input_str(str_input);
                
                ucn -> print_alumnos(carrera);
                break;
            case 2:
                if(ucn -> cursos_start == nullptr){
                    cout<<"No hay Cursos."<< endl;
                    break;
                }
                if(ucn -> alumnos_start == nullptr) {
                    cout<<"No hay Alumnos."<< endl;
                    break;
                }
                
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                if(ucn -> getAlumno(id) == nullptr){
                    cout<<"Error, ID del alumno inexistente."<< endl;
                    break;
                }
                
                ucn -> print_cursos(id);
                break;
            case 3:
                if(ucn -> cursos_start == nullptr){
                    cout<<"No hay Cursos."<< endl;
                    break;
                }
                if(ucn -> alumnos_start == nullptr) {
                    cout<<"No hay Alumnos."<< endl;
                    break;
                }
                if (ucn -> notas_start == nullptr){
                    cout<<"No hay inscripciones ni Notas."<< endl;
                    break;
                }
                
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                if(ucn -> getAlumno(id) == nullptr){
                    cout<<"Error, ID del Alumno inexistente."<< endl;
                    break;
                }
                
                cout<<"[ID CURSO]"<< endl;
                id_curso = leer_input_int(int_input);
                
                temp = ucn -> getCurso(id_curso);
                if(temp == nullptr){
                    cout<<"Error, ID del Curso inexistente."<< endl;
                    break;
                }
                promedio = ucn -> promedio(id,id_curso);
                if(promedio != 0.0){
                    cout<<"Promedio de Notas del Alumno en el Curso " + temp -> getNombre() + ": ";
                    cout<<promedio<< endl;
                } else {
                    cout<<"Error, no hay notas para el Alumno en el Curso " + temp -> getNombre() + "."<< endl;
                }
                temp = nullptr;
                break;
            case 4:
                if(ucn -> cursos_start == nullptr){
                    cout<<"No hay cursos."<< endl;
                    break;
                }
                if(ucn -> alumnos_start == nullptr) {
                    cout<<"No hay alumnos."<< endl;
                    break;
                }
                if (ucn -> notas_start == nullptr){
                    cout<<"No hay inscripciones ni notas."<< endl;
                    break;
                }
                
                cout<<"[ID ALUMNO]"<< endl;
                id = leer_input_int(int_input);
                
                if(ucn -> getAlumno(id) == nullptr){
                    cout<<"Error, ID del Alumno inexistente."<< endl;
                    break;
                }
                
                promedio_g = ucn -> promedio_General(id);
                if(promedio_g != 0.0){
                    cout<<"Promedio General de Notas del Alumno: ";
                    cout<<promedio_g<< endl;
                } else {
                    cout<<"Error, alumno no tiene notas."<< endl;
                }
                break;
            default:
                cout<<"Opción no válida, debe ser un numero del 0 al 4."<< endl;
                break;
        }
        
    } while (int_input != 0);
    return;
}

void menu(){
    cout<<"Datos por defecto: ID's 1 y 2 tanto para Alumnos como para Cursos."<< endl;
    cout<<" "<< endl;
    string str_input;
    int int_input = -1;
    do {
        cout<<"[MENÚ PRINCIPAL]"<< endl;
        cout<<" "<< endl;
        cout<<"Opciones:"<< endl;
        cout<<"0. Salir."<< endl;
        cout<<"1. Manejo de Alumnos."<< endl;
        cout<<"2. Manejo de Cursos."<< endl;
        cout<<"3. Consultas y Reportes."<< endl;
        
        int_input = leer_input_int(int_input);
        
        switch(int_input){
            case 0:
                cout<<"[MENÚ FINALIZADO]"<< endl;
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
                cout<<"Opción no válida, debe ser un numero del 0 al 3."<< endl;
                break;
        }
    } while (int_input != 0);
    return;
}

int main(){
    //Datos por defecto.
    ucn -> cursos_start = new Curso(1, "Programación", 3, "iti","E.d");
    ucn -> cursos_start -> setNext(new Curso(2, "Electrotecnia", 3, "iti","F.d"));
    ucn -> addAlumno(new Alumno(1, "Juan", "Beckios", "iti","2024"));
    ucn -> addAlumno(new Alumno(2, "Helen", "Flores", "iti","2025"));
    
    ucn -> addNota(new Node(0.0, 1, 1));
    ucn -> addNota(new Node(0.0, 1, 2));
    ucn -> addNota(new Node(0.0, 2, 1));
    
    ucn -> addNota(new Node(2.0, 1, 1));
    ucn -> addNota(new Node(6.0, 1, 1));
    ucn -> addNota(new Node(6.0, 1, 2));
    ucn -> addNota(new Node(4.5, 2, 1));
    ucn -> addNota(new Node(7, 2, 1));
    menu();
    return 0;
}
