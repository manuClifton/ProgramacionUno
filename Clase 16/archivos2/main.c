#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////// ESTRUCTURAS

typedef struct{
    int legajo;
    char nombre[30];
    float salario;
}eEmpleado;


////////////////////// PROTOTIPOS
void escribirBinario(char* path);
void leerBinario(char* path);


/////////////////////////// MAIN

int main()
{

    escribirBinario("miEmpleado.bin");
    leerBinario("miEmpleado.bin");

    return 0;
}



void escribirBinario(char* path){

    int len = 2;
    char nombre[4]="Loco";
    eEmpleado miEmpleado[2]= {
        {100, "pepe", 1000},
        {101, "pompin", 1500}
    };

    FILE* miArchivo;

    miArchivo = fopen(path, "wb");

    if(miArchivo != NULL){
        fwrite(&len, sizeof(int), 1, miArchivo);
        //fwrite(nombre, sizeof(strlen(nombre)), 4, miArchivo);
        for(int i=0; i<len; i++){
            fwrite(&miEmpleado[i], sizeof(eEmpleado), 1, miArchivo);

        }
        fclose(miArchivo);
    }
}

void leerBinario(char* path){
    int len;

    eEmpleado miEmpleado[2];
    FILE* miArchivo;

    miArchivo = fopen(path,"rb");

    if(miArchivo != NULL){
        fread(&len, sizeof(int), 1, miArchivo);
        printf("%d\n", len);
        fread(miEmpleado, sizeof(eEmpleado), len, miArchivo);

        for(int i=0; i<len; i++){
            printf("%d  %s  %.2f\n", miEmpleado[i].legajo, miEmpleado[i].nombre, miEmpleado[i].salario);
        }


        fclose(miArchivo);
    }

}




