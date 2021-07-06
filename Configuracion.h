#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void menuRealizarBackUp(){
    char op;

                while(true){

                textcolor(0);
                clrscr();
                recuadro(55, 5, 33, 16, cAZUL, cGRIS_CLARO);
                textcolor(cAZUL, cGRIS_CLARO);
                gotoxy(63,6);
                cout << "REALIZAR BACKUP";
                gotoxy(57,7);
                cout << "-----------------------------";
                gotoxy(57,8);
                cout << "1 - TODOS LOS ARCHIVOS";
                gotoxy(57, 9);
                cout << "2 - ARCHIVO PRODUCTO";
                gotoxy(57, 10);
                cout << "3 - ARCHIVO PROVEEDORES";
                gotoxy(57, 11);
                cout << "4 - ARCHIVO VENTAS";
                gotoxy(57, 12);
                cout << "-----------------------------";
                gotoxy(57, 13);
                cout << "0 - MENU CONFIGURACION";
                gotoxy(57, 15);
                cout << "Ingresar opcion: ";
                cin >> op;

                    switch(op){

                    case '1':
                        opcionBackUpTodos();
                        break;

                    case '2':
                        opcionBackUpProductos();
                        break;

                    case '3':
                        opcionBackUpProveedores();
                        break;

                    case '4':
                        opcionBackUpVentas();
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


void menuRestaurarBackUp(){
    char op;

                while(true){

                textcolor(0);
                clrscr();
                recuadro(55, 5, 33, 16, cAZUL, cGRIS_CLARO);
                textcolor(cAZUL, cGRIS_CLARO);
                gotoxy(63,6);
                cout << "RESTAURAR BACKUP";
                gotoxy(57,7);
                cout << "-----------------------------";
                gotoxy(57,8);
                cout << "1 - TODOS LOS ARCHIVOS";
                gotoxy(57, 9);
                cout << "2 - ARCHIVO PRODUCTO";
                gotoxy(57, 10);
                cout << "3 - ARCHIVO PROVEEDORES";
                gotoxy(57, 11);
                cout << "4 - ARCHIVO VENTAS";
                gotoxy(57, 12);
                cout << "-----------------------------";
                gotoxy(57, 13);
                cout << "0 - MENU CONFIGURACION";
                gotoxy(57, 15);
                cout << "Ingresar opcion: ";
                cin >> op;

                    switch(op){

                    case '1':
                           opcionRestaurarTodos();
                        break;

                    case '2':
                           opcionRestaurarProductos();
                        break;

                    case '3':
                           opcionRestaurarProveedor();
                        break;

                    case '4':
                           opcionRestaurarVentas();
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


void menuConfiguracion(){
    char op;

                while(true){

                textcolor(0);
                clrscr();
                recuadro(55, 5, 33, 16, cAZUL, cGRIS_CLARO);
                textcolor(cAZUL, cGRIS_CLARO);
                gotoxy(63,6);
                cout << " MENU CONFIGURACION";
                gotoxy(57,7);
                cout << "-----------------------------";
                gotoxy(57,8);
                cout << "1 - REALIZAR BACKUP";
                gotoxy(57, 9);
                cout << "2 - RESTAURAR BACKUP";
                gotoxy(57, 10);
                cout << "-----------------------------";
                gotoxy(57, 11);
                cout << "0 - MENU PRINCIPAL";
                gotoxy(57, 13);
                cout << "Ingresar opcion: ";
                cin >> op;

                    switch(op){

                      case '1':
                           menuRealizarBackUp();
                        break;

                      case '2':
                          menuRestaurarBackUp();
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


bool limpiarArchivo(char *nomArch){

    FILE *f;
    f=fopen(nomArch,"w");
    if(f==NULL){
       false;
    }
    fclose(f);
    return true;
}


bool backUpProductos(){
    FILE * fbkp;
    Producto regP;
    int pos=0;
    bool sino=false;
    limpiarArchivo("auxProd.bkp");
    fbkp=fopen("auxProd.bkp","ab");
    if(fbkp==NULL){
        return false;
    }
    while(regP.leerDeDisco(pos)){
        sino=fwrite(&regP,sizeof regP,1,fbkp);
        if(sino==false){
            return false;
        }
        pos++;
    }
    fclose(fbkp);
    return true;

}


bool backUpProveedores(){
    FILE * fbkp;
    Proveedor regP;
    int pos=0;
    bool sino=false;
    limpiarArchivo("auxProv.bkp");
    fbkp=fopen("auxProv.bkp","ab");
    if(fbkp==NULL){
        return false;
    }
    while(regP.leerDeDisco(pos)){
        sino=fwrite(&regP,sizeof regP,1,fbkp);
        if(sino==false){
            return false;
        }
        pos++;
    }
    fclose(fbkp);
    return true;
}


bool backUpVC(){
    FILE * fbkp;
    VentaCabecera reg;
    int pos=0;
    bool sino=false;
    limpiarArchivo("auxVC.bkp");
    fbkp=fopen("auxVC.bkp","ab");
    if(fbkp==NULL){
        return false;
    }
    while(reg.leerDeDisco(pos)){
        sino=fwrite(&reg,sizeof reg,1,fbkp);
        if(sino==false){
            return false;
        }
        pos++;
    }
    fclose(fbkp);
    return true;
}


bool backUpVD(){
    FILE * fbkp;
    VentaDetalle reg;
    int pos=0;
    bool sino=false;
    limpiarArchivo("auxVD.bkp");
    fbkp=fopen("auxVD.bkp","ab");
    if(fbkp==NULL){
        return false;
    }
    while(reg.leerDeDisco(pos)){
        sino=fwrite(&reg,sizeof reg,1,fbkp);
        if(sino==false){
            return false;
        }
        pos++;
    }
    fclose(fbkp);
    return true;
}


bool restaurarBackUpProductos(){

    FILE *fbkp;
    Producto regP;
    bool sino=false;
    limpiarArchivo("Productos.dat");
    fbkp=fopen("auxProd.bkp","rb");
    if(fbkp==NULL){
        return false;
    }
     while(fread(&regP,sizeof regP,1,fbkp)==1){
        if(regP.guardarEnDisco()){
            sino=true;
        }
     }
    fclose(fbkp);
    return true;
}


bool restaurarBackUpProveedores(){

    FILE *fbkp;
    Proveedor regP;
    bool sino=false;
    limpiarArchivo("Proveedores.dat");
    fbkp=fopen("auxProv.bkp","rb");
    if(fbkp==NULL){
        return false;
    }
     while(fread(&regP,sizeof regP,1,fbkp)==1){
        if(regP.guardarEnDisco()){
            sino=true;
        }
     }
    fclose(fbkp);
    return true;
}


bool restaurarBackUpVC(){

    FILE *fbkp;
    VentaCabecera reg;
    bool sino=false;
    limpiarArchivo("VentaCabecera.dat");
    fbkp=fopen("auxVC.bkp","rb");
    if(fbkp==NULL){
        return false;
    }
     while(fread(&reg,sizeof reg,1,fbkp)==1){
        if(reg.guardarEnDisco()){
            sino=true;
        }
     }
    fclose(fbkp);
    return true;
}


bool restaurarBackUpVD(){

    FILE *fbkp;
    VentaDetalle reg;
    bool sino=false;
    limpiarArchivo("VentaDetalle.dat");
    fbkp=fopen("auxVD.bkp","rb");
    if(fbkp==NULL){
        return false;
    }
     while(fread(&reg,sizeof reg,1,fbkp)==1){
        if(reg.guardarEnDisco()){
            sino=true;
        }
     }
    fclose(fbkp);
    return true;
}



void opcionBackUpTodos(){
  textcolor(cBLANCO,cNEGRO);
  system("cls");
  if(cuadroAdvertencia(55,10,"REALIZAR BACKUP TODOS S/N?")==true){
      if(backUpProductos()&&backUpProveedores()&&backUpVC()&&backUpVD()){
         letreroInfo(65,17,cAZUL,cVERDE_CLARO,"BACKUP EXITOSO");
      }
  }else{
      letreroInfo(63,17,cAZUL,cROJO_CLARO,"SE CANCELO EL BACKUP");
  }

}


void opcionBackUpProductos(){
  textcolor(cBLANCO,cNEGRO);
  system("cls");
  if(cuadroAdvertencia(55,10,"REALIZAR BACKUP PRODUCTOS S/N?")==true){
     if(backUpProductos()){
         letreroInfo(63,17,cAZUL,cVERDE_CLARO,"BACKUP PRODUCTOS EXITOSO");
     }
  }else{
      letreroInfo(63,17,cAZUL,cROJO_CLARO,"SE CANCELO EL BACKUP");
  }
}


void opcionBackUpProveedores(){
  textcolor(cBLANCO,cNEGRO);
  system("cls");
  if(cuadroAdvertencia(55,10,"REALIZAR BACKUP PROVEEDORES S/N?")==true){
     if(backUpProveedores()){
         letreroInfo(63,17,cAZUL,cVERDE_CLARO,"BACKUP PROVEEDORES EXITOSO");
     }
  }else{
      letreroInfo(63,17,cAZUL,cROJO_CLARO,"SE CANCELO EL BACKUP");
  }
}


void opcionBackUpVentas(){
  textcolor(cBLANCO,cNEGRO);
  system("cls");
  if(cuadroAdvertencia(55,10,"REALIZAR BACKUP VENTAS S/N?")==true){
     if(backUpVC()&&backUpVD()){
         letreroInfo(63,17,cAZUL,cVERDE_CLARO,"BACKUP VENTAS EXITOSO");
     }
  }else{
      letreroInfo(63,17,cAZUL,cROJO_CLARO,"SE CANCELO EL BACKUP");
  }
}


void opcionRestaurarTodos(){
  textcolor(cBLANCO,cNEGRO);
  system("cls");
  if(cuadroAdvertencia(55,10,"RESTAURAR ARCHIVO TODOS S/N?")==true){
     if(restaurarBackUpProductos()&&restaurarBackUpProveedores()&&restaurarBackUpVC()&&restaurarBackUpVD()){
         letreroInfo(63,17,cAZUL,cVERDE_CLARO,"RESTAURACION TOTAL EXITOSA");
     }
  }else{
      letreroInfo(63,17,cAZUL,cROJO_CLARO,"SE CANCELO LA RESTAURACION");
  }
}


void opcionRestaurarProductos(){
  textcolor(cBLANCO,cNEGRO);
  system("cls");
  if(cuadroAdvertencia(55,10,"RESTAURAR ARCHIVO PRODUCTO S/N?")==true){
     if(restaurarBackUpProductos()){
         letreroInfo(63,17,cAZUL,cVERDE_CLARO,"RESTAURACION EXITOSA");
     }
  }else{
      letreroInfo(63,17,cAZUL,cROJO_CLARO,"SE CANCELO LA RESTAURACION");
  }
}


void opcionRestaurarProveedor(){
  textcolor(cBLANCO,cNEGRO);
  system("cls");
  if(cuadroAdvertencia(55,10,"RESTAURAR ARCHIVO PROVEEDOR S/N?")==true){
     if(restaurarBackUpProveedores()){
         letreroInfo(63,17,cAZUL,cVERDE_CLARO,"RESTAURACION EXITOSO");
     }
  }else{
      letreroInfo(63,17,cAZUL,cROJO_CLARO,"SE CANCELO LA RESTAURACION");
  }
}


void opcionRestaurarVentas(){
  textcolor(cBLANCO,cNEGRO);
  system("cls");
  if(cuadroAdvertencia(55,10,"RESTAURAR ARCHIVO VENTAS S/N?")==true){
     if(restaurarBackUpVC()&&restaurarBackUpVD()){
         letreroInfo(63,17,cAZUL,cVERDE_CLARO,"RESTAURACION EXITOSO");
     }
  }else{
      letreroInfo(63,17,cAZUL,cROJO_CLARO,"SE CANCELO LA RESTAURACION");
  }
}


#endif // CONFIGURACION_H_INCLUDED



















