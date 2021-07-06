#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED


///METODOS VENTA CABECERA

VentaCabecera::VentaCabecera(){
     id=0;
     tipo='N';
     total=0;
     activo=false;
}


bool VentaCabecera::guardarEnDisco(){
    FILE *v;
    v=fopen("VentaCabecera.dat","ab");
    if(v==NULL){
        cout<<"Error al abrir archivo VentaCabecera - funcion: guardarEnDisco."<<endl;
        exit(1);
    }
    bool siNo=fwrite(this,sizeof*this,1,v);
    fclose(v);
    return siNo;
}


bool VentaCabecera::guardarEnDisco(int pos){
    FILE *v;
    v=fopen("VentaCabecera.dat","rb+");
    if(v==NULL){
        cout<<"Error al abrir archivo VentaCabecera - funcion: guardarEnDisco(pos)."<<endl;
        exit(1);
    }
    fseek(v,sizeof*this*pos,0);
    bool siNo=fwrite(this,sizeof*this,1,v);
    fclose(v);
    return siNo;
}


bool VentaCabecera::leerDeDisco(int pos){
    FILE *v;
    v=fopen("VentaCabecera.dat","rb");
    if(v==NULL){
      cout<<"error al abrir archivo Ventacabecera - funcion: leerDeDisco(pos),"<<endl;
      exit(1);
    }
    fseek(v,sizeof*this*pos,0);
    bool sino=fread(this,sizeof *this,1,v);
    fclose(v);
    return sino;
}


void VentaCabecera::mostrarVentaCabecera(int y){
    gotoxy(42,y);cout<<id;
    gotoxy(58,y);cout<<fech.getDia()<<"/"<<fech.getMes()<<"/"<<fech.getAnio();
    gotoxy(79,y);cout<<tipo;
    gotoxy(90,y);cout<<"$ "<<total;
}



///METODOS VENTA DETALLE

VentaDetalle::VentaDetalle(){
     idVenta=0;
     strcpy(cod_prod,"0000");
     cantidad=0;
     importe=0;
     estado=false;
}


bool VentaDetalle::guardarEnDisco(){
    FILE *v;
    v=fopen("VentaDetalle.dat","ab");
    if(v==NULL){
        cout<<"Error al abrir archivo VentaDetalle - funcion: guardarEnDisco()."<<endl;
        exit(1);
    }
    bool siNo=fwrite(this,sizeof*this,1,v);
    fclose(v);
    return siNo;
}


bool VentaDetalle::guardarEnDisco(int pos){
    FILE *v;
    v=fopen("VentaDetalle.dat","rb+");
    if(v==NULL){
        cout<<"Error al abrir archivo VentaDetalle - funcion: guardarEnDisco(pos)."<<endl;
        exit(1);
    }
    fseek(v,sizeof*this*pos,0);
    bool siNo=fwrite(this,sizeof*this,1,v);
    fclose(v);
    return siNo;
}


bool VentaDetalle::leerDeDisco(int pos){
    FILE *v;
    v=fopen("VentaDetalle.dat","rb");
    if(v==NULL){
      cout<<"error al abrir archivo VentaDetalle - funcion: leerDeDisco(pos),"<<endl;
      exit(1);
    }
    fseek(v,sizeof*this*pos,0);
    bool sino=fread(this,sizeof *this,1,v);
    fclose(v);
    return sino;
}


void VentaDetalle::mostrarPrueba(int y){
     Producto regP;
     int posProd=buscarPosProducto(cod_prod);
     regP.leerDeDisco(posProd);
     gotoxy(23,y);cout<<cod_prod;
     gotoxy(43,y);cout<<regP.getDescripcion();
     gotoxy(99,y);cout<<cantidad;
     gotoxy(112,y);cout<<"$ "<<importe;

}


