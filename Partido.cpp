#include "Partido.h"
#include "Gol.h"
#include <iostream>

using namespace std;

    void Partido::cargarEstado()
    {
        int opc;
        do{
        cout<< "Ingrese el estado del partido:\n";
        cout << "1: Jugado \n";
        cout << "2: Pendiente\n";
        cin >>opc;
        switch(opc)
        {
            case 1: setEstado(EstadoPartido::JUGADO);break;
            case 2: setEstado(EstadoPartido::PENDIENTE);break;
            default: cout<< "Opcion invalida, intente nuevamente\n";break;
        }
        }while(opc < 1 || opc > 2);
    }
void Partido::cargar(bool mod)
{

    if(!mod)
    {
        cout<< "********************************************"<<endl;
        cout<< "ID del Partido: "<<endl;
        cin>>_idPartido;
        cout<< "Ingrese el numero de fecha: "<<endl;
        cin>>_fecha;
        cout<<" ID del Equipo Local: "<<endl;
        cin>>_idLocal;
        cout<< " ID del Equipo Visitante: "<<endl;
        cin>> _idVisitante;
        cargarEstado();
        if(_estado == EstadoPartido::JUGADO)
        {
        cout<< "Cantidad de Goles del Equipo Local: " <<endl;
        cin>>_cantGolesLocal;
        cout<< "Cantidad de Goles del Equipo Visitante: " <<endl;
        cin>>_cantGolesVisitante;
        }else
        {
            _cantGolesLocal =0;
            _cantGolesVisitante =0;
        }
        cout<< "********************************************"<<endl;

    }
    else
    {
        cout<< "********************************************"<<endl;
        cout<< "Ingrese el numero de fecha: "<<endl;
        cin>>_fecha;
        cout<<" ID del Equipo Local: "<<endl;
        cin>>_idLocal;
        cout<< " ID del Equipo Visitante: "<<endl;
        cin>> _idVisitante;
        cargarEstado();
        if(_estado == EstadoPartido::JUGADO)
        {
        cout<< "Cantidad de Goles del Equipo Local: " <<endl;
        cin>>_cantGolesLocal;
        cout<< "Cantidad de Goles del Equipo Visitante: " <<endl;
        cin>>_cantGolesVisitante;
        }else
        {
            _cantGolesLocal =0;
            _cantGolesVisitante =0;
        }
        cout<< "********************************************"<<endl;
    }

}
void Partido::mostrar()
{
    cout<< "********************************************"<<endl;
    cout<< "ID del Partido: "<<_idPartido<<endl;
    cout<< "Numero de Fecha: "<<_fecha<<endl;
    cout<<" ID del Equipo Local: "<<_idLocal<<endl;
    cout<< " ID del Equipo Visitante: "<<_idVisitante<<endl;
    if(_estado == EstadoPartido::JUGADO)
    {
    cout<< "Estado: Partido Jugado"<<endl;
    cout<< "Cantidad de Goles del Equipo Local: " <<_cantGolesLocal<<endl;
    cout<< "Cantidad de Goles del Equipo Visitante: " <<_cantGolesVisitante<<endl;
    }else if(_estado == EstadoPartido::PENDIENTE)
    {
        cout<< "Estado: Partido Pendiente"<<endl;
    }else{
    cout<< "Estado: Partido Dado de Baja"<<endl;
    }
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
int Partido::getCantGolesLocal()
{
    return _cantGolesLocal;
}
int Partido::getCantGolesVisita()
{
    return _cantGolesVisitante;
}
EstadoPartido Partido::getEstado()
{
    return _estado;
}
int Partido::getFecha()
{
    return _fecha;
}







