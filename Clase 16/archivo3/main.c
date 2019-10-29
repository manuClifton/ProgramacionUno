#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[20];
    char apellido[20];
    float sueldo;
}eEmpleado;

eEmpleado* newEmpleado();

int main()
{
    eEmpleado* lista[50];
    eEmpleado* emple;
    int i=0;

    FILE* miArchivo;
    char legajo[10];
    char nombre[20];
    char apellido[20];
    char sueldo[20];

    miArchivo = fopen("datos.csv", "r");

    if(miArchivo != NULL){

        fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n] \n", legajo, nombre, apellido, sueldo);
        printf(" %2s %10s %10s %10s  \n",  legajo, nombre, apellido, sueldo);

        while(!feof(miArchivo)){

            fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n] \n", legajo, nombre, apellido, sueldo);

            emple = newEmpleado();

            emple->legajo = atoi(legajo);
            emple->sueldo = atof(sueldo);
            strcpy(emple->nombre, nombre);
            strcpy(emple->apellido, apellido);


            //lista[i] = emple;
            *(lista+i) = emple;
            i++;
        }
        fclose(miArchivo);

        for(int i=0; i<50; i++){
            printf(" %2d    %10s    %10s     %.2f  \n", lista[i]->legajo, lista[i]->nombre, lista[i]->apellido, lista[i]->sueldo);
        }
    }

    return 0;
}

//////////// CONSTRUCTOR
eEmpleado* newEmpleado(){
    eEmpleado* e;

    e= (eEmpleado*) malloc(sizeof(eEmpleado));
    return e;
}










