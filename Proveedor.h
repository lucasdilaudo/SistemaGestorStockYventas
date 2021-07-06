#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

///METODOS CLASE

Proveedor::Proveedor(){
    strcpy(cod_prov,"aaaa");
}


bool Proveedor::leerDeDisco(int pos){
    FILE *p;
    p=fopen("Proveedores.dat","rb");
    if(p==NULL){
        cout<<"Error al leer archivo PROVEEDORES - funcion: leerDeDisco."<<endl;
        exit(1);
    }
    fseek(p,sizeof*this*pos,0);
    bool siNo=fread(this,sizeof*this,1,p);
    fclose(p);
    return siNo;
}


bool Proveedor::guardarEnDisco(){
    FILE *p;
    p=fopen("Proveedores.dat","ab");
    if(p==NULL){
        cout<<"Error al abrir archivo PROVEEDORES - funcion: guardarEnDisco."<<endl;
        exit(1);
    }
    bool siNo=fwrite(this,sizeof*this,1,p);
    fclose(p);
    return siNo;
}


bool Proveedor::guardarEnDisco(int pos){
    FILE *p;
    p=fopen("Proveedores.dat","rb+");
    if(p==NULL){
        cout<<"Error al abrir archivo PROVEEDORES - funcion: guardarEnDisco(posicion)."<<endl;
        exit(1);
    }
    fseek(p,sizeof*this*pos,0);
    bool siNo=fwrite(this,sizeof*this,1,p);
    fclose(p);
    return siNo;
}


