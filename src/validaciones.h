/*
 * validaciones.h
 *
 *  Created on: Apr 25, 2021
 *      Author: Diego Maiorano
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

int val_isValidInt(char* numero, int flagSigned);
int val_isValidFloat(char* numero, int flagSigned);
int val_isValidName(char* nombre);
int val_isValidDni(char* dni);
int val_isValidTelefono(char* telefono);
int val_isValidTarjeta(char* tarjeta);
int val_isValidCuit(char* cuit);
int val_isValidEmail(char* email);
int val_cantidadDigitos(char* arrayParaVerificar);
int val_cuitDigitoVerificador(char* cuit);


int val_isInWhiteList(char* caracterParaComparar, char* listaBlanca,int len);

#endif /* VALIDACIONES_H_ */
