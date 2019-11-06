#include "Alumno.h"

eAlumno* new_Alumno()
{
    eAlumno* unAlumno =(eAlumno*) malloc(sizeof(eAlumno));
    return unAlumno;
}

eAlumno* new_Alumno_Parametros(int id,char* nombre,char* apellido,float nota)
{

    eAlumno* unAlumno = new_Alumno();

    unAlumno->id = id;
    strcpy(unAlumno->nombre,nombre);
    strcpy(unAlumno->apellido,apellido);
    unAlumno->nota = nota;


    return unAlumno;

}


int getId(eAlumno* unAlumno)
{
    int id = -1;
    if(unAlumno!=NULL)
    {
        id = unAlumno->id;
    }
    return id;
}
void setId(eAlumno* unAlumno, int id)
{
    unAlumno->id = id;
}

