#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

///METODOS CLASE

Producto::Producto(){
    strcpy(cod_prod,"aaaa");
    estado=false;
}


bool Producto::leerDeDisco(int pos){
    FILE *p;
    p=fopen("Productos.dat","rb");
    if(p==NULL){
        cout<<"Error al leer archivo PRODUCTOS - funcion: leerDeDisco."<<endl;
        exit(1);
    }
    fseek(p,sizeof*this*pos,0);
    bool siNo=fread(this,sizeof*this,1,p);
    fclose(p);
    return siNo;
}


bool Producto::guardarEnDisco(){
    FILE *p;
    p=fopen("Productos.dat","ab");
    if(p==NULL){
        cout<<"Error al abrir archivo PRODUCTOS - funcion: guardarEnDisco."<<endl;
        exit(1);
    }
    bool siNo=fwrite(this,sizeof*this,1,p);
    fclose(p);
    return siNo;
}


bool Producto::guardarEnDisco(int pos){
    FILE *p;
    p=fopen("Productos.dat","rb+");
    if(p==NULL){
        cout<<"Error al abrir archivo PRODUCTOS - funcion: guardarEnDisco(pos)."<<endl;
        exit(1);
    }
    fseek(p,sizeof*this*pos,0);
    bool siNo=fwrite(this,sizeof*this,1,p);
    fclose(p);
    return siNo;
}


