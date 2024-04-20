#ifndef _PEDIDOS_
#define _PEDIDOS_
#include "datos.h"

int intro_pedidos(Pedidos**, int);
int alta_pedidos(Pedidos **,int);
int modifica_pedidos(Pedidos *,int);
int busqueda_pedidos(Pedidos *,int);
int baja_pedidos(Pedidos **,int);
void listado_pedidos(Pedidos *,int);
int consultar_estado(Pedidos *,int);

//char Id_pedido[8];  //7 digitos y caracter terminador
    //Fecha fecha_pedi;   //fecha del pedido
    //char Id_cliente[8]; //7 digitos y caracter terminador
    //char Lugar; //d: <<domicilio>> o l: <<locker>>
    //char Id_locker[11]; //10 caracteres y caracter terminador
    //char Id_cod[11];    //10 caracteres y caracter terminador





#endif // _PEDIDOS_
