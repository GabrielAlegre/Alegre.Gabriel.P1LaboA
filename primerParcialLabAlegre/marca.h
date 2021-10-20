#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];

}eMarca;

#endif // MARCA_H_INCLUDED

/** \brief carga la descripcion de la estrucutura marca que coincida con el id recibido como parametro.
 *
 * \param ArrayMarcas[] eMarca lista de las marcas
 * \param tamMarca int tam del array marca
 * \param idMarca int id a buscar.
 * \param descripcionMarca[] char cadena de caracteres donde se copiara la descripcion.
 * \return int retorna 1 si no hubo error o 0 si ha ocurrido un error.
 *
 */
int cargarDescripcionMarca(eMarca ArrayMarcas[], int tamMarca, int idMarca, char descripcionMarca[]);

/** \brief muestra todas las marcas disponibles para que el usuario elija uno atravez de su id
 *
 * \param ArrayMarcas[] eMarca lista de las marcas discponibles
 * \param tamMarca int tamanio del array marca
 * \return int retorna 1 si no hubo error o 0 si ha ocurrido un error.
 *
 */
int mostrarMarcas(eMarca ArrayMarcas[], int tamMarca);
