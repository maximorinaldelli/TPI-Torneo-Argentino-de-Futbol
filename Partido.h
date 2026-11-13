#pragma once

#include <iostream>
#include "Gol.h"

class Partido
{
private:
    int _idPartido;
    int _idLocal;
    int _idVisitante;
    Gol _cantGolesLocal;
    Gol _cantGolesVisitante;

public:
    void setIdPartido(int id);
    void setIdLocal(int idl);
    void setIdVisitante(int );
    void setCantGolLocal(Gol cant);
    void setCantGolVisita(Gol cant);

    int getIdPartido();
    int getIdLocal();
    int getIdVisitante();
    Gol getCantGolesLocal();
    Gol getCantGolesVisita();
};


