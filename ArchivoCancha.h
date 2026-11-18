#pragma once
#include <cstring>
#include <iostream>
#include "Cancha.h"


class ArchivoCancha
{
private:
    char _nombreArchivo[20];
public:
    ArchivoCancha(const char* nom="Canchas.dat");

    bool guardarRegistro(Cancha reg);
    bool modificarRegistro(Cancha reg,int pos);
    Cancha leerRegistro(int pos);
    int buscarPorId(int id);
    int contarRegistros();

};

