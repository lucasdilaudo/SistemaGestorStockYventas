#ifndef OTRASFUNCIONES_H_INCLUDED
#define OTRASFUNCIONES_H_INCLUDED
#include "funciones.h"

///PRODUCTOS

void lineaProducto(int y){
    for(int i=4;i<146;i++){
        gotoxy(i,y);printf("%c",196);
    }
    gotoxy(17,y);printf("%c",193);
    gotoxy(17,y-1);printf("%c",179);
    gotoxy(81,y);printf("%c",193);
    gotoxy(81,y-1);printf("%c",179);
    gotoxy(90,y);printf("%c",193);
    gotoxy(90,y-1);printf("%c",179);
    gotoxy(110,y);printf("%c",193);
    gotoxy(110,y-1);printf("%c",179);
    gotoxy(128,y);printf("%c",193);
    gotoxy(128,y-1);printf("%c",179);
}


void cuadroProductos(int alto,int x_titulo,char *titulo){
   textcolor(0);
    clrscr();
    recuadro(3, 5, 143, 10+alto, cAZUL, cGRIS_CLARO);
    gotoxy(x_titulo,5);cout<<titulo;
    for(int i=3;i<146;i++){
     gotoxy(i,12);
     printf("%c",205);
     gotoxy(i,14);
     printf("%c",205);
   }
   gotoxy(3,12);printf("%c",204);
   gotoxy(146,12);printf("%c",185);
   gotoxy(3,14);printf("%c",204);
   gotoxy(146,14);printf("%c",185);
   gotoxy(7,13);cout<<"CODIGO";
   gotoxy(41,13);cout<<"DESCRIPCION";
   gotoxy(83,13);cout<<"STOCK";
   gotoxy(92,13);cout<<"CODIGO PROVEEDOR";
   gotoxy(116,13);cout<<"PRECIO";
   gotoxy(135,13);cout<<"MARCA";
   gotoxy(17,12);printf("%c",203);
   gotoxy(17,13);printf("%c",186);
   gotoxy(17,14);printf("%c",202);
   gotoxy(81,12);printf("%c",203);
   gotoxy(81,13);printf("%c",186);
   gotoxy(81,14);printf("%c",202);
   gotoxy(90,12);printf("%c",203);
   gotoxy(90,13);printf("%c",186);
   gotoxy(90,14);printf("%c",202);
   gotoxy(110,12);printf("%c",203);
   gotoxy(110,13);printf("%c",186);
   gotoxy(110,14);printf("%c",202);
   gotoxy(128,12);printf("%c",203);
   gotoxy(128,13);printf("%c",186);
   gotoxy(128,14);printf("%c",202);
}


void marcaColorEstadoProd(int posY,int posX,short colorMarca){

    textcolor(cBLANCO,colorMarca);
    gotoxy(posX,posY);cout<<"   ";
    textcolor(cAZUL,cGRIS_CLARO);
}


void borrarProdMostrar(int y){
    gotoxy(5,y);cout<<"          ";
    gotoxy(19,y);cout<<"                                                   ";
    gotoxy(83,y);cout<<"   ";
    gotoxy(92,y);cout<<"          ";
    gotoxy(112,y);cout<<"         ";
    gotoxy(130,y);cout<<"         ";
}




///PROVEEDOR

void cuadroProveedor(int alto,int x_titulo,char *titulo){
    textcolor(0);
    clrscr();
    recuadro(3, 5, 143, 10+alto, cAZUL, cGRIS_CLARO);
    gotoxy(x_titulo,5);cout<<titulo;
    for(int i=3;i<146;i++){
     gotoxy(i,12);
     printf("%c",205);
     gotoxy(i,14);
     printf("%c",205);
   }
   gotoxy(3,12);printf("%c",204);
   gotoxy(146,12);printf("%c",185);
   gotoxy(3,14);printf("%c",204);
   gotoxy(146,14);printf("%c",185);
   gotoxy(7,13);cout<<"CODIGO";
   gotoxy(28,13);cout<<"NOMBRE";
   gotoxy(50,13);cout<<"APELLIDO";
   gotoxy(69,13);cout<<"TELEFONO";
   gotoxy(89,13);cout<<"EMPRESA";
   gotoxy(122,13);cout<<"EMAIL";
   gotoxy(17,12);printf("%c",203);
   gotoxy(17,13);printf("%c",186);
   gotoxy(17,14);printf("%c",202);
   gotoxy(43,12);printf("%c",203);
   gotoxy(43,13);printf("%c",186);
   gotoxy(43,14);printf("%c",202);
   gotoxy(65,12);printf("%c",203);
   gotoxy(65,13);printf("%c",186);
   gotoxy(65,14);printf("%c",202);
   gotoxy(80,12);printf("%c",203);
   gotoxy(80,13);printf("%c",186);
   gotoxy(80,14);printf("%c",202);
   gotoxy(105,12);printf("%c",203);
   gotoxy(105,13);printf("%c",186);
   gotoxy(105,14);printf("%c",202);

}


