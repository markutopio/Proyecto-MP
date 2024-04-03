#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "datos.h"
#define N 3

typedef struct{
char dni[10];
char nombre[21];
int edad;
}registro;

void intro_datos(registro *);
void introcliente(registro *,int);
void eliminar_salto(char *,int);
int guarda_fichero(registro *,int);
int guarda_cliente(registro *,int);
int carga_fichero(registro **,int);
void ConsultaDatos(registro *,int);
void ConsultaClientes(registro *,int);
void ModificaDatos(registro *,int);
int AltaDatos(registro **,int);
int BajaDatos(registro **, int);


int main(){
    registro *reg;
    int op,op2;
    int reg_carga,reg_exacto=0; //variable 1: numero de registros cargados, variable 2: registro exacto localizado en el vector
    char s_n;

    reg_carga=N;

    if((reg=(registro *)malloc(N*sizeof(registro)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        printf("funcionamiento correcto\n\n");

    do{
        fflush(stdin);
        printf("que quieres hacer(1-guardar datos en un fichero, 2-cargar datos de fichero a estructuras, 3-modificar datos,4-almacenar en estructuras los datos, 5-alta datos, 6-consulta datos,7-baja datos)\n\n");
        scanf("%i",&op);

        switch(op){
            case 1:
                printf("\n\nIntroduce 1 para datos y 2 para clientes: ");
                scanf("%i",&op2);
                switch(op2){
                    case 1:
                        reg_carga=guarda_fichero(reg,reg_carga); //reg_carga es el numero total de registros que se han almacenado en el fichero
                        printf("\n\nSe han guardado %i registros",reg_carga);
                        break;
                    case 2:
                        reg_carga=guarda_cliente(reg,reg_carga); //reg_carga es el numero total de registros que se han almacenado en el fichero
                        printf("\n\nSe han guardado %i registros",reg_carga);
                        break;
                    case 0: return 0;
                        break;
                }

                break;
            case 2:
                reg_carga=carga_fichero(&reg,reg_carga);
                printf("\n\nSe han cargado %i registros",reg_carga);
                break;
            case 3:
                ModificaDatos(reg,reg_carga);
                break;
            case 4:
                printf("\n\nIntroduce 1 para datos y 2 para clientes: ");
                scanf("%i",&op2);

                switch(op2){
                    case 1:
                        intro_datos(reg);
                        break;
                    case 2:
                        introcliente(reg,reg_carga);
                        break;
                    case 0: return 0;
                        break;
                }

                break;
            case 5:
                reg_exacto=AltaDatos(&reg,reg_carga);
                printf("\n\nSe ha modificado el elemento %i",reg_exacto);
                reg_carga=reg_exacto;
                break;
            case 6:
                printf("\n\nIntroduce 1 para datos y 2 para clientes: ");
                scanf("%i",&op2);

                switch(op2){
                    case 1:
                        ConsultaDatos(reg,reg_carga);
                        break;
                    case 2:
                        ConsultaClientes(reg,reg_carga);
                        break;
                    case 0: return 0;
                        break;
                }
                break;
            case 7:
                reg_exacto=BajaDatos(&reg,reg_carga);
                printf("\n\nSe ha eliminado el registro deseado");
                reg_carga=reg_exacto;
                break;
            case 0: return 0;
                break;
        }

        fflush(stdin);
        printf("\n\nSi quieres volver a elegir pulse 's': ");
        scanf("%c",&s_n);
    }while(s_n=='s');

        free(reg); //se libera la memoria
    }
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
            registro *nuevo_reg = (registro *)realloc(*reg, (i+1) * sizeof(registro));

            if (nuevo_reg == NULL) {
                printf("Error al realocar memoria\n");
                fclose(f); // Cerramos el archivo antes de salir
                return -1;
            }

            *reg = nuevo_reg;
                printf("\n%i linea",i+1);
                token=strtok(linea, "-");
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
void ModificaDatos(registro *reg,int x){
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

}


//cabecera: void intro_datos(registro *r,int x,char *c)
//precondicion:
//postcondicion: se almacenan una serie de valores al principio del programa en el vector de registros
void intro_datos(registro *r){
    int i,x;
    char c[10];
    fflush(stdin);
    for(i=0;i<N;i++){
        printf("\nIntroduce tu dni: ");
        fgets(c,10,stdin);

        fflush(stdin);

        printf("\nEl valor es %s",c);

        eliminar_salto(c,10);

        printf("\nIntroduce tu edad: ");
        scanf("%d",&x);

        fflush(stdin);

        printf("\nEl valor es %d\n",x);

        strcpy(r[i].dni,c);
        r[i].edad=x;
    }
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

    registro *nuevo_reg=(registro *)realloc(*reg,x *sizeof(registro));

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


void ConsultaClientes(registro *reg, int can_regs){
    int i;

    printf("\nLos registros almacenados son: ");
    for(i=0;i<can_regs;i++){
        printf("\nPosicion %i del vector de estructuras: [%s]-[%f]",i+1,v_clientes[i].Id_cliente,v_clientes[i].Cartera);
    }
}

void introcliente(registro *r,int a){
    int i;
    float x;
    char c[8];

    if((v_clientes=(Clientes *)malloc(a*sizeof(Clientes)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        fflush(stdin);
        for(i=0;i<N;i++){
        printf("\nIntroduce tu id: ");
        fgets(c,8,stdin);

        fflush(stdin);

        printf("\nEl valor es %s",c);

        eliminar_salto(c,8);

        strcpy(v_clientes[i].Id_cliente,c);


        printf("\nIntroduce el dinero que tienes: ");
        scanf("%f",&x);

        fflush(stdin);

        v_clientes[i].Cartera=x;
        }
    }
}


int guarda_cliente(registro *r,int a){
    FILE *f;
    int i;

    f=fopen("cliente.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%f\n",v_clientes[i].Id_cliente,v_clientes[i].Cartera); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%f",v_clientes[i].Id_cliente,v_clientes[i].Cartera); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//bajadatos elimina una posicion del vector de registros

//entonces si tu tienes N posiciones y eliminas la posicion i te queda que el vector tiene N-1 posiciones

//por lo que tendrias que devolver como entero que el vector tiene return (numero_registros_actuales-1)
