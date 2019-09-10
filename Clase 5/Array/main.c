#include <stdio.h>
#include <stdlib.h>

#define TAM 3

void pedirVector(int vec[], int tam);
void mostrarVectorInt(int vec[], int tam);
int sumarVector(int vec[], int tam);
int obtenerMayor(int vec[], int tam);
int obtenerIndice(int vec[], int tam, int num);


int main()
{
    int numeros[TAM];
    int suma;
    int max;
    int index;

    pedirVector(numeros, TAM);
    mostrarVectorInt(numeros, TAM);
    max = obtenerMayor(numeros, TAM);
    index = obtenerIndice(numeros, TAM, max);
    suma = sumarVector(numeros, TAM);

    printf("\n la suma es: %d", suma);

    printf("\n el maximo es %d y el indice es %d", max, index);

    return 0;
}// FIN MAIN

void pedirVector(int vec[], int tam){
    for(int i = 0; i < tam; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &vec[i]);
    }
}


void mostrarVectorInt(int vec[], int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", vec[i]);

    }
    printf("\n\n");
}

int sumarVector(int vec[], int tam){
    int suma = 0;
     for(int i = 0; i < tam; i++){
            suma =  suma + vec[i];
            printf("%d", vec[i]);
        }
    return suma;
}

int obtenerMayor(int vec[], int tam){
    int max;
    int flag = 0;

        for(int i=0; i<tam; i++){
            if(max < vec[i] || flag == 0){
                max = vec[i];
                flag = 1;
            }
        }
    return max;
}

int obtenerIndice(int vec[], int tam, int num){
    int index = -1;
     for(int i=0; i<tam; i++){
        if( vec[i] == num){
            index = i+1;
        }
 }
 return index;
}
