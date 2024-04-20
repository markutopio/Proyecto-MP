#include "cliente.h"
#include "datos.h"


int intro_client(Clientes **cli, int a){
    int i;
    float x;
    char id[8], nom[21], dirr[51], loc[21], prov[21], ema[31], cont[16];

    if((cli=(Clientes **)malloc(a*sizeof(Clientes)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        fflush(stdin);
        for(i=0;i<a;i++){
        printf("\nIntroduce tu id: ");
        scanf("%s",id);
        eliminar_salto(id,8);
        strcpy((*cli)[i].Id_cliente, id);
        fflush(stdin);

        printf("Introduce tu nombre\n");
        fgets(nom,21,stdin);
        eliminar_salto(nom, 21);
        strcpy((*cli)[i].Nomb_cliente,nom);
        fflush(stdin);

        printf("Introduce tu direccion\n");
        fgets(dirr,51,stdin);
        eliminar_salto(dirr, 51);
        strcpy((*cli)[i].Dir_cliente,dirr);
        fflush(stdin);

        printf("Introduce tu localidad\n");
        fgets(loc,21,stdin);
        eliminar_salto(loc, 21);
        strcpy((*cli)[i].Localidad,loc);
        fflush(stdin);

        printf("Introduce tu provincia\n");
        fgets(prov,21,stdin);
        eliminar_salto(prov,21);
        strcpy((*cli)[i].Provincia,prov);
        fflush(stdin);

        printf("Introduce tu email\n");
        scanf("%s",ema);
        eliminar_salto(ema,31)
        strcpy((*cli)[i].email,ema)
        fflush(stdin);

        printf("Introduce la contraseña\n");
        scanf("%s",cont);
        strcpy((*cli)[i].Contraseña, cont);
        fflush(stdin);

        printf("\nIntroduce el dinero que tienes: ");
        scanf("%f",&x);
        fflush(stdin);
        (*cli)[i].Cartera=x;
        }
    }
}

int modifica_cliente(Clientes *cli,int x){
    int i,aux,num;
    int encontrado=0;
    char id[8],nom[21],dir[21],loc[21],prov[21],email[31],contra[16];
    float dineros;

    printf("Introduce el nuevo usuario: \n");
    scanf("%s",id);
    eliminar_salto(id,8);

    for(i=0;i<x;i++){
        if(strcmp(cli[i].Id_cliente,id)==0){
            aux=i;
            printf("\nEl id auxiliar [%s] y el almacenado [%s] son iguales\n",cid,cli[aux].Id_cliente);

            do{ //si modifico el nombre del producto tambien deberia modificar la categoria, el gestor y la descripcion ya que un producto al cambiarse debe estar en otra categoria forzosamente
                printf("Introduce la opcion que deseas modificar(1-modificar todo, 2-modificar nombre, 3-modificar direccion, 4-modificar localidad, 5-modificar provincia 6-modificar email 7-modificar contrasenia)");
                scanf("%c",&op);

                switch(op){
                    case 1: //se modifican todos los elementos de ese id excepto el propio id
                        printf("\n\nHas elegido modificar todo(el id se mantendra igual \n");


                        printf("\nIntroduce el nuevo nombre del cliente:\n");
                        fgets(nom,21,stdin)
                        eliminar_salto(nom,21);

                        strcpy(cli[aux].Nomb_cliente,nom);
                        fflush(stdin);

                        printf("Introduce la nueva direccion del cliente: \n");
                        fgets(dir,51,stdin);
                        eliminar_salto(dir,51);

                        strcpy(cli[aux].Dir_cliente,dir);
                        fflush(stdin);

                        printf("Introduce la nueva localidad del cliente: \n");
                        scanf("%s",loc);
                        eliminar_salto(loc,21);

                        strcpy(cli[aux].Localidad,loc);
                        fflush(stdin);

                        printf("Introduce la nueva provincia del cliente: \n");
                        fgets(prov,21,stdin);
                        eliminar_salto(prov,21);
                        strcpy(cli[aux].Localidad,loc);
                        fflush(stdin);

                        printf("Introduce el nuevo email del cliente: \n");
                        scanf("%s",email);
                        eliminar_salto(email,31);

                        strcpy(cli[aux].email,email);
                        fflush(stdin);

                        printf("Introduce la nueva contrasena del usuario: \n");
                        scanf("%s",contra);
                        eliminar_salto(contra,31);
                        strcpy(cli[aux].Contrasena,contra);
                        fflush(stdin);
                        break;

                    case 2:
                        printf("Usted va a cambiar el nombre del usuario, pulse s: \n");
                        scanf("%c",&s);

                        if(s=='s'){
                            printf("\nHas elegido modificar el nombre\n");
                            fflush(stdin);

                            printf("Introduce el nuevo nombre del cliente: ");
                            fgets(nom,21,stdin)
                            eliminar_salto(nom,21);

                            strcpy(cli[aux].Nomb_cliente,nom);
                            fflush(stdin);

                        }
                        break;

                    case 3:
                        printf("\nHas elegido cambiar la direccion del usuario\n");
                        fflush(stdin);

                        printf("Introduce la nueva direccion del cliente: \n");
                        fgets(dir,51,stdin);
                        eliminar_salto(dir,51);

                        strcpy(cli[aux].Dir_cliente,dir);
                        fflush(stdin);
                        break;

                    case 4:
                        printf("\nHas elegido cambiar la localidad del usuario\n");

                        printf("Introduce la nueva localidad del cliente: \n");
                        scanf("%s",loc);
                        eliminar_salto(loc,21);

                        strcpy(cli[aux].Localidad,loc);
                        fflush(stdin);
                        break;

                    case 5:
                        printf("\nHas elegido cambiar la provincia del usuario\n");

                        printf("Introduce la nueva provincia del cliente: \n");
                        fgets(prov,21,stdin);
                        eliminar_salto(prov,21);
                        strcpy(cli[aux].Localidad,loc);
                        fflush(stdin);

                        break;

                    case 6:
                        printf("\nHas elegido cambiar el email del usuario\n");

                        printf("Introduce el nuevo email del cliente: \n");
                        scanf("%s",email);
                        eliminar_salto(email,31);

                        strcpy(cli[aux].email,email);
                        fflush(stdin);

                        break;
                    case 7:
                        printf("Has elegido cambiar la contrasena del usuario\n");

                        printf("Introduce la nueva contrasena del usuario: \n");
                        scanf("%s",contra);
                        eliminar_salto(contra,31);
                        strcpy(cli[aux].Contrasena,contra);
                        fflush(stdin);
                        break;


                    case 0:  return 0;
                    break;
                }

                fflush(stdin);

                printf("Quieres modificar algo mas?(pulse s para si): ");
                scanf("%c",&sino);
            }while(sino=='s');
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

int alta_clientes(Clientes **cli,int x){  //x es el numero de registros que tenemos y si lo aumentamos en 1 podremos a�adir uno extra
    int sto;
    float dineros;
    char id[8], nom[21], dir[51], loc[21], prov[21], email[31], contra[16];

    x++;

    printf("Hay %i registros despues de aumentar en 1.\n\n",x);

    Clientes *cli=(Productos *)realloc(*cli,x*sizeof(Clientes));

    if (v_productos==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }



    printf("Introduce el nuevo id del cliente: ");
    scanf("%s",id);
    eliminar_salto(id,8);

    strcpy((*cli)[x-1].Id_cliente,id);
    fflush(stdin);


    printf("\nIntroduce el nuevo nombre del cliente:\n");
    fgets(nom,21,stdin)
    eliminar_salto(nom,21);

    strcpy(cli[aux].Nomb_cliente,nom);
    fflush(stdin);

    printf("Introduce la nueva direccion del cliente: \n");
    fgets(dir,51,stdin);
    eliminar_salto(dir,51);

    strcpy(cli[aux].Dir_cliente,dir);
    fflush(stdin);


    printf("Introduce la nueva localidad del cliente: \n");
    scanf("%s",loc);
    eliminar_salto(loc,21);
    strcpy(cli[aux].Localidad,loc);
    fflush(stdin);

    printf("Introduce la nueva provincia del cliente: \n");
    fgets(prov,21,stdin);
    eliminar_salto(prov,21);
    strcpy(cli[aux].Localidad,loc);
    fflush(stdin);

    printf("Introduce el nuevo email del cliente: \n");
    scanf("%s",email);
    eliminar_salto(email,31);

    strcpy(cli[aux].email,email);
    fflush(stdin);

    printf("Introduce la nueva contrasena del usuario: \n");
    scanf("%s",contra);
    eliminar_salto(contra,31);
    strcpy(cli[aux].Contrasena,contra);
    fflush(stdin);

    return x;
}

int baja_clientes(Clientes **cli,int x){
    int i,aux;
    char id[8];
    int encontrado=0;


    printf("Introduce el id del cliente que quieras eliminar: \n");
    scanf("%s",id);
    eliminar_salto(id,8);


    for(i=0;i<x;i++){
        printf("\nSe accede al bucle");
        if((strcmp((*cli)[i].Id_cliente,id))==0){
            printf("\nSe ha encontrado el elemento %s",cadena);
            aux=i;
            encontrado=1;
            break;
        }
    }

    if(encontrado==1){
        do{
            strcpy((*pro)[aux].Id_cliente,(*pro)[aux+1].Id_cliente);
            strcpy((*pro)[aux].Nomb_cliente,(*pro)[aux+1].Nomb_cliente);
            strcpy((*pro)[aux].Dir_cliente,(*pro)[aux+1].Dir_cliente);
            strcpy((*pro)[aux].Localidad,(*pro)[aux+1].Localidad);
            strcpy((*pro)[aux].Provincia,(*pro)[aux+1].Provincia);
            strcpy((*pro)[aux].email,(*pro)[aux+1].email);
            strcpy((*pro)[aux].Contrasena,(*pro)[aux+1].Contrasena);
            aux++;
        }while(aux<x);
    }else{
        return -1;
    }

    Clientes *nuevo_reg=(Clientes *)realloc(*pro,(x-1) *sizeof(Clientes)); //elimina una posicion del vector que en este caso sera la ultima

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }

    *cli=nuevo_reg;

    return x-1;
}

void listado_cliente(Clientes *cli,int x){
    int i;

    printf("\nLos registros almacenados son: ");
    for(i=0;i<x;i++){
        printf("\nPosicion %i del vector de estructuras: [%s]-[%s]-[%s]-[%s]-[%s]-[%s]-[%s]-[%f]",i+1,cli[i].Id_cliente,cli[i].Nomb_cliente,cli[i].Dir_cliente,cli[i].Id_categ,pro[i].Id_gestor,pro[i].stock,pro[i].entrega,pro[i].importe);
    }
}

int busqueda_productos(Productos *pro,int a){
    int i,n=0; //hacer condicional de si no se encuentra el valor se devuelve NULL por lo que no existiria el elemento
    char produc[16];

    printf("Introduce el producto que quieres encontrar(mete el nombre exacto sin usar mayusculas): ");
    scanf("%s",produc);

    for(i=0;i<a;i++){
        if(strcmp(pro[i].nomb_prod,produc)==0){
            printf("Se ha encontrado el producto %s en la posicion %i",produc,i);
            n=i;
        }
        break;
    }
    return n;
}


















void anadir_din(Clientes *r){
float x;
printf("Cuanto dinero desea agregar a la cartera?\n");
scanf("%f",&x);
r.Cartera=r.Cartera+x;
printf("Ahora mismo dispone de %f",r->Cartera);

}

void eliminar_din(Clientes *r){
float x;
printf("Cuanto dinero desea retirar de su cartera\n");
scanf("%f",&x);
r.Cartera= r.Cartera-x;
printf("Ahora mismo dispone de %f",r.Cartera);
}

int login(Clientes *usuar,int tam,int *pos, Adminprov *rusuar){
    int i=0,encontrado=0;
    char user[5],password[9];
    //Pedimos un usuario y una contraseña
    printf("\nEscribe su usuario: ");
    fflush(stdin);
    gets(user);
    printf("\nEscribe su contraseña: ");
    fflush(stdin);
    gets(password);
    //Recorremos el vector, viendo si ese usuario y esa contraseña coinciden
    while(i<=tam&&encontrado==0){
        if(strcmp(usuar[i].Id_cliente,user)==0)
            if(strcmp(usuar[i].Contrasena,password)==0)
                if(comprobar_id(usuar[i].Id_cliente)==1){
                    encontrado=1;
                    //Salvaguardamos la posicion dentro del vector para potenciales usos futuros
                    *pos=i;
                    if(strcmp(usuar[(*pos)].Perfil_usuario,"administrador")==0)
                        printf("\n\nBienvenido de nuevo %s (Administrador)",rusuar[(*pos)].Perfil_usuario);
                    else
                        printf("\n\nBienvenido de nuevo %s (Usuario)",usuar[(*pos)].Nomb_cliente);
                }
        i++;
    }
    //Si no se ha encontrado que de un mensaje por pantalla
    if(encontrado==0)
        puts("\n\nUsuario o contraseña no validos, vuelva a intentarlo o cree un nuevo usuario\n\n");
    return encontrado;
}




