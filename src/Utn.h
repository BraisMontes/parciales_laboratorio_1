/*
 * Utn.h
 *
 *  Created on: 25 may. 2022
 *      Author: brais
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */
int myGets(char* cadena, int tamanio);
int utn_getNombre(char array[], int tamanio, char* mensaje, char* mensajeError, int reintentos );
int esNombre (char array [], int tamanio);
int getNombre (char pResultado[], int tamanio);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getInt(int* pResultado);
int getNumeroFlotante(float* pResultado, char mensaje[], char errorMensaje[], float minimo, float maximo, int reintentos);
int getFloat(float* pResultado);
int esFlotante(char* cadena,int limite);
int esNumerica (char* cadena, int tamanio);
int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);
int getAlfanumerico(char inPut[],char mensaje[], char errorMensaje[],int tamano, int reintentos);