bool Proveedor::cargarProveedor(){
    char nom[20],apellido[20],telefono[10],nomEmp[40];
    int existe,xLetrero=120,yLetrero=9,tamLet=25;
    char op;
    bool continuar;

    do{
        continuar=true;
        borrar(12,9,35);
        gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PROVEEDOR.";
        borrar(xLetrero,yLetrero,20);
        borrar(5,15,5);
        gotoxy(5,15);cargarCadena(cod_prov,10);
        existe=buscarPosProveedor(cod_prov);
        if(cod_prov[0]=='\0'){
            continuar=false;
            letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
            pausa();
       }else if(existe>-1){
           continuar=false;
           letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CODIGO EXISTENTE");
           pausa();
       }
        if(continuar==false){
          do{
            borrar(xLetrero,yLetrero,22);
            borrar(12,9,34);
            borrar(60,8,30);
            borrar(65,10,25);
            letreroInfo(60,8,cAZUL,cGRIS_CLARO,"1 - REINTENTAR   2 - VOLVER");
            gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;
            if(op=='2'){
               return false;
            }else if(op=='1'){
                borrar(60,8,30);
                borrar(65,10,25);
            }else{
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
            }
         }while(op>'2');
      }
    }while(continuar==false);

    do{
        continuar=true;
        borrar(12,9,35);
        borrar(xLetrero,yLetrero,25);
        gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PROVEEDOR.";
        borrar(19,15,20);
        gotoxy(19,15);cargarCadena(nom,20);
        if(nom[0]=='\0'){
            continuar=false;
            letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
            pausa();
        }else{
            setNombre(nom);
        }
        if(continuar==false){
          do{
            borrar(xLetrero,yLetrero,22);
            borrar(12,9,34);
            borrar(60,8,30);
            borrar(65,10,25);
            letreroInfo(60,8,cAZUL,cGRIS_CLARO,"1 - REINTENTAR   2 - VOLVER");
            gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;
            if(op=='2'){
               return false;
            }
            else if(op=='1'){
                borrar(60,8,30);
                borrar(65,10,25);
            }else{
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
            }
         }while(op>'2');
      }
    }while(continuar==false);

    do{
        continuar=true;
        borrar(12,9,35);
        gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PROVEEDOR.";
        borrar(xLetrero,yLetrero,tamLet);
        borrar(45,15,20);
        gotoxy(45,15);cargarCadena(apellido,20);
        if(apellido[0]=='\0'){
            continuar=false;
            letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
            pausa();
        }else{
            setApellido(apellido);
        }
        if(continuar==false){
          do{
            borrar(xLetrero,yLetrero,22);
            borrar(12,9,34);
            borrar(60,8,30);
            borrar(65,10,25);
            letreroInfo(60,8,cAZUL,cGRIS_CLARO,"1 - REINTENTAR   2 - VOLVER");
            gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;
            if(op=='2'){
               return false;
            }
            else if(op=='1'){
                borrar(60,8,30);
                borrar(65,10,25);
            }else{
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
            }
         }while(op>'2');
      }
    }while(continuar==false);

    do{
       continuar=true;
       borrar(12,9,35);
       gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PROVEEDOR.";
       borrar(xLetrero,yLetrero,tamLet);
       borrar(67,15,11);
       gotoxy(67,15);cargarCadena(telefono,10);
       if(telefono[0]=='\0'){
            continuar=false;
            letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
            pausa();
       }else{
          setTelefono(telefono);
       }
       if(continuar==false){
          do{
            borrar(xLetrero,yLetrero,22);
            borrar(12,9,34);
            borrar(60,8,30);
            borrar(65,10,25);
            letreroInfo(60,8,cAZUL,cGRIS_CLARO,"1 - REINTENTAR   2 - VOLVER");
            gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;
            if(op=='2'){
               return false;
            }
            else if(op=='1'){
                borrar(60,8,30);
                borrar(65,10,25);
            }else{
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
            }
         }while(op>'2');
      }
    }while(telefono[0]=='\0');

    do{
       continuar=true;
       borrar(12,9,35);
       gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PROVEEDOR.";
       borrar(xLetrero,yLetrero,tamLet);
       borrar(82,15,23);
       gotoxy(82,15);cargarCadena(nomEmp,40);
       if(nomEmp[0]=='\0'){
            continuar=false;
            letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
            pausa();
       }else{
          setNomEmpresa(nomEmp);
       }
       if(continuar==false){
          do{
            borrar(xLetrero,yLetrero,22);
            borrar(12,9,34);
            borrar(60,8,30);
            borrar(65,10,25);
            letreroInfo(60,8,cAZUL,cGRIS_CLARO,"1 - REINTENTAR   2 - VOLVER");
            gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;
            if(op=='2'){
               return false;
            }
            else if(op=='1'){
                borrar(60,8,30);
                borrar(65,10,25);
            }else{
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
            }
         }while(op>'2');
      }
    }while(nomEmp[0]=='\0');

    do{
       continuar=true;
       borrar(12,9,35);
       gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PROVEEDOR.";
       borrar(xLetrero,yLetrero,tamLet);
       borrar(107,15,39);
       gotoxy(107,15);cargarCadena(email,50);
       if(email[0]=='\0'){
            continuar=false;
            letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
            pausa();
       }
       if(continuar==false){
          do{
            borrar(xLetrero,yLetrero,22);
            borrar(12,9,34);
            borrar(60,8,30);
            borrar(65,10,25);
            letreroInfo(60,8,cAZUL,cGRIS_CLARO,"1 - REINTENTAR   2 - VOLVER");
            gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;
            if(op=='2'){
               return false;
            }
            else if(op=='1'){
                borrar(60,8,30);
                borrar(65,10,25);
            }else{
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
            }
         }while(op>'2');
      }
    }while(continuar==false);
    estado=true;
    return true;
}


void Proveedor::mostrarProveedor(int y){

    gotoxy(5,y);cout<<cod_prov;
    gotoxy(19,y);cout<<getNombre();
    gotoxy(45,y);cout<<getApellido();
    gotoxy(67,y);cout<<getTelefono();
    gotoxy(82,y);cout<<getNomEmpresa();
    gotoxy(107,y);cout<<email;
}


