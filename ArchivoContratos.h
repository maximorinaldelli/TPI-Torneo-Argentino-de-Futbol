#pragma once
#include <cstring>
#include <iostream>
#include "Contrato.h"


class ArchivoContratos
{
private:
    char _nombreArchivo[100];
public:
    ArchivoContratos(const char* nom="Contratos.dat");

    bool guardarRegistro(Contrato reg);
    bool modificarRegistro(Contrato reg,int pos);
    Contrato leerRegistro(int id);
    int buscarPorId(int id);
    int contarRegistros();

};
