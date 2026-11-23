#pragma once

#include <iostream>


class Partido
{
private:
    int _idPartido;
    int _idLocal;
    int _idVisitante;
    int _cantGolesLocal;
    int _cantGolesVisitante;
    bool _estado;

public:
    void cargar(bool mod);
    void mostrar();

    void setIdPartido(int id);
    void setIdLocal(int idl);
    void setIdVisitante(int );
    void setCantGolLocal(int cant);
    void setCantGolVisita(int cant);
    void setEstado(bool est);

    int getIdPartido();
    int getIdLocal();
    int getIdVisitante();
    int getCantGolesLocal();
    int getCantGolesVisita();
    bool getEstado();
};


