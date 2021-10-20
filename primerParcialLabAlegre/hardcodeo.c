#include "hardcodeo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int IdMarca[10]={1000, 1001, 1004, 1003, 1003, 1004, 1001, 1002,1002,1004};

int color[10]={5004, 5001, 5000, 5003, 5004, 5002, 5001, 5002, 5000, 5001};

char caja[10]={'m', 'a', 'm', 'm', 'a', 'm', 'a', 'a', 'm', 'a'};


int harcodearAutos(eAuto arrayAutos[], int tamAuto, int cantidadACargar, int* pIdAuto)
{
    int contador=-1;

    if(arrayAutos!=NULL && tamAuto>0 && cantidadACargar>=0 && cantidadACargar<=tamAuto && pIdAuto!=NULL)
    {
        contador=0;
        for(int i=0; i<cantidadACargar; i++)
        {
            arrayAutos[i].id= *pIdAuto;
            (*pIdAuto)++;
            arrayAutos[i].idMarca=IdMarca[i];
            arrayAutos[i].idColor=color[i];
            arrayAutos[i].caja=caja[i];
            arrayAutos[i].isEmpty=0;
            contador++;
        }
    }
    return contador;
}
