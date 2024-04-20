#include "pedidos.h"

//char Id_pedido[8];  //7 digitos y caracter terminador
//Fecha fecha_pedi;   //fecha del pedido
//char Id_cliente[8]; //7 digitos y caracter terminador
//char Lugar; //d: <<domicilio>> o l: <<locker>>
//char Id_locker[11]; //10 caracteres y caracter terminador
//char Id_cod[11];    //10 caracteres y caracter terminador

//cabecera: int intro_pedidos(Pedidos *ped,int a)
//precondicion: ped no es NULL y x es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
int intro_pedidos(Pedidos **ped,int a)
{
    int i,sto,b,fp;//fp guarda uno de los enteros que forman una fecha
    float x;
    char id_ocho[8],l,id_once[11];




    printf("Cuantos pedidos quieres meter: ");
    scanf("%i",&a);

    if((ped=(Pedidos *)malloc(a*sizeof(Pedidos)))==NULL)  //se almacena memoria para emplear los registros
    {
        printf("Error");
    }
    else
    {
        for(i=0; i<a; i++)
        {

            fflush(stdin);
            printf("Introduce el id del pedido: ");
            scanf("%s",id_ocho);

            eliminar_salto(id_ocho,8);

            strcpy(ped[i].Id_ped,id_ocho);

            fflush(stdin);

            printf("\nIntroduce el dia en que se realizo el pedido: ");
            scanf("%d",&fp);
            (*ped)[i].fecha_pedi.dia=fp;

            printf("\nIntroduce el mes en que se realizo el pedido: ");
            scanf("%d",&fp);
            (*ped)[i].fecha_pedi.mes=fp;

            printf("\nIntroduce el anio en que se realizo el pedido: ");
            scanf("%d",&fp);
            (*ped)[i].fecha_pedi.anio=fp;

            printf("Introduce el id del cliente: ");
            scanf("%s",id_ocho);

            eliminar_salto(id_ocho,8);

            strcpy(ped[i].Id_cliente,id_ocho);

            fflush(stdin);


            printf("\nIndica si va a ir a un locker o a un  domicilio (l/d): ");
            scanf("%c",l);

            ped[i].Lugar=l;

            fflush(stdin);

            printf("Introduce el id del codigo promocional o del cheque regalo: ");
            scanf("%s",id_once);

            eliminar_salto(id_once,11);

            strcpy(ped[i].Id_cod,id_once);

            fflush(stdin);

        }
        printf("\n\nHas introducido %i pedidos",a);
    }
    return a;
}


//char Id_pedido[8];  //7 digitos y caracter terminador
//Fecha fecha_pedi;   //fecha del pedido
//char Id_cliente[8]; //7 digitos y caracter terminador
//char Lugar; //d: <<domicilio>> o l: <<locker>>
//char Id_locker[11]; //10 caracteres y caracter terminador
//char Id_cod[11];    //10 caracteres y caracter terminador


