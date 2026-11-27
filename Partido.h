#pragma once

#include <iostream>

enum class EstadoPartido
{
    JUGADO = 1,
    PENDIENTE = 2,
    BAJA = 3
};

class Partido
{
private:
    int _idPartido;
    int _idLocal;
    int _idVisitante;
    int _cantGolesLocal;
    int _cantGolesVisitante;
    int _fecha;
    EstadoPartido _estado;

public:
    void cargar(bool mod);
    void mostrar();

    void setIdPartido(int id);
    void setIdLocal(int idl);
    void setIdVisitante(int );
    void setCantGolLocal(int cant);
    void setCantGolVisita(int cant);
    void setFecha(int fecha);
    void setEstado(EstadoPartido est);

    int getIdPartido();
    int getIdLocal();
    int getIdVisitante();
    int getCantGolesLocal();
    int getCantGolesVisita();
    int getFecha();
    EstadoPartido getEstado();
};


