#include <cstring>
#include <iostream>
#include "ArchivoGoles.h"

bool ArchivoGoles::guardarRegistro(Gol reg)
{
    FILE *pFile = fopen(_nombreArchivo,"ab");

    if(pFile==nullptr)
    {
        return false;
    }

    bool resultado = fwrite(&reg,sizeof(Gol),1,pFile);
    fclose(pFile);
    return resultado;

}
bool ArchivoGoles::modificarRegistro(Gol reg, int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb+");
    if (pFile==nullptr)
    {
        return false;
    }
    fseek(pFile,sizeof(Gol)*pos,SEEK_SET);
    bool res = fwrite(&reg,sizeof(Gol),1,pFile);
    fclose(pFile);
    return res;

}
Gol ArchivoGoles::leerRegistro(int id)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    Gol reg;

    if(pFile==nullptr)
    {
     return reg;
    }

    fseek(pFile,sizeof(Gol)*pos,SEEK_SET);
    fread(&reg,sizeof(Gol),1,pFile);
    fclose(pFile);
    return reg;


}
int ArchivoGoles::buscarPorId(int id)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    if(pFile==nullptr)
    {
        return -1;
    }
    Gol reg;
    int pos=0;

    while(fread(&reg,sizeof(Gol),1,pFile))
    {
        if(reg.getIdPartido()==id)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
int ArchivoGoles::contarRegistros()
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    if(pFile==nullptr)return 0;

    fseek(pFile,0,SEEK_END);

    int cant = ftell(pFile) / sizeof(Gol);

    fclose(pFile);
    return cant;

}
