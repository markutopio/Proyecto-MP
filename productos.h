#ifndef _PRODUCTOS_
#define _PRODUCTOS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"

int guarda_productos(Productos *,int);
int alta_productos(Productos **,int);
int modifica_productos(Productos *,int);
int busqueda_productos(Productos *,int);
int baja_productos(Productos **,int);
int listado_productos(Productos *,int);
void eliminar_salto(char *,int);

#endif // _PRODUCTOS_
