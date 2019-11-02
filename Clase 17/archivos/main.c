#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define TAM 1

///////////////////////// ESTRUCTURAS
typedef struct{
    int id;  // ENTRE 1000 Y 2000
    char marca[30];
    int modelo;
    float precio;
}eAuto;

///////////////////////// PROTOTIPOS
//Constructores
eAuto* new_Auto();
eAuto* new_AutoParam(int id, char*marca, int modelo, float precio);

// COMPARISON

int guardarAutosBinario(eAuto** lista, int tam, char* path);

int guardarAutosCSV(eAuto** lista, int tam, char* path);
// Mostrar
int mostrarAuto(eAuto* unAuto);
int mostrarAutos(eAuto** autos, int tam);

// Getters y Setters
float getPrecioAuto(eAuto* unAuto);
int setPrecioAuto(eAuto* unAuto, float precio);

int getModeloAuto(eAuto* unAuto);
int setModeloAuto(eAuto* unAuto, int modelo);

int setMarcaAuto(eAuto* unAuto, char* marca);
int getMarcaAuto(eAuto* unAuto, char* marca);

int getIdAuto(eAuto* unAuto);
int setIdAuto(eAuto* unAuto, int id);

////////////////////////// MAIN

int main()
{
    int tam = 0;
    int cant = 0;
    char buffer[4][30];

    FILE* f = NULL;
    eAuto* autoAux = NULL;

    eAuto** auxLista = NULL;
    eAuto** lista = (eAuto**) malloc(sizeof(eAuto*));

        if(lista == NULL){
            printf("NO HAY MEMORIA PERROOOO\n\n");
            system("pause");
            exit(EXIT_FAILURE);
        }

        f = fopen("autos.csv", "r");

        if(f == NULL){
            printf("NO SE PUDO ABRIR EL ARCHIVO\n\n");
            system("pause");
            exit(EXIT_FAILURE);
        }

        fscanf(f, "%[^,],%[^,],%[^,],%[^\n] \n", buffer[0], buffer[1], buffer[2], buffer[3]);

        while(!feof(f)){
            cant = fscanf(f, "%[^,],%[^,],%[^,],%[^\n] \n", buffer[0], buffer[1], buffer[2], buffer[3]);
            if(cant < 4){
                break;
            }
            else{
                autoAux = new_AutoParam(atof(buffer[0]), buffer[1], atoi(buffer[2]), atof(buffer[3]) );
                if(autoAux != NULL){
                    *(lista + tam) = autoAux;
                    tam++;
                    auxLista = (eAuto**) realloc(lista, sizeof(eAuto*) * (tam + 1) );
                    if(auxLista != NULL){
                        lista = auxLista;
                    }
                }
            }
        }

        fclose(f);

        mostrarAutos(lista, tam);

        ///////////////////////////////////////////// ABRIR EN BINARIO
        if(guardarAutosBinario(lista, tam,"autos.bin")){
            printf("AUTOS CARGADOS EN ARCHIVO BINARIO");
        }
        else{
            printf("NO SE PUDIERON CARGAR LOS AUTOS EN ARCHIVO BINARIO");
        }


        ///////////////////////////////////// LEEER EN BINARIO
        // DECLARO
        int tam2 = 0;
       // int cant2 = 0;
        eAuto** lista2 = (eAuto**) malloc(sizeof(eAuto*));

        if(lista2 == NULL){
            printf("NO HAY MEMORIA PERROOOO\n\n");
            system("pause");
            exit(EXIT_FAILURE);
        }
        /// leer dato
        f = fopen("autos.bin", "rb");

        if(f == NULL){
            printf("NO SE PUDO ABRIR EL ARCHIVO BINARIO\n\n");
            system("pause");
            exit(EXIT_FAILURE);
        }

        while(!feof(f)){

            eAuto* auxAuto = new_Auto();

            if(auxAuto == NULL){
                break;
            }

            cant = fread(   auxAuto ,sizeof(eAuto), 1, f);

            if(cant < 1){
                break;
            }

            else{
                    *(lista2 + tam2) = autoAux;
                    tam2++;
                    auxLista = (eAuto**) realloc(lista2, sizeof(eAuto*) * (tam + 1) );
                    if(auxLista != NULL){
                        lista = auxLista;
                    }
            }
        }

        fclose(f);

        mostrarAutos(lista2, tam2);




    return 0;
}

////////////////////////// DESARROLLO

