#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED


Fecha::Fecha(){
    dia=0;
    mes=0;
    anio=0;
}

Fecha::Fecha(int d,int m,int a){
    dia=d;
    mes=m;
    anio=a;
}

void Fecha::mostrarFecha(int x,int y){

    gotoxy(x,y);cout<<dia;
    gotoxy(x+2,y);cout<<"/";
    gotoxy(x+3,y);cout<<mes;
    gotoxy(x+4,y);cout<<"/";
    gotoxy(x+5,y);cout<<anio;
}

void Fecha::fechaAcual(){

  time_t tiempo;
  struct tm *tmPtr;

  tiempo = time(NULL);
  tmPtr = localtime(&tiempo);

  dia=tmPtr->tm_mday;
  mes=tmPtr->tm_mon+1;
  anio=1900+tmPtr->tm_year;
}

bool Fecha::operator==(Fecha aux){
    if(dia!=aux.dia)return false;
    if(mes!=aux.mes)return false;
    if(anio!=aux.anio)return false;
    return true;
}

bool Fecha::cargarFecha(int x,int y){
    gotoxy(x+2,y);cout<<"/";
    gotoxy(x+5,y);cout<<"/";
    gotoxy(x,y);cin>>dia;
    gotoxy(x+3,y);cin>>mes;
    gotoxy(x+6,y);cin>>anio;
}

bool Fecha::operator>=(Fecha aux){
    if(anio>aux.anio){
        return true;
    }else{
       if(anio==aux.anio){
         if(mes>aux.mes){
            return true;
         }else{
            if(mes==aux.mes){
                if(dia>=aux.dia){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
         }
       }else{
           return false;
       }
    }
}

bool Fecha::operator<=(Fecha aux){
    if(anio<aux.anio){
        return true;
    }else{
       if(anio==aux.anio){
         if(mes<aux.mes){
            return true;
         }else{
            if(mes==aux.mes){
                if(dia<=aux.dia){
                    return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
         }
       }else{
           return false;
       }
    }
}


#endif // FECHA_H_INCLUDED
