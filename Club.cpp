#include <iostream>
#include <cstring>
#include "Club.h"

using namespace std;

Club::Club(int id,const char* nom,const char* dt,const char* pres,int canttit,bool est)
{
    _idClub = id;
    strcpy(_dt,dt);
    strcpy(_presidente,pres);
    _cantTitulos = canttit;
    _estado = est;
    strcpy(_nombre,nom);
}

void Club::mostrar()
{
    cout<<"Nombre del Club: "<<_nombre<<endl;
    cout<<"ID: "<<_idClub<<endl;
    cout<<"Presidente: "<<_presidente<<endl;
    cout<<"Cantidad de titulos: "<<_cantTitulos<<endl;
}

void Club::cargar()
{
    cout<<"Nombre del Club: "<<endl;
    cin>>_nombre;
    cout<<"ID: "<<endl;
    cin>>_idClub;
    cout<<"Presidente: "<<endl;
    cin>>_presidente;
    cout<<"Cantidad de titulos: "<<endl;
    cin>>_cantTitulos;
}

void Club::setIDClub(int idc)
{
    _idClub = idc;
}

void Club::setNombre(const char* nom)
{
    strcpy(_nombre,nom);
}

void Club::setDt(const char* dt)
{
    strcpy(_dt,dt);
}

void Club::setPresidente(const char* pres)
{
    strcpy(_presidente,pres);
}

void Club::setEstado(bool est)
{
    _estado = est;
}

int Club::getIDClub()
{
    return _idClub;
}

const char* Club::getDt()
{
    return _dt;
}

const char* Club::getPresidente()
{
    return _presidente;
}

int Club::getCantTitulos()
{
    return _cantTitulos;
}

const char* Club::getNombre()
{
    return _nombre;
}

bool Club::getEstado()
{
    return _estado;
}

