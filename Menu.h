#pragma once
#include "Partido.h"

class Menu
{
public:
    void ejecutar();

private:
    void menuPrincipal();
    void menuJugadores();
    void menuContratos();
    void menuClubes();
    void menuCanchas();
    void menuGoles();
    void menuPartidos();
    void menuReportes();

    bool esValido(Partido reg);
};




