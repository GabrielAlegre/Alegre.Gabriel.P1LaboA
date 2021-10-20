#include "color.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDescripcionColor(eColor ArrayColor[], int tamColor, int idColor, char descripcionColor[])
{
    int todoOk=0;
    if(ArrayColor!=NULL && tamColor>0 && descripcionColor!=NULL)
    {
        for(int i=0; i<tamColor; i++)
        {
            if(ArrayColor[i].id==idColor)
            {
                strcpy(descripcionColor, ArrayColor[i].nombreColor);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarColor(eColor ArrayColor[], int tamColor)
{
    int todoOk=0;
    if(ArrayColor!=NULL && tamColor>0)
    {
        printf("\nColor:\n");
        printf("Id       Color\n");
        for(int i=0; i<tamColor; i++)
        {
            printf("%d     %-10s\n", ArrayColor[i].id, ArrayColor[i].nombreColor);
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}
