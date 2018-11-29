#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "alumno.h"
#include "LinkedList.h"

eAlumno* nuevo_alumno()
{
    eAlumno* newAlumno;

    newAlumno=(eAlumno*) malloc(sizeof(eAlumno));

    return newAlumno;
}

eAlumno* nuevo_alumnoParametros(char* id,char* nombre,char* nota1,char* nota2,char* notaFinal)
{
    eAlumno* alumno;

    if(esNumerica(id)!=-1)
    {
        if(esLetra(nombre)!=-1)
        {
            if(esNumerica(nota1)!=-1)
            {
                if(esNumerica(nota2)!=-1)
                {
                    if(esNumerica(notaFinal)!=-1)
                    {
                         alumno=nuevo_alumno();

                        if(alumno!=NULL)
                        {
                            eAlumno_setId(alumno,atoi(id));
                            eAlumno_setNombre(alumno,nombre);
                            eAlumno_setNota1(alumno,atoi(nota1));
                            eAlumno_setNota2(alumno,atoi(nota2));
                            eAlumno_setNotaFinal(alumno,atoi(notaFinal));
                        }
                    }
                }
            }
        }
    }

    return alumno;
}

int eAlumno_setId(eAlumno* this,int id)
{
    int ret=0;
    if(this!=NULL)
    {
        this->id=id;
        ret=1;
    }

    return ret;
}

int eAlumno_setNombre(eAlumno* this,char* nombre)
{
    int ret=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        ret=1;
    }

    return ret;
}

int eAlumno_setNota1(eAlumno* this,int nota1)
{
    int ret=0;
    if(this!=NULL)
    {
        this->nota1=nota1;
        ret=1;
    }

    return ret;
}

int eAlumno_setNota2(eAlumno* this,int nota2)
{
    int ret=0;
    if(this!=NULL)
    {
        this->nota2=nota2;
        ret=1;
    }

    return ret;
}

int eAlumno_setNotaFinal(eAlumno* this,int notaFinal)
{
    int ret=0;
    if(this!=NULL)
    {
        this->notaFinal=notaFinal;
        ret=1;
    }

    return ret;
}

int eAlumno_getId(eAlumno* this,int* id)
{
    int ret=0;
    if(this!=NULL)
    {
        *id=this->id;
        ret = 1;
    }
    return ret;
}

int eAlumno_getNombre(eAlumno* this,char* nombre)
{
    int ret=0;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        ret=1;
    }
    return ret;
}

int eAlumno_getNota1(eAlumno* this,int* nota1)
{
    int ret=0;
    if(this!=NULL)
    {
        *nota1=this->nota1;
        ret=1;
    }
    return ret;
}

int eAlumno_getNota2(eAlumno* this,int* nota2)
{
    int ret=0;
    if(this!=NULL)
    {
        *nota2=this->nota2;
        ret=1;
    }
    return ret;
}

int eAlumno_getNotaFinal(eAlumno* this,int* notaFinal)
{
    int ret=0;
    if(this!=NULL)
    {
        *notaFinal=this->notaFinal;
        ret=1;
    }
    return ret;
}

int esNumerica(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isdigit(cadena[i])))
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
}

int esLetra(char* cadena)
{
    int i=0;
    if(cadena!=NULL)
    {
        while(cadena[i]!='\0')
        {
            if(!(isalpha(cadena[i])))
            {
                return -1;
            }
            i++;
        }
    }
    return 1;
}

int ParserFromText(char* path , LinkedList* lista)
{
    FILE* pArchivo;
    int ret=-1;

    pArchivo = fopen(path,"r");

    ret = parser_AlumnoFromText(pArchivo,lista);

    fclose(pArchivo);
    return ret;
}

int parser_AlumnoFromText(FILE* pFile , LinkedList* lista)
{
    int ret=-1;
    eAlumno* pAux;
    int cantidad;
    char id[50];
    char nombre[50];
    char nota1[50];
    char nota2[50];
    char notaFinal[50];

    if(pFile!=NULL && lista!=NULL)
    {
        cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,nota1,nota2,notaFinal);
        do{
            cantidad=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,nota1,nota2,notaFinal);

            if(cantidad==5)
            {
                pAux=nuevo_alumno();
               eAlumno_setId(pAux,atoi(id));
               eAlumno_setNombre(pAux,nombre);
               eAlumno_setNota1(pAux,atoi(nota1));
               eAlumno_setNota2(pAux,atoi(nota2));
               eAlumno_setNotaFinal(pAux,atoi(notaFinal));
               ll_add(lista,pAux);
               listaAlumno(pAux);
               ret=1;
            }
        }while(!feof(pFile));
    }
    return ret;
}