bool VentaDetalle::cargarVentDetalle(int y,int id){
    Producto regP;
    int exisProd=false,cant=0;
    char cod[10];
    float monto=0;
    system("cls");
    cuadroVentaDentalleRealizar(66,"REALIZAR VENTA");
    gotoxy(23,y);cargarCadena(cod,10);
    exisProd=buscarPosProducto(cod);
    if(exisProd>-1){
        regP.leerDeDisco(exisProd);
        if(regP.getEstado()==true){
            if(buscarRepetVentDell(id,cod)==false){
              gotoxy(43,y);cout<<regP.getDescripcion();
              gotoxy(99,y);cin>>cant;
               if(cant<=regP.getStock()&&cant>0){
                 monto=regP.getPrecioUni()*cant;
                 gotoxy(113,y);cout<<monto;
                 regP.bajarStock(cant);
                 regP.guardarEnDisco(exisProd);
                 idVenta=id;
                 strcpy(cod_prod,cod);
                 cantidad=cant;
                 importe=monto;
                 estado=true;
                return true;
               }else{
                 letreroInfo(90,7,cAZUL,cROJO_CLARO,"CANTIDAD INVALIDA");
                 pausa();
                 return false;
               }
            }else{
                letreroInfo(90,7,cAZUL,cROJO_CLARO,"PRODUCTO YA INGRESADO EN AL VENTA");
                pausa();
                return false;
            }
        }else{
            letreroInfo(90,7,cAZUL,cROJO_CLARO,"PRODUCTO DADO DE BAJA");
            pausa();
            return false;
        }
    }else{
        letreroInfo(90,7,cAZUL,cROJO_CLARO,"PRODUCTO INEXISTENTE");
        pausa();
        return false;
    }

}



