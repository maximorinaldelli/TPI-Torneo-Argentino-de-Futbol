#pragma once

#include <iostream>



class Gol
{
private:
    int _idJugador;
    int _idPartido;
    int _minuto;
    bool _estado;

public:
    Gol(int idj=-1, int idp=-1,int minu=-1, bool est = true);

    void cargar(bool mod);
    void mostrar();

    void setIdJugador(int idj);
    void setIdPartido(int idp);
    void setMinuto(int minu);
    void setEstado(bool est);

    int getIdJugador();
    int getIdPartido();
    int getMinuto();
    bool getEstado();
};
