#include <iostream>
#include "Sequential/Sequential_file.h"
using namespace std;

void print_vec(vector<Estudiante> vec){
    for(auto i : vec){
        i.print();
    }
}

//LOS REGISTROS DEL DATA SET DEBEN DE ESTAR ORDENADOS

int main(){
    Sequential_File seq("Sequential/Estudiantes.bin", "Sequential/SequentialEstudiante.bin");
    seq.insert(Estudiante(11,"Masculino","Juan","Sara",19,"Industrial",3));
    seq.insert(Estudiante(12,"Masculino","Alonso","Junco",29,"CS",6));
    seq.insert(Estudiante(13,"Femenino","Karla","Tarazona",7,"DS",7));
    seq.insert(Estudiante(14,"Femenino","Marcia","Valverde",23,"Mecanica",4));
    seq.insert(Estudiante(15,"Masculino","Diego","Landauri",54,"Minas",2));
    seq.insert(Estudiante(16,"Femenino","Alondra","Palacios",32,"Energia",10));
    seq.insert(Estudiante(17,"Masculino","Heider","Sanchez",4,"Electronica",7));
    seq.insert(Estudiante(18,"Femenino","Valeria","Gonzales",56,"Comunicaciones",8));
    vector<Estudiante> estudiantes = seq.load();
    print_vec(estudiantes);
    cout<<"-------------------EMPIEZA EL SEARCH---------------"<<endl;
    Estudiante es = seq.search(3);
    es.print();
    cout<<"-------------------TERMINO EL SEARCH---------------"<<endl;
    cout<<"-------------------EMPIEZA EL RANGE SEARCH---------------"<<endl;
    vector<Estudiante> vec = seq.range_search(14,21);
    print_vec(vec);
    cout<<"-------------------TERMINO EL RANGE SEARCH----------------"<<endl;
}