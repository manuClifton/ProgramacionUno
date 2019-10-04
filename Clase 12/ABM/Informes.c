#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include "Informes.h"
#include "biblioteca.h"


int menuInformes(){
    int opcion;

    system("cls");
    printf("****** INFORMES *******\n\n");
    printf("1-Mostrar Alumnos de una Carrera\n");
    printf("2-Mostrar Alumnos por Carrera\n");
    printf("3-Mostrar Cantidad de Alumnos por Carrera\n");
    printf("4-Mostrar La Carrera con mas Inscriptos\n");
    printf("5-Mostrar mejor Promedio por Carrera\n");
    printf("6-Mostrar Alumnos Varones\n");
    printf("7-Mostrar Mujeres de Alguna carrera\n");
    printf("8-Mostrar Alumnos mayores a 30 por carrera seleccionada\n");

    printf("9-Mostrar Almuerzos de una fecha determinada\n");
    printf("10-Listar Alumnos que comieron una determinada comida\n");
    printf("11-Listar cantidad de almuerzos x carrera\n");
    printf("12-Carrera amante de las milanesas\n");
    printf("13-Informe deuda alumno seleccionado\n");

    printf("20-Salir\n\n");

    getIntRange(&opcion, "Ingrese opcion: ", "Error, Reingrese opcion: ", 1,20);

    return opcion;
}

void mostrarInformes(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom){
    char salir = 'n';
    int flag = 0;

    for(int i=0; i<tamA; i++){
        if(alumnos[i].isEmpty == 0){
           flag = 1;
        }

    }
    if(flag == 0){
        printf("NO HAY ALUMNOS!!!");
        printf("\n\n");
    }
    else{

        do{
                switch( menuInformes()){
                case 1:
                    //printf("1-Mostrar Alumnos de una Carrera\n");
                    mostrarAlumnosCarreraSeleccionada(alumnos, tamA, carreras, tamC);
                    break;
                case 2:
                    //printf("2-Mostrar Alumnos por Carrera\n");
                    mostrarAlumnosDeTodasLasCarreras(alumnos, tamA, carreras, tamC);
                    break;
                case 3:
                    //printf("3-Mostrar Cantidad de Alumnos por Carrera\n");
                    mostrarCantidaDeAlumnosPorCarrera(alumnos, tamA, carreras, tamC);
                    break;
                case 4:
                    //printf("4-Mostrar La Carrera con mas Inscriptos\n");
                    carrerasInscriptos(alumnos, tamA, carreras, tamC);
                    break;
                case 5:
                    //printf("5-Mostrar mejor Promedio por Carrera\n");
                    mostrarMejorPromedioPorCarrera(alumnos, tamA, carreras, tamC);
                    break;
                case 6:
                    //printf("6-Mostrar Alumnos Varones\n");
                    mostrarAlumnosVarones(alumnos, tamA, carreras, tamC);
                    break;
                case 7:
                    //printf("7-Mostrar Mujeres de Alguna carrera\n");
                    mostrarMujeresPorCarreraSeleccionada(alumnos, tamA, carreras, tamC);
                    break;
                case 8:
                    //printf("8-Mostrar Alumnos mayores a 30 de Licenciatura\n");
                    alumnosMayores(alumnos, tamA, carreras, tamC);
                    break;
                case 9:
                    //printf(" 9-Mostrar Almuerzos de una fecha determinada\n");
                    almuerzosPorFecha(almuerzos, tamAlm, comidas, tamCom);
                    break;
                case 10:
                     //printf("10-Listar Alumnos que comieron una determinada comida\n");
                     alumnosPorComidaSeleccionada(alumnos, tamA, almuerzos, tamAlm, comidas, tamCom, carreras, tamC);
                    break;
                case 11:
                   // printf("11-Listar cantidad de almuerzos x carrera\n");
                    mostrarCantidaDeAlmuerzosPorCarrera(alumnos, tamA, carreras, tamC, almuerzos, tamAlm);
                    break;
                case 12:
                    printf("12-Carrera amante de las milanesas\n");
                    break;
                case 13:
                    printf("13-Informe deuda alumno seleccionado\n");
                    break;
                case 20:
                    printf("Confirma salir?:");
                    fflush(stdin);
                    salir = getchar();
                    printf("\n\n");
                    break;
                default:
                    printf("\nOpcion Invalida!\n\n");
                    break;
            }
            system("pause");
            }while(salir == 'n');
    }
}

