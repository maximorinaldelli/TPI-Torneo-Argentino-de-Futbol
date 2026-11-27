#include <cstring>
#include <iostream>

#include "TablaPosiciones.h"
#include "ArchivoClubes.h"
#include "ArchivoPartidosh.h"
#include "Club.h"
#include "Partido.h"

using namespace std;

TablaPosiciones::TablaPosiciones()
{
    _vec = nullptr;
    _cant = 0;
}
TablaPosiciones::~TablaPosiciones()
{
    delete[] _vec;
}
void TablaPosiciones::calcularTabla()
{
    delete[] _vec;
    _cant = _archClub.contarActivos();

    if(_cant == 0)
    {
        cout<<"ARCHIVO DE CLUBES VACIO"<<endl;
        return;
    }

    _vec = new  Posicion[_cant];

    int cantreg = _archClub.contarRegistro();
    int j=0;
    Club reg;

    for(int i=0; i<cantreg; i++)
    {
        reg = _archClub.leerRegistro(i);
        if(reg.getEstado())
        {
            _vec[j] = Posicion(reg.getIDClub());
            j++;
        }
    }

    int cantPartidos = _archPart.contarRegistros();
    Partido regPartido;
    Posicion regPos;

    for(int i=0;i<cantPartidos;i++)
    {
        regPartido = _archPart.leerRegistro(i);

        if(regPartido.getEstado()::JUGADO || regPartido.getEstado()::PENDIENTE)
        {
            if(regPartido.getCantGolesLocal() > regPartido.getCantGolesVisita())
            {

            }
        }
    }

}
