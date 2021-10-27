#ifndef HARDCODEO_H_INCLUDED
#define HARDCODEO_H_INCLUDED
#include "auto.h"
#include "trabajo.h"



#endif // HARDCODEO_H_INCLUDED

/** \brief funcion para hardcodear los datos de los autos
 *
 * \param arrayAutos[] eAuto lista de autos activos
 * \param tamAuto int tamanio del array de autos
 * \param cantidadACargar int cantidad de indices a cargar con datos hardcodeados
 * \param pIdAuto int* puntero a entero para incrementar el id
 * \return int retorna -1 si hubo un error o la cantidad de cargas
 *
 */
int harcodearAutos(eAuto arrayAutos[], int tamAuto, int cantidadACargar, int* pIdAuto);

/** \brief funcion para hardcodear los datos de los trabajos
 *
 * \param trabajo[] eTrabajo lista de trabajos activos
 * \param tamTrabajo int tamanio del array de trabajos
 * \param cant int cantidad de indices a cargar con datos hardcodeados
 * \param pIdTrabajo int* puntero a entero para incrementar el id
 * \return int retorna -1 si hubo un error o la cantidad de cargas
 *
 */
int hardcodearTrabajos(eTrabajo trabajo[], int tamTrabajo, int cant, int* pIdTrabajo);
