#include "datos.h"
#ifndef _DATOS_
#define _DATOS_

int guarda_adminprov(Adminprov *,int);
int guarda_prod(Productos *, int);
int guarda_cat(Categorias *, int);
int guarda_desc(Descuentos *, int);
int guarda_descclient(Descuentosclientes *, int);
int guarda_lockers(Lockers *, int);
int guarda_compartlockers(Compartimentoslockers *, int);
int guarda_ped(Pedidos *, int);
int guarda_pedprod(Productospedidos *, int);
int guarda_transp(Transportistas *, int);
int guarda_devo(Devoluciones *, int);
int guarda_cliente(Clientes *r, int)
int guarda();

#endif // GUARDAR_H

