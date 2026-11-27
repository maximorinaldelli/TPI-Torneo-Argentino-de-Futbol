#pragma once
#include <iostream>
#include "ArchivoClubes.h"
#include "ArchivoPartidosh.h"
#include "Posicion.h"

class TablaPosiciones
{
private:

    Posicion *_vec;

    int _cant;

    ArchivoClubes _archClub;
    ArchivoPartidos _archPart;

public:
    TablaPosiciones();
    ~TablaPosiciones();

    void calcularTabla();
    void ordenarTabla();
    void mostrarTabla();
};


