void lineaProveedor(int y){
    for(int i=4;i<146;i++){
        gotoxy(i,y);printf("%c",196);
    }
    gotoxy(17,y);printf("%c",193);
    gotoxy(17,y-1);printf("%c",179);
    gotoxy(43,y);printf("%c",193);
    gotoxy(43,y-1);printf("%c",179);
    gotoxy(65,y);printf("%c",193);
    gotoxy(65,y-1);printf("%c",179);
    gotoxy(80,y);printf("%c",193);
    gotoxy(80,y-1);printf("%c",179);
    gotoxy(105,y);printf("%c",193);
    gotoxy(105,y-1);printf("%c",179);

}




///VENTAS

void lineaVentaComun(int y){
    for(int i=41;i<105;i++){
        gotoxy(i,y);printf("%c",196);
    }
    gotoxy(56,y);printf("%c",193);
    gotoxy(56,y-1);printf("%c",179);
    gotoxy(77,y);printf("%c",193);
    gotoxy(77,y-1);printf("%c",179);
    gotoxy(88,y);printf("%c",193);
    gotoxy(88,y-1);printf("%c",179);

}


void lineaVentaDetRealizar(int y){
    for(int i=21;i<125;i++){
        gotoxy(i,y);printf("%c",196);
    }
    gotoxy(41,y);printf("%c",193);
    gotoxy(41,y-1);printf("%c",179);
    gotoxy(97,y);printf("%c",193);
    gotoxy(97,y-1);printf("%c",179);
    gotoxy(110,y);printf("%c",193);
    gotoxy(110,y-1);printf("%c",179);

}



void cuadroRealizarVenta(int alto, int id,Fecha fech,char tip,float tot){
    textcolor(0);
    clrscr();
    recuadro(20, 5, 105, 10+alto, cAZUL, cGRIS_CLARO);
    gotoxy(65,5);cout<<"REALIZAR VENTA";
    gotoxy(21,6);cout<<"FECHA VENTA: ";
    fech.mostrarFecha(34,6);
    gotoxy(21,11);cout<<"ID: "<<id;
    for(int i=20;i<125;i++){
     gotoxy(i,12);
     printf("%c",205);
     gotoxy(i,14);
     printf("%c",205);
   }
   for(int i=30;i<115;i++){
     gotoxy(i,13+alto);
     printf("%c",196);
   }
   gotoxy(20,12);printf("%c",204);
   gotoxy(125,12);printf("%c",185);
   gotoxy(20,14);printf("%c",204);
   gotoxy(125,14);printf("%c",185);
   gotoxy(23,13);cout<<"CODIGO PRODUCTO";
   gotoxy(65,13);cout<<"DESCRIPCION";
   gotoxy(100,13);cout<<"CANTIDAD";
   gotoxy(116,13);cout<<"MONTO";
   gotoxy(41,12);printf("%c",203);
   gotoxy(41,13);printf("%c",186);
   gotoxy(41,14);printf("%c",202);
   gotoxy(97,12);printf("%c",203);
   gotoxy(97,13);printf("%c",186);
   gotoxy(97,14);printf("%c",202);
   gotoxy(110,12);printf("%c",203);
   gotoxy(110,13);printf("%c",186);
   gotoxy(110,14);printf("%c",202);
   gotoxy(53,14+alto);cout<<"TIPO PAGO: "<<tip;
   gotoxy(83,14+alto);cout<<"TOTAL: $"<<tot;



}


void cuadroStdVentaDetalle(int alto,int xTitulo,char *titulo){
    textcolor(0);
    clrscr();
    recuadro(20, 5, 105, 10+alto, cAZUL, cGRIS_CLARO);
    gotoxy(xTitulo,5);cout<<titulo;
    gotoxy(21,6);cout<<"FECHA VENTA: ";
    gotoxy(21,11);cout<<"ID: ";
    for(int i=20;i<125;i++){
     gotoxy(i,12);
     printf("%c",205);
     gotoxy(i,14);
     printf("%c",205);
   }
   for(int i=30;i<115;i++){
     gotoxy(i,13+alto);
     printf("%c",196);
   }
   gotoxy(20,12);printf("%c",204);
   gotoxy(125,12);printf("%c",185);
   gotoxy(20,14);printf("%c",204);
   gotoxy(125,14);printf("%c",185);
   gotoxy(23,13);cout<<"CODIGO PRODUCTO";
   gotoxy(65,13);cout<<"DESCRIPCION";
   gotoxy(100,13);cout<<"CANTIDAD";
   gotoxy(116,13);cout<<"MONTO";
   gotoxy(41,12);printf("%c",203);
   gotoxy(41,13);printf("%c",186);
   gotoxy(41,14);printf("%c",202);
   gotoxy(97,12);printf("%c",203);
   gotoxy(97,13);printf("%c",186);
   gotoxy(97,14);printf("%c",202);
   gotoxy(110,12);printf("%c",203);
   gotoxy(110,13);printf("%c",186);
   gotoxy(110,14);printf("%c",202);
   gotoxy(53,14+alto);cout<<"TIPO PAGO: ";
   gotoxy(83,14+alto);cout<<"TOTAL: $";
}


