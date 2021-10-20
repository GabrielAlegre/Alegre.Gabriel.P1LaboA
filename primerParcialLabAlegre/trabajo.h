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


/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone los isEmpty en TRUE(1) en todas las posiciones del array.
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array trabajos
 * \return int retorna 0 si no hubo error o -1 si hubo error
 *
 */
int inicializarTrabajos(eTrabajo arrayDeTrabajos[], int tamTrab);

/** \brief Esta funcion recorre todas las posiciones del array hasta encontrar el primer indice libre (isEmpty en 1) para luego retornarl
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array trabajos
 * \return int retorna 0 si no hubo error o -1 si hubo error
 *
 */
int buscarLibreTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab);

//No me dio el tiempo para seguir con los doxygen

int altaDeTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, int* pIdTrabajo);

int mostrarUnTrabajo(eTrabajo unTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

int mostrarTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);