///FUNCIONES
//MENU
void menuProveedores(){
    char op;

                while(true){

                textcolor(0);
                clrscr();
                recuadro(55, 5, 33, 16, cAZUL, cGRIS_CLARO);
                textcolor(cAZUL, cGRIS_CLARO);
                gotoxy(63,6);
                cout << " MENU PROVEEDORES";
                gotoxy(57,7);
                cout << "-----------------------------";
                gotoxy(57,8);
                cout << "1 - AGREGAR";
                gotoxy(57, 9);
                cout << "2 - MOSTRAR";
                gotoxy(57,10);
                cout << "3 - DAR DE BAJA";
                gotoxy(57,11);
                cout << "4 - BUSCAR";
                gotoxy(57,12);
                cout << "5 - MODIFICAR";
                gotoxy(57, 13);
                cout << "-----------------------------";
                gotoxy(57, 14);
                cout << "0 - MENU PRINCIPAL";
                gotoxy(57, 16);
                cout << "Ingresar opcion: ";
                cin >> op;

                    switch(op){

                      case '1':
                          agregarProveedor();
                        break;

                      case '2':
                          mostrarProveedores();
                        break;

                      case '3':
                          darDeBajaProveedor();
                        break;

                      case '4':
                          buscarProveedor();
                        break;

                      case '5':
                          modificarProveedor();
                        break;

                      case '0':
                        return ;
                        break;

                      default:
                          textcolor(cAZUL,cROJO_CLARO);
                        gotoxy(63, 19);
                        cout<<"OPCION INCORRECTA";
                      break;
                    }
                    textcolor(cBLANCO,cNEGRO);
                    gotoxy(0,0);
                    system("pause");
                  }
}


//DEVUELVE POSICION DE PROVEEDOR O -1 SI NO EXISTE
int buscarPosProveedor(char *cod){

    Proveedor regP;
    int pos=0;
    while(regP.leerDeDisco(pos)){
        if(strcmp(regP.getCodProv(),cod)==0){
            return pos;
        }
        pos++;
    }
    return -1;
}


//BEVUELVE CANTIDAD DE PROVEEDORES ACTIVOS
int cantidadProveedoresActivos(){

    Proveedor regP;
    int pos=0,cant=0;
    while(regP.leerDeDisco(pos)){
        if(regP.getEstado()==true){
            cant++;
        }
        pos++;
    }
    return cant;
}


//DEVUELVE LA CANTIDAD DE PROVEEDORES CON EL NOMBRE QUE SE BUSCA
int cantidadProvNombre(char *nom){
    int pos=0,cant=0;
    Proveedor reg;
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getNombre(),nom)==0){
            cant++;
        }
      pos++;
    }
    return cant;
}


//DEVUELVE LA CANTIDAD DE PROVEEDORES CON EL APELLIDO QUE SE BUSCA
int cantidadProvApellido(char *apell){
    int pos=0,cant=0;
    Proveedor reg;
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getApellido(),apell)==0){
            cant++;
        }
      pos++;
    }
    return cant;
}



int cantidadProvEmpresa(char *emp){
    int pos=0,cant=0;
    Proveedor reg;
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getNomEmpresa(),emp)==0){
            cant++;
        }
      pos++;
    }
    return cant;
}


//DEVUELVE LA CANTIDAD TOTAL DE PROVEEDORES
int cantRegTotProveedores(){
    int pos=0;
    Proveedor reg;
    while(reg.leerDeDisco(pos)){
        pos++;
    }
    return pos;
}


//DEVUELVE LA CANTIDAD DE PROVEEDORES ACTIVOS
int cantProvActivos(){
     int pos=0;
     int cant = 0;
    Proveedor reg;
    while(reg.leerDeDisco(pos)){
       if(reg.getEstado()==true){
        cant++;
       }
        pos++;
    }
    return cant;
}


//OPCION AGREGAR PROVEEDOR
void agregarProveedor(){

    Proveedor regP;
    bool sino;
    cuadroProveedor(2,66,"AGREGAR PROVEEDOR");
    lineaProveedor(16);
    sino=regP.cargarProveedor();
    if(sino==true){
        if(regP.guardarEnDisco()){
          letreroInfo(110,9,cAZUL,cVERDE_CLARO,"GUARDADO EXITOSO");
        }else{
          letreroInfo(110,9,cAZUL,cROJO_CLARO,"GUARDADO SIN EXITO");
        }
    }

}


