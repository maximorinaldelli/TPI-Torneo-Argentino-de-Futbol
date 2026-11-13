#pragma once

#include <iostream>



class Gol
{
private:
    int _idJugador;
    int _idPartido;
    int _minuto;
public:
    Gol(int idj=-1, int idp=-1,int minu=-1);
    void setIdJugador(int idj);
    void setIdPartido(int idp);
    void setMinuto(int minu);

    int getIdJugador();
    int getIdPartido();
    int getMinuto();
};
