#include <cstring>
#include <iostream>
#include "ArchivoCancha.h"

ArchivoCancha::ArchivoCancha(const char *nom)
{
    strcpy(_nombreArchivo,nom);
}

bool ArchivoCancha::guardarRegistro(Cancha reg)
{
    FILE *pFile = fopen(_nombreArchivo,"ab");

    if(pFile==nullptr)
    {
        return false;
    }

    bool resultado = fwrite(&reg,sizeof(Cancha),1,pFile);
    fclose(pFile);
    return resultado;

}
bool ArchivoCancha::modificarRegistro(Cancha reg, int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb+");
    if (pFile==nullptr)
    {
        return false;
    }
    fseek(pFile,sizeof(Cancha)*pos,SEEK_SET);
    bool res = fwrite(&reg,sizeof(Cancha),1,pFile);
    fclose(pFile);
    return res;

}
Cancha ArchivoCancha::leerRegistro(int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    Cancha reg;

    if(pFile==nullptr)
    {
     return reg;
    }

    fseek(pFile,sizeof(Cancha)*pos,SEEK_SET);
    fread(&reg,sizeof(Cancha),1,pFile);
    fclose(pFile);
    return reg;


}
int ArchivoCancha::buscarPorId(int id)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    if(pFile==nullptr)
    {
        return -1;
    }
    Cancha reg;
    int pos=0;

    while(fread(&reg,sizeof(Cancha),1,pFile))
    {
        if(reg.getIdCancha()==id)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
int ArchivoCancha::contarRegistros()
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    if(pFile==nullptr)return 0;

    fseek(pFile,0,SEEK_END);

    int cant = ftell(pFile) / sizeof(Cancha);

    fclose(pFile);
    return cant;

}

bool ArchivoCancha::bajaLogica(int id)
{
    int pos = buscarPorId(id);

    if(pos==-1)
    {
        return false;
    }

    Cancha reg;
    reg = leerRegistro(pos);
    reg.setEstado(false);
    return modificarRegistro(reg,pos);
}
