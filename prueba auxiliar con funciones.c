#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5

typedef struct{
char dni[10];
char nombre[21];
int edad;
}registro;


void eliminar_salto(char *,int);
int guarda_fichero(registro *, char *,int);
int carga_fichero(registro **,int);
int ConsultaDatos(registro *, int, char *, registro *);
int ModificaDatos(registro *, int, char *, registro *);
int AltaDatos(registro **, int, registro*);
int BajaDatos(registro **, int, char *);


int main(){
    registro *reg;
    int edad,op;
    char dni[10];
    int a,b;

    if((reg=(registro *)malloc(N*sizeof(registro)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        printf("funcionamiento correcto\n\n");

        printf("que quieres hacer(1-guardar datos en un fichero, 2-cargar datos de fichero a estructuras, 3-listar datos,4-modificar datos, 5-alta datos, 6-baja datos)\n\n");
        scanf("%i",&op);

        switch(op){
            case 1: a=guarda_fichero(reg,dni,edad);
                break;
            case 2: b=carga_fichero(&reg,a);
                break;
            default: return 0;
        }

    }
}

int guarda_fichero(registro *r,char *c,int x){
    FILE *f;
    int i;

    f=fopen("datos.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<N;i++){ //N veces para que haya saltos de linea
        printf("\nIntroduce tu dni: ");
        fgets(c,10,stdin);

        fflush(stdin);

        printf("\nEl valor es %s",c);

        eliminar_salto(c,10);


        printf("\nIntroduce tu edad: ");
        scanf("%d",&x);

        fflush(stdin);

        printf("\nEl valor es %d\n",x);


        strcpy(r->dni,c); //pasamos valor auxiliar dni a la estructura
        r->edad=x; //pasamos valor auxiliar edad a la estrutura

        fprintf(f,"%s-%d\n",r->dni,r->edad); //los valores se guardan en el fichero
    }

    fclose(f); //se cierra el fichero
    free(r); //se libera la memoria
    return (i+1);
}


int carga_fichero(registro **reg,int x){ //x es el numero de registros que se han guardado
    printf("\n\nacceso correcto a carga\n\n");
    FILE *f;
    char linea[100];
    *reg=NULL;
    int i=0,j;
    char *token;
    int retorno = 0;

    if(f=fopen("datos.txt","r")){
        printf("\napertura de fichero hecha\n");
    while((fgets(linea,100,f))){
        if((*reg=(registro*)realloc(*reg, (i+1)*sizeof(registro)))!=NULL){
            printf("\nse amplia memoria");
        }
        printf("\n%i linea",i+1);
        //Habria que poner un if para comprobar si hay memoria disponible
        token=strtok(linea, "-");
        strcpy((*(reg+i))->dni,token);


        token=strtok(NULL,"\n");//último de la linea \n
        ((*(reg+i))->edad)=atoi(token);
        printf("\n\ndni [%s] edad [%d]\n",(*(reg+i))->dni,(*(reg+i))->edad);
        //strcpy((*(reg+i))->edad,token);
        i++;
    }
    printf ("Se ha leído el fichero con %d registros \n",i);
    for(j=0;j<i;j++){ printf("dni [%s] edad [%d]\n",(*(reg+i))->dni,(*(reg+i))->edad);}
        fclose(f);
        free(f);
    }
    return i;
}


void eliminar_salto(char *v_n,int n){ //n es el numero de caracteres de la cadena
    int i;

    for(i=0;i<=n;i++){
        if(v_n[i]=='\n') {
        	v_n[i]='\0';
        	printf("\nSe ha sustituido con exito\n");
		}
    }
}