//OPCION MOSTRAR PROVEEDORES
void mostrarProveedores(){

    int y,pos=0,cantProv=0,aux=0;
    char opMos;
    Proveedor regP, *vReg;
    bool mostrar=true;
    cantProv=cantProvActivos();
    vReg=new Proveedor[cantProv];
    if(vReg==NULL){
        exit(1);
    }
    while(regP.leerDeDisco(pos)){
      if(regP.getEstado()==true){
        vReg[aux]=regP;
        aux++;
      }
      pos++;
    }
    pos=0,aux=0;


    cuadroProveedor(10,60,"MOSTRAR PROVEEDORES");


    do{
            y=15;

            gotoxy(45,8);cout<<"1 - MOSTRAR  MENOS     2 - MOSTRAR MAS    3 - SALIR";

           if(mostrar==true){
            borrarProvMostrar(15);
            borrarProvMostrar(17);
            borrarProvMostrar(19);
            borrarProvMostrar(21);
            borrarProvMostrar(23);
            for(int i=pos;i<pos+5;i++){
                if(i<cantProv){
                    vReg[i].mostrarProveedor(y);
                    lineaProveedor(y+1);
                    y=y+2;

                }
            }
            mostrar=false;
           }
            borrar(60,10,20);
            gotoxy(60,10);cout<<"Ingrese opcion: ";cin>>opMos;
            if(opMos=='2'){
              pos=pos+5;
               if(pos<cantProv){
                  mostrar=true;
               }else{
                 pos=pos-5;
               }

            }else if(opMos=='1'){
                pos=pos-5;
                 if(pos>=0){
                    mostrar=true;
                 }else{
                    pos=pos+5;
                 }



            }


          }while(opMos!='3');

   delete vReg;



}


//OPCION DAR DE BAJA A PROVEEDOR
void darDeBajaProveedor(){

    char codProv[10];
    int existe,xAdv=108,yAdv=6,op;
    bool salir=false;
    Proveedor regP;
    cuadroProveedor(2,65,"DAR BAJA PROVEEDOR");
    lineaProveedor(16);

    do{
       borrar(110,9,25);
       borrar(10,9,50);
       borrar(62,10,50);
       gotoxy(55,8);cout<<"1 - INGRESAR CODIGO  2 - SALIR ";
       gotoxy(62,10);cout<<"Ingrese opcion:  ";cin>>op;
       switch(op){

       case 1:
           borrar(55,8,30);
           borrar(62,10,30);
           borrar(5,15,10);
           borrar(110,9,25);
           borrarProvMostrar(15);
           gotoxy(10,9);cout<<"INGRESE CODIGO PROVEEDOR A DAR DE VAJA.";
           gotoxy(5,15);cargarCadena(codProv,10);
           existe=buscarPosProveedor(codProv);
           if(existe>-1){
              regP.leerDeDisco(existe);
              regP.mostrarProveedor(15);
            if(regP.getEstado()==true){
               if(cuadroAdvertencia(xAdv,yAdv,"Dar de baja al proveedor S/N:? ")==1){
                   regP.setEstado(false);
                  if(regP.guardarEnDisco(existe)){
                      borrarCuadroAdvertencia(xAdv,yAdv);
                      letreroInfo(110,9,cAZUL,cVERDE_CLARO,"BAJA EXISTOSA");
                      pausa();
                  }else{
                      borrarCuadroAdvertencia(xAdv,yAdv);
                      letreroInfo(110,9,cAZUL,cROJO_CLARO,"ERROR AL GUARDAR");
                      pausa();
                  }
              }else{
                borrarCuadroAdvertencia(xAdv,yAdv);
                letreroInfo(110,9,cAZUL,cROJO_CLARO,"PROVEEDOR NO DADO DE BAJA");
                pausa();
              }
           }else{
              letreroInfo(110,9,cAZUL,cAMARILLO,"PROV. YA DADO DE BAJA");
              pausa();
           }
        }else{
           letreroInfo(110,9,cAZUL,cROJO_CLARO,"PROVEEDOR INEXISTENTE");
           pausa();
        }
        break;

       case 2:
           salir=true;
        break;
       }
    }while(salir==false);


}


