#include <stdio.h>
#include <stdlib.h>
#include "stdlib.h"
#include "LinkedList.h"
#include "Dominio.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_DominioFromText(FILE* pFile, LinkedList* pArrayLinkedDominio)
{
    int result = 0;
    char buffer[3][30];
    int cant;

    eDominio* dom = NULL;

    if(pFile != NULL && pArrayLinkedDominio != NULL)
    {

        fscanf(pFile,"%[^,],%[^,],%[^\n],\n", buffer[0], buffer[1], buffer[2]);

        while(!feof(pFile))
        {
            cant = fscanf(pFile,"%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2]);

            if(cant == 3)
            {

            printf("%s %s %s\n",buffer[0],buffer[1],buffer[2] );
                dom = newDominio_Parametros(buffer[0],buffer[1],buffer[2], "X");
                    showDominio(dom);
                if(dom != NULL)
                {
                    printf("Hola");
                    ll_add(pArrayLinkedDominio,dom );
                    result = 1;
                }
            }
            else
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    result = 0;
                    break;
                }
            }
        }
    }
    return result;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_DominioFromBinary(FILE* pFile, LinkedList* pArrayLinkedDominio)
{
    int result = 0;
    int cant;
    eDominio* dom = NULL;

    if(pFile != NULL && pArrayLinkedDominio != NULL)
    {

        while(!feof(pFile))
        {

            dom = newDominio();
            if(dom != NULL)
            {
                cant = fread(dom,sizeof(eDominio),1,pFile);

                if(cant == 1)
                {

                    ll_add(pArrayLinkedDominio,dom);
                    result = 1;
                }
                if(cant < 1)
                {
                    if(feof(pFile))
                    {
                        break;
                    }
                    else
                    {

                        result = 0;
                        break;
                    }
                }
            }

        }
    }

    return result;
}
