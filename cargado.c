#include "cargado.h"


//cabecera: int carga_clientes(Clientes **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_clientes(Clientes **reg,int x)  //x es el numero de registros que se han guardado
{
    FILE *f;
    char linea[200];
    *reg=NULL;
    int i=0,j;
    char *token;

    if((f=fopen("clientes.txt","r"))!=NULL)
    {
        while(fgets(linea,200,f))
        {
            Clientes *nuevo_reg=(Clientes *)realloc(*reg,(i+1)*sizeof(Clientes));

            if (nuevo_reg==NULL)
            {
                printf("\nError al realocar memoria\n");
                fclose(f); // Cerramos el archivo antes de salir
                return -1;
            }
            *reg=nuevo_reg;
            token=strtok(linea,"-");
            strcpy((*reg)[i].Id_cliente,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].Nomb_cliente,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].Dir_cliente,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].Localidad,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].Provincia,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].email,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].Contrasena,token);


            token=strtok(NULL,"\n");
            (*reg)[i].Cartera=atof(token);

            i++;
        }
    }
    printf ("Se ha leido el fichero clientes.txt con %d registros \n",i);
    for(j=0; j<i; j++)
    {
        printf("\nId cliente [%s] Nombre cliente[%s] Direccion cliente[%s] Localidad[%s] Provincia[%s] email[%s] Contrasena[%s] Cartera[%.2f] \n",(*reg)[j].Id_cliente,(*reg)[j].Nomb_cliente,(*reg)[j].Dir_cliente,(*reg)[j].Localidad,(*reg)[j].Provincia,(*reg)[j].email,(*reg)[j].Contrasena,(*reg)[j].Cartera);
    }
    fclose(f);
    return i;
}

