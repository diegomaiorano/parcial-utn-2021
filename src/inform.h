/*
 * inform.h
 *
 *  Created on: Apr 30, 2021
 *      Author: Diego Maiorano
 */

#ifndef INFORM_H_
#define INFORM_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "validaciones.h"
#include "cliente.h"
#include "compra.h"

int info_subMenu(Compra* arrayCompras,int limiteCompras,int comprasPendientes);
int	info_calcularImporteMasBajo(Compra* arrayCompras,int limiteCompras,float* importeMasBajo,int* auxIdCompra);
int info_listarCompra(Compra* arrayCompras,Cliente* arrayClientes,int limiteCompras,int limiteClientes,int auxIdCliente);
int	info_comprasById(Compra* arrayCompras,int limiteCompras,Cliente* arrayClientes,int limiteClientes,char* auxiliarId);
int info_listarVentas(Compra* arrayCompras,Cliente* arrayClientes,int limiteCompras,int limiteClientes,int auxIdVenta,int idCliente);
int info_cantComprasPendientes(Compra* arrayCompras,int limiteCompras);


#endif /* INFORM_H_ */
