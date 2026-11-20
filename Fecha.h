#pragma once


class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha(int d=0, int m=0, int a=0);

    void mostrar();
    void cargar();

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

};