bool Producto::cargarProducto(){
    Proveedor regProv;
    int existe;
    char op;
    bool continuar;
    textcolor(cNEGRO,cGRIS_CLARO);
    do{
      continuar=true;
      borrar(12,9,34);
      borrar(5,15,10);
      gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PRODUCTO.";
      gotoxy(5,15);cargarCadena(cod_prod,10);
      existe=buscarPosProducto(cod_prod);
           if(cod_prod[0]=='\0'){
        continuar=false;
        letreroInfo(110,9,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
        pausa();
        borrar(110,9,20);
      }
      if(existe>-1){
        continuar=false;
        letreroInfo(110,9,cAZUL,cROJO_CLARO,"CODIGO YA EXISTENTE");
        pausa();
        borrar(110,9,20);
      }
      if(continuar==false){
          do{
            borrar(110,9,22);
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
                letreroInfo(110,9,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
                borrar(60,8,30);
                borrar(65,10,25);
            }
         }while(op>'2');
      }

    }while(continuar==false);

    do{
      continuar=true;
      borrar(19,15,38);
      borrar(12,9,34);
      gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PRODUCTO.";
      gotoxy(19,15);cargarCadena(descripcion,50);
      if(descripcion[0]=='\0'){
        continuar=false;
        letreroInfo(98,9,cAZUL,cROJO_CLARO,"NO PUEDE ESTAR VACIO");
        pausa();
        borrar(98,9,20);
      }
      if(continuar==false){
          do{
            borrar(110,9,22);
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
                letreroInfo(110,9,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
                borrar(60,8,30);
                borrar(65,10,25);
            }
         }while(op>'2');
      }
    }while(continuar==false);

    do{
      continuar=true;
      borrar(12,9,34);
      gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PRODUCTO.";
      borrar(83,15,7);
      gotoxy(83,15);cin>>stock;
      if(stock<1){
        continuar=false;
        letreroInfo(98,9,cAZUL,cROJO_CLARO,"STOCK INGRESADO INVALIDO");
        pausa();
        borrar(98,9,23);
      }
      if(continuar==false){
          do{
            borrar(110,9,22);
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
                letreroInfo(110,9,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
                borrar(60,8,30);
                borrar(65,10,25);
            }
         }while(op>'2');
      }
    }while(continuar==false);

    do{
      continuar=true;
      borrar(12,9,34);
      gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PRODUCTO.";
      borrar(92,15,10);
      gotoxy(92,15);cargarCadena(cod_prov,10);
      existe=buscarPosProveedor(cod_prov);
      if(cod_prov[0]=='\0'){
        continuar=false;
        letreroInfo(98,9,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
        pausa();
        borrar(98,9,23);
      }else if(existe<0){
        continuar=false;
        letreroInfo(98,9,cAZUL,cROJO_CLARO,"PROVEEDOR INEXISTENTE");
        pausa();
       borrar(98,9,23);
      }else{
         regProv.leerDeDisco(existe);
         if(regProv.getEstado()==false){
           continuar=false;
           letreroInfo(98,9,cAZUL,cROJO_CLARO,"PROVEEDOR DADO DE BAJA");
           pausa();
         }
      }
      if(continuar==false){
          do{
            borrar(110,9,22);
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
                letreroInfo(110,9,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
                borrar(60,8,30);
                borrar(65,10,25);
            }
         }while(op>'2');
      }
    }while(continuar==false);

    do{
        continuar=true;
        borrar(12,9,34);
        gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PRODUCTO.";
        borrar(112,15,9);
        gotoxy(112,15);cout<<"$";cin>>precio_uni;
        if(precio_uni<1){
           continuar=false;
           letreroInfo(98,9,cAZUL,cROJO_CLARO,"PRECIO INGRESADO INVALIDO");
           pausa();
           borrar(98,9,24);
        }
        if(continuar==false){
          do{
            borrar(110,9,22);
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
                letreroInfo(110,9,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
                borrar(60,8,30);
                borrar(65,10,25);
            }
         }while(op>'2');
      }
    }while(continuar==false);

    do{
        continuar=true;
        borrar(12,9,34);
        gotoxy(12,9);cout<<"INGRESE INFORMACION DEL PRODUCTO.";
        borrar(130,15,9);
        gotoxy(130,15);cargarCadena(marca,20);
        if(marca[0]=='\0'){
           continuar=false;
           letreroInfo(98,9,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
           pausa();
           borrar(98,9,24);
        }
        if(continuar==false){
          do{
            borrar(110,9,22);
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
                letreroInfo(110,9,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
                borrar(60,8,30);
                borrar(65,10,25);
            }
         }while(op>'2');
      }
    }while(continuar==false);
    estado=true;
    textcolor(cAZUL,cGRIS_CLARO);
    return true;

}


void Producto::mostrarProducto(int y){

    gotoxy(5,y);cout<<cod_prod;
    gotoxy(19,y);cout<<descripcion;
    gotoxy(83,y);cout<<stock;
    gotoxy(92,y);cout<<cod_prov;
    gotoxy(112,y);cout<<"$"<<precio_uni;
    gotoxy(130,y);cout<<marca;
}



///FUNCIONES
//MENU
void menuProductos(){

    char op;

                while(true){
                int cantProd=0,pos=0,posYreg=15;
                textcolor(0);
                clrscr();
                recuadro(55, 5, 33, 16, cAZUL, cGRIS_CLARO);
                textcolor(cAZUL, cGRIS_CLARO);
                gotoxy(63,6);
                cout << " MENU PRODUCTOS";
                gotoxy(57,7);
                cout << "-----------------------------";
                gotoxy(57,8);
                cout << "1 - AGREGAR ";
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
                            AgregarProducto();
                        break;

                      case '2':
                            mostrarProductos();
                        break;

                       case '3':
                            darDeBajaProducto();
                         break;

                       case '4':
                            buscarProducto();
                         break;

                       case '5':
                            modificarProducto();
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


//BUSCA Y DEVUELVE POSICION EN EL ARCHIVO DEL PRODUCTO BUSCADO O -1 SI NO SE ENCONTRO EL PRODUCTO
int buscarPosProducto(char *codProd){
    Producto regP;
    int posP=0;
    while(regP.leerDeDisco(posP)){
        if(strcmp(regP.getCodProd(),codProd)==0){
            return posP;
        }
        posP++;
    }
    return -1;
}


//DEVUELVE CANTIDAD DE PRODUCTOS ACTIVOS EN ARCHIVO
int cantidadProductosActivos(){

    int pos=0;
    int cant=0;
    Producto regP;
    while(regP.leerDeDisco(pos)){
      if(regP.getEstado()==true){
        cant++;
      }
      pos++;
    }
    return cant;
}


//DEVUELVE CANTIDAD DE PRODUCTOS TOTALES EN EL ARCHIVO
int cantRegTotProductos(){
    int pos=0;
    Producto reg;
    while(reg.leerDeDisco(pos)){
        pos++;
    }
    return pos;
}


//OPCION AGREGAR PRODUCTOS
void AgregarProducto(){
    Producto regP;
    bool sino;
    cuadroProductos(2,66,"AGREGAR PRODUCTO");
    lineaProducto(16);
    sino=regP.cargarProducto();
    if(sino==true){
       if(regP.guardarEnDisco()){
          letreroInfo(100,9,cAZUL,cVERDE_CLARO,"Guardado con exito");
       }else{
          letreroInfo(100,9,cAZUL,cROJO_CLARO,"Guardado sin exito");
       }
    }
}


//OPCION MOSTRAR PRODUCTOS
void mostrarProductos(){
    int y,pos=0,cantProd=0,aux=0;
    char opMos;
    Producto regP, *vReg;
    bool mostrar=true;
    cantProd=cantidadProductosActivos();
    vReg=new Producto[cantProd];
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


    cuadroProductos(10,60,"MOSTRAR PRODUCTOS");


    do{
            y=15;

            gotoxy(45,8);cout<<"1 - MOSTRAR  MENOS     2 - MOSTRAR MAS    3 - SALIR";

           if(mostrar==true){
            borrarProdMostrar(15);
            borrarProdMostrar(17);
            borrarProdMostrar(19);
            borrarProdMostrar(21);
            borrarProdMostrar(23);
            for(int i=pos;i<pos+5;i++){
                if(i<cantProd){
                  vReg[i].mostrarProducto(y);
                   lineaProducto(y+1);
                   y=y+2;
                }
            }
            mostrar=false;
           }
            borrar(60,10,20);
            gotoxy(60,10);cout<<"Ingrese opcion: ";cin>>opMos;
            if(opMos=='2'){
              pos=pos+5;
               if(pos<cantProd){
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


//OPCION DAR DE BAJA PRODUCTO
void darDeBajaProducto(){
    int xCuadAdv=108,yCuadAdv=6,xLetrero=115,yLetrero=9;
    char cod[10],op;
    Producto regP;
    int existe;
    bool salir=false;
    cuadroProductos(2,62,"DAR DE BAJA PRODUCTO");
    lineaProducto(16);
    do{
       borrar(50,8,50);
       borrar(62,10,50);
       gotoxy(55,8);cout<<"1 - INGRESAR CODIGO  2 - SALIR ";
       gotoxy(62,10);cout<<"Ingrese opcion:  ";cin>>op;
       switch(op){

       case '1':
           borrar(55,8,30);
           borrar(62,10,30);
           borrar(5,15,10);
           gotoxy(52,8);cout<<"INGRESE CODIGO PRODUCTO A DAR DE VAJA.";
           borrarProdMostrar(15);
           borrar(xLetrero,yLetrero,30);
           gotoxy(5,15);cargarCadena(cod,10);
           existe=buscarPosProducto(cod);
           if(existe>-1){
             regP.leerDeDisco(existe);
             if(regP.getEstado()==true){
                 regP.mostrarProducto(15);
                 if(cuadroAdvertencia(xCuadAdv,yCuadAdv,"Dar de baja al producto S/N:? ")==1){
                    regP.setEstado(false);
                    regP.guardarEnDisco(existe);
                    borrarCuadroAdvertencia(xCuadAdv,yCuadAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CODIGO DADO DE BAJA");


                 }else{
                    borrarCuadroAdvertencia(xCuadAdv,yCuadAdv);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"PRODUCTO NO DADO DE BAJA");


                 }
             }else{
                regP.mostrarProducto(15);
                letreroInfo(xLetrero,yLetrero,cAZUL,cAMARILLO,"PRODUCTO YA DADO DE BAJA");

             }
          }else{
             letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"PRODUCTO INEXISTENTE");
          }

        break;

       case '2':
           salir=true;
        break;
       }

    }while(salir==false);


}


//OPCION BUSCAR PRODUCTO
void buscarProducto(){

    char codI[10];
    int existeProd,existeProv,existeMarca,xLetrero=115,yLetrero=9,cantReg=0,pos=0;
    int y=15;
    char op,opAux,marca[20];
    bool sino=false;
    Producto regProd, auxProd;
    Proveedor regProv;
    cuadroProductos(2,64,"BUSCAR PRODUCTO");
    lineaProducto(16);

    do{
    borrar(10,9,35);
    borrar(40,8,60);
    borrar(8,10,35);
    borrar(65,10,20);
    gotoxy(40,8);cout<<"1 - INGRESAR COD.     2 - BUSCAR    3 - INFO. PROVEEDOR     4 - SALIR";
    gotoxy(65,10);cout<<"Ingrese Opcion: ";cin>>op;
      switch(op){
       case '1':
             cuadroProductos(2,64,"BUSCAR PRODUCTO");
             borrarProdMostrar(15);
             borrar(5,15,10);
             borrar(40,8,80);
             borrar(65,10,20);
             gotoxy(10,9);cout<<"INGRESE CODIGO PRODUCTO A BUSCAR. ";
             lineaProducto(16);
             gotoxy(5,15);cargarCadena(codI,10);
             existeProd=buscarPosProducto(codI);
             if(existeProd>-1){
               regProd.leerDeDisco(existeProd);
               regProd.mostrarProducto(15);
               if(regProd.getEstado()==false){
                  letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"PRODUCTO DADO DE BAJA");
                  pausa();
                  borrar(xLetrero,yLetrero,25);
                  borrarProdMostrar(15);
               }else{
                  auxProd=regProd;
                  sino=true;
               }
             }else{
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"  PRODUCTO INEXISTENTE  ");
                pausa();
                borrar(xLetrero,yLetrero,25);
             }
        break;

       case '2':
           do{
            sino=false;
            borrar(40,8,70);
            borrar(65,10,20);
            gotoxy(40,8);cout<<"1 - DESCRIPCION.     2 - COD.PROVEEDOR    3 - MARCA     0 - VOLVER";
            gotoxy(65,10);cout<<"Ingrese Opcion: ";cin>>op;
            switch(op){

            case '1':
                break;

            case '2':
                y=15;
                pos=0;
               cuadroProductos(2,64,"PRODUCTOS POR PROVEEDOR");
               lineaProducto(16);
               borrarProdMostrar(15);
               gotoxy(10,9);cout<<"INGRESE CODIGO PROVEEDOR A BUSCAR. ";
               gotoxy(92,15);cargarCadena(regProv.getCodProv(),10);
               existeProv=buscarPosProveedor(regProv.getCodProv());
               if(existeProv>-1){
                  cantReg=cantidadProdProveedor(regProv.getCodProv());
                  cuadroProductos(cantReg*2,64,"PRODUCTOS POR PROVEEDOR");
                  while(regProd.leerDeDisco(pos)){
                        if(strcmp(regProd.getCodProv(),regProv.getCodProv())==0){
                            regProd.mostrarProducto(y);
                            lineaProducto(y+1);
                            y=y+2;
                        }
                     pos++;
                  }
               }
                break;

            case '3':
                y=15;
                pos=0;
               cuadroProductos(2,64,"PRODUCTOS POR MARCA");
               lineaProducto(16);
               borrarProdMostrar(15);
               gotoxy(130,15);cargarCadena(marca,10);
               cantReg=cantidadProdMarca(marca);
               if(cantReg>0){
                 cuadroProductos(cantReg*2,64,"MOSTRAR POR MARCA");
                 while(regProd.leerDeDisco(pos)){
                  if(strcmp(regProd.getMarca(),marca)==0){
                     regProd.mostrarProducto(y);
                            lineaProducto(y+1);
                            y=y+2;
                  }
                  pos++;
                }
               }

              break;
            }
           }while(op!='0');

           break;

       case '3':
           if(sino==true){
            regProv.leerDeDisco(buscarPosProveedor(auxProd.getCodProv()));
             cuadroProveedor(2,66,"INFO PROVEEDOR");
             gotoxy(10,9);cout<<"INFORMACION DE PROVEEDOR DEL PRODUCTO: "<<auxProd.getCodProd();
             lineaProveedor(16);
             regProv.mostrarProveedor(15);
             pausa();
             cuadroProductos(2,64,"BUSCAR PRODUCTO");
             lineaProducto(16);
             auxProd.mostrarProducto(15);
           }

        break;


       case '4':
         break;

      }


    }while(op!='4');
}


//OPCIONE MODIFICAR PRODUCTOS
void modificarProducto(){
    char codd[10],op;
    int existe,existeNuevCod,xLetrero=120,yLetrero=9;
    const int xCuadAdv=108;
    Producto regP;
    cuadroProductos(2,64,"MODIFICAL PRODUCTO");
    lineaProducto(16);
    gotoxy(8,10);cout<<"INGRESE CODIGO PRODUCTO A MODIFICAR. ";
    gotoxy(5,15);cin>>codd;
    existe=buscarPosProducto(codd);
    if(existe>-1){
        borrar(8,10,40);
        regP.leerDeDisco(existe);
        regP.mostrarProducto(15);
        do{
            borrar(20,8,40);
            borrar(65,10,22);
            letreroInfo(20,8,cAZUL,cGRIS_CLARO,"       1 - CODIGO   2 - DESCRIPCION   3 - STOCK   4 - PROVEEDOR   5 - PRECIO  6 - MARCA   7 - VOLVER");
            gotoxy(65,10);cout<<"Ingrese Opcion: ";
            cin>>op;
            if(op>'7'){
                borrar(26,8,98);
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
                pausa();
                borrar(xLetrero,yLetrero,17);
            }
        }while(op>'7');
        borrar(65,10,25);
        //BORRA LETREROINFO - LINEA 870
        borrar(26,8,98);
        switch(op){
        case '1':
          char cod[10];
          gotoxy(12,9);cout<<"INGRESE NUEVO CODIGO DEL PRODUCTO.";
          do{
            borrar(5,15,10);
            gotoxy(5,15);cargarCadena(cod,10);
            existeNuevCod=buscarPosProducto(cod);
            if(existeNuevCod>-1){
              letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CODIGO EXISTENTE");
              pausa();
              borrar(xLetrero,yLetrero,25);
            }
            if(cod[0]=='\0'){
              letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
              pausa();
              borrar(xLetrero,yLetrero,25);
            }
          }while(existeNuevCod>-1||cod[0]=='\0');
          if(cuadroAdvertencia(xCuadAdv,6,"Realizar cambio codigo S/N?")==true){
              regP.setCodProd(cod);
              if(regP.guardarEnDisco(existe)){
                  borrarCuadroAdvertencia(xCuadAdv,6);
                  letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
              }
          }else{
              borrarCuadroAdvertencia(xCuadAdv,6);
              letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
          }
          break;

        case '2':
          char descrip[50];
          gotoxy(12,9);cout<<"INGRESE NUEVA DESCRIPCION DEL PRODUCTO.";
          do{
            borrar(19,15,38);
            gotoxy(19,15);cargarCadena(descrip,50);
            if(descrip[0]=='\0'){
                letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                pausa();
                borrar(xLetrero,yLetrero,20);
            }
          }while(descrip[0]=='\0');
          if(cuadroAdvertencia(xCuadAdv,6,"Realizar cambio descripcion S/N?")==true){
              regP.setDescripcion(descrip);
              if(regP.guardarEnDisco(existe)){
                  borrarCuadroAdvertencia(xCuadAdv,6);
                  letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
              }
          }else{
              borrarCuadroAdvertencia(xCuadAdv,6);
              letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
          }
        break;

          case '3':
              int stk;
              //BORRA LETREROINFO - LINEA 758
              borrar(26,8,98);
              gotoxy(12,9);cout<<"INGRESE NUEVO STOCK DEL PRODUCTO.";
              do{
                borrar(83,15,7);
                gotoxy(83,15);cin>>stk;
                if(stk<0){
                   letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"STOCK NEGATIVO INVALIDO");
                   pausa();
                   borrar(xLetrero,yLetrero,25);
                }
              }while(stk<0);
              if(cuadroAdvertencia(xCuadAdv,6,"Realizar cambio stock S/N?")==1){
                  regP.setStock(stk);
                  if(regP.guardarEnDisco(existe)){
                      borrarCuadroAdvertencia(xCuadAdv,6);
                      letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                  }
              }else{
                  borrarCuadroAdvertencia(xCuadAdv,6);
                  letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
              }
            break;

            case '4':
              char codProv[10];
              gotoxy(12,9);cout<<"INGRESE NUEVO CODIGO DE PROVEEDOR.";
              do{
                borrar(92,15,17);
                gotoxy(92,15);cargarCadena(codProv,10);
                existeNuevCod=buscarPosProveedor(codProv);
                if(existeNuevCod<0){
                   letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"PROVEEDOR INEXISTENTE");
                   pausa();
                   borrar(xLetrero,yLetrero,25);
                }
                if(codProv[0]=='\0'){
                   letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                   pausa();
                   borrar(xLetrero,yLetrero,25);
                }
              }while(existeNuevCod<0||codProv[0]=='\0');
              if(cuadroAdvertencia(xCuadAdv,6,"Realizar cambio proveedor S/N?")==1){
                  regP.setCodProv(codProv);
                  if(regP.guardarEnDisco(existe)){
                     borrarCuadroAdvertencia(xCuadAdv,6);
                     letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                  }
                  }else{
                      borrarCuadroAdvertencia(xCuadAdv,6);
                      letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
                  }
                break;

            case '5':
                float prec;
                gotoxy(12,9);cout<<"INGRESE NUEVO PRECIO DEL PRODUCTO.";
                do{
                  borrar(112,15,10);
                  gotoxy(112,15);cout<<"$ ";cin>>prec;
                  if(prec<0){
                    letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"PRECIO NEGATIVO INVALIDO");
                    pausa();
                    borrar(xLetrero,yLetrero,25);
                  }
                }while(prec<0);
                if(cuadroAdvertencia(xCuadAdv,6,"Realizar cambio precio S/N?")==1){
                regP.setPrecUni(prec);
                    if(regP.guardarEnDisco(existe)){
                        borrarCuadroAdvertencia(xCuadAdv,6);
                        letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                    }
                }else{
                    borrarCuadroAdvertencia(xCuadAdv,6);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
                }
                break;

            case '6':
                char marca[20];
                gotoxy(12,9);cout<<"INGRESE NUEVA MARCA DEL PRODUCTO.";
                do{
                  borrar(130,15,10);
                  gotoxy(130,15);cargarCadena(marca,20);
                  if(marca[0]=='\0'){
                    letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMPO VACIO INVALIDO");
                    pausa();
                    borrar(xLetrero,yLetrero,25);
                  }
                }while(marca[0]=='\0');
                if(cuadroAdvertencia(xCuadAdv,6,"Realizar cambio marca S/N?")==1){
                   regP.setMarca(marca);
                   if(regP.guardarEnDisco(existe)){
                     borrarCuadroAdvertencia(xCuadAdv,6);
                     letreroInfo(xLetrero,yLetrero,cAZUL,cVERDE_CLARO,"CAMBIO EXITOSO");
                   }
                }else{
                    borrarCuadroAdvertencia(xCuadAdv,6);
                    letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CAMBIO NO REALIZADO");
                }
                break;

         }
      }else{
          letreroInfo(xLetrero,yLetrero,cAZUL,cROJO_CLARO,"CODIGO INEXISTENTE");
      }
}


 //DEVUELVE CANTIDAD DE PRODUCTOS POR EL PROVEEDOR ENVADO
int cantidadProdProveedor(char *codProv){
     int pos=0,cant=0;
     Producto reg;
     while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getCodProv(),codProv)==0){
            cant++;
        }
        pos++;
     }
     return cant;
}


//DEVUELVE CANTIDAD DE PRODUCTOS POR LA MARCA ENVIADA
int cantidadProdMarca(char *marca){
    int pos=0,cant=0;
    Producto reg;
    while(reg.leerDeDisco(pos)){
        if(strcmp(reg.getMarca(),marca)==0){
            cant++;
        }
        pos++;
    }
    return cant;
}




#endif // PRODUCTO_H_INCLUDED
