#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "stdlib.h"

#include "LinkedList.h"
#include "biblioteca.h"
#include "Controller.h"
#include "Dominio.h"


int main()
{

    LinkedList* listaDominios = ll_newLinkedList();

    controller_loadFromText("datos.csv", listaDominios);

        showDominios(listaDominios);
    return 0;
}



