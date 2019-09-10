#include <stdio.h>
#include <stdlib.h>

#define TAM 5

void mostrarVectorInt(int vec[], int tam);
void ordenarVectorInt(int vec[], int tam, int criterio);

int main()
{
    int numeros[]= {5,7,8,2,6};

    printf("Muestro el vector: \n\n");

    mostrarVectorInt(numeros, TAM);

    printf("Muestro ordenado por criterio acendente: \n\n");
    ordenarVectorInt(numeros, TAM, 0);
    mostrarVectorInt(numeros, TAM);

    printf("Muestro ordenado por criterio decendente: \n\n");
    ordenarVectorInt(numeros, TAM, 1);
    mostrarVectorInt(numeros, TAM);

    return 0;
}

void mostrarVectorInt(int vec[], int tam)
{

    for(int i=0; i < tam; i++)
    {
        printf("%d ", vec[i]);
    }
    printf("\n\n");
}

void ordenarVectorInt(int vec[], int tam, int criterio)
{
    int aux;
    for(int i=0; i < tam-1; i++)
    {
        for(int j=i+1; j < tam; j++)
        {
            if(!criterio)
            {
                if(vec[i] > vec[j])
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
            else
            {
                if(vec[i] < vec[j])
                {
                    aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                }
            }
        }
    }
}

