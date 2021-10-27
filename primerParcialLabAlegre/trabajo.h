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

/** \brief Funcion que verifica si hay un indice libre en la lista de trabajos, de haberlo, da de alta a un trabajo cargando todos los campos de la estructura.
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \param pIdTrabajo int* puntero a entero que hacer incrementar al id de trabajos
 * \return int retorna 0 hubo error o 1 si esta todo ok
 *
 */
int altaDeTrabajo(eTrabajo arrayDeTrabajos[], int tamTrab, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, int* pIdTrabajo);

/** \brief
 *
 * \param unTrabajo eTrabajo funcion que recibe la estructura de un auto como parametro e imprime el valor de sus campos.
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 hubo error o 1 si esta todo ok
 *
 */
int mostrarUnTrabajo(eTrabajo unTrabajo, eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

/** \brief esta funcion muestra la lista de los autos que esten activos en ese momento
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 hubo error o 1 si esta todo ok
 *
 */
int mostrarTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

/** \brief sub menu de todos los informes que esten relacionados con los trabajos
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 hubo error o 1 si esta todo ok
 *
 */
int informesAutosTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

/** \brief menu donde estan todos los informes informes con sus respectivas opciones
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 hubo error o 1 si esta todo ok
 *
 */
int menuInformes(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores, int hayUnAuto, int hayUnTrabajo);


/** \brief funcion que contiene un sub menu con los informes relacionados al trabajo
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos activos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos activos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 en caso de haber algun error o 1 si esta todo ok
 *
 */
int informesAutosTrabajos(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

//7mo informe
/** \brief funcion que pide un auto y mostrar todos los trabajos que se le hicieron al mismo
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos activos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos activos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 en caso de haber algun error o 1 si esta todo ok
 *
 */
int trabajosDeUnAuto(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

//8vo informe
/** \brief funcion que pide un auto e informar la suma de los importes que se le hicieron al mismo
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos activos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos activos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 en caso de haber algun error o 1 si esta todo ok
 *
 */
int importeTotalDeUnAuto(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

//9no informe
/** \brief funcion que pide un servicio y mostrar los autos a los que se realizo ese servicio y la fecha
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos activos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos activos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 en caso de haber algun error o 1 si esta todo ok
 *
 */
int autosDeUnServicio(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);

//10mo informe
/** \brief funcion que pide una fecha y mostrar todos los servicios realizados en la misma.
 *
 * \param arrayDeTrabajos[] eTrabajo lista de trabajos activos
 * \param tamTrab int tamanio del array de trabajos
 * \param autos[] eAuto array de autos activos
 * \param tamAuto int tamanio del array de autos
 * \param servicios[] eServicio array donde estaran todos los servicios disponibles
 * \param tamServ int tamanio del array de servicios
 * \param marcas[] eMarca array donde estaran todas las marcas disponibles
 * \param tamMarca int tamanio del array de marcas
 * \param colores[] eColor lista de todos los colores disponibles
 * \param tamColores int tamanio del array de colores
 * \return int retorna 0 en caso de haber algun error o 1 si esta todo ok
 *
 */
int serviciosEnUnaFecha(eTrabajo arrayTrabajos[], int tamTrab,  eAuto autos[], int tamAuto, eServicio servicios[], int tamServ, eMarca marcas[], int tamMarca, eColor colores[], int tamColores);
