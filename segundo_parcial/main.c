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
    int guardar;

    dato=ParserFromText("MOCK_DATA.csv",alumnoLista);

    if(dato==1)
    {
        printf("se cargo con exito\n");
    }

    orden=ordenarAlumno(alumnoLista);

    mostrar=notaAlumnos(alumnoLista);

    guardar=guardarAlumno("final.csv",alumnoLista);
    return 0;
}
