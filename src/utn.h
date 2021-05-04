/*
 * utn.h
 *
 *  Created on: Apr 22, 2021
 *      Author: Diego Maiorano
 */

#ifndef UTN_H_
#define UTN_H_

int get_myGets(char* pResultado, int len);

int get_int(int* pResultado,int len,char* mensaje,char* mensajeError,int minimo, int maximo, int reintentos,int flagSigned);
int get_float(float* pResultado,int len,char* mensaje,char* mensajeError, int minimo, int maximo, int reintentos,int flagSigned);
int get_name(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
int get_text(char* pResultado,int len,char* mensaje,char* mensajeError, int reintentos);
int get_dni(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_tarjeta(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_cuit(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_telefono(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_email(char* pResultado,char* mensaje,char* mensajeError,int reintentos);

/*
 * FUNCIONES PARA OBTENER DATOS
 */

#endif /* UTN_H_ */
