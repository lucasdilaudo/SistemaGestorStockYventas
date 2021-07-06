#ifndef TIPOSCLASES_H_INCLUDED
#define TIPOSCLASES_H_INCLUDED


///MENUS
void menuProductos();
void menuProveedores();
void menuVenta();
void MenuCuentaCorriente();




///FECHA
class Fecha{

private:
    int dia, mes, anio;
public:
    Fecha();
    Fecha(int,int,int);
    //GETS
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
    //SETS
    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}
    //OTROS METODOS
    void mostrarFecha(int,int);
    void fechaAcual();
    bool operator==(Fecha);
    bool operator>=(Fecha);
    bool operator<=(Fecha);
    bool cargarFecha(int,int);
};



///PERSONA
class Persona{

protected:
    char nombre[20];
    char apellido[20];
    char telefono[11];
    char nom_empresa[40];
public:
    //GETS
    char *getNombre(){return nombre;}
    char *getApellido(){return apellido;}
    char *getTelefono(){return telefono;}
    char *getNomEmpresa(){return nom_empresa;}
    //SETS
    void setNombre(char *nom){strcpy(nombre,nom);}
    void setApellido(char *apell){strcpy(apellido,apell);}
    void setTelefono(char *tel){strcpy(telefono,tel);}
    void setNomEmpresa(char *nomEmp){strcpy(nom_empresa,nomEmp);}
};



/// CLASE PRODUCTO
class Producto{

private:
    char cod_prod[10];
    char descripcion[50];
    int stock;
    char cod_prov[10];
    float precio_uni;
    char marca[20];
    bool estado;
public:
    Producto();
    //GETS
    char *getCodProd(){return cod_prod;}
    char *getDescripcion(){return descripcion;}
    int getStock(){return stock;}
    char *getCodProv(){return cod_prov;}
    float getPrecioUni(){return precio_uni;}
    bool getEstado(){return estado;}
    char *getMarca(){return marca;}
    //SETS
    void setCodProd(char *codProd){strcpy(cod_prod,codProd);}
    void setDescripcion(char *desc){strcpy(descripcion,desc);}
    void setStock(int st){stock=st;}
    void setCodProv(char *codProv){strcpy(cod_prov,codProv);}
    void setPrecUni(float precUni){precio_uni=precUni;}
    void setEstado(bool est){estado=est;}
    void setMarca(char *marc){strcpy(marca,marc);}
    //OTROS METODOS
    bool leerDeDisco(int);
    bool guardarEnDisco();
    bool guardarEnDisco(int);
    bool cargarProducto();
    void mostrarProducto(int);
    void bajarStock(int st){stock=stock-st;}
    void subirStock(int st){stock=stock+st;}
};






/// CLASE PROVEEDOR
class Proveedor:public Persona{

private:
    char cod_prov[10];
    char email[50];
    bool estado;
public:
    Proveedor();
    //GETS
    char *getCodProv(){return cod_prov;}
    char *getEmail(){return email;}
    bool getEstado(){return estado;}
    //SETS
    void setCodProv(char *cod){strcpy(cod_prov,cod);}
    void setEmail(char *em){strcpy(email,em);}
    void setEstado(bool est){estado=est;}
    //OTROS METODOS
    bool leerDeDisco(int);
    bool guardarEnDisco();
    bool guardarEnDisco(int);
    bool cargarProveedor();
    void mostrarProveedor(int);
};





/// CLASE VENTA CABECERA
class VentaCabecera{

private:
    int id;
    Fecha fech;
    char tipo;
    float total;
    bool activo;

public:
    VentaCabecera();
    int getIde(){return id;}
    Fecha getFecha(){return fech;}
    char getTipo(){return tipo;}
    float getTotal(){return total;}
    bool getActivo(){return activo;}
    void setId(int i){id=i;}
    void setFecha(Fecha f){fech=f;}
    void setTipo(char t){tipo=t;}
    void setTotal(float tot){total=tot;}
    void setActivo(bool act){activo=act;}
    bool leerDeDisco(int);
    bool guardarEnDisco();
    bool guardarEnDisco(int);
    void mostrarVentaCabecera(int);


};

//PROTOTIPOS VENTA CABECERA

/// CLASE VENTA DETALLE
class VentaDetalle{

private:
     int idVenta;
     char cod_prod[10];
     int cantidad;
     float importe;
     bool estado;

public:
    VentaDetalle();
    int getIdVenta(){return idVenta;}
    char *getCodProd(){return cod_prod;}
    int getCantProd(){return cantidad;}
    float getImporte(){return importe;}
    bool getEstado(){return estado;}
    void setIdVenta(int idvent){idVenta=idvent;}
    void setCodProd(char *cod){strcpy(cod_prod,cod);}
    void setImporte(float imp){importe=imp;}
    void setCantidad(int cant){cantidad=cant;}
    void setEstado(bool est){estado=est;}
    bool leerDeDisco(int);
    bool guardarEnDisco();
    bool guardarEnDisco(int);
    void mostrarPrueba(int);
    bool cargarVentDetalle(int,int);


};

//PROTOTIPOS
//PRODUCTO
int buscarPosProducto(char*);
int cantRegTotProductos();
int cantidadProductosActivos();
int cantidadProdProveedor(char*);
int cantidadProdMarca(char*);
void AgregarProducto();
void mostrarProductos();
void darDeBajaProducto();
void buscarProducto();
void modificarProducto();
void borrarProdPantalla(int);
//PROVEEDORES
int buscarPosProveedor(char*);
int cantidadProveedoresActivos();
int cantRegTotProveedores();
int cantidadProvNombre(char*);
int cantidadProvApellido(char*);
void agregarProveedor();
void mostrarProveedores();
void darDeBajaProveedor();
void buscarProveedor();
void modificarProveedor();
void borrarProvMostrar(int);
//VENTAS
int cantidadVentas();
void realizarVenta();
void mostrarVentas();
void buscarVenta();
void modificarVenta();
void realizarVenta();
int cantVentDetallAct();
int cantVentDetallTotal();
void mostrarProdVentID(int);
void cancelarVentDetalle(int);
float sumarImportesVentaID(int);
bool buscarRepetVentDell(int,char*);
int buscarPosProdVenta(int,char*);
//CONFIGURACION
void opcionBackUpTodos();
void opcionBackUpProductos();
void opcionBackUpProveedores();
void opcionBackUpVentas();
void opcionRestaurarTodos();
void opcionRestaurarProductos();
void opcionRestaurarProveedor();
void opcionRestaurarVentas();
//REPORTES
void reporteGeneral();
void reporteProductos();

#endif // TIPOSCLASES_H_INCLUDED
