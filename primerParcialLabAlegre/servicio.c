#include "servicio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarDescripcionServicio(eServicio ArrayServicios[], int tamServicio, int idServicio, char descripcionServicio[])
{
    int todoOk=0;
    if(ArrayServicios!=NULL && tamServicio>0 && descripcionServicio!=NULL)
    {
        for(int i=0; i<tamServicio; i++)
        {
            if(ArrayServicios[i].id==idServicio)
            {
                strcpy(descripcionServicio, ArrayServicios[i].descripcionServicio);
                break;
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarServicios(eServicio ArrayServicios[], int tamServicio)
{
    int todoOk=0;
    if(ArrayServicios!=NULL && tamServicio>0)
    {
        printf("\nServicios disponibles para el auto:\n");
        printf("Id\tServicios\tPrecios\n");
        for(int i=0; i<tamServicio; i++)
        {
            printf("%d\t%-10s\t%d\n", ArrayServicios[i].id, ArrayServicios[i].descripcionServicio, ArrayServicios[i].precio);
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarServicioPorId(eServicio arrayDeServicios[], int tamSer, int idServicio)
{
    int indiceDeIdEncontrado=-1;
    if(arrayDeServicios!=NULL && tamSer>0)
    {
        for(int i=0; i<tamSer; i++)
        {
            if(arrayDeServicios[i].id==idServicio)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}
