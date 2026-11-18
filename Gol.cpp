#include <iostream>
#include <cstring>

#include "Gol.h"

Gol::Gol(int idj, int idp,int minu)
{
    _idJugador = idj;
    _idPartido = idp;
    _minuto = minu;
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


