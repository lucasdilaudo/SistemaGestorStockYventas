#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;
#include <ctime>
#include <stdio.h>
#include "TiposClases.h"
#include "funciones.h"
#include "otrasFunciones.h"
#include "Fecha.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Ventas.h"
#include "Reportes.h"
#include "Configuracion.h"


void crearArchivosVenta(){
    VentaCabecera reg;
    Fecha regF;
    regF.fechaAcual();
    reg.setId(1);
    reg.setFecha(regF);
    reg.setTipo('T');
    reg.setTotal(1300);
    reg.guardarEnDisco();

    VentaDetalle regD;
    regD.setIdVenta(1);
    regD.setCodProd("mag666");
    regD.setCantidad(1);
    regD.setImporte(1300);
    regD.setEstado(true);
    regD.guardarEnDisco();
}

void mostrarCantidadRegistros(){
    cout<<endl<<endl<<"cantidad de reg venta cabecera: "<<cantidadVentas()<<endl;
    cout<<"cantidad de reg. total VD: "<<cantVentDetallTotal()<<endl;
    cout<<"cantidad de reg. activos VD: " <<cantVentDetallAct()<<endl;
}



int main(){


   AjustarVentana(150,40);


    char op;
    while(true){
        textcolor(0);
        clrscr();
        recuadro(55, 5, 33, 16, cAZUL, cGRIS_CLARO);
        textcolor(cAZUL, cGRIS_CLARO);
        gotoxy(63,6);
        cout << " MENU PRINCIPAL";
        gotoxy(57,7);
        cout << "-----------------------------";
        gotoxy(57,8);
        cout << "1 - PRODUCTOS";
        gotoxy(57, 9);
        cout << "2 - PROVEEDORES";
        gotoxy(57,10);
        cout << "3 - VENTA";
        gotoxy(57,11);
        cout << "4 - REPORTES";
        gotoxy(57,12);
        cout << "5 - CONFIGURACION";
        gotoxy(57, 13);
        cout << "-----------------------------";
        gotoxy(57, 14);
        cout << "0 - SALIR DEL PROGRAMA";
        gotoxy(57, 16);
        cout << "Ingresar opcion: ";
        cin >> op;

            switch(op){

              case '1':
                 menuProductos();
              break;

              case '2':
                 menuProveedores();
              break;

              case '3':
                 menuVenta();
              break;

              case '4':
                 reporteGeneral();
              break;

              case '5':
                 menuConfiguracion();
              break;

              case '0':
                return 0 ;
              break;

              default:
                textcolor(cAZUL,cROJO_CLARO);
                gotoxy(63, 19);
                cout<<"OPCION INCORRECTA";
              break;
            }
            textcolor(cBLANCO,cNEGRO);
            pausa();
          }


return 0;
}
