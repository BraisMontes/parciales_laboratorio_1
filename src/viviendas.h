/*
 * viviendas.h
 *
 *  Created on: 24 may. 2022
 *      Author: brais
 */
#include <stdio.h>
#include <stdlib.h>

#ifndef VIVIENDAS_H_
#define VIVIENDAS_H_
#define NOMBRE_LEN 25
typedef struct{
int idVivienda;
char calle[25];
int cantidadPersonas;
int cantidadHabitaciones;
int tipoDeVivienda; //1)Casa. 2)departamento,3)casilla,4)rancho
int legajoCensista;
int isEmpty;
}eViviendas;



#endif /* VIVIENDAS_H_ */
int initArray(eViviendas* list,int len);
int addViviendas(eViviendas* list, int len, int* id, int indice);
int buscarLibre(eViviendas* list, int tam);
int viviendaPrint(eViviendas auxPasajero);
int printViviendas(eViviendas* list, int length);
int findViviendaById(eViviendas* list, int len,int id);
void viviendaModificarMenu(eViviendas* list ,int tamTexto);
int removeVivienda(eViviendas* list, int len, int id);
int viviendaOrdenarPorCalleCantidadPersonas (eViviendas* array,int tamanio);

