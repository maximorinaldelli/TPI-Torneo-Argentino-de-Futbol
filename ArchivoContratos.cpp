#include <cstring>
#include <iostream>
#include "ArchivoContratos.h"

ArchivoContratos::ArchivoContratos(const char *nom)
{
    strcpy(_nombreArchivo,nom);
}

bool ArchivoContratos::guardarRegistro(Contrato reg)
{
    FILE *pFile = fopen(_nombreArchivo,"ab");

    if(pFile==nullptr)
    {
        return false;
    }

    bool resultado = fwrite(&reg,sizeof(Contrato),1,pFile);
    fclose(pFile);
    return resultado;

}
bool ArchivoContratos::modificarRegistro(Contrato reg, int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb+");
    if (pFile==nullptr)
    {
        return false;
    }
    fseek(pFile,sizeof(Contrato)*pos,SEEK_SET);
    bool res = fwrite(&reg,sizeof(Contrato),1,pFile);
    fclose(pFile);
    return res;

}
Contrato ArchivoContratos::leerRegistro(int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    Contrato reg;

    if(pFile==nullptr)
    {
     return reg;
    }

    fseek(pFile,sizeof(Contrato)*pos,SEEK_SET);
    fread(&reg,sizeof(Contrato),1,pFile);
    fclose(pFile);
    return reg;


}
int ArchivoContratos::buscarPorId(int id)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    if(pFile==nullptr)
    {
        return -1;
    }
    Contrato reg;
    int pos=0;

    while(fread(&reg,sizeof(Contrato),1,pFile))
    {
        if(reg.getIdContrato()==id)
        {
            fclose(pFile);
            return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
int ArchivoContratos::contarRegistros()
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    if(pFile==nullptr)return 0;

    fseek(pFile,0,SEEK_END);

    int cant = ftell(pFile) / sizeof(Contrato);

    fclose(pFile);
    return cant;

}

bool ArchivoContratos::bajaLogica(int id)
{
    int pos = buscarPorId(id);

    if(pos==-1)
    {
        return false;
    }

    Contrato reg;
    reg = leerRegistro(pos);
    reg.setEstado(false);
    return modificarRegistro(reg,pos);
}
