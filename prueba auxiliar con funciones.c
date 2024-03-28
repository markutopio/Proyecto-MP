#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 3

typedef struct{
char dni[10];
char nombre[21];
int edad;
}registro;

void intro_datos(registro *,int,char *);
void eliminar_salto(char *,int);
int guarda_fichero(registro *, char *,int);
int carga_fichero(registro **,int);
int ConsultaDatos(registro *, int, char *, registro *);
int ModificaDatos(registro *);
int AltaDatos(registro **, int, registro*);
int BajaDatos(registro **, int, char *);


int main(){
    registro *reg;
    int edad,op;
    char dni[10];
    int a,b;
    char s_n;

    if((reg=(registro *)malloc(N*sizeof(registro)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        printf("funcionamiento correcto\n\n");

    do{
        fflush(stdin);
        printf("que quieres hacer(1-guardar datos en un fichero, 2-cargar datos de fichero a estructuras, 3-modificar datos,4-almacenar en estructuras los datos, 5-alta datos, 6-baja datos)\n\n");
        scanf("%i",&op);

        switch(op){
            case 1:
                a=guarda_fichero(reg,dni,edad);
                printf("\n\nSe han guardado %i registros",a);
                break;
            case 2:
                b=carga_fichero(&reg,a);
                printf("\n\nSe han cargado %i registros",b);
                break;
            case 3:
                b=ModificaDatos(reg);
                printf("\n\nSe ha modificado la posicion %i del vector de estructuras\n",b);
                break;
            case 4:
                intro_datos(reg,edad,dni);
                break;
            default: return 0;
        }

        printf("\n\nSi quieres volver a elegir pulse 's': ");
        scanf("%c",&s_n);
    }while(s_n=='s');

        free(reg); //se libera la memoria
    }
}

int guarda_fichero(registro *r,char *c,int x){
    FILE *f;
    int i;

    f=fopen("datos.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<N-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%d\n",r[i].dni,r[i].edad); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%d",r[i].dni,r[i].edad); //los valores se guardan en el fichero

    free(r);
    fclose(f); //se cierra el fichero
    return (i+1);
}


//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_fichero(registro **reg,int x){ //x es el numero de registros que se han guardado
    printf("\n\nacceso correcto a carga\n\n");
    FILE *f;
    char linea[100];
    *reg=NULL;
    int i=0,j;
    char *token;
    int retorno = 0;

    if((f=fopen("datos.txt","r"))!=NULL){
        printf("\napertura de fichero hecha\n");
        while(fgets(linea,100,f)){
            if((*reg=(registro*)realloc(*reg, (i+1)*sizeof(registro)))!=NULL){
                printf("\nse amplia memoria");
            } else {
                // Manejar el error de realloc aquí
                printf("Error al realocar memoria\n");
                return -1;
            }
            printf("\n%i linea",i+1);
            token=strtok(linea, "-");
            strcpy((*reg)[i].dni,token);

            token=strtok(NULL,"\n");//último de la linea \n
            (*reg)[i].edad=atoi(token);
            printf("\n\ndni [%s] edad [%d]\n",(*reg)[i].dni,(*reg)[i].edad);
            i++;
        }
        printf ("Se ha leido el fichero con %d registros \n",i);
        for(j=0;j<i;j++){
            printf("dni [%s] edad [%d]\n",(*reg)[j].dni,(*reg)[j].edad);
        }
        fclose(f);
    } else {
        // Manejar el error de fopen aquí
        printf("Error al abrir el fichero\n");
        return -1;
    }
    return i;
}


int ModificaDatos(registro *reg){
    int i,aux;
    char posicion[10],camb[10];

    printf("Introduce el DNI que quiere modificar: ");
    scanf("%s",posicion);

    eliminar_salto(posicion,10);

    for(i=0;i<N;i++){
        if(strcmp(reg[i].dni,posicion)==0){
            aux=i;
            printf("\nEl dni auxiliar [%s] y el almacenado [%s] son iguales\n",posicion,reg[i].dni);
            strcpy(reg[i].dni,posicion);

            printf("\nEl dni almacenado en registro es %s",reg[i].dni);
            printf("\nIntroduce ahora el nuevo dni a almacenar: ");
            scanf("%s",camb);

            strcpy(reg[i].dni,camb);
        }
        guarda_fichero(reg,0,0);
    }
    return aux;
}


void intro_datos(registro *r,int x,char *c){
    int i;
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


//cabecera:void eliminar_salto(char *v_n,int n)
//precondicion: inicializada una cadena pasada como parametro
//postcondicion: devuelve la cadena solicitada sin caracter salto de line
void eliminar_salto(char *v_n,int n){ //n es el numero de caracteres de la cadena
    int i;

    for(i=0;i<=n;i++){
        if(v_n[i]=='\n') {
        	v_n[i]='\0';
        	printf("\nSe ha sustituido con exito\n");
        	break;
		}
    }
}
