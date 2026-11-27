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
    Club leerRegistro(int pos);
    int buscarXId(int id);
    int contarRegistro();
    int contarActivos();
    bool bajaLogica(int id);


};

