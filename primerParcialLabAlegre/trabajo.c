#include "trabajo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#include "servicio.h"
#include "fecha.h"
#include "color.h"
#include "marca.h"
#include "input.h"


int inicializarTrabajos(eTrabajo arrayDeTrabajos[], int tamTrab)
{
    int todoOk=0;

    if(arrayDeTrabajos!=NULL && tamTrab>0)
    {
        for(int i=0; i<tamTrab; i++)
        {
            arrayDeTrabajos[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab)
{
    int indiceLibre=-1;

    if(arrayDeTrabajos!=NULL && tamTrab>0)
    {
        for(int i=0; i<tamTrab; i++)
        {
            if(arrayDeTrabajos[i].isEmpty)
            {
                indiceLibre=i;
                break;
            }
        }
    }
    return indiceLibre;
}

int altaDeTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, int* pIdTrabajo)
{

    int todoOk=0;
    int indiceLibre;
    eTrabajo auxTrabajo;

    if(arrayDeTrabajos!=NULL && tamTrab>0 && autos!=NULL && tamAuto>0 && servicios!=NULL && tamServ>0 && pIdTrabajo!=NULL && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColores>0)
    {
        system("cls");
        indiceLibre=buscarLibreTrabajo(arrayDeTrabajos, tamTrab);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            mostrarAutos(autos, tamAuto, marcas, tamMarca, colores, tamColores);

            printf("\n--------------------------------------------------------------------------------------\n");
            printf("                     ***   Alta de Trabajo   ***             \n");
            printf("--------------------------------------------------------------------------------------\n\n");

            auxTrabajo.idTrabajo= *pIdTrabajo;
            (*pIdTrabajo)++;

            printf("Ingrese el id del auto: ");
            scanf("%d", &auxTrabajo.idAuto);
            while(buscarAutoPorId(autos, tamAuto, auxTrabajo.idAuto)<0)
            {
                printf("Id invalido, reingrese el id del auto: ");
                scanf("%d", &auxTrabajo.idAuto);
            }

            mostrarServicios(servicios, tamServ);
            validarEntero(&auxTrabajo.idServicio, "Ingrese el id del servicio: ", "Error. Ingrese el id del servicio: ", 20000, 20003);

            validarFecha(&auxTrabajo.fecha);

            auxTrabajo.isEmpty=0;

            arrayDeTrabajos[indiceLibre]=auxTrabajo;

            printf("\nExcelente. Se realizo correctamente la alta del trabajo: \n");

            printf("ID TRABAJO  |                    AUTO                       |   SERVICIO   PRECIO SERVICIO   FECHA SERVICIO \n");
            printf("            |        Id      Marca      Color     Caja      |                          \n");
            mostrarUnTrabajo(arrayDeTrabajos[indiceLibre], autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);

        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarUnTrabajo(eTrabajo unTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores)
{
    int todoOk=0;
    char descripcionServicio[20];
    char descripcionMarcaAuto[20];
    char descripcionColorAuto[20];
    int indiceAutoAMostrar;
    int indiceServicioAMostrar;


    if(autos!=NULL && tamAuto>0 && servicios!=NULL && tamServ>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColores>0)
    {
        indiceAutoAMostrar=buscarAutoPorId(autos, tamAuto, unTrabajo.idAuto);

        indiceServicioAMostrar=buscarServicioPorId(servicios, tamServ, unTrabajo.idServicio);
        cargarDescripcionServicio(servicios, tamServ, unTrabajo.idServicio, descripcionServicio);
        //Para cargar las string de las id color y id marca que le corresponden al auto a realizar servicio
        cargarDescripcionColor(colores, tamColores, autos[indiceAutoAMostrar].idColor, descripcionColorAuto);
        cargarDescripcionMarca(marcas, tamMarca, autos[indiceAutoAMostrar].idMarca, descripcionMarcaAuto);

        printf("%d           |         %d     %-10s %-10s %c         |   %-10s   %d              %02d/%02d/%d\n",
        unTrabajo.idTrabajo,
        autos[indiceAutoAMostrar].id,
        descripcionMarcaAuto,
        descripcionColorAuto,
        autos[indiceAutoAMostrar].caja,
        descripcionServicio,
        servicios[indiceServicioAMostrar].precio,
        unTrabajo.fecha.dia,
        unTrabajo.fecha.mes,
        unTrabajo.fecha.anio);

        todoOk=1;
    }
    return todoOk;
}

int mostrarTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores)
{
    int todoOk=0;

    if(arrayTrabajos!=NULL && tamTrab>0 && autos!=NULL && tamAuto>0 && servicios!=NULL && tamServ>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColores>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de Trabajos   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("ID TRABAJO  |                    AUTO                       |   SERVICIO   PRECIO SERVICIO   FECHA SERVICIO \n");
        printf("            |        Id      Marca      Color     Caja      |                          \n");

        for(int i=0; i<tamTrab; i++)
        {
            if(arrayTrabajos[i].isEmpty==0)
            {
                mostrarUnTrabajo(arrayTrabajos[i], autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
            }
        }
        todoOk=1;
    }
    return todoOk;

}

