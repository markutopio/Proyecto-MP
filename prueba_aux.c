#include "prueba_aux.h"

int main(){
    registro *reg;
    Productos *p;
    Clientes *cli;
    Categorias *cat;

    int op,op2,out;
    int num_clientes=0, num_datos=0, num_prod=0, num_cat=0; //variable 1: numero de registros cargados, variable 2: registro exacto localizado en el vector
    int cliente_exac, datos_exac, prod_exac, cat_exac;
    char s_n;


    do{
        fflush(stdin);
        printf("que quieres hacer: (elige un numero entre 1 a 7 (0 para salir))\n");
        op=ventana_eleccion();

        system("cls");

        switch(op){
            case 1: //llamada a funciones de guardado en ficheros
                printf("\n\nIntroduce 1 para datos, 2 para clientes, 3 para productos y 4 para categorias: ");
                scanf("%i",&op2);
                switch(op2){
                    case 1:
                        num_datos=guarda_fichero(reg,num_datos); //reg_carga es el numero total de registros que se han almacenado en el fichero
                        printf("\n\nSe han guardado %i registros",num_datos);
                        break;
                    case 2:
                        num_clientes=guarda_cliente(cli,num_clientes); //reg_carga es el numero total de registros que se han almacenado en el fichero
                        printf("\n\nSe han guardado %i registros",num_clientes);
                        break;
                    case 3:
                        num_prod=guarda_prod(p,num_prod);
                        printf("\n\nSe han guardado %i registros",num_prod);
                        break;
                    case 4:
                        num_cat=guarda_cat(cat,num_cat);
                        printf("\n\nSe han guardado %i registros",num_cat);
                        break;
                    case 0: return 0;
                        break;
                }
                break;

            case 2: //llamada a funciones de carga de datos desde ficheros
                printf("\n\nIntroduce 1 para datos, 2 para clientes, 3 para productos y 4 para categorias: ");
                scanf("%i",&op2);
                switch(op2){
                    case 1:
                        num_datos=carga_fichero(&reg,num_datos); //reg_carga es el numero total de registros que se han almacenado en el fichero
                        printf("\n\nSe han guardado %i registros",num_datos);
                        break;
                    case 2:
                        num_clientes=carga_clientes(&cli,num_clientes); //reg_carga es el numero total de registros que se han almacenado en el fichero
                        printf("\n\nSe han guardado %i registros",num_clientes);
                        break;
                    case 3:
                        num_prod=carga_prod(&p,num_prod);
                        printf("\n\nSe han guardado %i registros",num_prod);
                        break;
                    case 4:
                        num_cat=carga_cat(&cat,num_cat);
                        printf("\n\nSe han guardado %i registros",num_cat);
                        break;
                    case 0: return 0;
                        break;
                }
                break;

            case 3: //llamada a funciones de modificacion de registros
                printf("\n\nIntroduce 1 para datos, 3 para productos y 4 para categorias: ");
                scanf("%i",&op2);
                switch(op2){
                    case 1:
                        datos_exac=ModificaDatos(reg,datos_exac);
                        printf("\n\nSe ha modificado el registro %i",datos_exac);
                        break;
                    /*case 2:
                        =ModificaCliente(cli,reg_carga);
                        printf("\n\nSe ha modificado el registro %i",reg_exacto);
                        break;*/
                    case 3:
                        prod_exac=modifica_productos(p,prod_exac);
                        printf("\n\nSe ha modificado el registro %i",prod_exac);
                        break;
                    case 4:
                        num_cat=modifica_categorias(cat,num_cat);
                        printf("\n\nSe ha modificado el registro %i",num_cat);
                        break;
                    case 0: return 0;
                        break;
                }
                break;

            case 4: //llamada a funciones de introduccion de datos
                printf("\n\nIntroduce 1 para datos, 2 para clientes, 3 para productos y 4 para categorias: ");
                scanf("%i",&op2);
                switch(op2){
                    case 1:
                        num_datos=intro_datos(&reg,num_datos);
                        printf("\n\nSe han introducido %i registros",num_datos);
                        break;
                    case 2:
                        num_clientes=introcliente(&cli,num_clientes);
                        printf("\n\nSe han introducido %i registros",num_clientes);
                        break;
                    case 3:
                        num_prod=intro_productos(&p,num_prod);
                        printf("\n\nSe han introducido %i registros",num_prod);
                        break;
                    case 4:
                        num_cat=intro_categorias(&cat,num_cat);
                        printf("\n\nSe han introducido %i registros",num_cat);
                        break;
                    case 0: return 0;
                        break;
                }
                break;

            case 5: //llamada a funciones de alta de datos
                printf("\n\nIntroduce 1 para datos, 3 para productos y 4 para categorias: ");
                scanf("%i",&op2);
                switch(op2){
                    case 1:
                        datos_exac=AltaDatos(&reg,num_datos);
                        printf("\n\nSe ha anadido un elemento teniendo ahora %i elementos",datos_exac);
                        num_datos=datos_exac;
                        break;
                    /*case 2:
                        reg_exacto=AltaClientes(&cli,reg_carga);
                        printf("\n\nSe ha anadido un elemento teniendo ahora %i elementos",reg_exacto);
                        reg_carga=reg_exacto;
                        break;*/
                    case 3:
                        prod_exac=alta_productos(&p,num_prod);
                        printf("\n\nSe ha anadido un elemento teniendo ahora %i elementos",prod_exac);
                        num_prod=prod_exac;
                        break;
                    case 4:
                        cat_exac=alta_categorias(&cat,num_cat);
                        printf("\n\nSe ha anadido un elemento teniendo ahora %i elementos",cat_exac);
                        num_cat=cat_exac;
                        break;
                    case 0: return 0;
                        break;
                }
                break;

            case 6: //llamada a funciones de consulta de datos
                printf("\n\nIntroduce 1 para datos, 2 para clientes, 3 para productos y 4 para categorias: ");
                scanf("%i",&op2);

                switch(op2){
                    case 1:
                        ConsultaDatos(reg,num_datos);
                        break;
                    case 2:
                        ConsultaClientes(cli,num_clientes);
                        break;
                    case 3:
                        listado_productos(p,num_prod);
                        break;
                    case 4:
                        listado_categorias(cat,num_cat);
                        break;
                    case 0: return 0;
                        break;
                }
                break;

            case 7: //llamada a funciones de baja de datos o eliminacion
                printf("\n\nIntroduce 1 para datos, 3 para productos y 4 para categorias: ");
                scanf("%i",&op2);
                switch(op2){
                    case 1:
                        datos_exac=BajaDatos(&reg,num_datos);
                        printf("\n\nSe ha eliminado el registro %i",datos_exac);
                        num_datos=datos_exac;
                        break;
                    /*case 2:
                        reg_exacto=BajaClientes(&cli,reg_carga);
                        printf("\n\nSe ha eliminado el registro %i",reg_exacto);
                        reg_carga=reg_exacto;
                        break;*/
                    case 3:
                        prod_exac=baja_productos(&p,num_prod);
                        printf("\n\nSe ha eliminado el registro %i",prod_exac);
                        num_prod=prod_exac;
                        break;
                    case 4:
                        cat_exac=baja_categorias(&cat,num_cat);
                        printf("\n\nSe ha eliminado el registro %i",cat_exac);
                        num_cat=cat_exac;
                        break;
                    case 0: return 0;
                        break;
                }
                break;

           /* case 8: //llamada a funciones de busqueda de datos
                printf("\n\nIntroduce 1 para datos, 2 para clientes, 3 para productos y 4 para categorias: ");
                scanf("%i",&op2);
*/
            case 0: return 0;
                break;
        }

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
       system("cls");
    }while(out==0);

    free(reg); //se libera la memoria
    free(cli);  //se libera la memoria
    free(p);    //se libera la memoria
    free(cat);   //se libera la memoria
}