void mostrarAlumnosDeTodasLasCarreras(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    char desc[20];

    system("cls");
    printf("***** MOSTRAR ALUMNOS DE TODAS LAS CARRERA  ******** \n\n");

    for(int i=0; i<tamC; i++){
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera: %s \n\n", desc);
        mostrarAlumnoPorCarrera(alumnos, tamA, carreras, tamC, carreras[i].id);
    }
}

void mostrarAlumnosCarreraSeleccionada(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    int idCarrera;
    system("cls");
    printf("***** MOSTRAR ALUMNOS POR CARRERA SELECCIONADA  ******** \n\n");

    mostrarCarreras(carreras, tamC);

    getIntCarrera(&idCarrera, "Ingrese ID de la carrera: ", "Error. Reingrese ID de la carrera: ", 1000, 1001, 1002);

    mostrarAlumnoPorCarrera(alumnos, tamA, carreras, tamC, idCarrera);
}

void mostrarAlumnoPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera){
    for(int i=0; i<tamA; i++){
        if(alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0){
            mostrarAlumno(alumnos[i], carreras, tamC);
        }
    }
    printf("\n\n");
}


void mostrarCantidaDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    char desc[20];
    int cantidad;

    system("cls");
    printf("***** MOSTRAR CANTIDAD DE ALUMNOS POR CARRERA  ******** \n\n");

    for(int i=0; i<tamC; i++){
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera %s ", desc);
        cantidad = cantidadDeAlumnosPorCarrera(alumnos, tamA, carreras, tamC, carreras[i].id);
        printf("Cantidad: %d \n\n", cantidad);
    }
}

int cantidadDeAlumnosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, int idCarrera){
    int contador = 0;
    for(int i=0; i<tamA; i++){
        if(alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0){
            contador++;
        }
    }
    return contador;
}

void carrerasInscriptos(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    int inscriptos[tamC];
    int mayor;
    int flag = 0;

    system("cls");
    printf("***** CARRERA CON MAS ALUMNOS******** \n\n");

    for(int i=0; i<tamC; i++){
       inscriptos[i] = cantidadDeAlumnosPorCarrera(alumnos, tamA, carreras, tamC, carreras[i].id);
    }
    for(int i=0; i<tamC; i++){
        if(inscriptos[i] > mayor || flag == 0){
        mayor = inscriptos[i];
        flag = 1;
        }
    }
    for(int i=0; i<tamC; i++){
        if(inscriptos[i] == mayor){
            printf(" %s \n", carreras[i].descripcion);
        }
    }
     printf("cantidad incriptos %d\n\n", mayor);
}

void mostrarAlumnosVarones(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    int flag = 0;

    system("cls");
    printf("***** ALUMNOS VARONES  ******** \n\n");

    printf("\n LEGAJO   NOMBRE    EDAD   SEXO   NOTA 1    NOTA 2     PROMEDIO    FECHA INGRESO     CARRERA\n");
    printf("***********************************************************************************************\n");

    for(int i=0; i<tamA; i++){
        if(alumnos[i].sexo == 'M'){
            mostrarAlumno(alumnos[i], carreras, tamA);
            flag = 1;
        }
    }
    if(flag == 0){
        printf("\n NO HAY ALUMNOS VARONES!!\n\n");
    }
}


void mostrarMejorPromedioPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){

    float mayorPromedio[tamC];
    int flag = 0;

    system("cls");

    printf("***** MEJOR PROMEDIO DE CADA CARRERA  ******** \n\n");


        for(int i=0; i<tamC; i++){
                  printf(" Carera: %s \n", carreras[i].descripcion);
            for(int j=0; j<tamA; j++){
                if(alumnos[j].idCarrera == carreras[i].id){
                    if( alumnos[j].promedio > mayorPromedio[i] || flag == 0){
                        mayorPromedio[i] = alumnos[j].promedio;
                        flag = 1;
                    }
                }
            }
            printf(" Alumno: %s,   Promedio: %.2f \n\n", alumnos[i].nombre, alumnos[i].promedio);
            flag = 0;
        }

        /*for(int i=0; i<tamC; i++){
            printf(" Carera: %s \n", carreras[i].descripcion);
            for(int j=0; j<tamA; j++){
                if(alumnos[j].idCarrera == carreras[i].id){
                    if(mayorPromedio[i] == alumnos[j].promedio){
                            printf(" Alumno: %s,   Promedio: %.2f \n\n", alumnos[i].nombre, alumnos[i].promedio);
                        //mostrarAlumno(alumnos[j], carreras, tamC);
                    }
                }
            }
        }*/
}


