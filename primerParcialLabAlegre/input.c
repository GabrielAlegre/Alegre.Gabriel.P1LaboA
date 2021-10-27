#include "input.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int validarEntero(char pEnteroAValidar[])
{
	int todoOk = 1;

	if(strlen(pEnteroAValidar) > 0)
	{
		for(int i = 0;i< strlen(pEnteroAValidar);i++)
		{
			if(isdigit(pEnteroAValidar[i]) == 0)
			{
				if(i == 0 && pEnteroAValidar[0] == '-')
				{
                    todoOk = 1;

				}
				else
				{
					todoOk = 0;
				}
			}
		}
	}
    else
    {
        todoOk=0;
    }

	return todoOk;
}

int ingresoEntero(int* enteroValidado, char mensaje[], char mensajeError[], int min, int max)
{
	char auxEntero[150];
	int todoOk = 0;

	if(enteroValidado != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s",mensaje);
		fflush(stdin);
		gets(auxEntero);

		while(validarEntero(auxEntero) == 0 || atoi(auxEntero) > max || atoi(auxEntero) < min)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(auxEntero);
		}

		*enteroValidado = atoi(auxEntero);
		todoOk = 1;
	}
	return todoOk;
}

int validarFlotante(float* flotanteValidado, char mensaje[], char mensajeError[], float min, float max)
{
	int todoOk = 0;
	float numeroIngresado;

	if(flotanteValidado != NULL && mensaje != NULL && mensajeError != NULL && min < max)
	{
		printf("%s", mensaje);
		fflush(stdin);
		scanf("%f", &numeroIngresado);

		while(numeroIngresado < min || numeroIngresado > max)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			scanf("%f", &numeroIngresado);
		}

		*flotanteValidado = numeroIngresado;
		todoOk = 1;
	}
	return todoOk;
}

int validarCadena(char cadena[], char mensaje[], char mensajeError[], int max)
{
	int retorno = 0;
	char auxString[256];

	if(cadena != NULL && mensaje != NULL && mensajeError != NULL && max > 0)
	{
		printf("%s", mensaje);
		fflush(stdin);
		gets(auxString);

		while(strlen(auxString)> max || SoloLetras(auxString)==0)
		{
			printf("%s", mensajeError);
			fflush(stdin);
			gets(auxString);
		}
		strcpy(cadena, auxString);
		ordenarCadena(cadena);

		retorno = 1;
	}
	return retorno;
}

int validarCaracter(char* charAValidar, char mensaje[], char mensajeError[], char opcionUno, char opcionDos)
{
    int todoOk=0;
    char respuesta;

    if(mensaje!=NULL && mensajeError!=NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c",&respuesta);

        while(respuesta != opcionUno && respuesta != opcionDos)
        {
                printf("%s", mensajeError);
                fflush(stdin);
                scanf("%c",&respuesta);
        }

        *charAValidar=respuesta;
        todoOk=1;
    }
    return todoOk;
}

int SoloLetras(char palabra[])
{
    int soloHayLetras=1;
    int i=0;

    if(palabra!=NULL)
    {
        while(palabra[i]!='\0')
        {
            if((palabra[i]!=' ')&&(palabra[i] < 'a'||  palabra[i] > 'z') && (palabra[i] < 'A' || palabra[i] > 'Z'))
            {
                soloHayLetras=0;
            }
            i++;
        }
    }
    return soloHayLetras;
}


int ordenarCadena(char cadena[])
{
    int todoOk=0;
    int i=0;

    if(cadena!=NULL)
    {
        strlwr(cadena);
        cadena[0]=toupper(cadena[0]);

        while(cadena[i]!='\0')
        {
            if(cadena[i]==' ')
            {
                cadena[i+1]=toupper(cadena[i+1]);
            }
            i++;
        }
        todoOk=1;
    }
    return todoOk;
}

