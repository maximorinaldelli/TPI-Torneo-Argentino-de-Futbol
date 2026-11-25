#include <iostream>
#include <cstring>

#include "Gol.h"
#include "Partido.h"
using namespace std;

Gol::Gol(int idj, int idp,int minu,bool est)
{
    _idJugador = idj;
    _idPartido = idp;
    _minuto = minu;
    _estado = est;
}
void Gol::cargar(bool mod)
{
   if(!mod){
    cout<< "***********************************************"<<endl;
    cout<< "INGRESE EL ID DEL PARTIDO: "<<endl;
    cin>>_idPartido;
    cout<< "INGRESE EL ID DEL JUGADOR: "<<endl;
    cin>>_idJugador;
    cout<< "INGRESE EL MINUTO DEL GOL: "<<endl;
    cin>>_minuto;
    _estado = true;

    }else{
    cout<< "***********************************************"<<endl;
    cout<< "INGRESE EL ID DEL JUGADOR: "<<endl;
    cin>>_idJugador;
    cout<< "INGRESE EL MINUTO DEL GOL: "<<endl;
    cin>>_minuto;
    _estado = true;
    }
}
void Gol::mostrar()
{
    cout<< "***********************************************"<<endl;
    cout<< "ID DEL PARTIDO: "<<_idPartido<<endl;
    cout<< "ID DEL JUGADOR: "<<_idJugador<<endl;
    cout<< "MINUTO: "<<_minuto<<endl;
    cout<< "***********************************************"<<endl;
}
void Gol::setIdJugador(int idj)
{
    _idJugador = idj;
}
void Gol::setIdPartido(int idp)
{
    _idPartido = idp;
}
void Gol::setMinuto(int minu)
{
    _minuto = minu;
}
void Gol::setEstado(bool est)
{
    _estado = est;
}

int Gol::getIdJugador()
{
    return _idJugador;
}
int Gol::getIdPartido()
{
    return _idPartido;
}
int Gol::getMinuto()
{
    return _minuto;
}
bool Gol::getEstado()
{
    return _estado;
}


