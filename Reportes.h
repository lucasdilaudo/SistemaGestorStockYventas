#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void reporteGeneral(){
    VentaCabecera regV;
    int pos=0,suma=0;
    textcolor(0);
    system("cls");
    recuadro(30,5,75,18, cAZUL, cGRIS_CLARO);

    gotoxy(60, 8);
    cout << "REPORTES GENERALES" <<endl;
    gotoxy(40,12);
    cout << "La cantidad de productos activos son:      " << cantidadProductosActivos() <<endl;
    gotoxy(40, 15);
    cout << "La cantidad de proveedores activos son:    " << cantidadProveedoresActivos() <<endl;
    gotoxy(40, 18);
    cout << "La cantidad de ventas realizadas:          " << cantidadVentas() <<endl;
    while(regV.leerDeDisco(pos++)){
        suma+=regV.getTotal();
    }
    gotoxy(40, 21);
    cout << "El valor de todas las ventas es:           $" << suma <<endl;

}





#endif // REPORTES_H_INCLUDED
