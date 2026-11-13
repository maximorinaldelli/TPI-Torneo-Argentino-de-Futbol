#include <iostream>
#include <cstring>

#include "Contrato.h"
#include "Fecha.h"


using namespace std;

Contrato::Contrato(int id,Fecha fi,Fecha ff,float monto,const char* obj,bool est)
{
    _idContrato = id;
    _idJugador = id;
    _idClub = id;
    _montoTransferencia = monto;
    _salarioMensual =monto;
    strcpy(_objetivos,obj);
    _estado = est;
    _fechaInicio = fi;
    _fechaFin = ff;
}

void Contrato::cargar()
{

}
void Contrato::mostrar()
{
    cout << "ID del contrato: "<<_idContrato<<endl;
    cout<<"ID del Jugador: "<<_idJugador<<endl;
    cout<< "ID del Club nuevo: "<<_idClub<<endl;


}

void Contrato::setIdClub(int idc)
{
    _idClub = idc;
}

void Contrato::setSalarioMensual(float sal)
{
    _salarioMensual = sal;
}
void Contrato::setIdContrato(int id)
{
    _idContrato = id;
}
void Contrato::setIdJugador(int idj)
{
    _idJugador = idj;
}
void Contrato::setFechaInicio(Fecha fecha)
{
    _fechaInicio = fecha;
}
void Contrato::setFechaFin(Fecha fechafin)
{
    _fechaFin = fechafin;
}
void Contrato::setMontoTransfer(float monto)
{
    _montoTransferencia = monto;
}
void Contrato::setObjetivos(const char* obj)
{
    strcpy(_objetivos,obj);
}
void Contrato::setEstado(bool est)
{
    _estado = est;
}

int Contrato::getIdClub()
{
    return _idClub;
}

int Contrato::getIdJugador()
{
    return _idJugador;
}
int Contrato::getIdContrato()
{
    return _idContrato;
}

Fecha Contrato::getFechaFin()
{
    return _fechaFin;
}

Fecha Contrato::getFechaInicio()
{
    return _fechaInicio;
}

float Contrato::getMontoTransferencia()
{
    return _montoTransferencia;
}

bool Contrato::getEstado()
{
    return _estado;
}

float Contrato:: getSalarioMensual()
{
    return _salarioMensual;
}
