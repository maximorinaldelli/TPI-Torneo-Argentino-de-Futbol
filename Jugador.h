#pragma once
#include "Fecha.h"

class Jugador
{
private:
    int _idJugador;
    int _idClub;
    int _idContrato;
    int _dorsal;
    Fecha _fechaNacimiento;
    char _nombre[30];
    char _apellido[30];
    char _posicion[30];
    bool _estado;

public:
    Jugador(int idj=-1,int idc=-1,int idcon=-1,int dors=-1,const char* nom="n",const char* apellido="n",const char* pos="n",bool est=true);

    void mostrar();
    void cargar(bool mod);


    void setIdJugador(int idj);
    void setIdClub(int idc);
    void setIdContrato(int idcon);
    void setDorsal(int dor);
    void setFechaNacimiento(Fecha nac);
    void setNombre(const char* nom);
    void setApellido(const char* ape);
    void setPosicion(const char* pos);
    void setEstado(bool est);

    int getIdJugador();
    int getIdClub();
    int getIdContrato();
    int getDorsal();
    Fecha getFechaNacimiento();
    const char* getNombre();
    const char* getApellido();
    const char* getPosicion();
    bool getEstado();




};
