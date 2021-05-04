/*
 ============================================================================
 Name        : parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct cliente{
	char nombreCompleto[60];
	int cuit;
};
struct compra{
	int idCliente;
	int cantidadBarbijos;
	char direccionEnvio[64];
	char color[32];

};

int main(void) {
	puts("!!!Hello World9!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}
