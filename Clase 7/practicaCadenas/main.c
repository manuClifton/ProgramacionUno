#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[20];
    char apellido[20];
    char comaEspacio[3]= ", ";
    char nombreCompleto[41];

    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s", nombre);
    strlwr(nombre);
    nombre[0] = toupper(nombre[0]);

    printf("Ingrese apellido: ");
    fflush(stdin);
    scanf("%s", apellido);
    strlwr(apellido);
    apellido[0] = toupper(apellido[0]);


    if(strlen(nombre)+strlen(apellido)+strlen(comaEspacio)<41){
        strcat(nombreCompleto, nombre);
        strcat(nombreCompleto, comaEspacio);
        strcat(nombreCompleto, apellido);
        printf("%s\n", nombreCompleto);
    }
    else{
        printf("No se cargo el nombre");
    }


    return 0;
}
