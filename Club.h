#pragma once

class Club
{
private:
    int _idClub;
    char _nombre[50];
    char _dt[40];
    char _presidente[40];
    int _cantTitulos;
    bool _estado;

public:
    Club(int id=-1,const char* nom="n",const char* dt="null",const char* pres="null",int canttit=-1,bool est=true);

    void mostrar();
    void cargar();

    void setIDClub(int idclub);
    void setNombre(const char* nom);
    void setDt(const char* dt);
    void setPresidente(const char* presidente);
    void setCantTitulos(int cant);
    void setEstado(bool est);

    int getIDClub();
    const char* getDt();
    const char* getPresidente();
    int getCantTitulos();
    const char* getNombre();
    bool getEstado();

};

















