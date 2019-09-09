#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectorInt(int vec[], int tam);
int obtenerMayor(int vec[], int tam);
void obtenerIndice(int vec[]n int tam, int num);


int main()
{
    int numeros[5];
    int suma = 0;
    int max;
    int index;

    for(int i = 0; i < 5; i++){
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
    }
    mostrarVectorInt(numeros, 5);
    /*
    for(int i = 0; i < 5; i++){
        printf(" %d ", numeros[i]);
        if(max <= numeros[i]){
                max = numeros[i];
                index = i;
            }
    }*/
    max = obtenerMayor(numeros, 5);
    obtenerIndice(numeros, TAM, max)

    for(int i = 0; i < 5; i++){
        suma += numeros[i];
    }
        printf("\n la suma es: %d", suma);

        printf("\n el maximo es %d y el indice es %d", max, index);

    return 0;
}

void mostrarVectorInt(int vec[], int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", vec[i]);

    }
    printf("\n\n");
}

int obtenerMayor(int vec[], int tam){
    int max;
    int flag = 0;

        for(int i=0; i<5; i++){
            if(max < vec[i] || flag == 0){
                max = vec[i];
                flag = 1;
            }
        }
    return max;
}

void obtenerIndice(int vec[] int tam, int num){
    int index;
     for(int i=0; i<tam; i++){
        if( vec[i] = num){
            index = i;
        }


}
