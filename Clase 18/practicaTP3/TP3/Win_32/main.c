#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "biblioteca.h"
#include "menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    char salir = 'N';
    int flagLoadLinkedList = 0;
    int devolution;

    LinkedList* listaEmploye = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
                if(flagLoadLinkedList == 0){
                    devolution=controller_loadFromText("data.csv",listaEmploye);
                    if(devolution==1)
                    {
                        printf("\n   **********************\n");
                        printf("   * Cargo Exitosamente *\n");
                        printf("   **********************\n\n");
                        flagLoadLinkedList=1;
                    }
                    else if (devolution==0)
                    {
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
                    }
                }else{
                    printf("\n   *********************\n");
                    printf("   * Ya estan cargados *\n");
                    printf("   *********************\n\n");
                }
                break;
            case 2:
                if(flagLoadLinkedList == 0){
                    devolution=controller_loadFromBinary("data.bin",listaEmploye);
                    if(devolution==1)
                    {
                        printf("\n   **********************\n");
                        printf("   * Cargo Exitosamente *\n");
                        printf("   **********************\n\n");

                        flagLoadLinkedList=1;
                    }
                    else if (devolution==0)
                    {
                        printf("\n   *******************\n");
                        printf("   * Error al cargar *\n");
                        printf("   *******************\n\n");
                    }
                }else{
                    printf("\n   *********************\n");
                    printf("   * Ya estan cargados *\n");
                    printf("   *********************\n\n");
                }

                system("pause");
                break;
            case 3:
                //ALTA EMPLEADO
                break;
            case 4:
                //MODIFICAR
                break;
            case 5:
                //BAJA
                break;
            case 6:
                //MOSTRAR
                showEmployees(listaEmploye);
                break;
            case 7:
                // ORDENAR EMPLEADOS
                break;
            case 8:
                // GUARDAR EN TEXTO
                break;
            case 9:
                // GUARDAR EN BINARIO
                break;
            case 10:
                getChar(&salir,"Desea Salir?  S o N: ","Error. Ingrese S o N: ", 'S', 'N');
                printf("\n\n");
            default:
                printf("\n\nOPCION INVALIDA!! \n\n");
            break;
        }
        system("pause");

    }while(salir == 'N');

    return 0;
}
