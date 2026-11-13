

#include "Fecha.h"


Fecha::Fecha(int d, int m, int a)
{
    _dia = d;
    _mes = m;
    _anio = a;
}

void Fecha::setDia(int dia)
    {
    _dia = dia;
    }

void Fecha::setMes(int mes)
{
    _mes = mes;
}

void Fecha::setAnio(int anio)
{
    _anio = anio;
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnnio()
{
    return _anio;
}









