/*
 * inform.c
 *
 *  Created on: Apr 30, 2021
 *      Author: Diego Maiorano
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"
#include "cliente.h"
#include "compra.h"
#define CANT_COMPRAS 1000
#define CANT_CLIENTES 100

int info_subMenu(Compra* arrayCompras,int limiteCompras,int comprasPendientes)
{
	int retorno=-1;
	int opcion;
	float importeMasBajo;
	int auxIdCompra;

	if(get_int(&opcion,2,"\n--SUBMENU--\n"
						"INGRESE UNA OPCION:\n"
						"1)Mostrar color de barbijo que se compró mas veces.\n"
						"2)Mostrar cantidad de compras pendientes.\n"
						"3)Mostrar compra con “precio por unidad” mas bajo.\n","La opcion es incorrecta\n",1,3,2,0)==1)
	{
		switch(opcion)
		{
		case 1:
			com_calcularColorBarbijoMasComprado(arrayCompras,CANT_COMPRAS);
			break;
		case 2:
			printf("La cantidad de compras pendientes es:%d\n",comprasPendientes);
			break;
		case 3:
			info_calcularImporteMasBajo(arrayCompras,CANT_COMPRAS,&importeMasBajo,&auxIdCompra);
			printf("El importe mas bajo es:%.2f--ID DE LA COMPRA:%d\n",importeMasBajo,auxIdCompra);
			break;

		}
	}

	return retorno;
}
int info_cantComprasPendientes(Compra* arrayCompras,int limiteCompras)
{
	int retorno=-1;
	int i;
	int contadorComprasPendientes;
	if(arrayCompras != NULL && limiteCompras >= 0)
	{
		for(i=0;i<limiteCompras;i++)
		{
			if(strncmp(arrayCompras[i].estadoCompra,"Pendiente a cobrar",22)==0)
			{
				contadorComprasPendientes++;
				retorno=0;
				printf("ABRA ENTRAO?");
			}
		}
		printf("La cantidad de compras pendientes es:%d",contadorComprasPendientes);
	}


	return retorno;
}

int info_listarCompra(Compra* arrayCompras,Cliente* arrayClientes,int limiteCompras,int limiteClientes,int auxIdCliente)
{
	int retorno=-1;
	int i;

	if(arrayCompras != NULL && arrayClientes != NULL && limiteCompras > 0 && limiteClientes > 0 )
	{
		for(i=0;i<limiteCompras;i++)
		{
			if(arrayCompras[i].isEmpty==0)
			{
			if(arrayCompras[i].idCliente == auxIdCliente)
			{
			//	indiceArrayCompras=com_buscarId(arrayCompras,limiteCompras,auxIdCliente);
				printf("ID CLIENTE:%d\n------COMPRAS:\nCANTIDAD DE BARBIJOS:%d-----"
													"COLOR DE BARBIJO:%s-----"
													"DIRECCION DE ENTREGA:%s\n",auxIdCliente,arrayCompras[i].cantBarbijos,arrayCompras[i].colorBarbijo,arrayCompras[i].direccionDeEntrega);
				retorno=0;
			}
			}
		}
	}
	return retorno;
}
int info_listarVentas(Compra* arrayCompras,Cliente* arrayClientes,int limiteCompras,int limiteClientes,int auxIdVenta,int idCliente)
{
	int retorno=-1;
	int i;
	int auxIdCliente;
	int indiceArrayCliente;
	if(arrayCompras != NULL && arrayClientes != NULL && limiteCompras > 0 && limiteClientes > 0 )
	{

		for(i=0;i<limiteCompras;i++)
		{
			if(arrayCompras[i].isEmpty==0)
			{
				if(arrayCompras[i].id==auxIdVenta)
				{
					auxIdCliente=arrayCompras[i].idCliente;
					indiceArrayCliente=cli_buscarId(arrayClientes,limiteCompras,auxIdCliente);
					printf("ID CLIENTE:%d---NOMBRE:%s-----CUIT:%s-----APELLIDO:%s----\n",arrayClientes[indiceArrayCliente].id,arrayClientes[indiceArrayCliente].nombre,arrayClientes[indiceArrayCliente].apellido,arrayClientes[indiceArrayCliente].cuit);
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int	info_comprasById(Compra* arrayCompras,int limiteCompras,Cliente* arrayClientes,int limiteClientes,char auxiliarId)
{
	int retorno=-1;
	int i;
	int indiceArrayCompra;//PARA ESTABLECER LA RELACION
	int auxId;
	auxId=auxiliarId;
	if(arrayCompras != NULL && limiteCompras > 0 && arrayClientes != NULL && limiteClientes > 0)
	{
		for(i=0;i<limiteCompras;i++)
		{
			if(arrayCompras[i].isEmpty == 0)
			{
				continue;
			}

				if(arrayCompras[i].id == auxId)//SI EL CUIT YA FUE INGRESADO ENTONCES SE MUESTRAN LAS CONDICIONES
				{
					retorno=0;
					indiceArrayCompra=cli_buscarId(arrayClientes,limiteClientes,auxId);
					printf("ID CLIENTE:%d\n"
							"NOMBRE:%s\n"
							"APELLIDO:%s\n"
							"CUIT:%s\n",arrayClientes[i].id,arrayClientes[i].nombre,arrayClientes[i].apellido,arrayClientes[i].cuit);
					printf("ID DE LA COMPRA::%d\n",arrayCompras[indiceArrayCompra].id);
				}
		}
	}
	return retorno;
}
/*
int com_bajaArray(Compra* arrayCompra,int limiteCompra,Cliente* arrayClientes,int limiteClientes,int idCliente)
{
	int retorno=-1;
	int opcion;
	int i;
	if(arrayCompra != NULL && limiteCompra > 0 && idCliente < limiteCompra && idCliente >= 0 && arrayCompra[idCliente].isEmpty==0)
	{
		if(get_int(&opcion,2,"CONFIRME SI QUIERE ELIMINAR LOS DATOS:\n"
				   	     	 "0)NO--"
				   	     	 "1)SI","OPCION INCORRECTA.\n",0,1,2,0)==1)
		{
			if(opcion==1)
			{
				for(i=0;i<limiteCompra;i++)
				{
					arrayClientes[idCliente].isEmpty=1;
						if(arrayCompra[i].idCliente == idCliente)
						{
							arrayCompra[i].isEmpty=1;
							retorno=0;
						}

			}

		}
	}
	return retorno;
}
*/
int	info_calcularImporteMasBajo(Compra* arrayCompras,int limiteCompras,float* importeMasBajo,int* auxIdCompra)
{
	int retorno=-1;
	int i;
	float importeBase=10000;
	float importeSegunCantidad;
	float primerValor=0;
	int flag=0;
	if(arrayCompras != NULL && limiteCompras > 0 && importeMasBajo >=0)
	{
		for(i=0;i<limiteCompras;i++)
		{
			if(arrayCompras[i].isEmpty==0)
			{
				importeSegunCantidad=(float)arrayCompras[i].importe/arrayCompras[i].cantBarbijos;
				if(importeSegunCantidad<=importeBase && flag==0)
				{
					primerValor=importeSegunCantidad;
					flag++;
				}
				if(importeSegunCantidad < primerValor && flag != 0)
				{
					*importeMasBajo=importeSegunCantidad;
						*auxIdCompra=arrayCompras[i].id;
				}
			}
		}
		retorno=0;
	}
	return retorno;
}
