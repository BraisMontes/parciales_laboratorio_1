/*
 ============================================================================
 Name        : ParcialLaboUno.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include "viviendas.h"
#include "censista.h"
#include "Utn.h"
#define LEN 5
#define NOMBRE_LEN 25
#define TAMCEN 3
int main(void) {
setbuf(stdout,NULL);
char opcion;
eViviendas vivienda[LEN];
int idVivienda=20000;
int flagAlta=0;
int indice;
int verificoAlta;
int verificoModificacion;
int verificoIdBaja;
int verificoBaja;
int verificoOrdenamiento;
int contCensistaAna=0;
int contCensistaJuan=0;
int contCensistaSol=0;

eCensistas censistas[LEN]={{100,"Ana",34,"1203-2345"},{101,"Juan",24,"4301-54678"},{102,"Sol",47,"5902-37487"}};
if(initArray(vivienda,LEN)==0){
	do{
		printf("\nElija la opcion a)Alta vivienda\nb)Modificar Vivienda\nc)Baja de la vivienda\nd)Listar Viviendas\ne)Listar censistas\nf)ListadoCensistasViviendas\ng)Salir");
		scanf("%c", &opcion);

		switch(opcion){
		case 'a':
			printCensistas(censistas,LEN);
			indice = buscarLibre(vivienda, LEN);
			if(utn_getNumero(&vivienda[indice].legajoCensista,"\nIngrese el legajo del censista\n","\nError legajo invalido\n",100,103,2)==0){
				printf("\nAlta Viviendas\n");

				if(indice == -1){
					printf("\nError, no se realizo el alta\n");

				}else{
					verificoAlta= addViviendas(vivienda,LEN,&idVivienda,indice);
					if(verificoAlta != -1)
					{
						printf("\nAlta realizada con exito\n");
					}
				}
			}
				flagAlta=1;
			break;
		case 'b':
			printViviendas(vivienda,LEN);
			if(flagAlta == 1){
			printf("\nModificar Viviendas\n");
			if(utn_getNumero(&idVivienda,"\n Ingrese el id que desea modificar\n","Id ingresado invalido\n",20000,20003,2)==0){
				verificoModificacion= findViviendaById(vivienda,LEN,idVivienda);
				if(verificoModificacion != -1){
					viviendaModificarMenu(vivienda,NOMBRE_LEN);
				}

			}

			}
			break;
		case 'c':
			if(flagAlta==1){

				printf("\nBaja de la vivienda\n");
				printViviendas(vivienda,LEN);
				if(utn_getNumero(&idVivienda,"\nIngrese el id que desea dar de baja\n","\nId ingresado invalido\n",20000,20003,2)==0){
					verificoIdBaja= findViviendaById(vivienda,LEN,idVivienda);
					if(verificoIdBaja != -1){
						verificoBaja= removeVivienda(vivienda,LEN,idVivienda);
						if(verificoBaja != -1){
							printf("\nBaja realizada con exito\n");

						}else{
							printf("\nError no se pudo realizar la baja con exito\n");
						}
					}

				}


			}

			break;
		case 'd':
			if(flagAlta==1){
			printf("\nListado de viviendas\n");
				verificoOrdenamiento=viviendaOrdenarPorCalleCantidadPersonas(vivienda,LEN);
				if(verificoOrdenamiento != -1){
					printf("Ordenamiento realizado con exito");
					printViviendas(vivienda,LEN);
				}else{
				printf("Error ordenamiento");
				}
			}
			break;
		case 'e':

			printf("\nListar censistas\n");
				printCensistas(censistas,TAMCEN);

			break;
		case 'f':
		if(flagAlta==1){
			printf("\n Listado Censistas Viviendas\n");
			printCensistas(censistas,TAMCEN);
				for(int i=0;i<LEN;i++){
					for(int j=0;i<TAMCEN;i++){
						if(vivienda[i].isEmpty==0 && censistas[j].legajoCensista == 100){
							printCensistas(censistas,TAMCEN);
							printViviendas(vivienda,LEN);
						}
						else if(vivienda[i].isEmpty==0 && censistas[j].legajoCensista == 101){
								printCensistas(censistas, TAMCEN);
								printViviendas(vivienda,LEN);
						}
						else if(vivienda[i].isEmpty==0 && censistas[j].legajoCensista == 102){
							printCensistas(censistas,TAMCEN);
							printViviendas(vivienda,LEN);
						}
					}
				}
			}
		}
		case 'g':
			if(contCensistaAna>contCensistaJuan && contCensistaAna>contCensistaSol){
				printf("Ana hizo mas censos");
			}
			else if(contCensistaJuan>contCensistaSol){
				printf("Juan hizo mas censos");

			}else{
				printf("Sol hizo mas censos");
			}
			break;
	}while(opcion != 'h');
}
	return EXIT_SUCCESS;
	}
