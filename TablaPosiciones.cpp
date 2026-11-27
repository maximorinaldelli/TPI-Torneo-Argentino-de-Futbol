#include <cstring>
#include <iostream>
#include <iomanip>

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
int TablaPosiciones::buscarPos(int id)
{
    for(int i=0; i<_cant; i++)
    {
        if (_vec[i].getIdClub() == id)
        {
            return i;
        }
    }
    return -1;
}
void TablaPosiciones::calcularTabla()
{
    delete[] _vec;
    _vec = nullptr;
    _cant = _archClub.contarActivos();

    if(_cant == 0)
    {
        cout<<"ARCHIVO DE CLUBES VACIO"<<endl;
        return;
    }

    _vec = new  Posicion[_cant];

    int cantreg = _archClub.contarRegistro();
    int j=0;
    Club regClub;

    for(int i=0; i<cantreg; i++)
    {
        regClub = _archClub.leerRegistro(i);
        if(regClub.getEstado())
        {
            _vec[j] = Posicion(regClub.getIDClub());
            j++;
        }
    }

    int cantPartidos = _archPart.contarRegistros();

    Partido regPartido;

    for(int i=0; i<cantPartidos; i++)
    {
        regPartido = _archPart.leerRegistro(i);

        if(regPartido.getEstado() != EstadoPartido::JUGADO) continue;

        int posL = buscarPos(regPartido.getIdLocal());
        int posV = buscarPos(regPartido.getIdVisitante());

        if(posL == -1 || posV == -1) continue;

        int golesL = regPartido.getCantGolesLocal();
        int golesV = regPartido.getCantGolesVisita();

        _vec[posL].actualizarGoles(golesL,golesV);
        _vec[posV].actualizarGoles(golesV,golesL);

        if(golesL > golesV)
        {
            _vec[posL].actualizarPartidos(Resultado::GANADO);
            _vec[posV].actualizarPartidos(Resultado::PERDIDO);
        }
        else if(golesV > golesL)
        {
            _vec[posV].actualizarPartidos(Resultado::GANADO);
            _vec[posL].actualizarPartidos(Resultado::PERDIDO);
        }
        else
        {
            _vec[posL].actualizarPartidos(Resultado::EMPATADO);
            _vec[posV].actualizarPartidos(Resultado::EMPATADO);
        }
    }

    for(int i=0; i<_cant; i++)
    {
        _vec[i].calcularDiferenciaGol();
        _vec[i].sumarPuntos();
    }
}

bool TablaPosiciones::vaAntes(Posicion a, Posicion b)
{
    if(a.getPuntos() > b.getPuntos())
    {
        return true;
    }
    else if(a.getPuntos() == b.getPuntos())
    {
        if(a.getDiferenciaGol() > b.getDiferenciaGol())
        {
            return true;
        }
        else if(a.getDiferenciaGol() == b.getDiferenciaGol())
        {
            if(a.getGolesFavor() > b.getGolesFavor())
            {
                return true;
            }
        }
    }
    return false;
}

void TablaPosiciones::ordenarTabla()
{
    Posicion aux;

    for (int i = 0; i < _cant - 1; i++)
    {
        for(int j = i+1; j < _cant; j++)
        {
            if(vaAntes(_vec[j],_vec[i]))
            {
                aux = _vec[i];
                _vec[i] = _vec[j];
                _vec[j] = aux;
            }
        }
    }
}
void TablaPosiciones::mostrarTabla()
{
    if(_cant==0)return;

    calcularTabla();
    ordenarTabla();

    Club reg;

    cout<<right << setw(5)  <<"POS" << " | "
        <<left << setw(15) <<"CLUB"
        <<right << setw(5) <<"PJ"
        << setw(5) <<"PG"
        << setw(5) <<"PP"
        << setw(5) <<"PE"
        << setw(5) <<"GF"
        << setw(5) <<"GC"
        << setw(5) <<"DG"
        << setw(5) <<"PTS"
        <<endl;

    for(int i=0; i<_cant; i++)
    {
        int pos = _archClub.buscarXId(_vec[i].getIdClub());
        reg = _archClub.leerRegistro(pos);

        const char* nom = reg.getNombre();

        cout<<right<<setw(5)<<i+1 << " | "
            <<left<<setw(15)<<nom;
        _vec[i].mostrar();
        cout<<endl;
    }
}

