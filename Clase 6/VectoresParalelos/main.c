#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarAlumnos(int legs[], char sexos[], int ages[], int n1[], int n2[], float promedios[],  int tam);
void mostrarAlumno(int legajo, char sexo, int edad, int nota1, int nota2, float promedio);
void sortAlumnos(int legs[], char sexos[], int ages[], int nota1[], int nota2[], float promedios[],  int tam, int criterio);

int main()
{
    int legajos[TAM] = {123, 124, 125, 126, 127};
    int edades[TAM] = {30, 23 ,45, 32, 19};
    int nota1[TAM] = {8, 9 ,10, 2, 3};
    int nota2[TAM] = {8, 9 ,10, 2, 3};
    float promedios[TAM] = {8, 9, 10, 2, 3};
    char sexos[TAM] = {'f', 'm', 'f', 'm', 'f'};

    /*for(int i=0; i<TAM; i++){

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
    }*/

    mostrarAlumnos(legajos, sexos, edades, nota1, nota2, promedios, TAM);

    sortAlumnos(legajos, sexos, edades, nota1, nota2, promedios, TAM, 0);
    mostrarAlumnos(legajos, sexos, edades, nota1, nota2, promedios, TAM);

    return 0;
}

void mostrarAlumnos(int legs[], char sexos[], int ages[], int n1[], int n2[], float promedios[],  int tam){

    printf("\n LEGAJO   SEXO   EDAD    NOTA 1    NOTA 2     PROMEDIO\n\n");

    for(int i=0; i<tam; i++){
        mostrarAlumno(legs[i],sexos[i], ages[i], n1[i], n2[i], promedios[i]);
    }
    printf("\n\n");
}

void mostrarAlumno(int legajo, char sexo, int edad, int nota1, int nota2, float promedio){

     printf("  %2d     %2c     %3d    %5d     %5d     %10.2f\n\n", legajo, sexo, edad, nota1, nota2, promedio);
}

void sortAlumnos(int legs[], char sexos[], int ages[], int nota1[], int nota2[], float promedios[],  int tam, int criterio){

    int auxLegs;
    char auxSex;
    int auxAges;
    int auxN1;
    int auxN2;
    float auxProm;

    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(legs[i] < legs[j] && !criterio){
                auxLegs = legs[i];
                legs[i] = legs[j];
                legs[j] = auxLegs;

                auxSex = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxSex;

                auxAges = ages[i];
                ages[i] = ages[j];
                ages[j] = auxAges;

                auxN1 = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxN1;

                auxN2 = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxN2;

                auxProm = promedios[i];
                promedios[i] = promedios[j];
                promedios[j] = auxProm;
            }
            else if(legs[i] > legs[j] && !criterio){
                auxLegs = legs[i];
                legs[i] = legs[j];
                legs[j] = auxLegs;

                auxSex = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxSex;

                auxAges = ages[i];
                ages[i] = ages[j];
                ages[j] = auxAges;

                auxN1 = nota1[i];
                nota1[i] = nota1[j];
                nota1[j] = auxN1;

                auxN2 = nota2[i];
                nota2[i] = nota2[j];
                nota2[j] = auxN2;

                auxProm = promedios[i];
                promedios[i] = promedios[j];
                promedios[j] = auxProm;
            }
        }
    }
}