int guarda_fichero(registro *r,int a){
    FILE *f;
    int i;

    f=fopen("datos.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%d\n",r[i].dni,r[i].edad); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%d",r[i].dni,r[i].edad); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_fichero(registro **reg,int x){ //x es el numero de registros que se han guardado
    printf("\nacceso correcto a carga\n");
    FILE *f;
    char linea[100];
    *reg=NULL;
    int i=0,j;
    char *token;

    if((f=fopen("datos.txt","r"))!=NULL){
        while(fgets(linea,100,f)){
            registro *nuevo_reg=(registro *)realloc(*reg,(i+1)*sizeof(registro));

            if (nuevo_reg==NULL){
                printf("Error al realocar memoria\n");
                fclose(f); // Cerramos el archivo antes de salir
                return -1;
            }

                *reg=nuevo_reg;
                printf("\n%i linea",i+1);
                token=strtok(linea,"-");
                strcpy((*reg)[i].dni,token);

                token=strtok(NULL,"\n");//último de la linea \n
                (*reg)[i].edad=atoi(token);
                printf("\ndni [%s] edad [%d]\n",(*reg)[i].dni,(*reg)[i].edad);
                i++;
            }
        }

        printf ("Se ha leido el fichero con %d registros \n\n",i);
        for(j=0;j<i;j++){
            printf("dni [%s] edad [%d]\n",(*reg)[j].dni,(*reg)[j].edad);
        }
    fclose(f);
    return i;
}


