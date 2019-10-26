#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *aux;
    int* numeros = (int*) malloc(sizeof(int)*5);

    for(int i=0; i<5; i++){
        printf("Ingrese un numero: ");
            scanf("%d", numeros + i);
    }

    for(int i=0; i<5; i++){
        printf("%d  ", *(numeros + i) );// el ASTERISCO MUSTRA EL VALOR DENTRO DE ESA DIRECCION DE MEMORIA
    }

    //  REALOC PARA MAS MEMORIA
    aux = realloc(numeros, sizeof(int)*10);
    if(aux != NULL){
        numeros = aux;
    }

    for(int i=0; i<5; i++){
        printf("Ingrese un numero: ");
            scanf("%d", numeros + i);
    }

    for(int i=0; i<10; i++){
        printf("%d  ", *(numeros + i) );// el ASTERISCO MUSTRA EL VALOR DENTRO DE ESA DIRECCION DE MEMORIA
    }

    // REALOC PARA MENOS MEMORIA
    numeros = (int*) realloc( numeros, sizeof(int)*6);

     for(int i=0; i<6; i++){
        printf("%d  ", *(numeros + i) );// el ASTERISCO MUSTRA EL VALOR DENTRO DE ESA DIRECCION DE MEMORIA
    }

    free(numeros);
    return 0;
}