///FUNCIONES
//MENU
void menuVenta(){
    char op;

                while(true){

                textcolor(0);
                clrscr();
                recuadro(55, 5, 33, 16, cAZUL, cGRIS_CLARO);
                textcolor(cAZUL, cGRIS_CLARO);
                gotoxy(63,6);
                cout << " MENU VENTAS";
                gotoxy(57,7);
                cout << "-----------------------------";
                gotoxy(57,8);
                cout << "1 - REALIZAR";
                gotoxy(57, 9);
                cout << "2 - MOSTRAR";
                gotoxy(57,10);
                cout << "3 - BUSCAR";
                gotoxy(57,11);
                cout << "4 - MODIFICAR";
                gotoxy(57, 12);
                cout << "-----------------------------";
                gotoxy(57, 13);
                cout << "0 - MENU PRINCIPAL";
                gotoxy(57, 15);
                cout << "Ingresar opcion: ";
                cin >> op;

                    switch(op){

                      case '1':
                            realizarVenta();
                        break;

                      case '2':
                            mostrarVentas();
                        break;

                      case '3':
                            buscarVenta();
                        break;

                      case '4':
                            modificarVenta();
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


//DEVUELVE CANTIDAD DE VENTAS TOTALES
int cantidadVentas(){
    int pos=0;
    VentaCabecera reg;
    while(reg.leerDeDisco(pos)){
        pos++;
    }
    return pos;
}


//DEVUELVE CANTIDAD DE PRODUCTOS VENDIDOS ACTIVOS
int cantVentDetallAct(){
    int pos=0,cant=0;
    VentaDetalle regVD;
    while(regVD.leerDeDisco(pos)){
        if(regVD.getEstado()==true){
            cant++;
        }
        pos++;
    }
    return cant;
}


//DEVUELVE CANTIDAD DE PRODUCTOS VENDIDOS TOTAL
int cantVentDetallTotal(){
    int pos=0;
    VentaDetalle regVD;
    while(regVD.leerDeDisco(pos)){
        pos++;
    }
    return pos;
}


//DEVUELVE LA CANTIDAD DE PRODUCTOS VENDIDOS POR UN ID
int cantProdVentID(int id){
    VentaDetalle reg;
    int pos=0,cant=0;
    while(reg.leerDeDisco(pos)){
        if(reg.getIdVenta()==id){
           if(reg.getEstado()==true){
            cant++;
           }
        }
        pos++;
    }
    return cant;
}


//DEVUELVE LA CANTIDAD DE VENTAS REALIZADAS EN LA FECHA QUE SE LE PASA
int cantVentPorFecha(Fecha regF){
    int pos=0,cant=0;
    VentaCabecera reg;
    while(reg.leerDeDisco(pos)){
        if(reg.getFecha()==regF){
            cant++;
        }
        pos++;
    }
    return cant;
}


//DEVUELVE LA CANTIDAD DE VENTAS REALIZADAS ENTRE LAS FECHAS QUE SE LES PASA.
int cantVentParamFecha(Fecha regF1,Fecha regF2){
    int pos=0,cant=0;
    Fecha regAux;
    VentaCabecera reg;
    if(regF1>=regF2){
        regAux=regF1;
        regF1=regF2;
        regF2=regAux;
    }
    while(reg.leerDeDisco(pos)){
        if(reg.getFecha()>=regF1&&reg.getFecha()<=regF2){
            cant++;
        }
        pos++;
    }
    return cant;
}


//MUESTRA LOS PRODUCTOS DE UNA VENTA
void mostrarProdVentID(int id){
    VentaDetalle regVD;
    int pos=0,yMos=15;
    while(regVD.leerDeDisco(pos)){
        if(regVD.getIdVenta()==id){
             if(regVD.getEstado()==true){
               regVD.mostrarPrueba(yMos);
               yMos++;

             }
        }
        pos++;
    }

}


//MUESTRA LA INFORMACION DE CABECERA DE UNA VENTA EN LA POSICON DEL CUADRO VENTA CABECERA
void mostrarventaCabeceraCuadro(int alto,int id,Fecha fech,char tip,float tot){
    textcolor(cNEGRO,cGRIS_CLARO);
    fech.mostrarFecha(34,6);
    gotoxy(21,11);cout<<"ID: "<<id;
    gotoxy(53,14+alto);cout<<"TIPO PAGO: "<<tip;
    gotoxy(83,14+alto);cout<<"TOTAL: $"<<tot;
    textcolor(cAZUL,cGRIS_CLARO);
}


//CAMBIA EL ESTADO BOOLEANOA A FALSE DE LOS REGISTROS DE PRODUCTOS DE UNA VENTA
void cancelarVentDetalle(int id){
    VentaDetalle regVD;
    Producto regP;
    int pos=0,posProd;
    while(regVD.leerDeDisco(pos)){
        if(regVD.getIdVenta()==id){
            if(regVD.getEstado()==true){
              regVD.setEstado(false);
              regVD.guardarEnDisco(pos);
              posProd=buscarPosProducto(regVD.getCodProd());
              regP.leerDeDisco(posProd);
              regP.subirStock(regVD.getCantProd());
              regP.guardarEnDisco(posProd);
            }
        }
        pos++;
    }
}


//DEVUELVE EL TOTAL DE UNA VENTA
float sumarImportesVentaID(int id){
    VentaDetalle regVD;
    int pos=0;
    float suma=0;
    while(regVD.leerDeDisco(pos)){
        if(regVD.getIdVenta()==id){
            if(regVD.getEstado()==true){
               suma+=regVD.getImporte();
            }
        }
        pos++;
    }
    return suma;
}


//DEVUELVE VERDADERO SI YA EXSTE UN REGISTRO CON EL ID Y CODIGO PRODUCTO ENVIADOS
bool buscarRepetVentDell(int id,char *cod){
    int pos=0;
    VentaDetalle regVD;
    while(regVD.leerDeDisco(pos)){
        if(regVD.getIdVenta()==id){
            if(strcmp(regVD.getCodProd(),cod)==0){
                if(regVD.getEstado()==true){
                   return true;
                }
            }
        }
        pos++;
    }
    return false;
}


//DEVUELVE LA POSICION SI YA EXSTE UN REGISTRO CON EL ID Y CODIGO PRODUCTO ENVIADOS, SINO DEVUELVE -1
int buscarPosProdVenta(int id,char *cod){
    int pos=0;
    VentaDetalle regVD;
    while(regVD.leerDeDisco(pos)){
        if(regVD.getIdVenta()==id){
            if(strcmp(regVD.getCodProd(),cod)==0){
                if(regVD.getEstado()==true){
                  return pos;
                }
            }
        }
        pos++;
    }
    return -1;
}


//BUSCA LA POSICION DE UNA VENTA POR EL ID
int buscarPosVentaCabeceraID(int id){
    VentaCabecera reg;
    int pos=0;
    while(reg.leerDeDisco(pos)){
        if(reg.getIde()==id){
            return pos;
        }
        pos++;
    }
    return -1;
}


//QUITA Y DEVUELVE STOCK DEL PRODUCTO ELIMINADO DE LA VENTA
void quitarProdVenta(int posProdV){
    VentaDetalle regV;
    Producto regP;
    int posProdP;
    regV.leerDeDisco(posProdV);
    posProdP=buscarPosProducto(regV.getCodProd());
    regP.leerDeDisco(posProdP);
    regP.subirStock(regV.getCantProd());
    regP.guardarEnDisco(posProdP);
    regV.setEstado(false);
    regV.guardarEnDisco(posProdV);
}


//OPCION REALIAR VENTA
void realizarVenta(){
    Fecha regF;
    VentaCabecera regVC;
    VentaDetalle regVD;
    bool continuar,aux;
    char op,tipo,codProd[10];
    int id, cantProds,altoCuadro,posProdV,posProdP;
    float total;

    continuar=false;aux=false;id=cantidadVentas()+1;cantProds=0;altoCuadro=3;
    regF.fechaAcual();
    do{
     total=regVC.getTotal();
     tipo=regVC.getTipo();
     cuadroRealizarVenta(altoCuadro,id,regF,tipo,total);
     if(cantProds>0){
       mostrarProdVentID(id);
     }
     gotoxy(25,8);cout<<"1 - Agregar     2 - Quitar     3 - Ingresar Tipo      4 - Concretar Venta      5 - Cancelar/Salir";
     gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;

     switch(op){

     case '1':
          aux=regVD.cargarVentDetalle(15,id);
          if(aux==true){
            regVD.guardarEnDisco();
            regVC.setTotal(sumarImportesVentaID(id));
            cantProds++;
            altoCuadro++;
          }

        break;

        case '2':
         if(cantProds>0){
             borrar(65,10,20);
             borrar(25,8,97);
             gotoxy(48,8);cout<<"ingrese codigo de producto a Quitar de la venta. ";
             gotoxy(65,10);cout<<"Ingrese Codigo: ";cargarCadena(codProd,10);
             posProdV=buscarPosProdVenta(id,codProd);
             if(posProdV>-1){
                quitarProdVenta(posProdV);
                regVC.setTotal(sumarImportesVentaID(id));
                cantProds--;
                altoCuadro--;
             }else{
                letreroInfo(99,7,cAZUL,cROJO_CLARO,"PRODUCTO NO EN LA VENTA");
                pausa();
             }
         }else{
             letreroInfo(60,10,cAZUL,cROJO_CLARO,"INGRESE PRODUCTOS PRIMERO");
             pausa();
         }


        break;

     case '3':
         if(cantProds>0){
            borrar(64,14+altoCuadro,5);
           gotoxy(64,14+altoCuadro);cin>>tipo;
            if(tipo=='E'||tipo=='T'){
              regVC.setTipo(tipo);
            }else{
                letreroInfo(60,10,cAZUL,cROJO_CLARO,"INGRESE 'E' O 'T' COMO TIPO");
                pausa();
            }
         }else{
             letreroInfo(60,10,cAZUL,cROJO_CLARO,"INGRESE PRODUCTOS PRIMERO");
             pausa();
         }
        break;

     case '4':
         if(cantProds>0){
            if(regVC.getTipo()=='E'||regVC.getTipo()=='T'){
                borrar(65,10,20);
                borrar(25,8,97);
                if(cuadroAdvertencia(87,6,"CONCRETAR VENTA S/N?")){
                   regVC.setId(id);
                   regVC.setFecha(regF);
                   regVC.setActivo(true);
                   if(regVC.guardarEnDisco()){
                        borrarCuadroAdvertencia(87,6);
                        letreroInfo(65,10,cAZUL,cVERDE_CLARO,"VENTA REALIZADA");
                        continuar=true;
                   }
                }
            }else{
                letreroInfo(60,10,cAZUL,cROJO_CLARO,"INGRESE TIPO VENTA PRIMERO");
                pausa();
            }
         }else{
             letreroInfo(60,10,cAZUL,cROJO_CLARO,"INGRESE PRODUCTOS PRIMERO");
             pausa();
         }
        break;

     case '5':
         if(cantProds>0){
           cancelarVentDetalle(id);
         }
           borrar(65,10,20);
           letreroInfo(65,10,cAZUL,cROJO_CLARO,"VENTA CANCELADA");
           continuar=true;
        break;

     }
    }while(continuar==false);


}


//BORRA VENTA CABECERA MOSTRADA
void borrarVentCabeceraMostrar(int y){
    gotoxy(42,y);cout<<"        ";
    gotoxy(58,y);cout<<"          ";
    gotoxy(79,y);cout<<"     ";
    gotoxy(90,y);cout<<"          ";
}


//MUESTRA DE A 5 REGISTROS UN VENTOR DE VENTAS CABEERA
void listarVentCabeVector(VentaCabecera *vReg,int cantVent){
    int y,pos=0;
    char opMos;
    bool mostrar=true;

    do{
            y=15;

            gotoxy(47,8);cout<<"1 - MOSTRAR  MENOS     2 - MOSTRAR MAS    3 - SALIR";

           if(mostrar==true){
            borrarVentCabeceraMostrar(15);
            borrarVentCabeceraMostrar(17);
            borrarVentCabeceraMostrar(19);
            borrarVentCabeceraMostrar(21);
            borrarVentCabeceraMostrar(23);
            for(int i=pos;i<pos+5;i++){
                if(i<cantVent){
                   vReg[i].mostrarVentaCabecera(y);
                   lineaVentaComun(y+1);
                   y=y+2;
                }
            }
            mostrar=false;
           }
            borrar(63,10,20);
            gotoxy(63,10);cout<<"Ingrese opcion: ";cin>>opMos;
            if(opMos=='2'){
              pos=pos+5;
               if(pos<cantVent){
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
}


//OPCION MOSTRAR VENTAS
void mostrarVentas(){
   int y,pos=0,cantVent=0;
    char opMos;
    VentaCabecera regV, *vReg;
    bool mostrar=true;
    cantVent=cantidadVentas();
    vReg=new VentaCabecera[cantVent];
    if(vReg==NULL){
        exit(1);
    }
    while(regV.leerDeDisco(pos)){
        vReg[pos]=regV;
        pos++;
    }
    pos=0;


    cuadroVentaCabecera(10,65,"MOSTRAR VENTA");


    listarVentCabeVector(vReg,cantVent);

   delete vReg;

}


//OPCION BUSCAR VENTA
void buscarVenta(){
    VentaCabecera regVC, *vRegVC;
    VentaDetalle regVD;
    Fecha regF, regF1, regF2;
    char op;
    int alto,id,posVC,posVD,cantPorFech=0,posAux=0;
    bool continuar=false;
    do{
     alto=2;
     cuadroStdVentaDetalle(alto,66,"BUSCAR VENTA");
     gotoxy(49,8);cout<<"1 - POR ID     2 - POR FECHA     3 - SALIR";
     gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;
     switch(op){
     //POR ID
     case '1':
        gotoxy(25,11);cin>>id;
        posVC=buscarPosVentaCabeceraID(id);
        if(posVC>-1){
            regVC.leerDeDisco(posVC);
            cuadroStdVentaDetalle(alto+cantProdVentID(id),66,"BUSCAR VENTA");
            mostrarventaCabeceraCuadro(alto+cantProdVentID(id),id,regVC.getFecha(),regVC.getTipo(),regVC.getTotal());
            mostrarProdVentID(id);
            pausa();
        }else{
            letreroInfo(95,6,cAZUL,cROJO_CLARO,"ID INGRESADO INEXISTENTE");
            pausa();
        }
        break;

     //POR FECHA
     case '2':
         do{
           cuadroStdVentaDetalle(alto,66,"BUSCAR VENTA");
           gotoxy(40,8);cout<<"1 - INGRESAR FECHA    2 - INGRESAR PARAMETROS     3 - VOLVER";
           gotoxy(65,10);cout<<"Ingrese opcion: ";cin>>op;
           switch(op){
           case '1':
               posVC=0;posAux=0;
               regF.cargarFecha(34,6);
               cantPorFech=cantVentPorFecha(regF);
               if(cantPorFech>0){
                 vRegVC=new VentaCabecera[cantPorFech];
                 if(vRegVC==NULL){
                   exit(1);
                 }
                 while(regVC.leerDeDisco(posAux)){
                    if(regVC.getFecha()==regF){
                        vRegVC[posVC]=regVC;
                        posVC++;
                    }
                    posAux++;
                 }
                 cuadroVentaCabecera(10,65,"BUSCAR POR FECHA");
                 listarVentCabeVector(vRegVC,cantPorFech);
                  delete vRegVC;
               }else{
                  letreroInfo(90,6,cAZUL,cROJO_CLARO,"NO HAY VENTAS EN ESA FECHA");
                  pausa();
               }

            break;

           case '2':
               posVC=0;posAux=0;
               borrar(40,8,70);
               borrar(65,10,20);
               gotoxy(55,8);cout<<"INGRESE PARAMETROS FEHCA A BUSCAR.";
               gotoxy(70,10);cout<<"HASTA";
               regF1.cargarFecha(58,10);
               regF2.cargarFecha(77,10);
               cantPorFech=cantVentParamFecha(regF1,regF2);
               if(cantPorFech>0){
                 gotoxy(5,15);cout<<"exito, cant: "<<cantPorFech;
                 vRegVC=new VentaCabecera[cantPorFech];
                 if(vRegVC==NULL){
                   exit(1);
                 }
                 while(regVC.leerDeDisco(posAux)){
                    if(regVC.getFecha()>=regF1&&regVC.getFecha()<=regF2){
                        vRegVC[posVC]=regVC;
                        posVC++;
                    }
                    posAux++;
                 }
                 cuadroVentaCabecera(10,65,"BUSCAR POR FECHA");
                 listarVentCabeVector(vRegVC,cantPorFech);
                 delete vRegVC;

               }else{
                  letreroInfo(90,6,cAZUL,cROJO_CLARO,"NO HAY VENTAS EN ESAS FECHA");
                  pausa();
               }
            break;

           }
         }while(op!='3');
        break;

     case '3':
         continuar=true;
        break;

    }

}while(continuar==false);

}


//OPCION MODIFICAR VENTA
void modificarVenta(){
    VentaCabecera regVC;
    VentaDetalle regVD;
    Producto regP;
    Fecha regF;
    bool continuar=false,aux;
    char op, cod[10];
    int id,posVC,alto,posProdV,cant,posProd;
    alto=3;
    float totOrig=0,nuevoTot=0,adev=0,acob=0;
    do{
      cuadroVentaModificar(alto,0,regF,'N',0,0,0,0);
      gotoxy(58,8);cout<<"1 - INGRESAR ID     2 - SALIR";
      gotoxy(64,10);cout<<"Ingrese opcion: ";cin>>op;
      switch(op){

      case '1':
          borrar(25,11,5);
          gotoxy(25,11);cin>>id;
          posVC=buscarPosVentaCabeceraID(id);
          if(posVC>-1){
            totOrig=0,nuevoTot=0,adev=0,acob=0;
            regVC.leerDeDisco(posVC);
            totOrig=regVC.getTotal();
            do{
              nuevoTot=regVC.getTotal();
              if(nuevoTot==totOrig){
                nuevoTot=0;
              }else{
                 nuevoTot=regVC.getTotal();
                 if(nuevoTot>totOrig){
                    acob=nuevoTot-totOrig;
                    adev=0;
                 }else{
                     adev=totOrig-nuevoTot;
                     acob=0;
                 }
              }
              cuadroVentaModificar(alto+cantProdVentID(id),regVC.getIde(),regVC.getFecha(),regVC.getTipo(),totOrig,nuevoTot,acob,adev);
              mostrarProdVentID(id);
              gotoxy(35,8);cout<<"1 - AGREGAR PROD.     2 - QUITAR PROD.     3 - MOD. CANTIDAD     4 - VOLVER";
              gotoxy(64,10);cout<<"Ingrese opcion: ";cin>>op;
              switch(op){

              case '1':
                  aux=regVD.cargarVentDetalle(15,id);
                  if(aux==true){
                    regVD.guardarEnDisco();
                    regVC.setTotal(sumarImportesVentaID(id));
                    regVC.guardarEnDisco(posVC);
                    }
                break;

              case '2':
                   borrar(35,8,80);
                   borrar(64,10,20);
                   gotoxy(50,8);cout<<"INGRESE CODIGO PRODUCTO A QUITAR DE LA VENTA:";
                   gotoxy(64,10);cout<<"Ingrese codigo: ";cargarCadena(cod,10);
                   posProdV=buscarPosProdVenta(id,cod);
                     if(posProdV>-1){
                       quitarProdVenta(posProdV);
                       regVC.setTotal(sumarImportesVentaID(id));
                       regVC.guardarEnDisco(posVC);
                     }else{
                        letreroInfo(100,7,cAZUL,cROJO_CLARO,"PRODUCTO NO EN LA VENTA");
                     }
                      pausa();
                break;


                case '3':
                      cant=0;
                    borrar(35,8,80);
                    borrar(64,10,20);
                    gotoxy(50,8);cout<<"INGRESE CODIGO PRODUCTO A MODIFICAR CANTIDAD.";
                    gotoxy(64,10);cout<<"Ingrese codigo: ";cargarCadena(cod,10);
                    posProdV=buscarPosProdVenta(id,cod);
                     if(posProdV>-1){
                        posProd=buscarPosProducto(cod);
                        regVD.leerDeDisco(posProdV);
                        regP.leerDeDisco(posProd);
                        borrar(64,10,25);
                        gotoxy(43,8);cout<<"1 - AGREGAR CANTIDAD     2 RESTAR CANTIDAD     3 - CANCELAR";
                        gotoxy(64,10);cout<<"Ingrese opcion: ";cin>>op;
                        switch(op){

                        case '1':
                             borrar(35,8,80);
                             borrar(64,10,20);
                             gotoxy(50,8);cout<<"INGRESE CANTIDAD A AGREGAR DEL PRODUCTO: "<<regVD.getCodProd();
                             gotoxy(64,10);cout<<"Cantidad: ";cin>>cant;
                             if(cant>0&&cant<=regP.getStock()){
                                regVD.setCantidad(regVD.getCantProd()+cant);
                                regVD.setImporte(regVD.getImporte()+(cant*regP.getPrecioUni()));
                                regVD.guardarEnDisco(posProdV);
                                regP.bajarStock(cant);
                                regP.guardarEnDisco(posProd);
                                regVC.setTotal(sumarImportesVentaID(id));
                                regVC.guardarEnDisco(posVC);
                             }else{
                               letreroInfo(100,7,cAZUL,cROJO_CLARO,"CANTIDAD INVALIDA");
                               pausa();
                             }
                            break;

                        case '2':
                             borrar(35,8,80);
                             borrar(64,10,20);
                             gotoxy(50,8);cout<<"INGRESE CANTIDAD A RESTAR DEL PRODUCTO: "<<regVD.getCodProd();
                             gotoxy(64,10);cout<<"Cantidad: ";cin>>cant;
                             if(cant>0&&cant<regVD.getCantProd()){
                                regVD.setCantidad(regVD.getCantProd()-cant);
                                regVD.setImporte(regVD.getImporte()-(cant*regP.getPrecioUni()));
                                regVD.guardarEnDisco(posProdV);
                                regP.subirStock(cant);
                                regP.guardarEnDisco(posProd);
                                regVC.setTotal(sumarImportesVentaID(id));
                                regVC.guardarEnDisco(posVC);
                             }else{
                               letreroInfo(100,7,cAZUL,cROJO_CLARO,"CANTIDAD INVALIDA");
                               pausa();
                             }
                            break;

                        }

                     }else{
                        letreroInfo(97,7,cAZUL,cROJO_CLARO,"PRODUCTO NO EN LA VENTA");
                        pausa();
                     }
                   break;
              }

            }while(op!='4');
          }else{
            letreroInfo(97,7,cAZUL,cROJO_CLARO,"ID INGRESADO INEXISTENTE");
            pausa();
          }
        break;

      case '2':
          continuar=true;
        break;
      }
    }while(continuar==false);

    /*
    VentaCabecera regVC;
    VentaDetalle regVD;
    Producto regP;
    bool continuar=false,aux;
    char op, cod[10];
    int id,posVC,alto,posProdV,cant,posProd;
    alto=3;
    do{

      cuadroStdVentaDetalle(alto,63,"MODIFICAR VENTA");
      gotoxy(58,8);cout<<"1 - INGRESAR ID     2 - SALIR";
      gotoxy(64,10);cout<<"Ingrese opcion: ";cin>>op;
      switch(op){

      case '1':
          gotoxy(25,11);cin>>id;
          posVC=buscarPosVentaCabeceraID(id);
          if(posVC>-1){
            regVC.leerDeDisco(posVC);
            do{
               cuadroStdVentaDetalle(alto+cantProdVentID(id),63,"MODIFICAR VENTA");
               mostrarventaCabeceraCuadro(alto+cantProdVentID(id),id,regVC.getFecha(),regVC.getTipo(),regVC.getTotal());
               mostrarProdVentID(id);
               gotoxy(35,8);cout<<"1 - AGREGAR PROD.     2 - QUITAR PROD.     3 - MOD. CANTIDAD     4 - VOLVER";
               gotoxy(64,10);cout<<"Ingrese opcion: ";cin>>op;
        //EMPIEZAN LAS OPCIONES DEL SWICH MODIFICAR LA VENTA
               switch(op){

               case '1':
                   aux=regVD.cargarVentDetalle(15,id);
                   if(aux==true){
                      regVD.guardarEnDisco();
                      regVC.setTotal(sumarImportesVentaID(id));
                      regVC.guardarEnDisco(posVC);
                   }
                break;

               case '2':
                   borrar(35,8,80);
                   borrar(64,10,20);
                   gotoxy(50,8);cout<<"INGRESE CODIGO PRODUCTO A QUITAR DE LA VENTA:";
                   gotoxy(64,10);cout<<"Ingrese codigo: ";cargarCadena(cod,10);
                   posProdV=buscarPosProdVenta(id,cod);
                     if(posProdV>-1){
                       quitarProdVenta(posProdV);
                       regVC.setTotal(sumarImportesVentaID(id));
                     }else{
                        letreroInfo(100,7,cAZUL,cROJO_CLARO,"PRODUCTO NO EN LA VENTA");
                     }
                      pausa();
                break;

               case '3':
                    cant=0;
                    borrar(35,8,80);
                    borrar(64,10,20);
                    gotoxy(50,8);cout<<"INGRESE CODIGO PRODUCTO A MODIFICAR CANTIDAD.";
                    gotoxy(64,10);cout<<"Ingrese codigo: ";cargarCadena(cod,10);
                    posProdV=buscarPosProdVenta(id,cod);
                     if(posProdV>-1){
                        posProd=buscarPosProducto(cod);
                        regVD.leerDeDisco(posProdV);
                        regP.leerDeDisco(posProd);
                        borrar(64,10,25);
                        gotoxy(43,8);cout<<"1 - AGREGAR CANTIDAD     2 RESTAR CANTIDAD     3 - CANCELAR";
                        gotoxy(64,10);cout<<"Ingrese opcion: ";cin>>op;
                        switch(op){

                        case '1':
                             borrar(35,8,80);
                             borrar(64,10,20);
                             gotoxy(50,8);cout<<"INGRESE CANTIDAD A AGREGAR DEL PRODUCTO: "<<regVD.getCodProd();
                             gotoxy(64,10);cout<<"Cantidad: ";cin>>cant;
                             if(cant>0&&cant<=regP.getStock()){
                                regVD.setCantidad(regVD.getCantProd()+cant);
                                regVD.setImporte(regVD.getImporte()+(cant*regP.getPrecioUni()));
                                regVD.guardarEnDisco(posProdV);
                                regP.bajarStock(cant);
                                regP.guardarEnDisco(posProd);
                                regVC.setTotal(sumarImportesVentaID(id));
                             }else{
                               letreroInfo(100,7,cAZUL,cROJO_CLARO,"CANTIDAD INVALIDA");
                               pausa();
                             }
                            break;

                        case '2':
                             borrar(35,8,80);
                             borrar(64,10,20);
                             gotoxy(50,8);cout<<"INGRESE CANTIDAD A RESTAR DEL PRODUCTO: "<<regVD.getCodProd();
                             gotoxy(64,10);cout<<"Cantidad: ";cin>>cant;
                             if(cant>0&&cant<regVD.getCantProd()){
                                regVD.setCantidad(regVD.getCantProd()-cant);
                                regVD.setImporte(regVD.getImporte()-(cant*regP.getPrecioUni()));
                                regVD.guardarEnDisco(posProdV);
                                regP.subirStock(cant);
                                regP.guardarEnDisco(posProd);
                                regVC.setTotal(sumarImportesVentaID(id));
                             }else{
                               letreroInfo(100,7,cAZUL,cROJO_CLARO,"CANTIDAD INVALIDA");
                               pausa();
                             }
                            break;

                        }
                        if(op=='4'){
                            op='5';
                        }
                     }else{
                        letreroInfo(97,7,cAZUL,cROJO_CLARO,"PRODUCTO NO EN LA VENTA");
                        pausa();
                     }
                break;

               }
        //TERMINAN LAS OPCIONES DEL SWICH MODIFICAR LA VENTA
            }while(op!='4');
          }else{
            letreroInfo(97,7,cAZUL,cROJO_CLARO,"ID INGRESADO INEXISTENTE");
            pausa();
          }
        break;

      case '2':
          continuar=true;
        break;

      }
    }while(continuar==false);
*/
}



#endif // VENTAS_H_INCLUDED
