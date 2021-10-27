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
                fflush(stdin);
                scanf("%d", &auxTrabajo.idAuto);
            }

            mostrarServicios(servicios, tamServ);
            ingresoEntero(&auxTrabajo.idServicio, "Ingrese el id del servicio: ", "Error. Ingrese el id del servicio: ", 20000, 20003);

            validarFecha(&auxTrabajo.fecha);

            auxTrabajo.isEmpty=0;

            arrayDeTrabajos[indiceLibre]=auxTrabajo;

            printf("\nExcelente. Se realizo correctamente la alta del trabajo: \n");

            printf("ID TRABAJO|           AUTOS                | SERVICIO   PRECIO SERVICIO   FECHA SERVICIO \n");
            printf("          | Id   Marca       Color    Caja |                          \n");
            mostrarUnTrabajo(arrayDeTrabajos[indiceLibre], autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
            printf("\n");

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

        cargarDescripcionColor(colores, tamColores, autos[indiceAutoAMostrar].idColor, descripcionColorAuto);
        cargarDescripcionMarca(marcas, tamMarca, autos[indiceAutoAMostrar].idMarca, descripcionMarcaAuto);

        printf("%-10d| %-5d%-12s%-8s %-3c  | %-10s       %d         %02d/%02d/%d\n",
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
    int indiceAuto;

    if(arrayTrabajos!=NULL && tamTrab>0 && autos!=NULL && tamAuto>0 && servicios!=NULL && tamServ>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColores>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de Trabajos   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("ID TRABAJO|           AUTOS                | SERVICIO   PRECIO SERVICIO   FECHA SERVICIO \n");
        printf("          | Id   Marca       Color    Caja |                          \n");

        for(int i=0; i<tamTrab; i++)
        {
            indiceAuto=buscarAutoPorId(autos, tamAuto, arrayTrabajos[i].idAuto);

            if(arrayTrabajos[i].isEmpty==0 && indiceAuto>=0)
            {
                mostrarUnTrabajo(arrayTrabajos[i], autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
            }
        }
        todoOk=1;
    }
    return todoOk;
}

int trabajosDeUnAuto(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores)
{
    int idDelAuto;
    int todoOk=0;
    int indiceDelAutoElegido;

    if(arrayTrabajos!=NULL && tamTrab>0 && autos!=NULL && tamAuto>0 && servicios!=NULL && tamServ>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColores>0)
    {

        system("cls");
        mostrarAutos(autos, tamAuto, marcas, tamMarca, colores, tamColores);
        printf("\n--------------------------------------------------------------------------------------------------------------\n");
        printf("           ***   Trabajos de un auto    ***             \n");
        printf("-------------------------------------------------------------------------------------------------------------\n");

        printf("Ingrese el id del auto: ");
        scanf("%d", &idDelAuto);
        while(buscarAutoPorId(autos, tamAuto, idDelAuto)<0)
        {
            printf("No se encontro ningun auto con esa id, reingrese el id del auto: ");
            fflush(stdin);
            scanf("%d", &idDelAuto);
        }
        indiceDelAutoElegido=buscarAutoPorId(autos, tamAuto, idDelAuto);

        printf("\nTrabajos del auto con la id %d:\n", autos[indiceDelAutoElegido].id);

        printf("ID TRABAJO|           AUTOS                | SERVICIO   PRECIO SERVICIO   FECHA SERVICIO \n");
        printf("          | Id   Marca       Color    Caja |                                               \n");

        for(int i=0;i<tamTrab;i++)
        {
            if(arrayTrabajos[i].isEmpty==0 && autos[indiceDelAutoElegido].isEmpty==0)
            {
                if(arrayTrabajos[i].idAuto==autos[indiceDelAutoElegido].id)
                {
                    mostrarUnTrabajo(arrayTrabajos[i], autos, tamAuto, servicios, tamServ, marcas, tamMarca,colores, tamColores);
                }
            }
        }
        todoOk=1;
	}
	return todoOk;
}


int importeTotalDeUnAuto(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores)
{
    int idDelAuto;
    int todoOk=0;
    int indiceDelAutoElegido;
    int acumuladorDeImporte=0;
    int indiceServicio;


    if(arrayTrabajos!=NULL && tamTrab>0 && autos!=NULL && tamAuto>0 && servicios!=NULL && tamServ>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColores>0)
    {
        system("cls");
        mostrarAutos(autos, tamAuto, marcas, tamMarca, colores, tamColores);
        printf("\n--------------------------------------------------------------------------------------------------------------\n");
        printf("           ***   Infomorme suma de los importes de un auto     ***             \n");
        printf("-------------------------------------------------------------------------------------------------------------\n");

        printf("Ingrese el id del auto: ");
        scanf("%d", &idDelAuto);
        while(buscarAutoPorId(autos, tamAuto, idDelAuto)<0)
        {
            printf("No se encontro ningun auto con esa id, reingrese el id del auto: ");
            fflush(stdin);
            scanf("%d", &idDelAuto);
        }
        indiceDelAutoElegido=buscarAutoPorId(autos, tamAuto, idDelAuto);

        printf("\nLos servios/Trabajos que le realizaron al auto elegido son:\n");
        printf("ID TRABAJO|           AUTOS                | SERVICIO   PRECIO SERVICIO   FECHA SERVICIO \n");
        printf("          | Id   Marca       Color    Caja |                                               \n");
        for(int i=0;i<tamTrab;i++)
        {
            if(arrayTrabajos[i].isEmpty==0 && autos[indiceDelAutoElegido].isEmpty==0)
            {
                if(arrayTrabajos[i].idAuto==autos[indiceDelAutoElegido].id)
                {
                    indiceServicio=buscarServicioPorId(servicios, tamServ, arrayTrabajos[i].idServicio);
                    acumuladorDeImporte+=servicios[indiceServicio].precio;
                    mostrarUnTrabajo(arrayTrabajos[i], autos, tamAuto, servicios, tamServ, marcas, tamMarca,colores, tamColores);
                }
            }
        }

        printf("\nLa suma de los importes realizados al auto es: %d\n\n", acumuladorDeImporte);
        todoOk=1;
	}
	return todoOk;
}

int autosDeUnServicio(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores)
{
    int idDelServicio;
    int todoOk=0;
    int idDelAutoConElServicioElegido;
    char descripcionServicio[20];
    int indiceAuto;
    int noHuboServicio=1;

    if(arrayTrabajos!=NULL && tamTrab>0 && autos!=NULL && tamAuto>0 && servicios!=NULL && tamServ>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColores>0)
    {
        system("cls");
        mostrarTrabajos(arrayTrabajos, tamTrab, autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
        printf("\n--------------------------------------------------------------------------------------------------------------\n");
        printf("           ***   Informes de los autos que se realizaron un determinado servicio    ***             \n");
        printf("-------------------------------------------------------------------------------------------------------------\n");

        printf("\nElija un servicio para luego mostrar los autos que se realizaron dicho servicio\n");
        mostrarServicios(servicios, tamServ);
        ingresoEntero(&idDelServicio, "Ingrese el id del servicio: ", "Error. Ingrese el id del servicio: ", 20000, 20003);

        cargarDescripcionServicio(servicios, tamServ, idDelServicio, descripcionServicio);

        printf("\nLos autos que se realizaron el servicio %s son:\n", descripcionServicio);
        printf("  Fecha     Id  Marca      Color     Caja   \n");

        for(int i=0;i<tamTrab;i++)
        {
            indiceAuto=buscarAutoPorId(autos, tamAuto, arrayTrabajos[i].idAuto);

            if(arrayTrabajos[i].isEmpty==0 && indiceAuto>=0)
            {
                if(arrayTrabajos[i].idServicio==idDelServicio)
                {
                    printf("%02d/%02d/%d  ",
                    arrayTrabajos[i].fecha.dia,
                    arrayTrabajos[i].fecha.mes,
                    arrayTrabajos[i].fecha.anio);
                    idDelAutoConElServicioElegido=buscarAutoPorId(autos, tamAuto, arrayTrabajos[i].idAuto);
                    mostrarUnAuto(autos[idDelAutoConElServicioElegido], marcas, tamMarca, colores, tamColores);
                    noHuboServicio=0;

                }
            }
        }
        if(noHuboServicio)
        {
            printf("\nNingun auto se realizo el servicio de %s\n", descripcionServicio);
        }
        todoOk=1;
	}
	return todoOk;
}

int serviciosEnUnaFecha(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores)
{
    int todoOk=0;
    char descripcionServicio[20];
    eFecha auxFecha;
    int indiceAuto;
    int noHuboServicio=1;

    if(arrayTrabajos!=NULL && tamTrab>0 && autos!=NULL && tamAuto>0 && servicios!=NULL && tamServ>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColores>0)
    {

        system("cls");
        mostrarTrabajos(arrayTrabajos, tamTrab, autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
        printf("\n--------------------------------------------------------------------------------------------------------------\n");
        printf("           ***   Informe de los servicios realizados en una fecha    ***             \n");
        printf("-------------------------------------------------------------------------------------------------------------\n");

        validarFecha(&auxFecha);

        printf("\nLos servicios realizados en la fecha %02d/%02d/%d son:\n",
                auxFecha.dia,
                auxFecha.mes,
                auxFecha.anio);

        for(int i=0;i<tamTrab;i++)
        {
            indiceAuto=buscarAutoPorId(autos, tamAuto, arrayTrabajos[i].idAuto);

            if(arrayTrabajos[i].isEmpty==0 && indiceAuto>=0)
            {
                if(arrayTrabajos[i].fecha.dia==auxFecha.dia && arrayTrabajos[i].fecha.mes==auxFecha.mes && arrayTrabajos[i].fecha.anio==auxFecha.anio)
                {
                       cargarDescripcionServicio(servicios, tamServ, arrayTrabajos[i].idServicio, descripcionServicio);
                       printf(" -%s\n", descripcionServicio);

                       noHuboServicio=0;
                }
            }
        }

        if(noHuboServicio)
        {
            printf("\nNo se realizaron servicios en la fecha: %02d/%02d/%d\n",
            auxFecha.dia,
            auxFecha.mes,
            auxFecha.anio);
        }
        todoOk=1;
	}
	return todoOk;
}

int informesAutosTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores)
{
    int opcion;
    system("cls");
    printf("---------------------------------------------------------------------------------------------------------------\n");
    printf("         *** Informes de autos relacionados con trabajos y servicios (Bonus Track)  ***             \n");
    printf("----------------------------------------------------------------------------------------------------------------\n");

    printf("7- Pedir un auto y mostrar todos los trabajos que se le hicieron al mismo\n");
    printf("\n8- Pedir un auto e informar la suma de los importes que se le hicieron al mismo\n");
    printf("\n9- Pedir un servicio y mostrar los autos a los que se realizo ese servicio y la fecha.\n");
    printf("\n10- Pedir una fecha y mostrar todos los servicios realizados en la misma.\n");
    printf("\n11- Salir\n");

    printf("\nIngrese opcion: ");
    scanf("%d", &opcion);

    switch(opcion)
    {
        case 7:
            printf("\nCase 7\n");
            trabajosDeUnAuto(arrayTrabajos, tamTrab, autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
            break;

        case 8:
            printf("\nCase 8\n");
            importeTotalDeUnAuto(arrayTrabajos, tamTrab, autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
            break;

        case 9:
            printf("\nCase 9\n");
             autosDeUnServicio(arrayTrabajos, tamTrab, autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
            break;

        case 10:
            printf("\nCase 10\n");
            serviciosEnUnaFecha(arrayTrabajos, tamTrab, autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
            break;

        case 11:
            //Salir
            printf("\nChau, chau, adios\n");
            break;

        default:
            printf("Opcion Invalida!!!!!!");
            break;
    }
    return opcion;
}

int menuInformes(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, int hayUnAuto, int hayUnTrabajo)
{
    int todoOk=0;
    int opcion;
    system("cls");

    printf("-----------------------------------------------------------------------\n");
    printf("                ***  Informes  ***             \n");
    printf("-----------------------------------------------------------------------\n");

    printf("1- Informes solo de autos\n");
    printf("2- Informes de autos relacionados con trabajos y servicios (Bonus Track)\n");
    printf("3- Salir\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                if(hayUnAuto)
                {
                    informeSoloDeAutos(autos, tamAuto, marcas, tamMarca, colores, tamColores);
                }
                else
                {
                    printf("\nNo se pueden realizar los informes de autos si no hay ningun auto activo\n");
                }
                break;

            case 2:
                if(hayUnTrabajo)
                {
                    informesAutosTrabajos(arrayTrabajos, tamTrab, autos, tamAuto, servicios, tamServ, marcas, tamMarca, colores, tamColores);
                }
                else
                {
                    printf("\nNo se pueden realizar los informes de trabajos si no hay ningun trabajo activo\n");
                }
                break;

            case 3:
                printf("\nSalida exitosa del menu de informes!\n");
            break;

            default:
                printf("Opcion invalida!!!!!!!\n");
                break;
        }
    return todoOk;
}