//OPCION BUSCAR PROVEEDOR
void buscarProveedor(){
    char codI[10],nom[20],nomEmp[20];
    int existeProv,xLetrero=115,yLetrero=9,cant=0;
    int y=15,pos=0;
    char op;
    Proveedor regProv;

    do{
    cuadroProveedor(2,60,"MOSTRAR PROVEEDOR");
    lineaProveedor(16);
    borrar(xLetrero,yLetrero,25);
    borrar(10,9,35);
    borrar(50,8,63);
    borrar(8,10,35);
    borrar(65,10,20);
    gotoxy(50,8);cout<<"1 - INGRESAR COD.     2 - BUSCAR     3 - SALIR";
    gotoxy(65,10);cout<<"Ingrese Opcion: ";cin>>op;
      switch(op){
       case '1':
             borrarProvMostrar(15);
             borrar(5,15,10);
             borrar(50,8,80);
             borrar(65,10,20);
             borrar(xLetrero,yLetrero,25);
             gotoxy(10,9);cout<<"INGRESE CODIGO PROVEEDOR A BUSCAR. ";
             gotoxy(5,15);cargarCadena(codI,10);
             existeProv=buscarPosProveedor(codI);
             if(existeProv>-1){
               borrar(10,9,50);
               gotoxy(10,9);cout<<"INFORMACION DEL PROVEEDOR BUSCADO.";
               regProv.leerDeDisco(existeProv);
               regProv.mostrarProveedor(15);
               if(regProv.getEstado()==false){
                  letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"PROVEEDOR DADO DE BAJA");
                  pausa();

               }else{
                  letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"PROVEEDOR ACTIVO");
                  pausa();
               }
             }else{
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"PROVEEDOR INEXISTENTE");
                pausa();
             }
        break;

       case '2':
           do{
            borrar(50,8,70);
            borrar(65,10,20);
            gotoxy(43,8);cout<<"1 - NOMBRE     2 - APELLIDO    3 - NOM.EMPRESA     0 - VOLVER";
            gotoxy(65,10);cout<<"Ingrese Opcion: ";cin>>op;
            switch(op){

            case '1':
                   y=15,pos=0;
                   cuadroProveedor(2,60,"MOSTRAR POR NOMBRE");
                   lineaProveedor(16);
                   gotoxy(10,9);cout<<"INGRESE NOMBRE PROVEEDOR A BUSCAR.";
                   gotoxy(19,15);cargarCadena(nom,20);
                   cant=cantidadProvNombre(nom);
                   if(cant>0){
                    cuadroProveedor(2*cant,60,"MOSTRAR POR NOMBRE");
                    while(regProv.leerDeDisco(pos)){
                        if(strcmp(regProv.getNombre(),nom)==0){
                            regProv.mostrarProveedor(y);
                            lineaProveedor(y+1);
                            y+=2;
                        }
                        pos++;
                     }
                   }
                   borrar(10,9,50);
                break;

            case '2':
                   y=15,pos=0;
                   cuadroProveedor(2,60,"MOSTRAR POR APELLIDO");
                   lineaProveedor(16);
                   gotoxy(10,9);cout<<"INGRESE APELLIDO PROVEEDOR A BUSCAR. ";
                   gotoxy(45,15);cargarCadena(nom,20);
                   cant=cantidadProvApellido(nom);
                   if(cant>0){
                    cuadroProveedor(2*cant,60,"MOSTRAR POR APELLIDO");
                    while(regProv.leerDeDisco(pos)){
                        if(strcmp(regProv.getApellido(),nom)==0){
                            regProv.mostrarProveedor(y);
                            lineaProveedor(y+1);
                            y+=2;
                        }
                        pos++;
                     }
                   }
                   borrar(10,9,50);
                break;

            case '3':
              y=15,pos=0;
                   cuadroProveedor(2,60,"MOSTRAR POR NOMBRE DE EMPRESA");
                   lineaProveedor(16);
                   gotoxy(10,9);cout<<"INGRESE NOMBRE DE LA EMPRESA A BUSCAR. ";
                   gotoxy(85,15);cargarCadena(nomEmp,20);
                   cant=cantidadProvEmpresa(nomEmp);
                   if(cant>0){
                    cuadroProveedor(2*cant,60,"MOSTRAR POR APELLIDO");
                    while(regProv.leerDeDisco(pos)){
                        if(strcmp(regProv.getNomEmpresa(),nomEmp)==0){
                            regProv.mostrarProveedor(y);
                            lineaProveedor(y+1);
                            y+=2;
                        }
                        pos++;
                     }
                   }
                   borrar(10,9,50);
              break;

            case '0':
                borrar(43,8,60);
                break;
            }
           }while(op!='0');

           break;

       case '3':
        break;

      }


    }while(op!='3');


}


