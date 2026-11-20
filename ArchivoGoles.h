#pragma once
#include <cstring>
#include <iostream>
#include "Gol.h"


class ArchivoGoles
{
private:
    int _IdJugador;
    int _IdPartido;
    int _minuto;
    int _segundo;
    char _nombreArchivo[20];

public:
    ArchivoGoles(const char* nom="Goles.dat");

    bool guardarRegistro(Gol reg);
    bool modificarRegistro(Gol reg,int pos);
    Gol leerRegistro(int id);
    int buscarPorId(int id);
    int contarRegistros();

};
