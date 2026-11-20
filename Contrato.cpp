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

void Contrato::cargar(bool mod)
{

    if(!mod){
    cout<< "********************************************"<<endl;
    cout<< "ID del contrato: "<<endl;
    cin>>_idContrato;
    cout<<" ID del Jugador: "<<endl;
    cin>>_idJugador;
    cout<< "ID del Club: "<<endl;
    cin>>_idClub;
    cout<< "Fecha de inicio: " <<endl;
    _fechaInicio.cargar();
    cout<< "Fecha de fin: "<<endl;
    _fechaFin.cargar();
    cout<< "Salario mensual: "<<endl;
    cin>>_salarioMensual;
    cout<< "Objetivos: "<<endl;
    cin>>_objetivos;
    cout<< "********************************************"<<endl;
    }else{
    cout<< "********************************************"<<endl;
    cout<<" ID del Jugador: "<<endl;
    cin>>_idJugador;
    cout<< "ID del Club: "<<endl;
    cin>>_idClub;
    cout<< "Fecha de inicio: " <<endl;
    _fechaInicio.cargar();
    cout<< "Fecha de fin: "<<endl;
    _fechaFin.cargar();
    cout<< "Salario mensual: "<<endl;
    cin>>_salarioMensual;
    cout<< "Objetivos: "<<endl;
    cin>>_objetivos;
    cout<< "********************************************"<<endl;
    }

}
void Contrato::mostrar()
{
    cout<< "********************************************"<<endl;
    cout<< "ID del contrato: "<<_idContrato<<endl;
    cout<<" ID del Jugador: "<<_idJugador<<endl;
    cout<< "ID del Club: "<<_idClub<<endl;
    cout<< "Fecha de inicio: " <<endl;
    _fechaInicio.mostrar();
    cout<< "Fecha de fin: "<<endl;
    _fechaFin.mostrar();
    cout<< "Salario mensual: "<<_salarioMensual<<"$"<<endl;
    cout<< "Objetivos: "<<_objetivos<<endl;
    cout<< "********************************************"<<endl;

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
