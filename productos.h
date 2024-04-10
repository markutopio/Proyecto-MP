#ifndef _PRODUCTOS_
#define _PRODUCTOS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

int alta_productos(Productos **,int);
int modifica_productos(Productos *,int);
int busqueda_productos(Productos *,int);
int baja_productos(Productos **,int);
void listado_productos(Productos *,int);
int intro_productos(Productos **,int);

int alta_categorias(Categorias **,int);
int baja_categorias(Categorias **,int);
void listado_categorias(Categorias *,int);
int busqueda_categorias(Categorias *,int);
int modifica_categorias(Categorias *,int);
int intro_categorias(Categorias **,int);

#endif // _PRODUCTOS_
