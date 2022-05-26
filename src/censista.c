/*
 * censista.c
 *
 *  Created on: 25 may. 2022
 *      Author: brais
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "censista.h"

int printCensistas(eCensistas* array,int tam){
	int retorno=-1;
	if(array != NULL && tam>0){
		retorno=0;
		for(int i=0;i<3;i++){
			printf("\n---------------------------------------------------------------------------------------------\n");
			printf("\nLegajo Censista     Nombre     Edad     Telefono\n");
			printf("\n    %d -            %s -     %d -     %s\n", array[i].legajoCensista, array[i].nombre,array[i].edad, array[i].telefono);
			printf("\n---------------------------------------------------------------------------------------------\n");
		}
	}
	return retorno;
}

