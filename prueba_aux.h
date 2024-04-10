#ifndef _PRUEBA_AUX_
#define _PRUEBA_AUX_

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "datos.h"
#include "productos.h"
#include "moduloguardar.h"
#define N 3

typedef struct{
char dni[10];
char nombre[21];
int edad;
}registro;

void intro_datos(registro *);
void introcliente(Clientes **,int);
void eliminar_salto(char *,int);
int guarda_fichero(registro *,int);
int guarda_cliente(Clientes *,int);
int carga_fichero(registro **,int);
void ConsultaDatos(registro *,int);
void ConsultaClientes(Clientes *,int);
void ModificaDatos(registro *,int);
int AltaDatos(registro **,int);
int BajaDatos(registro **, int);

#endif // _PRUEBA_AUX_
