#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct{

    int id;
    char nombreColor[20];

}eColor;


#endif // COLOR_H_INCLUDED


/** \brief carga la descripcion de la estrucutura color que coincida con el id recibido como parametro.
 *
 * \param ArrayColor[] eColor vector de color.
 * \param tamColor int tamanio del array de color.
 * \param idColor int id a buscar.
 * \param descripcionColor[] char cadena de caracteres donde se copiara la descripcion de la estructura de color.
 * \return int retorna 1 si no hubo error o 0 si ha ocurrido un error.
 *
 */
int cargarDescripcionColor(eColor ArrayColor[], int tamColor, int idColor, char descripcionColor[]);

/** \brief muestra todos los colores disponibles para que el usuario elija uno atravez de su id
 *
 * \param ArrayColor[] eColor lista de colores
 * \param tamColor int tamanio del array
 * \return int retorna 1 si no hubo error o 0 si ha ocurrido un error.
 *
 */
int mostrarColor(eColor ArrayColor[], int tamColor);
