#include <stdio.h>
#include <stdlib.h>
#include "alumno.h"
#include "LinkedList.h"

int main()
{
    LinkedList* alumnoLista = ll_newLinkedList();
    int dato;
    int orden;
    int mostrar;

    dato=ParserFromText("MOCK_DATA.csv",alumnoLista);

    if(dato==1)
    {
        printf("se cargo con exito\n");
    }

    orden=ordenarAlumno(alumnoLista);
    return 0;
}
