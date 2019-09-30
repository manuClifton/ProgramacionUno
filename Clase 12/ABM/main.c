#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "carrera.h"
#include "alumno.h"
#include "biblioteca.h"
#include "Informes.h"

#define TAM 10
#define TAMC 3
#define TAMCOM 5
#define TAMALM 10

// ESTRUCTURAS
typedef struct{
    int id;
    char descripcion[20];
    float precio;
}eComida;

typedef struct{
    int id;
    int legajo;
    int idComida;
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;

////////////////////////////////// PROTOTIPOS

int menu();
void mostrarComida(eComida comida);
void mostrarComidas(eComida comidas[], int tam);
int cargarDescComida(int id, eComida comidas[], int tam, char desc[]);


void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam);
int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad);
void mostrarAlmuerzos(eAlmuerzo almuerzos[],int tam, eComida comidas[], int tamC);
void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamC);
int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam);
eAlmuerzo newAlmuerzo(int id, int idComida, int legajo, eFecha fecha);
int altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eAlumno alumnos[], int tamAlumno, eCarrera carreras[], int tamCarr);


//////////////////////////////// MAIN
int main()
{
    int legajo = 20000;
    int idAlmuerzo = 60000;



    eCarrera carreras[TAMC]={{1000,"TUP"},{1001,"TUSI"},{1002,"LIC"}};

    eComida comidas[TAMCOM] = {
        {5000, "Bife", 250},
        {5001, "Fideos", 200},
        {5002, "Pizza", 190},
        {5003, "Arroz", 200},
        {5004, "Milanesa", 220}
    };

    eAlmuerzo almuerzos[TAMALM];

    eAlumno lista[TAM];

    inicializarAlumnos(lista, TAM);

    inicializarAlmuerzos(almuerzos, TAMALM);

    legajo = legajo + hardcodearAlumnos(lista, TAM, 6);
    idAlmuerzo = idAlmuerzo + hardcodearAlmuerzos(almuerzos, TAMALM, 6);

    char salir = 'n';

    do{

        switch(menu()){

        case 1:
            //  ALTA ALUMNO
            if(altaAlumno(lista, TAM, legajo, carreras, TAMC)){
                legajo++;
            }

            break;
        case 2:
           //  BAJA ALUMNJO
            bajaAlumno(lista, TAM, carreras, TAMC);
            break;
        case 3:
            // MODIFICAR ALUMNO
            modificarAlumno(lista, TAM, carreras, TAMC);
            break;
        case 4:
            // MOSTRAR ALUMNOS
            mostrarAlumnos(lista, TAM, carreras, TAMC);
            break;
        case 5:
            // ORDENAR ALUMNOS
            ordenarAlumnos(lista, TAM);
            break;
        case 6:
            // IFORMES
            mostrarInformes(lista, TAM, carreras, TAMC);
            break;
        case 7:
            // MOSTRAR CARRERAS
            mostrarCarreras(carreras, TAMC);
            break;
        case 8:
            // MOSTRAR comidas
            mostrarComidas(comidas, TAMCOM);
            break;
         case 9:
            // MOSTRAR ALMUERZO
            mostrarAlmuerzos(almuerzos, TAMALM, comidas, TAMCOM);
            break;
         case 10:
               if(altaAlmuerzo(idAlmuerzo, almuerzos, TAMALM, comidas, TAMCOM, lista, TAM, carreras, TAMC)){
                    idAlmuerzo++;
                }
            break;
        case 11:
            printf("Confirma Salir?  ");
            fflush(stdin);
            salir = getchar();
            salir = tolower(salir);
            printf("\n\n");
            break;


        default:
            printf("Opcion invalida.");
            break;
        }

        system("pause");
    }while(salir == 'n');



    return 0;
}


int menu(){

    int opcion;

    system("cls");

    printf("\n***** ABM de Alumnos  ********\n\n");
    printf("1- Alta \n");
    printf("2- Baja \n");
    printf("3- Modificar  \n");
    printf("4- Mostrar Alumnos \n");
    printf("5- Ordenar Alumnos \n");
    printf("6- Informes \n");
    printf("7- Listar CARRERAS \n");
    printf("8- Mostrar Comidas \n");
    printf("9- Mostrar Almuerzos \n");
    printf("10- aLTA Almuerzos \n");
    printf("11- Salir \n");


    getIntRange(&opcion, "Ingrese Opcion: ", "Error. Ingrese un entero entre 1 y 8: ", 1, 11);

    return opcion;
}

