#include "productos.h"

//cabecera: int alta_productos(registro *pro,int x)
//precondicion: inicializados una serie de valores en el vector de estructuras
//postcondicion: añade un elemento extra al vector de estructuras
int alta_productos(Productos **pro,int x){  //x es el numero de registros que tenemos y si lo aumentamos en 1 podremos añadir uno extra
    int sto;
    char cadena[8];
    char tex[51];
    char ids[5];
    char prodf[16];


    // Incrementamos el contador de registros
    x++;

    printf("Hay %i registros después de aumentar en 1.\n\n",x);

    Productos *v_productos=(Productos *)realloc(*pro,x *sizeof(Productos));

    if (v_productos==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }
    *pro=v_productos;

    // Solicitamos el nuevo DNI
    printf("Introduce el nuevo id del producto: ");
    scanf("%s",cadena);
    eliminar_salto(cadena,8); // Eliminamos el carácter de nueva línea si existe

    // Copiamos el DNI al registro
    strcpy((*pro)[x-1].Id_prod,cadena);

    fflush(stdin);


    printf("Introduce el nuevo nombre del producto: ");
    scanf("%s",prodf);
    eliminar_salto(prodf,16); // Eliminamos el carácter de nueva línea si existe

    // Copiamos el DNI al registro
    strcpy((*pro)[x-1].nomb_prod,prodf);

    fflush(stdin);


    printf("Introduce la nueva descripcion del producto: ");
    scanf("%s",tex);
    eliminar_salto(tex,51); // Eliminamos el carácter de nueva línea si existe

    // Copiamos el DNI al registro
    strcpy((*pro)[x-1].Descrip,tex);

    fflush(stdin);


    printf("Introduce el nuevo id de la categoria del producto: ");
    scanf("%s",ids);
    eliminar_salto(ids,5); // Eliminamos el carácter de nueva línea si existe

    // Copiamos el DNI al registro
    strcpy((*pro)[x-1].Id_categ,ids);

    fflush(stdin);


    printf("Introduce el nuevo id del gestor del producto: ");
    scanf("%s",ids);
    eliminar_salto(ids,5); // Eliminamos el carácter de nueva línea si existe

    // Copiamos el DNI al registro
    strcpy((*pro)[x-1].Id_gestor,ids);

    fflush(stdin);


    // Solicitamos la nueva edad
    printf("\nIntroduce el nuevo stock: ");
    scanf("%i",&sto);
    (*pro)[x-1].stock=sto;

    free(v_productos);
    return x;
}



/*char Id_prod[8];
    char Descrip[51];
    char Id_categ[5];
    char Id_gestor[5]; //debe coincidir con identificador de la empresa administradora o proveedora del producto
    int stock;  //stock del producto
    int entrega; //dia maximo desde realizacion de pedido hasta la entrega al cliente
    float importe;
    */
