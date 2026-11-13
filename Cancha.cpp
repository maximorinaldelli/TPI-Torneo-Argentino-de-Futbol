#include "Cancha.h"
#include <cstring>
#include <iostream>

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






