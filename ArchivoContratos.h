#pragma once
#include <cstring>
#include <iostream>
#include "Contrato.h"


class ArchivoContratos
{
private:
    char _nombreArchivo[20];
public:
    ArchivoContratos(const char* nom="contratos.dat");

    bool guardarRegistro(Contrato reg);
    bool modificarRegistro(Contrato reg,int pos);
    Contrato leerRegistro(int id);
    int buscarPorId(int id);
    int contarRegistros();
    bool bajaLogica(int id);

};
