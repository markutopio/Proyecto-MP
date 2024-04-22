#include <stdio.h>
#include <time.h>
#include "me.h"

void presentacion(){
    puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
    puts("Hola! Bienvenido a ESIZON, la nueva aplicacion de la esi.");
    puts("-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-");
}


//cabecera:int ventana_inicio()
//precondicion:
//postcondicion: devuelve el valor escogido por el usuario del menu inicio
int ventana_inicio(){
    int op;

    printf("Introduce una opcion del menu: \n");
    do{
        printf("0. salir de la aplicacion(al salir se sobreescriben los datos o se anaden a los existentes)\n");
        printf("1. Cliente\n");
        printf("2. Administrador\n");
        printf("3. Transportista\n");
        printf("4. Proveedor\n");
        printf("Ingrese el numero de la opcion deseada (0-4): ");
        scanf("%d", &op);
    }while(op<0 || op>4);
    return op;
}


//cabecera:int ventana_cliente()
//precondicion:
//postcondicion: devuelve el valor escogido por el usuario del menu cliente
int ventana_cliente(){
    int op;

    printf("Introduce una opcion del menu cliente: \n");
    do{
        printf("1. Perfil\n");
        printf("2. Productos\n");
        printf("3. Descuentos\n");
        printf("4. Pedidos\n");
        printf("5. Devoluciones\n");
        printf("6. salir del menu cliente\n");
        printf("Ingrese el numero de la opcion deseada (1-6): ");
        scanf("%d", &op);
    }while(op<1 || op>6);

    return op;
}



//cabecera:int ventana_admin()
//precondicion:
//postcondicion: devuelve el valor escogido por el usuario del menu admin
int ventana_admin(){
    int op;

    printf("Introduce una opcion del menu admin: \n");
    do{
        printf("1. Perfil\n");
        printf("2. Clientes\n");
        printf("3. Proveedores\n");
        printf("4. Productos\n");
        printf("5. Categorias\n");
        printf("6. Pedidos\n");
        printf("7. Transportista\n");
        printf("8. Descuentos\n");
        printf("9. Devoluciones\n");
        printf("10. salir del menu admin\n");

        printf("Ingrese el numero de la opcion deseada (1-10): ");
        scanf("%d", &op);
    }while(op<1 || op>10);

    return op;
}


//cabecera:int ventana_proveedor()
//precondicion:
//postcondicion: devuelve el valor escogido por el usuario del menu proveedor
int ventana_proveedor(){
    int op;

    printf("Introduce una opcion del menu proveedor: \n");
    do{
        printf("1. Perfil\n");
        printf("2. Productos\n");
        printf("3. Pedidos\n");
        printf("4. salir del menu admin\n");

        printf("Ingrese el numero de la opcion deseada (1-4): ");
        scanf("%d", &op);
    }while(op<1 || op>4);

    return op;
}


//cabecera:int ventana_transportista()
//precondicion:
//postcondicion: devuelve el valor escogido por el usuario del menu transportista
int ventana_transportista(){
    int op;

    printf("Introduce una opcion del menu transportista: \n");
    do{
        printf("1. Perfil\n");
        printf("2. Repartos\n");
        printf("3. Retornos\n");
        printf("4. salir del menu transportista\n");

        printf("Ingrese el numero de la opcion deseada (1-4): ");
        scanf("%d", &op);
    }while(op<1 || op>4);

    return op;
}


//cabecera: int comprobarFecha(char *dia_cad, char *mes_cad, char *anio_cad)
//precondicion: dados unos valores para los campos de fecha
//postcondicion: devuelve la fecha actual o la futura
int comprobarFecha(char *dia_cad, char *mes_cad, char *anio_cad){
  //Obtenemos la fecha y hora actual del sistema
  time_t current_time=time(NULL);
  struct tm*current_tm=localtime(&current_time);

  //Convertimos las cadenas de caracteres a enteros
  int dia=atoi(dia_cad);
  int mes=atoi(mes_cad);
  int anio=atoi(anio_cad);

  //Verificamos si la fecha es válida
  if (dia<1||dia>31||mes<1||mes>12||anio<1900)
    return 0; // Fecha incorrecta

  //Verificamos si febrero tiene 28 o 29 días dependiendo del año bisiesto
  int feb_max_days=28;
  if ((anio%4==0&&anio%100!=0)||anio%400==0)
    feb_max_days = 29;

  //Verificamos si el día es válido para el mes especificado
  int max_days=31;
  if (mes==2)
    max_days=feb_max_days;
  else
    if (mes==4||mes==6||mes==9||mes==11)
        max_days=30;
  if (dia<1||dia>max_days)
    return 0; // Fecha incorrecta

  //Creamos una estructura tm con la fecha especificada
  struct tm input_tm=*current_tm;
  input_tm.tm_mday=dia;
  input_tm.tm_mon=mes-1;
  input_tm.tm_year=anio-1900;

  //Convertimos ambas estructuras tm a time_t
  time_t input_time=mktime(&input_tm);
  time_t current_time_plus_one_minute=current_time+60;

  //Comparamos la fecha especificada con la actual
  if (input_time<current_time){
    return 0; // Fecha anterior a la actual
  }
  else
    if (input_time >= current_time && input_time < current_time_plus_one_minute)
        return 1; //Fecha actual del sistema
    else
        return 2; //Fecha futura
}
