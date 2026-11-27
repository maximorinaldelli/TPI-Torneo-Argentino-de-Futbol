#pragma once
#include <iostream>
#include <cstring>

#include "Club.h"

class ArchivoClubes
{
private:
    char _nombreArchivo[30];

public:
    ArchivoClubes(const char* nom="clubes.dat");

    bool guardarRegistro(Club reg);
    bool modificarRegistro(Club reg, int pos);
    bool bajaLogica(int id);
    bool estaActivo(int id);

    Club leerRegistro(int pos);
    int buscarXId(int id);
    int contarRegistro();
    int contarActivos();


};

