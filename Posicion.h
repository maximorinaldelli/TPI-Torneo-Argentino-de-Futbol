#pragma once
#include <iostream>
#include <cstring>

enum class Resultado
{
    GANADO,
    EMPATADO,
    PERDIDO
};



class Posicion
{
private:
    int _idClub;
    int _partidosJugados;
    int _partidosGanados;
    int _partidosPerdidos;
    int _partidosEmpatados;
    int _golesFavor;
    int _golesContra;
    int _diferenciaGol;
    int _puntos;

public:
    Posicion(int id=-1);
    void mostrar();

    int getIdClub() ;
    int getPartidosJugados() ;
    int getPartidosGanados();
    int getPartidosPerdidos() ;
    int getPartidosEmpatados() ;
    int getGolesFavor() ;
    int getGolesContra() ;
    int getDiferenciaGol() ;
    int getPuntos();

    void sumarPuntos();
    void actualizarGoles(int gf, int gc);
    void calcularDiferenciaGol();
    void actualizarPartidos(Resultado res);
};
