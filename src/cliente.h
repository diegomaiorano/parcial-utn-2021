/*
 * entidad.h
 *
 *  Created on: Apr 26, 2021
 *      Author: Diego Maiorano
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define	LEN_NOMBRE 13
#define LEN_CUIT 20
#define	LEN_APELLIDO 12
typedef struct
{
		int id;
		char nombre[LEN_NOMBRE];
		char cuit[LEN_CUIT];
		char apellido[LEN_APELLIDO];
		int isEmpty;


}Cliente;
void cargarTxtTipo(Cliente* pElemento,char cadenaTipo[]);
int cli_imprimir(Cliente* pElemento);
int cli_imprimirArray(Cliente* array,int limite);
int cli_inicializoArray(Cliente* array,int limite);
void mostrarValores(Cliente valor);
void mostrarValoresPorReferencia(Cliente* valor);
int cargarProducto(Cliente* array, int limite, int indice);
int ordenarPorNombreYPrecio(Cliente* array,int limite);
int ordenarPorNombre(Cliente* array,int limite);
int getEmptyIndex(Cliente* array,int limite);
int cli_buscarId(Cliente* array,int limite,int valorBuscado);
int cli_bajaArray(Cliente* array,int limite,int indice);
int cli_modificarArray(Cliente* array,int limite,int indice);
int cli_altaArray(Cliente* array,int limite,int indice,int* idCliente);
int cli_altaForzadaArray(Cliente* array,int limite,int indice,int* idPantalla,char* nombre,char* apellido,char* cuit);
int cli_imprimirClientePorIndice(Cliente* arrayClientes, char* mensaje,int indice);
int cli_getIndexById(Cliente* arrayClientes, int limiteClientes, int idCliente);
#endif /* CLIENTE_H_ */