//cabecera: int carga_fichero(Adminprov **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_adminprov(Adminprov **reg,int x)  //x es el numero de registros que se han guardado
{
    FILE *f;
    char linea[110];
    *reg=NULL;
    int i=0,j;
    char *token;

    if((f=fopen("admin.txt","r"))!=NULL)
    {
        while(fgets(linea,110,f))
        {
            Adminprov *nuevo_reg=(Adminprov *)realloc(*reg,(i+1)*sizeof(Adminprov));

            if (nuevo_reg==NULL)
            {
                printf("\nError al realocar memoria\n");
                fclose(f); // Cerramos el archivo antes de salir
                return -1;
            }
            *reg=nuevo_reg;
            token=strtok(linea, "-");
            strcpy((*reg)[i].Id_empresa,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].Nombre_empre,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].email,token);


            token=strtok(NULL, "-");
            strcpy((*reg)[i].Contrasena,token);


            token=strtok(NULL,"\n");
            strcpy((*reg)[i].Perfil_usuario,token);

            i++;
        }
    }
    printf ("Se ha leido el fichero admin.txt con %d registros \n",i);
    for(j=0; j<i; j++)
    {
        printf("\nId empresa [%s] Nombre empresa[%s] email[%s] Contrasena[%s] Perfil_usuario[%s] \n",(*reg)[j].Id_empresa,(*reg)[j].Nombre_empre,(*reg)[j].email,(*reg)[j].Contrasena,(*reg)[j].Perfil_usuario);
    }
    fclose(f);
    return i;
}

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_prod(Productos **reg,int x)  //x es el numero de registros que se han guardado
    {
        FILE *f;
        char linea[130];
        *reg=NULL;
        int i=0,j;
        char *token;

        if((f=fopen("productos.txt","r"))!=NULL)
        {
            while(fgets(linea,130,f))
            {
                Productos *nuevo_reg=(Productos *)realloc(*reg,(i+1)*sizeof(Productos));

                if (nuevo_reg==NULL)
                {
                    printf("\nError al realocar memoria\n");
                    fclose(f); // Cerramos el archivo antes de salir
                    return -1;
                }
                *reg = nuevo_reg;
                token=strtok(linea,"-");
                strcpy((*reg)[i].Id_prod,token);


                token=strtok(NULL,"-");
                strcpy((*reg)[i].nomb_prod,token);


                token=strtok(NULL,"-");
                strcpy((*reg)[i].Descrip,token);


                token=strtok(NULL,"-");
                strcpy((*reg)[i].Id_categ,token);


                token=strtok(NULL,"-");
                strcpy((*reg)[i].Id_gestor,token);


                token=strtok(NULL,"-");
                (*reg)[i].stock=atoi(token);


                token=strtok(NULL,"-");
                (*reg)[i].entrega=atoi(token);


                token=strtok(NULL,"\n");
                (*reg)[i].importe=atof(token);

                i++;
            }
        }
        printf ("Se ha leido el fichero productos.txt con %d registros \n",i);
        for(j=0; j<i; j++)
        {
            printf("\nId producto [%s] Nombre producto[%s] Descripcion[%s] Id categoria[%s] Id gestor[%s] stock[%i] entrega[%i] importe[%.2f] \n",(*reg)[j].Id_prod,(*reg)[j].nomb_prod,(*reg)[j].Descrip,(*reg)[j].Id_categ,(*reg)[j].Id_gestor,(*reg)[j].stock,(*reg)[j].entrega,(*reg)[j].importe);
        }
        fclose(f);
        return i;
    }

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_cat(Categorias **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[80];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("categorias.txt","r"))!=NULL)
            {
                while(fgets(linea,80,f))
                {
                    Categorias *nuevo_reg=(Categorias *)realloc(*reg,(i+1)*sizeof(Categorias));

                    if (nuevo_reg == NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg=nuevo_reg;
                    token=strtok(linea, "-");
                    strcpy((*reg)[i].Id_categ,token);


                    token=strtok(NULL,"\n");
                    strcpy((*reg)[i].Descrip,token);

                    i++;
                }
            }
            printf ("Se ha leido el fichero con categorias.txt %d con registros \n",i);
            for(j=0; j<i; j++)
            {
                printf("\nId categoria [%s] Descripcion[%s] \n",(*reg)[j].Id_categ,(*reg)[j].Descrip);
            }
            fclose(f);
            return i;
        }

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_desc(Descuentos **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[90];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("descuentos.txt","r"))!=NULL)
            {
                while(fgets(linea,90,f))
                {
                    Descuentos *nuevo_reg=(Descuentos *)realloc(*reg,(i+1)*sizeof(Descuentos));

                    if (nuevo_reg==NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg=nuevo_reg;
                    token=strtok(linea,"-");
                    strcpy((*reg)[i].Id_cod,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Descrip,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Tipo_des,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Estado_act,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Aplicable,token);


                    token=strtok(NULL,"\n");
                    (*reg)[i].Importe=atof(token);

                    i++;
                }
            }

            printf ("Se ha leido el fichero descuentos.txt con %d registros \n",i);
            for(j=0; j<i; j++)
            {
                printf("\nId cod[%s] Descrip[%s] Tipo_des[%s] Estado_act[%s] Importe[%.2f] Aplicable[%s] \n",(*reg)[j].Id_cod,(*reg)[j].Descrip,(*reg)[j].Tipo_des,(*reg)[j].Estado_act,(*reg)[j].Importe,(*reg)[j].Aplicable); //Preguntar esta parte
            }
            fclose(f);
            return i;
        }

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_descclient(Descuentosclientes **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[50];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("descuentosclientes.txt","r"))!=NULL)
            {
                while(fgets(linea,50,f))
                {
                    Descuentosclientes *nuevo_reg=(Descuentosclientes *)realloc(*reg,(i+1)*sizeof(Descuentosclientes));

                    if (nuevo_reg == NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg = nuevo_reg;
                    token=strtok(linea, "-");
                    strcpy((*reg)[i].Id_cliente,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Id_cod,token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_asig.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_asig.mes=atoi(token);
                    token=strtok(NULL,"-");
                    (*reg)[i].fecha_asig.anio=atoi(token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_cadu.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_cadu.mes=atoi(token);
                    token=strtok(NULL,"-");
                    (*reg)[i].fecha_cadu.anio=atoi(token);


                    token=strtok(NULL,"\n");
                    (*reg)[i].Estado_apli=atoi(token);

                    i++;
                }
            }

            printf ("Se ha leido el fichero descuentosclientes.txt con %d registros \n",i);
            for(j=0; j<i; j++)
            {
               printf("\n nId_cliente[%s] Id_cod[%s] fecha_asig[%i/%i/%i] fecha_cadu[%i/%i/%i] Estado_apli[%i] \n",(*reg)[i].Id_cliente,(*reg)[i].Id_cod,(*reg)[i].fecha_asig.dia,(*reg)[i].fecha_asig.mes,(*reg)[i].fecha_asig.anio,(*reg)[i].fecha_cadu.dia,(*reg)[i].fecha_cadu.mes,(*reg)[i].fecha_cadu.anio,(*reg)[i].Estado_apli);
            }
            fclose(f);
            return i;

        }

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_lockers(Lockers **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[100];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("lockers.txt","r"))!=NULL)
            {
                while(fgets(linea,100,f))
                {
                    Lockers *nuevo_reg=(Lockers *)realloc(*reg,(i+1)*sizeof(Lockers));

                    if (nuevo_reg==NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg=nuevo_reg;
                    token=strtok(linea, "-");
                    strcpy((*reg)[i].Id_locker,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Localidad,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Provincia,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Ubica,token);


                    token=strtok(NULL,"-");
                    (*reg)[i].Num_compT=atoi(token);


                    token=strtok(NULL,"-");
                    (*reg)[i].Num_compOcup=atoi(token);

                    i++;
                }
            }

            printf ("Se ha leido el fichero lockers.txt con %d registros \n",i);
            for(j=0; j<i; j++)
            {
               printf("\nId locker[%s] Localidad[%s] Provincia[%s] Ubicacion[%s] Num_compT[%i]  Num_compOcup[%i]\n",(*reg)[i].Id_locker,(*reg)[i].Localidad,(*reg)[i].Provincia,(*reg)[i].Ubica,(*reg)[i].Num_compT,(*reg)[i].Num_compOcup);
            }
            fclose(f);
            return i;
        }

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_compartlockers(Compartimentoslockers **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[65];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("compartimentoslockers.txt","r"))!=NULL)
            {
                while(fgets(linea,65,f))
                {
                    Compartimentoslockers *nuevo_reg=(Compartimentoslockers *)realloc(*reg,(i+1)*sizeof(Compartimentoslockers));

                    if (nuevo_reg==NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg = nuevo_reg;
                    token=strtok(linea, "-");
                    strcpy((*reg)[i].Id_locker,token);


                    token=strtok(NULL,"-");
                    (*reg)[i].Num_comp=atoi(token);


                    token=strtok(linea, "-");
                    (*reg)[i].Cod_locker=atoi(token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Estado,token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_ocupa.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_ocupa.mes=atoi(token);
                    token=strtok(NULL,"-");
                    (*reg)[i].fecha_ocupa.anio=atoi(token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_caduci.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_caduci.mes=atoi(token);
                    token=strtok(NULL,"\n");
                    (*reg)[i].fecha_caduci.anio=atoi(token);

                    i++;
                }
            }
            printf ("Se ha leido el fichero compartimentoslockers.txt con %d registros \n",i);
            for(j=0; j<i; j++)
            {
               printf("\nId_locker[%s] Num_comp[%i] Cod_locker[%i] Estado[%s] fecha_ocupa[%i/%i/%i] fecha_caduci[%i/%i/%i]\n",(*reg)[i].Id_locker,(*reg)[i].Num_comp,(*reg)[i].Cod_locker,(*reg)[i].Estado,(*reg)[i].fecha_ocupa.dia,(*reg)[i].fecha_ocupa.mes,(*reg)[i].fecha_ocupa.anio,(*reg)[i].fecha_caduci.dia,(*reg)[i].fecha_caduci.mes,(*reg)[i].fecha_caduci.anio);
            }
            fclose(f);
            return i;
        }

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_ped(Pedidos **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[65];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("pedidos.txt","r"))!=NULL)
            {
                while(fgets(linea,65,f))
                {
                    Pedidos *nuevo_reg=(Pedidos *)realloc(*reg,(i+1)*sizeof(Pedidos));

                    if (nuevo_reg==NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg=nuevo_reg;
                    token=strtok(linea, "-");
                    strcpy((*reg)[i].Id_pedido,token);

                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_pedi.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_pedi.mes=atoi(token);
                    token=strtok(NULL,"-");
                    (*reg)[i].fecha_pedi.anio=atoi(token);


                    token=strtok(linea, "-");
                    strcpy((*reg)[i].Id_cliente,token);


                    token=strtok(linea,"-");
                    strcpy((*reg)[i].Lugar,token);


                    token=strtok(linea, "-");
                    strcpy((*reg)[i].Id_locker,token);


                    token=strtok(linea, "\n");
                    strcpy((*reg)[i].Id_cod,token);

                    i++;
                }
            }

            printf ("Se ha leido el fichero pedidos.txt con %d registros \n",i);
            for(j=0; j<i; j++)
            {
               printf("\nId_pedido[%s] fecha_pedi[%i/%i/%i] Id_cliente[%s] Lugar[%s] Id_cod[%s]\n",(*reg)[i].Id_pedido,(*reg)[i].fecha_pedi.dia,(*reg)[i].fecha_pedi.mes,(*reg)[i].fecha_pedi.anio,(*reg)[i].Id_cliente,(*reg)[i].Lugar,(*reg)[i].Id_cod);
            }
            fclose(f);
            return i;

        }

//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_pedprod(Productospedidos **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[100];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("productospedidos.txt","r"))!=NULL)
            {
                while(fgets(linea,100,f))
                {
                    Productospedidos *nuevo_reg=(Productospedidos *)realloc(*reg,(i+1)*sizeof(Productospedidos));

                    if (nuevo_reg==NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg = nuevo_reg;
                    token=strtok(linea,"-");
                    strcpy((*reg)[i].Id_pedido,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Id_prod,token);


                    token=strtok(NULL,"-");
                    (*reg)[i].Num_unid=atoi(token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_entre.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_entre.mes=atoi(token);
                    token=strtok(NULL,"-");
                    (*reg)[i].fecha_entre.anio=atoi(token);


                    token=strtok(NULL,"-");
                    (*reg)[i].Importe=atof(token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Estado_ped,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Id_transp,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Id_locker,token);


                    token=strtok(NULL,"-");
                    (*reg)[i].Cod_locker=atoi(token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_entre_devo.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_entre_devo.mes=atoi(token);
                    token=strtok(NULL,"\n");
                    (*reg)[i].fecha_entre_devo.anio=atoi(token);

                    i++;
                }
            }

            printf ("Se ha leido el fichero productospedidos.txt con %d registros \n",i);
            for(j=0; j<i; j++)
            {
               printf("\nId_pedido[%s] Id_prod[%s] Num_unid[%i] fecha_entre[%i/%i/%i] Importe[%.2f] Estado_ped[%s] Id_transp[%s] Id_locker[%s] Cod_locker[%i] fecha_entre_devo[%i/%i/%i]\n",(*reg)[i].Id_pedido,(*reg)[i].Id_prod,(*reg)[i].Num_unid,(*reg)[i].fecha_entre.dia,(*reg)[i].fecha_entre.mes,(*reg)[i].fecha_entre.anio,(*reg)[i].Importe,(*reg)[i].Estado_ped,(*reg)[i].Id_transp,(*reg)[i].Id_locker,(*reg)[i].Cod_locker,(*reg)[i].fecha_entre_devo.dia,(*reg)[i].fecha_entre_devo.mes,(*reg)[i].fecha_entre_devo.anio);
            }
            fclose(f);
            return i;

        }


//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_transp(Transportistas **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[130];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("transportistas.txt","r"))!=NULL)
            {
                while(fgets(linea,130,f))
                {
                    Transportistas *nuevo_reg=(Transportistas *)realloc(*reg,(i+1)*sizeof(Transportistas));

                    if (nuevo_reg==NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg=nuevo_reg;
                    token=strtok(linea,"-");
                    strcpy((*reg)[i].Id_transp,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Nombre_transp,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].email,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].contrasena,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Nombre_empre,token);


                    token=strtok(NULL,"\n");
                    strcpy((*reg)[i].ciudad_repar,token);

                    i++;
                }
            }
            printf ("Se ha leido el fichero transportistas.txt con %d registros \n",i);
            for(j=0; j<i; j++)
            {
               printf("\nId_transp[%s] Nombre_transp[%s] email[%s] contrasena[%s] Nombre_empre[%s] ciudad_repar[%s]\n",(*reg)[i].Id_transp,(*reg)[i].Nombre_transp,(*reg)[i].email,(*reg)[i].contrasena,(*reg)[i].Nombre_empre,(*reg)[i].ciudad_repar);
            }
            fclose(f);
            return i;
        }


//cabecera: int carga_fichero(registro **reg,int x)
//precondicion: inicializado el fichero que almacena los datos
//postcondicion: devuelve los valores almacenados en el vector de registros
int carga_devo(Devoluciones **reg,int x)  //x es el numero de registros que se han guardado
        {
            FILE *f;
            char linea[130];
            *reg=NULL;
            int i=0,j;
            char *token;

            if((f=fopen("devoluciones.txt","r"))!=NULL)
            {
                while(fgets(linea,130,f))
                {
                    Devoluciones *nuevo_reg = (Devoluciones *)realloc(*reg, (i+1) * sizeof(Devoluciones));

                    if (nuevo_reg==NULL)
                    {
                        printf("\nError al realocar memoria\n");
                        fclose(f); // Cerramos el archivo antes de salir
                        return -1;
                    }
                    *reg=nuevo_reg;
                    token=strtok(linea,"-");
                    strcpy((*reg)[i].Id_pedido,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Id_prod,token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_devolu.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_devolu.mes=atoi(token);
                    token=strtok(NULL,"-");
                    (*reg)[i].fecha_devolu.anio=atoi(token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].motivo,token);


                    token=strtok(NULL,"-");
                    strcpy((*reg)[i].Estado,token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_acep.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_acep.mes=atoi(token);
                    token=strtok(NULL,"-");
                    (*reg)[i].fecha_acep.anio=atoi(token);


                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_cadu.dia=atoi(token);
                    token=strtok(NULL,"/");
                    (*reg)[i].fecha_cadu.mes=atoi(token);
                    token=strtok(NULL,"\n");
                    (*reg)[i].fecha_cadu.anio=atoi(token);

                     i++;
                }
            }
            printf ("Se ha leido el fichero devoluciones.txt con %d registros \n",i);
            for(j=0; j<i; j++)
            {
               printf("\nId_pedido[%s] Id_prod[%s] fecha_devolu[%i/%i/%i] motivo[%s] Estado[%s] fecha_acep[%i/%i/%i] fecha_cadu[%i/%i/%i]\n",(*reg)[i].Id_pedido,(*reg)[i].Id_prod,(*reg)[i].fecha_devolu.dia,(*reg)[i].fecha_devolu.mes,(*reg)[i].fecha_devolu.anio,(*reg)[i].motivo,(*reg)[i].Estado,(*reg)[i].fecha_acep.dia,(*reg)[i].fecha_acep.mes,(*reg)[i].fecha_acep.anio,(*reg)[i].fecha_cadu.dia,(*reg)[i].fecha_cadu.mes,(*reg)[i].fecha_cadu.anio);
            }
            fclose(f);
            return i;
        }
