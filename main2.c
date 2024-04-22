#include "me.h"
#include "moduloguardar.h"

int main(){
    //declaracion de variables contadoras de registros
    int num_clientes=0, num_adminprov=0, num_prod=0, num_cat=0, num_desc=0, num_descclien=0, num_lockers=0;
    int num_compartlockers=0, num_ped=0, num_pedprod=0, num_transp=0, num_devo=0;

    //declaracion de variables que almacenan registros exactos
    int cli_exac, admiprov_exac, prod_exac, desc_exac, desccli_exac, locker_exac;
    int complock_exac, ped_exac, pedprod_exac, transp_exac, devo_exac;

    //resto de variables
    int elec,el,out,id;
    char s_n;

    //declaracion de vectores de estructuras que se usaran en todo el programa
    Clientes *cli;
    Adminprov *adpro;
    Productos *pro;
    Categorias *cat;
    Descuentos *des;
    Descuentosclientes *desccli;
    Lockers *loc;
    Compartimentoslockers *compart;
    Pedidos *ped;
    Productospedidos *pedprod;
    Transportistas *transp;
    Devoluciones *dev;

    //llamada a cargas de datos almacenados en registros
    num_clientes=carga_clientes(&cli,num_clientes);
    num_adminprov=carga_adminprov(&adpro,num_adminprov);
    num_prod=carga_prod(&pro,num_prod);
    num_cat=carga_cat(&cat,num_cat);
    num_desc=carga_desc(&des,num_desc);
    num_descclien=carga_descclient(&desccli,num_descclien);
    num_lockers=carga_lockers(&loc,num_lockers);
    num_compartlockers=carga_compartlockers(&compart,num_compartlockers);
    num_ped=carga_ped(&ped,num_ped);
    num_pedprod=carga_pedprod(&pedprod,num_pedprod);
    num_transp=carga_transp(&transp,num_transp);
    num_devo=carga_devo(&dev,num_devo);

    //presentacion de la aplicacion
    presentacion();

    //bucle que ejecutara la aplicacion hasta que salgas
    do{
        elec=ventana_inicio();
        switch(elec){
            case 0:
                do{
                    printf("Elige que opcion prefieres para guardar los datos\n");
                    printf("0. Sobreescribir los datos guardados en ficheros\n");
                    printf("1. Anadir los datos al final del fichero");
                    scanf("%i",&el);
                    switch(el){
                        case 0:
                            num_clientes=guarda_cliente(cli,num_clientes);
                            num_adminprov=guarda_adminprov(adpro,num_adminprov);
                            num_prod=guarda_prod(pro,num_prod);
                            num_cat=guarda_cat(cat,num_cat);
                            num_desc=guarda_desc(des,num_desc);
                            num_descclien=guarda_descclient(desccli,num_descclien);
                            num_lockers=guarda_lockers(loc,num_lockers);
                            num_compartlockers=guarda_compartlockers(compart,num_compartlockers);
                            num_ped=guarda_ped(ped,num_ped);
                            num_pedprod=guarda_pedprod(pedprod,num_pedprod);
                            num_transp=guarda_transp(transp,num_transp);
                            num_devo=guarda_devo(dev,num_devo);

                            return 0;
                            break;

                        case 1:
                            num_clientes=guarda_cliente_extra(cli,num_clientes);
                            num_adminprov=guarda_adminprov_extra(adpro,num_adminprov);
                            num_prod=guarda_prod_extra(pro,num_prod);
                            num_cat=guarda_cat_extra(cat,num_cat);
                            num_desc=guarda_desc_extra(des,num_desc);
                            num_descclien=guarda_descclient_extra(desccli,num_descclien);
                            num_lockers=guarda_lockers_extra(loc,num_lockers);
                            num_compartlockers=guarda_compartlockers_extra(compart,num_compartlockers);
                            num_ped=guarda_ped_extra(ped,num_ped);
                            num_pedprod=guarda_pedprod_extra(pedprod,num_pedprod);
                            num_transp=guarda_transp_extra(transp,num_transp);
                            num_devo=guarda_devo_extra(dev,num_devo);

                            return 0;
                            break;
                    }
                }while(el<0 || el>1);
                break;

            case 1:
                do{
                    printf("\nElija la opcion que desee\n");
                    printf("0. salir del menu eleccion cliente\n");
                    printf("1. Iniciar sesion\n");
                    printf("2. Crear cuenta nueva\n");
                    scanf("%d",&el);
                    switch(el){
                        case 0: break;

                        case 1:



                            break;

                        case 2: //crear cuenta nueva

                            break;
                    }

                }while(el<0 || el>2);
                break;

            case 2:
                do{
                    printf("\nElija la opcion que desee\n");
                    printf("0. salir del menu eleccion administrador\n");
                    printf("1. Iniciar sesion(hace falta contrasena especial de admin para iniciar como usuario)\n");
                    printf("2. Crear cuenta nueva(hace falta contrasena especial para crear cuenta de administrador)\n");
                    scanf("%d",&el);
                    switch(el){
                        case 0: break;

                        case 1: //iniciar sesion

                            break;

                        case 2: //crear cuenta nueva

                            break;
                    }

                }while(el<0 || el>2);
                break;

            case 3:
                 do{
                    printf("\nElija la opcion que desee\n");
                    printf("0. salir del menu eleccion proveedor\n");
                    printf("1. Iniciar sesion\n");
                    printf("2. Crear cuenta nueva\n");
                    scanf("%d",&el);
                    switch(el){
                        case 0: break;

                        case 1: //iniciar sesion

                            break;

                        case 2: //crear cuenta nueva

                            break;
                    }

                }while(el<0 || el>2);
                break;

            case 4:
                do{
                    printf("\nElija la opcion que desee\n");
                    printf("0. salir del menu eleccion transportista\n");
                    printf("1. Iniciar sesion\n");
                    printf("2. Crear cuenta nueva\n");
                    scanf("%d",&el);
                    switch(el){
                        case 0: break;

                        case 1: //iniciar sesion

                            break;

                        case 2: //crear cuenta nueva

                            break;
                    }

                }while(el<0 || el>2);
                break;

        }

        fflush(stdin);
        printf("\nIntroduce una opcion: (s para seguir en la aplicacion, n para salir): ");
        scanf("%c",&s_n);
        getchar();

        do{
        if(s_n=='s' || s_n=='S'){
            out=0;
            break;
        }else{
            if(s_n=='n' || s_n=='N'){
                out=1;
                return 0;
            }else{
                printf("\nEntrada no valida, introduce s, S, n o N\n");
                out=2;
                scanf("%c",&s_n);
                getchar();
                system("cls");
                }
            }
       }while(out==2);
       system("cls");
    }while(out==0);
    return 0;
}