//OPCION MODIFICAR PROVEEDOR
void modificarProveedor(){

    char codProv[10],op;
    int existe,existeNuevCod,xLetrero=120,yLetrero=9,xAdv=108,yAdv=6;
    bool continuar=false;
    Proveedor regP;
    cuadroProveedor(2,65,"MODIFICAR PROVEEDOR");
    lineaProveedor(16);
    gotoxy(8,10);cout<<"INGRESE CODIGO PROVEEDOR: ";
    gotoxy(5,15);cargarCadena(codProv,10);
    existe=buscarPosProveedor(codProv);
    if(existe>-1){
        regP.leerDeDisco(existe);
        regP.mostrarProveedor(15);
        borrar(8,10,30);
        do{
            borrar(xLetrero,yLetrero,25);
            borrar(12,9,35);
            borrar(65,10,22);
            letreroInfo(24,8,cAZUL,cGRIS_CLARO,"       1 - CODIGO   2 - NOMBRE   3 - APELLIDO   4 - TELEFONO   5 - EMPRESA   6 - EMAIL  7 - SALIR");
            gotoxy(65,10);cout<<"Ingrese Opcion: ";
            cin>>op;
            if(op>'7'){
                borrar(24,8,98);
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
                borrar(xLetrero,yLetrero,17);
            }
            borrar(65,10,25);
        //BORRA LETRERO LINEA 1258
        borrar(24,8,100);
        switch(op){
        case '1':
            char cod[10];
            gotoxy(12,9);cout<<"INGRESE NUEVO CODIGO DEL PROVEEDOR.";
            do{
              borrar(4,15,10);
              gotoxy(4,15);cargarCadena(cod,10);
              existeNuevCod=buscarPosProveedor(cod);
              if(cod[0]=='\0'){
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                pausa();

              }
              if(existeNuevCod>-1){
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CODIGO PROVEEDOR EXISTENTE");
                pausa();
              }
            }while(cod[0]=='\0'||existeNuevCod>-1);
            if(cuadroAdvertencia(xAdv,yAdv,"Cambiar codigo proveedor S/N?")){
                regP.setCodProv(cod);
                if(regP.guardarEnDisco(existe)){
                    borrarCuadroAdvertencia(xAdv,yAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                    pausa();
                }else{
                    borrarCuadroAdvertencia(xAdv,yAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"ERROR AL GUARDAR CAMBIO");
                }

            }else{
                borrarCuadroAdvertencia(xAdv,yAdv);
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
                pausa();
            }
            break;

        case '2':
            char nom[20];
            gotoxy(12,9);cout<<"INGRESE NUEVO NOMBRE DEL PROVEEDOR.";
            do{
              borrar(19,15,20);
              gotoxy(19,15);cargarCadena(nom,20);
              if(nom[0]=='\0'){
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                pausa();
              }
            }while(nom[0]=='\0');
            if(cuadroAdvertencia(xAdv,yAdv,"Cambiar nombre proveedor S/N?")){
                regP.setNombre(nom);
                if(regP.guardarEnDisco(existe)){
                    borrarCuadroAdvertencia(xAdv,yAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                    pausa();
                }else{
                    borrarCuadroAdvertencia(xAdv,yAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"ERROR AL GUARDAR CAMBIO");
                    pausa();
                }
            }else{
                borrarCuadroAdvertencia(xAdv,yAdv);
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
                pausa();
            }
            break;

        case '3':
            char apell[20];
            gotoxy(12,9);cout<<"INGRESE NUEVO APELLIDO DEL PROVEEDOR.";
            do{
              borrar(45,15,20);
              gotoxy(45,15);cargarCadena(apell,20);
              if(apell[0]=='\0'){
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                pausa();
              }
            }while(apell[0]=='\0');
            if(cuadroAdvertencia(xAdv,yAdv,"Cambiar apellido proveedor S/N?")){
                regP.setApellido(apell);
                if(regP.guardarEnDisco(existe)){
                    borrarCuadroAdvertencia(xAdv,yAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                    pausa();
                }else{
                    borrarCuadroAdvertencia(xAdv,yAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"ERROR AL GUARDAR CAMBIO");
                    pausa();
                }
            }else{
                borrarCuadroAdvertencia(xAdv,yAdv);
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
                pausa();
            }
            break;

        case '4':
            char tel[11];
            gotoxy(12,9);cout<<"INGRESE NUEVO TELEFONO DEL PROVEEDOR.";
            do{
              borrar(67,15,11);
              gotoxy(67,15);cargarCadena(tel,10);
              if(tel[0]=='\0'){
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                pausa();
              }
            }while(tel[0]=='\0');
            if(cuadroAdvertencia(xAdv,yAdv,"Cambiar telefono proveedor S/N?")){
                regP.setTelefono(tel);
                if(regP.guardarEnDisco(existe)){
                   borrarCuadroAdvertencia(xAdv,yAdv);
                   letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                   pausa();
                }else{
                   borrarCuadroAdvertencia(xAdv,yAdv);
                   letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"ERROR AL GUARDAR CAMBIO");
                   pausa();
                }
            }else{
                borrarCuadroAdvertencia(xAdv,yAdv);
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
                pausa();
            }
            break;

        case '5':
            char nomEmp[40];
            gotoxy(12,9);cout<<"INGRESE NUEVO NOMBRE DE EMPRESA DEL PROVEEDOR.";
            do{
              borrar(82,15,23);
              gotoxy(82,15);cargarCadena(nomEmp,40);
              if(nomEmp[0]=='\0'){
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                pausa();
              }
            }while(nomEmp[0]=='\0');
            if(cuadroAdvertencia(xAdv,yAdv,"Cambiar nombre empresa proveedor S/N?")){
                regP.setNomEmpresa(nomEmp);
                if(regP.guardarEnDisco(existe)){
                   borrarCuadroAdvertencia(xAdv,yAdv);
                   letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                   pausa();
                }else{
                   borrarCuadroAdvertencia(xAdv,yAdv);
                   letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"ERROR AL GUARDAR CAMBIO");
                   pausa();
                }
            }else{
               borrarCuadroAdvertencia(xAdv,yAdv);
               letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
               pausa();
            }
            break;

        case '6':
            char email[50];
            gotoxy(12,9);cout<<"INGRESE NUEVO EMAIL DEL PROVEEDOR.";
            do{
               borrar(107,15,39);
               gotoxy(107,15);cargarCadena(email,50);
               if(email[0]=='\0'){
                  letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                  pausa();
               }
            }while(email[0]=='\0');
            if(cuadroAdvertencia(xAdv,yAdv,"Cambiar email proveedor S/N?")){
                regP.setEmail(email);
                if(regP.guardarEnDisco(existe)){
                    borrarCuadroAdvertencia(xAdv,yAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                    pausa();
                }else{
                   borrarCuadroAdvertencia(xAdv,yAdv);
                   letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"ERROR AL GUARDAR CAMBIO");
                   pausa();
                }
            }else{
                borrarCuadroAdvertencia(xAdv,yAdv);
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
                pausa();
            }
            break;

        case '7':
            continuar=true;
            break;
        }
        }while(continuar==false);

    }else{
        letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CODIGO INEXISTENTE");
    }

}


//BORRA DE PANTALLA PROVEEDOR MOSTRADO
void borrarProvMostrar(int y){
    gotoxy(5,y);cout<<"      ";
    gotoxy(19,y);cout<<"             ";
    gotoxy(45,y);cout<<"            ";
    gotoxy(67,y);cout<<"            ";
    gotoxy(82,y);cout<<"                     ";
    gotoxy(107,y);cout<<"                                  ";
}


#endif // PROVEEDOR_H_INCLUDED