void mostrarComida(eComida comida){
    printf(" %d   %s      %.2f  \n\n", comida.id,  comida.descripcion, comida.precio);
}

void mostrarComidas(eComida comidas[], int tam){
    system("cls");

    printf("\n COMIODA   PRECIO \n");
    printf("**********************\n");

    for(int i=0; i<tam; i++){
        mostrarComida(comidas[i]);
    }
}


int cargarDescComida(int id, eComida comidas[], int tam, char desc[]){
    int todoOk = 0;

    for(int i=0; i < tam; i++){
        if( id == comidas[i].id){
            strcpy(desc, comidas[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}

void inicializarAlmuerzos(eAlmuerzo almuerzos[], int tam){
    for(int i=0; i<tam; i++){
        almuerzos[i].isEmpty = 1;
    }
}




int hardcodearAlmuerzos( eAlmuerzo vec[], int tam, int cantidad){
    int cont = 0;

    eAlmuerzo suplentes[]=
    {
        { 60000, 20000, 5000, {12, 10, 2019}, 0},
        { 60001, 20001, 5001, {10, 10, 2019}, 0},
        { 60002, 20002, 5002, { 9, 10, 2019}, 0},
        { 60003, 20003, 5003, { 2, 10, 2019}, 0},
        { 60004, 20004, 5004, { 1, 10, 2019}, 0},
        { 60005, 20005, 5001, {20, 10, 2019}, 0},
        { 60006, 20006, 5002, {17, 10, 2019}, 0},
        { 60007, 20007, 5003, {21, 10, 2019}, 0},
        { 60008, 20008, 5004, {14, 10, 2019}, 0},
        { 60009, 20009, 5005, {12, 10, 2019}, 0},
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {
            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

void mostrarAlmuerzo(eAlmuerzo almuerzo, eComida comidas[], int tamC){
    char descComida[20];

    cargarDescComida(almuerzo.idComida, comidas, tamC, descComida );

    printf(" %d      %10s       %2d       %d/%d/%d \n\n", almuerzo.id, descComida, almuerzo.legajo, almuerzo.fecha.dia, almuerzo.fecha.mes, almuerzo.fecha.anio);
}


void mostrarAlmuerzos(eAlmuerzo almuerzos[],int tam, eComida comidas[], int tamC){

    int flag = 0;

    system("cls");

    printf("\n  ID            COMIDA      LEGAJO       FECHA\n");
    printf("************************************************\n");


    for(int i=0; i<tam; i++){
        if(almuerzos[i].isEmpty == 0){
           mostrarAlmuerzo(almuerzos[i], comidas, tamC);
           flag = 1;
        }

    }
    if(flag == 0){
        printf("No hay almuerzos que mostrar");
    }
    printf("\n\n");
}




int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam){
    int indice = -1;

    for(int i=0; i<tam; i++){
        if(vec[i].isEmpty == 1){
            indice = i;
            break;
        }
    }
    return indice;
}





int altaAlmuerzo(int idAlmuerzo, eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eAlumno alumnos[], int tamAlumno, eCarrera carreras[], int tamCarr){
    int todoOk = 0;
    int indice;

    int legajo;
    eFecha fecha;
    int idComida;

        system("cls");
        printf("******* ALTA ALMUERZO *******\n\n");

        indice = buscarAlmuerzoLibre(almuerzos, tamAlm);

        if(indice == -1){
            printf("NO HAY LUGAR EN EL SISTEMA \n\n");
        }
        else{
                mostrarAlumnos(alumnos, tamAlumno, carreras, tamCarr);

                printf("Ingrese Legajo: ");
                scanf(" %d", &legajo);

                mostrarComidas(comidas, tamCom);

                printf("Ingrese id comida: ");
                scanf(" %d", &idComida);


                printf("Ingrese Fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio );

                almuerzos[indice] = newAlmuerzo(idAlmuerzo, idComida, legajo, fecha);

                todoOk = 1;
                if(todoOk){
                    printf("\n\nALTA ALMUERZO EXITOSA !!! \n\n");
                }
        }

    return todoOk;
}

eAlmuerzo newAlmuerzo(int id, int idComida, int legajo, eFecha fecha){
    eAlmuerzo al;

    al.id = id;
    al.idComida = idComida;
    al.legajo = legajo;
    al.fecha = fecha;
    al.isEmpty = 0;

    return al;
}













