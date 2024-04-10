#include "productos.h"
#include "prueba_aux.h"

int modifica_productos(Productos *pro,int x){
    int i,aux,num;
    int encontrado=0;
    char posicion[16],camb[16],nue_tex[51],ids[5];
    char op,sino,s;
    float dineros;

    printf("Introduce el nombre del producto que quiere modificar: ");
    scanf("%s",camb);
    eliminar_salto(camb,16);

    for(i=0;i<x;i++){
        if(strcmp(pro[i].nomb_prod,camb)==0){
            aux=i;
            printf("\nEl nombre auxiliar [%s] y el almacenado [%s] son iguales\n",camb,pro[aux].nomb_prod);

            do{ //si modifico el nombre del producto tambien deberia modificar la categoria, el gestor y la descripcion ya que un producto al cambiarse debe estar en otra categoria forzosamente
                printf("Introduce la opcion que deseas modificar(1-modificar todo, 2-modificar categoria, 3-modificar gestor, 4-modificar stock, 5-modificar dias hasta entrega o 6-modificar importe)");
                scanf("%c",&op);

                switch(op){
                    case 1: //se modifican todos los elementos de ese id excepto el propio id
                        printf("\n\nHas elegido modificar todo(el id se mantendra igual \n");


                        printf("\nIntroduce el nuevo nombre del objeto: ");
                        scanf("%s",posicion);
                        eliminar_salto(posicion,16);

                        strcpy(pro[aux].nomb_prod,posicion);
                        fflush(stdin);


                        printf("Introduce la descripcion del nuevo objeto: ");
                        fgets(nue_tex,51,stdin);
                        eliminar_salto(nue_tex,51);

                        strcpy(pro[aux].Descrip,nue_tex);
                        fflush(stdin);


                        printf("Introduce el nuevo id de la categoria: ");
                        scanf("%s",ids);
                        eliminar_salto(ids,5);

                        strcpy(pro[aux].Id_categ,ids);
                        fflush(stdin);


                        printf("Introduce el nuevo id del gestor: ");
                        scanf("%s",ids);
                        eliminar_salto(ids,5);

                        strcpy(pro[aux].Id_gestor,ids);
                        fflush(stdin);


                        printf("Introduce el stock del nuevo producto: ");
                        scanf("%i",&num);

                        pro[aux].stock=num;


                        printf("Introduce el numero maximo de dias de entrega del nuevo producto: ");
                        scanf("%i",&num);

                        pro[aux].importe=num;


                        printf("Introduce el precio del nuevo producto: ");
                        scanf("%f",&dineros);

                        pro[aux].importe=dineros;

                        break;

                    case 2:
                        printf("\nNo es recomendable cambiar la categoria de un producto que esta en la categoria correcta\n");
                        printf("En caso de que quiera continuar pulse s: ");
                        scanf("%c",&s);

                        if(s=='s'){
                            printf("\nHas elegido modificar id_categoria\n");
                            fflush(stdin);

                            printf("Introduce el nuevo id de la categoria: ");
                            scanf("%s",ids);

                            strcpy(pro[aux].Id_categ,ids);
                        }
                        break;

                    case 3:
                        printf("\nHas elegido cambiar el id_gestor\n");
                        fflush(stdin);

                        printf("Introduce el nuevo id del gestor: ");
                        scanf("%s",ids);

                        strcpy(pro[aux].Id_gestor,ids);

                        break;

                    case 4:
                        printf("\nHas elegido cambiar el stock del producto\n");

                        printf("Introduce el nuevo stock del producto: ");
                        scanf("%i",&num);

                        pro[aux].stock=num;

                        break;

                    case 5:
                        printf("\nHas elegido cambiar el numero maximo de dias del producto para entregarse\n");

                        printf("Introduce el nuevo numero maximo de dias para entregar el producto: ");
                        scanf("%i",&num);

                        pro[aux].entrega=num;

                        break;

                    case 6:
                        printf("\nHas elegido cambiar el importe del producto\n");

                        printf("Introduce el nuevo importe del producto: ");
                        scanf("%f",&dineros);

                        pro[aux].importe=dineros;

                        break;
                    case 0:  return 0;
                    break;
                }

                fflush(stdin);

                printf("Quieres modificar algo mas?(pulse s para si): ");
                scanf("%c",&sino);
            }while(sino=='s');
            break;
        }
    }
    printf("\nSe ha modificado la posicion %i",aux);

    if (!encontrado) {
        printf("No se encontró ningún registro con el DNI proporcionado.\n");
        aux = -1; // Indica que no se encontró el DNI
    }
    return aux;
}