//cabecera: int modifica_pedidos(Pedidos *ped,int a)
//precondicion: ped no es NULL y x es mayor que 0
//postcondicion: modifica los valores correspondientes a cada campo del vector de estructuras según la opción seleccionada
int modifica_pedidos(Pedidos *ped,int x)
{
    int i,aux,num,flag;
    int encontrado=0;
    char posicion[8],camb[8],ids[11];
    char op,sino,s;
    float dineros;

    printf("Introduce el id del pedido que quiere modificar: ");
    scanf("%s",camb);
    eliminar_salto(camb,8);

    for(i=0; i<x; i++)
    {
        if(strcmp(ped[i].Id_pedido,camb)==0)
        {
            aux=i;
            printf("\nEl nombre auxiliar [%s] y el almacenado [%s] son iguales\n",camb,ped[aux].Id_pedido);

            do  //si modifico el nombre del producto tambien deberia modificar la categoria, el gestor y la descripcion ya que un producto al cambiarse debe estar en otra categoria forzosamente
            {
                printf("\nIntroduce la opcion que deseas modificar(1-modificar todo, 2-modificar ir a locker/domicilio?, 3-modificar locker o 4-modificar codigo promocional)");

                scanf("%c",&op);

                switch(op)
                {
                case 1: //se modifican todos los elementos de ese id excepto el propio id
                    printf("\n\nHas elegido modificar todo(el id se mantendra igual) \n");

                    printf("\nQuieres que el pedido vaya a un locker o al domicilio del cliente?(l/d): ");
                    scanf("%c",&l);

                    fflush(stdin);

                    if(l=='l')//Si se ha elegido domicilio no hay que modificar nada más excepto el código de descuento
                    {
                        printf("\nQuieres modificar el locker? (s/n): ");
                        scanf("%c",&l);
                        fflush(stdin);

                        if(s=='s')
                        {
                            printf("\nIntroduce el nuevo id del locker: ");
                            scanf("%s",&ids);

                            strcpy(ped[aux].Id_locker,ids);
                            fflush(stdin);
                        }
                    }

                    printf("\nIntroduce el nuevo id del codigo descuento/cheque regalo: ");
                    scanf("%s",&ids);

                    strcpy(ped[aux].Id_cod,ids);
                    fflush(stdin);
                    break;

                case 2:
                    printf("\nQuieres que el pedido vaya a un locker o al domicilio del cliente?(l/d): ");
                    scanf("%c",&l);

                    ped[aux].Lugar=l;

                    fflush(stdin);

                    if(l=='l')//Si se ha elegido domicilio no hay que modificar nada más excepto el código de descuento
                    {
                        printf("\nQuieres modificar el locker? (s/n): ");
                        scanf("%c",&l);


                        fflush(stdin);

                        if(s=='s')
                        {
                            printf("\nIntroduce el nuevo id del locker: ");
                            scanf("%s",&ids);

                            strcpy(ped[aux].Id_locker,ids);
                            fflush(stdin);
                        }
                    }
                    break;

                case 3://modifica id del locker
                    fflush(stdin);
                    if(l!='l')
                    {
                        printf("\nEl pedido va a domicilio, por lo que no puede modificarse el locker");
                        break;
                    }else{
                        printf("\nIntroduce el nuevo id del locker: ");
                            scanf("%s",&ids);

                            strcpy(ped[aux].Id_locker,ids);
                            fflush(stdin);
                    }
                    break;

                case 4://modifica codigo promocional
                    printf("\nIntroduce el nuevo id del codigo descuento/cheque regalo: ");
                    scanf("%s",&ids);

                    strcpy(ped[aux].Id_cod,ids);
                    fflush(stdin);
                    break;

                case 0:
                    return 0;
                    break;
                }

                fflush(stdin);

                printf("Quieres modificar algo mas?(pulse s para si): ");
                scanf("%c",&sino);
            }
            while(sino=='s');
            break;
        }
    }
    printf("\nSe ha modificado la posicion %i",aux);

    if (!encontrado)
    {
        printf("No se encontro ningun registro con el id proporcionado.\n");
        aux = -1; // Indica que no se encontró el id
    }
    return aux;
}

//cabecera: int busqueda_pedidos(Pedidos *ped,int a)
//precondicion: ped no es NULL y x es mayor que 0
//postcondicion: devuelve la posicion en la que se encuentra la coincidencia con la busqueda
int busqueda_pedidos(Pedidos *ped,int a){
    int i,n=0; //hacer condicional de si no se encuentra el valor se devuelve NULL por lo que no existiria el elemento
    char pedid[16];

    printf("Introduce el id del pedido que quieres encontrar: ");
    scanf("%s",pedid);

    for(i=0;i<a;i++){
        if(strcmp(ped[i].Id_pedido,pedid)==0){
            printf("\nSe ha encontrado el producto %s en la posicion %i",pedid,i);
            n=i;
        }
        break;
    }
    if(n=0)
        printf("\nNo se ha encontrado el producto" );
        //No sé si falta alguna instrucción aquí
    return n;
}