void mostrarMujeresPorCarreraSeleccionada(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    int idCarrera;
    int cont = 0;
    system("cls");

    printf("***** MUJERES POR CARRERA SELECCIONADA  ******** \n\n");

    mostrarCarreras(carreras,tamC);

    getIntCarrera(&idCarrera, "Ingrese ID de la carrera: ", "Error. Reingrese ID de la carrera: ", 1000, 1001, 1002);

    for(int i=0; i<tamA; i++){
        if(alumnos[i].idCarrera == idCarrera && alumnos[i].sexo == 'F'){
            mostrarAlumno(alumnos[i], carreras, tamC);
            cont++;
        }
    }
    if(!cont){
        printf("Esa Carrera no tiene alumnas mujeres!!\n\n");
    }
}


void alumnosMayores(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC){
    int idCarrera;
    int cont = 0;
    system("cls");

    printf("***** ALUMNOS MAYORES A 30  ******** \n\n");

    mostrarCarreras(carreras,tamC);

    getIntCarrera(&idCarrera, "Ingrese ID de la carrera: ", "Error. Reingrese ID de la carrera: ", 1000, 1001, 1002);


    for(int i=0; i<tamA; i++){
        if(alumnos[i].idCarrera == idCarrera && alumnos[i].edad >= 30){
            mostrarAlumno(alumnos[i], carreras, tamC);
            cont++;
        }
    }
    if(!cont){
        printf("Esa Carrera no tiene alumnas mayores a 30!!\n\n");
    }
}


void almuerzosPorFecha(eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamC){

    eFecha fecha1;
    int comparacion;
    int flag = 0;

    system("cls");

    printf("***** ALMUERZOS POR FECHA  ******** \n\n");

    printf("Ingrese Fecha dd/mm/aaaa: ");
    scanf("%d/%d/%d", &fecha1.dia, &fecha1.mes, &fecha1.anio );

    for(int i=0; i<tamAlm; i++){
        comparacion = comparaFecha(fecha1, almuerzos[i].fecha);

        if(comparacion == 0){
            mostrarAlmuerzo(almuerzos[i], comidas, tamC);
            flag = 1;
        }
    }
    if(!flag){
        printf("NO HAY ALMUERZOS EN ESA FECHA\n\n");
    }

}


void alumnosPorComidaSeleccionada(eAlumno alumnos[], int tamA,eAlmuerzo almuerzos[], int tamAlm, eComida comidas[], int tamCom, eCarrera carreras[], int tamC){

    int idComida;
    system("cls");

    printf("***** ALUMNOS POR COMIDA SELECCIONADA  ******** \n\n");

    mostrarComidas(comidas, tamCom);

    getInt(&idComida, "Ingrese ID de la comida: ", "Error. Reingrese ID: ");

    for(int i=0; i<tamAlm; i++){
        if(almuerzos[i].idComida == idComida && almuerzos[i].isEmpty == 0){
            for(int j=0; j<tamA; j++){
                if(alumnos[j].legajo == almuerzos[i].legajo){
                    mostrarAlumno(alumnos[i],carreras, tamC);
                }
            }
        }
    }

}


int cantidadDeAlmuerzosPorCarrera(eAlmuerzo almuerzos[], int tamAlm, eAlumno alumnos[], int tamA,  eCarrera carreras[], int tamC, int idCarrera){
    int contador = 0;
    for(int i=0; i<tamA; i++){
        if(alumnos[i].idCarrera == idCarrera && alumnos[i].isEmpty == 0){
                for(int j=0; j<tamAlm; j++){
                    if(almuerzos[j].legajo == alumnos[i].legajo){
                        contador++;
                    }
                }
        }
    }
    return contador;
}

void mostrarCantidaDeAlmuerzosPorCarrera(eAlumno alumnos[], int tamA, eCarrera carreras[], int tamC, eAlmuerzo almuerzos[], int tamAlm){
    char desc[20];
    int cantidad;

    system("cls");
    printf("***** MOSTRAR CANTIDAD DE ALMUERZOS POR CARRERA  ******** \n\n");

    for(int i=0; i<tamC; i++){
        cargarDescCarrera(carreras[i].id, carreras, tamC, desc);
        printf("Carrera %s ", desc);
        cantidad = cantidadDeAlmuerzosPorCarrera(almuerzos, tamAlm, alumnos, tamA, carreras, tamC, carreras[i].id);
        printf("Cantidad: %d \n\n", cantidad);
    }
}