//cabecera: int alta_productos(registro *pro,int x)
//precondicion: pro no es NULL y x es mayor que 0
//postcondicion: anade un elemento extra al vector de estructuras
int alta_productos(Productos **pro,int x){  //x es el numero de registros que tenemos y si lo aumentamos en 1 podremos a�adir uno extra
    int sto;
    float dineros;
    char cadena[8], tex[51],prodf[16],ids[5];

    x++;

    printf("Hay %i registros despues de aumentar en 1.\n\n",x);

    Productos *nuevo_reg=(Productos *)realloc(*pro,x*sizeof(Productos));

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }
    *pro=nuevo_reg;


    printf("Introduce el nuevo id del producto: ");
    scanf("%s",cadena);
    eliminar_salto(cadena,8);

    strcpy((*pro)[x-1].Id_prod,cadena);
    fflush(stdin);


    printf("Introduce el nuevo nombre del producto: ");
    scanf("%s",prodf);
    eliminar_salto(prodf,16); // Eliminamos el car�cter de nueva l�nea si existe

    strcpy((*pro)[x-1].nomb_prod,prodf);
    fflush(stdin);


    printf("Introduce la nueva descripcion del producto: ");
    fgets(tex,51,stdin);
    eliminar_salto(tex,51);

    strcpy((*pro)[x-1].Descrip,tex);
    fflush(stdin);


    printf("Introduce el nuevo id de la categoria del producto: ");
    scanf("%s",ids);
    eliminar_salto(ids,5);

    strcpy((*pro)[x-1].Id_categ,ids);
    fflush(stdin);


    printf("Introduce el nuevo id del gestor del producto: ");
    scanf("%s",ids);
    eliminar_salto(ids,5);

    strcpy((*pro)[x-1].Id_gestor,ids);
    fflush(stdin);


    printf("Introduce el nuevo stock del producto: ");
    scanf("%i",&sto);
    (*pro)[x-1].stock=sto;


    printf("\nIntroduce la nueva entrega: ");
    scanf("%i",&sto);
    (*pro)[x-1].entrega=sto;


    printf("\nIntroduce la nueva entrega: ");
    scanf("%f",&dineros);
    (*pro)[x-1].importe=dineros;


    return x;
}


//cabecera: int baja_productos(Productos **pro,int x)
//precondicion: pro no es NULL y x es mayor que 0
//postcondicion: elimina la posicion seleccionada en el vector de estructuras y devuelve el numero de posiciones totales
int baja_productos(Productos **pro,int x){
    int i,aux;
    char cadena[16];
    int encontrado=0;


    printf("Introduce el nombre del producto que quiere eliminar: ");
    scanf("%s",cadena);
    eliminar_salto(cadena,16);


    for(i=0;i<x;i++){
        printf("\nSe accede al bucle");
        if((strcmp((*pro)[i].nomb_prod,cadena))==0){
            printf("\nSe ha encontrado el elemento %s",cadena);
            aux=i;
            encontrado=1;
            break;
        }
    }

    if(encontrado==1){
        do{
            strcpy((*pro)[aux].Id_prod,(*pro)[aux+1].Id_prod);
            strcpy((*pro)[aux].nomb_prod,(*pro)[aux+1].nomb_prod);
            strcpy((*pro)[aux].Descrip,(*pro)[aux+1].Descrip);
            strcpy((*pro)[aux].Id_categ,(*pro)[aux+1].Id_categ);
            strcpy((*pro)[aux].Id_gestor,(*pro)[aux+1].Id_gestor);
            (*pro)[aux].stock=(*pro)[aux+1].stock;
            (*pro)[aux].entrega=(*pro)[aux+1].entrega;
            (*pro)[aux].importe=(*pro)[aux+1].importe;

            aux++;
        }while(aux<x);
    }else{
        return -1;
    }

    Productos *nuevo_reg=(Productos *)realloc(*pro,(x-1)*sizeof(Productos)); //elimina una posicion del vector que en este caso sera la ultima

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }

    *pro=nuevo_reg;

    return x-1;
}


