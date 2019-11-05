
#include "Employee.h"
#include "stdlib.h"
#include <string.h>

int employee_setId(Employee* listaEmployee,int id)
{
    int result=0;
    if(listaEmployee!=NULL && id >0)
    {
        listaEmployee->id = id;
        result=1;
    }

    return result;
}

int employee_getId(Employee* listaEmployee,int* id)
{
    int result=0;

    if(listaEmployee!=NULL && id!=NULL)
    {
        *id = listaEmployee->id;
        result = 1;
    }


    return result;
}

int employee_setNombre(Employee* listaEmployee, char* nombre)
{
    int result=0;
    if( listaEmployee != NULL && nombre != NULL && strlen(nombre) >= 3 && strlen(nombre) <= 127)
    {
        strcpy(listaEmployee->nombre, nombre);
        result = 1;
    }
    return result;
}

int employee_getNombre(Employee* listaEmployee,char* nombre){

    int result=0;
    if( listaEmployee != NULL && nombre != NULL)
    {
        strcpy( nombre,listaEmployee->nombre);
        result = 1;
    }
    return result;
}

int employee_setHorasTrabajadas(Employee* listaEmployee,int horasTrabajadas){

    int result=0;
    if( listaEmployee != NULL && horasTrabajadas >= 0)
    {
        listaEmployee->horasTrabajadas = horasTrabajadas;
        result = 1;
    }
    return result;
}

int employee_getHorasTrabajadas(Employee* listaEmployee,int* horasTrabajadas){

    int result=0;

    if(listaEmployee!=NULL && horasTrabajadas>0)
    {
        *horasTrabajadas=listaEmployee->horasTrabajadas;
        result = 1;
    }
    return result;
}

int employee_setSueldo(Employee* listaEmployee,int sueldo){

    int result=0;
    if(listaEmployee!=NULL && sueldo >0)
    {
        listaEmployee->sueldo = sueldo;
        result=1;
    }

    return result;
}

int employee_getSueldo(Employee* listaEmployee,int* sueldo){

    int result=0;

    if(listaEmployee!=NULL && sueldo>0)
    {
        *sueldo=listaEmployee->sueldo;
        result = 1;
    }
    return result;
}



Employee* employee_new(){

    Employee* nuevo = (Employee*) malloc( sizeof(Employee));
    if( nuevo != NULL)
    {
        nuevo->id = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->horasTrabajadas = 0;
        nuevo->sueldo = 0;
    }
    return nuevo;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
    Employee* nuevo = employee_new();
    if( nuevo != NULL)
    {
        if(idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
        {
            if(!(employee_setId(nuevo, atoi(idStr)) && employee_setNombre(nuevo,nombreStr) && employee_setHorasTrabajadas(nuevo,atoi(horasTrabajadasStr)) && employee_setSueldo(nuevo,atoi(sueldoStr)) ) == 0 ){
            free(nuevo);
            nuevo = NULL;
            }

        }
    }
    return nuevo;
}

