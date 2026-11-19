#pragma once
#include <cstdio>
#include <iostream>
#include "Jugador.h"

class ArchivoJugadores
{
private:
    char _nombreArchivo[20];

public:
    ArchivoJugadores(const char* nombre="jugadores.dat");

    bool guardarRegistro(Jugador reg);
    bool modificaRegistro(Jugador reg, int pos);
    Jugador leerRegistro(int pos);
    int buscarPorId(int id);
    int contarRegistros();
    bool bajaLogica(int id);

};
