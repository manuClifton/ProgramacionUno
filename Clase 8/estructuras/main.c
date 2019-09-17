#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 4

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
    eFecha fechaIngreso;
}eAlumno;

void mostrarAlumno( eAlumno al);
void mostrarAlumnos(eAlumno vec[], int tam);
void sortAlumnosLeg(eAlumno vec[], int tam, int criterio);
void sortAlumnosNombre( eAlumno vec[], int tam, int criterio);
void sortAlumnosFecha(eAlumno vec[], int tam, int criterio);
int compararFecha(eFecha f1, eFecha f2);


int main()
{
    eAlumno listaAlumnos[TAM] = {
        {1354, "anuel", 25, 'M', 8, 9, 8.5, {12,4,2019} },
        {1267, "Lucia", 27, 'F', 8, 8, 8, {15,7,2019} },
        {1464, "Florencia", 22, 'F', 8, 9, 8.5, {3,4,2019} },
        {1154, "Eduardo", 23, 'M', 8, 9, 8.5, {5,7,2018} }
    };

    /*
    for(int i=0; i<TAM; i++){
        printf("Ingrese Legajo: ");
        scanf("%d", &lista[i].legajo);

        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);

        printf("Ingrese edad: ");
        scanf("%d", &lista[i].edad);

        printf("Ingrese Sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);

        printf("Ingrese Nota 1: ");
        scanf("%d", &lista[i].nota1);

        printf("Ingrese Nota 2: ");
        scanf("%d", &lista[i].nota2);


        lista[i].promedio = (float) (lista[i].nota1 + lista[i].nota2) / TAM;
        system("cls");
    }*/


    mostrarAlumnos(listaAlumnos, TAM);

    sortAlumnosLeg(listaAlumnos, TAM, 1);// 1 ASCENDENTE o 0 DESCENDENTE
    mostrarAlumnos(listaAlumnos, TAM);

    sortAlumnosNombre(listaAlumnos, TAM, 0);// 1 ASCENDENTE o 0 DESCENDENTE
    mostrarAlumnos(listaAlumnos, TAM);

    sortAlumnosFecha(listaAlumnos, TAM, 0);
     mostrarAlumnos(listaAlumnos, TAM);

    return 0;
}


void mostrarAlumnos(eAlumno vec[], int tam){
    printf("\n LEGAJO     NOMBRE      EDAD   SEXO   NOTA 1    NOTA 2     PROMEDIO    FECHA INGRESO \n");
    printf("***********************************************************************************\n");

    for(int i=0; i<tam; i++){
        mostrarAlumno(vec[i]);
    }
    printf("\n\n");
}

void mostrarAlumno( eAlumno al){
    printf("%6d  %10s      %2d    %3c       %d    %6d    %8.2f       %02d/%02d/%d \n", al.legajo, al.nombre, al.edad, al.sexo, al.nota1, al.nota2, al.promedio, al.fechaIngreso.dia, al.fechaIngreso.mes, al.fechaIngreso.anio );
}


void sortAlumnosLeg(eAlumno vec[], int tam, int criterio){
    eAlumno auxCad;

        for(int i=0; i<tam-1; i++){
            for(int j=i+1; j<tam; j++){
                if(vec[i].legajo > vec[j].legajo && criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
                else if(vec[i].legajo < vec[j].legajo && !criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
            }
        }
}

void sortAlumnosNombre( eAlumno vec[], int tam, int criterio){
    eAlumno auxCad;

        for(int i=0; i<tam-1; i++){
            for(int j=i+1; j<tam; j++){
                if(stricmp(vec[i].nombre, vec[j].nombre) > 0 && criterio ){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
                else if(stricmp(vec[i].nombre, vec[j].nombre) < 0 && !criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
            }
        }
}

void sortAlumnosFecha(eAlumno vec[], int tam, int criterio){
    eAlumno auxCad;

        for(int i=0; i<tam-1; i++){
            for(int j=i+1; j<tam; j++){
                if( compararFecha(vec[i].fechaIngreso, vec[j].fechaIngreso) > 0 && criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
                else if( compararFecha(vec[i].fechaIngreso, vec[j].fechaIngreso) < 0 && !criterio){
                    auxCad = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxCad;
                }
            }
        }
}


/* Función comparaFecha, devuelve:
   -1 si fecha1 < fecha2
   0 si fecha1 = fecha2
   1 si fecha1 > fecha2
*/
int compararFecha(eFecha f1, eFecha f2){
    int rta;

        if(f1.anio < f2.anio){
            rta = -1;
        }
        else if(f1.anio > f2.anio){
            rta = 1;
        }
         else {
            if(f1.mes < f2.mes){
                rta = -1;
            }
            else if( f1.mes > f2.mes ){
                 rta = 1;
            }
            else{
                if(f1.dia < f2.dia){
                     rta = -1;
                }
                else if ( f1.dia > f2.dia ){
                    rta = 1;
                }
                else{
                    rta = 0;
                }
            }
    }

    return rta;
}

