#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <windows.h>
enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};

void clrscr(void){
    system("cls");
}

void pause(void){
    system("pause >nul");
}

void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}

bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}

void cargarCadena(char *pal, int tam){

  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

void ordenarVector(int *v,int tam){

    int i,j,pos,aux;
    for(i=0;i<tam-1;i++){
        pos=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[pos]){
                pos=j;
            }
        }
        aux=v[i];
        v[i]=v[pos];
        v[pos]=aux;
    }
}


///VARIOS
void letreroInfo(int x, int y, short colorLetra, short colorFondo, char *letrero){

    textcolor(colorLetra,colorFondo);
    gotoxy(x,y);cout<<letrero;
    textcolor(cAZUL,cGRIS_CLARO);
}

void borrar(int x, int y,int tam){
    textcolor(cAZUL,cGRIS_CLARO);
    for(int i=0;i<tam;i++){
      gotoxy(x+i,y);cout<<" ";
    }
}

bool cuadroAdvertencia(int x, int y, char *texto){

    char d;
    recuadro(x,y,35,5,cROJO_CLARO,cROJO);
    textcolor(cROJO_CLARO,cROJO);
    gotoxy(x+10,y+1);cout<<"ADVERTENCIA";
    textcolor(cROJO_CLARO,cROJO);
    gotoxy(x+1,y+3);cout<<texto;
    do{
       borrar(x+18,y+4,3);
       gotoxy(x+18,y+4);cin>>d;
       if(d=='S'||d=='s'){
        return true;
    }else if(d=='n'||d=='N'){
        return false;
    }
    }while((d!='s'||d!='S')&&(d!='n'||d!='N'));


}

void borrarCuadroAdvertencia(int x,int y){

    recuadro(x,y,35,5,cGRIS_CLARO,cGRIS_CLARO);
}

void pausa(){
    textcolor(cBLANCO,cNEGRO);
    gotoxy(0,0);system("pause");
    gotoxy(0,0);cout<<"                                         ";
    textcolor(cAZUL,cGRIS_CLARO);
}

int letreroContinuarVolver(int x,int y){
    int op;
    gotoxy(x,y);cout<<"1 - REINTENTAR     2 - VOLVER";
    gotoxy(x+6,y+2);cout<<"Ingrese opcion: ";
    do{
      gotoxy(x+22,y+2);cout<<"  ";
      gotoxy(x+22,y+2);cin>>op;
      if(op!=1&&op!=2){
        letreroInfo(x+6,y+3,cAZUL,cROJO_CLARO,"OPCION INCORRECTA");
        pausa();
        borrar(x+6,y+3,17);
      }
    }while(op!=1&&op!=2);
    borrar(x,y,30);
    borrar(x+6,y+2,20);
    return op;

}



#endif // FUNCIONES_H_INCLUDED
