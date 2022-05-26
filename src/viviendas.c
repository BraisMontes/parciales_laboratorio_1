/*
 * viviendas.c
 *
 *  Created on: 24 may. 2022
 *      Author: brais
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "viviendas.h"
#include "censista.h"
#include "Utn.h"

int initArray(eViviendas* list, int len){
	int retorno = -1;
	 if(list != NULL && len>0){
		 retorno = 0;
		 for(int i=0;i<len;i++){
			 list[i].isEmpty=1;
		 }
	 }
	 return retorno;
	}
int addViviendas(eViviendas* list, int len, int* id, int indice){
	int retorno = -1;


	eViviendas bufferViviendas;
	if(list != NULL && len >0 && id > 0 && list[indice].isEmpty == 1){
		if(utn_getNombre(bufferViviendas.calle,NOMBRE_LEN,"\n Ingrese Calle\n","\n Calle invalida\n",2)==0
				&& utn_getNumero(&bufferViviendas.cantidadPersonas,"\nIngrese cantidad de personas\n", "\n Cantidad de personas ingresadas invalidas\n",1,10,2)==0
				&& utn_getNumero(&bufferViviendas.cantidadHabitaciones,"\nIngrese cantidad de habitaciones\n","Cantidad de habitaciones ingresadas incorrectas\n",1,10,2) == 0
				&& utn_getNumero(&bufferViviendas.tipoDeVivienda,"\n Ingrese tipo de vivienda\n1)Casa\n2)Departamento\n3)Casilla\n4)Rancho", "\n tipo de vivienda ingresada incorrecta\n",1,4,2)==0){
				retorno = 0;
				bufferViviendas.idVivienda = *id;
				bufferViviendas.isEmpty = 0;
				list[indice]= bufferViviendas;
				*id = *id + 1;

			}

	}
	return retorno;
}
int buscarLibre(eViviendas* list, int tam){
int indice=-1;

	if(list != NULL && tam>0){
		for(int i=0;i<tam;i++){

			if(list[i].isEmpty==1){
				indice=i;
				break;
			}
		}
	}
	return indice;
}
int viviendaImprimir(eViviendas auxVivienda){
	int retorno = -1;
	if(auxVivienda.isEmpty == 0){
		retorno = 0;
		printf("\n       ALTA    \n");
		printf("\n--------------------------------------------------------------------------------------------------\n");
		printf("\n ID:        CALLE:              CANT PERSONAS          CANT HABITACIONES              TIPO VIVIENDA\n");
		printf("\n%d -      %s -                   %d -                    %d -                           %d\n", auxVivienda.idVivienda, auxVivienda.calle, auxVivienda.cantidadPersonas,auxVivienda.cantidadHabitaciones,auxVivienda.tipoDeVivienda);
		printf("\n--------------------------------------------------------------------------------------------------\n");
	}
	return retorno;
}
int printViviendas(eViviendas* list, int length){
	int respuesta=-1;
	if(list != NULL && length > 0){
		respuesta=0;
		for(int i=0;i<length;i++){
			viviendaImprimir(list[i]);
		}
	}
	return respuesta;

}
int findViviendaById(eViviendas* list, int len,int id){
int indice =-1;
	if(list != NULL && len>0){
		for(int i=0;i<len;i++){
			if(list[i].idVivienda== id && list[i].isEmpty == 0){
				indice = i;
				break;
			}else{
				printf("error by id");
				printf("ID: %d indice %d", id ,indice);


			}
		}
	}
	return indice;
}
void viviendaModificarMenu(eViviendas* list ,int tamTexto){
	int opcion;
	do{
		if(utn_getNumero(&opcion,"\nIngrese numero de la opcion que quiere modificar\n1)Calle\n2)Cantidad de personas\n3)Cantidad de habitaciones\n4)Tipo de Vivienda\n5)Salir\n","\nOpcion no valida\n",1,5,2)==0){
			switch(opcion){
			case 1:
				if(utn_getNombre(list->calle,tamTexto,"\nIngrese nombre\n","\nError nombre ingresado invalido\n",2)==0){
					printf("\nCalle modificada con exito\n");

				}
				break;

			case 2:
				if(utn_getNumero(&list->cantidadPersonas,"\nIngrese la cantidad de personas\n","\nError cantidad de personas ingresadas invalidas\n",1,10,2)==0){

						printf("\nCantidad de personas modificadas con exito\n");

				}
				break;
			case 3:
				if(utn_getNumero(&list->cantidadHabitaciones,"\nIngrese cantidad de habitaciones\n","\nERROR cantidad de habitaciones ingresadas invalidas\n",1,10,2)==0){
					printf("Cantidad de habitaciones modificadas con exito");
				}
				break;
			case 4:
				if(utn_getNumero(&list->tipoDeVivienda, "\nTipo de vivienda,\n1)Casa\n2)Departamento0\n3)Casilla\n4)Rancho","\n Tipo de pasajero incorrecto\n",1,2,2)==0){
					printf("\nTipo de vivienda modificada con exito\n");
				}
				break;
			case 5:
				break;

			}
		}

	}while(opcion != 5);
}
int removeVivienda(eViviendas* list, int len, int id){
	int retorno = -1;

	if (list != NULL && list->isEmpty == 0 && len>0){
		for(int i=0;i<len;i++){
			if(list[i].idVivienda == id && list[i].isEmpty == 0){

				list->isEmpty = 1;
			}
		}
			retorno = 0;
		}

	return retorno;
}
int viviendaOrdenarPorCalleCantidadPersonas (eViviendas* array,int tamanio){

	int retorno = -1;
	int flagSwap;
	int i;
	eViviendas bufferSwap;


	if (array != NULL && tamanio >0){

			do {
				  flagSwap = 0;

				  for (i = 0 ; i< tamanio - 1; i++)
				  {
						if (array[i].isEmpty == 1 || array[i + 1].isEmpty == 1 ){

								continue;
						}

							if(strncmp(array[i].calle, array[i + 1].calle,NOMBRE_LEN) > 0)

							{
								flagSwap = 1;
								bufferSwap = array[i];
								array[i] = array[i + 1];
								array[i + 1] = bufferSwap;

							}
					else if (strncmp(array[i].calle, array[i + 1].calle,NOMBRE_LEN) == 0 &&  array[i].cantidadPersonas > array[i + 1].cantidadPersonas)

							{
									flagSwap = 1;
									bufferSwap = array[i];
									array[i] = array[i + 1];
									array[i + 1] = bufferSwap;
							}

				  }

				  tamanio --;

			}while (flagSwap);

			retorno = 0;
	}

	return retorno;
}

