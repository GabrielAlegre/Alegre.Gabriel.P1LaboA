#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "input.h"
#include "auto.h"
#include "color.h"
#include "marca.h"
#include "hardcodeo.h"
#include "servicio.h"
#include "trabajo.h"

#define TAM_COLOR 5
#define TAM_MARCA 5
#define TAM_AUTO 20
#define TAM_SERVICIO 4
#define TAM_TRAB 20


int main()
{
    char salir='n';
    int nextIdAutos=1;
    int nextIdTrabajo=1;
    int hayUnAuto=0;
    int hayUnTrabajo=0;

    eAuto listaDeAutos[TAM_AUTO];
    eTrabajo listaDeTrabajos[TAM_TRAB];

    eColor colores[TAM_COLOR]={ {5000, "Negro"}, {5001, "Blanco"}, {5002, "Rojo"}, {5003, "Gris"}, {5004, "Azul"}};

    eMarca marcas[TAM_MARCA]={ {1000, "Renault"}, {1001, "Ford"}, {1002, "Fiat"}, {1003, "Chevrolet"}, {1004, "Peugeot"}};

    eServicio servicios[TAM_SERVICIO]={ {20000, "Lavado", 450}, {20001, "Pulido", 500}, {20002, "Encerado", 600}, {20003, "Completo", 900}};


    if(inicializarAutos(listaDeAutos, TAM_AUTO)==-1)
    {
        printf("Ocurrio un problema al inicializar los autos");
    }

    if(inicializarTrabajos(listaDeTrabajos, TAM_TRAB)==-1)
    {
        printf("Ocurrio un problema al inicializar los trabajos");
    }

    harcodearAutos(listaDeAutos, TAM_AUTO, 10, &nextIdAutos);
    hayUnAuto=1;

    hardcodearTrabajos(listaDeTrabajos, TAM_TRAB, 10, &nextIdTrabajo);
    hayUnTrabajo=1;

    do{
        switch(menu())
        {
            case 'A':
                altaAuto(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR,&nextIdAutos);
                hayUnAuto=1;
                break;

            case 'B':
                if(hayUnAuto)
                {
                    modificarAuto(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR);
                }
                else
                {
                    printf("\nNo hay ningun auto para modificar, opcion A para dar de alta e ingresar un auto\n\n");
                }
                break;

            case 'C':
                if(hayUnAuto)
                {
                    bajaAuto(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR);
                }
                else
                {
                    printf("\nNo hay ningun auto para dar de baja, opcion A para dar de alta e ingresar un auto\n\n");
                }
                buscarSiHayUnAuto(listaDeAutos, TAM_AUTO, &hayUnAuto);
                break;

            case 'D':
                if(hayUnAuto)
                {
                    ordenarAutos(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR);
                    mostrarAutos(listaDeAutos, TAM_AUTO, marcas, TAM_MARCA, colores, TAM_COLOR);
                }
                else
                {
                    printf("\nNo hay ningun auto para listar, opcion A para dar de alta e ingresar un auto\n\n");
                }
                break;

            case 'E':
                system("cls");
                mostrarMarcas(marcas, TAM_MARCA);
                break;

            case 'F':
                system("cls");
                mostrarColor(colores, TAM_COLOR);
                break;
            case 'G':
                system("cls");
                mostrarServicios(servicios, TAM_SERVICIO);
                break;
            case 'H':
                if(hayUnAuto)
                {
                    altaDeTrabajo(listaDeTrabajos, TAM_TRAB, listaDeAutos, TAM_AUTO, servicios, TAM_SERVICIO, marcas, TAM_MARCA, colores, TAM_COLOR, &nextIdTrabajo);
                    hayUnTrabajo=1;
                }
                else
                {
                    printf("\nNo hay ningun auto para dar de alta a un trabajo, opcion A para dar de alta e ingresar un auto\n\n");
                }
                break;
            case 'I':
                if(hayUnAuto && hayUnTrabajo)
                {
                    mostrarTrabajos(listaDeTrabajos, TAM_TRAB, listaDeAutos, TAM_AUTO, servicios, TAM_SERVICIO, marcas, TAM_MARCA, colores, TAM_COLOR);
                }
                else
                {
                    printf("\nNo hay trabajos para en listar\n\n");
                }
                break;

            case 'J'://Valido que no se pueda informar si no hay autos o trabajos dentro de la funcion menuInformes

                menuInformes(listaDeTrabajos, TAM_TRAB, listaDeAutos, TAM_AUTO, servicios, TAM_SERVICIO, marcas, TAM_MARCA, colores, TAM_COLOR, hayUnAuto, hayUnTrabajo);

                break;

            case 'K':
                validarCaracter(&salir, "Esta seguro que desea salir s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');
                if(salir=='n')
                {
                    printf("\nSe ha cancelado la salida\n");
                }
                else
                {
                    printf("\nSalida exitosa!.\n\n");
                }
                break;

            default:
                printf("Opcion invalida!!!\n");
                break;
        }
        system("pause");

      }while(salir=='n');

    return 0;
}
