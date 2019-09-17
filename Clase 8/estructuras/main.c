#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 2

typedef struct{
    int legajo;
    char nombre[20];
    int edad;
    char sexo;
    int nota1;
    int nota2;
    float promedio;
}eAlumno;

void mostrarAlumno( eAlumno al);
void mostrarAlumnos(eAlumno vec[], int tam);



int main()
{
    eAlumno lista[TAM];

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
    }


    mostrarAlumnos(lista, TAM);

    return 0;
}


void mostrarAlumnos(eAlumno vec[], int tam){
    printf(" LEGAJO       NOMBRE     EDAD     SEXO     NOTA 1      NOTA 2       PROMEDIO");

    for(int i=0; i<tam; i++){
        mostrarAlumno(vec[i]);
    }
    printf("\n\n");
}

void mostrarAlumno( eAlumno al){
    printf("%d  %10s      %d      %c     %d      %d    %.2f \n", al.legajo, al.nombre, al.edad, al.sexo, al.nota1, al.nota2, al.promedio);
}


