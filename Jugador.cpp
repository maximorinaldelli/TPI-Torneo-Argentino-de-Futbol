#include <iostream>
#include <cstring>

#include "Jugador.h"
using namespace std;

Jugador::Jugador(int idj,int idc,int idcon,int dors,const char* nom,const char* apellido,const char* pos,bool est)
{
    _idClub = idc;
    _idContrato = idcon;
    _idJugador = idj;
    _dorsal = dors;
    strcpy(_nombre,nom);
    strcpy(_apellido,apellido);
    strcpy(_posicion,pos);
    _estado = est;
}

void Jugador::mostrar()
{
    cout <<"Nombre: "<<_nombre  <<endl;
    cout <<"Apellido: "<<_apellido  <<endl;
    cout <<"ID Jugador: "<<_idJugador  <<endl;
    cout <<"ID del Club: "<<_idClub  <<endl;
    cout <<"Dorsal: "<<_dorsal  <<endl;
}

void Jugador::cargar(bool mod)
{
    if (!mod)
    {
        cout << "ID Jugador: " << endl;
        cin >> _idJugador;
        cin.ignore();

        cout << "Nombre: " << endl;
        cin.getline(_nombre, 30);

        cout << "Apellido: " << endl;
        cin.getline(_apellido, 30);

        cout << "ID del Club: " << endl;
        cin >> _idClub;

        cout << "Dorsal: " << endl;
        cin >> _dorsal;
    }
    else
    {
        cin.ignore();

        cout << "Nombre: " << endl;
        cin.getline(_nombre, 30);

        cout << "Apellido: " << endl;
        cin.getline(_apellido, 30);

        cout << "ID del Club: " << endl;
        cin >> _idClub;

        cout << "Dorsal: " << endl;
        cin >> _dorsal;
    }
}




void Jugador::setIdJugador(int idj)
{
    _idJugador = idj;
}
void Jugador::setIdClub(int idc)
{
    _idClub = idc;
}
void Jugador::setIdContrato(int idcon)
{
    _idContrato = idcon;
}

void Jugador::setDorsal(int dor)
{
    _dorsal = dor;
}
void Jugador::setFechaNacimiento(Fecha nac)
{
    _fechaNacimiento = nac;
}
void Jugador::setNombre(const char* nom)
{
    strcpy(_nombre,nom);
}
void Jugador::setApellido(const char* ape)
{
    strcpy(_apellido,ape);
}
void Jugador::setPosicion(const char* pos)
{
    strcpy(_posicion,pos);
}

void Jugador::setEstado(bool est)
{
    _estado = est;
}

int Jugador::getIdJugador()
{
    return _idJugador;
}
int Jugador::getIdClub()
{
    return _idClub;
}
int Jugador::getIdContrato()
{
    return _idContrato;
}
int Jugador::getDorsal()
{
    return _dorsal;
}
Fecha Jugador::getFechaNacimiento()
{
    return _fechaNacimiento;
}
const char* Jugador::getNombre()
{
    return _nombre;
}

const char* Jugador::getApellido()
{
    return _apellido;
}
const char* Jugador::getPosicion()
{
    return _posicion;
}

bool  Jugador::getEstado()
{
    return _estado;
}











