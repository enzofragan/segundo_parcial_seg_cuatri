#include "LinkedList.h"
#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[100];
    int nota1;
    int nota2;
    int notaFinal;
}eAlumno;

#endif // ALUMNO_H_INCLUDED

eAlumno* nuevo_alumno();
eAlumno* nuevo_alumnoParametros(char* id,char* nombre,char* nota1,char* nota2,char* notaFinal);
int eAlumno_setId(eAlumno* ,int );
int eAlumno_setNombre(eAlumno* this,char* nombre);
int eAlumno_setNota1(eAlumno* this,int nota1);
int eAlumno_setNota2(eAlumno* this,int nota2);
int eAlumno_setNotaFinal(eAlumno* this,int notaFinal);
int eAlumno_getId(eAlumno* this,int* id);
int eAlumno_getNombre(eAlumno* this,char* nombre);
int eAlumno_getNota1(eAlumno* this,int* nota1);
int eAlumno_getNota2(eAlumno* this,int* nota2);
int eAlumno_getNotaFinal(eAlumno* this,int* notaFinal);
int esNumerica(char* cadena);
int esLetra(char* cadena);
int ParserFromText(char* path ,LinkedList* lista);
int parser_AlumnoFromText(FILE* pFile ,LinkedList* lista);
int listaAlumno(eAlumno* alumno);
int listarTodos(LinkedList* lista);
int compararAlumnos (void* ,void* );
int ordenarAlumno (LinkedList* );
int notaFinalAlumnos (void* );
int notaAlumnos (LinkedList* );
int notaFinales();
int guardarAlumno(char* path , LinkedList* lista);
