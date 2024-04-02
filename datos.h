#ifndef _DATOS_
#define _DATOS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definicion de los registros que se usaran para cada fichero del proyecto

//***mas adelante se puede plantear cambiar las variables char varias opciones
//por enteros que permitan elegir previa pregunta: 1-apagado 2-encendido

typedef struct{
    int dia;
    int mes;
    int ano;
}Fecha;

typedef struct{ //Estructura para clientes.txt
    char Id_cliente[8];
    char Nomb_cliente[21];
    char Dir_cliente[51];
    char Localidad[21];
    char Provincia[21];
    char email[31]; //nombre de usuario para acceso a la plataforma
    char Contrasena[16];
    float Cartera; //dinero del que dispone el cliente para adquirir productos
}Clientes; //informacion de los clientes del sistema


typedef struct{ //Estructura para adminprov.txt
    char Id_empresa[5];
    char Nombre_esi[21]; //ESIZON si es administrador
    char email[31]; //nombre de usuario para acceso a la plataforma
    char Contrasena[16];
    char Perfil_usuario[15]; //<<administrador>> o <<proveedor>>
}Adminprov; //informacion de los administradores y proveedores de productos de ESIZON


typedef struct{ //Estructura para productos.txt
    char Id_prod[8];
    char Descrip[51];
    char Id_categ[5];
    char Id_gestor[5]; //debe coincidir con identificador de la empresa administradora o proveedora del producto
    int stock;  //stock del producto
    int entrega; //dia maximo desde realizacion de pedido hasta la entrega al cliente
    float importe;
}Productos; //informacion de todos los productos que se pueden adquirir desde la plataforma


typedef struct{ //Estructura para categorias.txt
    char Id_categ[5];
    char Descrip[51];
}Categorias; //informacion de todas las categorias de productos que pueden adquirirse en la plataforma


typedef struct{ //Estructura para descuentos.txt
    char Id_cod[11];
    char Descrip[51];
    char Tipo_des[8]; //<<codpro>>(codigo promocional) o <<cheqreg>>(cheque regalo)
    char Estado_act[9]; // <<activo>> o <<inactivo>>
    float Importe;
    char Aplicable[7]; //<<todos>>(si es aplicable a todos los productos) o <<esizon>>(si solo es aplicable a gestionados por ESIZON)
}Descuentos; //informacion de los distintos codigos promocionales de descuentos y cheques regalo a emplear en la compra de productos


typedef struct{ //Estructura para descuentosclientes.txt
    char Id_cliente[8];
    char Id_cod[11];
    Fecha fecha_asig;
    Fecha fecha_cadu;
    int Estado_apli;  //1(aplicado) o 0 (no aplicado)
}Descuentosclientes; //informacion de los distintos codigos promocionales de descuentos y cheques regalo de cada cliente registrado en la plataforma


typedef struct{ //Estructura para lockers.txt
    char Id_locker[11];
    char Localidad[21];
    char Provincia[21];
    char Ubica[21];
    int Num_compT;
    int Num_compOcup;
}Lockers; //informacion de los distintos repositorios utilizados por la plataforma para las entregas de los pedidos


typedef struct{ //Estructura para compartimentoslockers.txt
    char Id_locker[11];
    int Num_comp;
    int Cod_locker;
    char Estado[8];
    Fecha fecha_ocupa;
    Fecha fecha_caduci;
}Compartimentoslockers; //informacion de los distintos productos depositados en cada compartimento y el codigo locker asociado al producto


typedef struct{ //Estructura para pedidos.txt
    char Id_pedido[8];
    Fecha fecha_pedi;
    char Id_cliente[8];
    char Lugar[10];
    char Id_locker[11];
    char Id_cod[11];
}Pedidos; //informacion de los distintos pedidos realizados por los clientes registrados en la plataforma


typedef struct{ //Estructura para productospedidos.txt
    char Id_pedido[8];
    char Id_prod[8];
    int Num_unid;
    Fecha fecha_entre;
    float Importe; //debe registrarse el importe al que se compra un producto por si se modifica el importe posteriormente
    char Estado_ped[15]; //<<enPreparacion>>, <<enviado>>, <<enReparto>>, <<enLocker>>, <<entregado>>, <<devuelto>>, <<transportista>>
    char Id_transp[5];
    char Id_locker[11];
    int Cod_locker;
    Fecha fecha_entre_devo;
}Productospedidos; //informacion de todos los productos incluidos en los diferentes pedidos realizados


typedef struct{ //Estructura para transportistas.txt
    char Id_transp[5];
    char Nombre_transp[21];
    char email[31];
    char contrasena[16];
    char Nombre_empre[16];
    char ciudad[21];
}Transportistas; //informacion de los repartidores de pedidos


typedef struct{ //Estructura para devoluciones.txt
    char Id_pedido[8];
    char Id_prod[8];
    Fecha fecha_devolu;
    char motivo[51];
    char Estado[15]; //<<pendiente(de aceptacion)>>, <<aceptado>>, <<denegado>>, <<enviado(por cliente)>>, <<recibido>>
    Fecha fecha_acep;
    Fecha fecha_cadu;
}Devoluciones; //informacion de las devoluciones de los distintos productos incluidos en los pedidos entregados


//Los modulos se declaran de forma global y asi se usaran en todos los modulos
Clientes *v_clientes;
Adminprov *v_adminprov;
Transportistas *v_transportistas;
Productos *v_productos;
Categorias *v_categorias;
Descuentos *v_descuentos;
Descuentosclientes *v_descuentosclientes;
Lockers *v_lockers;
Compartimentoslockers *v_compartimentoslockers;
Pedidos *v_pedidos;
Productospedidos *v_productospedidos;
Devoluciones *v_devoluciones;

#endif // _DATOS_
