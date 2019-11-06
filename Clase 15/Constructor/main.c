#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 0


//////////////// ESTRUCTURAS
typedef struct{
    int id;
    char nombre[21];
    float sueldo;
    int estado;
}eEmpleado;


////////////////     PROTOTIPOS
eEmpleado* newEmpleado();
eEmpleado* newEmpleadoParam(int* id, char* nombre, float sueldo);
int inicializarEmpleados(eEmpleado* vec, int tam);
int mostrarEmpleado(eEmpleado* unEmpleado);


//////////////////// MAIN

int main()
{
   // eEmpleado emp1;// DECLARACION ESTATICA
    eEmpleado* lista = (eEmpleado*) malloc(sizeof(eEmpleado)* (TAM +1) );

    if(inicializarEmpleados(lista, TAM)){
        printf("Empleados inicializados\n");
    }
    else{
        printf("NO SE PUDO\n");
    }

    eEmpleado* emp2 = newEmpleado();// DECLARACION DINAMICA

    mostrarEmpleado(emp2);
    // CARGAR VALORES EN LA ESTRUCTURA
    /*
    emp2->id = 1234;
    mostrarEmpleado(emp2);
    printf("Ingrese ID: ");
    scanf("%d", &emp2->id);
    mostrarEmpleado(emp2);
    */

    eEmpleado* emp3 = newEmpleadoParam(255, "Jorge", 34000);

    mostrarEmpleado(emp3);

    *(lista + TAM) = *emp3;

    mostrarEmpleado(lista + TAM);

    return 0;
}

////////////////////////////////////// FUNCIONES
//   FUNCION CONSTRUCTORA
eEmpleado* newEmpleado(){
    eEmpleado* e;
    e= (eEmpleado*) malloc(sizeof(eEmpleado));

    if(e != NULL){
        e->id = 0;
        strcpy(e->nombre, "");
        e->sueldo = 0;
        e->estado = 0;
    }
    return e;
}

/////////////// FUNCIOIN COSTRUCTORA CON PARAMETROS
eEmpleado* newEmpleadoParam(int* id, char* nombre, float sueldo){
    eEmpleado* e = newEmpleado();

    if(e != NULL){
        e->id = id;
        strcpy(e->nombre, nombre);
        e->sueldo = sueldo;
        e->estado=0;
    }
    return e;
}

int inicializarEmpleados(eEmpleado* vec, int tam){
    int todoOk = 0;
    if(vec != NULL && tam >= 0){
        for(int i=0; i<tam; i++){
            (vec + i)->estado = 0;
        }
        todoOk = 1;
    }
    return todoOk;
}

int mostrarEmpleado(eEmpleado* unEmpleado){
    int todoOk=0;
    if(unEmpleado != NULL){
        printf("  %d   %s   %.2f \n\n", unEmpleado->id, unEmpleado->nombre, unEmpleado->sueldo);
        todoOk=1;
    }
    return todoOk;
}






