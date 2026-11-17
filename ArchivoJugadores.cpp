#include <cstring>
#include <iostream>

#include "Jugador.h"
#include "ArchivoJugadores.h"


ArchivoJugadores::ArchivoJugadores(const char* nom)
{
    strcpy(_nombreArchivo,nom);
}
bool ArchivoJugadores::guardarRegistro(Jugador reg)
{
    FILE *pFILE;
    pFILE = fopen(_nombreArchivo,"ab");

    if(pFILE == nullptr)
    {
        return false;
    }

    bool resultado = fwrite(&reg,sizeof(Jugador),1,pFILE);
    fclose(pFILE);
    return resultado;
}
Jugador ArchivoJugadores::leerRegistro(int pos)
{
    Jugador reg;
    FILE *pFile;

    pFile = fopen(_nombreArchivo,"rb");
    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile,sizeof(Jugador)*pos,SEEK_SET);
    fread(&reg,sizeof(Jugador),1,pFile);

    fclose(pFile);
    return reg;

}
bool ArchivoJugadores::modificaRegistro(Jugador reg,int pos)
{
    FILE* pFile;
    pFile = fopen(_nombreArchivo,"rb+");

    if(pFile==nullptr)
    {
        return false;
    }
    fseek(pFile,sizeof(Jugador)*pos,SEEK_SET);

    bool resultado = fwrite(&reg,sizeof(Jugador),1,pFile);
    fclose(pFile);

    return resultado;
}
int ArchivoJugadores::contarRegistros()
{
    FILE *pFile;
    pFile = fopen(_nombreArchivo,"rb");

    if(pFile == nullptr)
    {
        return 0;
    }
    fseek(pFile,sizeof(Jugador),SEEK_END);

    int cant = ftell(pFile) / sizeof(Jugador);

    fclose(pFile);
    return cant;
}

int ArchivoJugadores::buscarPorId(int id)
{
    FILE *pFile;
    Jugador reg;

    pFile = fopen(_nombreArchivo,"rb");

    if(pFile==nullptr)
    {
        return -1;
    }

    int pos=0;
    while(fread(&reg,sizeof(Jugador),1,pFile))
    {
        if(reg.getIdJugador()==id)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}

