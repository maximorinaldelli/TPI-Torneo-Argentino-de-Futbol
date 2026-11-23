#include <cstring>
#include <iostream>
#include "ArchivoPartidosh.h"


ArchivoPartidos::ArchivoPartidos(const char *nom)
{
    strcpy(_nombreArchivo,nom);
}

bool ArchivoPartidos::guardarRegistro(Partido reg)
{
    FILE *pFile = fopen(_nombreArchivo,"ab");

    if(pFile==nullptr)
    {
        return false;
    }

    bool resultado = fwrite(&reg,sizeof(Partido),1,pFile);
    fclose(pFile);
    return resultado;

}
bool ArchivoPartidos::modificarRegistro(Partido reg, int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb+");
    if (pFile==nullptr)
    {
        return false;
    }
    fseek(pFile,sizeof(Partido)*pos,SEEK_SET);
    bool res = fwrite(&reg,sizeof(Partido),1,pFile);
    fclose(pFile);
    return res;

}
Partido ArchivoPartidos::leerRegistro(int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    Partido reg;

    if(pFile==nullptr)
    {
     return reg;
    }

    fseek(pFile,sizeof(Partido)*pos,SEEK_SET);
    fread(&reg,sizeof(Partido),1,pFile);
    fclose(pFile);
    return reg;


}
int ArchivoPartidos::buscarPorId(int id)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    if(pFile==nullptr)
    {
        return -1;
    }
    Partido reg;
    int pos=0;

    while(fread(&reg,sizeof(Partido),1,pFile))
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
int ArchivoPartidos::contarRegistros()
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    if(pFile==nullptr)return 0;

    fseek(pFile,0,SEEK_END);

    int cant = ftell(pFile) / sizeof(Partido);

    fclose(pFile);
    return cant;

}

bool ArchivoPartidos::bajaLogica(int id)
{
    int pos = buscarPorId(id);

    if(pos==-1)
    {
        return false;
    }

    Partido reg;
    reg = leerRegistro(pos);
    reg.setEstado(false);
    return modificarRegistro(reg,pos);
}