int setIdAuto(eAuto* unAuto, int id){
    int todoOk = 0;

    if(unAuto != NULL && id >= 1000 && id <= 2000){
        unAuto->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int getIdAuto(eAuto* unAuto){
    int id = -1;

    if(unAuto != NULL){
        id = unAuto->id;
    }
    return id;
}

int setMarcaAuto(eAuto* unAuto, char* marca){
    int todoOk = 0;

    if(unAuto != NULL && marca != NULL && strlen(marca) >= 3){
        strcpy(unAuto->marca, marca);
        todoOk = 1;
    }
    return todoOk;
}

int getMarcaAuto(eAuto* unAuto, char* marca){
    int todoOk = 0;

    if(unAuto != NULL && marca != NULL ){
        strcpy(marca, unAuto->marca);
        todoOk = 1;
    }
    return todoOk;
}

int setModeloAuto(eAuto* unAuto, int modelo){
    int todoOk = 0;

    if(unAuto != NULL && modelo >= 1960 && modelo <= 3000){
        unAuto->modelo = modelo;
        todoOk = 1;
    }
    return todoOk;
}

int getModeloAuto(eAuto* unAuto){
    int modelo = -1;

    if(unAuto != NULL){
        modelo = unAuto->modelo;
    }
    return modelo;
}


int setPrecioAuto(eAuto* unAuto, float precio){
    int todoOk = 0;

    if(unAuto != NULL){
        unAuto->precio = precio;
        todoOk = 1;
    }
    return todoOk;
}

float getPrecioAuto(eAuto* unAuto){
    float precio = -1;

    if(unAuto != NULL){
        precio = unAuto->precio;
    }
    return precio;
}

int mostrarAuto(eAuto* unAuto){
    int todoOk = 0;

    if(unAuto != NULL){
        printf("  %d  %20s  %d  %6.2f\n ", unAuto->id, unAuto->marca, unAuto->modelo, unAuto->precio);
        todoOk = 1;
    }
    return todoOk;
}


int mostrarAutos(eAuto** autos, int tam){
    int todoOk = 0;

    if(autos != NULL){

        for(int i=0; i<tam; i++){
             mostrarAuto( *(autos+i) );
        }

        todoOk = 1;
    }
    return todoOk;
}

eAuto* new_Auto(){
    eAuto* a;
    a= (eAuto*) malloc(sizeof(eAuto));

    if(a != NULL){
         a->id = 0;
        strcpy(a->marca, "");
        a->modelo = 0;
        a->precio = 0;
    }
    return a;
}

eAuto* new_AutoParam(int id, char*marca, int modelo, float precio){
    eAuto* nuevo = new_Auto();

    if(nuevo != NULL){
        if( setIdAuto(nuevo, id)
            && setModeloAuto(nuevo, modelo)
            && setMarcaAuto(nuevo, marca)
            && setPrecioAuto(nuevo, precio) == 0 )
        {
            free(nuevo);
            nuevo = NULL;
        }
    }
    return nuevo;
}

int guardarAutosBinario(eAuto** lista, int tam, char* path){
    int todoOk = 0;
    FILE* f = NULL;

    if(lista != NULL && tam > 0 && path != NULL){
        f = fopen(path, "wb");

        if(f == NULL){
            printf("NO SE PUDO ABRIR EL ARCHIVO\n\n");
            system("pause");
            return todoOk;
        }

        // MANDAR A GUARDAR
        for(int i=0; i<tam; i++){
                fwrite( *(lista + i), sizeof(eAuto), 1, f);
        }
        /*
                SOLO SI ES VECTOR DE ESTRUCTURAS
        fwrite(*lista, sizeof(eAuto), tam, f);
        */

        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}




int guardarAutosCSV(eAuto** lista, int tam, char* path){
    int todoOk = 0;
    FILE* f = NULL;

    if(lista != NULL && tam > 0 && path != NULL){
        f = fopen(path, "w");

        if(f == NULL){
            printf("NO SE PUDO ABRIR EL ARCHIVO\n\n");
            system("pause");
            return todoOk;
        }

        // MANDAR A GUARDAR
        fprintf(f, "id,marca,modelo,precio\n");

        for(int i=0; i<tam; i++){
                fprintf(f,"%d,%s,%d,%.2f\n", (*(lista + i))-> );
                //fwrite( *(lista + i), sizeof(eAuto), 1, f);
        }
        /*
                SOLO SI ES VECTOR DE ESTRUCTURAS
        fwrite(*lista, sizeof(eAuto), tam, f);
        */

        fclose(f);
        todoOk = 1;
    }
    return todoOk;
}
