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
    int anio;
}Fecha;

typedef struct{ //Estructura para clientes.txt
    char Id_cliente[8]; //7 digitos y caracter terminador
    char Nomb_cliente[21];  //20 caracteres y caracter terminador
    char Dir_cliente[51];   //50 caracteres y caracter terminador
    char Localidad[21]; //20 caracteres y caracter terminador
    char Provincia[21]; //20 caracteres y caracter terminador
    char email[31]; //30 caracteres y caracter terminador, nombre de usuario para acceso a la plataforma
    char Contrasena[16];    //15 caracteres y caracter terminador, contrase�a para acceder al sistema
    float Cartera; //dinero del que dispone el cliente para adquirir productos
}Clientes; //informacion de los clientes del sistema


typedef struct{ //Estructura para adminprov.txt
    char Id_empresa[5]; //4 digitos y caracter terminador
    char Nombre_empre[21]; //20 caracteres y caracter terminador, ESIZON si es administrador
    char email[31]; //30 caracteres y caracter terminador, nombre de usuario para acceso a la plataforma
    char Contrasena[16];    //15 caracteres y caracter terminador, contrase�a para acceder al sistema
    char Perfil_usuario; //a: <<administrador>> o p: <<proveedor>>
}Adminprov; //informacion de los administradores y proveedores de productos de ESIZON


typedef struct{ //Estructura para productos.txt
    char Id_prod[8]; //7 digitos y caracter terminador
    char nomb_prod[16]; //15 caracteres y caracter terminador
    char Descrip[51];   //50 caracteres y caracter terminador
    char Id_categ[5];   //4 digitos y caracter terminador
    char Id_gestor[5]; //4 digitos y caracter terminador, debe coincidir con identificador de la empresa administradora o proveedora del producto
    int stock;  //stock del producto
    int entrega; //dia maximo desde realizacion de pedido hasta la entrega al cliente
    float importe;  //importe del producto en euros
}Productos; //informacion de todos los productos que se pueden adquirir desde la plataforma


typedef struct{ //Estructura para categorias.txt
    char Id_categ[5];   //4 digitos y caracter terminador
    char Descrip[51];   //50 caracteres y caracter terminador
}Categorias; //informacion de todas las categorias de productos que pueden adquirirse en la plataforma


typedef struct{ //Estructura para descuentos.txt
    char Id_cod[11];    //10 caracteres y caracter terminador
    char Descrip[51];   //50 caracteres y caracter terminador
    char Tipo_des; //p: <<codpro>>(codigo promocional) o r: <<cheqreg>>(cheque regalo)
    char Estado_act; //a: <<activo>> o i: <<inactivo>>
    float Importe;  //importe del descuento
    char Aplicable; //t: <<todos>>(si es aplicable a todos los productos) o e: <<esizon>>(si solo es aplicable a gestionados por ESIZON)
}Descuentos; //informacion de los distintos codigos promocionales de descuentos y cheques regalo a emplear en la compra de productos


typedef struct{ //Estructura para descuentosclientes.txt
    char Id_cliente[8]; //7 digitos y caracter terminador
    char Id_cod[11];    //10 caracteres y caracter terminador
    Fecha fecha_asig;   //fecha de asignacion
    Fecha fecha_cadu;   //fecha de caducidad
    int Estado_apli;  //1(aplicado) o 0 (no aplicado)
}Descuentosclientes; //informacion de los distintos codigos promocionales de descuentos y cheques regalo de cada cliente registrado en la plataforma


typedef struct{ //Estructura para lockers.txt
    char Id_locker[11]; //10 caracteres y caracter terminador
    char Localidad[21]; //20 caracteres y caracter terminador
    char Provincia[21]; //20 caracteres y caracter terminador
    char Ubica[21]; //20 caracteres y caracter terminador
    int Num_compT;  //numero de compartimentos totales
    int Num_compOcup;   //numero de compartimentos ocupados actualmente
}Lockers; //informacion de los distintos repositorios utilizados por la plataforma para las entregas de los pedidos


typedef struct{ //Estructura para compartimentoslockers.txt
    char Id_locker[11]; //10 caracteres maximo
    int Num_comp;   //numero de compartimentos
    int Cod_locker; //codigo del locker
    char Estado;    //o: <<ocupado>> o v: <<vacio>>
    Fecha fecha_ocupa;  //fecha ocupacion
    Fecha fecha_caduci; //fecha caducidad
}Compartimentoslockers; //informacion de los distintos productos depositados en cada compartimento y el codigo locker asociado al producto


typedef struct{ //Estructura para pedidos.txt
    char Id_pedido[8];  //7 digitos y caracter terminador
    Fecha fecha_pedi;   //fecha del pedido
    char Id_cliente[8]; //7 digitos y caracter terminador
    char Lugar; //d: <<domicilio>> o l: <<locker>>
    char Id_locker[11]; //10 caracteres y caracter terminador
    char Id_cod[11];    //10 caracteres y caracter terminador
}Pedidos; //informacion de los distintos pedidos realizados por los clientes registrados en la plataforma


typedef struct{ //Estructura para productospedidos.txt
    char Id_pedido[8];  //7 digitos y caracter terminador
    char Id_prod[8];    //7 digitos y caracter terminador
    int Num_unid;   //numero de unidades del producto pedido
    Fecha fecha_entre;  //fecha prevista de entrega
    float Importe; //debe registrarse el importe al que se compra un producto por si se modifica el importe posteriormente
    char Estado_ped; //p: <<enPreparacion>>, e: <<enviado>>, r: <<enReparto>>, l: <<enLocker>>, n: <<entregado>>, d: <<devuelto>>, t: <<transportista>>
    char Id_transp[5];  //4 digitos y caracter terminador
    char Id_locker[11]; //10 caracteres y caracter terminador
    int Cod_locker; //codigo del locker
    Fecha fecha_entre_devo; //fecha entrega/devolucion por el transportista
}Productospedidos; //informacion de todos los productos incluidos en los diferentes pedidos realizados


typedef struct{ //Estructura para transportistas.txt
    char Id_transp[5];  //4 digitos y caracter terminador
    char Nombre_transp[21]; //20 caracteres y caracter terminador
    char email[31]; //30 caracteres y caracter terminador, sera usado como nombre de usuario para acceso
    char contrasena[16];    //15 caracteres maximo y caracter terminador
    char Nombre_empre[21];  //20 caracteres y caracter terminador
    char ciudad_repar[21];    //20 caracteres y caracter terminador
}Transportistas; //informacion de los repartidores de pedidos


typedef struct{ //Estructura para devoluciones.txt
    char Id_pedido[8];  //7 digitos y caracter terminador
    char Id_prod[8];   //7 digitos y caracter terminador
    Fecha fecha_devolu; //fecha devolucion
    char motivo[51];    //50 caracteres y caracter terminador
    char Estado[15]; //p: <<pendiente(de aceptacion)>>, a: <<aceptado>>, d: <<denegado>>, e: <<enviado(por cliente)>>, r: <<recibido>>
    Fecha fecha_acep;   //fecha de aceptacion
    Fecha fecha_cadu;   //fecha de caducidad
}Devoluciones; //informacion de las devoluciones de los distintos productos incluidos en los pedidos entregados


#endif // _DATOS_