void cuadroVentaModificar(int alto,int id,Fecha fech,char tip,float tot,float newTot,float acob,float adev){
    textcolor(0);
    clrscr();
    recuadro(20, 5, 105, 10+alto, cAZUL, cGRIS_CLARO);
    gotoxy(64,5);cout<<"MODIFICAR VENTA";
    gotoxy(21,6);cout<<"FECHA VENTA: ";
    fech.mostrarFecha(34,6);
    gotoxy(21,11);cout<<"ID: ";cout<<id;
    for(int i=20;i<125;i++){
     gotoxy(i,12);
     printf("%c",205);
     gotoxy(i,14);
     printf("%c",205);
   }
   for(int i=30;i<115;i++){
     gotoxy(i,13+alto);
     printf("%c",196);
   }
   gotoxy(20,12);printf("%c",204);
   gotoxy(125,12);printf("%c",185);
   gotoxy(20,14);printf("%c",204);
   gotoxy(125,14);printf("%c",185);
   gotoxy(23,13);cout<<"CODIGO PRODUCTO";
   gotoxy(65,13);cout<<"DESCRIPCION";
   gotoxy(100,13);cout<<"CANTIDAD";
   gotoxy(116,13);cout<<"MONTO";
   gotoxy(41,12);printf("%c",203);
   gotoxy(41,13);printf("%c",186);
   gotoxy(41,14);printf("%c",202);
   gotoxy(97,12);printf("%c",203);
   gotoxy(97,13);printf("%c",186);
   gotoxy(97,14);printf("%c",202);
   gotoxy(110,12);printf("%c",203);
   gotoxy(110,13);printf("%c",186);
   gotoxy(110,14);printf("%c",202);
   gotoxy(23,14+alto);cout<<"TIPO: ";cout<<tip;
   gotoxy(35,14+alto);cout<<"TOTAL: $";cout<<tot;
   gotoxy(54,14+alto);cout<<"NUEVO TOTAL: $";cout<<newTot;
   gotoxy(80,14+alto);cout<<"A COBRAR: $";cout<<acob;
   gotoxy(102,14+alto);cout<<"A DEVOLVER: $";cout<<adev;

}


void cuadroVentaDentalleRealizar(int x_titulo,char *titulo){
    int yLinea=16;
    textcolor(0);
    clrscr();
    recuadro(20, 5, 105, 12, cAZUL, cGRIS_CLARO);
    lineaVentaDetRealizar(16);
    gotoxy(x_titulo,5);cout<<titulo;
    gotoxy(33,9);cout<<"INGRESE DATOS DEL PRODUCTO A VENDER";
    for(int i=20;i<125;i++){
     gotoxy(i,12);
     printf("%c",205);
     gotoxy(i,14);
     printf("%c",205);
   }
   gotoxy(20,12);printf("%c",204);
   gotoxy(125,12);printf("%c",185);
   gotoxy(20,14);printf("%c",204);
   gotoxy(125,14);printf("%c",185);
   gotoxy(23,13);cout<<"CODIGO PRODUCTO";
   gotoxy(65,13);cout<<"DESCRIPCION";
   gotoxy(100,13);cout<<"CANTIDAD";
   gotoxy(116,13);cout<<"MONTO";
   gotoxy(41,12);printf("%c",203);
   gotoxy(41,13);printf("%c",186);
   gotoxy(41,14);printf("%c",202);
   gotoxy(97,12);printf("%c",203);
   gotoxy(97,13);printf("%c",186);
   gotoxy(97,14);printf("%c",202);
   gotoxy(110,12);printf("%c",203);
   gotoxy(110,13);printf("%c",186);
   gotoxy(110,14);printf("%c",202);
}


void cuadroVentaCabecera(int alto,int xTitulo, char *titulo){
    textcolor(0);
    clrscr();
    recuadro(40, 5, 65, 10+alto, cAZUL, cGRIS_CLARO);
    gotoxy(xTitulo,5);cout<<titulo;
    gotoxy(44,13);cout<<"ID VENTA";
    gotoxy(61,13);cout<<"FECHA VENTA";
    gotoxy(81,13);cout<<"TIPO";
    gotoxy(94,13);cout<<"TOTAL";
    for(int i=41;i<105;i++){
     gotoxy(i,12);
     printf("%c",205);
     gotoxy(i,14);
     printf("%c",205);
   }
   gotoxy(40,12);printf("%c",204);
   gotoxy(105,12);printf("%c",185);
   gotoxy(40,14);printf("%c",204);
   gotoxy(105,14);printf("%c",185);
   gotoxy(56,12);printf("%c",203);
   gotoxy(56,13);printf("%c",186);
   gotoxy(56,14);printf("%c",202);
   gotoxy(77,12);printf("%c",203);
   gotoxy(77,13);printf("%c",186);
   gotoxy(77,14);printf("%c",202);
   gotoxy(88,12);printf("%c",203);
   gotoxy(88,13);printf("%c",186);
   gotoxy(88,14);printf("%c",202);
}



///REPORTES


void recuadroReporte(){

}
















#endif // OTRASFUNCIONES_H_INCLUDED
