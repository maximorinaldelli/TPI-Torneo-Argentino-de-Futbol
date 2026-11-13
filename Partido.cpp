#include "Partido.h"
#include "Gol.h"
#include <iostream>


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
void Partido::setCantGolLocal(Gol cant)
{
    _cantGolesLocal = cant;
}
void Partido::setCantGolVisita(Gol cant)
{
    _cantGolesVisitante = cant;
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








