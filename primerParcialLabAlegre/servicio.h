#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct{

    int id;
    char descripcionServicio[20];
    int precio;

}eServicio;

#endif // SERVICIO_H_INCLUDED

/** \brief carga la descripcion de la estrucutura servicio que coincida con el id recibido como parametro.
 *
 * \param ArrayServicios[] eservicio vector de servicio.
 * \param tamServicio int tamanio del array de servicio.
 * \param idServicio int id a buscar.
 * \param descripcionServicio[] char cadena de caracteres donde se copiara la descripcion de la estructura de servicio.
 * \return int retorna 1 si no hubo error o 0 si ha ocurrido un error.
 *
 */
int cargarDescripcionServicio(eServicio ArrayServicios[], int tamServicio, int idServicio, char descripcionServicio[]);

/** \brief muestra todos los servicios disponibles
 *
 * \param ArrayServicios[] eServicio array que contiene los servicios disponibles
 * \param tamServicio int tamanio del array de servicios
 * \return int retorna 0 en caso de error o 1 si esta todo ok
 *
 */
int mostrarServicios(eServicio ArrayServicios[], int tamServicio);

/** \brief Se le pedira al usuario ingresar un id y la funcion se encargara de busca y encontra al servicio que coincida con dicha id ingresada.
 *
 * \param arrayDeServicios[] eServicio array que contiene a todos los servicio, que sera recorrido hasta encontrar al servicio que coincida con el id.
 * \param tamSer int tamanio del array servicio
 * \param idServicio int variable que contiene el valor del id del servicio a buscar.
 * \return int retorna el indice donde se encuntra el servicio que coincide con la id o -1 si no se encontro el servicio o si la funcion no se pudo realizar correctamente.
 *
 */
int buscarServicioPorId(eServicio arrayDeServicios[], int tamSer, int idServicio);
