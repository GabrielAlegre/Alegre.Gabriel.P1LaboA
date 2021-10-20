#include "auto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "color.h"
#include "marca.h"
#include "input.h"

int inicializarAutos(eAuto arrayAutos[], int tamAuto)
{
    int todoOk=0;

    if(arrayAutos!=NULL && tamAuto>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            arrayAutos[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibre(eAuto arrayAutos[], int tamAuto)
{
    int indiceLibre=-1;

    if(arrayAutos!=NULL && tamAuto>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(arrayAutos[i].isEmpty)
            {
                indiceLibre=i;
                break;//xq solo necesitamos el PRIMER indice que encontremos libre una vez encontrado no hay que buscar mas.
            }
        }
    }
    return indiceLibre;
}

int altaAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int* pIdAuto)
{
    int todoOk=0;
    int indiceLibre;
    eAuto auxAuto;

    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0 && pIdAuto!=NULL)
    {
        system("cls");
        indiceLibre=buscarLibre(arrayAutos, tamAuto);

        if(indiceLibre==-1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("--------------------------------------------------------------------------------------\n");
            printf("                     ***   Alta de Autos   ***             \n");
            printf("--------------------------------------------------------------------------------------\n");

            auxAuto.id= *pIdAuto;
            (*pIdAuto)++;

            mostrarMarcas(marcas, tamMarca);
            validarEntero(&auxAuto.idMarca, "Ingrese el id de la marca del auto: ", "Error. Ingrese el id de la marca del auto: ", 1000, 1004);

            mostrarColor(colores, tamColor);
            validarEntero(&auxAuto.idColor, "Ingrese el id del color de auto: ", "Error. Ingrese el id del color de auto: ", 5000, 5004);

            validarCaracter(&auxAuto.caja, "Ingrese caja ('m' manual, 'a' automatica): ", "Error. Ingrese caja (“m” manual, “a” automática): ", 'm','a');

            auxAuto.isEmpty=0;

            arrayAutos[indiceLibre]=auxAuto;

            printf("\nExcelente. Se realizo correctamente la alta del auto: \n");
            printf("Id\tMarca      Color     Caja\n");
            mostrarUnAuto(arrayAutos[indiceLibre], marcas, tamMarca, colores, tamColor);
        }
        todoOk=1;
    }
    return todoOk;
}

int mostrarUnAuto(eAuto unAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
    char descripcionMarca[20];
    char descripcionColor[20];

    if(marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {
        cargarDescripcionColor(colores, tamColor, unAuto.idColor, descripcionColor);
        cargarDescripcionMarca(marcas, tamMarca, unAuto.idMarca, descripcionMarca);

        printf("%d\t%-10s %-10s %c\n",
           unAuto.id,
           descripcionMarca,
           descripcionColor,
           unAuto.caja);

        todoOk=1;
    }
    return todoOk;
}

int mostrarAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=1;
    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {
        system("cls");
        printf("--------------------------------------------------------------------------------------\n");
        printf("                     ***   Lista de Autos   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");
        printf("Id\tMarca      Color     Caja\n");

        for(int i=0; i<tamAuto; i++)
        {
            if(arrayAutos[i].isEmpty==0)
            {
                mostrarUnAuto(arrayAutos[i], marcas, tamMarca, colores, tamColor);
            }
        }
        todoOk=1;
    }

    return todoOk;
}

int buscarAutoPorId(eAuto arrayAutos[], int tamAuto, int idAuto)
{
    int indiceDeIdEncontrado=-1;
    if(arrayAutos!=NULL && tamAuto>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(arrayAutos[i].id==idAuto && arrayAutos[i].isEmpty==0)
            {
                indiceDeIdEncontrado=i;
                break;
            }
        }
    }
    return indiceDeIdEncontrado;
}

int bajaAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
    int idAutoBaja;
    int indiceAutoBajar;
    char confirmacionDeBaja;

    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {


        printf("\n");
        mostrarAutos(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Dar de baja un auto   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID del auto a dar de baja: ");
        scanf("%d", &idAutoBaja);

        indiceAutoBajar=buscarAutoPorId(arrayAutos, tamAuto, idAutoBaja);

        if(indiceAutoBajar>=0)
        {
            printf("Id\tMarca      Color     Caja\n");
            mostrarUnAuto(arrayAutos[indiceAutoBajar], marcas, tamMarca, colores, tamColor);

            validarCaracter(&confirmacionDeBaja,
            "Esta seguro que desea dar de baja a este auto (s/n): ",
            "Respuesta Invalida. 's' para confirmar baja o 'n' para cancelar baja: ",
            's',
            'n');

            if(confirmacionDeBaja=='s')
            {
                arrayAutos[indiceAutoBajar].isEmpty=1;
                printf("Baja exitosa!\n");
                todoOk=1;
            }
            else
            {
                printf("Se ha cancelado la baja\n");
            }
        }
        else
        {
            printf("No se encontro el ID %d\n", idAutoBaja);
        }
    }
    return todoOk;
}