//cabecera: void listado_productos(Productos *pro,int x)
//precondicion: pro no es NULL y x es mayor que 0
//postcondicion: muestra todos los campos de cada posicion del vector de estructuras desde 0 hasta x
void listado_productos(Productos *pro,int x){
    int i;

    printf("\nLos registros almacenados son: ");
    for(i=0;i<x;i++){
        printf("\nPosicion %i del vector de estructuras: [%s]-[%s]-[%s]-[%s]-[%s]-[%i]-[%i]-[%f]",i+1,pro[i].Id_prod,pro[i].nomb_prod,pro[i].Descrip,pro[i].Id_categ,pro[i].Id_gestor,pro[i].stock,pro[i].entrega,pro[i].importe);
    }
}


//cabecera: int intro_productos(Productos *pro,int a)
//precondicion: pro no es NULL y x es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
int intro_productos(Productos **pro,int a){
    int i,sto,b;
    float x;
    char id[8],tex[51],ids[5],prodf[16];

    printf("Cuantos productos quieres meter: ");
    scanf("%i",&a);

    if((pro=(Productos **)malloc(a*sizeof(Productos)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        for(i=0;i<a;i++){

        fflush(stdin);
        printf("Introduce el id del producto (debe seguir un orden numerico 0000000,0000001,etc): ");
        scanf("%s",id);

        strcpy((*pro)[i].Id_prod,id);

        fflush(stdin);

        printf("\nIntroduce el nombre del producto: ");
        scanf("%s",prodf);

        strcpy((*pro)[i].nomb_prod,prodf);

        fflush(stdin);

        printf("\nIntroduce la descripcion del producto: ");
        fgets(tex,51,stdin);

        eliminar_salto(tex,51);

        strcpy((*pro)[i].Descrip,tex);

        fflush(stdin);


        printf("\nIntroduce el id de la categoria donde va a ir el producto(el producto debe ir en la categoria apropiada (0000,0001): ");
        scanf("%s",ids);

        strcpy((*pro)[i].Id_categ,ids);

        fflush(stdin);

        printf("\nIntroduce el id del gestor del producto(el producto debe ser administrado por un proveedor o un administrador(0000,0001): ");
        scanf("%s",ids);

        strcpy((*pro)[i].Id_gestor,ids);

        fflush(stdin);

        printf("\nIntroduce el stock del producto: ");
        scanf("%i",&sto);

        (*pro)[i].stock=sto;

        printf("\nIntroduce el numero maximo de dias hasta la entrega del producto: ");
        scanf("%i",&b);

        (*pro)[i].entrega=b;

        printf("\nIntroduce el dinero que cuesta el producto: ");
        scanf("%f",&x);

        fflush(stdin);

        (*pro)[i].importe=x;
        }
        printf("\n\nHas introducido %i productos",a);
    }
    return a;
}


//cabecera: int busqueda_productos(Productos *pro,int a)
//precondicion: pro no es NULL y x es mayor que 0
//postcondicion: devuelve la posicion en la que se encuentra la coincidencia con la busqueda
int busqueda_productos(Productos *pro,int a){
    int i,n=0; //hacer condicional de si no se encuentra el valor se devuelve NULL por lo que no existiria el elemento
    char produc[16];

    printf("Introduce el producto que quieres encontrar(mete el nombre exacto sin usar mayusculas): ");
    scanf("%s",produc);

    for(i=0;i<a;i++){
        if(strcmp(pro[i].nomb_prod,produc)==0){
            printf("Se ha encontrado el producto %s en la posicion %i",produc,i);
            n=i;
        }
        break;
    }
    return n;
}



int modifica_categorias(Categorias *cat,int x){
    int i,aux,num;
    int encontrado=0;
    char nue_tex[51],ids[5];
    char op,s;


    printf("Introduce el id de la categoria que quiere modificar: ");
    scanf("%s",ids);
    eliminar_salto(ids,5);

    for(i=0;i<x;i++){
        if(strcmp(cat[i].nomb_prod,camb)==0){
            aux=i;
            printf("\nEl nombre auxiliar [%s] y el almacenado [%s] son iguales\n",ids,cat[aux].Id_categ);

            do{ //si modifico el nombre del producto tambien deberia modificar la categoria, el gestor y la descripcion ya que un producto al cambiarse debe estar en otra categoria forzosamente
                printf("Introduce la opcion que deseas modificar(1-modificar descripcion, 0-salir)");
                scanf("%c",&op);

                switch(op){

                    case 1:
                        printf("\nHas elegido modificar la descripcion de la categoria\n");
                        printf("Introduce la nueva descripcion: ");
                        fgets(nue_tex,51,stdin);
                        eliminar_salto(nue_tex,51);

                        strcpy(cat[i].Descrip,nue_tex);
                        }
                        break;

                    case 0:  return 0;
                        break;
                }
                fflush(stdin);

                printf("Quieres modificar algo mas?(pulse s para si): ");
                scanf("%c",&sino);
            }while(sino=='s');
            break;
        }
    }
    printf("\nSe ha modificado la posicion %i",aux);

    if (!encontrado) {
        printf("No se encontró ningún registro con el DNI proporcionado.\n");
        aux = -1; // Indica que no se encontró el DNI
    }
    return aux;
}

//cabecera: int alta_categorias(Categorias **cat,int x)
//precondicion: cat no es NULL y x es mayor que 0
//postcondicion: anade un elemento extra al vector de estructuras
int alta_categorias(Categorias **cat,int x){
    char tex[51],ids[5];

    x++;

    printf("Hay %i registros despues de aumentar en 1.\n\n",x);

    Categorias *nuevo_reg=(Categorias *)realloc(*cat,x*sizeof(Categorias));

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }
    *cat=nuevo_reg;


    printf("Introduce el nuevo id de la categoria: ");
    scanf("%s",ids);
    eliminar_salto(ids,8);

    strcpy((*cat)[x-1].Id_categ,ids);
    fflush(stdin);


    printf("Introduce la nueva descripcion de la categoria: ");
    fgets(tex,51,stdin);
    eliminar_salto(tex,51);

    strcpy((*cat)[x-1].Descrip,tex);
    fflush(stdin);


    return x;
}

