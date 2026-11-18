#pragma once
#include <cstring>
#include <iostream>
#include "Gol.h"


class ArchivoGoles
{
private:
    int IdJugador;
public:
    ArchivoGoles(const char* nom="Goles.dat");

    bool guardarRegistro(Gol reg);
    bool modificarRegistro(Gol reg,int pos);
    Gol leerRegistro(int id);
    int buscarPorId(int id);
    int contarRegistros();

};
