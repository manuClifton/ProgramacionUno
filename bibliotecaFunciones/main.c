#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "Funciones.h"

int getString(char* strig,char message[],char messageError[], int lowLimit, int hiLimit, int attempts);


int main()
{
    // Pedir entero
    int numInt;
    int todoOkInt;
    todoOkInt = getIntRange(&numInt,"Ingrese numero Entero: ", "Error. Reingrese un numero valido: ",0,10,3);

    if(todoOkInt == 0){
        printf("No se pudo cargar la nota.\n");
    }else{
        printf("El numero es: %d\n", numInt);
    }

    //pedir flotante
    float numFloat;
    int todoOkFloat;

    todoOkFloat = getFloat(&numFloat, "Ingrese numero Flotante: ","Error. Reingrese un numero valido: ",0,10,3);

    if(todoOkFloat == 0){
        printf("No se pudo cargar el numero.\n");
    }else{
        printf("El numero es: %.2f\n", numFloat);
    }


    //Pedir un Caracter
    char input;
    int todoOkChar;

    todoOkChar = getChar(&input,"Ingrese Opcion [A][B][C]","Solo [A][B][C]",'A','C', 3);

     if(todoOkChar == 0){
        printf("No se pudo cargar la opcion.\n");
    }else{
        printf("la opcion es: %c\n", input);
    }

    //Pedir STRING
    char strig[50];
    int todoOkStrin;

    todoOkStrin = getString(strig,"Nombre: ","El largo debe ser entre 2 y 50: ", 2, 50, 3);

     if(todoOkStrin == 0){
        printf("No se pudo cargar el STRING.\n");
    }else{
        printf("El STRING es: %s\n", strig);
    }


    return 0;
}


int getString(char* strig,char message[],char messageError[], int lowLimit, int hiLimit, int attempts){


    char aux[50];
    int todoOk = 1;
    int i=0;

    printf("%s", message);
    fflush(stdin);
    scanf("%s", aux);

     while (aux[i] != '\0'){
            printf ("%c", aux[i]);
            i++;
     }

        while(i < lowLimit || i > hiLimit ){
            attempts--;
                if(attempts == 0){
                        todoOk = 0;
                    break;
                }
            printf("%s", messageError);
            fflush(stdin);
            scanf("%s", aux);
        }
        if(attempts != 0){
            strig = aux;
        }
    return todoOk;
}
