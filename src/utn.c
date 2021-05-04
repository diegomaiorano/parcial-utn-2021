/*
 * utn.c
 *
 *  Created on: Apr 22, 2021
 *      Author: Diego Maiorano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"

#define LEN_DNI 11
#define LEN_CUIT 20
#define LEN_EMAIL 30
#define LEN_TELEFONO 14
#define LEN_TARJETA 20

/*
 * \brief Recibe una cadena con fgets, le remueve el enter del final y devuelve el resultado por referencia
 * \param string Puntero a la direccion de memoria del string
 * \param len Tamaño del array. Limite de caracteres/digitos
 * \return -1 si hubo error de validacion, 1 si no hubo errores.
 * */
int get_myGets(char* pResultado, int len)
{
	int retorno = -1;
	fflush(stdin);
	if(pResultado != NULL && len > 0 && fgets(pResultado,len,stdin)==pResultado)
	{
		fflush(stdin);
		if(pResultado[strnlen(pResultado,len)-1]== '\n')
		{
			pResultado[strnlen(pResultado,len)-1]='\0';
		}
		retorno = 1;
	}
	return retorno;
}

											//FUNCIONES PARA OBTENER
/*
 * \brief Pide un numero entero
 * \param int* pResultado Puntero a la dirección de memoria donde guardar el valor obtenido y validado
 * \param int len Tamaño del array indica el maximo de digitos del numero (hay que descontar el EOF y el signo menos, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int flagMaximoMinimo: Indica si acepta valores maximos y minimos (1) o no (0)
 * \param int minimo Valor minimo a recibir
 * \param int maximo Valor maximo a recibir
 * \param int reintentos Cantidad de reintentos
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 *
 * \return Devuelve 1 si pudo obtener un entero, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */

int get_int(int* pResultado,int len,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos,int flagSigned)
{
	int retorno = -1;
	char buffer[len];
	int bufferInt;
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno= 0;
		for(int i=0; i <= reintentos ;reintentos--)
		{
			printf("%s",mensaje);
			fflush(stdin);
			if(get_myGets(buffer,len) && val_isValidInt(buffer,flagSigned))
			{
					bufferInt=atoi(buffer);
				if(bufferInt <= maximo && bufferInt >= minimo)
				{

					*pResultado = bufferInt;
					retorno = 1;
					break;
				}

			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}

/*
 * \brief Pide un numero flotante
 * \param float* pResultado Puntero a la dirección de memoria donde guardar el valor obtenido y validado
 * \param int len Tamaño del array indica el maximo de digitos del numero (hay que descontar el EOF y el signo menos, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int flagMaximoMinimo: Indica si acepta valores maximos y minimos (1) o no (0)
 * \param int minimo Valor minimo a recibir
 * \param int maximo Valor maximo a recibir
 * \param int reintentos Cantidad de reintentos
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return Devuelve 1 si pudo obtener un flotante, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_float(float* pResultado,int len,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos,int flagSigned)
{
	int retorno = -1;
	char buffer[len];
	float bufferFloat;
	if(pResultado != NULL && len > 0 && mensaje != NULL && minimo <= maximo && mensajeError != NULL && reintentos >= 0)
	{
		retorno = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,len) &&
				val_isValidFloat(buffer,flagSigned)==1)
			{
				bufferFloat=atof(buffer);
				if(bufferFloat >= minimo && bufferFloat <= minimo)
				{
					*pResultado = bufferFloat;
					retorno = 1;
					break;
				}
				else
				{
					*pResultado = bufferFloat;
					retorno = 1;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno ;
}

/*
 * \brief Pide un nombre
 * \param int* pResultado Puntero a la dirección de memoria donde guardar el dato obtenido y validado
 * \param int len Tamaño del array indica el maximo de caracteres del nombre (hay que descontar el EOF y espacios, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un nombre, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_name(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno  = -2;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno  = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, len) && val_isValidName(buffer))
			{
				strncpy(pResultado,buffer,len);
				retorno  = 1;
				break;
			}
			else
			{
				printf("%s",mensajeError);
			}
			reintentos--;
		}
	}
	return retorno;
}

/*
 * \brief Pide un texto no vacio
 * \param char* pResultado Puntero a la dirección de memoria donde guardar el texto obtenido
 * \param int len Tamaño del array indica el maximo de caracteres del texto (hay que descontar el EOF)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un texto, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_text(char* pResultado,int len,char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL)
	{
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, len) && buffer[0] != 0)
			{
				strncpy(pResultado,buffer,len);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}

/*
 * \brief Pide un dni
 * \param char* pResultado Dirección de memoria del array de caracteres donde almacenar el dni
 * \param int len Tamaño máximo del dni
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un dni, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_dni(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -2;
	char buffer[LEN_DNI];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, LEN_DNI) && val_isValidDni(buffer))
			{
				strncpy(pResultado,buffer,LEN_DNI);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}

int get_telefono(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -2;
	char buffer[LEN_TELEFONO];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,LEN_TELEFONO) && val_isValidTelefono(buffer))
			{
				strncpy(pResultado,buffer,LEN_TELEFONO);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}

/*
 * \brief Pide un cuit
 * \param char* pResultado Dirección de memoria del array de caracteres donde almacenar el cuit
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un cuit, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_cuit(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -2;
	char buffer[LEN_CUIT];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,LEN_CUIT)==1 && val_isValidCuit(buffer)==0)
			{
				strncpy(pResultado,buffer,LEN_CUIT);
				retorno=1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}

int get_email(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int retorno = -1;
	char buffer[LEN_EMAIL];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		retorno = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,LEN_EMAIL) && val_isValidEmail(buffer)==1)
			{
				strncpy(pResultado,buffer,LEN_EMAIL);
				retorno = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return retorno;
}