int listaAlumno(eAlumno* alumno)
{
    int* id;
    char nombre[100];
    int* nota1;
    int* nota2;
    int* notaFinal;
    eAlumno_getId(alumno,&id);
    eAlumno_getNombre(alumno,nombre);
    eAlumno_getNota1(alumno,&nota1);
    eAlumno_getNota2(alumno,&nota2);
    eAlumno_getNotaFinal(alumno,&notaFinal);
    printf("%d   %s   %d   %d   %d\n",id,nombre,nota1,nota2,notaFinal);
}

int listarTodos(LinkedList* lista)
{
    int i;
    int len;
    eAlumno* aux;
    int ret=-1;

    len=ll_len(lista);

    printf("id   nombre   nota1 nota2   notaFinal\n");

    for(i=0;i<len;i++)
    {
        aux=(eAlumno*) ll_get(lista,i);

        if(aux!=NULL)
        {
            listaAlumno(aux);
            ret=1;
        }
    }

    return ret;
}

int compararAlumnos (void* elemento1,void* elemento2)
{
    int ret=-1;
    char nombre1[100];
    char nombre2[100];

    eAlumno_getNombre((eAlumno*)elemento1,nombre1);
    eAlumno_getNombre((eAlumno*)elemento2,nombre2);

    if(strcmp(nombre1,nombre2)>0)
    {
        ret=1;
    }

    return ret;
}

int ordenarAlumno (LinkedList* lista)
{
    int i;
    int len;
    eAlumno* aux;
    int ret=-1;

    len=ll_len(lista);

    if(lista!=NULL)
    {
        for(i=0;i<len;i++)
        {
            aux=(eAlumno*) ll_get(lista,i);

            if(aux!=NULL)
            {
                ll_sort(lista,compararAlumnos,1);
                ret=1;
            }
        }
    }

    return ret;
}

int notaFinalAlumnos (void* elemento)
{
    int ret=-1;
    int* notaFinal;
    int hora = time(NULL);



    srand(hora);


        notaFinal = (rand()%11)+1;
        eAlumno_setNotaFinal((eAlumno*)elemento,notaFinal);
        ret=1;



    return ret;
}


int notaAlumnos (LinkedList* lista)
{
    int ret=-1;
    int i;
    int len;

    if(lista!=NULL)
    {
        len=ll_len(lista);
        for(i=0;i<len;i++)
        {
           ll_map(lista,notaFinalAlumnos);
        ret=1;
        }

        listarTodos(lista);
    }

    return ret;
}

int guardarAlumno(char* path , LinkedList* lista)
{
    FILE* pArchivo;
    int i;
    eAlumno* pAux;
    int len;
    int ret=-1;
    int* id;
    char nombre[128];
    int* nota1;
    int* nota2;
    int* notaFinal;
    int acu = 0;
    int acu2 = 0;
    int promedio;

    pArchivo=fopen(path,"w");

    if(pArchivo!=NULL && lista!=NULL)
    {
        len=ll_len(lista);

        for(i=0;i<len;i++)
        {
            pAux=(eAlumno*) ll_get(lista,i);

            if(pAux!=NULL)
            {
                eAlumno_getNotaFinal(pAux,&notaFinal);
                acu=notaFinal;
                acu2= acu2 + acu;
            }
        }

        promedio=acu2/i;

        for(i=0;i<len;i++)
        {
            pAux=(eAlumno*) ll_get(lista,i);

            if(pAux!=NULL)
            {
                eAlumno_getId(pAux,&id);
                eAlumno_getNombre(pAux,nombre);
                eAlumno_getNota1(pAux,&nota1);
                eAlumno_getNota2(pAux,&nota2);
                eAlumno_getNotaFinal(pAux,&notaFinal);

                if(notaFinal>=promedio)
                {
                    fprintf(pArchivo," %d, %s, %d, %d, %d\n",id,nombre,nota1,nota2,notaFinal);
                    ret=1;
                }

            }
        }
    }
    fclose(pArchivo);
    return ret;
}
