#include "Partido.h"
#include "Gol.h"
#include <iostream>

using namespace std;

void Partido::cargar(bool mod)
{

    if(!mod)
    {
        cout<< "********************************************"<<endl;
        cout<< "ID del Partido: "<<endl;
        cin>>_idPartido;
        cout<<" ID del Equipo Local: "<<endl;
        cin>>_idLocal;
        cout<< " ID del Equipo Visitante"<<endl;
        cin>> _idVisitante;
        cout<< "Cantidad de Goles del Equipo Local: " <<endl;
        cin>>_cantGolesLocal;
        cout<< "Cantidad de Goles del Equipo Visitante: " <<endl;
        cin>>_cantGolesVisitante;
        cout<< "********************************************"<<endl;

    }
    else
    {
        cout<< "********************************************"<<endl;
        cout<<" ID del Equipo Local: "<<endl;
        cin>>_idLocal;
        cout<< " ID del Equipo Visitante"<<endl;
        cin>> _idVisitante;
        cout<< "Cantidad de Goles del Equipo Local: " <<endl;
        cin>>_cantGolesLocal;
        cout<< "Cantidad de Goles del Equipo Visitante: " <<endl;
        cin>>_cantGolesVisitante;
        cout<< "********************************************"<<endl;
    }

}
void Partido::mostrar()
{
    cout<< "********************************************"<<endl;
    cout<< "ID del Partido: "<<_idPartido<<endl;
    cout<<" ID del Equipo Local: "<<_idLocal<<endl;
    cout<< " ID del Equipo Visitante"<<_idVisitante<<endl;
    cout<< "Cantidad de Goles del Equipo Local: " <<_cantGolesLocal<<endl;
    cout<< "Cantidad de Goles del Equipo Visitante: " <<_cantGolesVisitante<<endl;
    cout<< "********************************************"<<endl;

}

void Partido::setIdPartido(int id)
{
    _idPartido = id;
}
void Partido::setIdLocal(int idl)
{
    _idLocal = idl;
}
void Partido::setIdVisitante(int idv)
{
    _idVisitante = idv;
}
void Partido::setCantGolLocal(int cant)
{
    _cantGolesLocal = cant;
}
void Partido::setCantGolVisita(int cant)
{
    _cantGolesVisitante = cant;
}
void Partido::setFecha(int fecha)
{
    _fecha = fecha;
}
void Partido::setEstado(EstadoPartido est)
{
    _estado = est;
}

int Partido::getIdLocal()
{
    return _idLocal;
}
int Partido::getIdVisitante()
{
    return _idVisitante;
}
int Partido::getIdPartido()
{
    return _idPartido;
}

EstadoPartido Partido::getEstado()
{
    return _estado;
}
int Partido::getFecha()
{
    return _fecha;
}







