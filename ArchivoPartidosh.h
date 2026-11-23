#pragma once
#include <cstring>
#include <iostream>
#include "Partido.h"


class ArchivoPartidos
{
private:
    char _nombreArchivo[20];
public:
    ArchivoPartidos(const char* nom="partidos.dat");

    bool guardarRegistro(Partido reg);
    bool modificarRegistro(Partido reg,int pos);
    Partido leerRegistro(int pos);
    int buscarPorId(int id);
    int contarRegistros();
    bool bajaLogica(int id);





};
