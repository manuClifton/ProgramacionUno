#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    /////////////////////// GUARDAR EN UN ARCHIVO
    /*
    FILE* f;

    char nombre[]= " carlos";

    //f = fopen("archivo.txt", "w");
    f = fopen("archivo.txt", "a");

    if(f == NULL){
        printf("NO SE PUDO ABRIR EL ARCHIVO");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //fprintf(f, nombre);

    fwrite(nombre, sizeof(char), strlen(nombre), f);
    //fread(nombre, sizeof(char), strlen(nombre), f);
    fclose(f);
    */


    FILE* f;

    char nombre[]= " carlos";
    char nombre2[20];

    f = fopen("archivo.txt", "r");

    if(f == NULL){
        printf("NO SE PUDO ABRIR EL ARCHIVO");
        system("pause");
        exit(EXIT_FAILURE);
    }

    //fprintf(f, nombre);

    //fwrite(nombre, sizeof(char), strlen(nombre), f);

    while(!feof(f)){// mientras no llege al final del archivo entra
        fread(nombre, sizeof(char), 20, f);
        printf(" %s", nombre2);
    }

    fgetc();
    fgets();

    fscanf();



    fclose(f);


    return 0;
}
