#include "marca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cargarDescripcionMarca(eMarca ArrayMarcas[], int tamMarca, int idMarca, char descripcionMarca[])
{
    int todoOk=0;
    if(ArrayMarcas!=NULL && tamMarca>0 && descripcionMarca!=NULL)
    {
        for(int i=0; i<tamMarca; i++)
        {
            if(ArrayMarcas[i].id==idMarca)
            {
                strcpy(descripcionMarca, ArrayMarcas[i].descripcion);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;


}

int mostrarMarcas(eMarca ArrayMarcas[], int tamMarca)
{
    int todoOk=0;
    if(ArrayMarcas!=NULL && tamMarca>0)
    {
        printf("\nMarcas de autos disponibles:\n");
        printf("Id        Marcas\n");
        for(int i=0; i<tamMarca; i++)
        {
            printf("%d      %-10s\n", ArrayMarcas[i].id, ArrayMarcas[i].descripcion);
        }
        printf("\n");
        todoOk=1;
    }
    return todoOk;
}
