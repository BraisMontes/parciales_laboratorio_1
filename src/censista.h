/*
 * censista.h
 *
 *  Created on: 25 may. 2022
 *      Author: brais
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "viviendas.h"

#ifndef CENSISTA_H_
#define CENSISTA_H_
typedef struct{
int legajoCensista;
char nombre[10];
int edad;
char telefono[15];
}eCensistas;


#endif /* CENSISTA_H_ */
int printCensistas(eCensistas* array,int tam);
