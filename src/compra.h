/*
 * contrataciones.h
 *
 *  Created on: Apr 28, 2021
 *      Author: Diego Maiorano
 */
#include "cliente.h"

#ifndef COMPRA_H_
#define COMPRA_H_
#define LEN_COLOR 20
#define LEN_DIRECCION 12
#define LEN_ESTADOCOMPRA 22
typedef struct
{
		char estadoCompra[LEN_ESTADOCOMPRA];
		int idCliente;
		int cantBarbijos;
		char colorBarbijo[LEN_COLOR];
		char direccionDeEntrega[LEN_DIRECCION];
		int id;
		int isEmpty;
		int importe;
}Compra;
int com_imprimir(Compra* pElemento);
int com_imprimirArray(Compra* arrayCompra,int limiteCompra);
int com_inicializoArray(Compra* arrayCompra,int limiteCompra);
int com_cargarProducto(Compra* arrayCompra, int limiteCompra, int indice);
int com_ordenarPorNombreYCantDias(Compra* arrayCompra,int limiteCompra);
int com_ordenarPorNombre(Compra* arrayCompra,int limiteCompra);
int com_getEmptyIndex(Compra* arrayCompra,int limiteCompra);
int com_buscarId(Compra* arrayCompra,int limiteCompra,int valorBuscado);
int com_bajaArray(Compra* arrayCompra,int limiteCompra,Cliente* arrayClientes,int limiteClientes,int indice);
int com_altaArray(Compra* arrayCompra,int limiteCompra,int indice,int* idContratacion,int idPantalla);
int com_cancelarCompra(Compra* arrayCompra,int limiteCompra,Cliente* arrayClientes,int limiteClientes,int idCliente);
int com_altaForzadaArray(Compra* arrayCompra,int limiteCompras,int indice,int* idCompra,int idCliente,char* colorBarbijo,char* direccionDeEntrega,int cantBarbijos,int importe);
int com_pagarCompra(Compra* arrayCompra,int limite,int indice);
int com_buscarVentasDeCliente(Compra* arrayCompra,int limiteCompra,Cliente* arrayCliente,int auxIdVenta);
int compra_getIndexById(Compra* listadoCompras, int lenCompras, int idCompra);
int com_calcularColorBarbijoMasComprado(Compra* arrayCompras,int limiteCompras);



#endif /* COMPRA_H_ */
