#include <iostream>
#include <cstring>
#include <iomanip>

#include "Posicion.h"

Posicion::Posicion(int id)
{
    _idClub = id;
    _partidosJugados = 0;
    _partidosGanados = 0;
    _partidosPerdidos = 0;
    _partidosEmpatados = 0;
    _golesFavor = 0;
    _golesContra = 0;
    _diferenciaGol = 0;
    _puntos = 0;
}
void Posicion::mostrar()
{
    std::cout
    <<std::right <<std::setw(5)<< _partidosJugados
    <<std::setw(5)     << _partidosGanados
    <<std::setw(5)     << _partidosPerdidos
    <<std::setw(5)     << _partidosEmpatados
    <<std::setw(5)     << _golesFavor
    <<std::setw(5)     << _golesContra
    <<std::setw(5)     << _diferenciaGol
    <<std::setw(5)     << _puntos;
}
int Posicion::getIdClub()
{
    return _idClub;
}
int Posicion::getPartidosJugados()
{
    return _partidosJugados;
}
int Posicion::getPartidosGanados()
{
    return _partidosGanados;
}
int Posicion::getPartidosPerdidos()
{
    return _partidosPerdidos;
}
int Posicion::getPartidosEmpatados()
{
    return _partidosEmpatados;
}
int Posicion::getGolesFavor()
{
    return _golesFavor;
}
int Posicion::getGolesContra()
{
    return _golesContra;
}
int Posicion::getDiferenciaGol()
{
    return _diferenciaGol;
}
int Posicion::getPuntos()
{
    return _puntos;
}
void Posicion::sumarPuntos()
{
    _puntos = (_partidosGanados * 3) + _partidosEmpatados;
}
void Posicion::actualizarGoles(int gf, int gc)
{
    _golesFavor += gf;
    _golesContra += gc;
}
void Posicion::calcularDiferenciaGol()
{
    _diferenciaGol = _golesFavor - _golesContra;
}
void Posicion::actualizarPartidos(Resultado res)
{
    _partidosJugados++;
    if (res == Resultado::GANADO)
    {
        _partidosGanados++;
    }
    else if(res == Resultado::PERDIDO)
    {
        _partidosPerdidos++;
    }
    else
    {
        _partidosEmpatados++;
    }
}





















