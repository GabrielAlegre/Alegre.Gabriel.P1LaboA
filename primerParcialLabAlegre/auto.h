#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "color.h"
#include "marca.h"

typedef struct{

    int id;
    int idMarca;
    int idColor;
    char caja;
    int isEmpty;

}eAuto;


#endif // AUTO_H_INCLUDED

/** \brief Para indicar que todas las posiciones del array están vacías, esta función pone los isEmpty en TRUE(1) en todas las posiciones del array.
 *
 * \param arrayAutos[] eAuto lista de autos
 * \param tamAuto int tamanio del array
 * \return int int retorna 0 si no hubo error o -1 si hubo error.
 *
 */
int inicializarAutos(eAuto arrayAutos[], int tamAuto);

int buscarLibre(eAuto arrayAutos[], int tamAuto);

int altaAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor, int* pIdAuto);

int mostrarUnAuto(eAuto unAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int mostrarAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int buscarAutoPorId(eAuto arrayAutos[], int tamAuto, int idAuto);

int bajaAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

int modificarAuto(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

/** \brief Funcion que muestra el menu con las opciones para realizar una modificion .
 *
 * \return char retorna la opcion elegida por el usuario.
 *
 */
char menuDeModificacion();

int buscarSiHayUnAuto(eAuto arrayAutos[], int tamAuto, int* banderaHayUnAuto);

int ordenarAutos(eAuto arrayAutos[], int tamAuto, eMarca marcas[], int tamMarca, eColor colores[], int tamColor);

