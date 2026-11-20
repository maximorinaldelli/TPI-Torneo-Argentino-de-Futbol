#pragma once
#include "Fecha.h"

class Contrato
{
private:
    int _idContrato;
    int _idJugador;
    int _idClub;
    Fecha _fechaInicio;
    Fecha _fechaFin;
    float _montoTransferencia;
    float _salarioMensual;
    char _objetivos[100];
    bool _estado;

public:
    Contrato(int id=-1,Fecha fi=Fecha(), Fecha ff=Fecha(), float monto=-1,const char* obj="n",bool est=true);
    void cargar(bool mod);
    void mostrar();

    void setSalarioMensual(float sal);
    void setIdContrato(int id);
    void setIdJugador(int idj);
    void setIdClub(int idc);
    void setFechaInicio(Fecha fecha);
    void setFechaFin(Fecha fechafin);
    void setMontoTransfer(float monto);
    void setObjetivos(const char* obj);
    void setEstado(bool est);

    int getIdContrato();
    int getIdJugador();
    int getIdClub();
    Fecha getFechaInicio();
    Fecha getFechaFin();
    float getMontoTransferencia();
    float getSalarioMensual();
    const char* getObjetiivos();
    bool getEstado();
};












