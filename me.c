#include <stdio.h>
#include <time.h>
#include "me.h"
//cabecera:void presentacion()
//Precondicion:
//postcondicion: devuelve un mensaje de bienvenida a la aplicacion
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
//cabecera:int iniciar_cliente()
//precondicion:pide el tipo de registro del que se va a acceder y dos enteros, uno a puntero
//postcondicion:permite que se pueda acceder a la cuenta del usuario cliente administrado

int iniciar_cliente(Clientes *cli, int a, int *ps){
    int i, encontrado, intentos = 0;
    encontrado=0;
    char correo[31], contra[16], opcion;

    while(intentos<3 && encontrado==0){
        printf("\nEscribe su correo para acceder: ");
        fflush(stdin);
        gets(correo);
        printf("\nEscribe su contraseña para acceder: ");
        fflush(stdin);
        gets(contra);

        for(i=0;i<=a&&encontrado==0;i++){
            if(strcmp(cli[i].email, correo)==0 && strcmp(cli[i].Contrasena,contra)==0){
                if(comprobar_id(cli[i].email)==1){
                    encontrado=1;
                    *ps=i;
                    printf("\n\nBienvenido de nuevo %s (Usuario)", cli[(*ps)].Nomb_cliente);
                }
            }
        }

        if(encontrado == 0){
            puts("\n\nUsuario o contraseña no válidos.");
            intentos++;
            if(intentos == 3){
                printf("¿Desea crear una nueva cuenta? (S/N): ");
                fflush(stdin);
                opcion=getchar();
                if(opcion=='S' || opcion=='s'){
                    crear_cliente();
                    intentos = 0;
                }
            }
        }
    }
    return encontrado;
}

//cabecera:int iniciar_admin()
//precondicion:pide el tipo de registro al cual se va a acceder y dos enteros, uno puntero
//postcondicion:permite el acceso a la cuenta del administrador correspondiente
int iniciar_admin(Adminprov *adm, int a, int *ps){
    int i, encontrado, intentos = 0;
    encontrado=0;
    char correo[31], contra[16], opcion;

    while(intentos<3 && encontrado==0){
        printf("\nEscribe su correo para acceder: ");
        fflush(stdin);
        gets(correo);
        printf("\nEscribe su contraseña para acceder: ");
        fflush(stdin);
        gets(contra);

        for(i=0;i<=a&&encontrado==0;i++){
            if(strcmp(adm[i].email, correo)==0 && strcmp(adm[i].Contrasena,contra)==0){
                if(comprobar_id(adm[i].email)==1){
                    encontrado=1;
                    *ps=i;
                    printf("\n\nBienvenido de nuevo %s (Usuario)", adm[(*ps)].Nombre_empre);
                }
            }
        }

        if(encontrado == 0){
            puts("\n\nUsuario o contraseña no válidos.");
            intentos++;
            if(intentos == 3){
                printf("¿Desea crear una nueva cuenta? (S/N): ");
                fflush(stdin);
                opcion=getchar();
                if(opcion=='S' || opcion=='s'){
                    crear_admin();
                    intentos = 0;
                }
            }
        }
    }
    return encontrado;
}

//cabecera:int iniciar_prov()
//precondicion:pide el tipo del registro del que se vaya a iniciar sesion, dos enteros, uno puntero
//postcondicion:permite el acceso a la cuenta del proveedor administrado
int iniciar_prov(Adminprov *prov, int a, int *ps){
    int i, encontrado, intentos = 0;
    encontrado=0;
    char correo[31], contra[16], opcion;

    while(intentos<3 && encontrado==0){
        printf("\nEscribe su correo para acceder: ");
        fflush(stdin);
        gets(correo);
        printf("\nEscribe su contraseña para acceder: ");
        fflush(stdin);
        gets(contra);

        for(i=0;i<=a&&encontrado==0;i++){
            if(strcmp(prov[i].email, correo)==0 && strcmp(prov[i].Contrasena,contra)==0){
                if(comprobar_id(prov[i].email)==1){
                    encontrado=1;
                    *ps=i;
                    printf("\n\nBienvenido de nuevo %s (Usuario)", prov[(*ps)].Nombre_empre);
                }
            }
        }

        if(encontrado == 0){
            puts("\n\nUsuario o contraseña no válidos.");
            intentos++;
            if(intentos == 3){
                printf("¿Desea crear una nueva cuenta? (S/N): ");
                fflush(stdin);
                opcion=getchar();
                if(opcion=='S' || opcion=='s'){
                    crear_prov();
                    intentos = 0;
                }
            }
        }
    }
    return encontrado;
}

//cabecera:int iniciar_transp()
//precondicion:pide el tipo de registro del que se va a iniciar sesion, dos enteros, uno de ellos puntero
//postcondicion:permite el acceso a la cuenta del proveedor administrado
int iniciar_transp(Transportistas *transp, int a, int *ps){
    int i, encontrado, intentos = 0;
    encontrado=0;
    char correo[31], contra[16], opcion;

    while(intentos<3 && encontrado==0){
        printf("\nEscribe su correo para acceder: ");
        fflush(stdin);
        gets(correo);
        printf("\nEscribe su contraseña para acceder: ");
        fflush(stdin);
        gets(contra);

        for(i=0;i<=a&&encontrado==0;i++){
            if(strcmp(transp[i].email, correo)==0 && strcmp(transp[i].contrasena,contra)==0){
                if(comprobar_id(transp[i].email)==1){
                    encontrado=1;
                    *ps=i;
                    printf("\n\nBienvenido de nuevo %s (Usuario)", transp[(*ps)].Nombre_transp);
                }
            }
        }

        if(encontrado == 0){
            puts("\n\nUsuario o contraseña no válidos.");
            intentos++;
            if(intentos == 3){
                printf("¿Desea crear una nueva cuenta? (S/N): ");
                fflush(stdin);
                opcion=getchar();
                if(opcion=='S' || opcion=='s'){
                    crear_transp();
                    intentos = 0;
                }
            }
        }
    }
    return encontrado;
}

