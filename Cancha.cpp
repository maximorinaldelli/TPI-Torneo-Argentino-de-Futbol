#include "Cancha.h"
#include <cstring>
#include <iostream>

using namespace std;

void Cancha::cargar(bool mod)
{

    if(!mod){
    cout<< "********************************************"<<endl;
    cout<< "ID de la Cancha: "<<endl;
    cin>>_idCancha;
    cout<<" ID del Club: "<<endl;
    cin>>_idClub;
    cout<< "Capacidad: "<<endl;
    cin>> _capacidad;
    cout<< "Direccion: " <<endl;
    _direccion;
    cout<< "Nombre: "<<endl;
    _nombre;
    cout<< "********************************************"<<endl;

    }else{
    cout<< "********************************************"<<endl;
    cout<<" ID del Club: "<<endl;
    cin>>_idClub;
    cout<< "Capacidad: "<<endl;
    cin>> _capacidad;
    cout<< "Direccion: " <<endl;
    _direccion;
    cout<< "Nombre: "<<endl;
    _nombre;
    cout<< "********************************************"<<endl;
    }

}
void Cancha::mostrar()
{
    cout<< "********************************************"<<endl;
    cout<< "ID de la Cancha: "<<_idCancha<<endl;
    cout<<" ID del Club: "<<_idClub<<endl;
    cout<< "Capacidad: "<<_capacidad<<endl;
    cout<< "Direccion: " <<_direccion<<endl;
    cout<< "Nombre: "<<_nombre<<endl;
    cout<< "********************************************"<<endl;

}

void Cancha::setIdCancha(int id)
{
    _idCancha = id;
}
void Cancha::setIdClub(int idc)
{
    _idClub = idc;
}
void Cancha::setCapacidad(int cap)
{
    _capacidad = cap;
}
void Cancha::setNombre(const char* nom)
{
    strcpy(_nombre,nom);
}
void Cancha::setDireccion(const char* dir)
{
    strcpy(_direccion,dir);
}
void Cancha::setEstado(bool est)
{
    _estado = est;
}

int Cancha::getIdCancha()
{
    return _idCancha;
}
int Cancha::getIdClub()
{
    return _idClub;
}
int Cancha::getCapacidad()
{
    return _capacidad;
}
const char* Cancha::getNombre()
{
    return _nombre;
}
const char* Cancha::getDireccion()
{
    return _direccion;
}
bool Cancha::getEstado()
{
    return _estado;
}





