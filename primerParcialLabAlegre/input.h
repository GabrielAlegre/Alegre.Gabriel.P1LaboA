#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED



#endif // INPUT_H_INCLUDED



/** \brief funcion que se encarga de validar un numero.
 *
 * \param pEnteroAValidar[] char donde se guardara el numero para ser validado
 * \return int Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 *
 */
 int validarEntero(char pEnteroAValidar[]);

/** \brief funcion que permite pedir un numero entero y a su vez validarlo.
 *
 * \param enteroValidado int* Puntero a entero que se le asignara el valor del numero ya validado.
 * \param mensaje[] char Cadena de caracteres que contiene el mensaje que le aparecera al usuario al momento de pedir un numero entero.
 * \param mensajeError[] char Cadena de caracteres que contiene un mensaje de error que le aparecera al usuario al momento de ingresar un numero entero invalido.
 * \param min int minimo que debe tener el numero entero.
 * \param max int minimo que debe tener el numero entero.
 * \return int Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 *
 */
int ingresoEntero(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max);

/** \brief Funcion que permite pedir un numero flotante y a su vez validarlo.
 *
 * \param flotanteValidado float* Puntero a float al cual se le asignara el valor del numero ya validado segun los parametros min y max.
 * \param mensaje[] char Cadena de caracteres que contiene el mensaje que le aparecera al usuario al momento de pedir un numero flotante.
 * \param mensajeError[] char Cadena de caracteres que contiene un mensaje de error que le aparecera al usuario al momento de ingresar un numero flotante invalido.
 * \param min float Valor minimo que debe tener el numero flotante.
 * \param max float Valor maximo que debe tener el numero flotante.
 * \return int Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 *
 */
int validarFlotante(float* flotanteValidado, char mensaje[], char mensajeError[], float min, float max);

/** \brief  Funcion que recibe una cadena de caracteres (por ejemplo un nombre) y lo valida verificando que esta no tenga mas caracteres de los permitidos y que no contenga ningun numero.
 *
 * \param cadena[] char Cadena de caracteres a validar.
 * \param mensaje[] char Mensaje que le aparecera al usuario al momento de pedir una cadena de caracteres.
 * \param mensajeError[] char Mensaje de error que le aparecera al usuario al momento de ingresar un string invalido, por ejemplo si ingresa un string con mas caracteres de los permitidos.
 * \param max int la cantidad maxima de caracteres que puede llegar a tener la cadena.
 * \return int Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 *
 */
int validarCadena(char cadena[], char mensaje[], char mensajeError[], int max);


/** \brief Funcion que le pide al usuario un char y valida que dicho char este dentro de las 2 opciones recibidas en el parametro.
 *	por ejemplo, si quiero verificar que el usuario ingrese s/n la opcion1 va a ser 's' y la opcion2 'n', si el char ingresado
 *	no coincide con ninguna de las dos opciones le aparecera el mensaje de error hasta que lo ingrese correctamente.
 *
 * \param charAValidar char* Caracter a verificar.
 * \param mensaje[] char Mensaje que le aparecera al usuario al momento de pedir el char.
 * \param mensajeError[] char Mensaje de error que le aparecera al usuario al momento de ingresar un caracter invalido.
 * \param opcionUno char primera opcion que puede ingresar el usuario.
 * \param opcionDos char segunda opcion que puede ingresar el usuario.
 * \return int Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 *
 */
int validarCaracter(char* charAValidar, char mensaje[], char mensajeError[], char opcionUno, char opcionDos);


/** \brief verifica que una cadena de caracteres (por ejemplo un nombre) contenga solo letras.
 *
 * \param palabra[] char Cadena de caracteres a validar que contenga solo letras.
 * \return int Retorna 1 si se verifica que la palabra solo contiene letras y retorna 0 si la palabra contiene algo distinto a solo letras.
 *
 */
int SoloLetras(char palabra[]);

/** \brief funcion que "ordena" una cadena de caracteres. Por ejemplo, si ingresa: "dAniEl sEbAStiAn" la funcion lo ordena a: "Daniel Sebastian"
 *
 * \param cadena[] char Cadena de caracteres a ordenar.
 * \return int Retorna 1 en caso de no haber ningun error o 0 en caso de error.
 *
 */
int ordenarCadena(char cadena[]);