//cabecera: int baja_categorias(Categorias **cat,int x)
//precondicion: cat no es NULL y x es mayor que 0
//postcondicion: elimina un elemento del vector de estructuras
int baja_categorias(Categorias **cat,int x){
    int i,aux;
    char cadena[5];
    int encontrado=0;


    printf("Introduce el id de la categoria que quiere eliminar: ");
    scanf("%s",cadena);
    eliminar_salto(cadena,5);


    for(i=0;i<x;i++){
        printf("\nSe accede al bucle");
        if((strcmp((*cat)[i].Id_categ,cadena))==0){
            printf("\nSe ha encontrado el elemento %s",cadena);
            aux=i;
            encontrado=1;
            break;
        }
    }

    if(encontrado==1){
        do{
            strcpy((*cat)[aux].Id_categ,(*cat)[aux+1].Id_categ);
            strcpy((*cat)[aux].Descrip,(*cat)[aux+1].Descrip);
            aux++;
        }while(aux<x);
    }else{
        return -1;
    }

    Categorias *nuevo_reg=(Categorias *)realloc(*cat,(x-1)*sizeof(Categorias)); //elimina una posicion del vector que en este caso sera la ultima

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }

    *cat=nuevo_reg;

    return x-1;
}


//cabecera: int intro_productos(Productos *pro,int a)
//precondicion: cat no es NULL y x es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
int intro_categorias(Categorias **cat,int a){
    int i;
    char tex[51],ids[5];

    printf("Cuantos productos quieres meter: ");
    scanf("%i",&a);

    if((cat=(Categorias **)malloc(a*sizeof(Categorias)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        for(i=0;i<a;i++){

        fflush(stdin);
        printf("Introduce el id de la categoria (debe seguir un orden numerico 00000,00001,etc): ");
        scanf("%s",ids);
        eliminar_salto(ids,5);

        strcpy((*cat)[i].Id_categ,ids);
        fflush(stdin);

        printf("\nIntroduce la descripcion del producto: ");
        fgets(tex,51,stdin);
        eliminar_salto(tex,51);

        strcpy((*cat)[i].Descrip,tex);
        }
        printf("\n\nHas introducido %i categorias",a);
    }
    return a;
}

//cabecera: void listado_categorias(Categorias *cat,int x)
//precondicion: cat no es NULL y x es mayor que 0
//postcondicion: muestra los valores almacenados en el vector de estructuras
void listado_categorias(Categorias *cat,int x){
    int i;

    printf("\nLos registros almacenados son: ");
    for(i=0;i<x;i++){
        printf("\nPosicion %i del vector de estructuras: [%s]-[%s]",i+1,cat[i].Id_categ,cat[i].Descrip);
    }
}


int busqueda_categorias(Categorias *cat,int a){
    int i, n=0;
    char cate[5];

    printf("Introduce la categoria que quieres encontrar(mete el id exacto): ");
    scanf("%s",cate);

    for(i=0;i<a;i++){
        if(strcmp(cat[i].Id_categ,cate)==0){
            printf("Se ha encontrado el producto %s en la posicion %i",cate,i);
            n=i;
        }
        break;
    }
    return n;
}
