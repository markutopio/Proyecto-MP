#include "moduloguardar.h"
#include "datos.h"
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de clientes
int guarda_cliente(Clientes *r, int a){
    FILE *f;
    int i;

    f=fopen("clientes.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%s-%s-%s-%f\n",r[i].Id_cliente,r[i].Nomb_cliente,r[i].Dir_cliente,r[i].Localidad,r[i].Provincia,r[i].email,r[i].Contrasena,r[i].Cartera); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%s-%s-%s-%f\n",r[i].Id_cliente,r[i].Nomb_cliente,r[i].Dir_cliente,r[i].Localidad,r[i].Provincia,r[i].email,r[i].Contrasena,r[i].Cartera); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de administrador
int guarda_adminprov(Adminprov *r, int a){
    FILE *f;
    int i;

    f=fopen("admin.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%s\n",r[i].Id_empresa,r[i].Nombre_empre,r[i].email,r[i].Contrasena,r[i].Perfil_usuario); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%s\n",r[i].Id_empresa,r[i].Nombre_empre,r[i].email,r[i].Contrasena,r[i].Perfil_usuario); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}



//cabecera: int guarda_adminprov(registro *r, int a
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de los productos
int guarda_prod(Productos *r, int a){
    FILE *f;
    int i;

    f=fopen("productos.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%s-%d-%d-%f\n",r[i].Id_prod,r[i].nomb_prod,r[i].Descrip,r[i].Id_categ,r[i].Id_gestor[i],r[i].stock,r[i].entrega,r[i].importe); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%s-%d-%d-%f\n",r[i].Id_prod,r[i].nomb_prod,r[i].Descrip,r[i].Id_categ,r[i].Id_gestor[i],r[i].stock,r[i].entrega,r[i].importe); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);

}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de las categorias
int guarda_cat(Categorias *r, int a){
    FILE *f;
    int i;

    f=fopen("categorias.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s\n",r[i].Id_categ,r[i].Descrip); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s\n",r[i].Id_categ,r[i].Descrip); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de los descuentos
int guarda_desc(Descuentos *r, int a){
    FILE *f;
    int i;

    f=fopen("descuentos.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%f-%s\n",r[i].Id_cod,r[i].Descrip,r[i].Tipo_des,r[i].Estado_act,r[i].Importe,r[i].Aplicable); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%f-%s\n",r[i].Id_cod,r[i].Descrip,r[i].Tipo_des,r[i].Estado_act,r[i].Importe,r[i].Aplicable); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de los descuentos de cliente
int guarda_descclient(Descuentosclientes *r, int a){
    FILE *f;
    int i;

    f=fopen("descuentosclientes.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%d\n",r[i].Id_cliente,r[i].Id_cod,r[i].fecha_asig,r[i].fecha_cadu); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%d\n",r[i].Id_cliente,r[i].Id_cod,r[i].fecha_asig,r[i].fecha_cadu); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);

}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de los lockers
int guarda_lockers(Lockers *r, int a){
    FILE *f;
    int i;

    f=fopen("lockers.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%d-%d\n",r[i].Id_locker,r[i].Localidad,r[i].Provincia,r[i].Ubica,r[i].Num_compT,r[i].Num_compOcup); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%d-%d\n",r[i].Id_locker,r[i].Localidad,r[i].Provincia,r[i].Ubica,r[i].Num_compT,r[i].Num_compOcup); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de los compartimentos de los lockers
int guarda_compartlockers(Compartimentoslockers *r, int a){
    FILE *f;
    int i;

    f=fopen("compartimentoslockers.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%d-%d-%s-%s-%s\n",r[i].Id_locker,r[i].Num_comp,r[i].Cod_locker,r[i].Estado,r[i].fecha_ocupa,r[i].fecha_caduci); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%d-%d-%s-%s-%s\n",r[i].Id_locker,r[i].Num_comp,r[i].Cod_locker,r[i].Estado,r[i].fecha_ocupa,r[i].fecha_caduci); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de los pedidos
int guarda_ped(Pedidos *r, int a){
    FILE *f;
    int i;

    f=fopen("pedidos.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%s-%s\n",r[i].Id_pedido,r[i].fecha_pedi,r[i].Id_cliente,r[i].Lugar,r[i].Lugar,r[i].Id_locker,r[i].Id_cod); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%s-%s\n",r[i].Id_pedido,r[i].fecha_pedi,r[i].Id_cliente,r[i].Lugar,r[i].Lugar,r[i].Id_locker,r[i].Id_cod); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de los productos pedidos
int guarda_pedprod(Productospedidos *r, int a){
    FILE *f;
    int i;

    f=fopen("productospedidos.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%d-%s-%f-%s-%s-%s-%d-%s\n",r[i].Id_pedido,r[i].Id_prod,r[i].Num_unid,r[i].fecha_entre,r[i].Importe,r[i].Estado_ped,r[i].Id_transp,r[i].Id_locker,r[i].Cod_locker,r[i].fecha_entre_devo); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%d-%s-%f-%s-%s-%s-%d-%s\n",r[i].Id_pedido,r[i].Id_prod,r[i].Num_unid,r[i].fecha_entre,r[i].Importe,r[i].Estado_ped,r[i].Id_transp,r[i].Id_locker,r[i].Cod_locker,r[i].fecha_entre_devo); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de los transportistas
int guarda_transp(Transportistas *r, int a){
    FILE *f;
    int i;

    f=fopen("transportistas.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%s-%s\n",r[i].Id_transp,r[i].Nombre_transp,r[i].email,r[i].contrasena,r[i].Nombre_empre,r[i].ciudad_repar); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%s-%s\n",r[i].Id_transp,r[i].Nombre_transp,r[i].email,r[i].contrasena,r[i].Nombre_empre,r[i].ciudad_repar); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
//cabecera: int guarda_adminprov(registro *r, int a)
//precondicion: se debe de iniciar el fichero para guardar los datos (puede dar error al hacer el fopen por memoria)
//postcondicion: almacena en dicho fichero los valores de las devoluciones
int guarda_devo(Devoluciones *r, int a){
    FILE *f;
    int i;

    f=fopen("devoluciones.txt","w"); //apertura de fichero
    fflush(stdin);
    for(i=0;i<a-1;i++){ //N veces para que haya saltos de linea
        fprintf(f,"%s-%s-%s-%s-%s-%s-%s\n",r[i].Id_pedido,r[i].Id_prod,r[i].fecha_devolu,r[i].motivo,r[i].Estado,r[i].fecha_acep,r[i].fecha_cadu); //los valores se guardan en el fichero
    }
    fprintf(f,"%s-%s-%s-%s-%s-%s-%s\n",r[i].Id_pedido,r[i].Id_prod,r[i].fecha_devolu,r[i].motivo,r[i].Estado,r[i].fecha_acep,r[i].fecha_cadu); //los valores se guardan en el fichero

    fclose(f); //se cierra el fichero
    return (a);
}
