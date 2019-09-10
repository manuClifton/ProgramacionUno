#include <stdio.h>
#include <stdlib.h>

#define TAM 2

void mostrarAlumnos(int legs[], int ages[], char sexos[], int n1[], int n2[], float promedios[],  int tam);
void mostrarAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio);
int main()
{
    int legajos[TAM];
    int edades[TAM];
    int nota1[TAM];
    int nota2[TAM];
    float promedios[TAM];
    char sexos[TAM];

    for(int i=0; i<TAM; i++){

        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese edad: ");
        scanf("%d", &edades[i]);

        printf("Ingrese nota 1: ");
        scanf("%d", &nota1[i]);

        printf("Ingrese nota 2: ");
        scanf("%d", &nota2[i]);

        promedios[i] = (float) (nota1[i] + nota2[i]) / 2;
        system("cls");
    }

    mostrarAlumnos(legajos, edades, sexos, nota1, nota2, promedios, TAM);

    return 0;
}

void mostrarAlumnos(int legs[], int ages[], char sexos[], int n1[], int n2[], float promedios[],  int tam){

    printf("\n LEGAJO   SEXO   EDAD    NOTA 1    NOTA 2     PROMEDIO\n\n");

    for(int i=0; i<TAM; i++){
        mostrarAlumno(legs[i],sexos[i], ages[i], n1[i], n2[i], promedios[i]);
    }
    printf("\n\n");
}

void mostrarAlumno(int legajo, int edad, char sexo, int nota1, int nota2, float promedio){

     printf("  %5d     %4c     %4d    %5d     %5d     %5.2f\n\n", legajo, sexo, edad, nota1, nota2, promedio);
}









