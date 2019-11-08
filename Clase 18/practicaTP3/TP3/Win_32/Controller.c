#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"
#include "auto.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
     FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile= fopen(path,"r");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_EmployeeFromText(pFile, pArrayListEmployee);
        }
    }
    fclose(pFile);

    return result;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = NULL;
    int result=0;

    if(path != NULL && pArrayListEmployee != NULL){
        pFile = fopen(path,"rb");
        if(pFile==NULL)
        {
            result=0;
        }
        else
        {
          result = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
    }
    fclose(pFile);

    return result;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int result=-1;
    int id;
    int index=-1;
    int tam;
    char confirm;


    Employee* auxEmployee=employee_new();

    if(pArrayListEmployee != NULL){

        tam = ll_len(pArrayListEmployee);

        showEmployees(pArrayListEmployee);

        getInt(&id, "Ingrese ID: ", "Error. Reingrese ID numerico: ");

        index = buscarPorId(pArrayListEmployee, id);
    }


    if(index!=-1)
    {
    showEmployee(auxEmployee);

    getChar(&confirm, "Confirma eliminar el usuario? S/N: ", " Error. Confirma eliminar el usuario? S/N: ", 'S','N');

        if(confirm=='S')
        {
            ll_remove(pArrayListEmployee,index);
            result=1;
        }
        else
        {
            result=0;
        }
    }
    else
    {
        result=2;
    }
    return result;
}


/** \brief Busca empleado por ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param int
 * \return int
 *
 */
int buscarPorId(LinkedList* pArrayListEmployee, int id){
    int index = -1;
    Employee* auxEmployee = NULL;
    int tam;

    if(pArrayListEmployee != NULL){

        tam = ll_len(pArrayListEmployee);

         for(int i=1;i<tam;i++)
        {
            auxEmployee = ((Employee*) ll_get(pArrayListEmployee,i));

            if(auxEmployee->id == id)
            {
                index = i;
                break;
            }
        }
    }

    return index;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = NULL;
    Employee* auxEmp = NULL;
    int size=ll_len(pArrayListEmployee);
    int result=-1;

    int id;
    int hours;
    int salary;
    char name[130];

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"w");

            if(pFile!=NULL)
            {
                 for(int i=0;i<size;i++)
                {
                    auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(auxEmp,&id);
                    employee_getNombre(auxEmp,name);
                    employee_getHorasTrabajadas(auxEmp,&hours);
                    employee_getSueldo(auxEmp,&salary);
                    fprintf(pFile,"%d,%s,%d,%d\n",id,name,hours,salary);
                }
                fclose(pFile);
                result=1;
            }
            else{
                result=0;
            }
        }
    }

    return result;
}

/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile = NULL;
    Employee* auxEmp = NULL;
    int size = ll_len(pArrayListEmployee);
    int result = -1;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"wb");

            if(pFile!=NULL)
            {
                for(int i=0; i<size;i++)
                {///  aca te quedaste
                    auxEmp=ll_get(pArrayListEmployee,i);
                    if(auxEmp!=NULL)
                    {
                        fwrite(auxEmp,sizeof(Employee),1,pFile);
                    }
                }
            result=1;
            fclose(pFile);
            }
            else{
            result=0;
            }
        }
    }
    else{
        result=0;
    }

    return result;
}



