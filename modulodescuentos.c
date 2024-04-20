#include "modulodescuentos.h"
#include "datos.h"

// Implementación de funciones
//Precondicion:
int intro_desc(Descuentos **desc, int a){
    int i;
    float x;
    char id[11], descu[51], tipo, estado, aplica;

    if((desc=(Descuentos **)malloc(a*sizeof(Descuentos)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        fflush(stdin);
        for(i=0;i<a;i++){
        printf("\nIntroduce el id del codigo\n: ");
        scanf("%s",id);
        eliminar_salto(id,11);
        strcpy((*desc)[i].Id_cod,id);
        fflush(stdin);

        printf("Introduce la descripcion del descuento\n");
        fgets(descu,51,stdin);
        eliminar_salto(descu,51);
        strcpy((*desc)[i].Descrip,descu);
        fflush(stdin);

        printf("Introduce el tipo de descuento, si es un codigo promocional o si es un cheque regalo (p/r")
        scanf("%c",tipo);
        (*desc)[i].Tipo_des=tipo;
        fflush(stdin);

        printf("Introduce el estado actual del descuento, si esta activo o inactivo (a/i)");
        scanf("%c",estado);
        (*desc)[i].Estado_act=estado;
        fflush(stdin);

        printf("Introduce el importe del descuento\n");
        scanf("%f",x);
        (*desc)[i].Importe=x;
        fflush(stdin);

        printf("Es aplicable solo a Esizon o a todos? (t/e)\n");
        scanf("%c",aplica);
        (*desc)[i].Aplicable=aplica;
        fflush(stdin);
        }
    }
}

int modifica_descuentos(Descuentos *desc,int x){
    int i,aux,num;
    int encontrado=0;
    char descrip[51],tipo,estado,app;
    float dineros;

    printf("Introduce el nombre del nuevo descuento que quiere modificar: \n");
    scanf("%s",camb);
    eliminar_salto(camb,11);

    for(i=0;i<x;i++){
        if(strcmp(pro[i].nomb_prod,camb)==0){
            aux=i;
            printf("\nEl nombre auxiliar [%s] y el almacenado [%s] son iguales\n",camb,pro[aux].nomb_prod);

            do{ //si modifico el nombre del producto tambien deberia modificar la categoria, el gestor y la descripcion ya que un producto al cambiarse debe estar en otra categoria forzosamente
                printf("Introduce la opcion que deseas modificar(1-modificar todo, 2-modificar descripcion, 3-modificar tipo de descuento, 4-modificar estado actual, 5-modificar importe o 6-modificar aplicabilidad)");
                scanf("%c",&op);

                switch(op){
                    case 1: //se modifican todos los elementos de ese id excepto el propio id
                        printf("\n\nHas elegido modificar todo(el id se mantendra igual \n");

                        printf("Introduce la descripcion del nuevo objeto: ");
                        fgets(descrip,51,stdin);
                        eliminar_salto(descrip,51);
                        strcpy(desc[aux].Descrip,descrip);
                        fflush(stdin);

                        printf("Introduce el nuevo tipo de descuento: \n");
                        scanf("%c",tipo);
                        (*desc)[aux].Tipo_des=tipo;
                        fflush(stdin);

                        printf("Introduce el nuevo estado del descuento: \n");
                        scanf("%c",estado);
                        (*desc)[aux].Estado_act=estado;
                        fflush(stdin);


                        printf("Introduce el nuevo importe del descuento\n: ");
                        scanf("%f",&dineros);
                        (*desc)[aux].Importe=dineros;

                        printf("Introduce si es aplicable a esizon o a todos: \n");
                        scanf("%c",app);
                        (*desc)[aux].Aplicable=app;
                        break;

                    case 2:
                        printf("Va a modificar la descripcion del descuento, estas seguro?\n")
                        printf("En caso de que quiera continuar pulse s: ");
                        scanf("%c",&s);

                        if(s=='s'){
                            printf("\nHas elegido modificar descripcion\n");
                            fflush(stdin);

                            printf("Introduce la nueva descripcion del descuento: \n");
                            fgets(descrip,51,stdin);
                            strcpy(desc[aux].Descrip,descrip);
                        }
                        break;

                    case 3:
                        printf("\nHas elegido cambiar el tipo de descuento\n");
                        fflush(stdin);

                        printf("Introduce el nuevo tipo de descuento: \n");
                        scanf("%c",tipo);

                        (*desc)[aux].Tipo_des=tipo;
                        break;

                    case 4:
                        printf("\nHas elegido cambiar el estado actual del descuento\n");

                        printf("Introduce el nuevo estado del descuento: \n");
                        scanf("%c",estado);
                        (*desc)[aux].Estado_act=estado;
                        break;

                    case 5:
                        printf("\nHas elegido cambiar el importe del descuento\n");

                        printf("Introduce el nuevo importe del descuento: \n");
                        scanf("%f",&dineros);
                        (*desc)[aux].Importe=dineros;
                        break;

                    case 6:
                        printf("\nHas elegido cambiar la aplicabilidad del descuento\n");

                        printf("Introduce la nueva situacion de aplicabilidad del descuento: \n");
                        scanf("%c",app);
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
        printf("No se encontró ningún registro con el ID proporcionado.\n");
        aux = -1; // Indica que no se encontró el ID
    return aux;
}

int alta_descuentos(Descuentos **desc,int x){  //x es el numero de registros que tenemos y si lo aumentamos en 1 podremos a�adir uno extra
    int sto;
    float dineros;
    char id[11],descrip[51], tipo, estado, app;

    x++;

    printf("Hay %i registros despues de aumentar en 1.\n\n",x);

    Descuentos *desc=(Descuentos *)realloc(*desc,x*sizeof(Descuentos));

    if (desc==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }

    printf("Introduce el nuevo id del descuento: \n");
    scanf("%s",id);
    eliminar_salto(id,11);
    strcpy((*desc)[x-1].Id_cod,id);
    fflush(stdin);

    printf("Introduce una nueva descripcion al descuento: \n");
    fgets(descrip,51,stdin);
    eliminar_salto(descrip,51); // Eliminamos el car�cter de nueva l�nea si existe

    strcpy((*desc)[x-1].Descrip,descrip);
    fflush(stdin);

    printf("Introduce el nuevo tipo de descuento: \n");
    scanf("%c",tipo);
    (*desc)[x-1].Tipo_des=tipo;
    fflush(stdin);

    printf("Introduce el nuevo estado actual del descuento: \n");
    scanf("%s",ids);
    (*desc)[x-1].Estado_act=estado;
    fflush(stdin);

    printf("Introduce el nuevo importe del descuento: \n");
    scanf("%d",&dineros);
    (*desc)[x-1]=dineros;
    fflush(stdin);

    printf("Introduce la nueva aplicabilidad del descuento: \n");
    scanf("%c",app);
    (*desc)[x-1].Aplicable=app;

    return x;
}

int baja_descuento(Descuentos **desc,int x){
    int i,aux;
    char cadena[11];
    int encontrado=0;


    printf("Introduce el id del descuento para acceder: \n");
    scanf("%s",cadena);
    eliminar_salto(cadena,11);


    for(i=0;i<x;i++){
        printf("\nSe accede al bucle");
        if((strcmp((*desc)[i].Id_cod,cadena))==0){
            printf("\nSe ha encontrado el elemento %s",cadena);
            aux=i;
            encontrado=1;
            break;
        }
    }

    if(encontrado==1){
        do{
            strcpy((*desc)[aux].Id_cod,(*desc)[aux+1].Id_cod);
            strcpy((*desc)[aux].Descrip,(*desc)[aux+1].Descrip);
            (*desc)[aux].Tipo_des=(*desc)[aux+1].Tipo_des;
            (*desc)[aux].Importe=(*desc)[aux+1].Importe;
            (*desc)[aux].Aplicable=(*desc)[aux+1].Aplicable;

            aux++;
        }while(aux<x);
    }else{
        return -1;
    }

    Descuentos *nuevo_reg=(Descuentos *)realloc(*desc,(x-1) *sizeof(Descuentos)); //elimina una posicion del vector que en este caso sera la ultima

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }

    *desc=nuevo_reg;

    return x-1;
}

void listado_descuentos(Descuentos *desc,int x){
    int i;

    printf("\nLos registros almacenados son: ");
    for(i=0;i<x;i++){
        printf("\nPosicion %i del vector de estructuras: [%s]-[%s]-[%c]-[%c]-[%f]-[%c]",i+1,desc[i].Id_cod,pro[i].Descrip,desc[i].Tipo_des,desc[i].Estado_act,desc[i].Importe,desc[i].Aplicable);
    }
}

int busqueda_descuentos(Descuentos *desc,int a){
    int i,n=0; //hacer condicional de si no se encuentra el valor se devuelve NULL por lo que no existiria el elemento
    char desc[11];

    printf("Introduce el descuento que quieras buscar a partir de su id: \n");
    scanf("%s",desc);

    for(i=0;i<a;i++){
        if(strcmp(desc[i].Id_cod,desc)==0){
            printf("Se ha encontrado el producto %s en la posicion %i",desc,i);
            n=i;
        }
        break;
    }
    return n;
}