int comprobar_id(char *id_usu){
    int j,salir=0,encontrado;
    //Iniciamos el vector como 0001
    char vector[5] = "0001";
    //Se hara el bucle mientras no sea 9999 el vector y mientras salir sea 0
    while ((strcmp(vector, "9999"))!=0&&salir==0) {
        encontrado=0;
        //Comprobamos que ese id no existe ya, si existe encontrado sera 1, si no existe sera 0
        while(encontrado==0){
            if (strcmp(vector,id_usu) == 0){
                encontrado=1;
                salir=1;
            }
            j=3;
            while (vector[j]=='9') {
                vector[j]='0';
                j--;
            }
            vector[j]++;
        }
        //Aumento del vector
    }
    return encontrado;
}

//cabecera:int crear_cliente(Clientes *cli, int *a)
//precondicion:pide un puntero del registro cliente para crear la cuenta buscada y un puntero entero
//postcondicion:devuelve una cuenta creada con un nombre, correo y contrasena almacenada
void crear_cliente(Clientes *cli, int *a){
  char correo[31], contra[16], nombre[21];
    printf("Creando una nueva cuenta...\n");
    fflush(stdin);
    printf("Introduzca su nombre\n");
    fflush(stdin);
    printf("Ingrese su correo electrónico: \n");
    fflush(stdin);
    gets(correo);
    printf("Cree una contraseña: \n");
    fflush(stdin);
    gets(contra);

    // Aquí deberías agregar la lógica para verificar que el correo no esté ya en uso
    // y que la contraseña cumpla con los requisitos de seguridad

    // Si todo es correcto, agregamos el nuevo usuario al array de transportistas
    strcpy(cli[*a].Nomb_cliente, nombre);
    strcpy(cli[*a].email, correo);
    strcpy(cli[*a].Contrasena, contra);
    // Incrementamos el contador de transportistas
    (*a)++;
    printf("Usuario creado exitosamente. Bienvenido %s!\n", nombre);
}

//cabecera: int crear_admin(Adminprov *adm, int *a)
//precondicion:pide un puntero al registro admin indicado y un puntero entero
//postcondicion:devuelve la creacion de una cuenta nueva de administrador, almacenando un correo y una contrasena
void crear_admin(Adminprov *adm, int *a){
    char correo[31], contra[16];
    printf("Creando una nueva cuenta...\n");
    fflush(stdin);
    printf("Ingrese su correo electrónico: \n");
    fflush(stdin);
    gets(correo);
    printf("Cree una contraseña: \n");
    fflush(stdin);
    gets(contra);

    // Aquí deberías agregar la lógica para verificar que el correo no esté ya en uso
    // y que la contraseña cumpla con los requisitos de seguridad

    // Si todo es correcto, agregamos el nuevo usuario al array de transportistas
    strcpy(adm[*a].email, correo);
    strcpy(adm[*a].Contrasena, contra);
    // Incrementamos el contador de transportistas
    (*a)++;
    printf("Usuario creado exitosamente. Bienvenido %s!\n", correo);
}

//cabecera:int crear_prov(Adminprov *prov, int *a)
//precondicion:pide un puntero al registro indicado y un puntero entero
//postcondicion:devuelve la creacion de una cuenta de proveedor, almacenando un correo y una contrasena
void crear_prov(Adminprov *prov, int *a){
    char correo[31], contra[16];
    printf("Creando una nueva cuenta...\n");
    fflush(stdin);
    printf("Ingrese su correo electrónico: \n");
    fflush(stdin);
    gets(correo);
    printf("Cree una contraseña: \n");
    fflush(stdin);
    gets(contra);

    // Aquí deberías agregar la lógica para verificar que el correo no esté ya en uso
    // y que la contraseña cumpla con los requisitos de seguridad

    // Si todo es correcto, agregamos el nuevo usuario al array de transportistas
    strcpy(prov[*a].email, correo);
    strcpy(prov[*a].Contrasena, contra);
    // Incrementamos el contador de transportistas
    (*a)++;
    printf("Usuario creado exitosamente. Bienvenido %s!\n", correo);
}

//cabecera:int crear_transp(Transportistas *transp, int *a)
//precondicion:pide un puntero a el registro indicado y un puntero entero
//postcondicion:crea una nueva cuenta de transportista almacenando un nuevo nombre, correo y contrasena
void crear_transp(Transportistas *transp, int *a){
    char correo[31], contra[16], nombre[21];
    printf("Creando una nueva cuenta...\n");
    fflush(stdin);
    printf("Introduzca su nombre: \n");
    printf("Ingrese su correo electrónico: \n");
    fflush(stdin);
    gets(correo);
    printf("Cree una contraseña: \n");
    fflush(stdin);
    gets(contra);

    // Aquí deberías agregar la lógica para verificar que el correo no esté ya en uso
    // y que la contraseña cumpla con los requisitos de seguridad

    // Si todo es correcto, agregamos el nuevo usuario al array de transportistas
    strcpy(transp[*a].Nombre_transp,nombre);
    strcpy(transp[*a].email, correo);
    strcpy(transp[*a].Contrasena, contra);
    // Incrementamos el contador de transportistas
    (*a)++;
    printf("Usuario creado exitosamente. Bienvenido %s!\n", nombre);
}