char menuDeModificacion()
{
    char opcion;
    printf("\nQue le desea modificar al auto: \n");
    printf("A- Color \n");
    printf("B- Marca/Modelo \n");
    printf("C- Cancelar Modificacion\n");

    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=toupper(opcion);

    return opcion;
}

int modificarAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
{
    int todoOk=0;
    int idAutoModificar;
    int indiceModificarAuto;
    char confirmacionModificar;
    char opcionMenuModificacion;
    eAuto auxAuto;

    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {
        printf("\n");
        mostrarAutos(arrayAutos, tamAuto, marcas, tamMarca, colores, tamColor);
        printf("\n--------------------------------------------------------------------------------------\n");
        printf("                     ***   Modificar Auto   ***             \n");
        printf("--------------------------------------------------------------------------------------\n\n");

        printf("Ingrese el ID del auto a modificar: ");
        scanf("%d", &idAutoModificar);

        indiceModificarAuto=buscarAutoPorId(arrayAutos, tamAuto, idAutoModificar);

        if(indiceModificarAuto>=0)
        {
            printf("Id\tMarca      Color     Caja\n");

            mostrarUnAuto(arrayAutos[indiceModificarAuto], marcas, tamMarca, colores, tamColor);

            validarCaracter(&confirmacionModificar,
            "Esta seguro que desea modificar este auto (s/n): ",
            "Respuesta Invalida. 's' para confirmar modificacion o 'n' para cancelar modificacion: ",
            's',
            'n');

            if(confirmacionModificar=='s')
            {
                opcionMenuModificacion=menuDeModificacion();

                switch(opcionMenuModificacion)
                {
                    case 'A':
                        mostrarColor(colores, tamColor);
                        if(validarEntero(&auxAuto.idColor, "Ingrese el id del color a modificar: ", "Error. Ingrese el id modificado del color del auto: ", 5000, 5004))
                        {
                            arrayAutos[indiceModificarAuto].idColor=auxAuto.idColor;

                            printf("Modificacion exitosa!!!\n");
                        }
                        break;

                    case 'B':
                        mostrarMarcas(marcas, tamMarca);
                        if(validarEntero(&auxAuto.idMarca, "Ingrese el id marca a modificar: ", "Error. Ingrese el id modificado de la marca del auto: ", 1000, 1004))
                        {
                            arrayAutos[indiceModificarAuto].idMarca=auxAuto.idMarca;

                            printf("Modificacion exitosa!!!\n");
                        }

                        printf("Modificacion exitosa!!!\n");
                        break;

                    case 'C':
                        printf("Se ha cancelado la modificacion\n");
                        confirmacionModificar='n';
                        break;

                    default:
                        printf("Opcion invalida!!!\n");
                        break;
                }
            }
            else
            {
                printf("Se ha cancelado la modificacion\n");
            }
        }
        else
        {
            printf("No se encontro el ID %d\n", idAutoModificar);
        }
    }
    return todoOk;
}

 int buscarSiHayUnAuto(eAuto arrayAutos[], int tamAuto, int* banderaHayUnAuto)
 {
    int todoOk=0;

    if(arrayAutos!=NULL && tamAuto>0)
    {
        for(int i=0; i<tamAuto; i++)
        {
            if(arrayAutos[i].isEmpty==0)
            {
                *banderaHayUnAuto=1;
                break;
            }
            else
            {
                *banderaHayUnAuto=0;
            }
        }
        todoOk=1;
    }
    return todoOk;
 }

 int ordenarAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor)
 {

    int todoOk=0;
    char descripcionMarcaPadre[20];
    char descripcionMarca[20];
    eAuto auxAuto;

    if(arrayAutos!=NULL && tamAuto>0 && marcas!=NULL && tamMarca>0 && colores!=NULL && tamColor>0)
    {
        for(int i=0; i<tamAuto-1; i++)
        {
            for(int j=i+1; j<tamAuto; j++)
            {
                cargarDescripcionMarca(marcas, tamMarca, arrayAutos[i].idMarca, descripcionMarcaPadre);
                cargarDescripcionMarca(marcas, tamMarca, arrayAutos[j].idMarca, descripcionMarca);

                //Ascendente
                if(strcmp(descripcionMarcaPadre, descripcionMarca)>0 || (strcmp(descripcionMarcaPadre, descripcionMarca)==0 && arrayAutos[i].id>arrayAutos[j].id))
                {
                    auxAuto=arrayAutos[i];
                    arrayAutos[i]=arrayAutos[j];
                    arrayAutos[j]=auxAuto;
                }
            }
        }
        todoOk=1;
    }
    return todoOk;






 }
