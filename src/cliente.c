/*
 * entidad.c
 *
 *  Created on: Apr 26, 2021
 *      Author: Diego Maiorano
 */

#include "cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"

#define	LEN_DIRECCION 20
/*
 * brief Imprime el array
 * array Puntero al array de alumnos
 * return retorna 0(EXITO) y -1(ERROR)
 */

int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;
		if(pElemento != NULL && pElemento->isEmpty == 0)
		{
			retorno=0;
			printf("NOMBRE:%s----"
					"CUIT:%s----"
					"APELLIDO:%s----"
					"ID DEL CLIENTE:%d----\n",pElemento->nombre,pElemento->apellido,pElemento->cuit,pElemento->id);
		}
	return retorno;
}
/*
 * brief LLAMA A FUNCION PARA IMPRIMIR ARRAY
 * param array Puntero al array de alumnos
 * param limite define el tamaño del array
 * return retorna 0(EXITO) y -1(ERROR)
 */
int cli_imprimirArray(Cliente* array,int limite)
{
	int i;
	int retorno=-1;
	if(array != NULL && limite > 0 )
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			cli_imprimir(&array[i]);
		}
	}
	return retorno;
}
/*
 * brief INICIALIZO EL ARRAY DE PERSONAS
 * param array Puntero al array de alumnos
 * param limite define el tamaño del array
 * return retorna 0(EXITO) y -1(ERROR)
 */
int cli_inicializoArray(Cliente* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		retorno=0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return retorno;
}
/*
 * brief da de alta un array
 * param limite define el tamaño del array
 * param indice define el indice del array
 * param idCliente define el id del cliente generado
 * return retorna -1 (ERROR) y 0(EXITO)
 */
int cli_altaArray(Cliente* array,int limite,int indice,int* idCliente)
{
	int retorno=-1;
	Cliente auxiliar;
	if(array != NULL && idCliente != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		if(get_name(auxiliar.nombre,15,"Ingrese nombre:\n","ERROR\n",2) ==1 &&
			get_text(auxiliar.apellido,15,"Ingrese su apellido:\n","ERROR\n",2)==1)
		{
			if(get_cuit(auxiliar.cuit,"Ingrese su cuit:\n", "ERROR",2)==1)
			{
				auxiliar.id=*idCliente;
				auxiliar.isEmpty=0;
				array[indice]=auxiliar;
				(*idCliente)++;
				retorno=0;
			}
		}
	}
	return retorno;
}
/*
 * brief da de alta forzada de un array
 */
int cli_altaForzadaArray(Cliente* array,int limite,int indice,int* idCliente,char* nombre,char* apellido,char* cuit)
{
	int retorno=-1;
	Cliente auxiliar;
	if(array != NULL && idCliente != NULL && limite > 0 && indice < limite && indice >= 0)
	{
		strncpy(auxiliar.nombre,nombre,LEN_NOMBRE);
		strncpy(auxiliar.apellido,apellido,LEN_APELLIDO);
		strncpy(auxiliar.cuit,cuit,LEN_CUIT);

		auxiliar.id=*idCliente;
		auxiliar.isEmpty=0;
		array[indice]=auxiliar;
		(*idCliente)++;
		retorno=0;
	}
	return retorno;
}
/*
 * brief busca el id  en el array
 * param limiteClientes define el tamaño del array
 * param idCliente define el id cliente
 * return retorna -2(ERROR DE PARAMETRO) y -1(ERROR) y i si hay exito
 */

int cli_getIndexById(Cliente* arrayClientes, int limiteClientes, int idCliente)
{
	int retorno = -2;
	int i;
	if(arrayClientes != NULL && limiteClientes > 0 && idCliente > 0)
	{
		retorno = -1;
		for(i=0;i<limiteClientes;i++)
		{
			if(arrayClientes[i].id == idCliente)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
/*
 * brief imprime el cliente por un indice especifico
 * param mensaje define el mensaje que le aparecera al usuario
 * param indice define el indice especifico  del array
 * return retona -1(ERROR) y 0(EXITO)
 */
int cli_imprimirClientePorIndice(Cliente* arrayClientes, char* mensaje,int indice)
{
	int retorno = -1;
	if(arrayClientes != NULL && mensaje != NULL && indice >= 0)
	{
		retorno = 0;
		printf("%s",mensaje);
		printf("\nId:%d)--Apellido:%s--Nombre:%s--CUIT:%s\n",arrayClientes[indice].id,arrayClientes[indice].apellido,arrayClientes[indice].nombre,arrayClientes[indice].cuit);
	}
	return retorno;
}
/*
 * brief permite modificar los datos de un array
 * param limite define el tamaño del array
 * param indice define el indice del array
 * return retorna -1 (ERROR) y 0(EXITO)
 */
int cli_modificarArray(Cliente* array,int limite,int indice)
{
	int retorno=-1;
	Cliente auxiliar;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty==0)
	{
		if(get_name(auxiliar.nombre,15,"Ingrese nombre:\n","ERROR\n",2)==1 &&
					get_text(auxiliar.apellido,15,"Ingrese apellido:\n","ERROR\n",2)==1 &&
					get_cuit(auxiliar.cuit,"Ingrese cuit:\n","ERROR\n",2)==1)
		{
			retorno=0;
			auxiliar.id=array[indice].id;
			auxiliar.isEmpty=0;
			array[indice]=auxiliar;
		}
	}
	return retorno;
}
/*
 * brief permite dar de baja un array
 * param limite define el tamaño del array
 * param indice define el indice del array
 * return retorna -1 (ERROR) y 0(EXITO)
 */
int cli_bajaArray(Cliente* array,int limite,int indice)
{
	int retorno=-1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty==0)
	{
		array[indice].isEmpty=1;
		retorno=0;
	}
	return retorno;
}
/*
 * brief permite buscar el id en un array
 * param limite define el tamaño del array
 * param valor buscado para comparar y buscar la igualdad;
 * return retorna -1 (ERROR) y != -1(EXITO)
 */

int cli_buscarId(Cliente* array,int limite,int valorBuscado)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].id==valorBuscado)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
/*
 * brief inicializa el array
 * param array puntero al array de clientes
 * param limite define el tamaño del array
 * return retorna -1(ERROR) y != -1(EXITO)
 *
 */
int getEmptyIndex(Cliente* array,int limite)
{
	int retorno=-1;
	int i;
	if(array != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty==1)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
