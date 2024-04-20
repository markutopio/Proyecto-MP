#include "menu.h"
void presentacion(){
    puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.");
    puts("Hola! Bienvenido a ESIZON, la nueva aplicacion de la esi.");
    puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.");
}

menu_inicio1(){
int opcion;
printf("Pulsa\n");
puts("Intro productos");
puts("Alta productos");
puts("Baja productos");
puts("Lista productos");
puts("Modifica productos");
puts("Busca productos");
    switch (opcion){
        case 1:
            printf("Has elegido intro productos\n");
            intro_productos(Productos **, int);
            break;
        case 2:
            printf("Has elegido alta productos\n");
            alta_productos(Productos **, int);
            break;
        case 3:
            printf("Has elegido baja productos\n");
            baja_productos(Productos **, int);
            break;
        case 4:
            printf("Has elegido listar productos\n");
            listado_productos(Productos *, int);
            break;
        case 5:
            printf("Has elegido modificar productos\n");
            modifica_productos(Productos *, int);
            break;
        case 6:
            printf("Has elegido buscar productos\n");
            busqueda_prod(Productos *, int);
            break;
    }

}



int salir_aplicacion(){
    int int_salir=0;
    char salir;
    do
    {
        printf("\n\Seguro que quieres abandonar?(s/n): ");
        fflush(stdin);
        scanf("%c",&salir);
        if(salir=='s'||salir=='S')
            int_salir=1;
        if(salir=='n'||salir=='N')
            int_salir=0;
        if(salir!='s'&&salir!='n'&&salir!='S'&&salir!='N')
            printf("\nInserte una opcion que sea valida\n");
    }
    while(salir!='s'&&salir!='n'&&salir!='S'&&salir!='N');
    return int_salir;
}

void menu_inicio_sesion_clientes(){
    int opcion;
    printf("\nElija la opcion que desee\n");
    puts("1. Iniciar sesion\n");
    puts("2. Crear cuenta nueva\n");
    puts("3. Salir de la aplicacion\n");
    scanf("%d",&opcion);
    switch (opcion) {
            case 1:
                Iniciarsesion();
                break;
            case 2:
                ;
                break;
            case 3:
                ;
                break;
            default:
                printf("Opción no válida.\\n");
        }
    }
}


void menu_perfil_cliente(){
int opcion;
puts("*----------------------------------------*");
printf("\n\nElige la opcion que desee\n");
puts("1. Modificar datos");
puts("2. Volver al menu");
puts("*----------------------------------------*");
scanf("%d",&opcion);
switch (opcion) {
            case 1:
                k
                break;
            case 2:
                k
                break;
            case 3:
                k
                break;
            default:
                printf("Opción no válida.\\n");
        }
    }
}
void menu_presentacion_cliente(int a){
int op,i=0;
do{
    op=ventana_usuario();
    i++;
    switch (opcion) {
            case 1:
                Consultarperfilusu();
                break;
            case 2:
                Consultacartera();
                break;
            case 3:
                anadir_din();
                break;
            case 4:
                eliminar_din();
                break;
            case 5:
                salir_aplicacion();
                break;
            default:
                printf("Opción no válida.\\n");
            }
    }while(op>i);

}

//menu proveedor

void menu_presentacion_proveedor(){
int op,i=0;
do{
            op=ventana_proveed();
            case 1:
                Consultarperfilprov();
                break;
            case 2:
                consultaprod();
                break;
            case 3:
                consultaped();
                break;
            case 4:
                salir_aplicacion();
                break;
            default:
                printf("Opción no válida.\\n");
}
}

void menu_inicio_sesion_proveedores(){
    int opcion;
    printf("\nElija la opcion que desee\n");
    puts("1. Iniciar sesion\n");
    puts("2. Crear cuenta nueva\n");
    puts("3. Salir de la aplicacion\n");
    scanf("%d",&opcion);
    switch (opcion) {
            case 1:
                Iniciarsesion();
                break;
            case 2:
                ;
                break;
            case 3:
                salir_aplicacion();
                break;
            default:
                printf("Opción no válida.\\n");
        }
    }


