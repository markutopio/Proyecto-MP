#include "admin.h"
#include "datos.h"

//cabecera: int intro_admin(Adminprov **adm,int a)
//precondicion: adm no es NULL y a es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
int intro_admin(Adminprov **adm, int a){
    int i;
    char id[5], nome[21], mail[31], contra[16], perfil;

    if((adm=(Adminprov **)malloc(a*sizeof(Adminprov)))==NULL){ //se almacena memoria para emplear los registros
        printf("Error");
    }else{
        fflush(stdin);
        for(i=0;i<a;i++){
        printf("\nIntroduce el id de la empresa\n: ");
        scanf("%s",id);
        eliminar_salto(id,5);
        strcpy((*adm)[i].Id_empresa,id);
        fflush(stdin);

        printf("Introduce el nombre de la empresa\n");
        fgets(nome,21,stdin);
        eliminar_salto(nome,21);
        strcpy((*adm)[i].Nombre_empre, nome);
        fflush(stdin);

        printf("Introduce tu email\n");
        scanf("%s",mail);
        eliminar_salto(mail,31);
        strcpy((*adm)[i].email,mail);
        fflush(stdin);

        printf("Introduce tu contraseña\n");
        scanf("%s",contra);
        eliminar_salto(contra,16);
        strcpy((*adm)[i].Contrasena, contra);
        fflush(stdin);

        printf("Introduzca si es usted administrador o proveedor (a/p)\n");
        scanf("%c",perfil);
        (*perfil)[i].Perfil_usuario=perfil;
        fflush(stdin);
        }
    }
}
//cabecera: int modifica_admin(Adminprov *adm,int x)
//precondicion: adm no es NULL y a es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
int modifica_admin(Adminprov *adm,int x){
    int i,aux;
    int encontrado=0;
    char id[5],nom[21],emai[31],contra[16],perfil_usu[14];
    char sino,op,s;

    printf("Introduce el nuevo email: \n");
    scanf("%s",id);
    eliminar_salto(id,8);

    for(i=0;i<x;i++){
        if(strcmp(adm[i].email,emai)==0){
            aux=i;
            printf("\nEl id auxiliar [%s] y el almacenado [%s] son iguales\n",emai,adm[aux].email);

            do{ //si modifico el nombre del producto tambien deberia modificar la categoria, el gestor y la descripcion ya que un producto al cambiarse debe estar en otra categoria forzosamente
                printf("Introduce la opcion que deseas modificar(1-modificar todo, 2-modificar id de la empresa (con precaucion), 3-modificar nombre de la empresa, 4-modificar email, 5-modificar contrasena, 6-modificar perfil usuario)");
                scanf("%c",&op);

                switch(op){
                    case 1: //se modifican todos los elementos de ese id excepto el propio id
                        printf("\n\nHas elegido modificar todo\n");

                        printf("\nIntroduce el nuevo id de la empresa:\n");
                        fgets(id,5,stdin);
                        eliminar_salto(id,5);

                        strcpy(adm[aux].Id_empresa,id);
                        fflush(stdin);

                        printf("Introduce el nuevo nombre de la empresa: \n");
                        fgets(nom,21,stdin);
                        eliminar_salto(nom,21);

                        strcpy(adm[aux].Nombre_empre,nom);
                        fflush(stdin);

                        printf("Introduce el nuevo email: \n");
                        scanf("%s",emai);
                        eliminar_salto(emai,21);

                        strcpy(adm[aux].email,emai);
                        fflush(stdin);

                        printf("Introduce la nueva contrasena: \n");
                        fgets(contra,16,stdin);
                        eliminar_salto(contra,16);
                        strcpy(adm[aux].Contrasena,contra);
                        fflush(stdin);

                        printf("Introduce que tipo de perfil se actualizara ahora: \n");
                        scanf("%s",perfil_usu);
                        eliminar_salto(perfil_usu,14);

                        strcpy(adm[aux].Perfil_usuario,perfil_usu);
                        fflush(stdin);
                    case 2:
                        printf("Usted va a cambiar el id de la empresa, pulse s: \n");
                        scanf("%c",&s);

                        if(s=='s'){
                            printf("\nHas elegido modificar el id\n");
                            fflush(stdin);

                            printf("\nIntroduce el nuevo id de la empresa:\n");
                            fgets(id,5,stdin);
                            eliminar_salto(id,5);

                            strcpy(adm[aux].Id_empresa,id);
                            fflush(stdin);
                        }
                        break;

                    case 3:
                        printf("\nHas elegido cambiar el nombre de la empresa\n");
                        fflush(stdin);


                        printf("Introduce el nuevo nombre de la empresa: \n");
                        fgets(nom,21,stdin);
                        eliminar_salto(nom,21);

                        strcpy(adm[aux].Nombre_empre,dir);
                        fflush(stdin);

                        break;

                    case 4:
                        printf("\nHas elegido cambiar el email\n");

                        printf("Introduce el nuevo email: \n");
                        scanf("%s",emai);
                        eliminar_salto(emai,21);

                        strcpy(adm[aux].email,emai);
                        fflush(stdin);
                        break;

                    case 5:
                        printf("\nHas elegido cambiar la contrasena\n");

                        printf("Introduce la nueva contrasena: \n");
                        fgets(contra,16,stdin);
                        eliminar_salto(contra,16);
                        strcpy(adm[aux].Contrasena,contra);
                        fflush(stdin);

                        break;

                    case 6:
                        printf("\nHas elegido cambiar el email del usuario\n");

                        printf("Introduce que tipo de perfil se actualizara ahora: \n");
                        scanf("%s",perfil_usu);
                        eliminar_salto(perfil_usu,14);

                        strcpy(adm[aux].Perfil_usuario,perfil_usu);
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

//cabecera: int alta_admin(Adminprov *adm,int x)
//precondicion: adm no es NULL y a es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
int alta_admin(Adminprov **adm,int x){  //x es el numero de registros que tenemos y si lo aumentamos en 1 podremos a�adir uno extra
    int aux;
    char id[5],nom[21],emai[31],contra[16],perfil_usu[14];

    x++;

    printf("Hay %i registros despues de aumentar en 1.\n\n",x);

    adm=(Adminprov **)realloc(adm,x*sizeof(Adminprov));

    if (adm==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }

        printf("\nIntroduce el nuevo id de la empresa:\n");
        fgets(id,5,stdin);
        eliminar_salto(id,5);

        strcpy(adm[aux]->Id_empresa,id);
        fflush(stdin);

        printf("Introduce el nuevo nombre de la empresa: \n");
        fgets(nom,21,stdin);
        eliminar_salto(nom,21);

        strcpy(adm[aux]->Nombre_empre,nom);
        fflush(stdin);

        printf("Introduce el nuevo email: \n");
        scanf("%s",emai);
        eliminar_salto(emai,21);

        strcpy(adm[aux]->email,emai);
        fflush(stdin);

        printf("Introduce la nueva contrasena: \n");
        fgets(contra,16,stdin);
        eliminar_salto(contra,16);
        strcpy(adm[aux]->Contrasena,contra);
        fflush(stdin);

        printf("Introduce que tipo de perfil se actualizara ahora: \n");
        scanf("%s",perfil_usu);
        eliminar_salto(perfil_usu,14);

        strcpy(adm[aux]->Perfil_usuario,perfil_usu);
        fflush(stdin);

    return x;
}


//cabecera: int baja_admin(Adminprov **adm,int x)
//precondicion: adm no es NULL y a es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
int baja_admin(Adminprov **adm,int x){
    int i,aux;
    char emai[31];
    int encontrado=0;


    printf("Introduce el id del cliente que quieras eliminar: \n");
    fgets(emai,31,stdin);
    eliminar_salto(emai,31);


    for(i=0;i<x;i++){
        printf("\nSe accede al bucle");
        if((strcmp((*adm)[i].email,emai))==0){
            printf("\nSe ha encontrado el elemento %s",emai);
            aux=i;
            encontrado=1;
            break;
        }
    }

    if(encontrado==1){
        do{
            strcpy((*adm)[aux].Id_empresa,(*adm)[aux+1].Id_empresa);
            strcpy((*adm)[aux].Nombre_empre,(*adm)[aux+1].Nombre_empre);
            strcpy((*adm)[aux].email,(*adm)[aux+1].email);
            strcpy((*adm)[aux].Contrasena,(*adm)[aux+1].Contrasena);
            strcpy((*adm)[aux].Perfil_usuario,(*adm)[aux+1].Perfil_usuario);
            aux++;
        }while(aux<x);
    }else{
        return -1;
    }

    Adminprov *nuevo_reg=(Adminprov *)realloc(*adm,(x-1) *sizeof(Adminprov)); //elimina una posicion del vector que en este caso sera la ultima

    if (nuevo_reg==NULL){
        printf("Error al realocar memoria\n");
        return -1;
    }

    *adm=nuevo_reg;

    return x-1;
}


//cabecera: int listado_admin(Adminprov *adm,int x)
//precondicion: adm no es NULL y a es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
void listado_admin(Adminprov *adm,int x){
    int i;

    printf("\nLos registros almacenados son: ");
    for(i=0;i<x;i++){
        printf("\nPosicion %i del vector de estructuras: [%s]-[%s]-[%s]-[%s]-[%s]",i+1,adm[i].Id_empresa,adm[i].Nombre_empre,adm[i].email,adm[i].Contrasena,adm[i].Perfil_usuario);
    }
}


//cabecera: int busqueda_admin(Adminprov *adm,int a)
//precondicion: adm no es NULL y a es mayor que 0
//postcondicion: almacena los valores correspondientes a cada campo del vector de estructuras
int busqueda_admin(Adminprov *adm,int a){
    int i,n=0; //hacer condicional de si no se encuentra el valor se devuelve NULL por lo que no existiria el elemento
    char ema[31];

    printf("Introduce el correo del admin que quieres encontrar: \n");
    scanf("%s",ema);

    for(i=0;i<a;i++){
        if(strcmp(adm[i].email,ema)==0){
            printf("Se ha encontrado el producto %s en la posicion %i",ema,i);
            n=i;
        }
        break;
    }
    return n;
}
