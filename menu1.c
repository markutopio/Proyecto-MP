#include <stdio.h>

int main() {
    int opcion;

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

    return 0;
}

