#include <iostream>
#include <cstring>

#include "ArchivoClubes.h"
#include "Club.h"


ArchivoClubes::ArchivoClubes(const char *nom)
{
    strcpy(_nombreArchivo,nom);
}

bool ArchivoClubes::guardarRegistro(Club reg)
{
    FILE *pFile = fopen(_nombreArchivo,"ab");
    if(pFile == nullptr)
    {
        return false;
    }

    bool res = fwrite(&reg,sizeof(Club),1,pFile);
    fclose(pFile);
    return res;

}

bool ArchivoClubes::modificarRegistro(Club reg,int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb+");

    if(pFile == nullptr)
    {
        return false;
    }

    fseek(pFile,sizeof(Club)*pos,SEEK_SET);

    bool res = fwrite(&reg,sizeof(Club),1,pFile);
    fclose(pFile);
    return res;
}

Club ArchivoClubes::leerRegistro(int pos)
{
    FILE *pFile = fopen(_nombreArchivo,"rb");
    Club reg;

    if(pFile == nullptr)
    {
        return reg;
    }

    fseek(pFile,sizeof(Club)*pos,SEEK_SET);
    fread(&reg,sizeof(Club),1,pFile);

    fclose(pFile);
    return reg;
}
int ArchivoClubes::buscarXId(int id)
{
    FILE *pfile = fopen(_nombreArchivo,"rb");

    if(pfile == nullptr)
    {
        return -1;
    }

    Club reg;
    int pos=0;

    while(fread(&reg,sizeof(Club),1,pfile))
    {
        if(reg.getIDClub()==id)
        {
            fclose(pfile);
            return pos;
        }
        pos++;
    }
    fclose(pfile);
    return -1;
}

int ArchivoClubes::contarRegistro()
{
    FILE *pfile = fopen(_nombreArchivo,"rb");

    if(pfile==nullptr)
    {
        return 0;
    }

    fseek(pfile,0,SEEK_END);

    int cant = ftell(pfile) / sizeof(Club);

    fclose(pfile);
    return cant;
}

bool ArchivoClubes::bajaLogica(int id)
{
    int pos = buscarXId(id);

    if(pos==-1)
    {
        return false;
    }

    Club reg = leerRegistro(pos);
    reg.setEstado(false);
    return modificarRegistro(reg,pos);
}