//menu Transportistas

void menu_presentacion_transportista(){
int op,i=0;
do{
   op=ventana_transp();
   switch (opcion) {
            case 1:
                Consultarperfilprov();
                break;
            case 2:
                consultarepart();
                break;
            case 3:
                consultaretorn();
                break;
            case 4:
                salir_aplicacion();
                break;
            default:
                printf("Opción no válida.\\n");
        }
}
}

void menu_inicio_sesion_transportistas(){
    int opcion;
    printf("\nElija la opcion que desee\n");
    puts("1. Iniciar sesion\n");
    puts("2. Crear cuenta nueva\n");
    puts("3. Salir de la aplicacion\n");
    scanf("%d",&opcion);
    switch (opcion) {
            case 1:
                Iniciarsesion();
                break;
            case 2:
                ;
                break;
            case 3:
                salir_aplicacion();
                break;
            default:
                printf("Opción no válida.\\n");
        }
}

//menu admin

void menu_presentacion_admin(){
int op,i=0;
do{
    op=ventana_admin();
    switch (opcion){
            case 1:
                Consultarperfiladmin();
                break;
            case 2:
                consultacliente();
                break;
            case 3:
                consultaprov();
                break;
            case 4:
                consultaprod();
                break;
            case 5:
                consultacat();
                break;
            case 6:
                consultaped();
                break;
            case 7:
                consultatransp();
                break;
            case 8:
                consultadesc();
                break;
            case 9:
                consultadev();
                break;
            case 10:
                salir_aplicacion();
                break;
            default:
                printf("Opción no válida.\\n");
}

        }
}


void menu_inicio_sesion_admin(){
    int opcion;
    printf("\nElija la opcion que desee\n");
    puts("1. Iniciar sesion\n");
    puts("2. Crear cuenta nueva\n");
    puts("3. Salir de la aplicacion\n");
    scanf("%d",&opcion);
    switch (opcion) {
            case 1:
                Iniciarsesion();
                break;
            case 2:
                ;
                break;
            case 3:
                salir_aplicacion();
                break;
            default:
                printf("Opción no válida.\\n");
        }
}


int ventana_usuario(){
int opcion;
do{
    printf("\n\nElija la opcion que desee\n");
    printf("*---------------------------------------*");
    puts("1. Perfil");
    puts("2. Consulta de cartera");
    puts("3. Agregar dinero a la cartera");
    puts("4. Retirar dinero de la cartera");
    puts("5. Cerrar sesion");
    printf("*---------------------------------------*");
    scanf("%d",&opcion);
}while(1<=opcion || opcion>=5)

return opcion;
}

int ventana_admin(){
int opcion;
do{
    printf("\n\nElija la opcion que desee\n");
    printf("*---------------------------------------*");
    puts("1. Perfil");
    puts("2. Consulta de clientes");
    puts("3. Consulta de proveedores");
    puts("4. Consulta de productos");
    puts("5. Consulta de categorias");
    puts("6. Consulta de pedidos");
    puts("7. Consulta de transportistas");
    puts("8. Consulta de descuentos");
    puts("9. Consulta de devoluciones");
    puts("10. Cerrar sesion");
    printf("*---------------------------------------*");
    scanf("%d",&opcion);
}while(1<=opcion || opcion>=10)
return opcion;
}

int ventana_proveed(){
int opcion;
do{
    printf("\nElija la opcion que desee\n");
    puts("1. Iniciar sesion\n");
    puts("2. Crear cuenta nueva\n");
    puts("3. Salir de la aplicacion\n");
    scanf("%d",&opcion);
}while(1<=opcion || opcion>=3);
return opcion;
}

int ventana_transp(){
do{
    printf("\n\nElija la opcion que desee\n");
    printf("*---------------------------------------*");
    puts("1. Perfil");
    puts("2. Consulta de repartos");
    puts("3. Consulta de retornos");
    puts("4. Cerrar sesion");
    printf("*---------------------------------------*");
    scanf("%d",&opcion);
}while(1<=opcion || opcion>=4);
return opcion;
}


