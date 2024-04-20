#include <stdio.h>

int main() {
    int opcion,op;

    do{
        printf("Bienvenido a Esizon, elija una opcion:\n");
        printf("1. Cliente\n");
        printf("2. Administrador\n");
        printf("3. Transportista\n");
        printf("4. Proveedor\n");
        printf("Ingrese el numero de la opcion deseada (1-4): ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Usted ha elegido la opcion Cliente, Que desea hacer?\n");
                //preguntar id cliente junto a contraseña
                //si no hay id o contraseña equivocada dar opcion de crear cliente y registrarse
                //hacer llamada a ventana cliente
                switch(op){
                    case 1:
                        p=perfil_cliente(cli,cli_exac);
                        break;
                    case 2:
                        p=productos_cliente(cli,cli_exac);
                        break;
                    case 3: 
                        p=descuentos_cliente(cli,cli_exac);
                        break;
                    case 4: 
                        p=pedidos_cliente(cli,cli_exac);
                        break;
                    case 5:
                        p=devoluciones_cliente(cli,cli_exac);
                        break;
                    case 6:
                        break;
                    
                }
                break;
            case 2:
                printf("Usted ha elegido la opcion Administrador, Que desea hacer?\n");
                break;
            case 3:
                printf("Usted ha elegido la opcion Transportista, Que desea hacer?\n");
                break;
            case 4:
                printf("Usted ha elegido la opcion Proveedor, Que desea hacer?\n");
                break;
            default:
                printf("Opcion no valida. Por favor, intentelo de nuevo\n");
        }
    } while (opcion<1 || opcion>4);

    void menu_inicio_sesion_clientes(){
    int opcion,a;
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
                a=crearcuenta();
                break;
            case 3:
                salir
                break;
            default:
                printf("Opción no válida.\\n");
        }
    }
}
    return 0;
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


do{
fflush(stdin);
printf("\nIntroduce una opcion: (s para seguir, n para salir): ");
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
    printf("cls");
}while(out==0);