//cabecera: int ModificaDatos(registro *reg,int x)
//precondicion: teniendo una serie de registros en un vector de registros
//postcondicion: devuelve la posicion del elemento que se ha modificado y si se ha modificado el elemento
int ModificaDatos(registro *reg,int x){
    int i,aux,ed;
    int encontrado=0;
    char posicion[10],camb[10];

    printf("Introduce el DNI que quiere modificar: ");
    scanf("%s",posicion);
    eliminar_salto(posicion,10);

    for(i=0;i<x;i++){
        if(strcmp(reg[i].dni,posicion)==0){
            aux=i;
            printf("\nEl dni auxiliar [%s] y el almacenado [%s] son iguales\n",posicion,reg[i].dni);
            strcpy(reg[i].dni,posicion);

            printf("\nIntroduce ahora el nuevo dni a almacenar: ");
            scanf("%s",camb);

            strcpy(reg[i].dni,camb);

            printf("\nIntroduce la edad nueva: ");
            scanf("%i",&ed);
            encontrado=1;

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


//cabecera: void intro_datos(registro *r,int x,char *c)
//precondicion:
//postcondicion: se almacenan una serie de valores al principio del programa en el vector de registros
int intro_datos(registro **r,int a){
    int i,x;
    char c[10];
    fflush(stdin);

    printf("Cuantos productos quieres meter: ");
    scanf("%i",&a);
    getchar();

    if((*r=(registro *)malloc(a*sizeof(registro)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        for(i=0;i<a;i++){
        printf("\nIntroduce tu dni: ");
        fgets(c,10,stdin);

        fflush(stdin);

        printf("\nEl valor es %s",c);

        eliminar_salto(c,10);

        printf("\nIntroduce tu edad: ");
        scanf("%d",&x);

        fflush(stdin);

        printf("\nEl valor es %d\n",x);

        strcpy(((*r)[i].dni),c);
        ((*r)[i].edad)=x;
        }
    }
    return a;
}


//cabecera: int AltaDatos(registro *reg,int x)
//precondicion: inicializados una serie de valores en el vector de estructuras
//postcondicion: añade un elemento extra al vector de estructuras
int AltaDatos(registro **reg,int x){ //x es el numero de registros que tenemos y si lo aumentamos en 1 podremos añadir uno extra
    int eda;
    char cadena[10];

    // Incrementamos el contador de registros
    x++;

    printf("Hay %i registros después de aumentar en 1.\n\n",x);

    registro *nuevo_reg=(registro *)realloc(*reg,x*sizeof(registro));

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }
    *reg=nuevo_reg;

    // Solicitamos el nuevo DNI
    printf("Introduce el nuevo DNI: ");
    scanf("%s",cadena);
    eliminar_salto(cadena,10); // Eliminamos el carácter de nueva línea si existe

    // Copiamos el DNI al registro
    strcpy((*reg)[x-1].dni,cadena);

    // Solicitamos la nueva edad
    printf("\nIntroduce la nueva edad: ");
    scanf("%i",&eda);
    (*reg)[x-1].edad=eda;

    return x;
}


int BajaDatos(registro **reg,int x){ //x es el numero de registros que tenemos y deberemos reducirlo en uno para elminar la ultima posicion
    int i,aux;
    char cadena[10];
    int encontrado=0;

    printf("Introduce el dni que quiere eliminar: ");
    scanf("%s",cadena);
    eliminar_salto(cadena,10);


    for(i=0;i<x;i++){
        printf("\nSe accede al bucle");
        if((strcmp((*reg)[i].dni,cadena))==0){
            printf("\nSe ha encontrado el elemento %s",cadena);
            aux=i;
            encontrado=1;
            break;
        }
    }

    if(encontrado==1){
        do{
            strcpy((*reg)[aux].dni,(*reg)[aux+1].dni);
            (*reg)[aux].edad=(*reg)[aux+1].edad;
            aux++;
        }while(aux<x);
    }else{
        return -1;
    }

    registro *nuevo_reg=(registro *)realloc(*reg,(x-1) *sizeof(registro)); //elimina una posicion del vector que en este caso sera la ultima

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }

    *reg=nuevo_reg;
    return x-1;
}


//cabecera:void eliminar_salto(char *v_n,int n)
//precondicion: inicializada una cadena pasada como parametro
//postcondicion: devuelve la cadena solicitada sin caracter salto de line
void eliminar_salto(char *v_n,int n){ //n es el numero de caracteres de la cadena
    int i;

    for(i=0;i<n;i++){
        if(v_n[i]=='\n') {
        	v_n[i]='\0';
        	printf("\nSe ha sustituido con exito\n");
        	break;
		}
    }
}


//cabecera: void ConsultaDatos(registro *reg, int can_regs)
//precondicion: inicializados una serie de registros en un vector de estructuras
//postcondicion: muestra todos los elementos almacenados en el vector de estructuras
void ConsultaDatos(registro *reg, int can_regs){
    int i;

    printf("\nLos registros almacenados son: ");
    for(i=0;i<can_regs;i++){
        printf("\nPosicion %i del vector de estructuras: [%s]-[%i]",i+1,reg[i].dni,reg[i].edad);
    }
}


void ConsultaClientes(Clientes *reg,int can_regs){
    int i;

    printf("\nLos registros almacenados son: ");
    for(i=0;i<can_regs;i++){
        printf("\nPosicion %i del vector de estructuras: [%s]-[%f]",i+1,reg[i].Id_cliente,reg[i].Cartera);
    }
}

int introcliente(Clientes **cli,int a){
    int i;
    float x;
    char c[8];

    if((cli=(Clientes **)malloc(a*sizeof(Clientes)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        fflush(stdin);
        for(i=0;i<N;i++){
        printf("\nIntroduce tu id: ");
        fgets(c,8,stdin);

        fflush(stdin);

        printf("\nEl valor es %s",c);

        eliminar_salto(c,8);

        strcpy((*cli)[i].Id_cliente,c);


        printf("\nIntroduce el dinero que tienes: ");
        scanf("%f",&x);

        fflush(stdin);

        (*cli)[i].Cartera=x;
        }
    }
    return a;
}

int ventana_eleccion(){
    int i;

    do{
        printf("\n0-salir del menu eleccion");
        printf("\n1-guardar datos en un fichero");
        printf("\n2-cargar datos de fichero a estructuras");
        printf("\n3-modificar datos en estructuras");
        printf("\n4-almacenar los datos en estructuras");
        printf("\n5-dar de alta datos");
        printf("\n6-consultar datos en estructuras");
        printf("\n7-dar de baja datos\n");
        scanf("%i",&i);
    }while(i<0 || i>7);

    return i;
}
//bajadatos elimina una posicion del vector de registros

//entonces si tu tienes N posiciones y eliminas la posicion i te queda que el vector tiene N-1 posiciones

//por lo que tendrias que devolver como entero que el vector tiene return (numero_registros_actuales-1)
