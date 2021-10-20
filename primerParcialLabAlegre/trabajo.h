#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"
#include "servicio.h"
#include "auto.h"
#include "color.h"
#include "marca.h"

typedef struct{

    int idTrabajo;;
    int idAuto; //en el pdf decia patente, pero me guio mejor con el nombre "idAuto"
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // TRABAJO_H_INCLUDED
int inicializarTrabajos(eTrabajo arrayDeTrabajos[], int tamTrab);

int buscarLibreTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab);

int altaDeTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, int* pIdTrabajo);

int mostrarUnTrabajo(eTrabajo unTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

int mostrarTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);
