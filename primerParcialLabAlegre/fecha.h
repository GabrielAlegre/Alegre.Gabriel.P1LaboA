#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct{

    int dia;
    int mes;
    int anio;

}eFecha;

#endif // FECHA_H_INCLUDED


/** \brief Valida fecha
 *
 * \param fecha eFecha*
 * \return int retorna 0 no hubo error o -1 si hubo error
 *
 */
int validarFecha(eFecha* fecha);
