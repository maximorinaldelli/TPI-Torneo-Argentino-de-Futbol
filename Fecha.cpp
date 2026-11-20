#include <iostream>
#include "Fecha.h"


Fecha::Fecha(int d, int m, int a)
{
    setDia(d);
    setMes(m);
    setAnio(a);
}

void Fecha::cargar()
{
    std::cout<<"Dia: "<<std::endl;
    std::cin>>_dia;
    std::cout<<"Mes: "<<std::endl;
    std::cin>>_mes;
    std::cout<<"Anio: "<<std::endl;
    std::cin>>_anio;

}

void Fecha::mostrar()
{
    std::cout << _dia << "/"
              << _mes << "/"
              << _anio;
}

void Fecha::setDia(int dia)
{
    if(dia >= 1 && dia <= 31)
    {
        _dia = dia;
    }
}

void Fecha::setMes(int mes)
{
    if(mes >= 1 && mes <= 12)
    {
        _mes = mes;
    }
}

void Fecha::setAnio(int anio)
{
    if(anio > 0)
    {
        _anio = anio;
    }
}

int Fecha::getDia() const
{
    return _dia;
}

int Fecha::getMes() const
{
    return _mes;
}

int Fecha::getAnio() const
{
    return _anio;
}









