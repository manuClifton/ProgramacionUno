#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

void employee_delete();
void showEmployee(Employee* emp);
void showEmployees(LinkedList* pArrayLinkedList);

int employee_setId(Employee* listaEmployee,int id);
int employee_getId(Employee* listaEmployee,int* id);

int employee_setNombre(Employee* listaEmployee,char* nombre);
int employee_getNombre(Employee* listaEmployee,char* nombre);

int employee_setHorasTrabajadas(Employee* listaEmployee,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* listaEmployee,int* horasTrabajadas);

int employee_setSueldo(Employee* listaEmployee,int sueldo);
int employee_getSueldo(Employee* listaEmployee,int* sueldo);

#endif // employee_H_INCLUDED
