#pragma once


class Cancha
{
private:
    int _idCancha;
    int _idClub;
    int _capacidad;
    char _direccion[40];
    char _nombre[50];
    bool _estado;

public:
    void setIdCancha(int id);
    void setIdClub(int idc);
    void setCapacidad(int cap);
    void setDireccion(const char* dir);
    void setNombre(const char* nom);
    void setEstado(bool est);

    int getIdCancha();
    int getIdClub();
    int getCapacidad();
    const char* getNombre();
    const char* getDireccion();
    bool getEstado();

};
